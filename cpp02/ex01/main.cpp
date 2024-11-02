#include "Fixed.hpp"
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();	

	return (os);
}

// class Math {
// 	public:
// 		int add(int a, int b)
// 		{
// 			return a+b;
// 		}

// 		int add(int a, int b, int c)
// 		{
// 			return a+b+c;
// 		}

// 		double add(double a, double b)
// 		{
// 			return a+b;
// 		}
// };

int main( void )
{
	// std::cout << "-----------Function Overload-------------" << std::endl;

	// Math math;

	// std::cout << math.add(1, 2) << std::endl;
	// std::cout << math.add(1, 2, 3) << std::endl;
	// std::cout << math.add(1.5 , 2.75) << std::endl;
	
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
