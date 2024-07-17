#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_value = (intValue << this->_fBits);
}

Fixed::Fixed(const float floatValue)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_value = (roundf(floatValue * 256));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy Assignment operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

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

float Fixed::toFloat() const {
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
	Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)other.getRawBits());
	val.setRawBits((tmp1 * tmp2) / (1 << Fixed::_fBits));
	return (val);
}

// ---------- Increment/Decrement operators ---------- //

Fixed Fixed::operator++()
{
	this->_value++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;

	long nb = this->getRawBits();
	nb++;
	return (tmp);
}

Fixed Fixed::operator--()
{
	this->_value--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_value--;
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();	

	return (os);
}
