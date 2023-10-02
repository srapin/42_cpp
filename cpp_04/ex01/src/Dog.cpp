/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:17:21 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 02:00:04 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Brain& Dog::getBrain()
{
	// Brain b = *_brain;
	return (*_brain);
}

Dog::Dog() : Animal("Dog"), _brain(new Brain)
{
	std::cout << "Dog: Default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal("Dog")
{
	// _brain = newBr;
	// delete this->_brain;
    this->_brain = new Brain();
    *this->_brain = *other._brain;
	std::cout << "Dog: Copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) 
{
	this->type = other.type;
	delete _brain;
	_brain = new Brain();
	*this->_brain = *other._brain;
	std::cout << "Dog: Assignment operator" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete _brain;
    std::cout << "Dog: Destructor" << std::endl;
}


void Dog::makeSound() const
{
    std::cout << "Wouf" << std::endl;
}