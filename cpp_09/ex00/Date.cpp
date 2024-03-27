/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 02:16:47 by srapin            #+#    #+#             */
/*   Updated: 2024/03/27 16:00:29 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Date::Date(std::string input) : std::string(input.c_str())
{
	if (input.empty() || input.size() != 10 || input[4] != '-' || input[7] != '-')
        throw InvalidFormat();
    std::string year = input.substr(0, 4);
    std::string month = input.substr(5, 2);
    std::string days = input.substr(8, 2);
	if (days.find_first_not_of("0123456789") != std::string::npos || month.find_first_not_of("0123456789") != std::string::npos || year.find_first_not_of("0123456789") != std::string::npos)
        throw InvalidFormat();
    d = atoi(days.c_str());
    m = atoi(month.c_str());
    y = atoi(year.c_str());
    if (y < 2009 || y > 2022 || m > 12 || d > 31 || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30))
        throw InvalidDate();
    if (m == 2 && d > (((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 28 : 29))
        throw InvalidDate();
}

// bool Date::operator<(const Date &oth)
// {
//     std::cout << "called";
//     if (y != oth.y)
//         return (y < oth.y);
//     if (m != oth.m)
//         return (m < oth.m);
//     if (d != oth.d)
//         return (d < oth.d);
//     return false;
// }

// bool Date::operator==(const Date &oth)
// {
//     return (y == oth.y && m ==oth.m && d==oth.d);
// }

// bool Date::operator!=(const Date &oth)
// {
//     return false;
// }

// bool Date::operator>=(const Date &oth)
// {
//     return false;
// }

// bool Date::operator>(const Date &oth)
// {
//     return false;
// }

// bool Date::operator<=(const Date &oth)
// {
//     return false;
// }