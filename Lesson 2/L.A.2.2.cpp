//L.A.2.2 Math
//Brendan Wong

#include<iostream>  
#include <limits.h>
#include <float.h>


using namespace std;

int main()
{
	cout << "4 + 9 = " << 4 + 9 << endl;
	cout << "46 / 7 = " << 46/7 << endl;
	cout << "46 % 7 = " << 46%7 << endl;
	cout << "2 * 3.0 = " << 2*3.0 << endl;
	cout << "float (25) / 4 = " << float(25) / 4 << endl;
	cout << "int (7.75) + 2 = " << int(7.75) + 2 << endl;
	cout << "int ('P') = " << int('P') << endl;
	cout << "char (105) = " << char(105) << endl;

	cout << "The largest 2-byte integer = " << INT_MAX << endl;
	cout << "The smallest 2-byte integer = " << INT_MIN << endl;
	cout << "The largest unsigned 2-byte integer = " << UINT_MAX << endl;
	cout << "The largest 4-byte integer = " << LONG_MAX << endl;
	cout << "The smallest 4-byte integer = " << LONG_MIN << endl;
	cout << "The largest unsigned 4-byte integer = " << ULONG_MAX << endl;

	cout << "Largest 4-byte float = " << FLT_MAX << endl;
	cout << "Smallest 4-byte float = " << FLT_MIN << endl;
	cout << "Largest 8-byte float = " << DBL_MAX << endl;
	cout << "Smallest 8-byte float = " << DBL_MIN << endl;

	return 0;

}