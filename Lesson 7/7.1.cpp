//L.A.7.1 Fun
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>


void GetValues(int&, int&);
void GetValues(double&, double&);
void PrintValues(const int&, const int&);
void PrintValues(const double&, const double&);

template <class dataType>
void swapNum(dataType&, dataType&);

using namespace std;

int main()
{
	int a;
	int b;
	double c;
	double d;

	GetValues(a, b);
	cout <<"The two numbers: ";
	PrintValues(a, b);

	GetValues(c, d);
	cout << "The two doubles: ";
	PrintValues(c, d);

	swapNum(a, b);
	swapNum(c, d);

	cout <<  endl << "Numbers after swap: ";
	PrintValues(a, b);

	cout << "Doubles after swap: ";
	PrintValues(c, d);
	return 0;


}

void GetValues(int& one, int& two)
{
	cout << "First number: ";
	cin >> one;
	cout << "Second number: ";
	cin >> two;
	cout << endl;
}

void GetValues(double& first, double& second)
{
	cout << "First double ---> ";
	cin >> first;
	cout << "Second double ---> ";
	cin >> second;
	cout << endl;
}

void PrintValues(const int& one, const int& two)
{

	cout << one << ", " << two << endl << endl;
}

void PrintValues (const double &first, const double &second)
{
	cout << first << ", " << second << endl;
}

template <class dataType>
void swapNum (dataType &one, dataType &two)
{
	dataType  temp = one;
	one = two;
	two = temp;
}

