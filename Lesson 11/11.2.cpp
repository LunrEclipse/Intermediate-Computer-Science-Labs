//L.A.11 ACSLLAND
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	char choice;
	cout << "ACSLLand Problem" << endl;
	do
	{
		int a = 0;
		int b = 0;
		bool finished = false;
		int count = 0;
		int value = 1;

		cout << "Enter Rolls (0 to end)" << endl << endl;
		while (value > 0)
		{
			cout << "Roll: ";
			cin >> value;
			if (value > 0)
			{
				count++;
				if (count % 2 == 1)
				{
					if (value != 4 && value != 6)
					{
						a += value;
					}
					else
					{
						a -= value;
					}
					if (a < 0)
						a = 0;
					if (a > 40)
						a = 40;
					if (a == b)
						b = 0;
				}
				else
				{
					if (value != 4 && value != 6)
					{
						b += value;
					}
					else
					{
						b -= value;
					}
					if (b < 0)
						b = 0;
					if (b > 40)
						b = 40;
					if (b == a)
						a = 0;
				}
			}
		}
		cout << endl << "Game is Over. Result" << endl;
		if (a == 0)
		{
			cout << "A - Start" << endl;
		}
		else if (a == 40)
		{
			cout << "A - End" << endl;
		}
		else
		{
			cout << "A - " << a << endl;
		}

		if (b == 0)
		{
			cout << "B - Start" << endl;
		}
		else if (b == 40)
		{
			cout << "B - End" << endl;
		}
		else
		{
			cout << "B - " << b << endl << endl;
		}

		cout << endl << "Do you wish to play again (y/n)? ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

}

void turn(int &cur, int &other, int value)
{
	if (value != 4 && value != 6)
	{
		cur += value;
	}
	else
	{
		cur -= value;
	}
	if (cur < 0)
		cur = 0;
	if (cur > 40)
		cur = 40;
	if (cur = other)
		other = 0;
}