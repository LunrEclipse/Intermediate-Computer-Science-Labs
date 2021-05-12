//L.A.10.1 Pyramids
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>


using namespace std;

int main()
{
	double principal;
	double interest;
	double monthlyPayment;
	double rate;
	int count = 1;
	double total = 0.0;

	cout << "Enter Principal: $";
	cin >> principal;

	cout << "Enter Annual Interest Rate: %";
	cin >> rate;

	cout << "Enter Monthly Payment: $";
	cin >> monthlyPayment;

	double monthlyRate = rate / 12 / 100;

	cout << setprecision(2) << setiosflags(ios::fixed) << "Month     Principal     Interest     Payment     New Balance" << endl << endl;
	do
	{
		interest = principal * monthlyRate;
		cout << setw(5) << count << setw(14) << principal << setw(13) << interest << setw(12) << monthlyPayment;
		principal = principal + interest - monthlyPayment;
		cout << setw(16) << principal << endl;
		total += interest;
		count++;
	} while (principal > monthlyPayment);

	cout << endl << "Total Interest: $" << total;


}
