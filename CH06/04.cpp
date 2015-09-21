/*
 * 04. Safest Driving Area
 *
 * Shows which major city has the fewest reported automobile accidents.
 */

#include <iostream>
#include <string>

using namespace std;

int getNumAccidents(string region);
void findLowest(int, int, int, int, int);

int main()
{
	findLowest(
		getNumAccidents("north"),
		getNumAccidents("south"),
		getNumAccidents("east"),
		getNumAccidents("west"),
		getNumAccidents("centeral"));
	return 0;
}

int getNumAccidents(string region)
{
	int accidentCount = 0;
	cout << "How many accidents are in the " << region << " region? ";
	cin >> accidentCount;

	if (accidentCount < 0)
	{
		cout << "Cannot have less than zero accidents." << endl;
		return getNumAccidents(region);
	}
	else
	{
		return accidentCount;
	}
}

void findLowest(int north, int south, int east, int west, int centeral)
{
	int smallest = north;
	string smallestName = "north";

	if (south < smallest)
	{
		smallest = south;
		smallestName = "south";
	}
	if (east < smallest)
	{
		smallest = east;
		smallestName = "east";
	}
	if (west < smallest)
	{
		smallest = west;
		smallestName = "west";
	}
	if (centeral < smallest)
	{
		smallest = centeral;
		smallestName = "centeral";
	}
	cout << "The " << smallestName << " region has the fiewest amount of "
		 << "accidents, with a total of " << smallest << "." << endl;
}
