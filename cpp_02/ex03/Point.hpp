/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:30:01 by srapin            #+#    #+#             */
/*   Updated: 2024/01/30 21:19:05 by srapin           ###   ########.fr       */
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
    public:
        Point();
        Point(float x, float y);
        ~Point();
        Point(Point const &point);
        Point &operator=(Point const &point);
        bool    operator==(Point const &point) const;
        float   get_x(void) const;
        float   get_y(void) const;
};

std::ostream    &operator<<(std::ostream &new_out, Point const &point);
bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif