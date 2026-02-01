#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "dice.h"
using namespace std;

extern vector<string> ClassesVector;
extern vector<string> RacesVector;
extern vector<string> BackgroundsVector;

struct Characteristic
{
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;

	int strengthMod;
	int dexterityMod;
	int constitutionMod;
	int intelligenceMod;
	int wisdomMod;
	int charismaMod;

	Characteristic();
};

struct Wallet
{
	int copper;
	int silver;
	int electrum;
	int gold;
	int platinum;

	Wallet();
};

struct Character
{
	// Header
	string name;
	string characterClass;
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

	// Functions
	void PrintInfo();

	// Functions for header
	void SetName();
	void SetCharacterClass();
	void SetRace();
	void SetBackground();
	void SetWorldview();
	void SetPlayerName();
	void SetExperience(); // Пока программа не подразумевает лвлапы и/или создание персонажа уровня выше первого ф-я выполняется перед вызовом ф-ии PrintInfo() 
	void SetLevel(int _level); // Пока программа не подразумевает лвлапы и/или создание персонажа уровня выше первого ф-я выполняется перед вызовом ф-ии PrintInfo() со значением 1. Приоритетнее всех

	// Functions for left part of character's list
	void SetCharacteristics();
	void SetPassivePerception(); // Ф-я выполняется перед вызовом ф-ии PrintInfo()
	void SetModifficators(); // Ф-я выполняется перед вызовом ф-ии PrintInfo() приоритетнее всех других подобных функций, кроме SetLevel

	// Functions for Center part of character's list
	void SetClassArmor(); // Ф-я выполняется перед вызовом ф-ии PrintInfo()
	void SetInitiative(); // Ф-я выполняется перед вызовом ф-ии PrintInfo()

	// Functions for right part of character's list
	void SetCharacterTraits();
	void SetIdeals();
	void SetAffections();
	void SetWeaknesses();
};