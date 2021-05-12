//  ordShell.cpp
//  A program shell for the ordered linked list lab, Lesson 33

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"
#include <string>
#include <cstring>
#include <queue>
using namespace std;

const string SOURCE = "file20.txt";

struct treeNode
{
	char letter;
	treeNode* left;
	treeNode* right;

	treeNode(char, treeNode*, treeNode*);
};

treeNode::treeNode(char tempLetter, treeNode* tempLeft, treeNode* tempRight)
	:letter(tempLetter), left(tempLeft), right(tempRight)
{

}

typedef treeNode* treePtr;

void printByLevel(treePtr);
void insert(treePtr&, char);
void readData(treePtr&);
void mainMenu(treePtr&);


void main()
{
	treePtr root;

	root = NULL;
	readData(root);
	cout << "The tree printed by level: ";
	printByLevel(root);
}


void insert(treePtr& root, char c)
{
	if (root == NULL)
	{
		root = new treeNode(c, NULL, NULL);
	}
	else if (root->letter > c)
	{
		insert(root->left, c);
	}
	else
	{
		insert(root->right, c);
	}
}


void readData(treePtr& temp)
{
	ifstream inFile;
	char c;

	inFile.open("fileA.txt");
	while (inFile >> c)
		insert(temp, c);
}



void printByLevel(treePtr root)
{
	queue<treePtr> q;
	treePtr temp;

	if (root != NULL)
	{
		q.push(root);
		while (!q.empty())
		{
			temp = q.front();
			q.pop();
			cout << temp->letter << " ";
			if (temp->left != NULL)
				q.push(temp->left);
			if (temp->right != NULL)
				q.push(temp->right);
		}
	}
}
