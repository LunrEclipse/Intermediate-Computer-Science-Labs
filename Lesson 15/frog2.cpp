//L.A.15.2 Frog2
//Brendan Wong

#include <iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>
#include <fstream>
#include "frog.h"



using namespace std;

int main()
{
	int distance;
	frog  test;

	cout << "Enter Distance from Origin: ";
	cin >> distance;
	while (-distance < test.getPosition() && test.getPosition() < distance)
	{
		test.takeStep();
	}
	cout << "Position of Frog = " << test.getPosition() << endl;
	cout << "Number of Steps = " << test.getSteps() << endl;
	return 0;

}
