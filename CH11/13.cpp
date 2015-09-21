/*
 * 11.13 Drink Machine Simulator
 *
 * Asks the user for what drink they wish to purchase and has them
 * insert the proper amount of money.  If they enter more money than
 * needed, proper change is returned.  At the close of the application
 * the total money collected is displayed.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

struct Drink
{
	string Name;
	float Cost;
	int Available;
};

void showMenu(const Drink *drinks, const int drinkCount)
{
	const int NAME_WIDTH = 12;

	cout << "Select a beverage to enjoy" << endl;
	cout << endl;
	for (int i = 0; i < drinkCount; i++)
	{
		cout << setprecision(2) << fixed << showpoint;
		cout << (i + 1) << ") " << left << setw(NAME_WIDTH) <<
				drinks[i].Name << "$" << drinks[i].Cost << endl;
	}
	cout << "q) Quit" << endl;
	cout << endl;
}

char getMenuInput()
{
	cout << "Select an item: ";
	return cin.get();
}

float chargeCustomerAndGetChange(Drink *drink)
{
	const float MIN_MONEY = 0;
	const float MAX_MONEY = 1.00;

	float moneyIn;
	cout << "Enter money: ";
	cin >> moneyIn;

	if (moneyIn < MIN_MONEY || moneyIn > MAX_MONEY)
	{
		cout << "You can only insert between " <<
				MIN_MONEY << " and " << MAX_MONEY << endl;
		return chargeCustomerAndGetChange(drink);
	}

	if (moneyIn < drink->Cost)
	{
		cout << "You need at least $" << drink->Cost <<
				" to purchase this item" << endl;
		return chargeCustomerAndGetChange(drink);
	}
	return moneyIn - drink->Cost;
}

float purchaseItem(const char input, Drink *drinks, const int drinkCount)
{
	if (!isdigit(input))
	{
		return 0.0;
	}

	int index = (input - '0') - 1;
	if (index < 0 || index > drinkCount)
	{
		cout << "Invalid item selected" << endl;
		return 0.0;
	}

	if (drinks[index].Available == 0)
	{
		cout << "Sorry, that item is sold out" << endl;
		return 0.0;
	}

	Drink *drink = nullptr;
	drink = &drinks[index];
	cout << drink->Name << " costs $" << drink->Cost << endl;
	float change = chargeCustomerAndGetChange(drink);
	cout << "Your change is: $" << change << endl;
	drink->Available -= 1;

	cout << "Press enter to continue" << endl;
	cin.ignore();
	cin.get();
	return drink->Cost;
}

void runSodaMachine(Drink *drinks, const int drinkCount)
{
	float totalCollected = 0;
	char input = ' ';

	while (tolower(input) != 'q')
	{
		showMenu(drinks, drinkCount);
		input = getMenuInput();
		totalCollected += purchaseItem(input, drinks, drinkCount);
	}
	cout << "Total earned: $" << setprecision(2) << totalCollected << endl;
}

int main()
{
	const int DRINK_COUNT = 5;
	Drink drinks[]
	{
		Drink { "Cola", 0.75, 20 },
		Drink { "Root Beer", 0.75, 20 },
		Drink { "Lemon-Lime", 0.75, 20 },
		Drink { "Grape Soda", 0.80, 20 },
		Drink { "Cream Soda", 0.80, 20 },
	};
	runSodaMachine(drinks, DRINK_COUNT);
	return 0;
}

