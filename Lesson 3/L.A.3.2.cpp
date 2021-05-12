//L.A.3.2 Car Rental
//Brendan Wong

#include<iostream>  
#include <string.h>



using namespace std;

int main()
{
	string make;
	string model;
	string plate;
	char c1;
	char c2;
	char c3;
	int num;

	cout << "Enter Make of Car: ";
	cin >> make;

	cout << "Enter Model of Car: ";
	cin >> model;

	cout << "Enter License Plate (CPR 607): ";
	cin >> c1 >> c2 >> c3 >> num;

	int total = c1 + c2 + c3 + num;
	int position = total % 26;
	char letter = char(65 + position);

	cout << endl << "Make = " << make << endl;
	cout << "Model = " << model << endl;
	cout << c1 << c2 << c3 << " " << num << " = " << letter << total;
	return 0;





}