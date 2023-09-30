/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:55:26 by srapin            #+#    #+#             */
/*   Updated: 2023/09/30 20:25:11 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.hpp"

PhoneBook::PhoneBook()
{
    number_of_contact = 0;
}

void PhoneBook::add()
{
    // bool flag;
    
    if (!contact[number_of_contact].add(number_of_contact))
    {
        std::cout << "contact has not been saved because of an empty fiels\n";
    }
    number_of_contact++;
    if (number_of_contact >= 8)
        number_of_contact = 0;
    std::cout << "add\n";
}

void PhoneBook::search()
{
    std::string command;
    int i;
    
    for (int i = 0; i < 8; i++)
        contact[i].printShort();
    std::cout << ">";
    getline(std::cin, command);
    i = atoi( command.c_str() ) -1;
    // sscanf(command .c_str(), "%d", &i);
    // std::from_chars(command.c_str(), command.c_str() + command.length(), i);
    if (i < 0 || i > 7)
    {
        std::cout << "bad index\n";
        return;
    }
    
    contact[i].printAll();
    std::cout << "search\n";
}