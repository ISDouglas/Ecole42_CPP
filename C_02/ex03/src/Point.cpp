#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0))
{

}

Point::Point(const float x, const float y): _x(x), _y(y)
{

}

Point::Point(const Point& aPoint):_x(aPoint._x), _y(aPoint._y)
{

}

Point::~Point()
{
	std::cout << "Point Destructor called" << std::endl;
}

const Fixed &Point::getX(void) const
{
	return this->_x;
}

const Fixed &Point::getY(void) const
{
	return this->_y;
}
