// ConsoleRPG.cpp : Defines the entry point for the console application.
// Created by Nick Mullally a.k.a. thakyZ / Nire Inicana
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "time.h"
using namespace std;

// Roll the dice.
int diceRoll(int qty, int sides)
{
	int subTotal = 0; // Dice addition subtotal.
	// Roll the dice.

	// Loop to roll the dice
	for (int i = 0; i < qty; i++)
	{
		int currentRoll = rand() % sides + 1;
		subTotal += currentRoll;
	}

	return subTotal;
}



// Race Choices
enum RACE { HUMAN, ELF, DARKELF, ANGEL, MONGREL, SHAMANI, NIBELUNG, UNDEAD };

// Class Choices
enum OCC { FIGHTER, CLERIC, THEIF, BARD, ROUGE, TINKER, MAGE };

// Stats Tree
struct ATTRIBUTES
{
	unsigned int strength;
	unsigned int faith;
	unsigned int dexterity;
	unsigned int insperation;
	unsigned int cleverness;
	unsigned int focus;
	unsigned int hp, hpMax;
	unsigned int mp, mpMax;
};

void displayStats(ATTRIBUTES atts)
{
	cout << " +---------------------+ \n";
	cout << " |  Attributes:        | \n";
	cout << " +---------------------+ \n";
	cout << "\n";
	cout << "   Strength:      " << atts.strength << "\n";
	cout << "   Faith:         " << atts.faith << "\n";
	cout << "   Dexterity:     " << atts.dexterity << "\n";
	cout << "   Insperation:   " << atts.insperation << "\n";
	cout << "   Cleverness:    " << atts.cleverness << "\n";
	cout << "   Focus:         " << atts.focus << "\n";
	cout << "\n\n";
}

// Startup
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	RACE inputRace; // The race that is chosen.
	char inputs; // The inputs.
	ATTRIBUTES tempStats; // The stats the player gets by random.
	bool reroll = true; // The bool for rerolling.
	OCC inputClass; // The class that is chosen.
	bool retry = true;

	system("cls");

	cout << "Welcome to Zoro\n";

	while (reroll == true)
	{
		cout << "Please Select a Race:\n";
		cout << "[H]uman [E]lf [D]ark elf [A]ngel [M]ongrel [S]hamani [N]ibelung [U]ndead\n";

		// The input for the chosen race.
		cin >> inputs;

		while (retry == true)
		{
			retry == false;

			switch (inputs)
			{
				case 'h':
				case 'H':
					cout << "Human\n";
					inputRace = HUMAN;
					tempStats.strength = diceRoll(3, 6);
					tempStats.faith = diceRoll(3, 6);
					tempStats.dexterity = diceRoll(3, 6);
					tempStats.insperation = diceRoll(3, 6);
					tempStats.cleverness = diceRoll(3, 6);
					tempStats.focus = diceRoll(3, 6);
					break;
				case 'e':
				case 'E':
					cout << "Elf\n";
					inputRace = ELF;
					tempStats.strength = diceRoll(3, 6);
					tempStats.faith = diceRoll(3, 6);
					tempStats.dexterity = diceRoll(3, 6);
					tempStats.insperation = diceRoll(3, 6);
					tempStats.cleverness = diceRoll(2, 6);
					tempStats.focus = diceRoll(4, 6);
					break;
				case 'd':
				case 'D':
					cout << "Dark Elf\n";
					inputRace = DARKELF;
					tempStats.strength = diceRoll(3, 6);
					tempStats.faith = diceRoll(3, 6);
					tempStats.dexterity = diceRoll(4, 6);
					tempStats.insperation = diceRoll(2, 6);
					tempStats.cleverness = diceRoll(3, 6);
					tempStats.focus = diceRoll(3, 6);
					break;
				case 'a':
				case 'A':
					cout << "Angel\n";
					inputRace = ANGEL;
					tempStats.strength = diceRoll(3, 6);
					tempStats.faith = diceRoll(4, 6);
					tempStats.dexterity = diceRoll(3, 6);
					tempStats.insperation = diceRoll(3, 6);
					tempStats.cleverness = diceRoll(3, 6);
					tempStats.focus = diceRoll(3, 6);
					break;
				case 'm':
				case 'M':
					cout << "Mongrel\n";
					inputRace = MONGREL;
					tempStats.strength = diceRoll(4, 6);
					tempStats.faith = diceRoll(3, 6);
					tempStats.dexterity = diceRoll(3, 6);
					tempStats.insperation = diceRoll(3, 6);
					tempStats.cleverness = diceRoll(3, 6);
					tempStats.focus = diceRoll(2, 6);
					break;
				case 's':
				case 'S':
					cout << "Shamani\n";
					inputRace = SHAMANI;
					tempStats.strength = diceRoll(2, 6);
					tempStats.faith = diceRoll(4, 6);
					tempStats.dexterity = diceRoll(3, 6);
					tempStats.insperation = diceRoll(3, 6);
					tempStats.cleverness = diceRoll(3, 6);
					tempStats.focus = diceRoll(3, 6);
					break;
				case 'n':
				case 'N':
					cout << "Nibelung\n";
					inputRace = NIBELUNG;
					tempStats.strength = diceRoll(3, 6);
					tempStats.faith = diceRoll(3, 6);
					tempStats.dexterity = diceRoll(2, 6);
					tempStats.insperation = diceRoll(3, 6);
					tempStats.cleverness = diceRoll(4, 6);
					tempStats.focus = diceRoll(3, 6);
					break;
				case 'u':
				case 'U':
					cout << "Undead\n";
					inputRace = UNDEAD;
					tempStats.strength = diceRoll(3, 6);
					tempStats.faith = diceRoll(3, 6);
					tempStats.dexterity = diceRoll(3, 6);
					tempStats.insperation = diceRoll(3, 6);
					tempStats.cleverness = diceRoll(2, 6);
					tempStats.focus = diceRoll(3, 6);
					break;
				default:
					cout << "Please input a vaild race.\n";
					retry = true;
					break;
			}
		}

		displayStats(tempStats);

		cout << "Reroll? [Y]es [N]o\n";

		cin >> inputs;

		reroll = false;

		if (inputs == 'y' || inputs == 'Y')
		{
			reroll = true;
		}
	}

	reroll = true;

	while (reroll) // While reroll == true
	{
		reroll = false;

		cout << "Please select a class\n";
		cout << "[F]ighter [C]leric [T]heif [B]ard [R]ouge [M]age\n";

		cin >> inputs;

		switch (inputs)
		{
			case 'f':
			case 'F':
				inputClass = FIGHTER;
				cout << "Fighter\n";
				break;
			case 'c':
			case 'C':
				inputClass = CLERIC;
				cout << "Cleric\n";
				break;
			case 't':
			case 'T':
				inputClass = THEIF;
				cout << "Theif\n";
				break;
			case 'b':
			case 'B':
				inputClass = BARD;
				cout << "Bard\n";
				break;
			case 'r':
			case 'R':
				inputClass = ROUGE;
				cout << "Rouge\n";
				break;
			case 'm':
			case 'M':
				inputClass = MAGE;
				cout << "Mage\n";
				break;
			default:
				cout << "Please input a valid class.\n";
				reroll = true;
				break;
		}
	}

	return 0;
}