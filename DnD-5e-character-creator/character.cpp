#include "character.h"

vector<string> ClassesVector =
{
	"Бард",
	"Варвар",
	"Воин",
	"Волшебник",
	"Друид",
	"Жрец",
	"Изобретатель",
	"Колдун",
	"Монах",
	"Паладин",
	"Плут",
	"Следопыт",
	"Чародей"
};

vector<string> RacesVector =
{
	"Гном",
	"Дварф",
	"Драконороженный",
	"Полуорк",
	"Полурослик",
	"Полуэльф",
	"Тифлинг",
	"Человек",
	"Эльф"
};

vector<string> BackgroundsVector =
{
	"Артист",
	"Беспризорник",
	"Благородный",
	"Гильдейский ремесленник",
	"Моряк",
	"Мудрец",
	"Народный герой",
	"Отшельний",
	"Пират",
	"Преступник",
	"Прислужник",
	"Солдат",
	"Чужеземец",
	"Шарлатан"
};

Characteristic::Characteristic()
{
	strength = 0;
	dexterity = 0;
	constitution = 0;
	intelligence = 0;
	wisdom = 0;
	charisma = 0;
}

// Зона ответственноси Дарии
void Character::PrintInfo()
{
	// Header
	cout << "Имя персонажа: " << name << "\t\t Класс: " << characterClass << " Предыстория: " << background << " Имя игрока:" << playerName << endl;
	cout << "\t\t" << "Раса: " << race << " Мировоззрение: " << worldview << " Опыт: " << experience << " Уровень: " << level << endl << endl;

	// Left part of character's list

}

void Character::SetName()
{
	cout << "Введите имя вашему персонажу (Нажмите 'Enter', что бы пропустить): ";
	getline(cin, name);
	cout << endl;
}

void Character::SetCharacterClass()
{
	cout << "Введите один из предложенных классов (цифрой)" << endl;
	for (int i = 1; i <= ClassesVector.size(); i++)
	{
		cout << i << ". " << ClassesVector[i - 1] << endl;
	}

	int chosenClass;
	do
	{
		cin >> chosenClass;
		if (!(chosenClass >= 1 && chosenClass <= ClassesVector.size())) cout << "Неверный ввод. Попробуйте ещё раз" << endl;
	} while (!(chosenClass >= 1 && chosenClass <= ClassesVector.size()));

	characterClass = ClassesVector[chosenClass - 1];

	// Добавление кости хитов в зависимости от класса
	if (chosenClass == 4 || chosenClass == 13) hitDice = 6;
	else if (chosenClass == 1 || chosenClass == 5 || chosenClass == 6 || chosenClass == 7 || chosenClass == 8 || chosenClass == 9 || chosenClass == 11) hitDice = 8;
	else if (chosenClass == 3 || chosenClass == 10 || chosenClass == 12) hitDice = 10;
	else if (chosenClass == 2) hitDice = 12;

	// Добавление всего от класса
	// Бард
	if (chosenClass == 1)
	{
		// Зона ответственности Льва
	}
}

