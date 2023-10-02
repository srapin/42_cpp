/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:16:42 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 00:19:04 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

const std::string WrongAnimal::getType() const
{
    return type;
}

WrongAnimal::WrongAnimal(/* args */) : type("WrongAnimal") 
{
	std::cout << "WrongAnimal: Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	this->type = other.type;

	std::cout << "WrongAnimal: Copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	this->type = other.type;
	std::cout << "WrongAnimal: Assignment operator" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: Destructor" << std::endl;
}


void WrongAnimal::makeSound() const
{
    std::cout << "Pouet" << std::endl;
}