/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:56:11 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 22:01:07 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << ", my ClapTrap name is " << this->ClapTrap::getName() << std::endl;
}


DiamondTrap::DiamondTrap()
{
    std::cout << "\e[0;33mDefault Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{

	this->_name = name;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
	std::cout << this->_name << " DiamondTrap created" << std::endl;
}

void DiamondTrap::attack(std::string target) 
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "\e[0;33mDefault Destructor called of DiamondTrap\e[0m" << std::endl;
}
