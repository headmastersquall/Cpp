#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	const double ADULT_TICKET_PRICE = 10.00;
	const double CHILD_TICKET_PRICE = 6.00;
	const double GROSS_PERCENTAGE = 0.2;

	string movieName;
	int adultCount, childCount;
	double grossBoxOfficeProfit, netBoxOfficeProfit;

	cout << "What is the name of the movie? ";
	getline(cin, movieName);
	cout << "How many adult tickest sold? ";
	cin >> adultCount;
	cout << "How many child tickets sold? ";
	cin >> childCount;

	grossBoxOfficeProfit =
		(adultCount * ADULT_TICKET_PRICE) +
		(childCount * CHILD_TICKET_PRICE);
	netBoxOfficeProfit = grossBoxOfficeProfit * GROSS_PERCENTAGE;
	

	cout << setw(30) << left << "Movie Name: " << movieName << endl;
	cout << setprecision(2) << fixed;
	cout << setw(30) << left << "Adult Tickets Sold:"
		<< adultCount << endl;
	cout << setw(30) << left << "Child Tickets Sold:"
		<< childCount << endl;
	cout << setw(30) << left << "Gross Box Office Profit:"
		<< "$" << grossBoxOfficeProfit << endl;
	cout << setw(30) << left << "Net Box Office Profit:"
		<< "$" << netBoxOfficeProfit << endl;
	cout << setw(30) << left << "Amount Paid to Distributor:" 
		<< "$" << grossBoxOfficeProfit - netBoxOfficeProfit << endl;
	return 0;
}

