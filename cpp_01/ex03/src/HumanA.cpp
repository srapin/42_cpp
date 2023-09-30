/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:11:20 by srapin            #+#    #+#             */
/*   Updated: 2023/09/30 23:19:03 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon) : _weapon(Weapon)
{
    _name = name;
}

void	HumanA::attack(void)
{
    std::cout << _name << " attacks with their "<< _weapon.getType() << std::endl;
}