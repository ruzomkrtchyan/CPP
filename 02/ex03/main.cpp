#include "Point.hpp"

int main ()
{
	// Point A (0, 0);
	// Point B (10, 30);
	// Point C (20, 0);
	// Point P (10, 15);

	// // // if (bsp(A, B, C, P))
	// // // 	std::cout << "Inside" << std::endl;
	// // // std::cout << "Outside" << std::endl;
	// std::cout << (bsp(A, B, C, P)) << std::endl;

	// Point p1(1, 1);
	// Point p2(4, 1);
	// Point p3(2, 5);
	// Point point(0, 0);
	// // false

	// Point p1(1, 1);
	// Point p2(4, 1);
	// Point p3(2, 5);
	// Point point(3, 2);
	// // true

	// Point p1(1, 1);
	// Point p2(4, 1);
	// Point p3(2, 5);
	// Point point(3, 3);
	// // true

	Point p1(1, 1);
	Point p2(4, 1);
	Point p3(2, 5);
	Point point(5, 3);
	// false
	std::cout << bsp(p1, p2, p3, point) << std::endl;
	return 0;
}