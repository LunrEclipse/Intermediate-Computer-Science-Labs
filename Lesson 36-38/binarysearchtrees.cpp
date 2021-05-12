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

struct treeNode
{
	int id;
	int inv;
	treeNode* left;
	treeNode* right;

	treeNode(int, int, treeNode*, treeNode*);
};

treeNode::treeNode(int tempId, int tempInv, treeNode* tempLeft, treeNode* tempRight)
	: id(tempId), inv(tempInv), left(tempLeft), right(tempRight)
{
	
}

typedef treeNode* treePtr;

void insert(treePtr& temp, int id, int inv);
treePtr search(treePtr, int);
void testSearch(treePtr);
void testDelete(treePtr&);
void inorder(treePtr);
int countNodes(treePtr);
void modifyTree(treePtr&);
bool deleteNode(treePtr&, int);
void readData(treePtr&);
void mainMenu(treePtr&);


void main()
{
	treePtr root;
	root = NULL;
	mainMenu(root);
	return 0;
}

void insert(treePtr& tree, int id, int inv)
{
	if (tree == NULL)
	{
		tree = new treeNode(id, inv, NULL, NULL);
	}
	else
	{
		if (tree->id > id)
		{
			insert(tree->left, id, inv);
		}
		else
		{
			insert(tree->right, id, inv);
		}
	}
}

treePtr search(treePtr tree, int toFind)
{
	if (tree == NULL)
		return NULL;
	if (toFind == tree->id)
	{
		return tree;
	}
	else
	{
		if (tree->id > toFind)
		{
			return search(tree->left, toFind);
		}
		else
		{
			return search(tree->right, toFind);
		}
	}
}

void testSearch(treePtr tree)
{
	int toFind;
	treePtr spot;

	cout << "Testing search algorithm" << endl << endl;
	cout << "Enter Id value to search for (-1 to quit) ---> ";
	cin >> toFind;
	while (toFind >= 0)
	{
		spot = search(tree, toFind);
		cout << "Id # " << toFind;
		if (NULL == spot)
			cout << "     No such part in stock" << endl;
		else
			cout << "     Inventory = " << spot->inv << endl;
		cout << endl << "Enter Id value to search for (-1 to quit) ---> ";
		cin >> toFind;
	}
}

void testDelete(treePtr& tree)
{
	int toDelete;
	bool success;

	cout << "Testing delete algorithm" << endl << endl;
	cout << "Enter Id value to delete (-1 to quit) ---> ";
	cin >> toDelete;
	while (toDelete >= 0)
	{
		success = deleteNode(tree, toDelete);
		cout << "Id # " << toDelete;
		if (!success)
			cout << "     No such part in stock" << endl;
		else
			cout << "     Id #" << toDelete << " was deleted" << endl;
		cout << endl << "Enter Id value to delete (-1 to quit) ---> ";
		cin >> toDelete;
	}
}

void inorder(treePtr tree)
{
	if (tree != NULL)
	{
		inorder(tree->left);
		cout << setw(10) << tree->id << setw(10) << tree->inv << endl;
		inorder(tree->right);
	}
}

int countNodes(treePtr tree)
{
	if (NULL == tree)
	{
		return 0;
	}
	else
	{
		return  countNodes(tree->left) + countNodes(tree->right) + 1;
	}
}

void readData(treePtr& tree)
{
	ifstream inFile;
	int howMany, k, id, inv;

	inFile.open("file10.txt");
	inFile >> howMany;
	for (k = 1; k <= howMany; k++)
	{
		inFile >> id >> inv;
		insert(tree, id, inv);
	}
}

void modifyTree(treePtr& target)
{
	if ((target->right == NULL) && (target->left == NULL))
	{
		target = NULL;
	}
	else if (target->right == NULL)
	{
		target = target->left;
	}
	else if (target->left == NULL)
	{
		target = target->right;
	}
	else if (target->right->left == NULL)
	{
		target->id = target->right->id;
		target->inv = target->right->inv;
		target->right = target->right->right;
	}
	else
	{
		treePtr marker = target->right;
		while (marker->left->left != NULL)
		{
			marker = marker->left;
		}
		target->id = marker -> left->id;
		target->inv = marker->left->inv;
		marker->left = marker->left->right;

	}
}

bool deleteNode(treePtr& tree, int toDelete)
{
	if (tree == NULL)
	{
		return false;
	}
	else if (tree->id > toDelete)
	{
		return deleteNode(tree->left, toDelete);
	}
	else if (tree->id < toDelete)
	{
		return deleteNode(tree->right, toDelete);
	}
	else
	{
			modifyTree(tree);
			return true;
	}
}

void mainMenu(treePtr& root)
{
	char choice;

	cout << setiosflags(ios::right);
	do
	{
		cout << "Binary tree menu" << endl << endl;
		cout << "(1) Read " << "file10.txt" << " from disk" << endl;
		cout << "(2) Print tree inorder" << endl;
		cout << "(3) Search tree" << endl;
		cout << "(4) Delete from tree" << endl;
		cout << "(5) Count nodes in tree" << endl;
		cout << "(6) Quit" << endl << endl;
		cout << "Choice ---> ";
		cin >> choice;
		cin.get();	
		cout << endl;
		if ('1' <= choice && choice <= '5')
		{
			switch (choice)
			{
			case '1': readData(root); break;
			case '2':
				cout << endl << "The tree printed inorder" << endl << endl;
				cout << setw(10) << "Id" << setw(10) << "Inv" << endl;
				inorder(root);
				cout << endl;
				break;
			case '3': testSearch(root); break;
			case '4': testDelete(root); break;
			case '5':
				cout << "Number of nodes = " << countNodes(root) << endl << endl;
				break;
			}
		}
	} while (choice != '6');
}
