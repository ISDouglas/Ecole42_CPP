#include "../includes/Point.hpp"

static Fixed crossProduct(Point const &s, Point const &e, Point const &p)
{
	Fixed se_x = e.getX() - s.getX();
	Fixed se_y = e.getY() - s.getY();
	Fixed sp_x = p.getX() - s.getX();
	Fixed sp_y = p.getY() - s.getY();
	return se_x * sp_y - se_y * sp_x;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed x = crossProduct(a, b, point);
	Fixed y = crossProduct(b, c, point);
	Fixed z = crossProduct(c, a, point);
	if ((x <= 0 && y <= 0 && z <= 0) || (x >= 0 && y >= 0 && z >= 0))
		return true;
	else
		return false;
}
