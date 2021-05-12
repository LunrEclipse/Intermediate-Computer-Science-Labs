//L.A.8.1 Taxes
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>


using namespace std;

double single(double);
double married(double);

int main()
{
	char status;
	double income;
	cout << setprecision(2) << setiosflags(ios::fixed);
	cout << "Enter Marital Status, Single(S) or Married (M): ";
	cin >> status;

	cout << "Enter Income: ";
	cin >> income;

	if (status == 'S')
	{
		cout << "Single Tax: " << single(income);
	}
	else
	{
		cout << "Married Tax: " << married(income);
	}

}

double single(double income)
{
	if (income < 24650)
	{
		return income * 0.15;
	}
	else if (income < 59750)
	{
		return 3697.50 + 0.28 * (income - 24650);
	}
	else
		return 13525.5 + 0.31 * (income - 59750);
}

double married(double income)
{
	if (income < 41,200)
	{
		return income * 0.15;
	}
	else if (income < 99600)
	{
		return 6180 + 0.28 * (income - 41200);
	}
	else
		return 22532 + 0.31 * (income - 99600);
}
