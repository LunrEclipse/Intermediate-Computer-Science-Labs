
// makeLife.cpp

#include <iostream>
#include <fstream>
#include "dice.h"		// random number generator from Lesson 12
#include <iomanip>

const int MAX = 20;		// sets grid size for Life problem

using namespace std;



void inoculate(int** table, int howMany)
{
	int count = 0, row, col;
	dice die(MAX);

	while (count < howMany)
	{
		row = die.roll();
		col = die.roll();
		if (0 == table[row][col])
		{
			table[row][col] = 1;
			count++;
			cout << setw(4) << row << setw(4) << col << endl;
		}
	}
}

void saveFile(int** table, int howMany)
{
	ofstream outFile("lifeData.txt");
	// ofstream outFile ("lifeData.txt", ios::out);		Wintel version

	outFile << howMany << endl;
	for (int row = 1; row <= MAX; row++)
		for (int col = 1; col <= MAX; col++)
			if (table[row][col])
			{
				outFile << setw(4) << row << setw(4) << col << endl;
				cout << setw(4) << row << setw(4) << col << endl;
			}
}

void main()
{
	int howMany; 
	int** a = new int* [MAX+1];
	for (int i = 0; i < MAX+1; ++i)
		a[i] = new int[MAX+1];

	for (int i = 1; i <= MAX; i++)
	{
		for (int j = 1; j <= MAX; j++)
		{
			a[i][j] = 0;
		}
	}
	cout << "Life data file program" << endl << endl;
	cout << "Enter number of bacteria to create ---> ";
	cin >> howMany;
	inoculate(a, howMany);
	saveFile(a, howMany);
	return;
}
