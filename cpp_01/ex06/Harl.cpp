/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:23:42 by srapin            #+#    #+#             */
/*   Updated: 2024/01/30 17:18:22 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "[DEBUG]\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
}
void Harl::info()
{
    std::cout << "[INFO]\n" <<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n";
}
void Harl::warning()
{
    std::cout << "[WARNING]\n" << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}
void Harl::error()
{
    std::cout << "[ERROR]\n" << "This is unacceptable ! I want to speak to the manager now.\n";
}

void Harl::unRecognized()
{
    std::cout << "Probably complaining about insignificant problems\n";
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
    return 4;
}

Harl::Harl(std::string level)
{
	void	(Harl::*func)(void);
	
	switch (getIndex(level))
	{
		case 0:
			func = &Harl::debug;
			(this->*func)();
		case 1:
			func = &Harl::info;
			(this->*func)();
		case 2:
			func = &Harl::warning;
			(this->*func)();
		case 3:
			func = &Harl::error;
			(this->*func)();
			break;
		default:
			func = &Harl::unRecognized;
			(this->*func)();
			
	}
}
