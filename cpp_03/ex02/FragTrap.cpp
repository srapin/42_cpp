/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:20:19 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 01:05:59 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(100, 100, 30)
{
	std::cout << "	FragTrap: Default constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{

	std::cout << "	FragTrap: Copy constructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	this->ClapTrap::operator=(other);
	std::cout << "	FragTrap: Assignment operator" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "	FragTrap: Destructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : FragTrap()
{
    setName(name);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "	FragTrap : " << getName() << " high fives !!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (checkCapacity(true))
	{
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints()-1);	
	}
}

void FragTrap::doSpecifics()
{
	highFivesGuys();
}