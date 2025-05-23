/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:34:52 by tuta              #+#    #+#             */
/*   Updated: 2024/11/03 11:19:03 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal)
{
}

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return *this;
}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}
