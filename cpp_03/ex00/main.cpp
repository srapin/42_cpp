/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 04:20:35 by srapin            #+#    #+#             */
/*   Updated: 2024/02/01 20:51:58 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

#include <iostream>

int main() {
	ClapTrap *c1 = new ClapTrap("lol");
	ClapTrap *c2 = new ClapTrap("Zoro");
	ClapTrap *c3 = new ClapTrap(*c1);

	std::cout << std::endl;

	c1->attack("Slime");
	c2->attack("Sanji");
	c3->attack("Slime shiny");

	std::cout << std::endl;

	c1->takeDamage(80);
	c2->takeDamage(5);
	c2->takeDamage(5);
	c2->takeDamage(5);
	c3->takeDamage(5);

	// std::cout << std::endl;

	c1->beRepaired(1000);
	c2->beRepaired(1);
	c3->beRepaired(5);

	// std::cout << std::endl;

	delete c1;
	delete c2;
	delete c3;
}