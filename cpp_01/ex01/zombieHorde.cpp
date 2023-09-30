/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:33:48 by srapin            #+#    #+#             */
/*   Updated: 2023/09/30 22:38:45 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *z;

	z = new (std::nothrow) Zombie[N];
	if (!z)
		return (NULL);
	for (int i = 0; i < N; i++)
		z[i].set_name(name);
	return (z);
}