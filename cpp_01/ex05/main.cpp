/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:36:48 by srapin            #+#    #+#             */
/*   Updated: 2023/10/19 19:04:42 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;
    harl.complain("WARNING");
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("ERROR");
    harl.complain("bad");
    
    std::string lev;
    std::cout << "enter a complaining level or 'exit' to exit: ";
    while (getline(std::cin, lev) && lev != "exit")
    {
        harl.complain(lev);
        std::cout << "enter a complaining level or 'exit' to exit: ";
    }
}