//L.A.15.1 Frog1
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
	int steps;
	frog test;

	cout << "Enter Number of Steps: ";
	cin >> steps;

	while (test.getSteps() < steps)
	{
		test.takeStep();
	}
	cout << "Final Position: " << test.getPosition() << endl;

}
