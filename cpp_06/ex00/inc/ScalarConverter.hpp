/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:43:12 by srapin            #+#    #+#             */
/*   Updated: 2024/03/15 21:35:36 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
#define SCALARCONVERTER
#include <iostream>
#include <string>
#include <string.h>
# include <cstdlib>
# include <cerrno>
# include <cmath>
# include <limits>
# include <iomanip>

// typedef enum 
// {
    
// }

class ScalarConverter
{
	protected:
		ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter &operator=(const ScalarConverter& other);

	public:
        virtual ~ScalarConverter();
		static void convert(const std::string &literal);
		
};

#endif