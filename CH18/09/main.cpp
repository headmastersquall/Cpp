/*
 * 17.09 File Reverser
 *
 * Opens a file and loads each character into a stack.  The stack is then read
 * and written to a second file.
 */

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

void loadStack(ifstream &file, stack<char> &charStack)
{
	char c;
	file.get(c);
	charStack.push(c);
	while (!file.eof())
	{
		file.get(c);
		charStack.push(c);
	}
}

void outputReversedFileContent(stack<char> &charStack)
{
	while (!charStack.empty())
	{
		cout << charStack.top();
		charStack.pop();
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Must supply a file to reverse." << endl;
		return 1;
	}

	ifstream file;
	file.open(argv[1], ios::in);
	if (!file.is_open())
	{
		cout << "Error opening file." << endl;
		return 2;
	}

	stack<char> charStack;
	loadStack(file, charStack);
	outputReversedFileContent(charStack);
	return 0;
}
