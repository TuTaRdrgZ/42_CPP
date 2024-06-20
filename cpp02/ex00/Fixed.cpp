#include "Fixed.hpp"
#include <cstdio>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits function called" << std::endl;
	_value = raw;
}
