/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:37:09 by srapin            #+#    #+#             */
/*   Updated: 2023/10/04 22:32:36 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form(std::string name, int toSign, int toExe) : _name(name), _isSigned(false), _gradeToSign(toSign), _gradeToExecut(toExe)
{
	if (toSign > 150 || toExe > 150)
		throw GradeTooHighException();
	if (toSign < 1 || toExe < 1)
		throw GradeTooLowException();
	std::cout << "Form: Default constructor" << std::endl;
}

void Form::beSigned(const Bureaucrat bob)
{
	if (bob.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_isSigned = true;
}

Form::Form(const Form& other) : _name(other.getName()), _isSigned(other.getIsSigned()), _gradeToSign(other.getGradeToSign()), _gradeToExecut(other.getGradeToExecute())
{

	std::cout << "Form: Copy constructor" << std::endl;
}

Form& Form::operator=(const Form& other) {
	_isSigned = other.getIsSigned();
	std::cout << "Form: Assignment operator" << std::endl;
	return *this;
}

Form::~Form()
{
    std::cout << "Form: Destructor" << std::endl;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecut;
}

std::ostream & operator << (std::ostream &out, const Form &f)
{
	out << f.getName() << " Form, grade to sign = " << f.getGradeToSign() << ", grade to execut = " << f.getGradeToExecute() << ", is signed = " << f.getIsSigned() << std::endl;
    return out;
}

char const *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}