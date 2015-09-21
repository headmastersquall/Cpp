/*
 * 02. Test Scores #1
 *
 * Load a dynamically allocated array with test scores, then
 * sort and calculate average score.  The sorted scores will
 * be displayed as well.
 */
 
#include <iostream>

using namespace std;

int promptForScore()
{
	int score;
	cout << "Enter a score: ";
	cin >> score;
	if (score < 0) 
	{
		cout << "Score cannot be less than zero" << endl;
		return promptForScore();
	}
	else
	{
		return score;
	}
}

void sortAscending(int *arr, int size)
{
	int smallest;
	int smallestIndex;
	int start = 0;
	
	do
	{
		smallest = *(arr + start);
		smallestIndex = start;
	
		for (int i = start; i < size; i++)
		{
			if (*(arr + i) < smallest)
			{
				smallest = *(arr + i);
				smallestIndex = i;
			}
		}
		*(arr + smallestIndex) = *(arr + start);
		*(arr + start++) = smallest;
	} while (start < size - 1);
}

int calcAverage(int *scores, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += *(scores + i);
	}
	return sum / size;
}

int main()
{
	int size;
	cout << "How many test scores are there? ";
	cin >> size;
	
	int *scoresPtr = nullptr;
	scoresPtr = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		*(scoresPtr + i) = promptForScore();
	}
	sortAscending(scoresPtr, size);
	
	cout << "Test scores entered: ";
	for (int i = 0; i < size; i++)
	{
		cout << *(scoresPtr + i) << " ";
	}
	cout << endl;
	
	cout << "The average test score is " << calcAverage(scoresPtr, size)
		 << endl;
	
	delete [] scoresPtr;
	scoresPtr = nullptr;
}

