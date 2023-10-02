/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:20:19 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 20:20:36 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(100, 50, 20) 
{
    std::cout << "\e[0;33m Constructor called of ScavTrap\e[0m" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
    if ( getEnergyPoints() <= 0)
		std::cout << getName() << " is out of energypoints" << std::endl;
	else
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints()-1);	
	}
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap : " << getName() << " switched to gatekeeper mode" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ScavTrap()
{
    setName(name);
}

ScavTrap::~ScavTrap()
{
    std::cout << "\e[0;33m Destructor called of ScavTrap\e[0m" << std::endl;
}