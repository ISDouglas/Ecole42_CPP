#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& aPoint);
		~Point();
		Point &operator=(const Point &other) = delete;
		// member functions
		const Fixed &getX(void) const;
		const Fixed &getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif