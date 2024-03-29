/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:08:23 by srapin            #+#    #+#             */
/*   Updated: 2024/03/24 23:37:59 by srapin           ###   ########.fr       */
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
    std::cout << *easyfind(vec, 3) << std::endl;
    try
    {
        std::cout << *easyfind(vec, 11) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << *easyfind(lst, -8) << std::endl;
    try
    {
        std::cout << *easyfind(lst, 11) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}