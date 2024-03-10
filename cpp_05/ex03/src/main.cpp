/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:10:10 by srapin            #+#    #+#             */
/*   Updated: 2024/03/10 19:38:47 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

void checkExec()
{
	Intern i;
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

bool checkInitandError()
{
	Intern i = Intern();
	Intern j = i;
	try
	{
		i.makeForm("lol", "target");
		return false;
	}
	catch(const Intern::FormNotFound &e)
	{
		std::cerr << e.what() << std::endl;
	}
	AForm *sForm =i.makeForm("shrubbery creation" ,"test");
	if (sForm->getGradeToSign() != 145 || sForm->getGradeToExecute() != 137 || sForm->getTarget() != std::string("test"))
		return false;
	AForm *rForm = i.makeForm("robotomy request", "test");
	if (rForm->getGradeToSign() != 72 || rForm->getGradeToExecute() != 45 || rForm->getTarget() != std::string("test"))
		return false;
	AForm *pForm = i.makeForm("presidential pardon", "test");
	if (pForm->getGradeToSign() != 25 || pForm->getGradeToExecute() != 5 || pForm->getTarget() != std::string("test"))
		return false;
	delete sForm;
	delete rForm;
	delete pForm;
	return true;
}

int main(void)
{
	if (!checkInitandError())
		std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
	// if (!checkFormInitAndError())
	// 	std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
	// checkExec();
    return (0);
}