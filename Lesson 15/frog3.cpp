//L.A.15.3 Frog3
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
	int sameSpot = 0;
	frog frog1;
	frog frog2;

	cout << "Enter Steps: ";
	cin >> steps;
	while(frog1.getSteps() < steps)
	{
		frog1.takeStep();
		frog2.takeStep();
		if (frog1.getPosition() == frog2.getPosition())
			sameSpot++;
	}
	cout << "Position of Frog1: " << frog1.getPosition() << endl;
	cout << "Position of Frog2: " << frog2.getPosition() << endl;
	cout << "Same Positions: " << sameSpot << endl;

}
