/*
 * 16.14 Test Scores Vector
 *
 * Load a vector with test scores, then sort and calculate the average score.
 * The sorted scores will then be displayed.
 */
 
#include <iostream>
#include <vector>

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

void sortAscending(vector<int> &scores)
{
	int smallest;
	int smallestIndex;
	uint start = 0;
	
	do
	{
		smallest = scores[start];
		smallestIndex = start;
	
		for (uint i = start; i < scores.size(); i++)
		{
			if (scores[i] < smallest)
			{
				smallest = scores[i];
				smallestIndex = i;
			}
		}
		scores[smallestIndex] = scores[start];
		scores[start++] = smallest;
	} while (start < scores.size() - 1);
}

int calcAverage(const vector<int> &scores)
{
	int sum = 0;
	for (uint i = 0; i < scores.size(); i++)
	{
		sum += scores[i];
	}
	return sum / scores.size();
}

int main()
{
	int size;
	cout << "How many test scores are there? ";
	cin >> size;
	
	vector<int> scores;
	for (int i = 0; i < size; i++)
	{
		scores.push_back(promptForScore());
	}
	sortAscending(scores);
	
	cout << "Test scores entered: ";
	for (int i = 0; i < size; i++)
	{
		cout << scores[i] << " ";
	}
	cout << endl;
	
	cout << "The average test score is " << calcAverage(scores)
		 << endl;
}
