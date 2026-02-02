#include <Windows.h>
#include "character.h"

void main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	Character character;

	/*character.SetName();
	character.SetPlayerName();
	character.SetRace();*/
	character.SetBackground();
	character.SetWorldview();
	character.SetCharacteristics();

	character.SetLevel(1);
	character.SetModifficators();
	character.SetExperience();
	character.SetPassivePerception();
	character.SetClassArmor();
	character.SetInitiative();
	character.PrintInfo();
}
