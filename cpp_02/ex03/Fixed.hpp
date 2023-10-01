/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:00:05 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 01:50:20 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
    private:
        int                 _fixedPoint;
        static int const    _nFractionalBits;
    public:
        Fixed();
        Fixed(Fixed const &fixed);
        Fixed &operator= (Fixed const &Fixed); 
        int getRawBits(void) const;
        void setRawBits(int const raw);
        ~Fixed();
        Fixed(const int i);
        Fixed(const float f);
        float   toFloat(void) const;
        int     toInt(void) const;

        Fixed operator+(Fixed const &Fixed);
        Fixed operator-(Fixed const &Fixed);
        Fixed operator/(Fixed const &Fixed);
        Fixed operator*(Fixed const &Fixed);
        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);
        bool operator<(Fixed const &fixed) const;
        bool operator>(Fixed const &fixed) const;
        bool operator<=(Fixed const &fixed) const;
        bool operator>=(Fixed const &fixed) const;
        bool operator!=(Fixed const &fixed) const;
        bool operator==(Fixed const &fixed) const;
        static Fixed &min(Fixed &fixed1, Fixed &fixed2);
        static Fixed &min(Fixed const &fixed1, Fixed const &fixed2);
        static Fixed &max(Fixed &fixed1, Fixed &fixed2);
        static Fixed &max(Fixed const &fixed1, Fixed const &fixed2);
};

std::ostream    &operator<<(std::ostream &new_out, Fixed const &fixed);

#endif
