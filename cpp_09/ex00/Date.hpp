/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:58:02 by srapin            #+#    #+#             */
/*   Updated: 2024/04/10 19:16:52 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DATAHPP_
#define _DATAHPP_

# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <stdlib.h>

class Date : public std::string
{
  protected:
	int d;
	int m;
	int y;

  public:
	Date();
	~Date();
	
	// Date(const Date &other);
	// Date &operator=(const Date &other);
	void parseInput(std::string input);
  
	Date(std::string input);

	class InvalidFormat : public std::exception
	{
		public:
			virtual const char *what() const throw();
			
	};
	class InvalidDate : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif