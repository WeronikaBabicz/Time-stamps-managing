#include "TimeStamp.h"

bool TimeStamp::operator<(TimeStamp &timeStampOther)
{
	return timeInSeconds < timeStampOther.timeInSeconds;
}

bool TimeStamp::operator>(TimeStamp &timeStampOther)
{
	return timeInSeconds > timeStampOther.timeInSeconds;
}

bool TimeStamp::operator<=(TimeStamp &timeStampOther)
{
	return timeInSeconds <= timeStampOther.timeInSeconds;
}

bool TimeStamp::operator>=(TimeStamp &timeStampOther)
{
	return timeInSeconds >= timeStampOther.timeInSeconds;
}

bool TimeStamp::operator==(TimeStamp &timeStampOther)
{
	return timeInSeconds == timeStampOther.timeInSeconds;
}

string TimeStamp::getFormat(string format)
{
	string formated = format;

	replaceAll(formated, "yyyy", getDataToFormat("y"));
	replaceAll(formated, "MM", getDataToFormat("M"));
	replaceAll(formated, "dd", getDataToFormat("d"));
	replaceAll(formated, "hh", getDataToFormat("h"));
	replaceAll(formated, "mm", getDataToFormat("m"));
	return formated;


}

bool TimeStamp::setTimeStamp(int year, int month, int day, int hour, int minute)
{
	if (isHourValid(hour, minute) && isDateValid(year, month, day))
	{
		setDate(year, month, day);
		timeInSeconds += SECONDS_PER_MINUTE * (hour * MINUTES_PER_HOUR + minute);
		return true;
	}
	else return false;
}

bool TimeStamp::isHourValid(int hour, int minute)
{
	return hour >= 0 && hour < HOURS_PER_DAY && minute >= 0 && minute < MINUTES_PER_HOUR;
}

int TimeStamp::getMinutesDifference(TimeStamp & timeStampOther)
{
	return abs((timeInSeconds - timeStampOther.timeInSeconds) / SECONDS_PER_MINUTE);
}

void TimeStamp::addHours(int numberOfHours)
{
	timeInSeconds += numberOfHours * MINUTES_PER_HOUR * SECONDS_PER_MINUTE;
}

int TimeStamp::getHour()
{
	TimeStamp timestamp;
	timestamp.setTimeStamp(getYear(), getMonth(), getDay(), 0, 0);

	int hour = getMinutesDifference(timestamp) / MINUTES_PER_HOUR;

	return hour;
}

int TimeStamp::getMinute()
{
	TimeStamp timestamp;
	timestamp.setTimeStamp(getYear(), getMonth(), getDay(), getHour(), 0);
	return getMinutesDifference(timestamp);
}

string TimeStamp::getDataToFormat(string letter)
{
	if (letter == "y") return std::to_string(getYear());
	if (letter == "M") return std::to_string(getMonth());
	if (letter == "d") return std::to_string(getDay());
	if (letter == "h")
	{
		int h = getHour() % 12;
		string hour = std::to_string(h);
		if (h < 10) hour = "0" + hour;
		return hour;
	}


	if (letter == "m")
	{
		int m = getMinute();
		string minute = std::to_string(getMinute());
		if (m < 10) minute = "0" + minute;
		return minute;
	}


}

void TimeStamp::replaceAll(string& word, string from, string to)
{
	int start_pos = 0;
	while ((start_pos = word.find(from, start_pos)) != std::string::npos)
	{
		word.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}

}


