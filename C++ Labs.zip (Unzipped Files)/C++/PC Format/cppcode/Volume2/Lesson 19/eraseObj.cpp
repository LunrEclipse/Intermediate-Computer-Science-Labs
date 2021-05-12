// eraseObj.cpp

#include <iostream.h>
#include <fstream.h>
#include <apmatrix.h>
#include <iomanip.h>
#include <apstring.h>
#include <stdlib.h>

const int SIZE = 20;
const apstring SOURCE = "c:\\ap98\\digital.txt";

enum cellType {black, white};

void getData (apmatrix<cellType> &image);
void printImage (const apmatrix<cellType> &image);
void eraseObject (apmatrix<cellType> &image, int row, int col);

main ()
{
	apmatrix <cellType> image(SIZE+1,SIZE+1,white);
	int row,col;

	getData (image);
	printImage (image);
	cout << endl << "Enter row and col of starting point: ";
	cin >> row >> col;
	cin.get();	// to dump return key
	eraseObject (image,row,col);
	printImage (image);

	cout << endl << "Enter row and col of starting point: ";
	cin >> row >> col;
	cin.get();	// to dump return key
	eraseObject (image,row,col);
	printImage (image);

	return 0;
}

void getData (apmatrix<cellType> &image)
{
	ifstream inFile;
	int numPairs, row, col;

   inFile.open(SOURCE.c_str());
   if (inFile.fail())
   {
   	cerr << "Could not open " << SOURCE << endl;
   	abort();
   }
	inFile >> numPairs;
	for (int loop=1; loop<=numPairs; loop++)
	{
		inFile >> row >> col;
		image [row][col] = black;
	}
}

void printImage (const apmatrix<cellType> &image)
{
	int  col, row;

	cout << setiosflags (ios::right);	
	cout << "    ";  // 4 spaces
	for (col=1; col<=SIZE; col++)
		cout << col % 10;
	cout << endl;
	for (row=1; row<=SIZE; row++)
	{
		cout << " " << setw(2) << row << " ";
		for (col=1; col<=SIZE; col++)
			if (black == image[row][col])
				cout << "@";
			else
				cout << "-";
		cout << endl;
	}
}

void eraseObject (apmatrix<cellType> &image, int row, int col)
{
	if (1<=row && row<=SIZE && 1<=col && col<=SIZE)
		if (black == image[row][col])
		{
			image[row][col] = white;
			eraseObject (image,row-1,col);
			eraseObject (image,row,col+1);
			eraseObject (image,row+1,col);
			eraseObject (image,row,col-1);
		}
}
