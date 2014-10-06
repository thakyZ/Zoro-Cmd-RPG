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
enum RACE {HUMAN, ELF, DARKELF, ANGEL, MONGREL, SHAMANI, NIBELUNG, UNDEAD};

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

// Startup
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	RACE inputRace; // The race that is chosen.
	char inputs; // The input to choose the race.
	ATTRIBUTES tempStats; // The stats the player gets by random.

	cout << diceRoll(20, 86) << "\n";

	cout << "Welcome to Zorcan\n";

	cout << "Please Select a Race:\n";
	cout << "[H]uman [E]lf [D]ark elf [A]ngel [M]ongrel [S]hamani [N]ibelung [U]ndead\n";

	// The input for the chosen race.
	cin >> inputs;

	switch (inputs)
	{
		case 'h':
		case 'H':
			cout << "Human\n";
			inputRace = HUMAN;
			break;
		case 'e':
		case 'E':
			cout << "Elf\n";
			inputRace = ELF;
			break;
		case 'd':
		case 'D':
			cout << "Dark Elf\n";
			inputRace = DARKELF;
			break;
		case 'a':
		case 'A':
			cout << "Angel\n";
			inputRace = ANGEL;
			break;
		case 'm':
		case 'M':
			cout << "Mongrel\n";
			inputRace = MONGREL;
			break;
		case 's':
		case 'S':
			cout << "Shamani\n";
			inputRace = SHAMANI;
			break;
		case 'n':
		case 'N':
			cout << "Nibelung\n";
			inputRace = NIBELUNG;
			break;
		case 'u':
		case 'U':
			cout << "Undead\n";
			inputRace = UNDEAD;
			break;
		default:
			break;
	}

	return 0;
}