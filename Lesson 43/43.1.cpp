//  ordShell.cpp
//  A program shell for the ordered linked list lab, Lesson 33

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;


struct listNode
{
	int myId;
	int myInv;
	listNode* next;

	listNode(int, int, listNode*);
};

listNode::listNode(int tempId, int tempInv, listNode* tempNext)
	: myId(tempId), myInv(tempInv), next(tempNext)
{
}

typedef listNode* listPtr;
typedef vector<listPtr> hashTable;

int hashKey(long);
void insert(hashTable&, int, int);
void loadFile(hashTable&, int&);
int hashSearch(const hashTable&, int);
void testSearch(const hashTable&);
int numberOfNulls(const hashTable&);
int longestList(const hashTable&);
void stats(const hashTable&, int);

void main()
{
	hashTable table(600, NULL);

	ifstream inFile;
	int number = 0;

	inFile.open("file400.txt");
	inFile >> number;
	for (int i = 0; i < number; i++)
	{
		int id;
		int inv;
		inFile >> id >> inv;
		int location = hashKey(id);
		table[location] = new listNode(id, inv, table[location]);
	}

	testSearch(table);
	stats(table, number);

}

int hashKey(long keyId)
{
	long hash = keyId;
	for (int i = 0; i < keyId; i++)
	{
		hash = hash * 9 + 3987;
	}
	if (hash < 0)
		hash = hash * -1;
	long reverse = 0;
	while (hash != 0)
	{
		reverse += hash % 10;
		hash = hash / 10;
	}
	reverse += keyId;
	return (int)(reverse % 599);
}


int hashSearch(const hashTable& table, int idToFind)
{
	int location = hashKey(idToFind);
	listPtr cur = table[location];
	if (cur != NULL)
	{
		while (cur != NULL)
		{
			if (cur->myId == idToFind)
				return cur->myInv;
			cur = cur->next;
		}
	}
	return -1;
}

void testSearch(const hashTable& table)
{
	int idToFind, invReturned;

	cout << "Testing search algorithm" << endl << endl;
	cout << "Enter Id value to search for (-1 to quit) ---> ";
	cin >> idToFind;
	while (idToFind >= 0)
	{
		invReturned = hashSearch(table, idToFind);
		cout << "Id # " << idToFind;
		if (-1 == invReturned)
			cout << "     No such part in stock" << endl;
		else
			cout << "     Inventory = " << invReturned << endl;
		cout << endl << "Enter Id value to search for (-1 to quit) ---> ";
		cin >> idToFind;
	}
}

int numberOfNulls(const hashTable& table)
{
	int count = 0;

	for (int i = 0; i < 600; i++)
		if (table[i] == NULL)
			count++;
	return count;
}

int longestList(const hashTable& table)
{
	int longest = 0;

	for (int i = 0; i < 600; i++)
	{
		int length = 0;
		listPtr cur = table[i];
		while (cur != NULL)
		{
			cur = cur->next;
			length++;
		}
		if (length > longest)
			longest = length;
	}
	return longest;
}

void stats(const hashTable& table, int number)
{
	int emptySpots;
	double avgListLen;


	cout << setprecision(2) << setiosflags(ios::fixed);
	emptySpots = numberOfNulls(table);
	cout << "Number of NULLs = " << emptySpots << endl;
	cout << "% of NULL pointers = " << double(emptySpots) * 100 / 600 << " %" << endl;
	avgListLen = double(number) / (600 - emptySpots);
	cout << "Average list length = " << avgListLen << endl;
	cout << "The longest list = " << longestList(table) << endl;
}
