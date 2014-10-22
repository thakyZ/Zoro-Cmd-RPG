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
enum LOCATION { QUIT, TOWN, FOREST, VIEWSTATS, MONSTER, SAVE, ARMORSMITH, BUYARMOR, SELLARMOR, TAVERN, WEAPONSMITH, BUYWEAPON, SELLWEAPON, CHAPEL, BANK, ALCHIMEST };

// Armors types.
enum ARMOR { LOINCLOTH, CLOTH, LEATHER, CHAIN, PLATE, ANCIENTPLATE, MAGICPLATE, ARCHANEPLATE, IMPERVIUMPLATE };

// Weapons types.
enum WEAPON { FISTS, DAGGER, STAFF, SWORD, ANCIENTBLADE, MAGICBLADE, ARCHANEBLADE, VOIDEXCALIBUR };

// Potions.
enum Potions { HEALTH, MANA, EXP, CHEAT };

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
	cout << "Stats:\n";
	cout << "   Strength:      " << atts.strength << "\n";
	cout << "   Faith:         " << atts.faith << "\n";
	cout << "   Dexterity:     " << atts.dexterity << "\n";
	cout << "   Insperation:   " << atts.insperation << "\n";
	cout << "   Cleverness:    " << atts.cleverness << "\n";
	cout << "   Focus:         " << atts.focus << "\n";
	cout << "\n\n";
}

char *displayWeaponName(int tmpWeapon, int tmpCharClass)
{
	switch (tmpCharClass)
	{
		case 0:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Dagger";
					break;
				case 2:
					return "Staff";
					break;
				case 3:
					return "Sword";
					break;
				case 4:
					return "Ancient Blade";
					break;
				case 5:
					return "Magic Blade";
					break;
				case 6:
					return "Archane Blade";
					break;
				case 7:
					return "Void Excalibur";
					break;
			}
			break;
		case 1:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Cross";
					break;
				case 2:
					return "Long Cross";
					break;
				case 3:
					return "Holy Cross";
					break;
				case 4:
					return "Ancient Cross";
					break;
				case 5:
					return "Magic Cross";
					break;
				case 6:
					return "Archane Cross";
					break;
				case 7:
					return "Void Cross";
					break;
			}
			break;
		case 2:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Rusty Dagger";
					break;
				case 2:
					return "Dagger";
					break;
				case 3:
					return "Barbed Dagger";
					break;
				case 4:
					return "Ancient Dagger";
					break;
				case 5:
					return "Magic Dagger";
					break;
				case 6:
					return "Archane Dagger";
					break;
				case 7:
					return "Void Dagger";
					break;
			}
			break;
		case 3:
			switch (tmpWeapon)
			{
				case 0:
					return "Butter Knife";
					break;
				case 1:
					return "Rusty Sharp Knife";
					break;
				case 2:
					return "Sharp Knife";
					break;
				case 3:
					return "Barbed Knife";
					break;
				case 4:
					return "Ancient Knife";
					break;
				case 5:
					return "Magic Knife";
					break;
				case 6:
					return "Archane Knife";
					break;
				case 7:
					return "Void Long Knife";
					break;
			}
			break;
		case 4:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Rusty Short Blade";
					break;
				case 2:
					return "Short Balde";
					break;
				case 3:
					return "Barbed Short Blade";
					break;
				case 4:
					return "Ancient Short Blade";
					break;
				case 5:
					return "Magic Short Blade";
					break;
				case 6:
					return "Archane Short Blade";
					break;
				case 7:
					return "Void Short Excalibur";
					break;
			}
			break;
		case 5:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Rusty Wrench";
					break;
				case 2:
					return "Wrench";
					break;
				case 3:
					return "Mechanical Wrench";
					break;
				case 4:
					return "Ancient Wrench";
					break;
				case 5:
					return "Magic Wrench";
					break;
				case 6:
					return "Archane Wrench";
					break;
				case 7:
					return "Void Wrench";
					break;
			}
			break;
		case 6:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Dagger";
					break;
				case 2:
					return "Staff";
					break;
				case 3:
					return "Sword";
					break;
				case 4:
					return "Ancient Blade";
					break;
				case 5:
					return "Magic Blade";
					break;
				case 6:
					return "Archane Blade";
					break;
				case 7:
					return "Void Excalibur";
					break;
			}
			break;
		case 7:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Dagger";
					break;
				case 2:
					return "Staff";
					break;
				case 3:
					return "Sword";
					break;
				case 4:
					return "Ancient Staff";
					break;
				case 5:
					return "Magic Staff";
					break;
				case 6:
					return "Archane Staff";
					break;
				case 7:
					return "Void Staff";
					break;
			}
			break;
	}

	return "";
}

