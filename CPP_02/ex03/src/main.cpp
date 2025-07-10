#include <iostream>
#include "../includes/Point.hpp"

int main() {
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	Point inside(1, 1);     // inside the triangle
	Point edge(2.5, 0);     // at edge of triangle
	Point outside(5, 5);    // outside the triangle

	if (bsp(a, b, c, inside))
		std::cout << "Point (1, 1) is inside";
	else
		std::cout << "Point (1, 1) is outside";
	std::cout << " the triangle ABC." << std::endl;

	if (bsp(a, b, c, edge))
		std::cout << "Point (2.5, 0) is inside";
	else
		std::cout << "Point (2.5, 0) is outside";
	std::cout << " the triangle ABC." << std::endl;

	if (bsp(a, b, c, outside))
		std::cout << "Point (5, 5) is inside";
	else
		std::cout << "Point (5, 5) is outside";
	std::cout << " the triangle ABC." << std::endl;

	return 0;
}
