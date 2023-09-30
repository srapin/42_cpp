/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:04:38 by srapin            #+#    #+#             */
/*   Updated: 2023/09/30 23:20:43 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

std::string Weapon::getType()
{
    return _type;
}

void        Weapon::setType(std::string type)
{
    _type = type;
}

Weapon::Weapon(std::string type)
{
    _type = type;
}