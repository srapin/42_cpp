/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:00:05 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 01:20:56 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
        ~Fixed();
};




#endif
