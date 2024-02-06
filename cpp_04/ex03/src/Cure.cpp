/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:46:28 by srapin            #+#    #+#             */
/*   Updated: 2023/10/03 22:40:18 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"


Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure: Default constructor" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other.getType())
{

	std::cout << "Cure: Copy constructor" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	setType(other.getType());
	std::cout << "Cure: Assignment operator" << std::endl;
	return *this;
}

Cure::~Cure()
{
    std::cout << "Cure: Destructor" << std::endl;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;   
}

Cure* Cure::clone() const
{
	return (new Cure());
}