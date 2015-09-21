/*
 * 12.02 - File Display Program
 *
 * Display the contents of a file.  If the contents exceed 24 lines, provides
 * a prompt to continue reading the next group of lines.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int LINES_PER_PAGE = 24;

void showPage(fstream &file)
{
    string line;
    int linesRead = 0;

    while (!file.eof() && linesRead != LINES_PER_PAGE)
    {
        getline(file, line);
        linesRead += 1;
        cout << line << endl;
    }
}

void groupCat(char* fileName)
{
    fstream file(fileName, ios::in);
    if (!file)
    {
        cout << "Error opening file " << fileName << endl;
        return;
    }

    char prompt;
    showPage(file);
    while (!file.eof())
    {
        cout << "Show more (y/n)? ";
        cin >> prompt;
        if (prompt == 'Y' || prompt == 'y')
        {
            showPage(file);
        }
        else
        {
            break;
        }
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
        groupCat(argv[i]);
    }
    return 0;
}

