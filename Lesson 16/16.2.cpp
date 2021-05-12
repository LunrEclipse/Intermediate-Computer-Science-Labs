//L.A.16.1 Compact
//Brendan Wong

#include <iostream>  
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;

void compact(vector<int>&, int&);

int main()
{
	vector<int> nums(100);
	int size = 0;
	int temp;
	ifstream file("compact.txt");

	while (file >> temp)
	{
		nums[size] = temp;
		size++;
	}

	cout << "Before: ";
	for (int i = 0; i < size; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;

	compact(nums, size);

	cout << "After: ";
	for (int i = 0; i < size; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;



}

void compact(vector<int>& list, int& size)
{
	for (int i = 0; i < size; i++)
	{
		if (list[i] == 0)
		{
			int j = i + 1;
			int found = false;
			while (j < size && !found)
			{
				if (list[j] != 0)
					found = true;
				j++;
			}
			if (found)
			{
				list[i] = list[j - 1];
				list[j - 1] = 0;
			}
			else
			{
				size = i;
				break;
			}
		}
	}
}
