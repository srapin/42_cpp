/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:46:21 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 19:42:44 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria: Default constructor" << std::endl;
}

AMateria::AMateria(const AMateria& other) 
{
    setType(other.getType());
	std::cout << "AMateria: Copy constructor" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    setType(other.getType());
	std::cout << "AMateria: Assignment operator" << std::endl;
	return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria: Destructor" << std::endl;
}

std::string const & AMateria::getType() const
{
    return _type;
}

void AMateria::setType(std::string type)
{
    _type = type;
}