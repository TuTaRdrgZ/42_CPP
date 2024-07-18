/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:36:26 by tuta              #+#    #+#             */
/*   Updated: 2024/07/18 22:29:14 by tuta             ###   ########.fr       */
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
	Point a1(Fixed(8), Fixed(0));
    Point b1(Fixed(0), Fixed(8));
    Point c1(Fixed(0), Fixed(3));
	
    Point p(Fixed(1), Fixed(1));
    Point p1(Fixed(2), Fixed(1));
    Point p2(Fixed(8), Fixed(4));

    std::cout << (bsp(a, b, c, p)) << std::endl;
    std::cout << (bsp(a, b, c, p1)) << std::endl;
	std::cout << (bsp(a1,b1,c1,p2)) << std::endl;

	return (0);
}
