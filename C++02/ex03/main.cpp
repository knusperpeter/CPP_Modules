#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	Point a(1.0f, 1.0f);
	Point b(1.0f, 3.0f);
	Point c(3.0f, 1.0f);
	Point point(1.1f, 1.1f);

	if (bsp(a, b, c, point))
		return (std::cout << "P IS INSIDE!!1!" << std::endl, 0);
	return (std::cout << "P IS OUTSIDE!1!!" << std::endl, 0);
}
