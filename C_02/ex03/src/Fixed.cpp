#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

// constructor  functions
Fixed::Fixed()
{
	_rawBits = 0;
	std::cout << "Fixed Default constructor called" << std::endl;
}

Fixed::Fixed(const	int	intValue)
{
	_rawBits = intValue << this->_fractionalBits;
	std::cout << "Fixed Int constructor called" << std::endl;
}

Fixed::Fixed(const	float floatValue)
{
	_rawBits = roundf(floatValue * (1 << this->_fractionalBits));
	std::cout << "Fixed Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& aFixed)
{
	this->_rawBits = aFixed._rawBits;
	std::cout << "Fixed Copy constructor called" << std::endl;
}

// operator  functions
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_rawBits = other._rawBits;
	}
	std::cout << "Fixed Copy assignment operator called" << std::endl;
	return *this; 
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->_rawBits > other._rawBits; 
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	int64_t raw = static_cast<int64_t>(this->_rawBits) * static_cast<int64_t>(other._rawBits);
	result.setRawBits(static_cast<int>(raw >> this->_fractionalBits));
	return result;	
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	if (other._rawBits == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return result;	
	}
	int64_t raw = static_cast<int64_t>(this->_rawBits) << _fractionalBits;
	raw /= static_cast<int64_t>(other._rawBits);
	result.setRawBits(static_cast<int>(raw));
	return result;
}

// ++a
Fixed &Fixed::operator++() {
    this->_rawBits += 1;
    return *this;
}

// a++
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_rawBits += 1;
    return temp;
}

// --a
Fixed &Fixed::operator--() {
    this->_rawBits -= 1;
    return *this;
}

// a--
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_rawBits -= 1;
    return temp;
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Fixed Destructor called" << std::endl;
}

// member functions
float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_rawBits) / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_rawBits >> this->_fractionalBits;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}
