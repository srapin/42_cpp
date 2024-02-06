/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:20:19 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 01:06:05 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(100, 50, 20), _guard(false)
{
	std::cout << "	ScavTrap: Default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ScavTrap()
{
    setName(name);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "	ScavTrap: Copy constructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	this->ClapTrap::operator=(other);
	std::cout << "	ScavTrap: Assignment operator" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "	ScavTrap: Destructor" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	if (checkCapacity(true))
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints()-1);	
	}
}

void ScavTrap::guardGate()
{
	if (!_guard)
	{
		_guard = true;
		std::cout << "ScavTrap : " << getName() << " switched to gatekeeper mode" << std::endl;
	}
	else
		std::cout << "ScavTrap : " << getName() << " is already in gatekeeper mode" << std::endl;
		
}

void ScavTrap::doSpecifics()
{
	guardGate();	
}