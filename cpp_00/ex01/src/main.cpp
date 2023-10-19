/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:59:38 by srapin            #+#    #+#             */
/*   Updated: 2023/10/19 19:49:14 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int main()
{
    PhoneBook book;
    std::string	command;
    
    std::cout << ">";
    while (getline(std::cin, command) && command != "EXIT")
    {

        if (command == "ADD")
            book.add();
        else if (command == "SEARCH")
            book.search();
        std::cout << ">";
    }
}