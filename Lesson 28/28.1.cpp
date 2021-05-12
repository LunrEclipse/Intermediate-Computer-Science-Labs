// sorting template program

#ifndef date_h_
#define date_h_

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"
#include <string>
#include <cstring>
using namespace std;

class date {
public:
	date();
	date(int month, int day, int year);
	date(const date& temp);

	void setDate(int month, int day, int year);
	void getDate();
	void print() const;

private:
	int myMonth, myDay, myYear;
	int daysInMonth(int, int);
};


date::date(): myMonth(1), myDay(1), myYear(1998)
{

}


date::date(int month, int day, int year)
{
	setDate(month, day, year);
}

date::date(const date& temp): myMonth(temp.myMonth), myDay(temp.myDay), myYear(temp.myYear)
{
}


void date::setDate(int month, int day, int year)
{

	if (year < 0)
		year = 1997;
	else if ((0 == year) || (2000 == year))
		year = 2000;
	else if (year <= 19)
		year += 2000;
	else if ((19 < year) && (year <= 99))
		year += 1900;
	else if (year > 2099)
		year = 1997;
	if ((month < 1) || (month > 12))
		month = 1;
	if ((day > daysInMonth(month, year)) || (day < 1))
		day = 1;
	myMonth = month;
	myDay = day;
	myYear = year;
}

void date::getDate()
{
	int  month, day, year;

	cin >> month >> day >> year;
	setDate(month, day, year);
}

void date::print() const
{
	cout << myMonth << "/" << myDay << "/";
	if (2000 == myYear)
		cout << "00";
	else if ((2000 < myYear) && (myYear < 2010)) cout << "0" << myYear - 2000;
	else if ((2010 <= myYear) && (myYear < 2100)) cout << myYear - 2000;
	else cout << myYear - 1900;
}
int date::daysInMonth(int month, int year)
{
	int days;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		days = 31;
	}
	else if (month != 2)
	{
		days = 30;
	}
	else
	{
		if (year % 4 == 0)
			days = 29;
		else
			days = 28;
	}
	return days;
}

#endif
