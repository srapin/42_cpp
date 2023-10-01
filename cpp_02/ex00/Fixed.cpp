/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:00:22 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 01:21:02 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

int const       Fixed::_nFractionalBits = 8;

Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixed) : Fixed()
{
    std::cout << "Copy constructor called" << std::endl;
    setRawBits(fixed.getRawBits());
}

Fixed &Fixed::operator= (Fixed const &Fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(Fixed.getRawBits());
    return (*this);
} 

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
