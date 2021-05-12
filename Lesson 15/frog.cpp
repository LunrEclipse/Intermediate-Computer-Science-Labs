
#include "frog.h"
frog::frog() : myDice(2)
{
	myPosition = 0;
	mySteps = 0;
}

int frog::getPosition() const
{
	return myPosition;
}

int frog::getSteps() const
{
	return mySteps;
}

void frog::takeStep()
{
	if (myDice.roll() == 1)
		myPosition--;
	else
		myPosition++;
	mySteps++;
}
