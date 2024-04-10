/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:15:16 by srapin            #+#    #+#             */
/*   Updated: 2024/04/10 17:55:58by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define DB_FILENAME "data.csv"

# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <stdlib.h>
#include "Date.hpp"

class BitcoinExchange
{
  protected:
	typedef enum parseError
	{
		none,
		neg,
		tobig,
	} parsError;

	std::map<Date, float> _db;
	std::ifstream _inputFile;
	Date		_d;
	parsError	_e;

	void printErr(std::string line);
	void treatLine(std::string line);
    void checkOpen(std::string file, std::ifstream *stream,
			std::string toCheck);
	void setDb();
	void output();
	float getNumber(std::string nb_str);
	BitcoinExchange();

	
  
  public:
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	BitcoinExchange(std::string input_file);
	virtual ~BitcoinExchange();
	

	class InvalidInputFile : public std::exception
	{
		public:
		virtual const char *what() const throw();
		
	};
	class InvalidDb : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	class lineError : public std::exception
	{
		public:
		virtual const char *what() const throw();

	};
	class InvalidUsage : public std::exception
	{
		public:
		virtual const char *what() const throw();

	};
};

#endif