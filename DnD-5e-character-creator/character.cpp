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

// Сделал Лев
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

	// Полуорк
	else if (userInput == 4)
	{
		characteristics.strength += 2;
		characteristics.constitution += 1;
		speed = 30;
		otherProficienciesAndLanguages["Тёмное зрение"] = { "60 футов" };
		masterySkills.push_back("Запугивание");
		skills.push_back("Непоколебимая стойкость");
		skills.push_back("Свирепые атаки");
		otherProficienciesAndLanguages["Языки"] = { "Общий", "Орочий" };
	}

	// Полурослик
	else if (userInput == 5)
	{
		characteristics.dexterity += 2;
		speed = 25;
		skills.push_back("Везучий");
		skills.push_back("Храбрый");
		skills.push_back("Проворство полуросликов");
		otherProficienciesAndLanguages["Языки"] = { "Общий", "Язык Полуросликов" };

		// Подрасы
		int raceChoise;
		do
		{
			cout << "Выберите 1 из 2-х: \n1) Коренастый полурослик\t2) Легконогий полурослик" << endl;
			cin >> raceChoise;
			switch (raceChoise)
			{
			case 1:
				characteristics.constitution += 1;
				skills.push_back("Устойчивость коренастых");
				break;
			case 2:
				characteristics.charisma += 1;
				skills.push_back("Естественная скрытность");
				break;
			default:
				cout << "Неверный ввод. Попробуйте ещё раз" << endl;
			}
		} while (!(raceChoise == 1 || raceChoise == 2));
	}

	// Полуэльф
	else if (userInput == 6)
	{
		// Выбор характеристик
		vector<string> characteristicsForHalfelf = { "Сила", "Ловкость", "Телосложение", "Интелект", "Мудрость" };
		characteristics.charisma += 2;
		
		int userCharacteristicChoise;
		for (int i = 0; i < 2; i++)
		{
			cout << "Выбирете " << i << " характеристики, значение которых повысится на 1: " << endl;
			for (int j = 1; j <= characteristicsForHalfelf.size(); j++)
			{
				cout << j << ". " << characteristicsForHalfelf[j - 1] << endl;
			}
			cin >> userCharacteristicChoise;

			if (userCharacteristicChoise > characteristicsForHalfelf.size())
			{
				cout << "Неверный ввод. Попробуйте ещё раз" << endl;
				i--;
				continue;
			}

			string chosenCharacteriscic = characteristicsForHalfelf[userCharacteristicChoise - 1];

			if (chosenCharacteriscic == "Сила")
			{
				characteristics.strength += 1;
				characteristicsForHalfelf.erase(characteristicsForHalfelf.begin() + (userCharacteristicChoise - 1));
			}
			else if (chosenCharacteriscic == "Ловкость") 
			{
				characteristics.dexterity += 1;
				characteristicsForHalfelf.erase(characteristicsForHalfelf.begin() + (userCharacteristicChoise - 1));
			}
			else if (chosenCharacteriscic == "Телосложение") 
			{
				characteristics.constitution += 1;
				characteristicsForHalfelf.erase(characteristicsForHalfelf.begin() + (userCharacteristicChoise - 1));
			}
			else if (chosenCharacteriscic == "Интелект") 
			{
				characteristics.intelligence += 1;
				characteristicsForHalfelf.erase(characteristicsForHalfelf.begin() + (userCharacteristicChoise - 1));
			}
			else if (chosenCharacteriscic == "Мудрость")
			{
				characteristics.wisdom += 1;
				characteristicsForHalfelf.erase(characteristicsForHalfelf.begin() + (userCharacteristicChoise - 1));
			}
			
		}

		//Выбор навыков
		vector<string> skillsToChose = { "Акробатика", "Анализ", "Атлетика", "Восприятие", "Выживание", "Выступление", "Запугивание", "История", "Ловкость рук", "Магия", "Медицина", "Обман", "Природа", "Проницательность", "Религия", "Скрытность", "Убеждение", "Уход за животными" };
		//Убираем из списка выше все навыки, которые уже есть у персонажа
		for (int i = 0; i < masterySkills.size(); i++)
		{
			for (int j = 0; j < skillsToChose.size(); j++) 
			{
				if (masterySkills[i] == skillsToChose[j])
				{
					skillsToChose.erase(skillsToChose.begin() + j);
					break;
				}
			}
		}
		// Выбор из оставшихся навыков
		for (int i = 0; i < 2; i++)
		{
			cout << "Выберите " << i + 1 << "-й навык (из 2-х) для изучения: " << endl;
			for (int j = 1; j <= skillsToChose.size(); j++)
			{
				cout << j << ". " << skillsToChose[j - 1] << endl;
			}
			int chosenSkill;
			cin >> chosenSkill;
			if (chosenSkill <= skillsToChose.size())
			{
				skills.push_back(skillsToChose[chosenSkill - 1]);
				skillsToChose.erase(skillsToChose.begin() + (chosenSkill - 1));
			}
			else
			{
				cout << "Неверный ввод. Попробуйте ещё раз" << endl;
				i--;
			}
		}

		// Всё остальное
		speed = 30;
		otherProficienciesAndLanguages["Тёмное зрение"] = { "60 футов" };
		skills.push_back("Наследие фей");
		otherProficienciesAndLanguages["Языки"] = { "Общий", "Эльфийский", "Любой на выбор" };
	}

	// Тифлинг
	else if (userInput == 7)
	{
		characteristics.intelligence += 1;
		characteristics.charisma += 2;
		speed = 30;
		otherProficienciesAndLanguages["Тёмное зрение"] = { "60 футов" };
		skills.push_back("Адское сопротивление");
		skills.push_back("Дьявольское наследие");
		otherProficienciesAndLanguages["Языки"] = { "Общий", "Инфернальный" };
	}

	// Человек
	else if (userInput == 8)
	{
		cout << "Выберите 1 из 2-х:\n1) Человек обычный\t2) Человек альтернативный" << endl;
		int humanChoise;
		vector<string> characteristicsForHuman = { "Сила", "Ловкость", "Телосложение", "Интелект", "Мудрость", "Харизма" };
		vector<string> skillsToChose = { "Акробатика", "Анализ", "Атлетика", "Восприятие", "Выживание", "Выступление", "Запугивание", "История", "Ловкость рук", "Магия", "Медицина", "Обман", "Природа", "Проницательность", "Религия", "Скрытность", "Убеждение", "Уход за животными" };
		do
		{
			cin >> humanChoise;
			switch (humanChoise)
			{
			// Человек обычный
			case 1:
				characteristics.strength += 1;
				characteristics.dexterity += 1;
				characteristics.constitution += 1;
				characteristics.intelligence += 1;
				characteristics.wisdom += 1;
				characteristics.charisma += 1;
				speed = 30;
				otherProficienciesAndLanguages["Языки"] = { "Общий", "Любой на выбор" };
				break;
			// Человек альтернативный
			case 2:
				// Хахахахахарактеристика (я схожу с ума)
				int userCharacteristicChoise;

				for (int i = 0; i < 2; i++)
				{
					cout << "Выбирете " << i + 1 << "-ю характеристику, значение которых повысится на 1: " << endl;
					for (int j = 1; j <= characteristicsForHuman.size(); j++)
					{
						cout << j << ". " << characteristicsForHuman[j - 1] << endl;
					}
					cin >> userCharacteristicChoise;

					if (userCharacteristicChoise > characteristicsForHuman.size())
					{
						cout << "Неверный ввод. Попробуйте ещё раз" << endl;
						i--;
						continue;
					}

					string chosenCharacteriscic = characteristicsForHuman[userCharacteristicChoise - 1];

					if (chosenCharacteriscic == "Сила")
					{
						characteristics.strength += 1;
						characteristicsForHuman.erase(characteristicsForHuman.begin() + (userCharacteristicChoise - 1));
					}
					else if (chosenCharacteriscic == "Ловкость")
					{
						characteristics.dexterity += 1;
						characteristicsForHuman.erase(characteristicsForHuman.begin() + (userCharacteristicChoise - 1));
					}
					else if (chosenCharacteriscic == "Телосложение")
					{
						characteristics.constitution += 1;
						characteristicsForHuman.erase(characteristicsForHuman.begin() + (userCharacteristicChoise - 1));
					}
					else if (chosenCharacteriscic == "Интелект")
					{
						characteristics.intelligence += 1;
						characteristicsForHuman.erase(characteristicsForHuman.begin() + (userCharacteristicChoise - 1));
					}
					else if (chosenCharacteriscic == "Мудрость")
					{
						characteristics.wisdom += 1;
						characteristicsForHuman.erase(characteristicsForHuman.begin() + (userCharacteristicChoise - 1));
					}
					else if (chosenCharacteriscic == "Харизма")
					{
						characteristics.charisma += 1;
						characteristicsForHuman.erase(characteristicsForHuman.begin() + (userCharacteristicChoise - 1));
					}
				}

				//Убираем из списка выше все навыки, которые уже есть у персонажа
				for (int i = 0; i < masterySkills.size(); i++)
				{
					for (int j = 0; j < skillsToChose.size(); j++)
					{
						if (masterySkills[i] == skillsToChose[j])
						{
							skillsToChose.erase(skillsToChose.begin() + j);
							break;
						}
					}
				}

				cout << "Выберите 1 навык для изучения: " << endl;
				for (int j = 1; j <= skillsToChose.size(); j++)
				{
					cout << j << ". " << skillsToChose[j - 1] << endl;
				}
				int chosenSkill;
				do
				{
					cin >> chosenSkill;
					if (chosenSkill <= skillsToChose.size())
					{
						skills.push_back(skillsToChose[chosenSkill - 1]);
						skillsToChose.erase(skillsToChose.begin() + (chosenSkill - 1));
					}
					else
					{
						cout << "Неверный ввод. Попробуйте ещё раз" << endl;
					}
				} while (!(1 <= chosenSkill <= skillsToChose.size()));
				
				break;
			default:
				cout << "Неверный ввод. Попробуйте ещё раз" << endl;
			}
		} while (!(1 <= humanChoise <= 2));
	}

	// Эльф
	else if (userInput == 9)
	{
		characteristics.dexterity += 2;
		speed = 30;
		masterySkills.push_back("Восприятие");
		skills.push_back("Наследие фей");
		skills.push_back("Транс");
		otherProficienciesAndLanguages["Языки"] = { "Общий", "Эльфийский" };

		// Подраса
		int raceChoise;
		do
		{
			cout << "Выберите 1 из 3-х: \n1) Высший эльф\t2) Лесной эльф\t3) Тёмный эльф (Дроу)" << endl;
			cin >> raceChoise;
			switch (raceChoise)
			{
			case 1:
				otherProficienciesAndLanguages["Тёмное зрение"] = { "60 футов" };
				characteristics.intelligence += 1;
				otherProficienciesAndLanguages["Оружие"] = { "Длинный меч", "Короткий меч", "Длинный лук", "Короткий лук" };
				skills.push_back("Заговор");
				otherProficienciesAndLanguages["Языки"] = { "Любой на выбор" };
				break;
			case 2:
				otherProficienciesAndLanguages["Тёмное зрение"] = { "60 футов" };
				characteristics.wisdom += 1;
				otherProficienciesAndLanguages["Оружие"] = { "Длинный меч", "Короткий меч", "Длинный лук", "Короткий лук" };
				speed = 35;
				skills.push_back("Маскировка в дикой местности");
			case 3:
				characteristics.charisma += 1;
				otherProficienciesAndLanguages["Тёмное зрение"] = { "120 футов" };
				skills.push_back("Чувствительность к солнцу");
				skills.push_back("Магия дроу");
				otherProficienciesAndLanguages["Оружие"] = { "Рапира", "Короткий меч", "Ручной арбалет" };
				break;
			default:
				cout << "Неверный ввод. Попробуйте ещё раз" << endl;
			}
		} while (!(raceChoise == 1 || raceChoise == 2 || raceChoise == 3));
	}
}

void Character::SetBackground()
{
	cout << "Выберите предысторию (цифрой): " << endl;
	for (int i = 1; i <= BackgroundsVector.size(); i++)
	{
		cout << i << ". " << BackgroundsVector[i - 1] << endl;
	}

	int userInput;
	do
	{

	} while (!(1 <= userInput <= BackgroundsVector.size()));
}