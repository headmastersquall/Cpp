/*
 * 14. Student Line Up
 *
 * Prompt the user for a number of students, then asks for that many students
 * names.  Finally, the first and last alphabetical students name will be
 * displayed.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int MIN_STUDENTS = 1;
	const int MAX_STUDENTS = 25;

	string student = "";
	string first = "";
	string last = "";
	int studentCount = 0;

	cout << "How many students in the class? ";
	cin >> studentCount;

	if (studentCount < MIN_STUDENTS || studentCount > MAX_STUDENTS)
	{
		cout << "Student count must be within 1 - 25" << endl;
		return 1;
	}

	for (int i = 0; i != studentCount; i++)
	{
		cout << "Enter a students name: ";
		cin >> student;

		if (first == "" && last == "")
		{
			first = student;
			last = student;
		}
		else
		{
			first = student <= first ? student : first;
			last = student >= last ? student : last;
		}
	}

	cout << "The first student in line is " << first << endl;
	cout << "The last student in line is " << last << endl;
	return 0;
}

