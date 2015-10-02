#include "TestScores.h"
#include <iostream>
int TestScores::getAverageScore()
{
	int sum = 0;
	for (int i = 0; i < _scoreCount; i++)
	{
		throwExceptionIfTestScoreIsOutOfRange(_scores[i]);
		sum += _scores[i];
	}
	return static_cast<int>(sum / _scoreCount);
}

void TestScores::throwExceptionIfTestScoreIsOutOfRange(const int score)
{
	if (score < 0 || score > 100)
	{
		throw TestScores::InvalidScoreException();
	}
}
