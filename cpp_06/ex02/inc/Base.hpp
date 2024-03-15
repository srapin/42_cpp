/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:08:27 by srapin            #+#    #+#             */
/*   Updated: 2024/03/15 23:42:47 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BASE
#define _BASE

#include <cstdlib>
#include <iostream>
#include <unistd.h> 

class Base
{
	public:
        virtual ~Base() {};
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif