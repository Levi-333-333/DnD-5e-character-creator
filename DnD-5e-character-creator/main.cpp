#include <Windows.h>
#include "character.h"

void main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	Character character;

	character.SetBackground();
	character.SetRace();

	character.PrintInfo();
}
