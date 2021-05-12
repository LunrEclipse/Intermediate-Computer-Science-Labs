//L.A.11 ACSLLAND
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>
#include "dice.h"

using namespace std;

int main()
{
	dice die1(6);
	dice die2(6);

	for (int num = 2; num < 13; num++)
	{
		int count = 0;
		for (int i = 0; i < 1000; i++)
		{
			int roll = die1.roll() + die2.roll();
			if (roll == num)
				count++;
		}
		double percent = ((double)count) / 1000 * 100;
		cout << setprecision(2) << setiosflags(ios::fixed);
		cout << setw(2) << num << " " << setw(3) << count << " / 1000" << setw(8) << " = " << percent << " %" << endl;
	}
	cout << endl << "End Results:" << endl << "Dice 1 was Rolled: " << die1.numRolls() << endl << "Dice 2 was Rolled: " << die2.numRolls();
}