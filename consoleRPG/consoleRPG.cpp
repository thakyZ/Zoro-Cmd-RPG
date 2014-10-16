// ConsoleRPG.cpp : Defines the entry point for the console application.
// Created by Nick Mullally a.k.a. thakyZ / Nire Inicana
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "time.h"
#include <fstream>
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

// Race types.
enum RACE { HUMAN, ELF, DARKELF, ANGEL, MONGREL, SHAMANI, NIBELUNG, UNDEAD };

// Class types.
enum OCC { FIGHTER, CLERIC, THEIF, BARD, ROUGE, TINKER, MAGE };

// Loations types.
enum LOCATION { QUIT, TOWN, FOREST, VIEWSTATS, MONSTER, SAVE, LOAD };

// Armors types.
enum ARMOR { LOINCLOTH, CLOTHARMOR, LEATHER };

// Weapons types.
enum WEAPON { FISTS, DAGGER, STAFF, SWORD };

// Attacks types.
enum ATTACK { REGULAR, FRENZY, DEADLY };

// Stats Tree.
struct ATTRIBUTES
{
	unsigned int strength; // The strength stat of the class.
	unsigned int faith; // The faith stat of the class.
	unsigned int dexterity; // The dexterity stat of the class.
	unsigned int insperation; // The insperation stat of the class.
	unsigned int cleverness; // The cleverness stat of the class.
	unsigned int focus; // The focus stat of the class.
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

		// Create the monster class.
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
					weapon = DAGGER;
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

		// Get or set methods.
		int getHealth ()
		{
			return hp;
		}

		int getMaxHealth ()
		{
			return hpMax;
		}

		// We do not need this right now...
		/*int getMana ()
		{
			return mp;
		}

		int getMaxMana ()
		{
			return mpMax;
		}*/

		char *getName ()
		{
			return mName;
		}

		char *getAttackText ()
		{
			return attackText;
		}

		char *getDeathText ()
		{
			return deathText;
		}

		char *getWinText ()
		{
			return winText;
		}

		int getMasteries ()
		{
			return masteries;
		}

		int getCopper ()
		{
			return copper;
		}

		ARMOR getArmor ()
		{
			return armor;
		}

		WEAPON getWeapon ()
		{
			return weapon;
		}

		ATTRIBUTES getAtts ()
		{
			return atts;
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
		int masteries; // The skills level of the player.

	public:
		// Constructors
		// Create the character class.
		character()
		{
			// Set the default copper.
			copper = 50000;

			// Set the default location of the menu.
			location = VIEWSTATS;

			// Set default masteries.
			masteries = 1;

			// Set the default weapon.
			weapon = FISTS;

			// Set the default armor.
			armor = LOINCLOTH;
		}

		// Accessors
		int getHealth ()
		{
			return hp;
		}

		int getMaxHealth ()
		{
			return hpMax;
		}

		int getMana ()
		{
			return mp;
		}

		int getMaxMana ()
		{
			return mpMax;
		}

		int getCopper ()
		{
			return copper;
		}

		OCC getClass ()
		{
			return charClass;
		}

		RACE getRace ()
		{
			return charRace;
		}

		int getMasteries ()
		{
			return masteries;
		}

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

		virtual void attack(monster monster1) {}

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
						location = TOWN; // Set the location town because after we display stats we want to go back to town.
						break;
					default:
						reroll = true; // If you do not type in the right input this will repeat.
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
						location = FOREST; // Go to the forest.
						break;
					case '2':
						// location = ARMORSMITH; // Go to the armor smith.
						break;
					case '3':
						// location = TAVERN; // Go to the tavern.
						break;
					case '4':
						location = VIEWSTATS; // Go to the view stats screen.
						break;
					case '5':
						// location = WEAPONSMITH; // Go to the weapon smith.
						break;
					case '6':
						// location = CHAPEL; // Go to the chapel.
						break;
					case '7':
						// location = BANK; // Go to the bank.
						break;
					case '8':
						location = QUIT; // Quit the game.
						break;
					default:
						reroll = true; // If you do not type in a correct input then loop.
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
						location = MONSTER; // Go find a monster.
						break;
					case '2':
						location = TOWN; // Go to the town.
						break;
					case '3':
						// location = ALCHIMEST; // Go to the alchimest.
						break;
					default:
						reroll = true; // If you do not type in the right input then repeat.
						break;
				}
			}
		}

		// Display monster locations.
		void locMonster()
		{
			monster monster1; // Monster variable.

			cout << "\n";
			cout << "You hear a rustel in the bushes. " << monster1.getName() << " jumps out at you\n";

			// Start the loop.
			while (hp > 0 && monster1.getHealth() > 0)
			{
				cout << "\n\n";
				cout << monster1.getName() << ": " << monster1.getHealth() << "/" << monster1.getMaxHealth() << "\n";
				cout << "You: " << hp << "/" << hpMax << "\n\n";
				cout << "Action?\n";

				attack(monster1); // Start the battle.
			}
		}

		void locSave()
		{
			bool reroll = true;
			char menuItem;

			while (reroll)
			{
				reroll = false;

				cout << "\n";
			}
		}

		void locLoad()
		{

		}
};

// Class for the fighter.
class fighter : public character
{
	public:
		// Create the fighter class.
		fighter()
		{
			cout << "Fighter Created.\n";

			hpMax = hp = diceRoll(10, 6); // Set the default fighter's hitpoints.
			mpMax = mp = 20; // Set the default fighter's mana.

			masteries = 1; // Set the default fighter's skill level.

			armor = LEATHER; // Set the default fighter's armor.

			weapon = SWORD; // Set the default fighter's weapon.
		}

