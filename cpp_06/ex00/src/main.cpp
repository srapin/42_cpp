/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:00:10 by srapin            #+#    #+#             */
/*   Updated: 2024/03/15 22:03:46 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

#include <iostream>

int main(int argc, char *argv[]) 
{
	if (argc == 1) 
	{
		std::cerr << "Error: no parameters\n" << "Usage: ./ScalarConverter <arg>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	return 0;
}