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
enum LOCATION { QUIT, TOWN, FOREST, VIEWSTATS, MONSTER };

// Armors.
enum ARMOR { LOINCLOTH, CLOTHARMOR };

// Weapons.
enum WEAPON { FISTS, DAGGER };

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

class monster
{
	public:
		int hp, hpMax; // The var for hitpoints.
		ATTRIBUTES atts; // The var for stats.
		char *mName; // The name of the monster.
		char *attackText; // The text when the monster attacks.
		char *deathText; // The text when the monster dies.
		char *winText; // The text when the player dies.
		int masteries; // Unknown.
		int copper; // The amout of money the monster drops.
		ARMOR armor; // The armor the monster has.
		WEAPON weapon; // The weapon the monster has.

		monster()
		{
			masteries = 0; // Declare this for now to 0.

			// Switch to figure out what monster the player will face.
			switch (diceRoll(1, 2))
			{
				case 1:
					mName = "A Small Goblin";
					hp = hpMax = diceRoll(3, 6);
					atts.strength = diceRoll(2, 6);
					atts.focus = diceRoll(2, 6);
					atts.cleverness = diceRoll(2, 6);
					atts.dexterity = diceRoll(2, 6);
					atts.faith = diceRoll(2, 6);
					atts.insperation = diceRoll(2, 6);
					copper = diceRoll(10, 5);
					armor = LOINCLOTH;
					weapon = FISTS;
					attackText = "a moldy stick";
					deathText = "the goblin cries out \"why use hits mes sos hards?\"";
					winText = "the goblin celibrates its victory by dancing around with his moldy stick.";
					break;
				case 2:
					mName = "A Giant Rat";
					hp = hpMax = diceRoll(3, 6);
					atts.strength = diceRoll(2, 6);
					atts.focus = diceRoll(2, 6);
					atts.cleverness = diceRoll(2, 6);
					atts.dexterity = diceRoll(2, 6);
					atts.faith = diceRoll(2, 6);
					atts.insperation = diceRoll(2, 6);
					copper = diceRoll(10, 5);
					armor = LOINCLOTH;
					weapon = FISTS;
					attackText = "sharp pointy teeth";
					deathText = "the rat goes squee and keels over dead.";
					winText = "the rat starts eating your dead carcus.";
					break;
			}
		}
};

// Class for the character.
class character
{
	protected:
		ATTRIBUTES atts; // The stats that the player has.
		int copper; // The amount of money the player has.
		OCC charClass; // The characters class.
		RACE charRace; // The characters race.
		unsigned int hp, hpMax; // The hitpoints for the character.
		unsigned int mp, mpMax; // The mana or stamina for the character.
		LOCATION location; // The location the player is at.
		WEAPON weapon; // The weapon the character has.
		ARMOR armor; // The armor the character has.

	public:
		// Constructors
		character()
		{
			// Set the default copper.
			copper = 50000;

			// Set the default location of the menu.
			location = VIEWSTATS;
		}

		// Accessors
		// Get the attributes from outside this class.
		ATTRIBUTES getAtts()
		{
			// Return the attributes because thats what we want to do.
			return atts;
		}

		// Set the attributes from outside this class.
		void setAtts(ATTRIBUTES tmpAtts)
		{
			// Set the attributes to the character.
			atts = tmpAtts;
		}

		// Get the location
		LOCATION getLoc()
		{
			// Return the location because thats what we want to do.
			return location;
		}

		virtual void attack(monster* monster1) {}

		// Locations
		// Display stats.
		void locStats()
		{
			bool reroll = true; // Check for the loop.
			char menuItem; // The var for the menus.

			// Start the loop.
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";
				cout << "You look yourself over...\n\n";

				// Display the stats.
				displayStats(atts);

				cout << "   Hitpoints:     " << hp << "/" << hpMax << "\n";
				cout << "   Mana:          " << mp << "/" << mpMax << "\n";
				cout << "   Copper:        " << copper << "\n";

				cout << "\n";
				cout << "[G]o back to Town\n";

				// Get the input for the menu.
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

		// Display town code.
		void locTown()
		{
			bool reroll = true; // Check for the menu.
			char menuItem; // The var for the menus.

			// Start the loop.
			while (reroll)
			{
				// End the loop.
				reroll = false;

				cout << "\n\n";

				cout << "You find the small village of Zoro. This village is very small but strategic as it sits on the hotly contested bore bewteen Ipana and Seragul. You go to:\n";
				cout << "[1] The Forest\t\t [5] The Weaponsmith\n";
				cout << "[2] The Armorsmith\t [6] Chapel of the Void\n";
				cout << "[3] The Tavern\t\t [7] The Money Lender\n";
				cout << "[4] View your Stats\t [8] Quit\n";

				// Get the menuItem.
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

		// Display forest code.
		void locForest()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n\n";

				cout << "You enter the woods near Zoro. It's dark a spoopy, you think you hear some noise in the bushes. You:\n";
				cout << "[1] Look for monsters\t [3] Visit the alchimest\n";
				cout << "[2] Return To town\n";

				// Input for the menu.
				cin >> menuItem;

				switch (menuItem)
				{
					case '1':
						location = MONSTER;
						break;
					case '2':
						location = TOWN;
						break;
					case '3':
						// location = ALCHIMEST;
						break;
					default:
						reroll = true;
						break;
				}
			}
		}

		// Display monster locations.
		void locMonster()
		{
			monster monster1; // Monster variable.

			cout << "\n";
			cout << "You hear a rustel in the bushes. " << monster1.mName << " jumps out at you\n";

			// Start the loop.
			while (hp > 0 && monster1.hp > 0)
			{
				cout << "\n\n";
				cout << monster1.mName << ": " << monster1.hp << "/" << monster1.hpMax << "\n";
				cout << "You: " << hp << "/" << hpMax << "\n\n";
				cout << "Action?\n";

				attack(&monster1);
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

		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "\n";
				cout << "[A]ttack";

				if (mp >= 1)
				{
					cout << "\t[F]renzy\n";
				}
				if (mp >= 5)
				{
					cout << "[D]eadly Strike\n";
				}

				cin >> inputs;
			}
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

		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "\n";
				cout << "[A]ttack";

				if (mp >= 1)
				{
					cout << "\t[F]renzy\n";
				}
				if (mp >= 5)
				{
					cout << "[D]eadly Strike\n";
				}

				cin >> inputs;
			}
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

		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "\n";
				cout << "[A]ttack";

				if (mp >= 1)
				{
					cout << "\t[F]renzy\n";
				}
				if (mp >= 5)
				{
					cout << "[D]eadly Strike\n";
				}

				cin >> inputs;
			}
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

		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "\n";
				cout << "[A]ttack";

				if (mp >= 1)
				{
					cout << "\t[F]renzy\n";
				}
				if (mp >= 5)
				{
					cout << "[D]eadly Strike\n";
				}

				cin >> inputs;
			}
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

		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "\n";
				cout << "[A]ttack";

				if (mp >= 1)
				{
					cout << "\t[F]renzy\n";
				}
				if (mp >= 5)
				{
					cout << "[D]eadly Strike\n";
				}

				cin >> inputs;
			}
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

		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "\n";
				cout << "[A]ttack";

				if (mp >= 1)
				{
					cout << "\t[F]renzy\n";
				}
				if (mp >= 5)
				{
					cout << "[D]eadly Strike\n";
				}

				cin >> inputs;
			}
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
			case FOREST:
				player1->locForest();
				break;
			case MONSTER:
				player1->locMonster();
				break;
		}
	}

	return 0;
}