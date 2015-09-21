/*
 * 11.05 Weather Statistics Modified
 *
 * Gathers weather data for one year and displays total rainfall,
 * min, max and average temperature for each month.
 */


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum Months
{
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December,
};

string monthNames[]
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",
};

struct Weather
{
	int TotalRainfall;
	int HighTemp;
	int LowTemp;
	int AvgTemp;
};

int promptForTotalRainfall()
{
	cout << "Total rainfall: ";
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

Weather promptUserForWeatherData(string month)
{
	cout << "Enter weather data for " << month << endl;
	Weather data;
	data.TotalRainfall = promptForTotalRainfall();
	data.HighTemp = promptForTemperature("High Temperature: ");
	data.LowTemp = promptForTemperature("Low Temperature: ");
	data.AvgTemp = (data.HighTemp + data.LowTemp) / 2;
	return data;
}

void loadWeatherDataFromUser(Weather *data, const int monthCount)
{
	for (Months month = January; month < monthCount; month = static_cast<Months>(month + 1))
	{
		data[month] = promptUserForWeatherData(monthNames[month]);
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
		cout << setw(colWidth) << monthNames[monthIndex] <<
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

