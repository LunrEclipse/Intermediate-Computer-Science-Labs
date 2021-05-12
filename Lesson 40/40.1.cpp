//  ordShell.cpp
//  A program shell for the ordered linked list lab, Lesson 33

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"
#include <string>
#include <cstring>
#include<stack>
using namespace std;

const string SOURCE = "file20.txt";

struct treeNode
{
	int id;
	int inv;
	treeNode* left;
	treeNode* right;

	treeNode(int, int, treeNode*, treeNode*);
};

treeNode::treeNode(int tempId, int tempInv, treeNode* tempLeft, treeNode* tempRight)
	:id(tempId), inv(tempInv), left(tempLeft), right(tempRight)
{
	
}

typedef treeNode* treePtr;

void insert(treePtr&, int, int);
void inorder(treePtr);
void readData(treePtr&);
void mainMenu(treePtr&);


void main()
{
	treePtr root;

	root = NULL;
	readData(root);
	cout << setiosflags(ios::right);
	cout << setw(10) << "Id" << setw(10) << "Inv" << endl << endl;
	inorder(root);
	return 0;
}


void insert(treePtr& root, int id, int inv)
{
	if (root == NULL)
	{
		root = new treeNode(id, inv, NULL, NULL);
	}
	else if (root->id >id)
	{
		insert(root->left, id, inv);
	}
	else
	{
		insert(root->right, id, inv);
	}
}

void inorder(treePtr root)
{
	stack<treePtr> stack;
	treePtr temp = root;
	do
	{
		while (temp != NULL)
		{
			stack.push(temp);
			temp = temp->left;
		}
		if (!(stack.empty()))
		{
			temp = stack.top();
			stack.pop();
			cout << setw(10) << temp->id << setw(10) << temp->inv << endl;
			temp = temp->right;
		}
	} while ((temp != NULL) || (!(stack.empty())));
}



void readData(treePtr& temp)
{
	ifstream inFile;
	inFile.open("file20.txt");
	int num;
	inFile >> num;
	for (int i = 0; i < num; i++)
	{
		int id;
		int inv;
		inFile >> id >> inv;
		insert(temp, id, inv);
	}
}



