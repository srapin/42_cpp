/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:51:09 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 21:51:55 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : ClapTrap(10, 10, 0)
{
    std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(int hp, int ep, int ad)
{
    _hitPoint = hp;
    _energyPoint = ep;
    _attackDamage = ad;
}

ClapTrap::ClapTrap(std::string name) : ClapTrap()
{
    setName(name);
}
ClapTrap::ClapTrap(const ClapTrap &copy) : ClapTrap()
{
    setName(copy.getName());
    setHitPoints(copy.getHitPoints());
    setEnergyPoints(copy.getEnergyPoints());
    setAttackDamage(copy.getAttackDamage());
}

ClapTrap::~ClapTrap()
{
    std::cout << "\e[0;33mDefault Destructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &copy)
{
    setName(copy.getName());
    setHitPoints(copy.getHitPoints());
    setEnergyPoints(copy.getEnergyPoints());
    setAttackDamage(copy.getAttackDamage());
    return (*this);
    // setName(get)
}

std::string ClapTrap::getName() const
{
    return _name;
}
void ClapTrap::setName(std::string name)
{
    _name = name;
}
int ClapTrap::getHitPoints() const
{
    return _hitPoint;
}
void ClapTrap::setHitPoints(int hitPoints)
{
    _hitPoint = hitPoints;
}
int ClapTrap::getEnergyPoints() const
{
    return _energyPoint;
}
void ClapTrap::setEnergyPoints(int energyPoints)
{
    _energyPoint = energyPoints;
}
int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}
void ClapTrap::setAttackDamage(int attackDamage)
{
    _attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
    if ( getEnergyPoints() <= 0)
		std::cout << getName() << " is out of energypoints" << std::endl;
	else
	{
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints()-1);	
	}
	// else if ( getEnergyPoints() <= 0)
		// std::cout << getName() << " is out of energypoints" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << getName() << " it lose " << amount << " hit points." << std::endl;
    setHitPoints(getHitPoints() - amount);
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (getEnergyPoints() <= 0)
	{
		std::cout << getName() << " is out of energypoints" << std::endl;
	}
	else
	{
		std::cout << getName() << " repairs itself." << " it gets " << amount << " hit points back" << std::endl;
		setEnergyPoints(getHitPoints() + amount);
		setEnergyPoints(getEnergyPoints() - 1);
	}
}