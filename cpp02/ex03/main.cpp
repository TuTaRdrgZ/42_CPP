/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:36:26 by tuta              #+#    #+#             */
/*   Updated: 2024/11/03 11:23:42 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	// First triangle
	Point a(Fixed(0), Fixed(0));
    Point b(Fixed(3), Fixed(0));
    Point c(Fixed(0), Fixed(4));

	// Second triangle
	Point a1(Fixed(8), Fixed(1));
    Point b1(Fixed(1.5f), Fixed(8));
    Point c1(Fixed(2), Fixed(3));

	// Third triangle with floats
	Point a2(0.5f, 8.5f);
	Point b2(5.5f, 0.5f);
	Point c2(1.23f, 1.5f);
	
	// Point 
    Point p(Fixed(0.5f), Fixed(2));
    Point p1(Fixed(2), Fixed(1));
    Point p2(Fixed(8), Fixed(4));

	Point p3(2.3f, 4.5f);

    std::cout << (bsp(a, b, c, p)) << std::endl;
    std::cout << (bsp(a, b, c, p1)) << std::endl;
	std::cout << (bsp(a1,b1,c1,p1)) << std::endl;
	std::cout << (bsp(a1,b1,c1,p2)) << std::endl;
	std::cout << (bsp(a2,b2,c2,p3)) << std::endl;

	return (0);
}
