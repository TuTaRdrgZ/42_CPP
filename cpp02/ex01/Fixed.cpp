#include "Fixed.hpp"

// Default Constructor
Fixed::Fixed() : _value(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

// Default Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Constant Int constructor
Fixed::Fixed(const int intValue)
{
	this->_value = (intValue << this->_fBits);
	std::cout << "Int constructor called" << std::endl;
}

// Constant Float constructor
Fixed::Fixed(const float floatValue)
{
	this->_value = (roundf(floatValue * 256));
	std::cout << "Float constructor called" << std::endl;
}

// Copy Assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

// Getters and Setters
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

// Convertions
float Fixed::toFloat(void) const
{
	return ((float)this->_value / 256);
}

int Fixed::toInt(void) const
{
	return this->_value >> this->_fBits;
}
