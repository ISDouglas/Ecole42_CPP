#include "../includes/Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
    _rawBits = 0;
    std::cout << "Default constructor called" << std::endl;
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
