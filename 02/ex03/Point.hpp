#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point(const float n1, const float n2);
		Point(const Point &other);
		Point& operator=(const Point &other);
		~Point();
		float getx() const;
		float gety() const;
};

Fixed abs(Fixed n);
Fixed area(Point const a, Point const b, Point const c);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif