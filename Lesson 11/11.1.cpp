//L.A.11.1 GPA
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>


using namespace std;

int main()
{
	char choice;
	do
	{
		char grade;
		int count = 0;
		int total = 0;
		bool hasF = false;

		cout << "GPA:" << endl << endl;
		do {

			cout << "Enter grade: ";
			cin >> grade;
			if ('a' <= grade && grade <= 'z')
				grade -= 32;
			if ('A' <= grade && grade <= 'D' || grade == 'F')
			{
				switch (grade)
				{
				case 'A': total += 4;  break;
				case 'B': total += 3;  break;
				case 'C': total += 2;  break;
				case 'D': total += 1;  break;
				case 'F': hasF = true;  break;
				}
				count++;
			}
		} while ('A' <= grade && grade <= 'D' || grade == 'F');

		double gpa = double(total) / count;
		cout << setprecision(2) << endl << "GPA = " << gpa << endl;
		if (count < 4)
			cout << "Ineligible, taking less than 4 classes" << endl;
		else if (gpa < 2.0 && !hasF)
			cout << "Ineligible, gpa below 2.0" << endl;
		else if (gpa >= 2.0 && hasF)
			cout << "Ineligible, gpa above 2.0 but has F grade" << endl;
		else if (gpa < 2.0 && hasF)
			cout << "Ineligible, gpa below 2.0 and has F grade" << endl;
		else
			cout << "Eligible" << endl;
		cout << endl << "Do you wish to continue (y/n): ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');


}
