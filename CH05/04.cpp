/*
 * 4. Calories Burned
 */

#include <iostream>

using namespace std;

int main()
{
	const double CAL_BURN_PER_MINUTE = 3.6;

	for (int i = 5.0; i != 35; i += 5)
	{
		cout << "You burned " << CAL_BURN_PER_MINUTE * i << " calories after "
			 << i << " minutes." << endl;
	}
	return 0;
}
