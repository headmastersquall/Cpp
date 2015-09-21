#include "Numbers.h"
#include <string>

using namespace std;

const string numberNames[]
{
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
};

const string teens[]
{
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen",
};

const string tensNumberNames[]
{
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety",
};

const string THOUSAND = "thousand";
const string HUNDRED = "hundred";

Numbers::Numbers(const int number)
{
	_number = (number > 0 && number < 10000) ? number : 0;
}

string Numbers::ToString()
{
	string numStr = "";
	int numLeft = _number;
	int curDigit;

	if (numLeft > 1000)
	{
		curDigit = numLeft * .001;
		numStr.append(numberNames[curDigit - 1]);
		numStr.append(" ");
		numStr.append(THOUSAND);
		numStr.append(" ");
		numLeft = numLeft % 1000;
	}

	if (numLeft > 100)
	{
		curDigit = numLeft * .01;
		numStr.append(numberNames[curDigit - 1]);
		numStr.append(" ");
		numStr.append(HUNDRED);
		numStr.append(" ");
		numLeft = numLeft % 100;
	}

	if (numLeft >= 20)
	{
		curDigit = numLeft * .1;
		numStr.append(tensNumberNames[curDigit - 2]);
		numStr.append(" ");
		numLeft = numLeft % 10;
	}

	if (numLeft > 10)
	{
		curDigit = numLeft % 10;
		numStr.append(teens[curDigit - 1]);
		numStr.append(" ");
		numLeft = 0;
	}

	if (numLeft > 0)
	{
		numStr.append(numberNames[numLeft - 1]);
	}
	return numStr;
}
