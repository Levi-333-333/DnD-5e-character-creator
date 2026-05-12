#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "dice.h"
using namespace std;

#define strength characteristics.characteristics["Сила"]
#define dexterity characteristics.characteristics["Ловкость"]
#define constitution characteristics.characteristics["Телосложение"]
#define intelligence characteristics.characteristics["Интеллект"]
#define wisdom characteristics.characteristics["Мудрость"]
#define charisma characteristics.characteristics["Харизма"]

extern vector<string> ClassesVector;
extern vector<string> RacesVector;
extern vector<string> BackgroundsVector;
extern vector<string> CharacteristicsVector;
extern vector<string> SkillsVector;

struct Characteristic
{
	map<string, int> characteristics;

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

//...
class Header
{
public:
	void SetName();
	void SetCharacterClass();
	void SetRace();
	void SetBackground();
	void SetWorldview();
	void SetPlayerName();
	void SetExperience(); // Пока программа не подразумевает лвлапы и/или создание персонажа уровня выше первого ф-я выполняется перед вызовом ф-ии PrintInfo() 
	void SetLevel(int _level); // Пока программа не подразумевает лвлапы и/или создание персонажа уровня выше первого ф-я выполняется перед вызовом ф-ии PrintInfo() со значением 1. Приоритетнее всех
private:
	string name;
	string characterClass;
	string race;
	string background;
	string worldview;
	string playerName;
	int experience;
	int level;
};

class LeftPart
{
public:
	void SetCharacteristics();
	void SetPassivePerception(); // Ф-я выполняется перед вызовом ф-ии PrintInfo()
	void SetModifficators(); // Ф-я выполняется перед вызовом ф-ии PrintInfo() приоритетнее всех других подобных функций, кроме SetLevel
private:
	Characteristic characteristics;
	int masteryBonus;
	vector<string> masterySkills;
	vector<string> savingThrowsSkills;
	bool inspiration;
	int passivePerception;
	map<string, vector<string>> otherProficienciesAndLanguages;
};

class CenterPart
{
public:
	void SetClassArmor(); // Ф-я выполняется перед вызовом ф-ии PrintInfo()
	void SetInitiative(); // Ф-я выполняется перед вызовом ф-ии PrintInfo()
private:
	int classArmor;
	int initiative;
	int speed;
	int maxHits;
	int hitDice;
	Wallet cash;
	vector<string> inventory;
};

class RightPart
{
public:
	void SetCharacterTraits();
	void SetIdeals();
	void SetAffections();
	void SetWeaknesses();
private:
	string characterTraits;
	string ideals;
	string affections;
	string weaknesses;
	vector<string> skills;
};

struct Character
{
	// Header
	Header header;

	// Left part of character's list
	LeftPart leftPart;

	// Center part of character's list
	CenterPart centerPart;

	// Right part of character's list
	RightPart rightPart;

	// Functions
	void PrintInfo();	
};	