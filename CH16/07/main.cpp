/*
 * 16.07 TestScores Class
 *
 * Provides a class to calculate the average test score.  Throws exception if any score
 * is out of range.
 */

#include <iostream>
#include "TestScores.h"

using namespace std;

int promptForScore()
{
	int score = 0;
	cout << "Enter a score: ";
	cin >> score;
	return score;
}

int main()
{
	const int SCORE_COUNT = 5;
	int scores[SCORE_COUNT];
	for (int i = 0; i < SCORE_COUNT; i++)
	{
		scores[i] = promptForScore();
	}

	try
	{
		TestScores testScores(scores, SCORE_COUNT);
		int average = testScores.getAverageScore();
		cout << "The average score is " << average << endl;
	}
	catch (const TestScores::InvalidScoreException &)
	{
		cout << "One or more test scores were out of range.  Must be between 0 and 100." << endl;
	}
	return 0;
}
