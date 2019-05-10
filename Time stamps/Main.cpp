#include "TimeStamp.h"
#include <iostream>

using namespace std;

int main()
{
	Date d1;
	Date d2;
	Date d3;
	Date d4;

	TimeStamp ts1;
	TimeStamp ts2;
	TimeStamp ts3;
	TimeStamp ts4;

	/*cout << (d1 == d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 <= d2) << endl;*/

	cout << " =========================================== DATES =========================================== " << endl;

	d1.setDate(2003, 12, 31);
	d2.setDate(1970, 1, 1);
	d3.setDate(1980, 12, 31);
	d4.setDate(1980, 12, 28);

	cout << "2003.12.31 (00:00) TIME: " << d1.getTime() << "   -> Year: " << d1.getYear() << "  Month: " << d1.getMonth() << "  Day: " << d1.getDay() << endl;
	cout << "1970.01.01 (00:00) TIME: " << d2.getTime() << "\t       -> Year: " << d2.getYear() << "  Month: " << d2.getMonth() << "   Day: " << d2.getDay() << endl;
	cout << "1980.12.31 (00:00) TIME: " << d3.getTime() << "   -> Year: " << d3.getYear() << "  Month: " << d3.getMonth() << "  Day: " << d3.getDay() << endl << endl;
	cout << "1980.12.31 (00:00) and 1980.12.28 (00:00) DAY DIFFERENCE:  " << d3.getDaysDifference(d4) << endl;
	cout << "2003.12.31 (00:00) < 1970.01.01 (00:00)?: " << (d1 < d2) << endl << endl;



	cout << "========================================= TIMESTAMPS =========================================" << endl;

	ts1.setTimeStamp(2000, 2, 1, 13, 40);
	ts2.setTimeStamp(1980, 11, 30, 1, 59);
	ts3.setTimeStamp(1960, 12, 1, 2, 20);
	ts4.setTimeStamp(1960, 12, 4, 2, 21);

	cout << "2000.02.01 (13:40) TIME: " << ts1.getTime() << "   -> Year:  " << ts1.getYear() << "  Month: " << ts1.getMonth() << "   Day: " << ts1.getDay() << "   Hour: " << ts1.getHour() << "  Minute: " << ts1.getMinute() << endl;
	cout << "1980.11.30 (01:59) TIME: " << ts2.getTime() << "   -> Year:  " << ts2.getYear() << "  Month: " << ts2.getMonth() << "  Day: " << ts2.getDay() << "  Hour: " << ts2.getHour() << "   Minute: " << ts2.getMinute() << endl;
	cout << "1960.12.01 (02:20) TIME: " << ts3.getTime() << "  -> Year:  " << ts3.getYear() << "  Month: " << ts3.getMonth() << "  Day: " << ts3.getDay() << "   Hour: " << ts3.getHour() << "   Minute: " << ts3.getMinute() << endl << endl;
	cout << "1960.12.01 (02:20) and 1960.12.04 (02:21) DAY DIFFERENCE:  " << ts3.getDaysDifference(ts4) << endl;
	cout << "2000.02.01 (13:40) >= 1980.11.30 (01:59)?: " << (ts1 >= ts2) << endl << endl;

	ts4.addDays(3);
	cout << "Add 3 days to 1960.12.04 (02:21): " << ts4.getTime() << "  -> Year:  " << ts4.getYear() << "  Month: " << ts4.getMonth() << "  Day: " << ts4.getDay() << "   Hour: " << ts4.getHour() << "   Minute: " << ts4.getMinute() << endl;
	ts4.addHours(22);
	cout << "Add 22 hours to 1960.12.07 (02:21): " << ts4.getTime() << "  -> Year:  " << ts4.getYear() << "  Month: " << ts4.getMonth() << "  Day: " << ts4.getDay() << "   Hour: " << ts4.getHour() << "   Minute: " << ts4.getMinute() << endl << endl;

	TimeStamp ts5;
	ts5.setTimeStamp(1999, 12, 31, 23, 02);
	cout << "Get time 1999.12.31 (23:02): " << ts5.getTime() << endl;
	ts5.addHours(2);
	cout << "Get time 1999.12.31 (23:02) + 2hrs:" << ts5.getTime() << endl;
	//cout << ts5.getYear() << ts5.getMonth() << endl;

	cout << "Add 2 hours to 1999.12.31 (23:02): " << ts5.getTime() << "  -> Year:  " << ts5.getYear() << "  Month: " << ts5.getMonth() << "  Day: " << ts5.getDay() << "   Hour: " << ts5.getHour() << "   Minute: " << ts5.getMinute() << endl << endl;


	ts5.setTimeStamp(1999, 12, 31, 16, 02);
	cout << "1999.12.31 (16:02) in format yyyyy:MMM:ddddd:hhhhh:mm " << endl;
	cout << ts5.getFormat("yyyyy:MMM:ddddd:hhhhh:mm");



	int a;
	cin >> a;
	return 0;
}