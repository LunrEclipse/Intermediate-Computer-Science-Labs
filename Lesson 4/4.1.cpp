//L.A.4.1 Taxes
//Brendan Wong

#include<iostream>  
#include <string.h>



using namespace std;

int main()
{

	int hoursWorked;
	double hourlyRate;
	double federalTax = 0.15;
	double ficaTax = 0.08;
	double stateTax = 0.032;
	double total;

	cout << "Hours Worked: ";
	cin >> hoursWorked;

	cout << "Hourly Rate: ";
	cin >> hourlyRate;

	double totalPay = hoursWorked * hourlyRate;

	cout << endl << endl << "Gross pay: " << totalPay;

	double fedPaid = totalPay * federalTax;
	cout << endl << endl << "Federal Tax: " << fedPaid;

	double ficaPaid = totalPay * ficaTax;
	cout << endl << "FICA Tax: " << ficaPaid;

	double statePaid = totalPay * stateTax;
	cout << endl << "State Tax: " << statePaid;

	double netPaid = totalPay - fedPaid - ficaPaid - statePaid;
	cout << endl << endl << "Net Pay: " << netPaid;
	return 0;





}