#include "dice.h"

class frog
{
public:
	frog();
	int getPosition() const;
	int getSteps() const;
	void takeStep();
private:
	int myPosition;
	int mySteps;
	dice myDice;
};
