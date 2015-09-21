/*
 * 14.13 Carpet Calculator
 *
 * Calculate the area of carpet needed for a rectangular room, as well as
 * the cost.
 */

#include <iostream>
#include "RoomCarpet.h"
#include "RoomDimensions.h"
#include "FeetInches.h"

using namespace std;

int main()
{
	int ft, in = 0;

	cout << "What is the length of the room (feet inches): ";
	cin >> ft;
	cin >> in;
	FeetInches length(ft, in);

	cout << "What is the width of the room (feet inches): ";
	cin >> ft;
	cin >> in;
	FeetInches width(ft, in);
	RoomDimensions dimensions(width, length);

	cout << "What is the cost per square foot: ";
	double cost;
	cin >> cost;
	RoomCarpet carpet(dimensions, cost);

	printf("The total cost for the carpet is $%.2f", carpet.getTotalCost());
	return 0;
}
