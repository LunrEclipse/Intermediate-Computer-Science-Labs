//L.A.2.1 Practice
//Brendan Wong

#include<iostream>  

using namespace std;

int main()
{
	int num = 400;
	long int longNum = 1234567;
	unsigned int unsignedNum = 59;
	char letter = 'b';
	float floatNum = 57.9091;
	double doubleNum = 1239123.12390;
	long double longDoubleNum = 1.592e19;
	bool booleanTest = false;

	cout << "number = " << num << ", Size of an integer = " << sizeof(num) << endl;

	cout << "bignumber = " << longNum << ", Size of a long integer = " << sizeof(longNum) << endl;

	cout << "posnumber = " << unsignedNum << ", Size of an unsigned integer = "<< sizeof(unsignedNum) << endl;

	cout << "letter = " << letter << ", Size of a character = " << sizeof(letter) << endl;

	cout << "realnum = " << floatNum << ", Size of a float = " << sizeof(floatNum) << endl;

	cout << "doublereal = " << doubleNum << ", Size of a double float = "<< sizeof(doubleNum) << endl;

	cout << "bigreal = " << longDoubleNum << ", Size of a long double = "<< sizeof(longDoubleNum) << endl;

	cout << "done = " << booleanTest << ", Size of a bool = " << sizeof(booleanTest) << endl;

	cout << "Letter = " << letter << ", ASCII position = " << int(letter) << endl;

	letter = char(35);
	cout << "ASCII position = " << 35 << ", Letter = " << letter << endl;
	return 0;

}