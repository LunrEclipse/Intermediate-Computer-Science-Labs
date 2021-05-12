// sorting template program

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"

using namespace std;

const int SIZE = 200;
int steps = 0;

void fillArray(int temp[]);
void screenOutput(int temp[]);
void swap(int& a, int& b);
void selectionSort(int list[]);
void mergeSort(int list1[], int list2[], int final[]);

void main()
{
	int list1[SIZE + 1] = {};
	int list2[SIZE + 1] = {};
	int final[SIZE * 2 + 1] = {};
	fillArray(list1);
	selectionSort(list1);
	fillArray(list2);
	selectionSort(list2);
	mergeSort(list1, list2, final);
	screenOutput(final);

}


void fillArray(int temp[])
/* Asks the user for two inputs:  1)  the number of data to generate, and
	2) the largest possible random integer to create.  Then proceeds to fill
	the array, from 1..number, where number is stored in temp[0]. */
{
	int  size;

	cout << "How many numbers to you wish to generate? ";
	cin >> temp[0];
	cout << endl << "Largest integer to generate? ";
	cin >> size;
	dice die(size);	// allocate dice object
	for (int loop = 1; loop <= temp[0]; loop++)
		temp[loop] = die.roll();
}

void screenOutput(int temp[])
// prints out the contents of the array in tabular form, 12 columns
{
	cout << setiosflags(ios::right) << endl;
	for (int loop = 1; loop <= temp[0]; loop++)
	{
		cout << setw(6) << temp[loop];
		if (loop % 20 == 0) cout << endl;
	}
	cout << endl;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
	steps += 3;
}

void selectionSort(int list[])
{
	int flag;
	steps = 0;
	steps++;
	for (int outer = 1; outer < list[0]; outer++)
	{
		steps += 3;
		flag = outer;
		for (int inner = outer + 1; inner <= list[0]; inner++)
		{
			steps += 3;
			if (list[inner] < list[flag])
			{
				flag = inner;
			}
		}
		swap(list[outer], list[flag]);
		steps++;
	}

}

void mergeSort(int list1[], int list2[], int final[])
{
	cout << endl << "MergeSort" << endl << endl;
	int pos1 = 1;
	int pos2 = 1;
	final[0] = list1[0] + list2[0];
	for (int i = 1; i <= final[0]; i++)
	{
		if (pos1 > list1[0])
		{
			final[i] = list2[pos2];
			pos2++;
		}
		else if (pos2 > list2[0])
		{
			final[i] = list1[pos1];
			pos1++;
		}
		else if (list1[pos1] < list2[pos2])
		{
			final[i] = list1[pos1];
			pos1++;
		}
		else
		{
			final[i] = list2[pos2];
			pos2++;
		}
	}
}

void quickSort(int list[])
{
	cout << endl << "QuickSort" << endl << endl;
}


