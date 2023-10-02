/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:17:21 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 00:17:59 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(/* args */)
{
    type = "Dog";
	std::cout << "Dog: Default constructor" << std::endl;
}

Dog::Dog(const Dog& other) :Animal() {
	this->type = other.type;

	std::cout << "Dog: Copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	this->type = other.type;
	std::cout << "Dog: Assignment operator" << std::endl;
	return *this;
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor" << std::endl;
}


void Dog::makeSound() const
{
    std::cout << "Wouf" << std::endl;
}