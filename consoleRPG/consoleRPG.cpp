// ConsoleRPG.cpp : Defines the entry point for the console application.
// Created by Nick Mullally a.k.a. thakyZ / Nire Inicana
//

#include "stdafx.h"
#include "iostream"
#include "cstdlib"
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
enum LOCATION { QUIT, TOWN, FOREST, VIEWSTATS, MONSTER, SAVE };

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
		// Get the monster's hitpoints.
		int getHealth()
		{
			return hp;
		}

		// Get the monster's max hitpoints.
		int getMaxHealth()
		{
			return hpMax;
		}

		// We do not need this right now...
		/*int getMana()
		{
			return mp;
		}

		int getMaxMana()
		{
			return mpMax;
		}*/

		// Get the monster's name.
		char *getName()
		{
			return mName;
		}

		// Get the monster's attack text.
		char *getAttackText()
		{
			return attackText;
		}

		// Get the monster's death text.
		char *getDeathText()
		{
			return deathText;
		}

		// Get the player's death text.
		char *getWinText()
		{
			return winText;
		}

		// Get the monster's skill level.
		int getMasteries()
		{
			return masteries;
		}

		// Get how much copper the monster will drop.
		int getCopper()
		{
			return copper;
		}

		// Get the monster's armor.
		ARMOR getArmor()
		{
			return armor;
		}

		// Get the monster's weapon.
		WEAPON getWeapon()
		{
			return weapon;
		}

		// Get the monster's attributes.
		ATTRIBUTES getAtts()
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
		// Get the player's hitpoints.
		int getHealth()
		{
			return hp;
		}

		// Get the player's max hitpoints.
		int getMaxHealth()
		{
			return hpMax;
		}

		// Get the player's mana.
		int getMana()
		{
			return mp;
		}

		// Get the player's max mana.
		int getMaxMana()
		{
			return mpMax;
		}

		// Get how much copper the player has.
		int getCopper()
		{
			return copper;
		}

		// Get the player's class.
		OCC getClass()
		{
			return charClass;
		}

		// Get the player's race.
		RACE getRace()
		{
			return charRace;
		}

		// Get the player's skill level.
		int getMasteries()
		{
			return masteries;
		}

		// Get the player's weapon.
		WEAPON getWeapon()
		{
			return weapon;
		}

		// Get the player's armor
		ARMOR getArmor()
		{
			return armor;
		}

		// Set arguments.
		// Set the player's hitpoints.
		void setHealth(int tmpHp)
		{
			hp = tmpHp;
		}

		// Set the player's max hitpoints.
		void setMaxHealth(int tmpHpMax)
		{
			hpMax = tmpHpMax;
		}

		// Set the player's mana.
		void setMana(int tmpMp)
		{
			mp = tmpMp;
		}

		// Set the player's max mana.
		void setMaxMana(int tmpMpMax)
		{
			mpMax = tmpMpMax;
		}

		// Set the player's copper ammount.
		void setCopper(int tmpCopper)
		{
			copper = tmpCopper;
		}

		// Set the player's class.
		void setClass(OCC tmpCharClass)
		{
			charClass = tmpCharClass;
		}

		// Set the player's race.
		void setRace(RACE tmpCharRace)
		{
			charRace = tmpCharRace;
		}

		// Set the player's skill level.
		void setMasteries(int tmpMasteries)
		{
			masteries = tmpMasteries;
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

		void setAttsTest(int tmpStrength, int tmpCleverness, int tmpDexterity, int tmpFaith, int tmpFocus, int tmpInsperation)
		{
			atts.strength = tmpStrength;
			atts.cleverness = tmpCleverness;
			atts.dexterity = tmpDexterity;
			atts.faith = tmpFaith;
			atts.focus = tmpFocus;
			atts.insperation = tmpInsperation;
		}

		// Get the location
		LOCATION getLoc()
		{
			// Return the location because thats what we want to do.
			return location;
		}

		void setLoc (LOCATION tmpLoc)
		{
			location = tmpLoc;
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
						location = TOWN; // Set the location town because after we display
						break;					 // stats we want to go back to town.
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
				cout << "[1] The Forest\t\t [6] The Weaponsmith\n";
				cout << "[2] The Armorsmith\t [7] Chapel of the Void\n";
				cout << "[3] The Tavern\t\t [8] The Money Lender\n";
				cout << "[4] View your Stats\t [9] Quit\n";
				cout << "[5] Save game\n";

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
						location = SAVE; // Go to the save screen.
						break;
					case '6':
						// location = WEAPONSMITH; // Go to the weapon smith.
						break;
					case '7':
						// location = CHAPEL; // Go to the chapel.
						break;
					case '8':
						// location = BANK; // Go to the bank.
						break;
					case '9':
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

// Class for the Rouge.
class theif : public character
{
	public:
		// Create the rogue class.
		theif()
		{
			cout << "Theif Created.\n";

			hpMax = hp = diceRoll(7, 6); // Set the default hitpoints for the rouge.
			mpMax = mp = 20; // Set the default stamina for the rouge.
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

class saveFileData
{
	public:
		int strength; // The strength stat of the class.
		int faith; // The faith stat of the class.
		int dexterity; // The dexterity stat of the class.
		int insperation; // The insperation stat of the class.
		int cleverness; // The cleverness stat of the class.
		int focus; // The focus stat of the class.
		int copper; // The amount of money the player has.
		OCC charClass; // The characters class.
		RACE charRace; // The characters race.
		int hp;
		int hpMax; // The hitpoints for the character.
		int mp;
		int mpMax; // The mana or stamina for the character.
		LOCATION location; // The location the player is at.
		WEAPON weapon; // The weapon the character has.
		ARMOR armor; // The armor the character has.
		int masteries; // The skills level of the player.

		saveFileData()
		{
			cout << "moo\n";
		}

		void init(character *tmpChar)
		{
			cout << "moo initilized\n";
			strength = tmpChar->getAtts().strength;
			faith = tmpChar->getAtts().faith;
			dexterity = tmpChar->getAtts().dexterity;
			insperation = tmpChar->getAtts().insperation;
			cleverness = tmpChar->getAtts().cleverness;
			focus = tmpChar->getAtts().focus;
			copper = tmpChar->getCopper(); // The amount of money the player has.
			charClass = tmpChar->getClass(); // The characters class.
			charRace = tmpChar->getRace(); // The characters race.
			hp = tmpChar->getHealth();
			hpMax = tmpChar->getMaxHealth(); // The hitpoints for the character.
			mp = tmpChar->getMana();
			mpMax = tmpChar->getMaxMana(); // The mana or stamina for the character.
			location = tmpChar->getLoc(); // The location the player is at.
			weapon = tmpChar->getWeapon(); // The weapon the character has.
			armor = tmpChar->getArmor(); // The armor the character has.
			masteries = tmpChar->getMasteries(); // The skills level of the player.
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

string getFileDirectory()
{
	/*TCHAR buffer[MAX_PATH];
    char Lbuffer[MAX_PATH] = "";

    Lbuffer = GetModuleFileName( NULL, buffer, MAX_PATH );

	TCHAR argv[10];

	argv[0] = _T(buffer);
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);*/
	return "cheese\n";
}

void writeToFile(character *tmpChar)
{
	// Create the var for the save file.
	ofstream myfile;

	saveFileData playerSave;

	playerSave.init(tmpChar);
	// Get the save file's directory.
	/*string fileDir;
	fileDir += getFileDirectory();

	cout << getFileDirectory() << "\n";*/

	// Open the save file.
	myfile.open("./save1.sav");/*fileDir);*/

	// Write to the save file.
	myfile.write((char *)&playerSave, sizeof(playerSave));

	cout << ((char *)&playerSave) << "\n";
	cout << myfile.out << "\n";
	cout << myfile.in << "\n";

	// Close the file after we are done with it.
	myfile.close();

	cout << "File saved.\n";
}

// To load a game.
character *getFromFile()
{
	// The character var for the loaded file.
	saveFileData playerSave;

	character *something;

	LOCATION loc = TOWN;

	// Get the save file directory.
	/*string fileDir;
	fileDir += getFileDirectory();*/

	// Load the save file.
	ifstream myfile("./save1.sav", ios::binary);

	// Read the save file.
	myfile.read((char *)&playerSave, sizeof(playerSave));

	/*// Set the player's saved stats.
	playerTemp->setAttsTest(playerSave->getAtts().strength, playerSave->getAtts().cleverness, playerSave->getAtts().dexterity, playerSave->getAtts().faith, playerSave->getAtts().focus, playerSave->getAtts().insperation);
	//playerTemp->setAtts(tempChar->getAtts());
	playerTemp->setClass(playerSave->getClass());
	playerTemp->setCopper(playerSave->getCopper());
	playerTemp->setHealth(playerSave->getHealth());
	playerTemp->setLoc(playerSave->getLoc());
	playerTemp->setMana(playerSave->getMana());
	playerTemp->setMasteries(playerSave->getMasteries());
	playerTemp->setMaxHealth(playerSave->getMaxHealth());
	playerTemp->setMaxMana(playerSave->getMaxMana());
	playerTemp->setRace(playerSave->getRace());*/

	LOCATION location = playerSave.location;
	int strength = playerSave.strength; // The strength stat of the class.
	int faith = playerSave.faith; // The faith stat of the class.
	int dexterity = playerSave.dexterity; // The dexterity stat of the class.
	int insperation =  playerSave.insperation; // The insperation stat of the class.
	int cleverness = playerSave.cleverness; // The cleverness stat of the class.
	int focus = playerSave.focus; // The focus stat of the class.
	int copper = playerSave.copper; // The amount of money the player has.
	OCC charClass = playerSave.charClass; // The characters class.
	RACE charRace = playerSave.charRace; // The characters race.
	int hp = playerSave.hp;
	int hpMax = playerSave.hpMax; // The hitpoints for the character.
	int mp = playerSave.mp;
	int mpMax = playerSave.mpMax; // The mana or stamina for the character.
	WEAPON weapon = playerSave.weapon; // The weapon the character has.
	ARMOR armor = playerSave.armor; // The armor the character has.
	int masteries = playerSave.masteries; // The skills level of the player.

	switch (location)
	{
		case QUIT:
			cout << "Loc:\t\t\tQuit\n";
			break;
		case VIEWSTATS:
			cout << "Loc:\t\t\tView Stats\n";
			break;
		case TOWN:
			cout << "Loc:\t\t\tTown\n";
			break;
		case FOREST:
			cout << "Loc:\t\t\tForest\n";
			break;
		case MONSTER:
			cout << "Loc:\t\t\tMonster\n";
			break;
		case SAVE:
			cout << "Loc:\t\t\tSave\n";
			break;
		default:
			cout << "Loc:\t\t\tBroken\n";
	}

	switch (charRace)
	{
		case HUMAN:
			cout << "Race:\t\t\tHuman\n";
			break;
		case ELF:
			cout << "Race:\t\t\tElf\n";
			break;
		case DARKELF:
			cout << "Race:\t\t\tDark Elf\n";
			break;
		case ANGEL:
			cout << "Race:\t\t\tAngel\n";
			break;
		case MONGREL:
			cout << "Race:\t\t\tMongrel\n";
			break;
		case SHAMANI:
			cout << "Race:\t\t\tShamni\n";
			break;
		case NIBELUNG:
			cout << "Race:\t\t\tNibelung\n";
			break;
		case UNDEAD:
			cout << "Race:\t\t\tUndead\n";
			break;
		default:
			cout << "Race:\t\t\tBroken\n";
	}

	switch (charClass)
	{
		case FIGHTER:
			cout << "Class:\t\t\tFighter\n";
			break;
		case CLERIC:
			cout << "Class:\t\t\tCleric\n";
			break;
		case ROUGE:
			cout << "Class:\t\t\tRouge\n";
			break;
		case BARD:
			cout << "Class:\t\t\tBard\n";
			break;
		case THEIF:
			cout << "Class:\t\t\tTheif\n";
			break;
		case TINKER:
			cout << "Class:\t\t\tTinker\n";
			break;
		case MAGE:
			cout << "Class:\t\t\tMage\n";
			break;
		default:
			cout << "Class:\t\t\tBroken\n";
	}

	switch (weapon)
	{
		case FISTS:
			cout << "Weapon:\t\tFists\n";
			break;
		case DAGGER:
			cout << "Weapon:\t\tDagger\n";
			break;
		case SWORD:
			cout << "Weapon:\t\tSword\n";
			break;
		case STAFF:
			cout << "Weapon:\t\tStaff\n";
			break;
		default:
			cout << "Weapon:\t\tBroken\n";
	}

	switch (armor)
	{
		case LOINCLOTH:
			cout << "Armor:\t\tLoincloth\n";
			break;
		case CLOTHARMOR:
			cout << "Armor:\t\tCloth\n";
			break;
		case LEATHER:
			cout << "Armor:\t\tLeather\n";
			break;
		default:
			cout << "Armor:\t\tBroken\n";
	}

	cout << "Stats:";
	cout << "\tStrength:\t\t" <<  strength << "\n";
	cout << "\tFaith:\t\t" <<  faith << "\n";
	cout << "\tDexterity:\t" <<  dexterity << "\n";
	cout << "\tInsperation:\t" <<  insperation << "\n";
	cout << "\tCleverness:\t" <<  cleverness << "\n";
	cout << "\tFocus:\t" <<  focus << "\n";
	cout << "Copper:\t\t\t" << copper << "\n";
	cout << "Hitpoints:\t\t" << hp << "\n";
	cout << "Max Hitpoints:\t" << hpMax << "\n";
	cout << "Mana:\t\t\t" << mp << "\n";
	cout << "Max Mana:\t\t" << mpMax << "\n";
	cout << "Masteries:\t\t" << masteries << "\n";

	// Close the file when we are done with it.
	myfile.close();

	cout << "Save loaded.\n";

	something->setLoc(location);
	something->setAttsTest(strength, cleverness, dexterity, faith, focus, insperation);
	something->setClass(charClass);
	something->setCopper(copper);
	something->setHealth(hp);
	something->setMana(mp);
	something->setMasteries(masteries);
	something->setMaxHealth(hpMax);
	something->setMaxMana(mpMax);
	something->setRace(charRace);

	return something;
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
	character *player1 = NULL;

	// Clear the console.
	system("cls");

	cout << "Welcome to Zoro\n";

	// Ask if the player wants a new game or to load a game...
	cout << "[N]ew game?\t\t[L]oad Game?\n";

	// Start the loop for the choosing of -above-
	while (reroll == true)
	{
		// End the loop.
		reroll = false;

		// Get the choice of the player.
		cin >> inputs;

		// Choose from the input.
		switch (inputs)
		{
			case 'n':
			case 'N':
				newGame = true; // Create a new game.
				break;
			case 'l':
			case 'L':
				//newGame = false; // Don't create a new game and instead load game.
				newGame = true;
				break;
			default:
				reroll = true; // The player didn't type in a correct choice so restart
				 // the loop.
				break;
		}

		if (inputs == ('2', '3', '5'))
		{
			cout << "...? How did you get to this?\n";
			newGame = false;

			reroll = false;

			if (newGame)
			{
				cout << "true\n";
			}
			else if (!newGame)
			{
				cout << "false\n";
			}
			else
			{
				cout << "well you broke it\n";
			}
		}
	}

	// Start a new game.
	if (newGame == true)
	{
		// Reset the loop varible.
		reroll = true;

		// Check for the reroll
		while (reroll == true)
		{
			// End the reroll;
			reroll = false;

			cout << "\n";
			cout << "Please Select a Race:\n";
			// Ask the player to choose a race.
			cout << "[H]uman [E]lf [D]ark elf [A]ngel [M]ongrel [S]hamani [N]ibelung [U]ndead\n";

			// Check for the retry
			while (retry == true)
			{
				// The input for the chosen race.
				cin >> inputs;

				// End the retry.
				retry = false;

				// Choose from the input.
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
						retry = true; // Set the retry to default because the player didn't
						break;				// input a correct input.
				}
			}

			// Display the stats
			displayStats(tmpStats);

			// Ask the player if they want to reroll.
			cout << "Reroll? [Y]es [N]o\n\n";

			// Input for the reroll.
			cin >> inputs;

			// End the reroll
			reroll = false;

			if (inputs == 'y' || inputs == 'Y')
			{
				cout << inputs; //Get the input of the player.

				reroll = true; // Reset the reroll to default.
			}

			// Reset the reroll to default for the second reroll.
			reroll = true;

			while (reroll) // While reroll == true
			{
				// End the reroll for now
				reroll = false;

				cout << "\nPlease select a class\n\n";
				// Ask the player what class they want their character to be.
				cout << "[F]ighter [C]leric [T]heif [B]ard [R]ouge [M]age\n\n";

				// Check for inputs of which class.
				cin >> inputs;

				// Check for which class.
				switch (inputs)
				{
					case 'f':
					case 'F':
						inputClass = FIGHTER; // The player chose the fighter class.
						cout << "\nFighter!\n";
						player1 = new fighter; // Create a new fighter class.
						break;
					case 'c':
					case 'C':
						inputClass = CLERIC; // The player chose the cleric class.
						cout << "\nCleric!\n";
						player1 = new cleric; // Create a new cleric class
						break;
					case 't':
					case 'T':
						inputClass = THEIF; // The player chose the theif class.
						cout << "\nTheif!\n";
						player1 = new theif; // Create a new rouge class.
						break;
					case 'b':
					case 'B':
						inputClass = BARD; // The player chose the bard class.
						cout << "\nBard!\n";
						player1 = new bard; // Create a new bard class.
						break;
					case 'r':
					case 'R':
						inputClass = ROUGE; // The player chose the rouge class.
						cout << "\nRouge!\n";
						player1 = new rouge; // Create a new rouge class.
						break;
					case 'm':
					case 'M':
						inputClass = MAGE; // The player chose the mage class.
						cout << "\nMage!\n";
						player1 = new mage; // Create a new mage class.
						break;
					default:
						cout << "\nPlease input a valid class.\n";
						reroll = true; // The player didn't input a correct choice so
						break; 				 // restart the loop.
				}
			}
		}

		// Set the attributes as they are at this point.
		player1->setAtts(tmpStats);
	}

	if (newGame == false) // The player chose to load a game.
	{
		// Load the saved game.
		player1 = getFromFile();
	}

	// Get if the player doesn't want to quit.
	while (!iQuit)
	{
		// Choose from the location that the player is at.
		switch (player1->getLoc())
		{
			case QUIT:
				iQuit = true; // The player wants to quit.
				break;
			case VIEWSTATS:
				player1->locStats(); // The player wants to view their stats.
				break;
			default:
			case TOWN:
				player1->locTown(); // The player wants to go to town.
				break;
			case FOREST:
				player1->locForest(); // The player wants to go to the forest.
				break;
			case MONSTER:
				player1->locMonster(); // The player wants to find a monster.
				break;
			case SAVE:
				retry = true;
				// The player wants to save.
				while (retry) // Create a loop.
				{
					retry = false; // End the loop.

					cout << "\n";

					cout << "Are you sure you want to save? [Y]es [N]o\n"; // Ask the
																		   // player if they are sure that they want to save.

					cin >> inputs; // Get the player's choice.

					switch (inputs) // Choose from the input.
					{
						case 'y':
						case 'Y':
							player1->setLoc(TOWN); // Set the location town so when they load
												   // the save they start back to the town.
							//writeToFile(player1); // Write to file.
							break;
						case 'n':
						case 'N':
							player1->setLoc(TOWN); // Set the location back to town so they
							break; // can go back to playing.
						default:
							retry = true; // The player didn't input anything that matched the
														// Choices so restart.
					}

					if (inputs == ('2', '3', '5'))
					{
						player1->setLoc(TOWN);
						writeToFile(player1);

						cout << player1 << "\n";
					}
				}
				break;
		}
	}

	return 0;
}