char *displayArmorName(int tmpArmor, int tmpCharClass)
{
	switch (tmpCharClass)
	{
		case 0:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			switch (tmpArmor)
			{
				case 0:
					return "Loin Cloth";
					break;
				case 1:
					return "Cloth Armor";
					break;
				case 2:
					return "Leather Armor";
					break;
				case 3:
					return "Chain Armor";
					break;
				case 4:
					return "Plate Armor";
					break;
				case 5:
					return "Ancient Plate Armor";
					break;
				case 6:
					return "Magic Plate Armor";
					break;
				case 7:
					return "Archane Plate Armor";
					break;
				case 8:
					return "Impervium Plate Armor";
					break;
			}
			break;
		case 1:
		case 7:
			switch (tmpArmor)
			{
				case 0:
					return "Loin Cloth";
					break;
				case 1:
					return "Cloth Robe";
					break;
				case 2:
					return "Leather Robe";
					break;
				case 3:
					return "Chain Robe";
					break;
				case 4:
					return "Iron Robe";
					break;
				case 5:
					return "Ancient Robe";
					break;
				case 6:
					return "Magic Robe";
					break;
				case 7:
					return "Archane Robe";
					break;
				case 8:
					return "Impervium Robe";
					break;
			}
			break;
	}

	return "";
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

		// Subtract Health
		void subHealth(int tmpDamage)
		{
			hp -= tmpDamage;
		}

		void addHealth(int tmpDamage)
		{
			hp += tmpDamage;
		}

		// Damaging
		// Damaging the monster.
		int mitigate(int tmpDamage)
		{
			// The balace for the armor of the monster and it's dexterity
			int dice = getAtts().dexterity + getArmor();

			// The tmpDamage set by the armor and dexterity all rolled in a dice.
			tmpDamage -= diceRoll(dice, 3);

			// Debugging.
			if (debug)
			{
				cout << "\n";
				cout << "After Mit: " << tmpDamage << "\n";
			}

			// Check if the damage is nothing or less than nothing.
			if (tmpDamage <= 0)
			{
				tmpDamage = 1;
			}

			// Subtract hp from the monster.
			subHealth(tmpDamage);

			// Return the damage.
			return tmpDamage;
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
		bool cheated; // If the player cheated.

	public:
		// Constructors
		// Create the character class.
		character()
		{
			// Set the default copper.
			copper = 100;

			// Set the default location of the menu.
			location = VIEWSTATS;
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

		// Get the player's armor.
		ARMOR getArmor()
		{
			return armor;
		}

		// Get the location.
		LOCATION getLoc()
		{
			// Return the location because thats what we want to do.
			return location;
		}

		// Get the cheated var.
		bool getCheated()
		{
			return cheated;
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

		// Set the player's armor.
		void setArmor(ARMOR tmpArmor)
		{
			armor = tmpArmor;
		}

		// Set the player's weapon.
		void setWeapon(WEAPON tmpWeapon)
		{
			weapon = tmpWeapon;
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

		void setCheat(bool tmpCheated)
		{
			cheated = tmpCheated;
		}

		// Computing Functions
		// Subtract Health
		void subHealth(int tmpHp)
		{
			hp -= tmpHp;

			if (hp < 0)
			{
				hp = 0;
			}
		}

		// Add Health
		void addHealth(int tmpHp)
		{
			hp += tmpHp;
		}

		// Subtract Copper
		void subCopper(int tmpCopper)
		{
			copper -= tmpCopper;

			if (copper < 0)
			{
				copper = 0;
			}
		}

		// Add Health
		void addCopper(int tmpCopper)
		{
			copper += tmpCopper;

			if (copper >= 25000 && !debug)
			{
				copper = 24999;
			}
		}

		// Subtract Mana
		void subMana(int tmpMp)
		{
			mp -= tmpMp;

			if(mp < 0)
			{
				mp = 0;
			}
		}

		// Add Mana
		void addMana(int tmpMp)
		{
			mp = tmpMp;
		}

		// Attack functions
		// Damaging the player.
		int mitigate(int tmpDamage)
		{
			// The balace for the armor of the player and their dexterity
			int dice = getAtts().dexterity + getArmor();

			// The tmpDamage set by the armor and dexterity all rolled in a dice.
			tmpDamage -= diceRoll(dice, 3);

			// Debugging.
			if (debug)
			{
				cout << "\n";
				cout << "After Mit: " << tmpDamage << "\n";
			}

			// If the damage is below or equal to 0 then set to 1.
			if (tmpDamage <= 0)
			{
				tmpDamage = 1;
			}

			// Subtract hp from the player.
			subHealth(tmpDamage);

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
					cout << "\n";
					cout << "Monster damage: " << damage << "\n";
				}

				// Do damage.
				damage = mitigate(damage);

				cout << "\n";

				cout << tmpMonster->getName() << " Attacks you with " << tmpMonster->getAttackText() << " for " << damage << " damage!";
			}
		}

		// Buying/Selling Functions
		// Function to pawn the item.
		int pawnItem(int item, int sell)
		{
			int tmpGold = 0;

			switch (item)
			{
				case 7:
					tmpGold += 1600;
				case 6:
					tmpGold += 800;
				case 5:
					tmpGold += 400;
				case 4:
					tmpGold += 200;
				case 3:
					tmpGold += 100;
				case 2:
					tmpGold += 50;
				case 1:
					tmpGold += 50;
				default:
					break;
			}

			if (sell == 1)
			{
				addCopper(tmpGold);
			}

			return tmpGold;
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
				cout << "You look yourself over...\n";
				cout << "\n";

				// Display the stats.
				displayStats(getAtts());

				cout << "   Hitpoints:     " << getHealth() << "/" << getMaxHealth() << "\n";
				cout << "   Mana:          " << getMana() << "/" << getMaxMana() << "\n";
				cout << "   Copper:        " << getCopper() << "\n";

				cout << "   Armor:         " << displayArmorName(getArmor(), getClass()) << "\n";

				cout << "   Weapon:        " << displayWeaponName(getWeapon(), getClass()) << "\n";

				cout << "\n";
				cout << "[G]o back to Town\n";

				// Get the input for the menu.
				cin >> menuItem;

				// Choose to go back to the town, no matter what.
				switch (menuItem)
				{
					case 'g':
					case 'G':
						setLoc(TOWN); // Set the location town because after we display
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

				cout << "\n";

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
						setLoc(FOREST); // Go to the forest.
						break;
					case '2':
						setLoc(ARMORSMITH); // Go to the armor smith.
						break;
					case '3':
						setLoc(TAVERN); // Go to the tavern.
						break;
					case '4':
						setLoc(VIEWSTATS); // Go to the view stats screen.
						break;
					case '5':
						setLoc(SAVE); // Go to the save screen.
						break;
					case '6':
						setLoc(WEAPONSMITH); // Go to the weapon smith.
						break;
					case '7':
						setLoc(CHAPEL); // Go to the chapel.
						break;
					case '8':
						setLoc(BANK); // Go to the bank.
						break;
					case '9':
						setLoc(QUIT); // Quit the game.
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

				cout << "\n";

				cout << "You enter the woods near Zoro. It's dark a spoopy, you think you hear some noise in the bushes. You:\n";
				cout << "[1] Look for monsters\t [3] Visit the alchimest\n";
				cout << "[2] Return To town\n";

				// Input for the menu.
				cin >> menuItem;

				// Choose from the locations in the forest.
				switch (menuItem)
				{
					case '1':
						setLoc(MONSTER); // Go find a monster.
						break;
					case '2':
						setLoc(TOWN); // Go to the town.
						break;
					case '3':
						setLoc(ALCHIMEST); // Go to the alchimest.
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
				cout << "\n";
				cout << monster1.getName() << ": " << monster1.getHealth() << "/" << monster1.getMaxHealth() << "\n";
				cout << "You: " << hp << "/" << hpMax << "\n\n";
				cout << "Action?\n";

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
				cout << "As it dies, " << monster1.getDeathText() << "\n";
				// Set the location back to forest.
				setLoc(FOREST);
				cout << "You collect " << monster1.getCopper() << " copper from teh corpse.";
				// Collect copper.
				copper += monster1.getCopper();
			}
			if (hp <= 0) // You die and quit.
			{
				cout << monster1.getWinText() << "\n";
				cout << "You died!";
				// Quit the game.
				setLoc(QUIT);
			}
		}

		// Display armor smith code.
		void locArmorSmith()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";

				cout << "You enter a shop filled with a variaty of armor. Some are made of metal and some are not. Some are enchanted with magic runes. The shop owner asks what is your bussiness:\n";
				cout << "[1] Buy Armor\t [3] Return to town\n";
				cout << "[2] Sell Armor\n";

				// Input for the menu.
				cin >> menuItem;

				// Choose from the locations in the armor smith shop.
				switch (menuItem)
				{
					case '1':
						setLoc(BUYARMOR); // Go buy armor.
						break;
					case '2':
						setLoc(SELLARMOR); // Go sell armor.
						break;
					case '3':
						setLoc(TOWN); // Go back to the town.
						break;
					default:
						reroll = true; // If you do not type in the right input then repeat.
						break;
				}
			}
		}

		// Display sell the armor code.
		void locBuyArmor()
		{
			bool reroll = true; // Check the loop
			int menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";
				cout << "There are many suits of armor on display. Which do you wish to buy?\n";

				cout << "\n";

				switch (getArmor())
				{
					case LOINCLOTH:
						cout << "[1] " << displayArmorName(CLOTH, getClass()) << "\t100 copper\n";
					case CLOTH:
						cout << "[2] " << displayArmorName(LEATHER, getClass()) << "\t200 copper\n";
					case LEATHER:
						cout << "[3] " << displayArmorName(CHAIN, getClass()) << "\t400 copper\n";
					case CHAIN:
						cout << "[4] " << displayArmorName(PLATE, getClass()) << "\t800 copper\n";
					case PLATE:
						cout << "[5] " << displayArmorName(ANCIENTPLATE, getClass()) << "\t1600 copper\n";
					case ANCIENTPLATE:
						cout << "[6] " << displayArmorName(MAGICPLATE, getClass()) << "\t3200 copper\n";
					case MAGICPLATE:
						cout << "[7] " << displayArmorName(ARCHANEPLATE, getClass()) << "\t6400 copper\n";
					default:
						cout << "[8] Back to Shop\n";
				}

				int lowMenu = getArmor() + 1;

				cin >> menuItem;

				cout << "\n";

				if (menuItem < lowMenu)
				{
					menuItem = 9;
				}

				switch (menuItem)
				{
					case 1:
						if (copper >= 100)
						{
							cout << "You buy " << displayArmorName(CLOTH, getClass()) << " for 100 copper\n";
							cout << "You recive the " << displayArmorName(CLOTH, getClass()) << "\n";
							subCopper(100);
							setArmor(CLOTH);
						}
						break;
					case 2:
						if (copper >= 200)
						{
							cout << "You buy " << displayArmorName(LEATHER, getClass()) << " for 200 copper\n";
							cout << "You recive the " << displayArmorName(LEATHER, getClass()) << "\n";
							subCopper(200);
							setArmor(LEATHER);
						}
						break;
					case 3:
						if (copper >= 400)
						{
							cout << "You buy " << displayArmorName(CHAIN, getClass()) << " for 400 copper\n";
							cout << "You recive the " << displayArmorName(CHAIN, getClass()) << "\n";
							subCopper(400);
							setArmor(CHAIN);
						}
						break;
					case 4:
						if (copper >= 800)
						{
							cout << "You buy " << displayArmorName(PLATE, getClass()) << " for 800 copper\n";
							cout << "You recive the " << displayArmorName(PLATE, getClass()) << "\n";
							subCopper(800);
							setArmor(PLATE);
						}
						break;
					case 5:
						if (copper >= 1600)
						{
							cout << "You buy " << displayArmorName(ANCIENTPLATE, getClass()) << " for 1600 copper\n";
							cout << "You recive the " << displayArmorName(ANCIENTPLATE, getClass()) << "\n";
							subCopper(1600);
							setArmor(ANCIENTPLATE);
						}
						break;
					case 6:
						if (copper >= 3200)
						{
							cout << "You buy " << displayArmorName(MAGICPLATE, getClass()) << " for 3200 copper\n";
							cout << "You recive the " << displayArmorName(MAGICPLATE, getClass()) << "\n";
							subCopper(3200);
							setArmor(MAGICPLATE);
						}
						break;
					case 7:
						if (copper >= 6400)
						{
							cout << "You buy " << displayArmorName(ARCHANEPLATE, getClass()) << " for 6400 copper\n";
							cout << "You recive the " << displayArmorName(ARCHANEPLATE, getClass()) << "\n";
							subCopper(6400);
							setArmor(ARCHANEPLATE);
						}
						break;
					case 8:
						setLoc(ARMORSMITH);
						break;
					case 9:
						reroll = true;
						break;
					default:
						break;
				}
			}
		}

		// Display sell the armor code.
		void locSellArmor()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";
				cout << "The armor smith looks over your armor, \"I'll give ya " << pawnItem(getArmor(), 0) << " copper for it! Would you like to buy it?\" [Y]es [N]o\n";

				cin >> menuItem;

				switch (menuItem)
				{
					case 'y':
					case 'Y':
						cout << "You sell your armor for " << pawnItem(getArmor(), 1) << "copper\n";
						setArmor(LOINCLOTH);
						break;
					case 'n':
					case 'N':
					default:
						break;
				}
			}

			setLoc(ARMORSMITH);
		}

		void locWeaponSmith()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n\n";

				cout << "You enter a shop filled with a variaty of armor. Some are made of metal and some are not. Some are enchanted with magic runes. The shop owner asks what is your bussiness:\n";
				cout << "[1] Buy Armor\t [3] Return to town\n";
				cout << "[2] Sell Armor\n";

				// Input for the menu.
				cin >> menuItem;

				// Choose from the locations in the weapon smith shop.
				switch (menuItem)
				{
					case '1':
						setLoc(BUYWEAPON); // Go buy weapons.
						break;
					case '2':
						setLoc(SELLWEAPON); // Go sell weapons.
						break;
					case '3':
						setLoc(TOWN); // Go back to the town.
						break;
					default:
						reroll = true; // If you do not type in the right input then repeat.
						break;
				}
			}
		}

		void locBuyWeapon()
		{
			bool reroll = true; // Check the loop
			int menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";
				cout << "There are many suits of armor on display. Which do you wish to buy?\n";

				cout << "\n";

				switch (getArmor())
				{
					case FISTS:
						cout << "[1] " << displayArmorName(DAGGER, getClass()) << "\t100 copper\n";
					case DAGGER:
						cout << "[2] " << displayArmorName(STAFF, getClass()) << "\t200 copper\n";
					case STAFF:
						cout << "[3] " << displayArmorName(SWORD, getClass()) << "\t400 copper\n";
					case SWORD:
						cout << "[4] " << displayArmorName(ANCIENTBLADE, getClass()) << "\t800 copper\n";
					case ANCIENTBLADE:
						cout << "[5] " << displayArmorName(MAGICBLADE, getClass()) << "\t1600 copper\n";
					case MAGICBLADE:
						cout << "[6] " << displayArmorName(ARCHANEBLADE, getClass()) << "\t3200 copper\n";
					default:
						cout << "[7] Back to Shop";
				}

				int lowMenu = getWeapon() + 1;

				cin >> menuItem;

				if (menuItem < lowMenu)
				{
					menuItem = 8;
				}

				switch (menuItem)
				{
					case 1:
						if (copper >= 100)
						{
							cout << "\n";
							cout << "You buy " << displayArmorName(DAGGER, getClass()) << " for 100 copper\n";
							cout << "You recive the " << displayArmorName(DAGGER, getClass()) << "\n";
							subCopper(100);
							setArmor(CLOTH);
						}
						break;
					case 2:
						if (copper >= 200)
						{
							cout << "\n";
							cout << "You buy " << displayArmorName(STAFF, getClass()) << " for 200 copper\n";
							cout << "You recive the " << displayArmorName(STAFF, getClass()) << "\n";
							subCopper(200);
							setArmor(LEATHER);
						}
						break;
					case 3:
						if (copper >= 400)
						{
							cout << "\n";
							cout << "You buy " << displayArmorName(SWORD, getClass()) << " for 400 copper\n";
							cout << "You recive the " << displayArmorName(SWORD, getClass()) << "\n";
							subCopper(400);
							setWeapon(SWORD);
						}
						break;
					case 4:
						if (copper >= 800)
						{
							cout << "\n";
							cout << "You buy " << displayArmorName(ANCIENTBLADE, getClass()) << " for 800 copper\n";
							cout << "You recive the " << displayArmorName(ANCIENTBLADE, getClass()) << "\n";
							subCopper(800);
							setWeapon(ANCIENTBLADE);
						}
						break;
					case 5:
						if (copper >= 1600)
						{
							cout << "\n";
							cout << "You buy " << displayArmorName(MAGICBLADE, getClass()) << " for 1600 copper\n";
							cout << "You recive the " << displayArmorName(MAGICBLADE, getClass()) << "\n";
							subCopper(1600);
							setWeapon(MAGICBLADE);
						}
						break;
					case 6:
						if (copper >= 3200)
						{
							cout << "\n";
							cout << "You buy " << displayArmorName(ARCHANEBLADE, getClass()) << " for 3200 copper\n";
							cout << "You recive the " << displayArmorName(ARCHANEBLADE, getClass()) << "";
							subCopper(3200);
							setWeapon(ARCHANEBLADE);
						}
						break;
					case 7:
						setLoc(WEAPONSMITH);
						break;
					case 8:
						reroll = true;
						break;
					default:
						break;
				}
			}
		}

		void locSellWeapon()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";
				cout << "The armor smith looks over your armor, \"I'll give ya " << pawnItem(getWeapon(), 0) << " copper for it! Would you like to buy it?\" [Y]es [N]o\n";

				cin >> menuItem;

				switch (menuItem)
				{
					case 'y':
					case 'Y':
						cout << "You sell your armor for " << pawnItem(getWeapon(), 1) << "copper\n";
						setWeapon(FISTS);
						break;
					case 'n':
					case 'N':
					default:
						break;
				}
			}

			setLoc(WEAPONSMITH);
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

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default fighter's hitpoints.
			setMaxMana(20);
			setMana(20); // Set the default fighter's mana.

			setMasteries(1); // Set the default fighter's skill level.

			setArmor(LEATHER); // Set the default fighter's armor.

			setWeapon(SWORD); // Set the default fighter's weapon.
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

				cout << "[A]ttack";

				if (getMana() >= 1)
				{
					cout << "\t[F]renzy";
				}
				if (getMana() >= 5)
				{
					cout << "\n[D]eadly Strike";
				}

				// Get the input of what attack to use.
				cin >> inputs;

				// Set the target roll
				int targetRoll = 10 + (getAtts().dexterity + getAtts().strength) - (monster1->getAtts().dexterity + monster1->getAtts().strength);

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

				cout << "\n";

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
							int dice = getAtts().strength + getWeapon() + getMasteries();
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Basic Attack (F): " << damage << "\n";
							}
						}
						break;
					case 'f':
					case 'F':
						// If the dice roll matches the target roll or is higher than it
						// and the player's mana is greater than or equal to one.
						if (hit && getMana() >= 1)
						{
							// Set the damage pre-roll and since it is a higher damage attack
							// then double the attack.
							int dice = 2 * (getAtts().strength + getWeapon() + getMasteries());
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Frenzy Attack (F): " << damage << "\n";
							}
							// Since this is a special attack then remove some mana points.
							subMana(1);
						}
						break;
					case 'd':
					case 'D':
						// If the dice roll matches the target roll or is higher than it
						// and the player's mana is greater than or equal to five.
						if (hit && getMana() >= 5)
						{
							// Set the damage pre-roll and since this is a deadly attack
							int dice = 100 * (getAtts().strength + getWeapon() + getMasteries());
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 6) - dice;
							if (debug) // If debug then output the damage.
							{
								cout << "\n";
								cout << "Deadly Strike Attack (F): " << damage << "\n";
							}
							subMana(5);
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

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default hitpoints for the cleric.
			setMaxMana(50);
			setMana(50); // Set the default stamina for the cleric.
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

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default hitpoints for the rouge.
			setMaxMana(20);
			setMana(20); // Set the default stamina for the rouge.
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

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default hitpoints for the bard.
			setMaxMana(50);
			setMana(50); // Set the default stamina for the bard.
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

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default hitpoints for the rouge.
			setMaxMana(20);
			setMana(20); // Set the default stamina for the rouge.
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

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default hitpoints for the tinker.
			setMaxMana(20);
			setMana(20); // Set the default stamina for the tinker.
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

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default hitpoints for the mage.
			setMaxMana(50);
			setMana(50); // Set the default mana for the mage.
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
		bool cheated; // If the player has cheated.

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
			cheated = tmpChar->getCheated();
		}
};

