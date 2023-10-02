/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:16:42 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 01:16:53 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

const std::string Animal::getType() const
{
    return type;
}

Animal::Animal(std::string str) : type(str)
{
	
	std::cout << "Animal: String constructor" << std::endl;
}

Animal::Animal(/* args */) : type("Animal") 
{
	std::cout << "Animal: Default constructor" << std::endl;
}

Animal::Animal(const Animal& other) {
	this->type = other.type;

	std::cout << "Animal: Copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	this->type = other.type;
	std::cout << "Animal: Assignment operator" << std::endl;
	return *this;
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor" << std::endl;
}


void Animal::makeSound() const
{
    std::cout << "Pouet" << std::endl;
}