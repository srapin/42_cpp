/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 04:20:35 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 21:44:05 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
// #include ""
int foo() {
	return 5;}

int main() {
	ScavTrap *c1 = new ScavTrap("lol");
	DiamondTrap *c2 = new DiamondTrap("Zoro");
	DiamondTrap *aux = new DiamondTrap("maud");
	DiamondTrap *c3 = new DiamondTrap(*aux);
	int a = 15;
	a-=2;
	foo();
	std::cout << std::endl;

	c1->attack("Slime");
	c2->attack("Sanji");
	c3->attack("Slime shiny");

	std::cout << std::endl;

	c1->takeDamage(80);
	c2->takeDamage(50);
	c2->takeDamage(50);
	c3->takeDamage(5);

	std::cout << std::endl;

	c1->beRepaired(1000);
	c2->beRepaired(1);
	c3->beRepaired(5);

	std::cout << std::endl;

	c1->guardGate();

	c2->guardGate();
	c3->guardGate();

	c2->highFivesGuys();
	c3->highFivesGuys();

	c2->whoAmI();
	c3->whoAmI();

	std::cout << std::endl;

	delete c1;
	delete c2;
	delete aux;
	delete c3;
}