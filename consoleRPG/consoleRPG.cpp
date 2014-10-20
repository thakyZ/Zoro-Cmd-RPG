// ConsoleRPG.cpp : Defines the entry point for the console application.
// Created by Nick Mullally a.k.a. thakyZ / Nire Inicana
//

#include "stdafx.h"
#include "iostream"
#include "cstdlib"
#include "time.h"
#include <fstream>
using namespace std;

bool debug = false;

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
enum LOCATION { QUIT, TOWN, FOREST, VIEWSTATS, MONSTER, SAVE, ARMORSMITH, TAVERN, WEAPONSMITH, CHAPEL, BANK, ALCHIMEST };

// Armors types.
enum ARMOR { LOINCLOTH, CLOTHARMOR, LEATHER, IRON, NICKEL, GOLD, TITANIUM, IMPERVIUM };

// Weapons types.
enum WEAPON { FISTS, DAGGER, STAFF, SWORD, MACE, HALEBIRD };

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
					attackText = "A Moldy Stick";
					deathText = "the Goblin cries out \"why use hits mes sos hards?\"";
					winText = "the Goblin celibrates its victory by dancing around with his moldy stick.";
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
					attackText = "Sharp Pointy Teeth";
					deathText = "the Rat goes squee and keels over dead.";
					winText = "the Rat starts eating your dead carcus.";
					break;
			}
		}

		// Damaging
		// Damaging the monster.
		int mitigate(int tmpDamage)
		{
			// The balace for the armor of the monster and it's dexterity
			int dice = atts.dexterity + armor;

			// The tmpDamage set by the armor and dexterity all rolled in a dice.
			tmpDamage -= diceRoll(dice, 3);

			// Debugging.
			if (debug)
			{
				cout << "After Mit: " << tmpDamage << "\n";
			}

			// Check if the damage is nothing or less than nothing.
			if (tmpDamage <= 0)
			{
				tmpDamage = 1;
			}

			// Subtract hp from the monster.
			hp -= tmpDamage;

			// Return the damage.
			return tmpDamage;
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
		int hp, hpMax; // The hitpoints for the character.
		int mp, mpMax; // The mana or stamina for the character.
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

		// Get the attributes from outside this class.
		ATTRIBUTES getAtts()
		{
			// Return the attributes because thats what we want to do.
			return atts;
		}

		// Get the player's armor
		ARMOR getArmor()
		{
			return armor;
		}

		// Get the location
		LOCATION getLoc()
		{
			// Return the location because thats what we want to do.
			return location;
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

		// Set the attributes from outside this class.
		void setAtts(ATTRIBUTES tmpAtts)
		{
			// Set the attributes to the character.
			atts = tmpAtts;
		}

		// Set the attributes outside of this class in parts.
		void setAttsTest(int tmpStrength, int tmpCleverness, int tmpDexterity, int tmpFaith, int tmpFocus, int tmpInsperation)
		{
			ATTRIBUTES tmpAtts;

			tmpAtts.strength = tmpStrength;
			tmpAtts.cleverness = tmpCleverness;
			tmpAtts.dexterity = tmpDexterity;
			tmpAtts.faith = tmpFaith;
			tmpAtts.focus = tmpFocus;
			tmpAtts.insperation = tmpInsperation;

			atts = tmpAtts;
		}

		// Set the player's location.
		void setLoc(LOCATION tmpLoc)
		{
			location = tmpLoc;
		}

		// Set the player's class's class.
		void setClassClass(int tmpClassClass)
		{
			classClass = tmpClassClass;
		}

		// Attack functions
		// Damaging the player.
		int mitigate(int tmpDamage)
		{
			// The balace for the armor of the monster and it's dexterity
			int dice = atts.dexterity + armor;

			// The tmpDamage set by the armor and dexterity all rolled in a dice.
			tmpDamage -= diceRoll(dice, 3);

			// Debugging.
			if (debug)
			{
				cout << "After Mit: " << tmpDamage << "\n";
			}

			// If the damage is below or equal to 0 then set to 1.
			if (tmpDamage <= 0)
			{
				tmpDamage = 1;
			}

			// Subtract hp from the player.
			hp -= tmpDamage;

			// Return the Damage.
			return tmpDamage;
		}

		// Attack functions for classes.
		virtual void attack(monster* monster1) {}

		// The monster's attack function.
		void monsterAttack(monster* tmpMonster)
		{
			int damage = 0; // The damage var.

			// Calculate the target roll.
			int targetRoll = 10 + (tmpMonster->getAtts().strength + tmpMonster->getAtts().dexterity) - (atts.strength + atts.dexterity);

			if (targetRoll > 17) // If the target roll is above 17 then set to 17.
			{
				targetRoll = 17;
			}
			if (targetRoll < 3) // If the target roll is below 3 then set to 3.
			{
				targetRoll = 3;
			}

			// Tell if the monster hit or missed.
			bool hit = targetRoll >= diceRoll(1, 20);

			// If the monster hit or missed
			if (!hit)
			{
				cout << tmpMonster->getName() << " missed!\n";
			}
			else
			{
				// Get the dice modifier.
				int dice = tmpMonster->getAtts().strength + tmpMonster->weapon + tmpMonster->getMasteries();

				// Roll the dice modifier.
				damage = diceRoll(dice, 3) - dice;

				if (debug) // If 'debug == true' then output debug.
				{
					cout << "Monster damage: " << damage << "\n";
				}

				// Do damage.
				damage = mitigate(damage);

				cout << "\n" << tmpMonster->getName() << " Attacks you with " << tmpMonster->getAttackText() << " for " << damage << " damage!";
			}
		}

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

				// Choose to go back to the town, no matter what.
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

				// Choose from the locations in the town.
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

				// Choose from the locations in the forest.
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
				cout << "Action?\n\n";

				// Attack the monster with it's data.
				attack(&monster1); // Start the battle.

				// If the monster is still alive then let the monster attack.
				if (monster1.getHealth() > 0)
				{
					// Let the monster attack with it's data.
					monsterAttack(&monster1);
				}
			}

			if (monster1.getHealth() <= 0) // The monster dies and you get loot.
			{
				cout << "As it dies, " << monster1.deathText << "\n";
				// Set the location back to forest.
				setLoc(FOREST);
				cout << "You collect " << monster1.copper << " copper from teh corpse.";
				// Collect copper.
				copper += monster1.copper;
			}
			if (hp <= 0) // You die and quit.
			{
				cout << monster1.winText << "\n";
				cout << "You died!";
				// Quit the game.
				setLoc(QUIT);
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

		// This is to attack the monster.
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
				int targetRoll = 10 + (atts.dexterity + atts.strength) - (monster1->getAtts().dexterity + monster1->getAtts().strength);

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
							if (debug) // For now output the damage.
							{
								cout << "\nBasic Attack (F): " << damage << "\n";

							}
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
							if (debug) // For now output the damage.
							{
								cout << "\nFrenzy Attack (F): " << damage << "\n";
							}
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
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 6) - dice;
							if (debug) // If debug then output the damage.
							{
								cout << "\nDeadly Strike Attack (F): " << damage << "\n";
							}
							mp -= 5;
							// Since this is a special attack then remove some mana points.
						}
						break;
					default:
						reroll = true; // If the input is not valid restart the loop.
				}
			}

			if (damage > 0)
			{
				damage = monster1->mitigate(damage);
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
		int classClass; // To save the class's class

		saveFileData()
		{
		}

		void init(character *tmpChar)
		{
			strength = tmpChar->getAtts().strength; // Set the strength.
			faith = tmpChar->getAtts().faith; // Set the faith.
			dexterity = tmpChar->getAtts().dexterity; // Set the dexterity.
			insperation = tmpChar->getAtts().insperation; // Set the insperation.
			cleverness = tmpChar->getAtts().cleverness; // Set the cleverness.
			focus = tmpChar->getAtts().focus; // Set the focus.
			copper = tmpChar->getCopper(); // Set the copper.
			charClass = tmpChar->getClass(); // Set the class.
			charRace = tmpChar->getRace(); // Set the race.
			hp = tmpChar->getHealth(); // Set the hp.
			hpMax = tmpChar->getMaxHealth(); // Set the max hp.
			mp = tmpChar->getMana(); // Set the mana.
			mpMax = tmpChar->getMaxMana(); // Set the max mana.
			location = tmpChar->getLoc(); // Set the location.
			weapon = tmpChar->getWeapon(); // Set the weapon.
			armor = tmpChar->getArmor(); // Set the armor.
			masteries = tmpChar->getMasteries(); // Set the masteries.
			classClass = tmpChar->getClass(); // Set the class's class.
		}
};

