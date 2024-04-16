#include "Point.hpp"

Fixed abs(Fixed n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

Fixed area(Point const a, Point const b, Point const c)
{
	return ((a.getx() * (b.gety() - c.gety()) + b.getx() * (c.gety() - a.gety()) + c.getx() * (a.gety() - b.gety())) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed ABC = abs(area (a, b, c));
	Fixed PBC = abs(area (point, b, c));
	Fixed PAC = abs(area (a, point, c));
	Fixed PAB = abs(area (a, b, point));

	return(ABC == PAB + PAC + PBC);

}