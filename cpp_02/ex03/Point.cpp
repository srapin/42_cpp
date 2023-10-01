/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:41:31 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 04:04:42 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(float x, float y) : _x(x), _y(y){}

Point::Point(/* args */) : _x(0), _y(0) {}


Point::~Point() {}

Point::Point(Point const &point) : Point(point.get_x(), point.get_y()) {}

Point &Point::operator=(Point const &point)
{
    _x = Fixed(point.get_x());
    _y = Fixed(point.get_y());
    return *this;
}

bool    Point::operator==(Point const &point) const
{
    return (point.get_x() == get_x() && point.get_x() == get_y());
}

float   Point::get_x(void) const
{
    return _x.toFloat();
}
float   Point::get_y(void) const
{
    return _y.toFloat();
}