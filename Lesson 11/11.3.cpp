//L.A.11 ACSLLAND
//Brendan Wong

#include<iostream>  
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	char choice;
	cout << "ACSLLand Problem" << endl;
	do
	{
		int a = 0;
		int b = 0;
		int c = 0;
		int count = 0;
		int value = 1;
		bool aForfeit = false;
		bool bForfeit = false;
		bool cForfeit = false;
		bool done = false;

		cout << "Enter Rolls (0 to end)" << endl << endl;
		while (!done && value > 0)
		{
			cout << "Roll: ";
			cin >> value;
			if (value > 0)
			{
				count++;
				if (count % 3 == 1)
				{
					if (!aForfeit)
					{
						if (value != 4 && value != 6)
						{
							a += value;
						}
						else if (value == 6)
						{
							aForfeit = true;
						}
						else
						{
							a -= value;
						}
						if (a < 0)
							a = 0;
						if (a >= 30)
						{
							a = 30;
							done = true;
						}
						if (a == b)
							b = 0;
						if (a == c)
							c = 0;
					}
					else
					{
						aForfeit = false;
						count++;
						if (!bForfeit)
						{
							if (value != 4 && value != 6)
							{
								b += value;
							}
							else if (value == 6)
							{
								bForfeit = true;
							}
							else
							{
								b -= value;
							}
							if (b < 0)
								b = 0;
							if (b >= 30)
							{
								b = 30;
								done = true;
							}
							if (b == a)
								a = 0;
							if (b == c)
								c = 0;
						}
						else
						{
							bForfeit = false;
							count++;
							if (!cForfeit)
							{
								if (value != 4 && value != 6)
								{
									c += value;
								}
								else if (value == 6)
								{
									cForfeit = true;
								}
								else
								{
									c -= value;
								}
								if (c < 0)
									c = 0;
								if (c >= 30)
								{
									c = 30;
									done = true;
								}
								if (c == a)
									a = 0;
								if (c == b)
									b = 0;
							}
							else
							{
								cForfeit = false;
							}
						}
					}
				}
				else if (count % 3 == 2)
				{
					if (!bForfeit)
					{
						if (value != 4 && value != 6)
						{
							b += value;
						}
						else if (value == 6)
						{
							bForfeit = true;
						}
						else
						{
							b -= value;
						}
						if (b < 0)
							b = 0;
						if (b>= 30)
						{
							b = 30;
							done = true;
						}
						if (b == a)
							a = 0;
						if (b == c)
							c = 0;
					}
					else
					{
						bForfeit = false;
						count++;
						if (!cForfeit)
						{
							if (value != 4 && value != 6)
							{
								c += value;
							}
							else if (value == 6)
							{
								cForfeit = true;
							}
							else
							{
								c -= value;
							}
							if (c < 0)
								c = 0;
							if (c >= 30)
							{
								c = 30;
								done = true;
							}
							if (c == a)
								a = 0;
							if (c == b)
								b = 0;
						}
						else
						{
							cForfeit = false;
							count++;
							if (!aForfeit)
							{
								if (value != 4 && value != 6)
								{
									a += value;
								}
								else if (value == 6)
								{
									aForfeit = true;
								}
								else
								{
									a -= value;
								}
								if (a < 0)
									a = 0;
								if (a >= 30)
								{
									a = 30;
									done = true;
								}
								if (a == b)
									b = 0;
								if (a == c)
									c = 0;
							}
							else
							{
								aForfeit = false;
							}
						}
					}
				}
				else
				{
					if (!cForfeit)
					{
						if (value != 4 && value != 6)
						{
							c += value;
						}
						else if (value == 6)
						{
							cForfeit = true;
						}
						else
						{
							c -= value;
						}
						if (c < 0)
							c = 0;
						if (c >= 30)
						{
							c = 30;
							done = true;
						}
						if (c == a)
							a = 0;
						if (c == b)
							b = 0;
					}
					else
					{
						cForfeit = false;
						count++;
						if (!aForfeit)
						{
							if (value != 4 && value != 6)
							{
								a += value;
							}
							else if (value == 6)
							{
								aForfeit = true;
							}
							else
							{
								a -= value;
							}
							if (a < 0)
								a = 0;
							if (a >= 30)
							{
								a = 30;
								done = true;
							}
							if (a == b)
								b = 0;
							if (a == c)
								c = 0;
						}
						else
						{
							aForfeit = false;
							count++;
							if (!bForfeit)
							{
								if (value != 4 && value != 6)
								{
									b += value;
								}
								else if (value == 6)
								{
									bForfeit = true;
								}
								else
								{
									b -= value;
								}
								if (b < 0)
									b = 0;
								if (b >= 30)
								{
									b = 30;
									done = true;
								}
								if (b == a)
									a = 0;
								if (b == c)
									c = 0;
							}
							else
							{
								bForfeit = false;
							}
						}
					}
				}
				cout << a << ", " << b << ", " << c << endl;
			}
		}
		cout << endl << "Game is Over. Result" << endl;
		if (a == 0)
		{
			cout << "A - Start" << endl;
		}
		else if (a == 30)
		{
			cout << "A - End" << endl;
		}
		else
		{
			cout << "A - " << a << endl;
		}

		if (b == 0)
		{
			cout << "B - Start" << endl;
		}
		else if (b == 30)
		{
			cout << "B - End" << endl;
		}
		else
		{
			cout << "B - " << b << endl;
		}

		if (c == 0)
		{
			cout << "C - Start" << endl;
		}
		else if (c == 30)
		{
			cout << "C - End" << endl;
		}
		else
		{
			cout << "C - " << c << endl << endl;
		}

		cout << endl << "Do you wish to play again (y/n)? ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

}