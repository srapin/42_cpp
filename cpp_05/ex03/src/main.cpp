/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:10:10 by srapin            #+#    #+#             */
/*   Updated: 2023/10/09 21:46:50 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int main(void) {

	srand((unsigned int)time(NULL));

	Bureaucrat bureaucrat[2] = { 
									Bureaucrat("Norminet", 46),
									Bureaucrat("Sophie", 1),
								};

	for (int i = 0; i < 2; i++) {

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "---------------" << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << std::endl << "		" << bureaucrat[i] << std::endl;
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;		
		std::cout << "---------------------------" << std::endl;
		std::cout << "---------------" << std::endl;
		std::cout << std::endl;

		try {

			std::cout << "---------SHRUBBERY CREATION FORM----------" << std::endl << std::endl;

			ShrubberyCreationForm A612("MyLoveForBobRoss");
			std::cout << A612 << std::endl;
		
			bureaucrat[i].signForm(A612);
			std::cout << A612 << std::endl;
			bureaucrat[i].executeForm(A612);
			std::cout << A612 << std::endl;


			std::cout << std::endl;
			std::cout << "---------ROBOTOMY REQUEST FORM----------" << std::endl << std::endl;
			
			RobotomyRequestForm B410("Bender");
			std::cout << B410 << std::endl;
		
			bureaucrat[i].signForm(B410);
			std::cout << B410 << std::endl;
			bureaucrat[i].executeForm(B410);
			std::cout << B410 << std::endl;
			

			std::cout << std::endl;
			std::cout << "---------PRESIDENTIAL PARDON FORM----------" << std::endl << std::endl;
			
			PresidentialPardonForm PP01("Julian Assange");
			std::cout << PP01 << std::endl;
		
			std::cout << std::endl;
			bureaucrat[i].signForm(PP01);
			std::cout << PP01 << std::endl;
			bureaucrat[i].executeForm(PP01);
			std::cout << PP01 << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;	
		}
	}
		

	std::cout << std::endl;
	std::cout << "---------TRYING TO SIGN A FORM TWICE----------" << std::endl << std::endl;
	try {
		RobotomyRequestForm B410("Bender");
		std::cout << B410 << std::endl;
		for (int i = 0; i < 2; i++) {
			bureaucrat[i].signForm(B410);
			std::cout << B410 << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}

	return 0;
}