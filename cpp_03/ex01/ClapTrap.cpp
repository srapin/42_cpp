/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:51:09 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 01:13:54 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: ClapTrap(10, 10, 0)
{
	std::cout << "ClapTrap: Default constructor" << std::endl;
}

ClapTrap::ClapTrap(int hp, int ep, int ad)
	: ClapTrap("Default", hp, ep, ad)
{
}

ClapTrap::ClapTrap(std::string name)
	: ClapTrap(name, 10, 10, 0)
{
	std::cout << "ClapTrap: Accessible constructor" << std::endl;
	// setName(name);
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad)
	: _name(name), _hitPoint(hp), _energyPoint(ep), _attackDamage(ad)
{
	std::cout << "ClapTrap: Complete constructor" << std::endl;
	// setName(name);
}

ClapTrap::ClapTrap(const ClapTrap &copy)
	: _name(copy.getName()), _hitPoint(copy.getHitPoints()),
		_energyPoint(copy.getEnergyPoints()),
		_attackDamage(copy.getAttackDamage())
{
	std::cout << "ClapTrap: Copy constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "ClapTrap: Assignment operator" << std::endl;
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	return (*this);
}

std::ostream &operator<<(std::ostream &new_out, ClapTrap const &clap)
{
	new_out << "My name is " << clap.getName() << "\nI got:\n"
			<< clap.getEnergyPoints() << " energy points\n"
			<< clap.getAttackDamage() << " attack\n"
			<< clap.getHitPoints() << " hit points\n";
	return (new_out);
}

std::string ClapTrap::getName() const
{
	return (_name);
}

void ClapTrap::setName(std::string name)
{
	_name = name;
}

int ClapTrap::getHitPoints() const
{
	return (_hitPoint);
}

void ClapTrap::setHitPoints(int hitPoints)
{
	_hitPoint = hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return (_energyPoint);
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	_energyPoint = energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	_attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string &target)
{
	if (checkCapacity(true))
	{
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
	{
		std::cout << getName() << " can not lose " << amount << " hit points." << std::endl;
		return ;
	}
	std::cout << getName() << " lose " << amount << " hit points." << std::endl;
	if (getHitPoints() - amount >= 0)
		setHitPoints(getHitPoints() - amount);
	else
		setHitPoints(0);	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (checkCapacity(false))
	{
		std::cout << getName() << " repairs itself."
					<< " it gets " << amount << " hit points back" << std::endl;
		setHitPoints(getHitPoints() + amount);
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

bool ClapTrap::checkCapacity(bool attack)
{
	if (getHitPoints() < 1)
		std::cout << getName() << " is out of hit points\n" << std::endl;
	else if (getEnergyPoints() < 1)
		std::cout << getName() << " is out of energypoints" << std::endl;
	else if (attack && getAttackDamage() < 1)
		std::cout << getName() << " can not make any damage" << std::endl;
	else
		return (true);
	return (false);
}

void ClapTrap::doClassics(ClapTrap &other, unsigned int rep)
{
    
    std::cout << "\n\nBefore test :\n Target is " << other.getName() << ". " << other.getName() << " will take damage and then repairs itself of " << rep;
    std::cout << "\n\nMy info before :\n" << *this;
    std::cout << "\nTarget info before: \n" << other << std::endl;
    attack(other.getName());
    
    other.takeDamage(getAttackDamage());

    other.beRepaired(rep);
    
	doSpecifics();

    std::cout << "\nAfter test :\n";
    std::cout << "\nMy info after :\n" << *this;
    std::cout << "\nTarget info after: \n" << other << std::endl;
}

void ClapTrap::doSpecifics()
{
	std::cout << "I can not do anything special" << std::endl;
}