		virtual void attack(monster monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			//moo

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "\n";
				cout << "[A]ttack";

				if (mp >= 1)
				{
					cout << "\t[F]renzy";
				}
				if (mp >= 5)
				{
					cout << "\n[D]eadly Strike";
				}

				cout << "\n";

				// Get the input of what attack to use.
				cin >> inputs;

				// Set the target roll
				int targetRoll = 10 + (atts.dexterity + atts.strength) - (monster1.getAtts().dexterity + monster1.getAtts().strength);

				// Make the maximum of target roll to 17.
				if (targetRoll > 17)
				{
					targetRoll = 17;
				}
				// Make the minimum of target roll to 3.
				if (targetRoll < 3)
				{
					targetRoll = 3;
				}

				// Get if the dice roll is the same as the target roll.
				bool hit = targetRoll >= diceRoll(1, 20);

				// If the dice roll doesn't equal the target roll.
				if (!hit)
				{
					cout << "Missed!\n";
				}

				switch (inputs)
				{
					case 'a':
					case 'A':
						// If the dice roll matches the target roll or is higher than it.
						if (hit)
						{
							// Set the damage pre-roll
							int dice = atts.strength + weapon + masteries;
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							// For now output the damage.
							cout << "\nBasic Attack (F): " << damage;
						}
						break;
					case 'f':
					case 'F':
						// If the dice roll matches the target roll or is higher than it
						// and the player's mana is greater than or equal to one.
						if (hit && mp >= 1)
						{
							// Set the damage pre-roll and since it is a higher damage attack
							// then double the attack.
							int dice = 2 * (atts.strength + weapon + masteries);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							// For now output the damage.
							cout << "\nFrenzy Attack (F): " << damage;
							// Since this is a special attack then remove some mana points.
							mp -= 1;
						}
						break;
					case 'd':
					case 'D':
						// If the dice roll matches the target roll or is higher than it
						// and the player's mana is greater than or equal to five.
						if (hit && mp >= 5)
						{
							// Set the damage pre-roll and since this is a deadly attack
							int dice = 100 * (atts.strength + weapon + masteries);
							damage = diceRoll(dice, 6) - dice;
							cout << "\nDeadly Strike Attack (F): " << damage;
							mp -= 5;
						}
						break;
					default:
						reroll = true; // If the input is not valid restart the loop.
				}
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

			hpMax = hp = diceRoll(7, 6); // Set the default hitpoints for the cleric.
			mpMax = mp = 50; // Set the default stamina for the cleric.
		}
};

// Class for the Rouge.
class rouge : public character
{
	public:
		// Create the rogue class.
		rouge()
		{
			cout << "Rouge Created.\n";

			hpMax = hp = diceRoll(7, 6); // Set the default hitpoints for the rouge.
			mpMax = mp = 20; // Set the default stamina for the rouge.
		}
};

// Class for the Bard.
class bard : public character
{
	public:
		// Create the bard class.
		bard()
		{
			cout << "Bard Created.\n";

			hpMax = hp = diceRoll(5, 6); // Set the default hitpoints for the bard.
			mpMax = mp = 50; // Set the default stamina for the bard.
		}
};

// Class for the Tinker.
class tinker : public character
{
	public:
		tinker()
		{
			// Create the tinker class.
			cout << "Tinker Created.\n";

			hpMax = hp = diceRoll(5, 6); // Set the default hitpoints for the tinker.
			mpMax = mp = 20; // Set the default stamina for the tinker.
		}
};

// Class for the Mage.
class mage : public character
{
	public:
		// Create the mage class.
		mage()
		{
			cout << "Mage Created.\n";

			hpMax = hp = diceRoll(3, 6); // Set the default hitpoints for the mage.
			mpMax = mp = 50; // Set the default mana for the mage.
		}
};

void writeToFile ()
{

}

void getFromFile (char *file)
{
	ifstream myfile (file, ifstream::binary);
	
	myfile.seekg(0, myfile.end);
	long size = myfile.tellg();
	myfile.seekg(0);
	
	char *buffer = new char[size];

	if (myfile.is_open())
	{
		while (myfile.read(buffer, size))
		{
			cout << buffer << "\n";
		}

		myfile.close();
	}
	else
	{
		cout << "Unable to read file";
	}
}

// Startup
int _tmain (int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	RACE inputRace; // The race that is chosen.
	char inputs; // The inputs.
	ATTRIBUTES tmpStats; // The stats the player gets by random.
	bool reroll = true; // The bool for rerolling.
	OCC inputClass; // The class that is chosen.
	bool retry = true; // The fix for the race chooser.
	bool iQuit = false; // To tell if the player want to quit the game.
	bool newGame = true; 

	// Set the character to pointer var.
	character *player1;

	// Clear the console.
	system("cls");

	cout << "Welcome to Zoro\n";

	cout << "[N]ew game?\t\t[L]oad Game?\n";


	while (reroll == true)
	{
		cin >> inputs;

		reroll = false;

		switch (inputs)
		{
			case 'n':
			case 'N':
				newGame = true;
				break;
			case 'l':
			case 'L':
				newGame = false;
				break;
			default:
				reroll = true;
				break;
		}
	}
	
	if (newGame == true)
	{
		reroll = true;

		// Check for the reroll
		while (reroll == true)
		{
			// End the reroll;
			reroll = false;

			cout << "\n";
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

			// Reset the reroll to default for the second reroll.
			reroll = true;
		}

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
	}
	else if (newGame == false)
	{
		getFromFile("save1.sav");
	}

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