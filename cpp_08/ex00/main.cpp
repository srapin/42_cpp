/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:08:23 by srapin            #+#    #+#             */
/*   Updated: 2024/03/21 13:42:54 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vec;
    std::list<int> lst;
    
    for (int i = 0; i < 20; i++)
    {
        vec.push_back(i % 10);
        lst.push_back(-i % 10);
    }
    std::cout << easyfind(vec, 3) << std::endl;
    std::cout << easyfind(vec, 11) << std::endl;
    std::cout << easyfind(lst, -8) << std::endl;
    std::cout << easyfind(lst, 11) << std::endl;
}