#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();	

	return (os);
}

// Default constructor
Fixed::Fixed() : _value(0)
{
	// std::cout << "Default Constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

// Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// Constructor with int value
Fixed::Fixed(const int intValue)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_value = (intValue << this->_fBits);
}

// Constructor with float value
Fixed::Fixed(const float floatValue)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_value = (roundf(floatValue * (1 << this->_fBits)));
}

// Copy Assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

// ---------- Getters and Setters ---------- //
int Fixed::getRawBits() const
{
	// std::cout << "getRawBits function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits function called" << std::endl;
	_value = raw;
}

// ---------- Conversion functions ---------- //
float Fixed::toFloat() const
{
    return static_cast<float>(_value) / (1 << _fBits);
}

int Fixed::toInt(void) const
{
	return this->_value >> _fBits;
}

// ---------- Comparison operators ---------- //

bool Fixed::operator>(const Fixed& other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

// ---------- Arithmetic operators ---------- //

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;

	result.setRawBits((this->getRawBits() << _fBits) / other.getRawBits());
	return (result);
}

Fixed Fixed::operator*(Fixed const &other) const
{
    Fixed result;
    long tmp1 = static_cast<long>(_value);
    long tmp2 = static_cast<long>(other._value);
    result.setRawBits((tmp1 * tmp2) >> _fBits);
    return result;
}

// ---------- Increment/Decrement operators ---------- //

// pre-increment
Fixed &Fixed::operator++()
{
	++this->_value;
	return(*this);
}

// post-increment
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	++(*this);
	return (tmp);
}

// pre-decrement
Fixed &Fixed::operator--()
{
	this->_value--;
	return(*this);
}

// post-decrement
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

// ---------- min/max functions ---------- //

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}
