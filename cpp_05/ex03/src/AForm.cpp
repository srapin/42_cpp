/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:37:09 by srapin            #+#    #+#             */
/*   Updated: 2023/10/05 17:09:03 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm(std::string name, std::string target,int toSign, int toExe) : _target(target), _name(name),_isSigned(false), _gradeToSign(toSign), _gradeToExecut(toExe)
{
	if (toSign > 150 || toExe > 150)
		throw GradeTooHighException();
	if (toSign < 1 || toExe < 1)
		throw GradeTooLowException();
	std::cout << "AForm: Default constructor" << std::endl;
}

void AForm::beSigned(const Bureaucrat bob)
{
	if (bob.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_isSigned = true;
}

AForm::AForm(const AForm& other) : _name(other.getName()), _isSigned(other.getIsSigned()), _gradeToSign(other.getGradeToSign()), _gradeToExecut(other.getGradeToExecute())
{

	std::cout << "AForm: Copy constructor" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	_isSigned = other.getIsSigned();
	std::cout << "AForm: Assignment operator" << std::endl;
	return *this;
}

AForm::~AForm()
{
    std::cout << "AForm: Destructor" << std::endl;
}

std::string AForm::getName() const
{
	return _name;
}

std::string AForm::getTarget() const
{
	return _target;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecut;
}

void AForm::checkExecutionCond(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw NotSignedException();
	if (getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException();
}

std::ostream & operator << (std::ostream &out, const AForm &f)
{
	out << f.getName() << " AForm, grade to sign = " << f.getGradeToSign() << ", grade to execut = " << f.getGradeToExecute() << ", is signed = " << f.getIsSigned() << std::endl;
    return out;
}

char const *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

char const *AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed");
}