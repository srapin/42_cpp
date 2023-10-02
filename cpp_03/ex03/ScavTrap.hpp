/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:49:38 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 20:51:17 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    private:
        /* data */
    protected:
        ScavTrap();
    public:
        ScavTrap(std::string name);
        ~ScavTrap();
        // ScavTrap &operator=(ScavTrap const &scavtrap);
        void attack(const std::string& target);
        void guardGate();
};




#endif