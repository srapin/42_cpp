/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:36:01 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 21:15:50 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
# define BLUE "\x1b[36m"
#define RED "\x1b[31m"
# define END_CLR "\033[0m"


int arrayTest()
{
	const Animal **array = NULL;
	int i = 0;
    int N = 10;

	array = new (std::nothrow) Animal const*[N];
	if(!array)
		return (1);	
	while (i < N)
	{
		while (i < (N / 2))
		{
			array[i] = new Dog();
			i++;
		}
		array[i] = new Cat();
		i++;
	}
	i = 0;
	while (i < N)
	{
			array[i]->makeSound();
			i++;
	}
	i = 0;
	while (i < N)
	{
		delete array[i];
		i++;
	}
	delete[] array;
	return (0);
}


int copyTest()
{
	std::cout << "\n*** -> second test for deep copy of two objects cat <- ***\n" << std::endl;
	{
		Cat basic;
			{
				Cat tmp(basic);
				basic = tmp;
				std::cout << BLUE << "inside small scope" << std::endl;
				tmp.makeSound();
				basic.makeSound();
				std::cout << END_CLR;
			}
		std::cout << RED << "outside small scope" << std::endl;
		basic.makeSound();
		std::cout << END_CLR;
		return (0);
    }
}

int main()
{
	arrayTest();
	copyTest();
	
}