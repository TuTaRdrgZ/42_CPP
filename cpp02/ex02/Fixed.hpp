/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:14:14 by bautrodr          #+#    #+#             */
/*   Updated: 2024/07/16 18:53:34 by tuta             ###   ########.fr       */
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

		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

        // ----------------- ex02 ----------------- \\

		// Comparison operators
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// Arithmetich operators
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Increment/Decrement operators
		Fixed operator++(); //pre-increment
		Fixed operator++(int); //post-increment
		Fixed operator--(); //pre-decrement
		Fixed operator--(int); //post-decrement
		
		// Overloaded functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

#endif
