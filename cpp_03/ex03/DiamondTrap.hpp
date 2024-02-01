/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:48:50 by srapin            #+#    #+#             */
/*   Updated: 2024/02/01 21:08:18 by srapin           ###   ########.fr       */
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
        void attack(const std::string target);
        void whoAmI(void);
};




#endif