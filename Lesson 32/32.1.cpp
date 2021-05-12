

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"
#include <string>
#include <cstring>
using namespace std;

struct listNode
{
	int data;
	listNode *next;

	listNode(int, listNode*);
};

listNode::listNode(int tempData, listNode* tempNode) :data(tempData), next(tempNode)
{

}

typedef listNode* nodePtr;

struct listType
{
	nodePtr first;
	nodePtr last;
};

void createList(listType&);
void printList(listType);

void main()
{
	listType list;

	list.first = list.last = NULL;
	for (int i = 0; i < 20; i++)
	{
		if (NULL == list.first)
		{
			list.first = list.last = new listNode(i, list.first);
		}
		else
		{
			list.last->next = new listNode(i, NULL);
			list.last = list.last->next;
		}
	}

	nodePtr temp = list.first;
	cout << setiosflags(ios::right);
	while (temp != NULL)
	{
		cout << setw(4) << temp->data;
		temp = temp->next;
	}
}
