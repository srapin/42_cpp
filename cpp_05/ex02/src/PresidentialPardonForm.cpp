/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:39:26 by srapin            #+#    #+#             */
/*   Updated: 2023/10/09 21:20:33 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", target, 25, 5)
{
	std::cout << "PresidentialPardonForm: Default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getTarget(), other.getGradeToSign(), other.getGradeToExecute())
{
	std::cout << "PresidentialPardonForm: Copy constructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	_target = other.getTarget();
	std::cout << "PresidentialPardonForm: Assignment operator" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm: Destructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecutionCond(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;

}