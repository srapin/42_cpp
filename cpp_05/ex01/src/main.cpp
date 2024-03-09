/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:10:10 by srapin            #+#    #+#             */
/*   Updated: 2024/03/09 16:46:47 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

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


void invalideFormCreation()
{
    //invalide form creation
    try
    {
        Form f1("F1", 90, 160);
        std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
    }
    catch(const Form::GradeTooLowException & e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form f1("F1", 0, 130);
        std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
    }
    catch(const Form::GradeTooHighException & e)
    {
        std::cerr << e.what() << '\n';
    }
}

void tooLowToBeSigned()
{
    try
    {
        Bureaucrat b1("B1", 150);
        std::cout << b1;
        Form f1("F1", 90, 160);
        std::cout << f1 << std::endl;
        std::cout << "Before f1 being signed "<< f1 << std::endl;
        b1.signForm(f1);
        std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
        std::cout << "After f1 being signed "<< f1 << std::endl;
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

void validFormSign()
{
    Bureaucrat b2("B2", 150);
    Form f2("F2", 150, 150);
    if (f2.getIsSigned())
        std::cout << "------------------UNEXPECTED--------------------------" << std::endl;

    std::cout << b2;
    std::cout << f2;
    b2.signForm(f2);
    std::cout << f2 ;
    if (!f2.getIsSigned())
        std::cout << "------------------UNEXPECTED--------------------------" << std::endl;
}

int main(void)
{
    invalideBureaucrateCreation();
	invalideDecIncOnBureaucrate();
	valideDecIncOnBureaucrate();
    std::cout << "\n\n\n" << std::endl;
    invalideFormCreation();
    tooLowToBeSigned();
    validFormSign();
    return (0);
}