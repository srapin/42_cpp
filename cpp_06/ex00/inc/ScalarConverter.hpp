/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:43:12 by srapin            #+#    #+#             */
/*   Updated: 2023/10/04 00:07:19 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
#define SCALARCONVERTER
#include <iostream>
#include <string>
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

	public:
		ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        virtual ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter& other);
		
};

#endif