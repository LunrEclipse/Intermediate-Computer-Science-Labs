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

void main()
{
	stack<int> stack;
	queue<char> queue;
	char input;
	int cur = 0;

	do
	{
		cout << "Current: " << cur << ", input: ";
		cin >> input;
		queue.push(input);
		if ((input == '+') || (input  == '-') || (input == '*') || (input  == '/'))
		{
			int num1 = 0;
			int num2 = 0;
			if (!stack.empty())
			{
				num2 = stack.top();
				stack.pop();
			}
			if (!stack.empty())
			{
				num1 = stack.top();
				stack.pop();
			}
			
			if (input == '+')
				cur = num1 + num2;
			else if (input == '-')
				cur = num1 - num2;
			else if (input == '*')
				cur = num1 * num2;
			else
				cur = num1 / num2;
			stack.push(cur);
		}
		else if ((input >= '0') && (input <= '9'))
		{
			cur = input - 48;
			stack.push(cur);
		}
	} while ((input != 'Q') && (input != 'q'));
	cout << endl;


	while (!(queue.empty()))
	{
		char c = queue.front();
		queue.pop();
		if ((c != 'q') && (c != 'Q'))
			cout << c << " ";
	}

	cout << "= " << cur << endl;

}