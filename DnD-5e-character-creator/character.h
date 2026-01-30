#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

enum CharacterClass;

int RollDice(int face);

struct Characteristic
{
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;
};

struct Wallet
{
	int copper;
	int silver;
	int electrum;
	int gold;
	int platinum;
};

struct Character
{
	// Header
	string name;
	CharacterClass charClass;
	string race;
	string background;
	string worldview;
	string playerName;
	int experience;
	int level;

	// Left part of character's list
	Characteristic characteristics;
	int masteryBonus;
	vector<string> masterySkills;
	vector<string> savingThrowsSkills;
	bool inspiration;
	int passivePerception;
	map<string, vector<string>> otherProficienciesAndLanguages;

	// Center part of character's list
	int classArmor;
	int initiative;
	int speed;
	int maxHits;
	int hitDice;
	Wallet cash;
	vector<string> inventory;

	// Right part of character's list
	string characterTraits;
	string ideals;
	string affections;
	string weaknesses;
	vector<string> skills;
};