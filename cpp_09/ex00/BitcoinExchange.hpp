/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:15:16 by srapin            #+#    #+#             */
/*   Updated: 2024/03/26 05:05:41 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define DB_FILENAME "data.csv"

#include <map>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>

class Date : public std::string
{
    protected: 
        int d;
        int m;
        int y;
        
    public :
        std::string _input;
        Date() {};
        // Date(const Date& other) {(void) other;};
        // ~Date() {};
        // Date &operator=(const Date& other);
        Date(std::string input);
        
    bool operator<(const Date &nbr);
    bool operator==(const Date &nbr);
    // bool operator>(const Date &nbr);
    // bool operator!=(const Date &nbr);
    // bool operator<=(const Date &oth);
    // bool operator>=(const Date &oth);
    

    class InvalidFormat : public std::exception
    {
        public:
            virtual const char* what() const throw() {return "Not a valid format";};
    };
    class InvalidDate : public std::exception
    {
        public:
            virtual const char* what() const throw() {return "Is not a valide date";};
    };
};

// bool Date::operator<(const Date&){
    
// }



class BitcoinExchange
{
    private:
        std::map<Date, float> _db;
        std::ifstream _inputFile;
        float _v;
        Date _d;
        
	protected:

	public:

		BitcoinExchange();
		BitcoinExchange(std::string input_file);
        BitcoinExchange(const BitcoinExchange& other);
        virtual ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange& other);
        void checkOpen(std::string file, std::ifstream *stream, std::string toCheck);
        void setDb();

        class InvalidFile : public std::exception
        {
        public:
            virtual const char *what() const throw() { return "Not a valid file"; };
        };
};

#endif