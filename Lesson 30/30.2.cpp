#include "date.h"
#include <iostream.h>


void main ()
{
	date day1;
	date day2;
	int count;
	
	cout << "How many number of days to compare: ";
	cin >> count;
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "Enter day1 (mo day yr) ---> ";
		cin >> day1;
		cout << "Enter day2 (mo day yr) ---> ";
		cin >> day2;
		cout << endl;
		
		int difference = 0;
		if(day1 < day2)
		{
			while(day1 < day2)
			{
				day1++;
				num++;
			}
		}
		else if(day1 > day2)
		{
			while(day1 > day2)
			{
				day1--;
				num++;
			}
		}		


		cout << day1 << " and " << day2 << " are " << difference << " days apart." << endl << endl;
	}
}

