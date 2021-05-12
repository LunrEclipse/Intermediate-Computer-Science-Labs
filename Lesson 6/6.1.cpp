//L.A.6.1 Fun
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>


double fToC(double);
double cToF(double);
double sphereVol(double);
double Pythag(double, double);


using namespace std;

int main()
{
	cout << setiosflags (ios::fixed) << setprecision(2);

	cout << "Fahrenheit to Celsius: " << endl;
	cout << "212 F = " << fToC(212) << endl;
	cout << "98.6 F = " << fToC(98.6) << endl;
	cout << "10 F = " << fToC(10) << endl << endl;

	cout << "Celsius to Fahrenheit: " << endl;
	cout << "-15 C = " << cToF(-15) << endl;
	cout << "0 C = " << cToF(0) << endl;
	cout << "70 C = " << cToF(70) << endl << endl;
	
	cout << "Volumes: " << endl;
	cout << "Radius: 1.0 = " << sphereVol(1.0) << endl;
	cout << "Radius: 2.25 = " << sphereVol(2.25) << endl;
	cout << "Radius: 7.5 = " << sphereVol(7.5) << endl << endl;

	cout << "Pythagorean Theorem: " << endl;
	cout << "Sides 3.0 and 4.0 = " << Pythag(3.0, 4.0) << endl;
	cout << "Side 6.75 and 12.31 = " << Pythag(6.75, 12.31) << endl;

}

double fToC(double fahr)
{
	return 5.0 / 9.0 * (fahr - 32);
}

double cToF(double cel)
{
	return (9.0 / 5.0 * cel) + 32;
}

double sphereVol(double rad)
{
	return 4.0 / 3.0 * pow(rad, 3) * (atan(1)*4);
}

double Pythag(double a, double b)
{
	return sqrt(pow(a, 2) + pow(b, 2));
}