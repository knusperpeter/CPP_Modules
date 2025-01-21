#include "Point.hpp"

Fixed calculate_area(Point const a, Point const b, Point const c){
	Fixed og_area = (a.getX() * (b.getY() - c.getY()) 
								+ b.getX() * (c.getY() - a.getY()) 
								+ c.getX() * (a.getY() - b.getY()));
	if (og_area < 0)
		og_area = og_area * Fixed(-1.0f);
	return (og_area / Fixed(2)) ;
};

bool not_inside(Fixed a){
	if (a > 0.0f && a < 1.0f)
		return false;
	return true;
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed abc = calculate_area(a, b, c);
	Fixed pbc = calculate_area(point, b, c);
	Fixed apc = calculate_area(a, point, c);
	Fixed abp = calculate_area(a, b, point);

	if (not_inside(pbc / abc) || not_inside(apc / abc) || not_inside(abp / abc))
		return false;
	Fixed area_new = pbc + apc + abp;
	if (abc != area_new)
		return false;
	return true;
}