/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:20:19 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 20:56:35 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(100, 100, 30) 
{
    std::cout << "\e[0;33m Constructor called of FragTrap\e[0m" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap : " << getName() << " high fives !!" << std::endl;
}

FragTrap::FragTrap(std::string name) : FragTrap()
{
    setName(name);
}

FragTrap::~FragTrap()
{
    std::cout << "\e[0;33m Destructor called of FragTrap\e[0m" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if ( getEnergyPoints() <= 0)
		std::cout << getName() << " is out of energypoints" << std::endl;
	else
	{
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints()-1);	
	}
}