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

void insert(treePtr&, char);
void inorder(treePtr);
void preorder(treePtr);
void postorder(treePtr);
int countNodes(treePtr);
int countLeaves(treePtr);
int height(treePtr);
int width(treePtr);
void clearTree(treePtr&);
void readData(treePtr&);
void mainMenu(treePtr&);
int max(int, int);


void main()
{
	treePtr root;

	root = NULL;
	mainMenu(root);
	return 0;
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

void inorder(treePtr root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->letter;
		inorder(root->right);
	}

}

void preorder(treePtr root)
{
	if (root != NULL)
	{
		cout << root->letter;
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(treePtr root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->letter;
	}
}

int countNodes(treePtr root)
{
	if (root != NULL)
	{
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
	return 0;
}

int countLeaves(treePtr root)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
			return 1;
		else
			return countLeaves(root->right) + countLeaves(root->left);
	}
	return 0;
}

int height(treePtr root)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
		{
			return 1;
		}
		else if (root->left == NULL)
		{
			return 1 + height(root->right);
		}
		else if (root->right == NULL)
		{
			return 1 + height(root->left);
		}
		else
		{
			return max(height(root->left) + 1, height(root->right) + 1);
		}
	}
}

int width(treePtr root)
{
	if (root != NULL)
	{
		int leftWidth = width(root->left);
		int rightWidth = width(root->right);
		int heigth = height(root->right) + height(root->left) + 1;
		if (leftWidth >= rightWidth && leftWidth >= heigth)
			return leftWidth;
		else if (rightWidth >= leftWidth && rightWidth >= heigth)
			return rightWidth;
		else
			return heigth;
	}
}

void clearTree(treePtr& p)
{
	p == NULL;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void readData(treePtr& temp)
{
	ifstream inFile;
	char c;

	inFile.open("fileA.txt");
	while (inFile >> c)
		insert(temp, c);
}

void mainMenu(treePtr& root)
{
	char choice;

	cout << setiosflags(ios::right);
	do
	{
		cout << "Binary tree menu" << endl << endl;
		cout << "(1) Read " << "fileA.txt" << " from disk" << endl;
		cout << "(2) Print tree preorder" << endl;
		cout << "(3) Print tree inorder" << endl;
		cout << "(4) Print tree postorder" << endl;
		cout << "(5) Count nodes in the tree" << endl;
		cout << "(6) Count the leaves in the tree" << endl;
		cout << "(7) Height of tree" << endl;
		cout << "(8) Width of tree" << endl;
		cout << "(9) Clear tree" << endl;
		cout << "(Q/q) Quit" << endl << endl;
		cout << "Choice ---> ";
		cin >> choice;
		cin.get();	// to dump return key
		cout << endl;
		if ('1' <= choice && choice <= '9')
		{
			switch (choice)
			{
			case '1': readData(root); break;
			case '2':
				cout << endl << "The tree printed preorder" << endl << endl;
				preorder(root);
				cout << endl;
				break;
			case '3':
				cout << endl << "The tree printed inorder" << endl << endl;
				inorder(root);
				cout << endl;
				break;
			case '4':
				cout << endl << "The tree printed postorder" << endl << endl;
				postorder(root);
				cout << endl;
				break;
			case '5':
				cout << endl << "Number of nodes in tree = ";
				cout << countNodes(root) << endl << endl;
				break;
			case '6':
				cout << endl << "Number of leaves in tree = ";
				cout << countLeaves(root) << endl << endl;
				break;
			case '7':
				cout << endl << "Height of tree = ";
				cout << height(root) << endl << endl;
				break;
			case '8':
				cout << endl << "Width of tree = ";
				cout << width(root) << endl << endl;
				break;
			case '9': clearTree(root); break;
			}
		}
	} while ((choice != 'Q') && (choice != 'q'));
}


