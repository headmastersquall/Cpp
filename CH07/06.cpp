/*
 * 08. Lo Shu Magic Square
 *
 * Validates a Lo Shu Magic Square with three rows and three columns,
 * to make sure all rows, columns and diagonals add up to the same number.
 * The square must also only contain the numbers 1-9 with no repeats.
 */

#include <iostream>
#include <vector>

using namespace std;

const int ROW_COUNT = 3;

bool isLoShuSquareValid(int[][ROW_COUNT]);
bool isNumberFrequencyValid(int[][ROW_COUNT]);
bool contains(int[], int, int);
int getGroupSum(vector<int>);
vector<int> getRow(int[][ROW_COUNT], int);
vector<int> getColumn(int[][ROW_COUNT], int);
vector<int> getTopDownDiagonal(int[][ROW_COUNT]);
vector<int> getBottomUpDiagonal(int[][ROW_COUNT]);

int main()
{
	int validLoShuSquare[][ROW_COUNT] = {
		{ 4, 9, 2 },
		{ 3, 5, 7 },
		{ 8, 1, 6 }
	};
	if (isLoShuSquareValid(validLoShuSquare))
	{
		cout << "The square is valid" << endl;
	}
	else
	{
		cout << "The square is not valid" << endl;
	}
	return 0;
}

bool isLoShuSquareValid(int square[][ROW_COUNT])
{
	int firstRowSum = getGroupSum(getRow(square, 0));
	bool sumsValid =
		getGroupSum(getRow(square, 1)) == firstRowSum &&
		getGroupSum(getRow(square, 2)) == firstRowSum &&
		getGroupSum(getColumn(square, 0)) == firstRowSum &&
		getGroupSum(getColumn(square, 1)) == firstRowSum &&
		getGroupSum(getColumn(square, 2)) == firstRowSum &&
		getGroupSum(getTopDownDiagonal(square)) == firstRowSum &&
		getGroupSum(getBottomUpDiagonal(square)) == firstRowSum;
	return sumsValid && isNumberFrequencyValid(square);
}

int getGroupSum(vector<int> group)
{
	int sum = 0;
	for (int i = 0; i < group.size(); i++)
	{
		sum += group[i];
	}
	return sum;
}

vector<int> getRow(int square[][ROW_COUNT], const int rowNum)
{
	vector<int> row;
	row.push_back(square[rowNum][0]);
	row.push_back(square[rowNum][1]);
	row.push_back(square[rowNum][2]);
	return row;
}

vector<int> getColumn(int square[][ROW_COUNT], const int colNum)
{
	vector<int> column;
	column.push_back(square[colNum][0]);
	column.push_back(square[colNum][1]);
	column.push_back(square[colNum][2]);
	return column;
}

vector<int> getTopDownDiagonal(int square[][ROW_COUNT])
{
	vector<int> diagonal;
	diagonal.push_back(square[0][0]);
	diagonal.push_back(square[1][1]);
	diagonal.push_back(square[2][2]);
	return diagonal;
}

vector<int> getBottomUpDiagonal(int square[][ROW_COUNT])
{
	vector<int> diagonal;
	diagonal.push_back(square[2][0]);
	diagonal.push_back(square[1][1]);
	diagonal.push_back(square[0][2]);
	return diagonal;
}

bool isNumberFrequencyValid(int square[][ROW_COUNT])
{
	const int FLAT_SQUARE_SIZE = 9;
	int flatSquare[] = {
		square[0][0],
		square[0][1],
		square[0][2],
		square[1][0],
		square[1][1],
		square[1][2],
		square[2][0],
		square[2][1],
		square[2][2]
	};
	for (int i = 0; i < FLAT_SQUARE_SIZE; i++)
	{
		if (contains(flatSquare, FLAT_SQUARE_SIZE, i))
		{
			return true;
		}
	}
	return false;
}

bool contains(int array[], int length, int num)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] == num)
		{
			return true;
		}
	}
	return false;
}

