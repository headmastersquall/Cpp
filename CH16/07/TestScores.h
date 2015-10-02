#ifndef TESTSCORES_H_
#define TESTSCORES_H_

class TestScores
{
private:
	int* _scores;
	int _scoreCount;
	void throwExceptionIfTestScoreIsOutOfRange(int);
public:
	TestScores(int scores[], const int scoreCount)
	{
		_scores = scores;
		_scoreCount = scoreCount;
	};
	int getAverageScore();

	class InvalidScoreException {};
};

#endif
