/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:17:15 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 00:18:31 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(/* args */) 
{
    type = "Cat";
	std::cout << "Cat: Default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal() {
	this->type = other.type;

	std::cout << "Cat: Copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	this->type = other.type;
	std::cout << "Cat: Assignment operator" << std::endl;
	return *this;
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor" << std::endl;
}


void Cat::makeSound() const
{
    std::cout << "Miaw" << std::endl;
}