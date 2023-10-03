/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CureMateria.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:46:28 by srapin            #+#    #+#             */
/*   Updated: 2023/10/03 22:40:18 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/CureMateria.hpp"


CureMateria::CureMateria() : AMateria("cure")
{
	std::cout << "CureMateria: Default constructor" << std::endl;
}

CureMateria::CureMateria(const CureMateria& other) : AMateria(other.getType())
{

	std::cout << "CureMateria: Copy constructor" << std::endl;
}

CureMateria& CureMateria::operator=(const CureMateria& other) {
	setType(other.getType());
	std::cout << "CureMateria: Assignment operator" << std::endl;
	return *this;
}

CureMateria::~CureMateria()
{
    std::cout << "CureMateria: Destructor" << std::endl;
}

void CureMateria::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;   
}

CureMateria* CureMateria::clone() const
{
	return (new CureMateria());
}