/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:48:50 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 21:46:58 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        /* data */
        std::string _name;
    protected:    
        DiamondTrap();
    public:
        DiamondTrap(std::string name);
        ~DiamondTrap();
        // DiamondTrap &operator=(DiamondTrap const &DiamondTrap);
        void attack(const std::string target);
        // using ScavTrap::attack();
        // using ScavTrap::getEnergyPoints;
        // using ScavTrap::setEnergyPoints;
        // using FragTrap::getHitPoints;
        // using FragTrap::setHitPoints;
        // using FragTrap::getAttackDamage;
        // using FragTrap::setAttackDamage;
        void whoAmI(void);
};




#endif