/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:58:24 by srapin            #+#    #+#             */
/*   Updated: 2023/10/19 18:53:39 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"


void subject_test()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
}

std::string getName()
{
    std::string name;
    
    std::cout << "Enter name: ";
    if (std::getline(std::cin, name))
        return name;
    return NULL;
}

std::string getWeaponType()
{
    std::string type;
    
    std::cout << "Enter weapon type: ";
    if (std::getline(std::cin, type))
        return type;
    return NULL;
}

void    testHumanA()
{
    std::string name = getName();
    std::string type = getWeaponType();
    Weapon w = Weapon(type);
    
    HumanA h(name, w);
    h.attack();
}

void    testHumanB()
{
    std::string name = getName();
    std::string choice;
    HumanB h(name);
    std::cout << "enter 'y' to arme " << name << " :";
    if (!std::getline(std::cin, choice))
        return;
    if (choice == "y")
    {
        std::string type = getWeaponType();
        Weapon w = Weapon(type);
        h.setWeapon(w);
    }
    
    h.attack();
}

int main()
{
    std::string type;
    subject_test();
    
    std::cout << "Enter type (a or b) or 'exit' to exit: ";
    while(std::getline(std::cin, type) && type != "exit")
    {
        if (type == "a")
            testHumanA();
        if (type =="b")
            testHumanB();
        std::cout << "Enter type (a or b) or 'exit' to exit: ";
    }
    return 0;
}
