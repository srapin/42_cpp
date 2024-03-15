/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:44:13 by srapin            #+#    #+#             */
/*   Updated: 2024/03/15 22:10:49 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter: Default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;
	std::cout << "ScalarConverter: Copy constructor" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void) other;
	std::cout << "ScalarConverter: Assignment operator" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter: Destructor" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;
	int i = 0;

	std::string pseudoTypes[6] = 
	{
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};
	

	
	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		std::cout << "char: " << literal[0] << "\nint: " << static_cast<int>(literal[0]) << "\nfloat: " << static_cast<float>(literal[0]) << ".0f\ndouble: " << static_cast<double>(literal[0]) << ".0" << std::endl;
		return ;
	}

	
	for (; literal != pseudoTypes[i] && i < 6 ;i++) {}
	if (i < 6)
	{
		std::cout << "char: impossible\nint: impossible" << std::endl;
		std::cout << "float: " << pseudoTypes[i % 3] << "\ndouble: " << pseudoTypes[3 + i%3] << std::endl;
		return;
	}

	
	if (literal[literal.length() - 1] == 'f')
	{
		toFloat = std::atof(literal.c_str());
		toInt = static_cast<int>(toFloat);
		toDouble = static_cast<double>(toFloat);
	}
	else if (strchr(literal.c_str(), '.'))
	{
		toDouble = std::atof(literal.c_str());
		toInt = static_cast<int>(toDouble);
		toFloat = static_cast<float>(toDouble);
	}
	else if (i == 6)
	{
		toInt = std::atoi(literal.c_str());
		toDouble = static_cast<double>(toInt);
		toFloat = static_cast<float>(toInt);
	}
	
	std::cout << "char: ";
	if (!(isprint(static_cast<char>(toInt))))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(toInt) << "'";
	std::cout << "\nint: " << toInt << "\nfloat: " << toFloat;
	if (!(toFloat - static_cast<int>(toFloat)))
		std::cout << ".0f";
	std::cout << "\ndouble: " << toDouble;
	if (!(toDouble - static_cast<int>(toDouble)))
		std::cout << ".0";
	std::cout << std::endl;
}