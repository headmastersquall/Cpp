/*
 * 11.04 Weather Statistics
 *
 * Gathers weather data for one year and displays total rainfall,
 * min, max and average temperature for each month.
 */


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Weather
{
	string Month;
	int TotalRainfall;
	int HighTemp;
	int LowTemp;
	int AvgTemp;
};

string promptForMonthName()
{
	cout << "What month is this weather data for? ";
	string month;
	cin >> month;
	return month;
}

int promptForTotalRainfall()
{
	cout << "What is the total rainfall? ";
	int total;
	cin >> total;
	return total;
}

int promptForTemperature(string prompt)
{
	const int MIN_TEMP = -100;
	const int MAX_TEMP = 140;

	cout << prompt;
	int temp;
	cin >> temp;
	if (temp > MAX_TEMP || temp < MIN_TEMP)
	{
		cout << "Temperature must be between " << MIN_TEMP <<
				" and " << MAX_TEMP << endl;
		return promptForTemperature(prompt);
	}
	else
	{
		return temp;
	}
}

Weather promptUserForWeatherData()
{
	Weather data;
	data.Month = promptForMonthName();
	data.TotalRainfall = promptForTotalRainfall();
	data.HighTemp = promptForTemperature("Enter High Temperature: ");
	data.LowTemp = promptForTemperature("Enter Low Temperature: ");
	data.AvgTemp = (data.HighTemp + data.LowTemp) / 2;
	return data;
}

void loadWeatherDataFromUser(Weather *data, const int monthCount)
{
	for (int monthIndex = 0; monthIndex < monthCount; monthIndex++)
	{
		data[monthIndex] = promptUserForWeatherData();
	}
}

void showWeatherData(Weather *data, const int monthCount)
{
	const int colWidth = 11;
	Weather monthData;
	int totalAverage = 0;

	cout << setw(colWidth) << "Month" <<
			setw(colWidth) << "Rainfall" <<
			setw(colWidth) << "High Temp" <<
			setw(colWidth) << "Low Temp" <<
			setw(colWidth) << "Avg Temp" << endl;

	for (int monthIndex = 0; monthIndex < monthCount; monthIndex++)
	{
		monthData = data[monthIndex];
		totalAverage += monthData.AvgTemp;
		cout << setw(colWidth) << monthData.Month <<
				setw(colWidth) << monthData.TotalRainfall <<
				setw(colWidth) << monthData.HighTemp <<
				setw(colWidth) << monthData.LowTemp <<
				setw(colWidth) << monthData.AvgTemp << endl;
	}
	cout << "Average Temperature for the year: " <<
			(totalAverage / monthCount) << endl;
}

int main()
{
	const int MONTHS = 12;
	Weather weatherData[MONTHS];
	loadWeatherDataFromUser(weatherData, MONTHS);
	showWeatherData(weatherData, MONTHS);
	return 0;
}

