/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:57:58 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 00:48:39 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

void Contact::set_first_name()
{
    std::cout << "first name>";
    getline(std::cin, first_name);
}

void Contact::set_last_name()
{
    std::cout << "last name>";
    getline(std::cin, last_name);
}
void Contact::set_nick_name()
{
    std::cout << "nick name>";
    getline(std::cin, nick_name);
}

void Contact::set_phone_number()
{
    std::cout << "phone number>";
    getline(std::cin, phone_number);
}
void Contact::set_darkest_secret()
{
    std::cout << "darkest secret>";
    getline(std::cin, darkest_secret);
}


void Contact::set_index(int i)
{
    index = i;
}

bool Contact::check()
{
    bool flag;
    flag = (first_name.length() && last_name.length()  && nick_name.length()  && phone_number.length()  && darkest_secret.length() );
    if (!flag)
        set_index(-1);
    return flag;
}

bool Contact::add(int index)
{
    set_first_name();
    set_last_name();
    set_nick_name();
    set_phone_number();
    set_darkest_secret();
    set_index(index);
    return check();
}


void Contact::printPipe()
{
    std::cout << "|";
}

void Contact::printSpaces(std::string str)
{
    for (int i = str.length(); i < 10; i++)
        std::cout << " ";
}

void Contact::printInfo(std::string str)
{
    std::cout << str << "\n";
}

void Contact::printAll()
{
    if (index < 0)
        return;
    printInfo(first_name);
    printInfo(last_name);
    printInfo(nick_name);
    printInfo(phone_number);
    printInfo(darkest_secret);
}

void Contact::printShortInfo(std::string str)
{
    if (str.length() < 10)
    {
        std::cout<< std::setw(10) << str;
        // printSpaces(str);
        return;
    }
    for (int i=0; i < 9; i++)
        std::cout << str[i];
    std::cout << ".";
}

void Contact::printShort()
{
    if (index < 0)
        return;
    std::cout <<"|         " << index + 1;
    printPipe();
    printShortInfo(first_name);
    printPipe();
    printShortInfo(last_name);
    printPipe();
    printShortInfo(nick_name);
    printPipe();
    std::cout << "\n";
}

Contact::Contact()
{
    set_index(-1);
}