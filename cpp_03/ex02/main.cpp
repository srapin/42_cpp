/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 04:20:35 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 20:35:55 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
// #include ""

int main() {
	ClapTrap c1("Clap");
	ScavTrap c2("Zoro");
	// ScavTrap aux = new ScavTrap("lol");
	ScavTrap c3(c2);
	ScavTrap c4("Luf");
	ScavTrap c5 = c4;
	FragTrap c6("Nam");
	// ScavTrap aux = new FragTrap("lol");
	FragTrap c7(c6);
	FragTrap c8("Uso");
	FragTrap c9 = c8;

	std::cout << std::endl;

	c1.attack("Slime");
	c2.attack("Sanji");
	c3.attack("Slime shiny");
	c4.attack("Truc");
	c5.attack("Mahcin");
	c6.attack("Bidule");
	c7.attack("Test");
	c8.attack("LOL");
	c9.attack("mdr");

	std::cout << std::endl;

	c1.takeDamage(80);
	c2.takeDamage(50);
	c3.takeDamage(5);
	c4.takeDamage(40);
	c5.takeDamage(500);
	c6.takeDamage(6);
	c7.takeDamage(7);
	c8.takeDamage(8);
	c9.takeDamage(9);


	std::cout << std::endl;

	c1.beRepaired(1000);
	c2.beRepaired(1);
	c3.beRepaired(5);
	c4.beRepaired(400);
	c5.beRepaired(50);
	c6.beRepaired(6);
	c7.beRepaired(7);
	c8.beRepaired(8);
	c9.beRepaired(9);

	std::cout << std::endl;

	c2.guardGate();
	c3.guardGate();
	c4.guardGate();
	c5.guardGate();

	std::cout << std::endl;

	c6.highFivesGuys();
	c7.highFivesGuys();
	c8.highFivesGuys();
	c9.highFivesGuys();

	std::cout << std::endl;
}