/*
 * 12.01 - File Head Program
 *
 * A simple impliementation of the head program that reads the first ten
 * characters of a file, or files, and outputs them to stdout.  File input
 * is provided via command line options.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int HEAD_LINE_COUNT = 10;

void showHead(char* fname)
{
    fstream file(fname, ios::in);
    if (!file)
    {
        cout << "Error opening " << fname << endl;
        return;
    }

    string line;
    int lineIndex = 0;

    getline(file, line);
    while (!file.eof() && lineIndex < HEAD_LINE_COUNT)
    {
        cout << line << endl;
        lineIndex += 1;
        getline(file, line);
    }
    file.close();
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        cout << "No input files provided." << endl;
    }

    for (int i = 1; i < argc; i++)
    {
        showHead(argv[i]);
    }
    return 0;
}

