/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:30:01 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 02:49:00 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed _x;
        Fixed _y;
        /* data */
    public:
        Point(/* args */);
        Point(float x, float y);
        ~Point();
        Point(Point const &point);
        Point &operator=(Point const &point);
        bool    operator==(Point const &point) const;
        float   get_x(void) const;
        float   get_y(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif