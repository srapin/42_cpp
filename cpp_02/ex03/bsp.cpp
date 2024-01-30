/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:42:06 by srapin            #+#    #+#             */
/*   Updated: 2024/01/30 21:31:46 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float foo(Point const a, Point const b, Point const c)
{
    float xa, xb, xc;
    float ya, yb, yc;

    xa = a.get_x();
    ya = a.get_y();
    xb = b.get_x();
    yb = b.get_y();
    xc = c.get_x();
    yc = c.get_y();
    return (fabs(xa * (yb - yc) + xb * (yc - ya) + xc * (ya - yb)) / 2.0);
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float obj;
    float ab, bc, ac;

    obj = foo(a, b, c);
    ab = foo(a,b, point);
    bc = foo(b, c, point);
    ac = foo(a, c, point);
    std::cout << ab << " "<< bc << " " << ac << " " << ab +bc+ac << " " << obj << std::endl;
    return (ab + bc + ac == obj && ab && bc && ac);
}