// sorting template program

#include <iostream>
#include <iomanip>
#include <fstream>
#include "dice.h"
#include <string>
#include <cstring>
using namespace std;

enum suitType { hearts, clubs, diamonds, spades, badsuit };
enum valueType {two, three, four, five, six, seven, eight, nine, ten,
	jack, queen, king, ace, badvalue };

ostream& operator<< (ostream& out, suitType cardSuit);
istream& operator>> (istream& in, suitType& cardSuit);
ostream& operator<< (ostream& out, valueType value);
istream& operator>> (istream& in, valueType& value);

void main()
{
	suitType cardSuit;
	valueType cardValue;

	do
	{
		cout << "Enter a card value: ";
		cin >> cardValue;
		cout << "Enter a card suit: ";
		cin >> cardSuit;
		cout << "Card entered = " << cardValue << " of " << cardSuit << endl;
	} while (cardSuit != badsuit);
}

ostream& operator<< (ostream& out, suitType cardSuit)
{
	switch (cardSuit)
	{
	case hearts:	out << "hearts"; break;
	case clubs:	out << "clubs"; break;
	case diamonds:	out << "diamonds"; break;
	case spades:  out << "spades"; break;
	case badsuit: out << "not a valid suit"; break;
	}
	return out;
}

istream& operator>> (istream& in, suitType& cardSuit)
{
	string temp;

	in >> temp;
	if (temp == "hearts") 
		cardSuit = hearts;
	else if (temp == "clubs") 
		cardSuit = clubs;
	else if (temp == "diamonds") 
		cardSuit = diamonds;
	else if (temp == "spades") 
		cardSuit = spades;
	else 
		cardSuit = badsuit;
	return in;
}

ostream& operator<< (ostream& out, valueType value)
{
	switch (value)
	{
	case two:	out << "two"; break;
	case three:	out << "three"; break;
	case four:	out << "four"; break;
	case five:  out << "five"; break;
	case six:	out << "six"; break;
	case seven:	out << "seven"; break;
	case eight: out << "eight"; break;
	case nine:  out << "nine"; break;
	case ten:   out << "ten"; break;
	case jack:	out << "jack"; break;
	case queen:	out << "queen"; break;
	case king:  out << "king"; break;
	case ace:	out << "ace"; break;
	case badvalue: out << "not a valid card value"; break;
	}
	return out;
}

istream& operator>> (istream& in, valueType& value)
{
	string temp;

	in >> temp;
	if (temp == "two") 
		value = two;
	else if (temp == "three")
		value = three;
	else if (temp == "four")
		value = four;
	else if (temp == "five")
		value = five;
	else if (temp == "six")
		value = six;
	else if (temp == "seven")
		value = seven;
	else if (temp == "eight")
		value = eight;
	else if (temp == "nine") 
		value = nine;
	else if (temp == "ten") 
		value = ten;
	else if (temp == "jack") 
		value = jack;
	else if (temp == "queen")
		value = queen;
	else if (temp == "king") 
		value = king;
	else if (temp == "ace") 
		value = ace;
	else 
		value = badvalue;
	return in;
}
