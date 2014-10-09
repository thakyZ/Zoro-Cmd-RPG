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

// Display the stats of the roll.
void displayStats(ATTRIBUTES atts)
{
	cout << " +---------------------+ \n";
	cout << " | Attributes:         | \n";
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

// Class for the character.
class character
{
	protected:
		ATTRIBUTES atts;
		int copper;
		OCC charClass;
		RACE charRace;

	public:
		character()
		{
			copper = 50000;
		}
};

// Class for the fighter.
class fighter : public character
{
	public:
		fighter()
		{
			cout << "Fighter Created.\n";

			atts.hpMax = atts.hp = diceRoll(10, 6);
			atts.mpMax = atts.mp = 20;


		}
};

// Class for the Cleric.
class cleric : public character
{
	public:
		cleric()
		{
			cout << "Cleric Created.\n";

			atts.hpMax = atts.hp = diceRoll(7, 6);
			atts.mpMax = atts.mp = 50;


		}
};

// Class for the Rouge.
class rouge : public character
{
	public:
		rouge()
		{
			cout << "Rouge Created.\n";

			atts.hpMax = atts.hp = diceRoll(7, 6);
			atts.mpMax = atts.mp = 20;


		}
};

// Class for the Bard.
class bard : public character
{
	public:
		bard()
		{
			cout << "Bard Created.\n";

			atts.hpMax = atts.hp = diceRoll(5, 6);
			atts.mpMax = atts.mp = 50;


		}
};

// Class for the Tinker.
class tinker : public character
{
	public:
		tinker()
		{
			cout << "Tinker Created.\n";

			atts.hpMax = atts.hp = diceRoll(5, 6);
			atts.mpMax = atts.mp = 20;


		}
};

// Class for the Mage.
class mage : public character
{
	public:
		mage()
		{
			cout << "Mage Created.\n";

			atts.hpMax = atts.hp = diceRoll(3, 6);
			atts.mpMax = atts.mp = 50;


		}
};

// Startup
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	RACE inputRace; // The race that is chosen.
	char inputs; // The inputs.
	ATTRIBUTES tempStats; // The stats the player gets by random.
	bool reroll = true; // The bool for rerolling.
	OCC inputClass; // The class that is chosen.
	bool retry = true; // The fix for the race chooser.

	character *player1;

	// Clear the console.
	system("cls");

	cout << "Welcome to Zoro\n";

	// Check for the reroll
	while (reroll == true)
	{
		cout << "Please Select a Race:\n";
		cout << "[H]uman [E]lf [D]ark elf [A]ngel [M]ongrel [S]hamani [N]ibelung [U]ndead\n";

		// Check for the retry
		while (retry == true)
		{
			// The input for the chosen race.
			cin >> inputs;

			// Reset the retry var.
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
					retry = false; // End the retry.
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
					retry = true; // Set the retry to default
					break;
			}
		}

		// Display the stats
		displayStats(tempStats);

		cout << "Reroll? [Y]es [N]o\n";

		// Input for the reroll.
		cin >> inputs;

		// End the reroll
		reroll = false;

		if (inputs == 'y' || inputs == 'Y')
		{
			// Reset the reroll to default.
			reroll = true;
		}
	}

	// Reset the reroll to default for the second reroll.
	reroll = true;

	while (reroll) // While reroll == true
	{
		// End the reroll for now
		reroll = false;

		cout << "Please select a class\n";
		cout << "[F]ighter [C]leric [T]heif [B]ard [R]ouge [M]age\n";

		// Check for inputs of which class.
		cin >> inputs;

		// Check for which class.
		switch (inputs)
		{
			case 'f':
			case 'F':
				inputClass = FIGHTER;
				cout << "Fighter\n";
				player1 = new fighter;
				break;
			case 'c':
			case 'C':
				inputClass = CLERIC;
				cout << "Cleric\n";
				player1 = new fighter;
				break;
			case 't':
			case 'T':
				inputClass = THEIF;
				cout << "Theif\n";
				player1 = new rouge;
				break;
			case 'b':
			case 'B':
				inputClass = BARD;
				cout << "Bard\n";
				player1 = new bard;
				break;
			case 'r':
			case 'R':
				inputClass = ROUGE;
				cout << "Rouge\n";
				player1 = new rouge;
				break;
			case 'm':
			case 'M':
				inputClass = MAGE;
				cout << "Mage\n";
				player1 = new mage;
				break;
			default:
				cout << "Please input a valid class.\n";
				reroll = true;
				break;
		}
	}

	return 0;
}