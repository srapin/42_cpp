/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:10:07 by srapin            #+#    #+#             */
/*   Updated: 2023/10/04 19:44:31 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) , _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat: Default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()) , _grade(other.getGrade())
{
	std::cout << "Bureaucrat: Copy constructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	_grade = other.getGrade();
	std::cout << "Bureaucrat: Assignment operator" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat: Destructor" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}

Bureaucrat& Bureaucrat::operator++()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
	return *this;
}

Bureaucrat& Bureaucrat::operator--()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
	return *this;
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}


std::ostream & operator << (std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return out;
}