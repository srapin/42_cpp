/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:55:26 by srapin            #+#    #+#             */
/*   Updated: 2023/10/17 18:39:30 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    number_of_contact = 0;
}

void PhoneBook::add()
{
    if (!contact[number_of_contact].add(number_of_contact))
    {
        std::cout << "contact has not been saved because of an empty fiels\n";
        return;
    }
    number_of_contact++;
    if (number_of_contact >= 8)
        number_of_contact = 0;
}

void PhoneBook::search()
{
    std::string command;
    int i;
    
    std::cout << std::setw(11) << "index|";
    std::cout << std::setw(11) << "first name|";
    std::cout << std::setw(11) << "last name|";
    std::cout << std::setw(11) << "nickname|" << std::endl;
    for (int i = 0; i < 8; i++)
        contact[i].printShort();
    std::cout << "enter index >";
    getline(std::cin, command);
    i = atoi( command.c_str() ) -1;
    if (i < 0 || i > 7)
    {
        std::cout << "bad index\n";
        return;
    }
    contact[i].printAll();
}