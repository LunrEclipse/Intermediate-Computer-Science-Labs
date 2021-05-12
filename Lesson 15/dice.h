#pragma once

#include <stdlib.h>

class dice {
public:
	dice(int sides);
	int roll();
	int numSides();
	int numRolls();
private:
	int mySides;
	int myRollCount;
};

dice::dice(int sides)
{
	myRollCount = 0;
	mySides = sides;
}

int dice::roll()
{
	myRollCount++;
	return rand() % mySides + 1;
}

int dice::numSides()
{
	return mySides;
}

int dice::numRolls()
{
	return myRollCount;
}