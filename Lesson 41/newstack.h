#pragma once

#ifndef _newstack_h
#define _newstack_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"
#include <string>
#include <cstring>

template <class itemType>
class apstack
{
public:
	apstack();
	apstack(const apstack& stack);
	~apstack();

	const apstack& operator= (const apstack& stack);

	const itemType& top()	const;
	bool isEmpty() const;
	int  length() const;

	void push(const itemType& item);
	void pop();
	void pop(itemType& item);
	void makeEmpty();

private:
	struct stackNode
	{
		itemType  myItem;
		stackNode* nextItem;

		stackNode(itemType MyItem, stackNode* Next)
			: myItem(MyItem), nextItem(Next)
		{
		}
	};
	typedef stackNode* stackPtr;

	stackPtr myStack;
};

template<class itemType>
apstack<itemType>::apstack()
{
	myStack = NULL;
}

template<class itemType>
apstack<itemType>::apstack(const apstack& stack)
{
	*this = stack;
}

template<class itemType>
apstack<itemType>::~apstack()
{
	makeEmpty();
}

template<class itemType>
const apstack<itemType>&
apstack<itemType>::operator= (const apstack<itemType>& stack)
{
	stackPtr temp;
	stackPtr end;

	makeEmpty();
	temp = stack.myStack;
	myStack = new StackNode(temp->myItem, NULL);
	end = myStack;
	temp = temp->next;
	while (temp != NULL)
	{
		end->next = new stackNode(temp->myItem, NULL);
		end = end->next;
		temp = temp->next;
	}
	return *this;
}

template<class itemType>
const itemType&
apstack<itemType>::top() const
{
	if (isEmpty())
	{
		cerr << "Stack is Empty";
	}
	return myStack->myItem;
}

template<class itemType>
bool
apstack<itemType>::isEmpty() const
{
	if (myStack == NULL)
		return true;
	else
		return false;
}

template<class itemType>
int
apstack<itemType>::length() const
{
	int count = 0;
	stackNode* temp = myStack;

	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

template<class itemType>
void
apstack<itemType>::push(const itemType& item)
{
	myStack = new stackNode(item, myStack);
}

template<class itemType>
void
apstack<itemType>::pop()
{
	if (isEmpty())
	{
		cerr << "Stack is Empty";
	}
	else
	{
		stackNode* temp = myStack;
		myStack = myStack->next;
	}
}

template <class itemType>
void
apstack<itemType>::pop(itemType& item)
{
	if (isEmpty())
	{
		cerr << "Stack is Empty";
	}
	else
	{
		stackNode* temp = myStack;
		item = myStack->myItem;
		myStack = myStack->next;
	}
}

template <class itemType>
void
apstack<itemType>::makeEmpty()
{
	stackPtr temp = myStack;
	myStack = NULL;
}

#endif
