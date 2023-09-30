/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:23:42 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 00:43:43 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
}
void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n";
}
void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}
void Harl::error()
{
    std::cout << "This is unacceptable ! I want to speak to the manager now.\n";
}

int Harl::getIndex( std::string level )
{
	int index;
	std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (index = 0; index < 4; index++)
    {
        if (level == str[index])
            return index;
    }
    return index;
}

void Harl::complain( std::string level )
{
    void	(Harl::*func)(void);

	switch (getIndex(level))
	{
		case 0:
			func = &Harl::debug;
			break ;
		case 1:
			func = &Harl::info;
			break ;
		case 2:
			func = &Harl::warning;
			break ;
		case 3:
			func = &Harl::error;
			break ;
		default:
			std::cout << level << "is not recognised\n";
			func = NULL; 
	}
	if (func)
		(this->*func)();
}