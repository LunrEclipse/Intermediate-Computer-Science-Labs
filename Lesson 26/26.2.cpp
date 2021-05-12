// sorting template program

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"
#include <string>
#include <cstring>
using namespace std;

struct uniqueWord
{
	string word;
	int  count;  
};

struct listOfWords
{
	uniqueWord list[1000];
	int size;
};

void swap(uniqueWord&, uniqueWord&);
bool isWord(char);



void main()
{
	ifstream inFile("DREAM.TXT");
	listOfWords data;

	data.size = 0;

	string currentWord;
	char start;
	char cur;

	if (inFile.get(start))
	{
		if (isWord(start))
			currentWord += start;
		while (inFile.get(cur))
		{
			if ('-' == cur)
			{
				if (currentWord != "")
					currentWord = currentWord + cur;
			}
			else if (isWord(cur))
			{
				currentWord = currentWord + cur;
			}
			else if (isWord(start) && !(isWord(cur)))
			{

				for (int i = 0; i < currentWord.length(); i++)
					if (('A' <= currentWord[i]) && (currentWord[i] <= 'Z'))
						currentWord[i] += 32;

				int index = -1;

				for (int i = 0; i < data.size; i++)
				{
					if (data.list[1].word == currentWord)
						index = i;
				}
				if (-1 == index)		// nextWord is a new word in list
				{
					data.size++;
					data.list[data.size - 1].word = currentWord;
					data.list[data.size - 1].count = 1;
					index = data.size - 1;
				}
				else
				{
					data.list[index].count++;
				}

				// cout << word << endl;
				currentWord = "";
			}
			start = cur;
		}
	}


	for (int outer = 1; outer <= data.size - 1; outer++)
	{

		for (int inner = 1; inner <= data.size - outer; inner++)
		{
			if (data.list[inner].count > data.list[inner + 1].count)
			{
				swap(data.list[inner], data.list[inner + 1]);
			}
		}
	}


	int line = 1;
	int num = 0;

	cout << setiosflags(ios::right);
	for (int i = 0; i < data.size; i++)
	{
		num += data.list[i].count;
		cout << setw(3) << line << setw(6) << data.list[i].count;
		cout << "   " << data.list[i].word << endl;
		if (line % 5 == 0) cout << endl;
		line++;
	}
	cout << "Number of words used = " << data.size << endl;
	cout << "Total # of words = " << num << endl;
}


bool isWord(char c1)
{
	if (('A' <= c1) && (c1 <= 'Z'))
		return true;
	else if (('a' <= c1) && (c1 <= 'z'))
		return true;
	else if ('\'' == c1)
		return true;
	else
		return false;
}

void swap(uniqueWord& one, uniqueWord& two)
{
	uniqueWord temp = one;
	one = two;
	two = temp;
}