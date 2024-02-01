/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 04:20:40 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 21:51:55 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _hitPoint;
        int _energyPoint;
        int _attackDamage;
	protected :
        ClapTrap();
        ClapTrap(int hp, int ep, int ad);
		std::string getName() const;
		void setName(std::string Name);
		int getHitPoints() const;
		void setHitPoints(int HitPoints);
		int getEnergyPoints() const;
		void setEnergyPoints(int EnergyPoints);
		int getAttackDamage() const;
		void setAttackDamage(int AttackDamage);
    public:
        ClapTrap(std::string name);
        void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		ClapTrap(const ClapTrap &copy);

		~ClapTrap();

		ClapTrap & operator=(const ClapTrap &assign);

};

#endif