//L.A.14.2 Average
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>
#include <fstream>



using namespace std;

int main()
{
	int  number = 0;
	int count = 0;
	int total = 0;
	double avg = 0;

	ifstream file ("numbers.txt");
	while (file >> number)
	{
		total += number;
		count++;
	}
	avg = float(total) / count;
	cout << setiosflags(ios::fixed) << setprecision(2) << "Average = " << avg << endl;

}
