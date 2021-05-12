

#include <iostream>
#include <fstream>
#include "dice.h"	
#include <iomanip>

const int MAX = 8;		

using namespace std;



bool inBound(int row, int col, int max, int** table)
{
	if (row >= 1 && row <= max)
		if (col >= 1 && col <= max)
			if(table[row][col] == 0)
				return true;

	return false;
}

bool isPossible(int row, int col, int max, int** table)
{
	if (!inBound(row - 2, col + 1, MAX, table))
		if (!inBound(row - 1, col + 2, MAX, table))
			if (!inBound(row + 1, col + 2, MAX, table))
				if (!inBound(row + 2, col + 1, MAX, table))
					if (!inBound(row + 2, col - 1, MAX, table))
						if (!inBound(row + 1, col - 2, MAX, table))
							if (!inBound(row - 1, col - 2, MAX, table))
								if (!inBound(row - 2, col - 1, MAX, table))
									return false;

	return true;
}


void main()
{
	int** a = new int* [MAX + 1];
	for (int i = 0; i < MAX + 1; ++i)
		a[i] = new int[MAX + 1];

	for (int i = 1; i <= MAX; i++)
		for (int j = 1; j <= MAX; j++)
			a[i][j] = 0;

	int row = 1;
	int col = 1;

	int count = 1;

	a[row][col] = count;
	count++;

	while (isPossible(row, col, MAX, a))
	{
		dice die(MAX);
		bool moveMade = false;
		while (!moveMade)
		{
			int move = die.roll();
			cout << row << " " << col << " " << move << endl;
			if (move == 1 && inBound(row - 2, col + 1, MAX, a))
			{
				moveMade = true;
				row = row - 2;
				col = col + 1;
				a[row][col] = count;
				count++;
			}
			if (move == 2 && inBound(row - 1, col + 2, MAX, a))
			{
				moveMade = true;
				row = row - 1;
				col = col + 2;
				a[row][col] = count;
				count++;
			}
			if (move == 3 && inBound(row + 1, col + 2, MAX, a))
			{
				moveMade = true;
				row = row + 1;
				col = col + 2;
				a[row][col] = count;
				count++;
			}
			if (move == 4 && inBound(row + 2, col + 1, MAX, a))
			{
				moveMade = true;
				row = row + 2;
				col = col + 1;
				a[row][col] = count;
				count++;
			}
			if (move == 5 && inBound(row + 2, col - 1, MAX, a))
			{
				moveMade = true;
				row = row + 2;
				col = col - 1;
				a[row][col] = count;
				count++;
			}
			if (move == 6 && inBound(row + 1, col - 2, MAX, a))
			{
				moveMade = true;
				row = row + 1;
				col = col - 2;
				a[row][col] = count;
				count++;
			}
			if (move == 7 && inBound(row - 1, col - 2, MAX, a))
			{
				moveMade = true;
				row = row - 1;
				col = col - 2;
				a[row][col] = count;
				count++;
			}
			if (move == 8 && inBound(row - 2, col - 1, MAX, a))
			{
				moveMade = true;
				row = row - 2;
				col = col - 1;
				a[row][col] = count;
				count++;
			}
		}
	}

	cout << setiosflags(ios::right);
	cout << "     ";
	for (int i = 1; i <= 8; i++)
		cout << setw(5) << i;
	cout << endl << endl;
	for (int j  = 1; j <= 8; j++)
	{
		cout << setw(5) << j;
		for (int i  = 1; i <= 8; i++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}

	cout << count << " squares were visited";

	return;

	
}
