/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IceMateria.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:46:31 by srapin            #+#    #+#             */
/*   Updated: 2023/10/03 22:23:50 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/IceMateria.hpp"


IceMateria::IceMateria() : AMateria("ice")
{
	std::cout << "IceMateria: Default constructor" << std::endl;
}

IceMateria::IceMateria(const IceMateria& other) : AMateria(other.getType())
{

	std::cout << "IceMateria: Copy constructor" << std::endl;
}

IceMateria& IceMateria::operator=(const IceMateria& other) {
	setType(other.getType());
	std::cout << "IceMateria: Assignment operator" << std::endl;
	return *this;
}

IceMateria::~IceMateria()
{
    std::cout << "IceMateria: Destructor" << std::endl;
}

void IceMateria::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;   
}

IceMateria* IceMateria::clone() const
{
	return (new IceMateria());
}