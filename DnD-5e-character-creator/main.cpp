#include <Windows.h>
#include "character.h"

void main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	Character character;

	cout << "Введите имя вашему персонажу (Нажмите 'Enter', что бы пропустить): ";
	getline(cin, character.name);
	cout << endl;

	cout << "Введите один из предложенных классов (цифрой)" << endl;
	for (int i = 1; i <= ClassesVector.size(); i++)
	{
		cout << i << ". " << ClassesVector[i - 1] << endl;
	}

	int userInput;
	do
	{
		cin >> userInput;
		if (!(userInput >= 1 && userInput <= ClassesVector.size())) cout << "Неверный ввод. Попробуйте ещё раз" << endl;
	} while (!(userInput >= 1 && userInput <= ClassesVector.size()));

	character.charClass = ClassesVector[userInput - 1];

	if (userInput == 4 || userInput == 13) character.hitDice = 6;
	else if (userInput == 1 || userInput == 5 || userInput == 6 || userInput == 7 || userInput == 8 || userInput == 9 || userInput == 11) character.hitDice = 8;
	else if (userInput == 3 || userInput == 10 || userInput == 12) character.hitDice = 10;
	else if (userInput == 2) character.hitDice = 12;

	cout << "Введите одну из предложенных рас (цифрой)" << endl;
	for (int i = 1; i <= RacesVector.size(); i++)
	{
		cout << i << ". " << RacesVector[i - 1] << endl;
	}
	
	do
	{
		cin >> userInput;
		if (!(userInput >= 1 && userInput <= RacesVector.size())) cout << "Неверный ввод. Попробуйте ещё раз" << endl;
	} while (!(userInput >= 1 && userInput <= RacesVector.size()));

	character.race = RacesVector[userInput - 1];

	character.PrintInfo();
}
