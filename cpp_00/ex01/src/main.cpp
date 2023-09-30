/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:59:38 by srapin            #+#    #+#             */
/*   Updated: 2023/09/29 20:08:00 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.hpp"

int main()
{
    PhoneBook book;
    std::string	command;
    
    
    while (true)
    {
        std::cout << ">";
        getline(std::cin, command);

        if (command == "ADD")
            book.add();
        else if (command == "SEARCH")
            book.search();
        else if (command == "EXIT")
        {
            std::cout << "exit" << std::endl;
            break;
        }
        else
            std::cout << "You enterd a wrong command\n";
        
    }
}