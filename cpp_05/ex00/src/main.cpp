/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:10:10 by srapin            #+#    #+#             */
/*   Updated: 2024/03/09 16:29:20 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

void invalideBureaucrateCreation()
{
	try
	{
		Bureaucrat bErr("Bob", 0);
		std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bErr("Bob", 151);
		std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void invalideDecIncOnBureaucrate()
{
	Bureaucrat b1("Bob", 1);
	
	std::cout << b1;
	//testing invalide incrementation 
	try
	{
		++b1;
		std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	//testing invalide decrementation 
	Bureaucrat b2("Joe", 150);
	std::cout << b2 ;
	
	try
	{
		--b2;
		std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void valideDecIncOnBureaucrate()
{
	Bureaucrat b1("Bob", 75);
	
	std::cout << b1;
	++b1;
	if (b1.getGrade() != 74)
		std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
	std::cout << b1;
	--b1;
	if (b1.getGrade() != 75)
		std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
	std::cout << b1;
}

int main(void)
{
	invalideBureaucrateCreation();
	invalideDecIncOnBureaucrate();
	valideDecIncOnBureaucrate();
}