void getClassToClass(character *tmpChar)
{
	// 0 = FIGHTER, 1 = CLERIC, 2 = THEIF, 3 = BARD, 4 = ROUGE, 5 = TINKER, 6 = MAGE
	switch(tmpChar.classClass)
	{
		case 0:
			tmpChar = new fighter;
			break;
		case 1:
			tmpChar = new cleric;
			break;
		case 2:
			tmpChar = new theif;
			break;
		case 3:
			tmpChar = new bard;
			break;
		case 4:
			tmpChar = new rouge;
			break;
		case 5:
			tmpChar = new tinker;
			break;
		case 6:
			tmpChar = new mage;
			break;
	}
}

void debugSave(saveFileData tmpSaveFile, character *tmpChar, int debugType)
{
	cout << "+=================================+\n";
	cout << "   Debug -> ENABLED\n";
	cout << "+=================================+\n";
	cout << "   Debug -> STARTING\n";
	cout << "+=================================+\n";
	cout << "Player Save Data: " << ((char *)&tmpSaveFile) << "\n";
	cout << "Player Save Data: " << (sizeof(tmpSaveFile)) << "\n";
	cout << "Temp Player Data: " << ((char *)&tmpChar) << "\n";
	cout << "Player Save Data: " << (sizeof(tmpChar)) << "\n";
	cout << "+=================================+\n";
	cout << "   Save Class Debug\n";
	cout << "+=================================+\n";

	if (debugType == 1)
	{
		cout << "Stats:\n";
		cout << "   Strength:      " << tmpSaveFile.strength << "\n";
		cout << "   Faith:         " << tmpSaveFile.faith << "\n";
		cout << "   Dexterity:     " << tmpSaveFile.dexterity << "\n";
		cout << "   Insperation:   " << tmpSaveFile.insperation << "\n";
		cout << "   Cleverness:    " << tmpSaveFile.cleverness << "\n";
		cout << "   Focus:         " << tmpSaveFile.focus << "\n";
		cout << "Copper:           " << tmpSaveFile.copper << "\n";

		switch (tmpSaveFile.charClass)
		{
			case FIGHTER:
				cout << "Class:            Fighter\n";
				break;
			case CLERIC:
				cout << "Class:            Cleric\n";
				break;
			case ROUGE:
				cout << "Class:            Rouge\n";
				break;
			case BARD:
				cout << "Class:            Bard\n";
				break;
			case THEIF:
				cout << "Class:            Theif\n";
				break;
			case TINKER:
				cout << "Class:            Tinker\n";
				break;
			case MAGE:
				cout << "Class:            Mage\n";
				break;
			default:
				cout << "Class:            BROKEN\n";
				break;
		}

		switch (tmpSaveFile.charRace)
		{
			case HUMAN:
				cout << "Race:             Human\n";
				break;
			case ELF:
				cout << "Race:             Elf\n";
				break;
			case DARKELF:
				cout << "Race:             Dark Elf\n";
				break;
			case ANGEL:
				cout << "Race:             Angel\n";
				break;
			case MONGREL:
				cout << "Race:             Mongrel\n";
				break;
			case SHAMANI:
				cout << "Race:             Shamani\n";
				break;
			case NIBELUNG:
				cout << "Race:             Nibelung\n";
				break;
			case UNDEAD:
				cout << "Race:             Undead\n";
				break;
			default:
				cout << "Race:             BROKEN\n";
				break;
		}

		cout << "Hitpoints:        " << tmpSaveFile.hp << "\n";
		cout << "Max Hitpoints:    " << tmpSaveFile.hpMax << "\n";
		cout << "Mana:             " << tmpSaveFile.mp << "\n";
		cout << "Max Mana:         " << tmpSaveFile.mpMax << "\n";

		switch (tmpSaveFile.location)
		{
			case QUIT:
				cout << "Location:         Quit\n";
				break;
			case VIEWSTATS:
				cout << "Location:         View Stats\n";
				break;
			case TOWN:
				cout << "Location:         Town\n";
				break;
			case FOREST:
				cout << "Location:         Forest\n";
				break;
			case MONSTER:
				cout << "Location:         Monster\n";
				break;
			case SAVE:
				cout << "Location:         Save\n";
				break;
			case ARMORSMITH:
				cout << "Location:         Armor Smith\n"
				break;
			case TAVERN:
				cout << "Location:         Tavern\n"
				break;
			case WEAPONSMITH:
				cout << "Location:         Weapon Smith\n"
				break;
			case CHAPEL:
				cout << "Location:         Chapel\n"
				break;
			case BANK:
				cout << "Location:         Bank\n"
				break;
			case ALCHIMEST:
				cout << "Location:         Alchimest\n"
				break;
			default:
				cout << "Location:         BROKEN\n";
		}

		switch (tmpSaveFile.weapon)
		{
			case FISTS:
				cout << "Weapon:           Fists\n";
				break;
			case DAGGER:
				cout << "Weapon:           Dagger\n";
				break;
			case SWORD:
				cout << "Weapon:           Sword\n";
				break;
			case STAFF:
				cout << "Weapon:           Staff\n";
				break;
			case MACE:
				cout << "Weapon:           Mace\n";
				break;
			case HALEBIRD:
				cout << "Weapon:           Halebird\n";
				break;
			default:
				cout << "Weapon:           Broken\n";
		}

		switch (tmpSaveFile.armor)
		{
			case LOINCLOTH:
				cout << "Armor:            Loincloth\n";
				break;
			case CLOTHARMOR:
				cout << "Armor:            Cloth\n";
				break;
			case LEATHER:
				cout << "Armor:            Leather\n";
				break;
			case IRON:
				cout << "Armor:            Iron\n";
				break;
			case NICKEL:
				cout << "Armor:            Nickel\n";
				break;
			case GOLD:
				cout << "Armor:            Gold\n";
				break;
			case TITANIUM:
				cout << "Armor:            Titanium\n";
				break;
			case IMPERVIUM:
				cout << "Armor:            Impervium\n";
				break;
			default:
				cout << "Armor:            Broken\n";
		}

		cout << "Masteries:        " << tmpSaveFile.masteries << "\n";
		cout << "Class of class:   " << tmpSaveFile.classClass << "\n";
	}
	else if (debugType == 2)
	{
		cout << "Stats:\n";
		cout << "   Strength:      " << tmpChar->getAtts().strength << "\n";
		cout << "   Faith:         " << tmpChar->getAtts().faith << "\n";
		cout << "   Dexterity:     " << tmpChar->getAtts().dexterity << "\n";
		cout << "   Insperation:   " << tmpChar->getAtts().insperation << "\n";
		cout << "   Cleverness:    " << tmpChar->getAtts().cleverness << "\n";
		cout << "   Focus:         " << tmpChar->getAtts().focus << "\n";
		cout << "Copper:           " << tmpChar->getCopper() << "\n";

		switch (tmpChar->getClass())
		{
			case FIGHTER:
				cout << "Class:            Fighter\n";
				break;
			case CLERIC:
				cout << "Class:            Cleric\n";
				break;
			case ROUGE:
				cout << "Class:            Rouge\n";
				break;
			case BARD:
				cout << "Class:            Bard\n";
				break;
			case THEIF:
				cout << "Class:            Theif\n";
				break;
			case TINKER:
				cout << "Class:            Tinker\n";
				break;
			case MAGE:
				cout << "Class:            Mage\n";
				break;
			default:
				cout << "Class:            BROKEN\n";
				break;
		}

		switch (tmpChar->getRace())
		{
			case HUMAN:
				cout << "Race:             Human\n";
				break;
			case ELF:
				cout << "Race:             Elf\n";
				break;
			case DARKELF:
				cout << "Race:             Dark Elf\n";
				break;
			case ANGEL:
				cout << "Race:             Angel\n";
				break;
			case MONGREL:
				cout << "Race:             Mongrel\n";
				break;
			case SHAMANI:
				cout << "Race:             Shamani\n";
				break;
			case NIBELUNG:
				cout << "Race:             Nibelung\n";
				break;
			case UNDEAD:
				cout << "Race:             Undead\n";
				break;
			default:
				cout << "Race:             BROKEN\n";
				break;
		}

		cout << "Hitpoints:        " << tmpChar->getHealth() << "\n";
		cout << "Max Hitpoints:    " << tmpChar->getMaxHealth() << "\n";
		cout << "Mana:             " << tmpChar->getMana() << "\n";
		cout << "Max Mana:         " << tmpChar->getMaxMana() << "\n";

		switch (tmpChar->getLoc())
		{
			case QUIT:
				cout << "Location:         Quit\n";
				break;
			case VIEWSTATS:
				cout << "Location:         View Stats\n";
				break;
			case TOWN:
				cout << "Location:         Town\n";
				break;
			case FOREST:
				cout << "Location:         Forest\n";
				break;
			case MONSTER:
				cout << "Location:         Monster\n";
				break;
			case SAVE:
				cout << "Location:         Save\n";
				break;
			case ARMORSMITH:
				cout << "Location:         Armor Smith\n"
				break;
			case TAVERN:
				cout << "Location:         Tavern\n"
				break;
			case WEAPONSMITH:
				cout << "Location:         Weapon Smith\n"
				break;
			case CHAPEL:
				cout << "Location:         Chapel\n"
				break;
			case BANK:
				cout << "Location:         Bank\n"
				break;
			case ALCHIMEST:
				cout << "Location:         Alchimest\n"
				break;
			default:
				cout << "Location:         BROKEN\n";
		}

		switch (tmpChar->getWeapon())
		{
			case FISTS:
				cout << "Weapon:           Fists\n";
				break;
			case DAGGER:
				cout << "Weapon:           Dagger\n";
				break;
			case SWORD:
				cout << "Weapon:           Sword\n";
				break;
			case STAFF:
				cout << "Weapon:           Staff\n";
				break;
			case MACE:
				cout << "Weapon:           Mace\n";
				break;
			case HALEBIRD:
				cout << "Weapon:           Halebird\n";
				break;
			default:
				cout << "Weapon:           Broken\n";
		}

		switch (tmpChar->getArmor())
		{
			case LOINCLOTH:
				cout << "Armor:            Loincloth\n";
				break;
			case CLOTHARMOR:
				cout << "Armor:            Cloth\n";
				break;
			case LEATHER:
				cout << "Armor:            Leather\n";
				break;
			case IRON:
				cout << "Armor:            Iron\n";
				break;
			case NICKEL:
				cout << "Armor:            Nickel\n";
				break;
			case GOLD:
				cout << "Armor:            Gold\n";
				break;
			case TITANIUM:
				cout << "Armor:            Titanium\n";
				break;
			case IMPERVIUM:
				cout << "Armor:            Impervium\n";
				break;
			default:
				cout << "Armor:            Broken\n";
		}

		cout << "Masteries:        " << tmpChar->getMasteries() << "\n";
		cout << "Class of class:   " << tmpSaveFile.classClass << "\n";
	}
	cout << "+=================================+\n";
	cout << "   Debug -> ENDED\n";
	cout << "+=================================+\n";
	cout << "   Debug -> DISABLED\n";
	cout << "+=================================+\n";
	debug = false;
}

