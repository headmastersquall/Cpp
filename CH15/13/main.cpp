/*
 * 15.13 Pure Abstract Base Class Project
 *
 * Define a pure abstract base class called BasicShape.  Several shapes
 * provided that inherit from this base class.
 */

#include <iostream>
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

int main()
{
	const long int RECT_WIDTH = 4;
	const long int RECT_LEN = 8;
	Rectangle rect(RECT_WIDTH, RECT_LEN);
	printf("A rectangle has been created with a width of %i and a length of %i\n",
			RECT_WIDTH,
			RECT_LEN);
	printf("The calculated area is %.2f\n", rect.getArea());

	const double RADIUS = 12.5;
	Circle circle(45, 60, RADIUS);
	printf("The circle has been created with a radius of %.2f\n", RADIUS);
	printf("The calculated area is %.2f\n", circle.getArea());

	return 0;
}
