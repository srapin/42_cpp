/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:58:02 by srapin            #+#    #+#             */
/*   Updated: 2023/10/12 19:40:13 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
# include <stdlib.h>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;
        int index;
        void set_first_name();
        void set_last_name();
        void set_nick_name();
        void set_phone_number();
        void set_darkest_secret();
        void set_index(int i);
        bool check();
        void printPipe();
        void printShortInfo(std::string str);
        void printInfo(std::string title, std::string str);
    public:
        Contact();
        bool add(int index);
        void printShort();
        void printAll();
        // std::string get_first_name();
        // std::string get_last_name();
        // std::string get_nick_name();
        // std::string get_phone_number();
        // std::string get_darkest_secret();
        // int         get_index();
        
};

#endif