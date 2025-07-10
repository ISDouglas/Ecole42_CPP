#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	_rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const	int	intValue)
{
	_rawBits = intValue << this->_fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const	float floatValue)
{
	_rawBits = roundf(floatValue * (1 << this->_fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& aFixed)
{
	this->_rawBits = aFixed._rawBits;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_rawBits = other._rawBits;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this; 
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_rawBits) / (1 <<this->_fractionalBits);
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
