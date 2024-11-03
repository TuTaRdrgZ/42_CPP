/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:29:27 by tuta              #+#    #+#             */
/*   Updated: 2024/11/03 11:14:59 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Auxiliar function to calculate determinant
// det=(x1−x3)(y2−y3)−(x2−x3)(y1−y3)
Fixed determinant(const Point& p1, const Point& p2, const Point& p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) -
           (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

// Function that checks if a point is inside of a triangle
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = determinant(point, a, b);
    Fixed d2 = determinant(point, b, c);
    Fixed d3 = determinant(point, c, a);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	bool isOnEdge = ((d1 == 0) || (d2 == 0) || (d3 == 0));

	//  The point is inside the triangle if all the determinants
	//  contain the same sign.
	//  Edge count as outside of the triangle.
    return !(hasNeg && hasPos) && !isOnEdge;
}
