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
	void getDate(istream&);
	void print(ostream&) const;
	void print() const;

	date operator++();
	date operator++(int);

	date operator--();
	date operator--(int);

	bool operator== (const date&) const;
	bool operator!= (const date&) const;
	bool operator< (const date&) const;
	bool operator> (const date&) const;
	bool operator<= (const date&) const;
	bool operator>= (const date&) const;


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

istream& operator>> (istream&, date&);
ostream& operator<< (ostream&, const date&);


void date::getDate(istream& infile)
{
	int  month, day, year;

	infile >> month >> day >> year;
	setDate(month, day, year);
}

void date::print(ostream& outfile) const
{
	outfile << myMonth << "/" << myDay << "/";
	if (2000 == myYear)
		outfile << "00";
	else if ((2000 < myYear) && (myYear < 2010)) outfile << "0" << myYear - 2000;
	else if ((2010 <= myYear) && (myYear < 2100)) outfile << myYear - 2000;
	else outfile << myYear - 1900;
}

istream& operator>> (istream& infile, date& temp)
{
	temp.getDate(infile);
	return infile;
}

ostream& operator<< (ostream& outfile, const date& temp)
{
	temp.print(outfile);
	return outfile;
}


//Lesson 30 Stuff
date date::operator++ (void)
{
	if (myDay == daysInMonth(myMonth, myYear))
	{
		myDay = 1;
		if (12 == myMonth)
		{
			myMonth = 1;
			myYear++;
		}
		else
			myMonth++;
	}
	else
		myDay++;
	return *this;
}

date date::operator++ (int)
{
	date temp = *this;
	++(*this);
	return temp;
}

date date::operator-- ()
{
	if ((1 == myDay) && (1 == myMonth))
	{
		myMonth = 12;
		myDay = 31;
		myYear--;
	}
	else if (1 == myDay)
	{
		myMonth--;
		myDay = daysInMonth(myMonth, myYear);
	}
	else
		myDay--;
	return *this;
}

date date::operator-- (int)
{
	date temp = *this;

	--(*this);
	return temp;
}

bool date::operator== (const date& temp) const
{
	bool same = false;
	if ((myMonth == temp.myMonth) && (myDay == temp.myDay) && (myYear == temp.myYear))
	{
		same = true;
	}
	else
	{
		same = false;
	}
	return same; 
}

bool date::operator!= (const date& temp) const
{
	return !(*this == temp);
}

bool date::operator< (const date& temp) const
{

	if (myYear == temp.myYear)
	{
		if (myMonth == temp.myMonth)
		{
			return(myMonth < temp.myMonth);
		}
		else
		{
			return (myDay < temp.myDay);
		}
	}
	else
	{
		return(myYear < temp.myYear);
	}
}

bool date::operator> (const date& temp) const
{
	return (!(*this == temp) && !(*this < temp));
}

bool date::operator<= (const date& temp) const
{
	return ((*this < temp) || (*this == temp));
}

bool date::operator>= (const date& temp) const
{
	return ((*this > temp) || (*this == temp));
}


#endif
