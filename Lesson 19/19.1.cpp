

#include <iostream>
#include <fstream>
#include "dice.h"	
#include <iomanip>
	

using namespace std;

enum  cellType { black, white };

void print(cellType board[][21] )
{
	cout << setiosflags(ios::right);
	cout << "       12345678901234567890" << endl << endl;
	for (int i = 1; i <= 20; i++)
	{
		cout << setw(2) << i << "     ";
		for (int j = 0; j <= 20; j++)
		{
			if (board[i][j] == white)
			{
				cout << "@";

			}
			else cout << "-";
		}
		cout << endl;
	}
}

void remove(cellType board[][21], int row, int col)
{
	if (row >= 1 && row <= 20)
	{
		if (col >= 1 && col <= 20)
		{
			if (board[row][col] == white)
			{
				board[row][col] = black;
				remove(board, row + 1, col + 1);
				remove(board, row + 1, col);
				remove(board, row + 1, col - 1);
				remove(board, row, col + 1);
				remove(board, row, col - 1);
				remove(board, row - 1, col + 1);
				remove(board, row - 1, col);
				remove(board, row - 1, col - 1);
			}
		}
	}
}



void main()
{
	cellType board[21][21] = {};
	ifstream infile("digital.txt", ios::in);
	int num;
	infile >> num;
	for (int i = 0; i < num; i++)
	{
		int row;
		int col;
		infile >> row;
		infile >> col;
		board[row][col] = white;
	}

	print(board);

	int row; 
	int col;

	cout << endl << "Enter a Row (0 to Terminate): ";
	cin >> row;
	cout << "Enter a Col (0 to Terminate): ";
	cin >> col;
	while (row != 0 && col != 0)
	{
		remove(board, row, col);
		print(board);

		cout << endl << "Enter a Row (0 to Terminate): ";
		cin >> row;
		cout << "Enter a Col (0 to Terminate): ";
		cin >> col;
	}
	
}
