

#include <iostream>
#include <fstream>
#include "dice.h"	
#include <iomanip>

const int MAX = 8;		

using namespace std;



bool inBound(int row, int col, int max)
{
	if (row >= 1 && row <= max)
		if (col >= 1 && col <= max)
				return true;

	return false;
}

void main()
{
	int a[9][9] = {};


	ifstream infile("ACCESS.txt", ios::in);
	int access[9][9] = {};
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			infile >> access[i][j];

	int row = 1;
	int col = 1;

	int count = 1;

	a[row][col] = count;
	count++;
	access[row][col] = 0;

	for (count = 2; count <= 64; count++)
	{
		int move = 0;
		int howAccessible = 9;
		if (inBound(row - 2, col + 1, MAX))
		{
			row = row - 2;
			col = col + 1;
			if (access[row][col] < howAccessible && a[row][col] == 0)
			{
				howAccessible = access[row][col];
				move = 1;
			}
			if (access[row][col] > 0)
			{
			int temp = access[row][col];
			temp = temp--;
			access[row][col] = temp;
			}
			row = row + 2;
			col = col - 1;
		}
		if (inBound(row - 1, col + 2, MAX))
		{
			row = row - 1;
			col = col + 2;
			if (access[row][col] < howAccessible && a[row][col] == 0)
			{
				howAccessible = access[row][col];
				move = 2;
			}
			if (access[row][col] > 0)
			{
				int temp = access[row][col];
				temp = temp--;
				access[row][col] = temp;
			}
			row = row + 1;
			col = col - 2;
		}
		if (inBound(row + 1, col + 2, MAX))
		{
			row = row + 1;
			col = col + 2;
			if (access[row][col] < howAccessible && a[row][col] == 0)
			{
				howAccessible = access[row][col];
				move = 3;
			}
			if (access[row][col] > 0)
			{
				int temp = access[row][col];
				temp = temp--;
				access[row][col] = temp;
			}
			row = row - 1;
			col = col - 2;
		}
		if (inBound(row + 2, col + 1, MAX))
		{
			row = row + 2;
			col = col + 1;
			if (access[row][col] < howAccessible && a[row][col] == 0)
			{
				howAccessible = access[row][col];
				move = 4;
			}
			if (access[row][col] > 0)
			{
				int temp = access[row][col];
				temp = temp--;
				access[row][col] = temp;
			}
			row = row - 2;
			col = col - 1;
		}
		if (inBound(row + 2, col - 1, MAX))
		{
			row = row + 2;
			col = col - 1;
			if (access[row][col] < howAccessible && a[row][col] == 0)
			{
				howAccessible = access[row][col];
				move = 5;
			}
			if (access[row][col] > 0)
			{
				int temp = access[row][col];
				temp = temp--;
				access[row][col] = temp;
			}
			row = row - 2;
			col = col + 1;
		}
		if (inBound(row + 1, col - 2, MAX))
		{
			row = row + 1;
			col = col - 2;
			if (access[row][col] < howAccessible && a[row][col] == 0)
			{
				howAccessible = access[row][col];
				move = 6;
			}
			if (access[row][col] > 0)
			{
				int temp = access[row][col];
				temp = temp--;
				access[row][col] = temp;
			}
			row = row - 1;
			col = col + 2;
		}
		if (inBound(row - 1, col - 2, MAX))
		{
			row = row - 1;
			col = col - 2;
			if (access[row][col] < howAccessible && a[row][col] == 0)
			{
				howAccessible = access[row][col];
				move = 7;
			}
			if (access[row][col] > 0)
			{
				int temp = access[row][col];
				temp = temp--;
				access[row][col] = temp;
			}
			row = row + 1;
			col = col + 2;
		}
		if (inBound(row - 2, col - 1, MAX))
		{
			row = row - 2;
			col = col - 1;
			if (access[row][col] < howAccessible && a[row][col] == 0)
			{
				howAccessible = access[row][col];
				move = 8;
			}
			if (access[row][col] > 0)
			{
				int temp = access[row][col];
				temp = temp--;
				access[row][col] = temp;
			}
			row = row + 2;
			col = col + 1;
		}

		if (move == 1)
		{
			row = row - 2;
			col = col + 1;
			a[row][col] = count;
		}
		if (move == 2)
		{
			row = row - 1;
			col = col + 2;
			a[row][col] = count;
		}
		if (move == 3)
		{
			row = row + 1;
			col = col + 2;
			a[row][col] = count;
		}
		if (move == 4)
		{
			row = row + 2;
			col = col + 1;
			a[row][col] = count;
		}
		if (move == 5)
		{
			row = row + 2;
			col = col - 1;
			a[row][col] = count;
		}
		if (move == 6)
		{
			row = row + 1;
			col = col - 2;
			a[row][col] = count;
		}
		if (move == 7)
		{
			row = row - 1;
			col = col - 2;
			a[row][col] = count;
		}
		if (move == 8)
		{
			row = row - 2;
			col = col - 1;
			a[row][col] = count;
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

	cout << count-1 << " squares were visited";

	return;

	
}
