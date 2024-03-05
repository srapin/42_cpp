/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:10:10 by srapin            #+#    #+#             */
/*   Updated: 2024/03/05 16:44:32 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b1("Bob", 1);
	Bureaucrat b2("Joe", 150);
	
	std::cout << "\n" << b1;
	std::cout << b2 << std::endl;

	//testing invalide incrementation 
	try
	{
		++b1;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	//testing invalide decrementation 
	
	try
	{
		--b2;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n" << b1;
	std::cout << b2 << std::endl;
	
	//testing valide incrementation 
	try
	{
		--b1;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	//testing valide decrementation 
	try
	{
		++b2;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n" << b1;
	std::cout << b2 << std::endl;
	
	//testing invalide creation 
	try
	{
		Bureaucrat bErr("Bob", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bErr("Bob", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}