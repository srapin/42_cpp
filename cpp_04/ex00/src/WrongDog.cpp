/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:17:21 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 00:17:59 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongDog.hpp"

WrongDog::WrongDog(/* args */)
{
    type = "WrongDog";
	std::cout << "WrongDog: Default constructor" << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal() {
	this->type = other.type;

	std::cout << "WrongDog: Copy constructor" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
	this->type = other.type;
	std::cout << "WrongDog: Assignment operator" << std::endl;
	return *this;
}

WrongDog::~WrongDog()
{
    std::cout << "WrongDog: Destructor" << std::endl;
}


void WrongDog::makeSound() const
{
    std::cout << "Wouf" << std::endl;
}