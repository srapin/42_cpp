/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:55:11 by srapin            #+#    #+#             */
/*   Updated: 2024/03/10 19:29:17 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() //: _formNameArray("shrubbery creation", "robotomy request", "presidential pardon"), _makers(&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm)
{
	forms[0] = new ShrubberyCreationForm("base");
	forms[1] = new RobotomyRequestForm("base");
	forms[2] = new PresidentialPardonForm("base");
	std::cout << "Intern: Default constructor" << std::endl;
}

Intern::Intern(const Intern& other) 
{
	(void) other;
	forms[0] = new ShrubberyCreationForm("base");
	forms[1] = new RobotomyRequestForm("base");
	forms[2] = new PresidentialPardonForm("base");
	std::cout << "Intern: Copy constructor" << std::endl;
}

Intern& Intern::operator=(const Intern& other) 
{
	(void) other;
	std::cout << "Intern: Assignment operator" << std::endl;
	return *this;
}

Intern::~Intern()
{
	for (int i = 0; i < 3 ; i++)
		delete(forms[i]);
	// delete [] this->forms;
    std::cout << "Intern: Destructor" << std::endl;
}

char const *Intern::FormNotFound::what() const throw()
{
	return ("Form not found");
}

AForm *Intern::makeForm(std::string formType, std::string formTarget)
{
 	std::string formNameArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	for (; i < 3 && formType != formNameArray[i]; i++);
	return i < 3 ? forms[i]->clone(formTarget) : throw Intern::FormNotFound();
}