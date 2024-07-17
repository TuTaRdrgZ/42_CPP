#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed x = (point.getX() - a.getX()) * (b.getY() - a.getY()) - (point.getY() - a.getY()) * (b.getX() - a.getX());
	Fixed y = (point.getX() - b.getX()) * (c.getY() - b.getY()) - (point.getY() - b.getY()) * (c.getX() - b.getX());
	Fixed z = (point.getX() - c.getX()) * (a.getY() - c.getY()) - (point.getY() - c.getY()) * (a.getX() - c.getX());
	if ((x >= 0 && y >= 0 && z >= 0) || (x <= 0 && y <= 0 && z <= 0))
		return true;
	return false;
}
