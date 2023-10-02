/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 04:20:35 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 20:23:26 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
// #include ""

int main() {

	ClapTrap c1("Clap");
	ScavTrap c2("Zoro");
	// ScavTrap aux = new ScavTrap("lol");
	ScavTrap c3(c2);
	ScavTrap c4("Luf");
	ScavTrap c5 = c4;

	std::cout << std::endl;

	c1.attack("Slime");
	c2.attack("Sanji");
	c3.attack("Slime shiny");

	std::cout << std::endl;

	c1.takeDamage(80);
	c2.takeDamage(50);
	c2.takeDamage(50);
	c3.takeDamage(5);
	c4.takeDamage(40);
	c5.takeDamage(500);


	std::cout << std::endl;

	c1.beRepaired(1000);
	c2.beRepaired(1);
	c3.beRepaired(5);
	c2.beRepaired(400);
	c3.beRepaired(50);

	std::cout << std::endl;

	c2.guardGate();
	c3.guardGate();
	c4.guardGate();
	c5.guardGate();

	std::cout << std::endl;
}