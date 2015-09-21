/*
 * 12.03 - Punch Line
 *
 * Reads a joke from a text file and outputs the content to stdout.  The
 * punchline is read from the last line of a second file, which is also
 * outputted to stdout.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void showJoke(const string fileName)
{
	fstream file(fileName.c_str(), ios::in);
	if (!file)
	{
		cout << "Error opening file " << fileName << endl;
		return;
	}

	string line;
	while (getline(file, line))
	{
		cout << line << endl;
	}
	file.close();
}

void showLastLine(const string fileName)
{
	fstream file(fileName.c_str(), ios::in);
	if (!file)
	{
		cout << "Error opening file " << fileName << endl;
		return;
	}

	vector<string> lines;
	string line;
	while (getline(file, line))
	{
		lines.push_back(line);
	}
	cout << lines[lines.size() - 1] << endl;
	file.close();
}

int main()
{
	const string JOKE_FILE = "joke.txt";
	const string PUNCHLINE_FILE = "punchline.txt";

	showJoke(JOKE_FILE);
	cout << endl;
	showLastLine(PUNCHLINE_FILE);
    return 0;
}

