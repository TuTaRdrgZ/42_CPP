/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuta <bautrodr@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:36:26 by tuta              #+#    #+#             */
/*   Updated: 2024/07/17 16:45:52 by tuta             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	// add the bsp tests here
	std::cout << bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(0.5f, 0.5f)) << std::endl; // should return true
	std::cout << bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 1)) << std::endl; // should return false

	Point a(3, 5);
	Point b(1, 1);
	Point c(5, 1);

	return (0);
}