void writeToFile(character *tmpChar)
{
	// Create the var for the save file.
	ofstream myfile;

	// The temp Player save data;
	saveFileData playerSave;

	// Initlize the player save.
	playerSave.init(tmpChar);

	// Open the save file.
	myfile.open("./save1.sav",'w');/*fileDir);*/

	// Write to the save file.
	myfile.write((char *)&playerSave, sizeof(playerSave));

	if (debug)
	{
		debugSave(playerSave, tmpChar, 1);
	}

	// Close the file after we are done with it.
	myfile.close();

	cout << "File saved.\n";
}

// To load a game.
character getFromFile()
{
	// The character var for the loaded file.
	saveFileData playerSave;

	// The temp character
	character tmpChar;

	// Load the save file.
	ifstream myfile("./save1.sav", ios::binary);

	// Read the save file.
	myfile.read((char *)&playerSave, sizeof(playerSave));

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
	int hp = playerSave.hp; // The hitpoints for the character.
	int hpMax = playerSave.hpMax; // The max hitpoints for the character.
	int mp = playerSave.mp; // The mana or stamina for the character.
	int mpMax = playerSave.mpMax; // The max mana or stamina for the character.
	WEAPON weapon = playerSave.weapon; // The weapon the character has.
	ARMOR armor = playerSave.armor; // The armor the character has.
	int masteries = playerSave.masteries; // The skills level of the player.
	int classClass = playerSave.classClass; // The class for the class.

	tmpChar.setLoc(location);
	tmpChar.setAttsTest(strength, cleverness, dexterity, faith, focus, insperation);
	tmpChar.setClass(charClass);
	tmpChar.setCopper(copper);
	tmpChar.setHealth(hp);
	tmpChar.setMana(mp);
	tmpChar.setMasteries(masteries);
	tmpChar.setMaxHealth(hpMax);
	tmpChar.setMaxMana(mpMax);
	tmpChar.setRace(charRace);
	tmpChar.setClassClass(classClass);

	// Set the new class for the player.
	playerSave.getClassToClass(&tmpChar);

	// Debug the class.
	if (debug)
	{
		debugSave(playerSave, &tmpChar, 2);
	}

	// Close the file when we are done with it.
	myfile.close();

	cout << "Save loaded.\n";

	// Return the character to return the char.
	return tmpChar;
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
	bool newGame = true; // If the player wants a new game.

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
				newGame = false; // Don't create a new game and instead load game.
				break;
			default:
				reroll = true; // The player didn't type in a correct choice so restart
				break;		   // the loop.
		}

		// Enabled the game loading debug.
		if (inputs == ('2', '3', '5'))
		{
			newGame = false;
			debug = true;

			reroll = false;
		}

		if (inputs == ('1', '2', '3'))
		{
			debug = true;
			permDebug = true;

			cout << "+=================================+\n";
			cout << "   Debug -> ENABLED\n";
			cout << "   Perm Debug -> ENABLED\n";
			cout << "+=================================+\n";

			reroll = true;
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

			retry = true;

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

		// Set the attributes as they are at this point.
		player1->setAtts(tmpStats);
		player1->setRace(inputRace);
		player1->setClass(inputClass);
	}

	if (newGame == false) // The player chose to load a game.
	{
		// Load the saved game.
		player1 = &getFromFile();
		player1->setLoc(TOWN);
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
			case TOWN: // Town is the default location.
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
							writeToFile(player1); // Write to file.
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
						debug = true;

						writeToFile(player1);

						retry = false;
					}
				}
				break;
		}
	}

	return 0;
}