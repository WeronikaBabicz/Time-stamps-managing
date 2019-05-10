#pragma once
#include "Date.h"
#include <iostream>
#include <string>


class TimeStamp : public Date
{
public:

	bool operator<(TimeStamp &timeStampOther);
	bool operator>(TimeStamp &timeStampOther);
	bool operator<=(TimeStamp &timeStampOther);
	bool operator>=(TimeStamp &timeStampOther);
	bool operator==(TimeStamp &timeStampOther);



	string getFormat(string format);
	bool setTimeStamp(int year, int month, int day, int hour, int minute);
	int getMinutesDifference(TimeStamp & timeStampOther);
	void addHours(int numberOfHours);
	int getHour();
	int getMinute();





protected:
	bool isHourValid(int hour, int minute);

private:
	string getDataToFormat(string letter);
	void replaceAll(string& word, string from, string to);
};