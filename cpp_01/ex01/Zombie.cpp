/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:15:44 by srapin            #+#    #+#             */
/*   Updated: 2023/09/30 22:41:18 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::set_name(std::string name)
{
    _name = name;
}

Zombie::Zombie() {}

Zombie::Zombie(std::string name)
{
    _name =name ;
}

Zombie::~Zombie()
{
    std::cout << _name << ": is destroyed\n";

}