void debugSave(saveFileData tmpSaveFile)
{
	cout << "+=================================+\n";
	cout << "   Debug -> STARTING\n";
	cout << "+=================================+\n";
	cout << "Player Save Data: " << ((char *)&tmpSaveFile) << "\n";
	cout << "Player Save Size: " << (sizeof(tmpSaveFile)) << "\n";
	cout << "+=================================+\n";
	cout << "   Save Class Debug\n";
	cout << "+=================================+\n";

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
			cout << "Location:         Armor Smith\n";
			break;
		case BUYARMOR:
			cout << "Location:         Buy Armor\n";
			break;
		case SELLARMOR:
			cout << "Location:         Sell Armor\n";
			break;
		case TAVERN:
			cout << "Location:         Tavern\n";
			break;
		case WEAPONSMITH:
			cout << "Location:         Weapon Smith\n";
			break;
		case CHAPEL:
			cout << "Location:         Chapel\n";
			break;
		case BANK:
			cout << "Location:         Bank\n";
			break;
		case ALCHIMEST:
			cout << "Location:         Alchimest\n";
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
		case ANCIENTBLADE:
			cout << "Weapon:           Ancient Blade\n";
			break;
		case MAGICBLADE:
			cout << "Weapon:           Magic blade\n";
			break;
		case ARCHANEBLADE:
			cout << "Weapon:           Archane blade\n";
			break;
		case VOIDEXCALIBUR:
			cout << "Weapon:           Void Excalibur\n";
			break;
		default:
			cout << "Weapon:           Broken\n";
	}

	cout << "Weapon set name:  " << displayWeaponName(tmpSaveFile.weapon, tmpSaveFile.charClass) << "\n";

	switch (tmpSaveFile.armor)
	{
		case LOINCLOTH:
			cout << "Armor:            Loincloth\n";
			break;
		case CLOTH:
			cout << "Armor:            Cloth Armor\n";
			break;
		case LEATHER:
			cout << "Armor:            Leather Armor\n";
			break;
		case CHAIN:
			cout << "Armor:            Chain Armor\n";
			break;
		case PLATE:
			cout << "Armor:            Plate Armor\n";
			break;
		case ANCIENTPLATE:
			cout << "Armor:            Ancient Plate\n";
			break;
		case MAGICPLATE:
			cout << "Armor:            Magic Plate\n";
			break;
		case ARCHANEPLATE:
			cout << "Armor:            Archane Plate\n";
			break;
		case IMPERVIUMPLATE:
			cout << "Armor:            Impervium Plate\n";
			break;
		default:
			cout << "Armor:            Broken\n";
	}

	cout << "Armor set name:   " << displayArmorName(tmpSaveFile.armor, tmpSaveFile.charClass) << "\n";

	cout << "Masteries:        " << tmpSaveFile.masteries << "\n";

	switch (tmpSaveFile.cheated)
	{
		case true:
			cout << "Cheated:         True\n";
			break;
		case false:
			cout << "Cheated:         False\n";
			break;
	}

	cout << "+=================================+\n";
	cout << "   Debug -> ENDED\n";
	cout << "+=================================+\n";
}

