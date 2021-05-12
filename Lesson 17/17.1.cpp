//L.A.17.1 Rolling
//Brendan Wong

#include <iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include "dice.h"


using namespace std;


int main()
{
	int count = 0;
	dice myDice(6);
	int a = myDice.roll();
	int b = myDice.roll();
	int c = myDice.roll();
	cout << a << " " << b << " " << c << endl;
	count++;
	while ((a == b) || (a == c) || (b == c))
	{
		a = myDice.roll();
		b = myDice.roll();
		c = myDice.roll();
		cout << a << " " << b << " " << c << endl;
		count++;
	}
	cout << "Final Count: " << count;
}


