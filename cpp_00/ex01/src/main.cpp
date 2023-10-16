/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:59:38 by srapin            #+#    #+#             */
/*   Updated: 2023/10/12 19:15:02 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

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
    }
}