// sorting template program

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"
#include <string>
#include <cstring>

using namespace std;

struct item
{
	int id;
	int inv;
};

struct storeType
{
	item list[50];
	int number;
};

void swap(item a, item b)
{
	item temp = a;
	a = b;
	b = temp;
}

void quickSort(item list[], int first, int last)
{
	int g = first, h = last;
	int midIndex, dividingValue, temp;

	midIndex = (first + last) / 2;
	dividingValue = list[midIndex].id;
	do
	{
		while (list[g].id < dividingValue)
		{
			g++;
		}
		while (list[h].id > dividingValue)
		{
			h--;
		}
		if (g <= h)
		{
			item temp = list[g];
			list[g] = list[h];
			list[h] = temp;
			g++;
			h--;
		}
	} while (g < h);
	if (h > first)
	{
		quickSort(list, first, h);
	}
	if (g < last)
	{
		quickSort(list, g, last);
	}
}


void main()
{
	storeType store;
	ifstream in;

	in.open("FILE50.txt");
	in >> store.number;
	for (int i = 0; i < store.number; i++)
	{
		in >> store.list[i].id >> store.list[i].inv;
	}

	quickSort(store.list, 0, store.number - 1);

	int line = 1;
	cout << setiosflags(ios::right);
	cout << setw(15) << "Id" << setw(10) << "Inv" << endl << endl;
	for (int i = 0; i < store.number; i++)
	{
		cout << line;
		cout << setw(15) << store.list[i].id;
		cout << setw(5) <<  store.list[i].inv << endl;
		if (line % 10 == 0)
		{
			cout << endl;
		}
		line++;
	}
}
