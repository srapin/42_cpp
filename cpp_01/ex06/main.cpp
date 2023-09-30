/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:36:48 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 00:46:07 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac <= 1)
    {
        std::cout << "bad args\n";
        return (1);
    }
    Harl harl(av[1]);
    // harl.complain("WARNING");
    // harl.complain("DEBUG");
    // harl.complain("INFO");
    // harl.complain("ERROR");
    // harl.complain("lol");
    
}