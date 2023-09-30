/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:21:17 by srapin            #+#    #+#             */
/*   Updated: 2023/09/30 22:42:30 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *z = zombieHorde(10, "truc");
    for (int i = 0; i < 10; i++)
		z[i].announce();

    delete [] z;
    // z->announce();
    // randomChump("bidule");
    // delete(z);
}