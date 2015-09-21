/*
 * 11.01 Movie Data
 *
 * Stores and displays information about a movie.
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct MovieData
{
	string Title;
	string Director;
	int YearReleased;
	int RunningTime;
};

void showMovie(const MovieData &movie)
{
	const int labelWidth = 16;
	cout << setw(labelWidth) <<
			"Title: " << movie.Title << endl;
	cout << setw(labelWidth) <<
			"Director: " << movie.Director << endl;
	cout << setw(labelWidth) <<
			"Released: " << movie.YearReleased << endl;
	cout << setw(labelWidth) <<
			"Running Time: " << movie.RunningTime << endl;
	cout << endl;
}

int main()
{
	MovieData movie1 = { "Foo Man", "Steve Jobs", 2014, 90 };
	MovieData movie2 = { "Bar Stool", "Andrew Jinkins", 1999, 75 };
	showMovie(movie1);
	showMovie(movie2);
	return 0;
}

