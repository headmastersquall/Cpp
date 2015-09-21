/*
 * 9. Hotel Occupancy
 */

#include <iostream>

using namespace std;

int main()
{
	int floors = 0;
	int percentageOccupied = 0;
	double totalRooms = 0;
	double totalOccupied = 0;
	

	cout << "How many floors does the hotel have? ";
	cin >> floors;

	for (int i = 1; i != floors + 1; i++)
	{
		int rooms = 0,
			occupied = 0;

		if (i == 13)
		{
			continue;
		}
		
		cout << "How many rooms are on floor " << i << "? ";
		cin >> rooms;
		
		cout << "How many rooms are occupied? ";
		cin >> occupied;

		totalRooms += rooms;
		totalOccupied += occupied;
	}

	percentageOccupied = (totalOccupied / totalRooms) * 100;

	cout << "The hotel has:" << endl;
	cout << "Rooms: " << totalRooms << endl;
	cout << "Occupied: " << totalOccupied << endl;
	cout << "Unoccupied: " << totalRooms - totalOccupied << endl;
	cout << "Percentage Occupied: %" << percentageOccupied << endl;

	return 0;
}

	
