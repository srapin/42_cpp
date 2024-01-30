/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:21:17 by srapin            #+#    #+#             */
/*   Updated: 2023/10/19 18:32:00 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string name;
    std::string nb_str;
    int nb;

    std::cout << "enter zombie name: ";
    if (!std::getline(std::cin, name))
        exit(0);
    std::cout << "enter zombie nbrs: ";
    if (!std::getline(std::cin, nb_str))
        exit(0);
    nb = std::atoi(nb_str.c_str());
    Zombie *z = zombieHorde(nb, name);
    for (int i = 0; i < nb; i++)
    {
      std::cout << "Zombie nbr " << i << ":";
		  z[i].announce();
    }
    delete [] z;
}