/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:44:13 by srapin            #+#    #+#             */
/*   Updated: 2023/10/03 23:44:21 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */)
{
	std::cout << "ScalarConverter: Default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {

	std::cout << "ScalarConverter: Copy constructor" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	std::cout << "ScalarConverter: Assignment operator" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter: Destructor" << std::endl;
}