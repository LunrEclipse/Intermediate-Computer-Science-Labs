//L.A.4.2 Quadratic
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>.h



using namespace std;

int main()
{

	double a;
	double b;
	double c;

	cout << "Enter a value: ";
	cin >> a;

	cout << "Enter b value: ";
	cin >> b;

	cout << "Enter c value: ";
	cin >> c;

	double determinate = sqrt(pow(b, 2) - 4 * a * c);
	double firstRoot = (-b + determinate) / 2 * a;
	double secondroot = (-b - determinate) / 2 * a;
	cout << setiosflags(ios::right | ios::fixed | ios::showpoint) << setprecision(4);
	cout << endl << endl << "First Root: " << firstRoot << endl << "Second Root: " << secondroot;





}