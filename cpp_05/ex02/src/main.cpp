/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:10:10 by srapin            #+#    #+#             */
/*   Updated: 2024/03/10 14:44:51 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"


bool checkFormInitAndError()
{
	Bureaucrat bob("Bob", 150);
	Bureaucrat alice("Alice", 5);
	ShrubberyCreationForm sForm("test");
	if (sForm.getGradeToSign() != 145 || sForm.getGradeToExecute() != 137 || sForm.getTarget() != std::string("test"))
		return false;
	RobotomyRequestForm rForm("test");
	if (rForm.getGradeToSign() != 72 || rForm.getGradeToExecute() != 45 || rForm.getTarget() != std::string("test"))
		return false;
	PresidentialPardonForm pForm("test");
	if (pForm.getGradeToSign() != 25 || pForm.getGradeToExecute() != 5 || pForm.getTarget() != std::string("test"))
		return false;
	try
	{
		alice.executeForm(sForm);
		return false;
	}
	catch(const AForm::NotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		alice.executeForm(rForm);
		return false;
	}
	catch(const AForm::NotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		alice.executeForm(pForm);
		return false;
	}
	catch(const AForm::NotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	alice.signForm(sForm);
	alice.signForm(rForm);
	alice.signForm(pForm);
	try
	{
		bob.executeForm(sForm);
		return false;
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		bob.executeForm(rForm);
		return false;
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		bob.executeForm(pForm);
		return false;
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return true;
}

void checkExec()
{
	Bureaucrat bob("Bob", 150);
	Bureaucrat alice("Alice", 5);
	ShrubberyCreationForm sForm("shru");
	PresidentialPardonForm pForm("pres");
	RobotomyRequestForm rForm("req");
	alice.signForm(sForm);
	alice.signForm(rForm);
	alice.signForm(pForm);
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "ShrubberyCreationForm" << std::endl;
	alice.executeForm(sForm);
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "PresidentialPardonForm" << std::endl;
	alice.executeForm(pForm);
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "RobotomyRequestForm" << std::endl;
	alice.executeForm(rForm);
	alice.executeForm(rForm);
	alice.executeForm(rForm);
	alice.executeForm(rForm);
	alice.executeForm(rForm);
}

int main(void)
{
	if (!checkFormInitAndError())
		std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
	checkExec();
    return (0);
}