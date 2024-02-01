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
    //// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixed) : Fixed()
{
    //// std::cout << "Copy constructor called" << std::endl;
    setRawBits(fixed.getRawBits());
}

Fixed &Fixed::operator= (Fixed const &Fixed)
{
    //// std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(Fixed.getRawBits());
    return (*this);
} 

int Fixed::getRawBits(void) const
{
    //// std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPoint = raw;
}

Fixed::~Fixed()
{
    //// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const i) {

	//// std::cout << "Int constructor called" << std::endl;
	setRawBits(i * pow(2, _nFractionalBits));
}

Fixed::Fixed(float const f) {
	// std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(f * pow(2, _nFractionalBits)));
    int exp = 0, exp_mask = 0x7f800000;
    int *test = (int *)&f;
    *test = *test & exp_mask;
    *test = *test >> 23;
    if (*test == 0xff)
    {
        setRawBits(0);
	    // std::cout << "Bad float, value set to 0" << std::endl;
    }
}

float   Fixed::toFloat(void) const
{
    return (float(getRawBits() / pow(2, _nFractionalBits)));
}

int     Fixed::toInt(void) const
{
    return (getRawBits() / pow(2, _nFractionalBits));
}

std::ostream    &operator<<(std::ostream &new_out, Fixed const &fixed)
{
    new_out << fixed.toFloat();
    return new_out;
}

Fixed Fixed::operator+(Fixed const &fixed)
{
    return (Fixed(toFloat() + fixed.toFloat()));
}
Fixed Fixed::operator-(Fixed const &fixed)
{
    return (Fixed(toFloat() - fixed.toFloat()));
}
Fixed Fixed::operator/(Fixed const &fixed)
{
    return (Fixed(toFloat() / fixed.toFloat()));
}
Fixed Fixed::operator*(Fixed const &fixed)
{
    return (Fixed(toFloat() * fixed.toFloat()));
}
Fixed Fixed::operator++()
{
    _fixedPoint++;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;

    _fixedPoint++;
    return tmp;
}
Fixed Fixed::operator--()
{
    _fixedPoint--;
    return (*this);
}
Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;

    _fixedPoint--;
    return tmp;
}
bool Fixed::operator<(Fixed const &fixed) const
{
    return (getRawBits() < fixed.getRawBits());
}
bool Fixed::operator>(Fixed const &fixed) const
{
    return !(*this <= fixed);
}
bool Fixed::operator<=(Fixed const &fixed) const
{
    return (*this < fixed || *this == fixed);
}
bool Fixed::operator>=(Fixed const &fixed) const
{
    return !(*this >= fixed);
}
bool Fixed::operator!=(Fixed const &fixed) const
{
    return !(*this == fixed);
}
bool Fixed::operator==(Fixed const &fixed) const
{
    return (getRawBits() == fixed.getRawBits());
}
Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1 < fixed2)
        return fixed1;
    return fixed2;
}
Fixed &Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
    if (fixed1 < fixed2)
        return (Fixed&) fixed1;
    return (Fixed&) fixed2;
}
Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    if (fixed1 > fixed2)
        return fixed1;
    return fixed2;
    
}
Fixed &Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
    if (fixed1 > fixed2)
        return (Fixed&) fixed1;
    return (Fixed&) fixed2;
}