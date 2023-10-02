/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:17:15 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 01:58:36 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Brain& Cat::getBrain()
{
	// Brain b = *_brain;
	return (*_brain);
}

Cat::Cat() : Animal("Cat"), _brain(new Brain)
{
	std::cout << "Cat: Default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal("Cat")
{
	// _brain = newBr;
	// delete this->_brain;
    this->_brain = new Brain();
    *this->_brain = *other._brain;
	std::cout << "Cat: Copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) 
{
	this->type = other.type;
	delete _brain;
	_brain = new Brain();
	*this->_brain = *other._brain;
	std::cout << "Cat: Assignment operator" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete _brain;
    std::cout << "Cat: Destructor" << std::endl;
}


void Cat::makeSound() const
{
    std::cout << "Miaw" << std::endl;
}