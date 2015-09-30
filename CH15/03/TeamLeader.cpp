#include "TeamLeader.h"

double TeamLeader::getMonthlyBonus() const
{
	return _trainingHoursAttended < _requiredTrainingHours
			? 0.0
			: _monthlyBounus;
}
