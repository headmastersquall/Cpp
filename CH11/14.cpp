/*
 * 11.14 Inventory Bins
 *
 * Show an inventory of items and allow the user to add or
 * remove items from the inventory.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

const int MAX_QUANTITY = 30;

struct InventoryItem
{
	string Name;
	int Quantity;
};

int promptForQuantity()
{
	int quantity;
	cout << "Enter quantity: ";
	cin >> quantity;

	if (quantity < 0)
	{
		cout << "Quantity cannot be negative" << endl;
		return promptForQuantity();
	}
	else
	{
		return quantity;
	}
}

void addParts(InventoryItem &item)
{
	int quantity = promptForQuantity();
	if (item.Quantity + quantity > MAX_QUANTITY)
	{
		cout << "Cannot exceed max quantity of " << MAX_QUANTITY << endl;
		addParts(item);
	}
	else
	{
		item.Quantity += quantity;
	}
}

void removeParts(InventoryItem &item)
{
	int quantity = promptForQuantity();
	if (item.Quantity - quantity < 0)
	{
		cout << "Cannot remove more than what is in stock" << endl;;
		removeParts(item);
	}
	else
	{
		item.Quantity -= quantity;
	}
}

void runModifySelection(string selection, InventoryItem &item)
{
	if (selection == "a")
	{
		addParts(item);
	}
	else if (selection == "r")
	{
		removeParts(item);
	}
}

string promptForSelection(string prompt)
{
	string selection;
	cout << prompt;
	cin >> selection;
	return selection;
}

void promptToModifyItem(int itemIndex, vector<InventoryItem> &inventory)
{
	cout << "(a)dd parts" << endl;
	cout << "(r)emove parts" << endl;
	cout << endl;

	string selection = promptForSelection("Choose action: ");
	runModifySelection(selection, inventory[itemIndex]);
}

bool isValidInventorySelection(const string selection, const vector<InventoryItem> &inventory)
{
	for (uint i = 0; i < inventory.capacity(); i++)
	{
		if (to_string(i + 1) == selection)
		{
			return true;
		}
	}
	return false;
}

void showInventoryMenu(const vector<InventoryItem> &inventory)
{
	cout << "Current Inventory:" << endl;
	cout << "    Item              In Stock" << endl;
	for (uint i = 0; i < inventory.capacity(); i++)
	{
		cout << setw(4) << left << (to_string(i + 1) + ")")
			 << setw(18) << left << inventory[i].Name
			 << inventory[i].Quantity << endl;
	}
}

void runInventoryMenu(vector<InventoryItem> &inventory)
{
	showInventoryMenu(inventory);
	string selection = promptForSelection("Enter item number or q to quit: ");
	if (selection == "q" || selection == "Q")
	{
		return;
	}
	if (isValidInventorySelection(selection, inventory))
	{
		promptToModifyItem(atoi(selection.c_str()) - 1, inventory);
	}
	runInventoryMenu(inventory);
}

int main()
{
	vector<InventoryItem> inventory
	{
		InventoryItem { "Valve", 10 },
		InventoryItem { "Bearing", 5 },
		InventoryItem { "Bushing", 15 },
		InventoryItem { "Coupling", 21 },
		InventoryItem { "Flange", 7 },
		InventoryItem { "Gear", 5 },
		InventoryItem { "Gear Housing", 5 },
		InventoryItem { "Vacuum Gripper", 25 },
		InventoryItem { "Cable", 18 },
		InventoryItem { "Rod", 12 },
	};
	runInventoryMenu(inventory);
	return 0;
}

