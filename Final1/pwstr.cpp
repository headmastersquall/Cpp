/*
 * Final Project 1
 *
 * Password strength tester.
 *
 * Takes a password from command line options and applies a scoring algorithm
 * to calculate a strength for the password.  A verbose command line flag can
 * be provided to output a report of calculation results as well as minimum
 * password requirements.
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int MIN_PW_LEN_REQIREMENT = 8;
const int MIN_CATEGORY_CHAR_COUNT = 2;
const int MIN_CATEGORY_REQUIREMENT = 3;

struct CmdArgs
{
	bool helpRequested = false;
	bool verboseMode = false;
	string password = "";
};

struct CharTotals
{
	int lowerCaseCount = 0;
	int upperCaseCount = 0;
	int numberCount = 0;
	int nonAlphaNumericCount = 0;
};

struct PenaltyTotals
{
	int caseInsensitiveRepeatCharacters = 0;
	int consecutiveUpperCount = 0;
	int consecutiveLowerCount = 0;
	int consecutiveNumberCount = 0;
	int consecutiveSpecialCount = 0;
	int sequentialCharacterCount = 0;
	int sequentialNumberCount = 0;
	int sequentialSpecialCount = 0;
};

void calcCharTotals(const string pw, CharTotals &totals)
{
	for (uint i = 0; i < pw.length(); i++)
	{
		if (isupper(pw[i]))
		{
			totals.upperCaseCount += 1;
		}
		else if (islower(pw[i]))
		{
			totals.lowerCaseCount += 1;
		}
		else if (isdigit(pw[i]))
		{
			totals.numberCount += 1;
		}
		else
		{
			totals.nonAlphaNumericCount += 1;
		}
	}
}

void calcPenalties(const string pw, PenaltyTotals &totals)
{
	const int MIN_SEQUENCIAL = 2;

	int sequentialNumCt = 0;
	int sequentialCharCt = 0;
	int sequentialSpecialCt = 0;

	char previous = pw[0];
	for (uint i = 1; i < pw.length(); i++)
	{
		if (tolower(previous) == tolower(pw[i]))
		{
			totals.caseInsensitiveRepeatCharacters += 1;
		}
		if (isupper(previous) && isupper(pw[i]))
		{
			totals.consecutiveUpperCount += 1;
		}
		if (islower(previous) && islower(pw[i]))
		{
			totals.consecutiveLowerCount += 1;
		}
		if (isdigit(previous) && isdigit(pw[i]))
		{
			totals.consecutiveNumberCount += 1;
		}
		if (ispunct(previous) && ispunct(pw[i]))
		{
			totals.consecutiveSpecialCount += 1;
		}

		if (isdigit(pw[i]) && pw[i] == previous + 1)
		{
			sequentialNumCt += 1;
			if (sequentialNumCt == MIN_SEQUENCIAL)
			{
				totals.sequentialNumberCount += 1;
			}
		}
		else
		{
			sequentialNumCt = 0;
		}

		if (isalpha(pw[i]) && pw[i] == previous + 1)
		{
			sequentialCharCt += 1;
			if (sequentialCharCt == MIN_SEQUENCIAL)
			{
				totals.sequentialCharacterCount += 1;
			}
		}
		else
		{
			sequentialCharCt = 0;
		}

		if (ispunct(pw[i]) && pw[i] == previous + 1)
		{
			sequentialSpecialCt += 1;
			if (sequentialSpecialCt == MIN_SEQUENCIAL)
			{
				totals.sequentialSpecialCount += 1;
			}
		}
		else
		{
			sequentialSpecialCt = 0;
		}
		previous = pw[i];
	}
}

bool meetsMinRequirements(const CharTotals &totals, const int pwLen)
{
	int met = 0;
	met += totals.lowerCaseCount >= MIN_CATEGORY_CHAR_COUNT ? 1 : 0;
	met += totals.upperCaseCount >= MIN_CATEGORY_CHAR_COUNT ? 1 : 0;
	met += totals.numberCount >= MIN_CATEGORY_CHAR_COUNT ? 1 : 0;
	met += totals.nonAlphaNumericCount >= MIN_CATEGORY_CHAR_COUNT ? 1 : 0;
	return met >= MIN_CATEGORY_REQUIREMENT && pwLen >= MIN_PW_LEN_REQIREMENT;
}

bool hasNumbersOnly(const string pw)
{
	for (uint i = 0; i < pw.length(); i++)
	{
		if (!isdigit(pw[i]))
		{
			return false;
		}
	}
	return true;
}

bool hasCharactersOnly(const string pw)
{
	for (uint i = 0; i < pw.length(); i++)
	{
		if (!isalpha(pw[i]))
		{
			return false;
		}
	}
	return true;
}

int calcPasswordScore(const CharTotals totals, const PenaltyTotals penalties, const string pw)
{
	int bonus = 0;
	int deductions = 0;

	bonus += pw.length() * 4;
	bonus += totals.lowerCaseCount * 2;
	bonus += totals.upperCaseCount * 2;
	bonus += totals.numberCount * 4;
	bonus += totals.nonAlphaNumericCount * 6;
	bonus += meetsMinRequirements(totals, pw.length()) ? 10 : 0;

	deductions += hasNumbersOnly(pw) ? pw.length() : 0;
	deductions += hasCharactersOnly(pw) ? pw.length() : 0;
	deductions += penalties.caseInsensitiveRepeatCharacters;
	deductions += penalties.consecutiveLowerCount * 2;
	deductions += penalties.consecutiveUpperCount * 2;
	deductions += penalties.consecutiveNumberCount * 2;
	deductions += penalties.consecutiveSpecialCount * 2;
	deductions += penalties.sequentialCharacterCount * 3;
	deductions += penalties.sequentialNumberCount * 3;
	deductions += penalties.sequentialSpecialCount * 3;
	return bonus - deductions;
}

void showPasswordReport(const CharTotals totals, const PenaltyTotals penalties, const string pw)
{
	if (pw.length() < MIN_PW_LEN_REQIREMENT)
	{
		cout << "Password is too short." << endl;
	}
	if (hasNumbersOnly(pw))
	{
		cout << "Password contains only numbers." << endl;
	}
	if (hasCharactersOnly(pw))
	{
		cout << "Password contains only alpha characters." << endl;
	}
	if (penalties.caseInsensitiveRepeatCharacters > 0)
	{
		cout << "Repeat characters found (case insensitive)." << endl;
	}
	if (penalties.consecutiveLowerCount > 0)
	{
		cout << "Consecutive lower case characters found." << endl;
	}
	if (penalties.consecutiveNumberCount > 0)
	{
		cout << "Consecutive numeric characters found." << endl;
	}
	if (penalties.consecutiveSpecialCount > 0)
	{
		cout << "Consecutive special characters found." << endl;
	}
	if (penalties.consecutiveUpperCount > 0)
	{
		cout << "Consecutive upper case characters found." << endl;
	}
	if (penalties.sequentialCharacterCount > 0)
	{
		cout << "Sequential characters found." << endl;
	}
	if (penalties.sequentialNumberCount > 0)
	{
		cout << "Sequential numbers found." << endl;
	}
	if (penalties.sequentialSpecialCount > 0)
	{
		cout << "Sequential special characters found." << endl;
	}
	if (!meetsMinRequirements(totals, pw.length()))
	{
		cout << "Minimum password requirements not met.  Use -h for details." << endl;
	}
}

string scoreToRank(int score)
{
	if (score < 20)
	{
		return "Very Weak";
	}
	else if (score >= 20 && score < 40)
	{
		return "Weak";
	}
	else if (score >= 40 && score < 60)
	{
		return "Good";
	}
	else if (score >= 60 && score < 80)
	{
		return "Strong";
	}
	else
	{
		return "Very Strong";
	}
}

void showUsage(const string name)
{
	cout << "Password strength tester" << endl
		 << endl
		 << "Usage: " << name << " <options>" << endl
		 << "Options:" << endl
		 << "\t-h, --help\tShow this help message." << endl
		 << "\t-p, --password\tPassword to be tested." << endl
		 << "\t-v, --verbose\tShow details of strength test." << endl
		 << endl
		 << "Minimum password requirements:" << endl
		 << "\t- Length of " << MIN_PW_LEN_REQIREMENT << " characters" << endl
		 << "\t- " << MIN_CATEGORY_CHAR_COUNT << " or more characters from at "
		 << "least " << MIN_CATEGORY_REQUIREMENT << " of the following: " << endl
		 << "\t\t- upper case letters" << endl
		 << "\t\t- lower case letters" << endl
		 << "\t\t- numbers" << endl
		 << "\t\t- special characters" << endl
		 << endl;
}

void parseArgs(const int argc, char* const argv[], CmdArgs &params)
{
	for (int i = 1; i < argc; i++)
	{
		if (string(argv[i]) == "-h" || string(argv[i]) == "--help")
		{
			params.helpRequested = true;
		}
		else if (string(argv[i]) == "-v" || string(argv[i]) == "--verbose")
		{
			params.verboseMode = true;
		}
		else if ((string(argv[i]) == "-p" || string(argv[i]) == "--password") &&
				i + 1 < argc)
		{
			params.password = argv[++i];
		}
	}
}

void runPasswordTests(const CmdArgs &params)
{
	CharTotals totals;
	PenaltyTotals penalties;

	calcCharTotals(params.password, totals);
	calcPenalties(params.password, penalties);

	int score = calcPasswordScore(totals, penalties, params.password);
	cout << "Strength: " << scoreToRank(score) << endl;

	if (params.verboseMode)
	{
		showPasswordReport(totals, penalties, params.password);
	}
}

int main(int argc, char* argv[])
{
	CmdArgs params;
	parseArgs(argc, argv, params);

	if (params.helpRequested)
	{
		showUsage(argv[0]);
		return 0;
	}

	if (params.password.length() == 0)
	{
		showUsage(argv[0]);
		return 1;
	}

	runPasswordTests(params);
	return 0;
}
