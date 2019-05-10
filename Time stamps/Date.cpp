#include "Date.h"

Date::Date()
{
	timeInSeconds = 0;
}

bool Date::operator<(Date &dateOther)
{
	return timeInSeconds < dateOther.timeInSeconds;
}

bool Date::operator>(Date &dateOther)
{
	return timeInSeconds > dateOther.timeInSeconds;
}

bool Date::operator<=(Date &dateOther)
{
	return timeInSeconds <= dateOther.timeInSeconds;
}

bool Date::operator>=(Date &dateOther)
{
	return timeInSeconds >= dateOther.timeInSeconds;
}

bool Date::operator==(Date &dateOther)
{
	return timeInSeconds == dateOther.timeInSeconds;
}

bool Date::setDate(int year, int month, int day)
{
	if (isDateValid(year, month, day))
	{
		double timeInSeconds = (year - ZERO_YEAR) * DAYS_OF_YEAR * getSecondsOfDay();
		int numberOfLeapYearsBetween = getNumberOfLeapYearsBetween(year);

		if (year >= ZERO_YEAR)
		{
			timeInSeconds += numberOfLeapYearsBetween * getSecondsOfDay();
		}
		else
		{
			timeInSeconds -= numberOfLeapYearsBetween * getSecondsOfDay();
		}

		for (int i = 1; i < month; i++)
		{
			timeInSeconds += getDaysOfMonth(year, i) * getSecondsOfDay();
		}

		timeInSeconds += day * getSecondsOfDay();
		this->timeInSeconds = timeInSeconds - getSecondsOfDay(); //1.01.1970 1:00 ma zwr 3600, a nie 90000

		return true;
	}
	else return false;

}

int Date::getDaysDifference(Date &dateOther)
{
	double timeDifference = abs(timeInSeconds - dateOther.timeInSeconds);
	return timeDifference / getSecondsOfDay();
}

void Date::addDays(int numberOfDays)
{
	timeInSeconds += numberOfDays * getSecondsOfDay();
}

int Date::getSecondsOfDay()
{
	return HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE;
}

double Date::getTime()
{
	return timeInSeconds;
}

int Date::getYear()
{

	int year = ZERO_YEAR + (timeInSeconds / (DAYS_OF_YEAR * getSecondsOfDay()));
	int numberOfLeapYearsBetween = getNumberOfLeapYearsBetween(year);
	if (timeInSeconds < (year - ZERO_YEAR) * DAYS_OF_YEAR * getSecondsOfDay() + numberOfLeapYearsBetween * getSecondsOfDay()) year--;

	return year;
}

int Date::getMonth()
{

	Date yearBeginning;
	yearBeginning.setDate(getYear(), 1, 1);
	double timePassed = yearBeginning.getTime();

	int month = 0;
	while (timePassed < timeInSeconds)
	{
		timePassed += getDaysOfMonth(getYear(), ++month) * getSecondsOfDay();
	}
	if (month == 0) ++month;
	return month;
}

int Date::getDay()
{
	Date monthBeginning;
	monthBeginning.setDate(getYear(), getMonth(), 1);
	int day = getDaysDifference(monthBeginning) + 1;
	return day;
}


int Date::getDaysOfMonth(int year, int month)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (year % 4 == 0) return 29;
		else return 28;
		break;
	default:
		return 0;
		break;
	}
}

bool Date::isDateValid(int year, int month, int day)
{
	return month <= MONTHS_COUNT && month > 0 && day > 0 && day <= getDaysOfMonth(year, month);
}

int Date::getNumberOfLeapYearsBetween(int year)
{
	int closestLeapYear = findClosestLeapYear(ZERO_YEAR);
	int numberOfLeapYearsBetween = abs((year - closestLeapYear) / LEAP_YEAR_OCCURENCE) + 1;
	if (year < closestLeapYear || (year % LEAP_YEAR_OCCURENCE == 0)) numberOfLeapYearsBetween--;
	return numberOfLeapYearsBetween;
}

int Date::findClosestLeapYear(int zeroYear)
{
	int leapYear = zeroYear;
	while (leapYear % LEAP_YEAR_OCCURENCE != 0)
	{
		leapYear++;
	}
	return leapYear;
}
