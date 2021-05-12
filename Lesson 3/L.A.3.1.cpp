//L.A.3.1 Change
//Brendan Wong

#include<iostream>  




using namespace std;

int main()
{
	double purchase;
	double paid;
	double temp;

	cout << "Enter amount of purchase: ";
	cin >> purchase;
	cout << "Enter amount of cash paid: ";
	cin >> paid;
	temp = paid - purchase;
	temp = temp - int(temp) +0.00001;
	int change = int(temp * 100);
	cout << endl << "Change: " << change << " cents"<< endl;

	int quarters = change / 25;
	int remainder = change % 25;
	int dimes = remainder / 10;
	remainder = remainder % 10;
	int nickels = remainder / 5;
	int pennies = remainder % 5;

	cout << "Quarters: " << quarters << endl;
	cout << "Dimes: " << dimes << endl;
	cout << "Nickels: " << nickels << endl;
	cout << "Pennies: " << pennies << endl;

	return 0;

}