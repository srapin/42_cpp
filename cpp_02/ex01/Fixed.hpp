/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:00:05 by srapin            #+#    #+#             */
/*   Updated: 2024/01/30 23:05:53 by srapin           ###   ########.fr       */
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
};

std::ostream    &operator<<(std::ostream &new_out, Fixed const &fixed);

#endif
