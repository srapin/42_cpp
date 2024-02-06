/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:56:11 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 01:39:17 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "		DiamondTrap: Default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other)
{
	this->_name = other.getName();
	std::cout << "		DiamondTrap: Copy constructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) 
{
	ClapTrap tmp = other;
	// tmp = other;
	this->ClapTrap::operator=(tmp);
	_name = other.getName();
	std::cout << "		DiamondTrap: Assignment operator" << std::endl;
	std::cout << *this;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "		DiamondTrap: Destructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30), FragTrap(), ScavTrap()
{
	std::cout << "		DiamondTrap: Accessible constructor" << std::endl;
	this->_name = name;
	
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << getName() << ", my ClapTrap name is " << ClapTrap::getName() << ", my ScavTrap name is " << this->ScavTrap::getName()<< ", my FragTrap name is " << this->FragTrap::getName() << std::endl;
}

std::string DiamondTrap::getName() const
{
	return _name;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::doSpecifics()
{
	whoAmI();
}