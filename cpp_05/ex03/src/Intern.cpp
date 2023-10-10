/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:08:04 by srapin            #+#    #+#             */
/*   Updated: 2023/10/09 22:12:02 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../inc/Intern.hpp"

Intern::Intern(/* args */)
{
	std::cout << "Intern: Default constructor" << std::endl;
}

Intern::Intern(const Intern& other) {

	std::cout << "Intern: Copy constructor" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern: Assignment operator" << std::endl;
	return *this;
}

Intern::~Intern()
{
    std::cout << "Intern: Destructor" << std::endl;
}

AForm *Intern::makeForm(std::string formType, std::string formTarget)
{
	switch (formType.c_str())
	{
	case /* constant-expression */:
		/* code */
		break;
	
	default:
		std::cout << formType << " is not a valid form type" << endl;
		break;
	}
}