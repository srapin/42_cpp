/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:21:51 by srapin            #+#    #+#             */
/*   Updated: 2023/09/30 23:24:55 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name)
{
    _name = name;
}

void	HumanB::setWeapon(Weapon &Weapon)
{
    _weapon = &Weapon;
}


void	HumanB::attack(void)
{
    if (_weapon)
        std::cout << _name << " attacks with their "<< _weapon->getType() << std::endl;
}