void Character::SetRace()
{
	cout << "Введите одну из предложенных рас (цифрой)" << endl;
	for (int i = 1; i <= RacesVector.size(); i++)
	{
		cout << i << ". " << RacesVector[i - 1] << endl;
	}

	int userInput;
	do
	{
		cin >> userInput;
		if (!(userInput >= 1 && userInput <= RacesVector.size())) cout << "Неверный ввод. Попробуйте ещё раз" << endl;
	} while (!(userInput >= 1 && userInput <= RacesVector.size()));

	race = RacesVector[userInput - 1];

	// Гном
	if (userInput == 1)
	{
		characteristics.intelligence += 2;
		speed = 25;
		otherProficienciesAndLanguages["Языки"] = { "Общий", "Гномий" };
		otherProficienciesAndLanguages["Тёмное зрение"] = { "60 футов" };
		skills.push_back("Гномья хитрость");

		// Подраса
		int raceChoise;
		do
		{
			cout << "Выберите 1 из 2-х: \n1) Лесной гном\t2) Скальный гном" << endl;
			cin >> raceChoise;
			switch (raceChoise)
			{	
			case 1:
				characteristics.dexterity += 1;
				skills.push_back("Природная иллюзия");
				skills.push_back("Общение с маленькими зверями");
				break;
			case 2:
				characteristics.constitution += 1;
				skills.push_back("Ремесленные знания");
				skills.push_back("Жестянщик");
				break;
			default:
				cout << "Неверный ввод. Попробуйте ещё раз" << endl;
			}
		} while (!(raceChoise == 1 || raceChoise == 2));
	}

	// Дварф
	else if (userInput == 2)
	{
		characteristics.constitution += 2;
		speed = 25;
		otherProficienciesAndLanguages["Тёмное зрение"] = { "60 футов" };
		skills.push_back("Дварфийская устойчивость");
		otherProficienciesAndLanguages["Оружие"] = { "Боевой топор", "Ручной топор", "Лёгкий молот", "Боевой молот" };

		int toolChoise;
		do
		{
			cout << "Выберите владение инструментами 1 из 3-х:\n1) Инструменты кузнеца\t2) Инструменты пивовара\t3) инструменты каменщика" << endl;
			cin >> toolChoise;

			switch (toolChoise)
			{
			case 1:
				otherProficienciesAndLanguages["Инструменты"] = { "Инструменты кузнеца" };
				break;
			case 2:
				otherProficienciesAndLanguages["Инструменты"] = { "Инструменты пивовара" };
				break;
			case 3:
				otherProficienciesAndLanguages["Инструменты"] = { "Инструменты каменщика" };
				break;
			default:
				cout << "Неверный ввод. Попробуйте ещё раз" << endl;
			}
		} while (!(toolChoise == 1 || toolChoise == 2 || toolChoise == 3));

		skills.push_back("Знание камня");
		otherProficienciesAndLanguages["Языки"] = { "Общий", "Дварфийский" };

		// Подраса
		int raceChoise;
		do
		{
			cout << "Выберите 1 из 2-х: \n1) Горный дварф\t2) Холмовой дварф" << endl;
			cin >> raceChoise;
			switch (raceChoise)
			{
			case 1:
				characteristics.strength += 2;
				otherProficienciesAndLanguages["Доспехи"] = { "Лёгкие доспехи", "Средние доспехи" };
				break;
			case 2:
				characteristics.wisdom += 1;
				skills.push_back("Дварфийская выдержка");
				maxHits += 1;
				break;
			default:
				cout << "Неверный ввод. Попробуйте ещё раз" << endl;
			}
		} while (!(raceChoise == 1 || raceChoise == 2));
	}

	// Драконорождённый
	else if (userInput == 3)
	{
		characteristics.strength += 2;
		characteristics.charisma += 1;
		speed = 30;
		otherProficienciesAndLanguages["Языки"] = { "Общий", "Драконий" };

		int raceChoise;
		do
		{
			cout << "Выберите наследие драконов:\n1) Белый\t2) Бронзовый\t3) Зелёный\t4) Золотой\n5) Красный\t6)Латунный\t7) Медный\t8) Серебрянный\n9) Синий\t10) Чёрный" << endl;
			cin >> raceChoise;

			switch (raceChoise)
			{
			case 1:
				skills.push_back("Оружие дыхания (Белый)");
				skills.push_back("Сопротивление урону (Холод)");
				break;
			case 2:
				skills.push_back("Оружие дыхания (Бронзовый)");
				skills.push_back("Сопротивление урону (Электричество)");
				break;
			case 3:
				skills.push_back("Оружие дыхания (Зелёный)");
				skills.push_back("Сопротивление урону (Яд)");
				break;
			case 4:
				skills.push_back("Оружие дыхания (Золотой)");
				skills.push_back("Сопротивление урону (Огонь)");
				break;
			case 5:
				skills.push_back("Оружие дыхания (Красный)");
				skills.push_back("Сопротивление урону (Огонь)");
				break;
			case 6:
				skills.push_back("Оружие дыхания (Латунный)");
				skills.push_back("Сопротивление урону (Огонь)");
				break;
			case 7:
				skills.push_back("Оружие дыхания (Медный)");
				skills.push_back("Сопротивление урону (Кислота)");
				break;
			case 8:
				skills.push_back("Оружие дыхания (Серебрянный)");
				skills.push_back("Сопротивление урону (Холод)");
				break;
			case 9:
				skills.push_back("Оружие дыхания (Синий)");
				skills.push_back("Сопротивление урону (Электричество)");
				break;
			case 10:
				skills.push_back("Оружие дыхания (Чёрный)");
				skills.push_back("Сопротивление урону (Кислота)");
				break;
			default:
				cout << "Неверный ввод. Попробуйте ещё раз" << endl;
			}
		} while (!(1 <= raceChoise <= 10));
	}
}