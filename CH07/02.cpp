/*
 * 02. Rainfall Statistics
 *
 * Prompts the user for rainfall values for 12 months then shows various
 * statistics on the data.
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int rainfallPrompt(int);
void showRainfallStatistics(int[], int);

int main()
{
	const int MONTHS = 12;
	int rainfall[MONTHS];

	for (int i = 0; i < MONTHS; i++)
	{
		rainfall[i] = rainfallPrompt(i);
	}
	showRainfallStatistics(rainfall, MONTHS);
	return 0;
}

int rainfallPrompt(const int num)
{
	int value;
	cout << "What is the rainfall for month " << (num + 1) << "? ";
	cin >> value;
	if (value < 0)
	{
		cout << "Rainfall cannot be negative." << endl;
		return rainfallPrompt(num);
	}
	return value;
}

void showRainfallStatistics(int rainfall[], const int months)
{
	int minRain = rainfall[0];
	int maxRain = rainfall[0];
	int totalRain = 0;
	double avgRain = 0.0;
	
	for (int i = 0; i < months; i++)
	{
		minRain = minRain < rainfall[i] ? minRain : rainfall[i];
		maxRain = maxRain > rainfall[i] ? maxRain : rainfall[i];
		totalRain += rainfall[i];
	}
	avgRain = totalRain / months;
	
	cout << fixed << setprecision(2);
	cout << "Rainfall Statistics:" << endl;
	cout << "Min: " << minRain << endl;
	cout << "Max: " << maxRain << endl;
	cout << "Avg: " << avgRain << endl;
	cout << "Total: " << totalRain << endl;
}
