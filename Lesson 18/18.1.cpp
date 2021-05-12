
// makeLife.cpp

#include <iostream>
#include <fstream>
#include "dice.h"		// random number generator from Lesson 12
#include <iomanip>

const int MAX = 20;		// sets grid size for Life problem

using namespace std;


void main()
{
	int howMany;
	int** a = new int* [MAX + 1];
	for (int i = 0; i < MAX + 1; ++i)
		a[i] = new int[MAX + 1];

	for (int i = 1; i <= MAX; i++)
	{
		for (int j = 1; j <= MAX; j++)
		{
			a[i][j] = 0;
		}
	}

	ifstream infile("LIFE100.txt", ios::in);
	int num;
	infile >> num;
	for (int i = 0; i < num; i++)
	{
		int row;
		int col;
		infile >> row;
		infile >> col;
		a[row][col] = 1;
	}

	for (int i = 0; i < 5; i++)
	{
		int** b = new int* [MAX + 1];
		for (int j = 0; j < MAX + 1; j++)
			b[j] = new int[MAX + 1];

		for (int j = 1; j <= MAX; j++)
		{
			for (int k = 1; k <= MAX; k++)
			{
				b[j][k] = 0;
			}
		}

		for (int j = 1; j <= MAX; j++)
		{
			for (int k = 1; k <= MAX; k++)
			{
				int count = 0;
				for (int l = -1; l <= 1; l++)
				{
					for (int m = -1; m <= 1; m++)
					{
						int curRow = j + l;
						int curCol = k + m;
						if (curRow >= 1 && curRow <= 20)
							if (curCol >= 1 && curCol <= 20)
								if(l!= 0 || m!= 0)
									if (a[curRow][curCol] == 1)
										count++;
					}
				}

				if (a[j][k] == 0 && count == 3)
					b[j][k] = 1;
				else if (a[j][k] == 1 && count <= 1)
					b[j][k] = 0;
				else if (a[j][k] == 1 && count >= 4)
					b[j][k] = 0;
				else if (a[j][k] == 1)
					b[j][k] = 1;
			}
		}

		a = b;
	}

	int living = 0;
	int row10 = 0;
	int col10 = 0;

	cout << setiosflags(ios::right);
	cout << "       12345678901234567890" << endl << endl;
	for (int i = 1; i <= MAX; i++)
	{
		cout << setw(2) << i << "     ";
		for (int j = 0; j <= MAX; j++)
		{
			if (a[i][j] == 1)
			{
				cout << "*";
				living++;
				if (i == 10)
					row10++;
				if (j == 10)
					col10++;
			}
			else cout << " ";
		}
		cout << endl;
	}

	cout << "Alive in Row 10: " << row10 << endl;
	cout << "Alive in Col 10: " << col10 << endl;
	cout << "Total Alive: " << living << endl;


}
