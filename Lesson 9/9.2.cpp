//L.A.9.2 Fun Loops
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>


using namespace std;

void magicsquare(int num);
long reverse(long num);
int lcm(int a, int b);




int main()
{

	cout << "Magic squares: " << endl;
	magicsquare(6);
	cout << endl << endl;

	cout << "Reverse: " << endl;
	cout << "12345 reversed: " << reverse(12345) << endl;
	cout << "10001 reversed: " << reverse(10001) << endl;
	cout << "1200 reversed: " << reverse(1200) << endl;
	cout << "5 reversed: " << reverse(5) << endl << endl;

	cout << "LCM: " << endl;
	cout << "LCM (15,18): " << lcm(15, 18) << endl;
	cout << "LCM (40,12): " << lcm(40, 12) << endl;
	cout << "LCM (2,7): " << lcm(2, 7) << endl;
	cout << "LCM (100,5): " << lcm(100, 5) << endl;
	return 0;




}

void magicsquare(int num)
{
	long squareCounter = 1;
	long count = 0;

	while (count < num)
	{
		long sum = 0;
		long increment = 1;
		long square = pow(squareCounter, 2);
		while (sum < square)
		{
			sum += increment;
			increment++;
		}
		if (sum == square)
		{
			cout << square << " ";
			count++;
		}
		squareCounter++;
	}

}

long reverse(long num)
{
	long reverse = 0;

	while (num != 0)
	{
		reverse *= 10;
		int temp = num % 10;
		reverse += temp;
		num /= 10;
	}

	return reverse;
}

int lcm(int a, int b)
{
	int count = 0;
	bool found = false;

	while (!found)
	{
		count++;
		if (count % a == 0 && count % b == 0)
		{
			found = true;
		}
	}
	return count;
}
