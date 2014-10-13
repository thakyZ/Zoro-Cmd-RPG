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

// Loations
enum LOCATION { QUIT, TOWN, FOREST, VIEWSTATS };

// Stats Tree
struct ATTRIBUTES
{
	unsigned int strength;
	unsigned int faith;
	unsigned int dexterity;
	unsigned int insperation;
	unsigned int cleverness;
	unsigned int focus;
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
		int copper; // Money var.
		OCC charClass;
		RACE charRace;
		unsigned int hp, hpMax;
		unsigned int mp, mpMax;
		LOCATION location;

	public:
		// Constructors
		character()
		{
			copper = 50000;
			location = VIEWSTATS;
		}

		// Accessors
		// Get the attributes from outside this class.
		ATTRIBUTES getAtts()
		{
			return atts;
		}

		// Set the attributes from outside this class.
		void setAtts(ATTRIBUTES tmpAtts)
		{
			atts = tmpAtts;
		}

		// Get the location
		LOCATION getLoc()
		{
			return location;
		}

		// Locations
		// Display stats.
		void locStats()
		{
			bool reroll = true;
			char menuItem;

			while (reroll)
			{
				reroll = false;

				cout << "\n";
				cout << "You look yourself over...\n\n";

				displayStats(atts);

				cout << "   Hitpoints:     " << hp << "/" << hpMax << "\n";
				cout << "   Mana:          " << mp << "/" << mpMax << "\n";
				cout << "   Copper:        " << copper << "\n";

				cout << "\n";
				cout << "[G]o back to Town\n";
				cin >> menuItem;

				switch (menuItem)
				{
					case 'g':
					case 'G':
						location = TOWN;
						break;
					default:
						reroll = true;
						break;
				}
			}
		}

		//display town code.
		void locTown()
		{
			bool reroll = true;
			char menuItem;

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";

				cout << "You find the small village of Zoro. This village is very small but strategic as it sits on the hotly contested bore bewteen Ipana and Seragul. You go to:\n";
				cout << "[1] The Forest\t\t [5] The Weaponsmith\n";
				cout << "[2] The Armorsmith\t [6] Chapel of the Void\n";
				cout << "[3] The Tavern\t\t [7] The Money Lender\n";
				cout << "[4] View your Stats\t [8] Quit\n";

				cin >> menuItem;

				switch (menuItem)
				{
					case '1':
						location = FOREST;
						break;
					case '2':
						// location = ARMORSMITH;
						break;
					case '3':
						// location = TAVERN;
						break;
					case '4':
						location = VIEWSTATS;
						break;
					case '5':
						// location = WEAPONSMITH;
						break;
					case '6':
						// location = CHAPEL;
						break;
					case '7':
						// location = BANK;
						break;
					case '8':
						location = QUIT;
						break;
					default:
						reroll = true;
						break;
				}
			}
		}
};

// Class for the fighter.
class fighter : public character
{
	public:
		fighter()
		{
			cout << "Fighter Created.\n";

			hpMax = hp = diceRoll(10, 6);
			mpMax = mp = 20;
		}
};

// Class for the Cleric.
class cleric : public character
{
	public:
		cleric()
		{
			cout << "Cleric Created.\n";

			hpMax = hp = diceRoll(7, 6);
			mpMax = mp = 50;
		}
};

// Class for the Rouge.
class rouge : public character
{
	public:
		rouge()
		{
			cout << "Rouge Created.\n";

			hpMax = hp = diceRoll(7, 6);
			mpMax = mp = 20;
		}
};

// Class for the Bard.
class bard : public character
{
	public:
		bard()
		{
			cout << "Bard Created.\n";

			hpMax = hp = diceRoll(5, 6);
			mpMax = mp = 50;
		}
};

// Class for the Tinker.
class tinker : public character
{
	public:
		tinker()
		{
			cout << "Tinker Created.\n";

			hpMax = hp = diceRoll(5, 6);
			mpMax = mp = 20;
		}
};

// Class for the Mage.
class mage : public character
{
	public:
		mage()
		{
			cout << "Mage Created.\n";

			hpMax = hp = diceRoll(3, 6);
			mpMax = mp = 50;
		}
};

