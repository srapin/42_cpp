/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:08:23 by srapin            #+#    #+#             */
/*   Updated: 2024/03/20 16:42:28 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"



template <typename T>
void print(T i)
{
	std::cout << i << std::endl;
}

int main( void ) {
	int intArray[] = {5, 4, 3, 2, 1};
	std::string  stringArray[] = {"lol", "waww", "\n"};
	iter(intArray, 5, print);
	iter(stringArray, 3, print);
	iter(intArray, 2, print);
}