//L.A.13 Fibonacci
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>

int  recFib(int);
int  iterFib(int);
int  mult(int, int);

using namespace std;

int main()
{
	cout << "Recursive Fibonacci:" << endl << endl;
	cout << "Fib(0) = " << recFib(0) << endl;
	cout << "Fib(3) = " << recFib(3) << endl;
	cout << "Fib(11) = " << recFib(11) << endl << endl;

	cout << "Iterative Fibonacci:" << endl << endl;
	cout << "Fib(1) = " << iterFib(1) << endl;
	cout << "Fib(5) = " << iterFib(5) << endl;
	cout << "Fib(14) = " << iterFib(14) << endl << endl;

	cout << "Recursive Multiplication:" << endl << endl;
	cout << "Mult(0,4) = " << mult(0, 4) << endl;
	cout << "Mult(3,1) = " << mult(3, 1) << endl;
	cout << "Mult(7,8) = " << mult(7, 8) << endl;
	cout << "Mult(5,0) = " << mult(5, 0) << endl;
	return 0;

}

int iterFib(int n)
{
	int old = 0;
	int cur = 1;

	if (n == 0)
		return n;
	if (n == 1)
		return n;

	for (int i = 2; i < n; i++)
	{
		int temp = old + cur;
		old = cur;
		cur = temp;
	}

	return cur;
}

int recFib(int n)
{
	if (n == 0)
		return n;
	if (n == 1)
		return n;
	if (n == 3)
		return 1;
	return recFib(n - 1) + recFib(n - 2);
}

int mult(int a, int b)
{
	if (a == 0)
		return 0;
	if (b == 0)
		return 0;
	return a + mult(a, b - 1);
}