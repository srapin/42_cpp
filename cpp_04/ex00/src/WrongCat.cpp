/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:17:15 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 00:18:31 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat(/* args */) 
{
    type = "WrongCat";
	std::cout << "WrongCat: Default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
	this->type = other.type;

	std::cout << "WrongCat: Copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	this->type = other.type;
	std::cout << "WrongCat: Assignment operator" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: Destructor" << std::endl;
}


void WrongCat::makeSound() const
{
    std::cout << "Miaw" << std::endl;
}