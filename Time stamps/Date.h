#pragma once
#include <iostream>
#include <vector>

using namespace std;

const int ZERO_YEAR = 1970;
const int LEAP_YEAR_OCCURENCE = 4;
const int ID_OF_LEAP_MONTH = 2;
const int DAYS_OF_YEAR = 365;
const int SECONDS_PER_MINUTE = 60;
const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;
const int MONTHS_COUNT = 12;

class Date
{
public:
	Date();

	bool operator<(Date &dateOther);
	bool operator>(Date &dateOther);
	bool operator<=(Date &dateOther);
	bool operator>=(Date &dateOther);
	bool operator==(Date &dateOther);

	bool setDate(int year, int month, int day);
	int getDaysDifference(Date &dateOther);
	void addDays(int numberOfDays);
	int getSecondsOfDay();
	double getTime();
	int getYear();
	int getMonth();
	int getDay();


protected:
	double timeInSeconds;

	int getDaysOfMonth(int year, int month);
	bool isDateValid(int year, int month, int day);
	int getNumberOfLeapYearsBetween(int year);
	int findClosestLeapYear(int year);


};