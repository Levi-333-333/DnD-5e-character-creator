#include "character.h"

enum CharacterClass
{
	Бард,
	Варвар,
	Воин,
	Волшебник,
	Друид,
	Жрец,
	Изобретатель,
	Колдун,
	Монах,
	Паладин,
	Плут,
	Следопыт,
	Чародей
};

int RollDice(int face)
{
	return rand() % face + 1;
}

struct Character
{
	string name;
	CharacterClass charClass;

};