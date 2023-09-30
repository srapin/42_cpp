/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:55:29 by srapin            #+#    #+#             */
/*   Updated: 2023/09/29 19:36:16 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "contact.hpp"

class PhoneBook
{
    private :
        int number_of_contact ;
        Contact contact[8];
        
    public :
        PhoneBook();
        void add();
        void search();
};


#endif