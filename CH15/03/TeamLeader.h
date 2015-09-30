#ifndef TEAMLEADER_H_
#define TEAMLEADER_H_

#include "ProductionWorker.h"
#include <string>

using namespace std;

class TeamLeader : public ProductionWorker
{
private:
	double _monthlyBounus;
	int _requiredTrainingHours;
	int _trainingHoursAttended;
public:
	TeamLeader(
			string name,
			int employeeNumber,
			string dateHired,
			Shift shift,
			double hourlyPayRate,
			double monthlyBonus,
			int requiredTrainingHours,
			int trainingHoursAttended)
		: ProductionWorker(
				name,
				employeeNumber,
				dateHired,
				shift,
				hourlyPayRate)
	{
		_monthlyBounus = monthlyBonus;
		_requiredTrainingHours = requiredTrainingHours;
		_trainingHoursAttended = trainingHoursAttended;
	};
	double getMonthlyBonus() const;
	int getRequiredTrainingHours() const { return _requiredTrainingHours; };
	int getTrainingHoursAttended() const { return _trainingHoursAttended; };
};

#endif
