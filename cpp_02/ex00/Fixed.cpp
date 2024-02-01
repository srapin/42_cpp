/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:00:22 by srapin            #+#    #+#             */
/*   Updated: 2024/02/01 20:42:14 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

int const       Fixed::_nFractionalBits = 8;

Fixed::Fixed() : _fixedPoint(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixed) : Fixed()
{
    // std::cout << "Copy constructor called" << std::endl;
    setRawBits(fixed.getRawBits());
}

Fixed &Fixed::operator= (Fixed const &Fixed)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(Fixed.getRawBits());
    return (*this);
} 

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    _fixedPoint = raw;
    
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}
