/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:48:50 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 02:11:20 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public virtual FragTrap, public virtual ScavTrap
{
    private:
        std::string _name;
    protected:   
     
    public:
        DiamondTrap();
        std::string getName() const;
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap &operator=(const DiamondTrap& other);
        DiamondTrap(std::string name);
        ~DiamondTrap();
        void attack(const std::string &target);
        void whoAmI(void);

        void doSpecifics() override;
};




#endif