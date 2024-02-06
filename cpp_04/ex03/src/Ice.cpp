/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:46:31 by srapin            #+#    #+#             */
/*   Updated: 2023/10/03 22:23:50 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"


Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice: Default constructor" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other.getType())
{

	std::cout << "Ice: Copy constructor" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	setType(other.getType());
	std::cout << "Ice: Assignment operator" << std::endl;
	return *this;
}

Ice::~Ice()
{
    std::cout << "Ice: Destructor" << std::endl;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;   
}

Ice* Ice::clone() const
{
	return (new Ice());
}