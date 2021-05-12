//L.A.9.1 Loan
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>


using namespace std;


int main()
{
	double principal;
	double low;
	double high;
	double years;

	cout << "Enter Principal: ";
	cin >> principal;

	cout << "Enter Low Interest Rate: ";
	cin >> low;

	cout << "Enter High Interest Rate: ";
	cin >> high;

	cout << "Enter Years: ";
	cin >> years;

	cout << endl << endl;

	cout << setprecision(2) << setiosflags(ios::fixed);
	
	while (low <= high)
	{
		double k = low / 12 / 100;
		double c = pow(1 + k, years * 12);
		double payment = (principal * k * c) / (c - 1);
		cout << low << "%: " << payment << endl;
		low = low + 0.25;
	}




}

