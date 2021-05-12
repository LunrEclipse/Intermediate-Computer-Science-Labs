//  ordShell.cpp
//  A program shell for the ordered linked list lab, Lesson 33

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"
#include <string>
#include <cstring>
using namespace std;

const string SOURCE = "file20.txt";

struct listNode
{
	int  id, inv;
	listNode* next;

	listNode(int tempId, int tempInv, listNode* nxt);
};

listNode::listNode(int tempId, int tempInv, listNode* nxt)
	: id(tempId), inv(tempInv), next(nxt)
{
	// all values initialized using initializer list
}

typedef listNode* nodePtr;

void split(nodePtr&, nodePtr&);
void merge(nodePtr&, nodePtr);
void mergeSort(nodePtr&);
void reverseList(nodePtr&);



void main()
{
	nodePtr list;

	ifstream inFile;
	int howMany, k, id, inv;

	inFile.open(SOURCE.c_str());
	if (inFile.fail())
	{
		cerr << "Could not open " << SOURCE << endl;
		abort();
	}
	inFile >> howMany;
	list = NULL;
	for (k = 1; k <= howMany; k++)
	{
		inFile >> id >> inv;
		list = new listNode(id, inv, list);
	}

	nodePtr temp;
	mergeSort(list);

	int line = 0;
	cout << setiosflags(ios::right);
	cout << setw(15) << "Id" << setw(10) << "Inv" << endl << endl;
	while (temp != NULL)
	{
		line++;
		cout << setw(5) << line << setw(10) << temp->id << setw(10) << temp->inv << endl;
		if (line % 10 == 0) cout << endl;
		temp = temp->next;
	}

	reverseList(list);

	int line = 0;
	cout << setiosflags(ios::right);
	cout << setw(15) << "Id" << setw(10) << "Inv" << endl << endl;
	while (temp != NULL)
	{
		line++;
		cout << setw(5) << line << setw(10) << temp->id << setw(10) << temp->inv << endl;
		if (line % 10 == 0) cout << endl;
		temp = temp->next;
	}


}

void split(nodePtr& first, nodePtr& second)
{
	int count = 0;
	nodePtr counter = first;
	while (count != NULL)
	{
		count++;
		counter = counter->next;
	}
	int middle = (count / 2) - 1;

	nodePtr temp = first;
	for (int i = 0; i < middle; i++)
	{
		temp = temp->next;
	}
	second = temp->next;
	temp->next = NULL;
}

void merge(nodePtr& first, nodePtr second)
{
	nodePtr tempFirst;
	nodePtr tempSecond;
	nodePtr final;
	if (second == NULL)
	{
		
	}
	else
	{
		if (first == NULL)
			first = second;
		else
		{
			tempFirst = first;
			tempSecond = second;

			if (tempFirst->id > tempSecond->id)
			{
				first = second;
				tempSecond = tempSecond->next;
			}
			else
			{
				tempFirst = tempFirst->next;
			}
			final = first;

			while ((NULL != tempFirst) || (NULL != tempSecond))
			{
				if (tempFirst == NULL)
				{
					final->next = tempSecond;
					tempSecond = tempSecond->next;
				}
				else if (tempSecond == NULL)
				{
					final->next = tempFirst;
					tempFirst = tempFirst->next;
				}
				else if (tempFirst->id < tempSecond->id)
				{
					final->next = tempFirst;
					tempFirst = tempFirst->next;
				}
				else
				{
					final->next = tempSecond;
					tempSecond = tempSecond->next;
				}
				final = final->next;
			}
			final->next = NULL;
		}
	}
}

void mergeSort(nodePtr& list)
{
	nodePtr temp;
	if (list != NULL && list->next != NULL)
	{
		split(list, temp);
		mergeSort(list);
		mergeSort(temp);
		merge(list, temp);
	}
}

void reverseList(nodePtr& list)
{
	nodePtr reverse;
	nodePtr temp = list;

	if (list != NULL)
	{
		reverse = temp;
		while (temp != NULL)
		{
			temp = temp->next;
			temp->next = reverse;
			reverse = temp; 
			
		}
	}
}