// Startup
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	RACE inputRace; // The race that is chosen.
	char inputs; // The inputs.
	ATTRIBUTES tmpStats; // The stats the player gets by random.
	bool reroll = true; // The bool for rerolling.
	OCC inputClass; // The class that is chosen.
	bool retry = true; // The fix for the race chooser.
	bool iQuit = false; // To tell if the player want to quit the game.

	// Set the character to pointer var.
	character *player1;

	// Clear the console.
	system("cls");

	cout << "Welcome to Zoro\n";

	// Check for the reroll
	while (reroll == true)
	{
		// End the reroll;
		reroll = false;

		cout << "Please Select a Race:\n";
		cout << "[H]uman [E]lf [D]ark elf [A]ngel [M]ongrel [S]hamani [N]ibelung [U]ndead\n";

		// Check for the retry
		while (retry == true)
		{
			// The input for the chosen race.
			cin >> inputs;

			// End the retry.
			retry = false;

			switch (inputs)
			{
				case 'h':
				case 'H':
					cout << "\nHuman!\n";
					inputRace = HUMAN;
					tmpStats.strength = diceRoll(3, 6);
					tmpStats.faith = diceRoll(3, 6);
					tmpStats.dexterity = diceRoll(3, 6);
					tmpStats.insperation = diceRoll(3, 6);
					tmpStats.cleverness = diceRoll(3, 6);
					tmpStats.focus = diceRoll(3, 6);
					retry = false; // End the retry.
					break;
				case 'e':
				case 'E':
					cout << "\nElf!\n";
					inputRace = ELF;
					tmpStats.strength = diceRoll(3, 6);
					tmpStats.faith = diceRoll(3, 6);
					tmpStats.dexterity = diceRoll(3, 6);
					tmpStats.insperation = diceRoll(3, 6);
					tmpStats.cleverness = diceRoll(2, 6);
					tmpStats.focus = diceRoll(4, 6);
					break;
				case 'd':
				case 'D':
					cout << "\nDark Elf!\n";
					inputRace = DARKELF;
					tmpStats.strength = diceRoll(3, 6);
					tmpStats.faith = diceRoll(3, 6);
					tmpStats.dexterity = diceRoll(4, 6);
					tmpStats.insperation = diceRoll(2, 6);
					tmpStats.cleverness = diceRoll(3, 6);
					tmpStats.focus = diceRoll(3, 6);
					break;
				case 'a':
				case 'A':
					cout << "Angel!\n";
					inputRace = ANGEL;
					tmpStats.strength = diceRoll(3, 6);
					tmpStats.faith = diceRoll(4, 6);
					tmpStats.dexterity = diceRoll(3, 6);
					tmpStats.insperation = diceRoll(3, 6);
					tmpStats.cleverness = diceRoll(3, 6);
					tmpStats.focus = diceRoll(3, 6);
					break;
				case 'm':
				case 'M':
					cout << "\nMongrel!\n";
					inputRace = MONGREL;
					tmpStats.strength = diceRoll(4, 6);
					tmpStats.faith = diceRoll(3, 6);
					tmpStats.dexterity = diceRoll(3, 6);
					tmpStats.insperation = diceRoll(3, 6);
					tmpStats.cleverness = diceRoll(3, 6);
					tmpStats.focus = diceRoll(2, 6);
					break;
				case 's':
				case 'S':
					cout << "\nShamani!\n";
					inputRace = SHAMANI;
					tmpStats.strength = diceRoll(2, 6);
					tmpStats.faith = diceRoll(4, 6);
					tmpStats.dexterity = diceRoll(3, 6);
					tmpStats.insperation = diceRoll(3, 6);
					tmpStats.cleverness = diceRoll(3, 6);
					tmpStats.focus = diceRoll(3, 6);
					break;
				case 'n':
				case 'N':
					cout << "\nNibelung!\n";
					inputRace = NIBELUNG;
					tmpStats.strength = diceRoll(3, 6);
					tmpStats.faith = diceRoll(3, 6);
					tmpStats.dexterity = diceRoll(2, 6);
					tmpStats.insperation = diceRoll(3, 6);
					tmpStats.cleverness = diceRoll(4, 6);
					tmpStats.focus = diceRoll(3, 6);
					break;
				case 'u':
				case 'U':
					cout << "\nUndead!\n";
					inputRace = UNDEAD;
					tmpStats.strength = diceRoll(3, 6);
					tmpStats.faith = diceRoll(3, 6);
					tmpStats.dexterity = diceRoll(3, 6);
					tmpStats.insperation = diceRoll(3, 6);
					tmpStats.cleverness = diceRoll(2, 6);
					tmpStats.focus = diceRoll(3, 6);
					break;
				default:
					cout << "\nPlease input a vaild race.\n";
					retry = true; // Set the retry to default
					break;
			}
		}

		// Display the stats
		displayStats(tmpStats);

		cout << "Reroll? [Y]es [N]o\n\n";

		// Input for the reroll.
		cin >> inputs;

		// End the reroll
		reroll = false;

		if (inputs == 'y' || inputs == 'Y')
		{
			cout << inputs;
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

		cout << "\nPlease select a class\n\n";
		cout << "[F]ighter [C]leric [T]heif [B]ard [R]ouge [M]age\n\n";

		// Check for inputs of which class.
		cin >> inputs;

		// Check for which class.
		switch (inputs)
		{
			case 'f':
			case 'F':
				inputClass = FIGHTER;
				cout << "\nFighter!\n";
				player1 = new fighter;
				break;
			case 'c':
			case 'C':
				inputClass = CLERIC;
				cout << "\nCleric!\n";
				player1 = new fighter;
				break;
			case 't':
			case 'T':
				inputClass = THEIF;
				cout << "\nTheif!\n";
				player1 = new rouge;
				break;
			case 'b':
			case 'B':
				inputClass = BARD;
				cout << "\nBard!\n";
				player1 = new bard;
				break;
			case 'r':
			case 'R':
				inputClass = ROUGE;
				cout << "\nRouge!\n";
				player1 = new rouge;
				break;
			case 'm':
			case 'M':
				inputClass = MAGE;
				cout << "\nMage!\n";
				player1 = new mage;
				break;
			default:
				cout << "\nPlease input a valid class.\n";
				reroll = true;
				break;
		}
	}



	// Set the attributes as they are at this point.
	player1->setAtts(tmpStats);

	// Something or rather.
	while (!iQuit)
	{
		switch (player1->getLoc())
		{
			case QUIT:
				iQuit = true;
				break;
			case VIEWSTATS:
				player1->locStats();
				break;
			default:
			case TOWN:
				player1->locTown();
				break;
		}
	}

	return 0;
}