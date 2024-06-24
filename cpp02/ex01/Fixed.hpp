/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:14:14 by bautrodr          #+#    #+#             */
/*   Updated: 2024/06/24 09:54:59 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _fBits = 8;

	public:
		// Default constructor
		Fixed();

		// Copy constructor
		Fixed(const Fixed& other);

		    // Constructor con un entero
		Fixed(const int intValue);

		// Constructor con un float
		Fixed(const float floatValue);

		// Copy assignment operator
		Fixed& operator=(const Fixed& other);

		// Destructor
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif
