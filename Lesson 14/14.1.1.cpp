//L.A.14.1 Squeeze
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>
#include <fstream>



using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	bool atSpaces = true;
	int count = 0;
	char letter;

	inFile.open("squeeze.txt");
	outFile.open("squeezed.txt");

	while (inFile.get(letter))
	{
		if (atSpaces && letter == ' ')
		{
			count++;
		}
		else
		{
			if (letter == '\n')
			{
				if (atSpaces)
					outFile << setw(2) << count;
				outFile << '\n';
				atSpaces = true;
			}
			else
			{
				if (atSpaces)
				{
					outFile << setw(2) << count << " " << letter;
					atSpaces = false;
				}
				else
					outFile << letter;
			}
			count = 0;
		}
	}

}
