// sorting template program

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"

using namespace std;

const int SIZE = 500;
int steps = 0;

void fillArray(int temp[]);
void screenOutput(int temp[]);
void swap(int& a, int& b);
void bubbleSort(int list[]);
void selectionSort(int list[]);
void insertionSort(int list[]);
void mergeSort(int list[], int first, int last);
void merge(int list[], int first, int mid, int last);
void quickSort(int list[], int first, int last);
void sortMenu(int list[]);

void main()
{
	int list[SIZE + 1] = {};

	sortMenu(list);
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
		if (loop % 12 == 0) cout << endl;
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

void bubbleSort(int list[])
{
	cout << endl << "Bubble Sort" << endl << endl;
	steps = 0;
	steps++;	//  initialization of outer
	for (int outer = 1; outer <= list[0] - 1; outer++)
	{
		steps += 3;
		//  1 - boundary check of outer loop;
		//  2 - increment, outer++
		//  3 - initialization of inner loop
		for (int inner = 1; inner <= list[0] - outer; inner++)
		{
			steps += 3;
			//  1 - boundary check of inner loop
			//  2 - increment, inner++
			//  3 - if comparison
			if (list[inner] > list[inner + 1])
			{
				swap(list[inner], list[inner + 1]);
				steps++;
			}
		}
	}

}

void selectionSort(int list[])
{
	cout << endl << "Selection Sort" << endl << endl;
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

void insertionSort(int list[])
{
	cout << endl << "Insertion Sort" << endl << endl;
	int outer, pos, temp;
	steps = 0;
	steps++;
	for (outer = 2; outer <= list[0]; outer++)
	{
		steps + 3;
		pos = outer;
		temp = list[pos];	// move list[pos] out of list
		while ((pos > 1) && (list[pos - 1] > temp))
		{
			steps += 3;
			list[pos] = list[pos - 1];
			pos--;
			steps++;
		}
		list[pos] = temp;
		steps++;
	}

}

void mergeSort(int list[], int first, int last)
{
	steps = 0;
	if (first != last)
	{
		steps++;
		if (first + 1 == last)
		{
			steps++;
			if (list[first] > list[last])
			{
				swap(list[first], list[last]);
				steps += 2;
			}
		}
		else
		{
			int mid = (first + last) / 2;
			mergeSort(list, first, mid);
			mergeSort(list, mid + 1, last);
			merge(list, first, mid, last);
			steps += 4;
		}

	}
}

void merge(int list[], int first, int mid, int last)
{
	int pos1 = first;
	int pos2 = mid + 1;
	int temp[SIZE + 1] = {};
	int total = last - first + 1;
	steps += 6;
	for (int i = first; i <= total + first; i++)
	{
		if (pos1 > mid)
		{
			temp[i] = list[pos2];
			pos2++;
			steps += 3;
		}
		else if (pos2 > last)
		{
			temp[i] = list[pos1];
			pos1++;
			steps += 4;
		}
		else if (list[pos1] < list[pos2])
		{
			temp[i] = list[pos1];
			pos1++;
			steps += 5;
		}
		else
		{
			temp[i] = list[pos2];
			pos2++;
			steps += 6;
		}
		steps++;
	}
	steps += 2;
	for (int i = first; i <= last; i++)
	{
		list[i] = temp[i];
			steps += 2;
	}
}

void quickSort(int list[], int first, int last)
{
	steps = 0;
	int g = first, h = last;
	int midIndex, dividingValue, temp;

	midIndex = (first + last) / 2;
	steps++;
	dividingValue = list[midIndex];
	do
	{
		while (list[g] < dividingValue)
		{
			g++;
			steps+=2;
		}
		while (list[h] > dividingValue)
		{
			h--;
			steps += 2;
		}
		if (g <= h)
		{
			swap(list[g], list[h]);
			g++;
			h--;
			steps += 3;
		}
		steps+=2;
	} while (g < h);
	if (h > first)
	{
		quickSort(list, first, h);
		steps++;
	}
	if (g < last)
	{
		quickSort(list, g, last);
		steps++;
	}
	steps += 2;
}


void sortMenu(int temp[])
{
	char choice, print;

	do
	{
		cout << "Sorting algorithm menu" << endl << endl;
		cout << "(1) Bubble sort" << endl;
		cout << "(2) Selection sort" << endl;
		cout << "(3) Insertion sort" << endl;
		cout << "(4) Recursive mergesort" << endl;
		cout << "(5) Quicksort" << endl;
		cout << "(6) Quit" << endl << endl;
		cout << "Choice ---> ";
		cin >> choice;
		cin.get();	// to dump return key
		cout << endl;
		if ('1' <= choice && choice <= '5')
		{
			fillArray(temp);
			switch (choice)
			{
			case '1': bubbleSort(temp); break;
			case '2': selectionSort(temp); break;
			case '3': insertionSort(temp); break;
			case '4': mergeSort(temp, 1, temp[0]); break;
			case '5': quickSort(temp, 1, temp[0]); break;
			}
			cout << endl << "Print list to screen (y/n)? ";
			cin >> print;
			cin.get();
			if (print == 'y' || print == 'Y')
			{
				screenOutput(temp);
				cout << endl << "Steps: " << steps << endl;
			}
			cout << endl << "Hit return to continue ";
			cin.get();
		}
	} while (choice != '6');
}

