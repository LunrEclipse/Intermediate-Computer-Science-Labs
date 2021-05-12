//L.A.16.1 Statistics
//Brendan Wong

#include <iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <vector>

double average(vector<int>, int);
double standardDeviation(vector<int>, int);
int mode(vector<int>, int);

using namespace std;

int main()
{
	vector<int> nums(1000);
	int size = 0;
	int temp; 
	ifstream file("statistics.txt");

	while (file >> temp)
	{
		nums[size] = temp;
		size++;
	}
	cout << setprecision(2) << setiosflags(ios::fixed);
	cout << "Average: " << average(nums, size) << endl;
	cout << "Standard Deviation: " << standardDeviation(nums, size) << endl;
	cout << "Mode: " << mode(nums, size) << endl;


}

double average(vector<int> array, int size)
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		total += array[i];
	}
	return (double)(total) / size;
}

double standardDeviation(vector<int> array, int size)
{
	double avg = average(array, size);
	double total;
	for (int i = 0; i < size; i++)
	{
		total += pow(array[i] - avg,2);
	}
	return sqrt(total / (size - 1));
}

int mode(vector<int> array, int size)
{
	vector<int> count(101);
	for (int i = 0; i < size; i++)
	{
		count[array[i]]++;
	}

	int largest = 0;
	int temp = 0;
	for (int i = 0; i < 101; i++)
	{
		if (count[i] > temp)
		{
			largest = i;
			temp = count[i];
		}
	}

	return largest;
}