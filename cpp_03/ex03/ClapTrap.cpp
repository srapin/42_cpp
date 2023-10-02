/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:51:09 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 21:55:54 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/ClapTrap.hpp"
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : ClapTrap(10, 10, 0)
{
    // std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(int hp, int ep, int ad) : _hitPoint(hp), _energyPoint(ep), _attackDamage(ad)
{
    std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
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
    std::cout << "\e[0;33m Copy constructor called of ClapTrap\e[0m" << std::endl;
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
    std::cout << "\e[0;33mOperator = called of ClapTrap\e[0m" << std::endl;
    return (*this);
    // setName(get)
}

std::string ClapTrap::getName() const
{
    return _name;
}
void ClapTrap::setName(std::string name)
{
   this->_name = name;
}
int ClapTrap::getHitPoints() const
{
    return this->_hitPoint;
}
void ClapTrap::setHitPoints(int hitPoints)
{
    this->_hitPoint = hitPoints;
}
int ClapTrap::getEnergyPoints() const
{
    return this->_energyPoint;
}
void ClapTrap::setEnergyPoints(int energyPoints)
{
    this->_energyPoint = energyPoints;
}
int ClapTrap::getAttackDamage() const
{
    return this->_attackDamage;
}
void ClapTrap::setAttackDamage(int attackDamage)
{
    this->_attackDamage = attackDamage;
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
    // if (getHitPoints() <= 0)
		// std::cout << getName() << " is out of hit points" << std::endl;
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