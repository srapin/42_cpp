/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:21:17 by srapin            #+#    #+#             */
/*   Updated: 2023/10/19 18:23:24 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string name;
    std::cout << "enter zombie name: ";
    if (!std::getline(std::cin, name))
        exit(0);
    Zombie *z = newZombie(name);
    z->announce();
    delete(z);
    std::cout << "enter random name: ";
    if (!std::getline(std::cin, name))
        exit(0);
    randomChump("bidule");
}