//L.A.10.1 Pyramids
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>

void printTable(int row, int col);
void pyramid(int row);


using namespace std;

int main()
{
	printTable(4, 6);
	cin.get();
	printTable(11, 12);
	cin.get();
	pyramid(10);
	cin.get();
	pyramid(25);
	cin.get();
	return 0;



}

void printTable(int row, int col)
{
	cout << "    ";
	for (int i = 1; i <= col; i++)
	{
		cout << setw(4) << i;
	}
	cout << endl << endl;

	for (int i = 1; i <= row; i++)
	{
		cout << i << "   ";
		cout << setiosflags(ios::right);
		for (int j = 1; j <= col; j++)\
		{
			cout << setw(4) << i*j;
		}
		cout << endl;
	}
	cout << endl;
}

void pyramid(int row)
{
	int stars = 1;
	int blanks = (row * 2 - 1)/2;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < blanks; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < stars; j++)
		{
			cout << "*";
		}
		for (int j = 0; j < blanks; j++)
		{
			cout << " ";
		}
		stars += 2;
		blanks -= 1;
		cout << endl;
	}
}