#include "Fixed.hpp"
// #include <iomanip>

int main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	// float f= 123456789.0f;
	// double d = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 +0.1 + 0.1 + 0.1 + 0.1;

	c = b;
	// std::cout << std::setprecision(10);
	// std::cout << "float: " << f << std::endl;
	// std::cout << std::setprecision(17);
	// std::cout << "double: " << d << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
