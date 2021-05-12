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

int bsearch(const storeType& store, int idToSearch)
{
	int first = 0;
	int last = store.number - 1;
	while (first <= last)
	{
		int mid = (first + last) / 2;
		if (store.list[mid].id == idToSearch)
		{
			return mid;
		}
		else
		{
			if (idToSearch < store.list[mid].id)
			{
				last = mid - 1;
			}
			else
				first = mid + 1;
		}
	}
	return -1;
}
/*	precondition:  store.list is sorted by the id field.  store.number stores how many items are in the array.
	data is stored in the array list from positions 0..store.number-1.

	postcondition:  if idToSearch exists in the array, the function returns the index position of the item, otherwise it returns -1.  */

int bsearch(const storeType& store, int idToSearch, int first, int last)
{
	if (last < first)
	{
		return -1;
	}
	else
	{
		int mid = (first + last) / 2;
		if (store.list[mid].id == idToSearch)
		{
			return mid;
		}
		else
		{
			if (store.list[mid].id > idToSearch)
			{
				return bsearch(store, idToSearch, first, mid - 1);
			}
			else
			{
				return bsearch(store, idToSearch, mid + 1, last);
			}
		}
	}

}

//	recursive version, searches range from first to last of the array

void testSearch(const storeType& store)
{
	int idToFind, invReturn, index;

	cout << "Testing search algorithm" << endl << endl;
	cout << "Enter Id value to search for (-1 to quit) ---> ";
	cin >> idToFind;
	while (idToFind >= 0)
	{
		index = bsearch(store, idToFind);
		//	index = bsearch (store, idToFind, 0, store.number-1);    recursive version call
		cout << "Id # " << idToFind;
		if (-1 == index)
			cout << "     No such part in stock" << endl;
		else
			cout << "     Inventory = " << store.list[index].inv << endl;
		cout << endl << "Enter Id value to search for (-1 to quit) ---> ";
		cin >> idToFind;
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

	testSearch(store);
}
