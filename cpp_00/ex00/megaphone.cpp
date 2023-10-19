/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:28:34 by srapin            #+#    #+#             */
/*   Updated: 2023/10/17 18:22:06 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int word = 1; word < ac; word++)
        {
            std::string str(av[word]);
            for (int i = 0; i < str.length(); i++)
                std::cout << (char)toupper(av[word][i]);
        }
    }
    std::cout << std::endl;
}