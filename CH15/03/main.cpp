/*
 * 15.03 TeamLeader
 *
 * Create a TeamLeader that extends ProductionWorker and add logic to
 * allow the leader to earn a monthly bonus based on number of training
 * hours attended.
 */

#include <iostream>
#include "TeamLeader.h"

using namespace std;

void showLeader(const TeamLeader &leader)
{
	printf("Employee Number: %i\n", leader.getEmployeeNumber());
	printf("Name: %s\n", leader.getName().c_str());
	printf("Hire Date: %s\n", leader.getHireDate().c_str());
	printf("Shift: %s\n", leader.getShift() == Day ? "Day" : "Night");
	printf("Hourly Pay Rate: %.2f\n", leader.getHourlyPayRate());
	printf("Training Hours Required: %i\n", leader.getRequiredTrainingHours());
	printf("Training Hours Attended: %i\n", leader.getTrainingHoursAttended());
	printf("Monthly Bonus: %.2f\n", leader.getMonthlyBonus());
	printf("\n");
}

int main()
{
	const int LEADER_CNT = 2;
	TeamLeader leaders[LEADER_CNT]
    {
		{ "Chris", 4928, "01/29/1999", Day, 14.90, 100, 10, 8 },
		{ "Chris", 4928, "01/29/1999", Day, 14.90, 100, 10, 12 }
    };

	for (int i = 0; i < LEADER_CNT; i++)
	{
		showLeader(leaders[i]);
	}
	return 0;
}
