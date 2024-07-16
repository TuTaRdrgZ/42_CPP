#include "Fixed.hpp"
#include <iterator>

int main( void )
{
	// Subject example
	
	std::cout << "----------- SUBJECT EXAMPLE -----------" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// Comparison operators
	
	std::cout << "----------- COMPARISON OPERATORS -----------" << std::endl;
	Fixed c(10);
	Fixed d(11);
	std::cout << "c= " << c << std::endl << "d= " << d << std::endl;
	std::cout << "Is c greater than d? -> ";
	std::cout << (c > d) << std::endl;
	std::cout << "Is c lower than d? -> ";
	std::cout << (c < d) << std::endl;
	std::cout << "Is c lower or equal than d? -> ";
	std::cout << (c <= d) << std::endl;
	std::cout << "Is c greater or equal than d? -> ";
	std::cout << (c >= d) << std::endl;
	std::cout << "Is c different than d? -> ";
	std::cout << (c != d) << std::endl;
	std::cout << "Is c equal than d? -> ";
	std::cout << (c == d) << std::endl;
	d = 10;
	std::cout << "c= " << c << std::endl << "d= " << d << std::endl;
	std::cout << "Is c greater than d? -> ";
	std::cout << (c > d) << std::endl;
	std::cout << "Is c lower than d? -> ";
	std::cout << (c < d) << std::endl;
	std::cout << "Is c lower or equal than d? -> ";
	std::cout << (c <= d) << std::endl;
	std::cout << "Is c greater or equal than d? -> ";
	std::cout << (c >= d) << std::endl;
	std::cout << "Is c different than d? -> ";
	std::cout << (c != d) << std::endl;
	std::cout << "Is c equal than d? -> ";
	std::cout << (c == d) << std::endl;

	// Arithmetic Operators
	
	std::cout << "----------- ARITHMETIC OPERATORS -----------" << std::endl;
	Fixed e(42);
	Fixed f(24);
	std::cout << "e = " << e << std::endl << "f = " << f << std::endl;
	std::cout << "(e + f)-> " << (e + f) << std::endl;
	std::cout << "(e - f)-> " << (e - f) << std::endl;
	std::cout << "(e / f)-> " << (e / f) << std::endl;
	std::cout << "(e * f)-> " << (e * f) << std::endl;

	// Increment/Decrement Operators
	
	std::cout << "----------- INCREMENT/DECREMENT OPERATORS -----------" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	// min/max functions
	
	std::cout << "----------- MIN/MAX FUNCTIONS -----------" << std::endl;
	Fixed g(123.123f);
	Fixed h(124);
	Fixed const i(12);
	Fixed const j(8);

	std::cout << "g = " << g << std::endl << "h = " << h << std::endl;
	std::cout << "i = " << i << std::endl << "j = " << j << std::endl;
	std::cout << "min(g, h)-> ";
	std::cout << Fixed::min(g, h) << std::endl;
	std::cout << "max(g, h)-> ";
	std::cout << Fixed::max(g, h) << std::endl;
	std::cout << "const min(i, j)-> ";
	std::cout << Fixed::min(i, j) << std::endl;
	std::cout << "const max(i, j)-> ";
	std::cout << Fixed::max(i, j) << std::endl;

	return 0;
}
