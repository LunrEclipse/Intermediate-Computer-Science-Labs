// sorting template program

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"
#include <string>
#include <cstring>

using namespace std;


void testConstructors()
{
	string word1;
	string word2("Hello world\0");
	string word3("Hello world\n");

	cout << "Testing constructors" << endl << endl;
	cout << word1;
	cout << word2;
	cout << word3;
}

void testAssignment()
{
	string test1("Hello world\n");
	string test2 = test1;
	string test3 = "C-String\n";
	string test4 = "t";

	cout << endl << "Testing Assignment" << endl << endl;
	cout << "Test 2 = " << test2 << "Test 3 = " << test3 << "Test 4 = " << test4 << endl;

}

void testAccessors()
{
	string test1 = "Candy4Andy";
	cout << endl << "Testing Assignment" << endl << endl;
	cout << "Length of " << test1 << ": " << test1.length() << endl;
	cout << "First Location of 4Andy: " << test1.find("4Andy") << endl;
	cout << "First instance of a: " << test1.find('a') << endl;
	cout << test1.substr(0, 5) << endl;
	//cstring temp = test1.c_str();
	//puts(temp);
}

void testIndexing()
{
	cout << endl << "Testing Indexing" << endl << endl;
	string word1 = "Candy4Andy";
	int  len = word1.length();
	for (int k = 0; k < len; k++)
		cout << word1[k];
	for (int k = 0; k < len; k++)
		if (('a' <= word1[k]) && (word1[k] <= 'z'))
			word1[k] -= 32;
	cout << endl << word1;
}

void testModifiers()
{
	cout << endl << endl << "Testing Modifiers" << endl << endl;
	string word1 = "God ";
	string word2 = "Parker";
	word1 += word2;
	word1 += ", Jason";
	cout << word1;
}

void testgetline()
{
	cout << endl << endl << "Testing Getline" << endl << endl;
	string word1;
	cout << "Enter a string with spaces: ";
	getline(cin, word1);
	cout << "word1: " << word1 << endl;

}

void testComparisons()
{
	cout << endl << endl << "Testing Comparisons" << endl << endl;
	string word1 = "Parker, Jason";
	string word2 = "Smith, Joe";
	string word3 = "Parker, Jason";
	if(word1 < word2)
		cout << word1 << " < " << word2 << endl;
	if (!(word1 > word2))
		cout << word1 << " !> " << word2 << endl;
	if (word1 == word3)
		cout << word1 << " = " << word3 << endl;

}

void testConcat()
{
	cout << endl << endl << "Testing Concat" << endl << endl;
	string word1 = "Patel, ";
	cout << word1 << endl;
	word1 += 'A';
	word1 += 'a';
	word1 += 'r';
	word1 += 'a';
	word1 += 'v';
	cout << word1 << endl;
}

void testSort()
{
	cout << endl << endl << "Testing Sort" << endl << endl;
	string list[3] = { "hello world", "hello", "programming is fun" };
	int flag;
	for (int outer = 0; outer < 2; outer++)
	{
		flag = outer;
		for (int inner = outer + 1; inner <= 2; inner++)
		{
			if (list[inner] < list[flag])
			{
				flag = inner;
			}
		}
		string temp = list[outer];
		list[outer] = list[flag];
		list[flag] = temp;
	}
	cout << list[0] << ", " << list[1] << ", " << list[2] << endl;
}

void testExtract()
{
	cout << endl << endl << "Testing Extract" << endl << endl;
	string word1;
	cout << "Enter a string with spaces: ";
	getline(cin, word1);
	int space = word1.find(" ");
	string first = word1.substr(0, space);
	cout << first;
}


void main()
{
		testConstructors();
		testAssignment();
		testAccessors();
		testIndexing();
		testModifiers();
		testgetline();
		testComparisons();
		testConcat();
		testSort();
		testExtract();
}


