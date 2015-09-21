#include <iostream>

using namespace std;

int main()
{
	int maleCount, femaleCount;
	double total;
	int mPercentage, fPercentage;
	
	cout << "How many males? ";
	cin >> maleCount;
	cout << "How many females? ";
	cin >> femaleCount;

	total = maleCount + femaleCount;
	mPercentage = (maleCount / total) * 10;
	fPercentage = (femaleCount / total) * 10;
	
	cout << mPercentage << "% Male" << endl;
	cout << fPercentage << "% Female" << endl;
	return 0;
}