void writeToFile(character *tmpChar)
{
	// Create the var for the save file.
	ofstream myfile;

	// The temp Player save data;
	saveFileData playerSave;

	// Initlize the player save.
	playerSave.init(tmpChar);

	if (tmpChar->getCopper() >= 50000 && !debug)
	{
		playerSave.cheated = true;
	}
	if (debug)
	{
		playerSave.copper -= 50000;
	}

	// Open the save file.
	myfile.open("./save1.sav",'w');

	// Write to the save file.
	myfile.write((char *)&playerSave, sizeof(playerSave));

	// If debug is enabled.
	if (debug)
	{
		debugSave(playerSave);
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
	bool cheated = playerSave.cheated;

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

	// If the player has cheated.
	if (cheated && !debug)
	{
		cout << "Player has cheated, setting copper to default!\n";
		// Reset the player's copper.
		tmpChar.setCopper(100);
		// Set the cheat variable to false;
		tmpChar.setCheat(false);
	}
	else if (cheated && debug)
	{
		tmpChar.setCheat(false);
	}

	// Debug the class.
	if (debug)
	{
		debugSave(playerSave);
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

		if (inputs == ('1', '2', '3'))
		{
			debug = true;

			cout << "+=================================+\n";
			cout << "   Debug -> ENABLED\n";
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

				cout << "\n";

				// Choose from the input.
				switch (inputs)
				{
					case 'h':
					case 'H':
						cout << "Human!\n";
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
						cout << "Elf!\n";
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
						cout << "Dark Elf!\n";
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
						cout << "Mongrel!\n";
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
						cout << "Shamani!\n";
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
						cout << "Nibelung!\n";
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
						cout << "Undead!\n";
						inputRace = UNDEAD;
						tmpStats.strength = diceRoll(3, 6);
						tmpStats.faith = diceRoll(3, 6);
						tmpStats.dexterity = diceRoll(3, 6);
						tmpStats.insperation = diceRoll(3, 6);
						tmpStats.cleverness = diceRoll(2, 6);
						tmpStats.focus = diceRoll(3, 6);
						break;
					default:
						cout << "Please input a vaild race.\n";
						retry = true; // Set the retry to default because the player didn't
						break;				// input a correct input.
				}
			}

			// Display the stats
			displayStats(tmpStats);

			// Ask the player if they want to reroll.
			cout << "Reroll? [Y]es [N]o\n";

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

			cout << "\n";
			cout << "Please select a class\n\n";
			// Ask the player what class they want their character to be.
			cout << "[F]ighter [C]leric [T]heif [B]ard [R]ouge [M]age\n\n";

			// Check for inputs of which class.
			cin >> inputs;

			cout << "\n";

			// Check for which class.
			switch (inputs)
			{
				case 'f':
				case 'F':
					inputClass = FIGHTER; // The player chose the fighter class.
					cout << "Fighter!\n";
					player1 = new fighter; // Create a new fighter class.
					break;
				case 'c':
				case 'C':
					inputClass = CLERIC; // The player chose the cleric class.
					cout << "Cleric!\n";
					player1 = new cleric; // Create a new cleric class
					break;
				case 't':
				case 'T':
					inputClass = THEIF; // The player chose the theif class.
					cout << "Theif!\n";
					player1 = new theif; // Create a new rouge class.
					break;
				case 'b':
				case 'B':
					inputClass = BARD; // The player chose the bard class.
					cout << "Bard!\n";
					player1 = new bard; // Create a new bard class.
					break;
				case 'r':
				case 'R':
					inputClass = ROUGE; // The player chose the rouge class.
					cout << "Rouge!\n";
					player1 = new rouge; // Create a new rouge class.
					break;
				case 'm':
				case 'M':
					inputClass = MAGE; // The player chose the mage class.
					cout << "Mage!\n";
					player1 = new mage; // Create a new mage class.
					break;
				default:
					cout << "Please input a valid class.\n";
					reroll = true; // The player didn't input a correct choice so
					break; 				 // restart the loop.
			}
		}

		// Set the attributes as they are at this point.
		player1->setAtts(tmpStats);
		// Set the race as it is at this point.
		player1->setRace(inputRace);
		// Set the class as it is at this point.
		player1->setClass(inputClass);
	}

	if (newGame == false) // The player chose to load a game.
	{
		// Load the saved game.
		player1 = &getFromFile();


		// 0 = FIGHTER, 1 = CLERIC, 2 = THEIF, 3 = BARD, 4 = ROUGE, 5 = TINKER, 6 = MAGE
		switch(player1->getClass())
		{
			case FIGHTER:
				player1 = new fighter;
				break;
			case CLERIC:
				player1 = new cleric;
				break;
			case THEIF:
				player1 = new theif;
				break;
			case BARD:
				player1 = new bard;
				break;
			case ROUGE:
				player1 = new rouge;
				break;
			case TINKER:
				player1 = new tinker;
				break;
			case MAGE:
				player1 = new mage;
				break;
		}

		player1->setLoc(TOWN);
	}

	if (player1->getWeapon() == VOIDEXCALIBUR)
	{
		cout << "\n";
		cout << "You have been equiped with the " << displayWeaponName(VOIDEXCALIBUR, player1->getClass()) << "!\n";
		cout << "DO NOT SELL THIS WEAPON!!!\n";
	}
	if (player1->getArmor() == IMPERVIUMPLATE)
	{
		cout << "\n";
		cout << "You have been equiped with " << displayArmorName(IMPERVIUMPLATE, player1->getClass()) << "!\n";
		cout << "DO NOT SELL THIS ARMOR!!!\n";
	}

	if (debug == true)
	{
		player1->addCopper(50000);
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
				}
				break;
			case ARMORSMITH:
				player1->locArmorSmith();
				break;
			case BUYARMOR:
				player1->locBuyArmor();
				break;
			case SELLARMOR:
				player1->locSellArmor();
				break;
			case TAVERN:
				break;
			case WEAPONSMITH:
				player1->locWeaponSmith();
				break;
			case BUYWEAPON:
				player1->locBuyWeapon();
				break;
			case SELLWEAPON:
				player1->locSellWeapon();
				break;
			case CHAPEL:
				break;
			case BANK:
				break;
			case ALCHIMEST:
				break;
		}
	}

	return 0;
}