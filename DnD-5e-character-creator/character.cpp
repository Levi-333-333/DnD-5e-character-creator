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

vector<string> CharacteristicsVector = 
{ 
	"Сила", 
	"Ловкость", 
	"Телосложение", 
	"Интелект", 
	"Мудрость", 
	"Харизма" 
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

Wallet::Wallet()
{
	copper = 0;
	silver = 0;
	electrum = 0;
	gold = 0;
	platinum = 0;
}

// Зона ответственноси Дарии
void Character::PrintInfo()
{
	// Header
	cout << "Имя персонажа: " << name << "\t\t Класс: " << characterClass << "   Предыстория: " << background << "   Имя игрока:" << playerName << endl;
	cout << "\t\t" << "Раса: " << race << "   Мировоззрение: " << worldview << "   Опыт: " << experience << "   Уровень: " << level << endl << endl;

	// Left part of character's list

}

void Character::SetName()
{
	cout << "Введите имя вашему персонажу: ";
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
			cout << "Выберите наследие драконов:\n1) Белый\t2) Бронзовый\t3) Зелёный\t4) Золотой\n5) Красный\t6) Латунный\t7) Медный\t8) Серебрянный\n9) Синий\t10) Чёрный" << endl;
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
			cout << "Выбирете " << i + 1 << "-ю характеристику, значение которых повысится на 1: " << endl;
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
		vector<string> CharacteristicsVector = { "Сила", "Ловкость", "Телосложение", "Интелект", "Мудрость", "Харизма" };
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
					for (int j = 1; j <= CharacteristicsVector.size(); j++)
					{
						cout << j << ". " << CharacteristicsVector[j - 1] << endl;
					}
					cin >> userCharacteristicChoise;

					if (userCharacteristicChoise > CharacteristicsVector.size())
					{
						cout << "Неверный ввод. Попробуйте ещё раз" << endl;
						i--;
						continue;
					}

					string chosenCharacteriscic = CharacteristicsVector[userCharacteristicChoise - 1];

					if (chosenCharacteriscic == "Сила")
					{
						characteristics.strength += 1;
						CharacteristicsVector.erase(CharacteristicsVector.begin() + (userCharacteristicChoise - 1));
					}
					else if (chosenCharacteriscic == "Ловкость")
					{
						characteristics.dexterity += 1;
						CharacteristicsVector.erase(CharacteristicsVector.begin() + (userCharacteristicChoise - 1));
					}
					else if (chosenCharacteriscic == "Телосложение")
					{
						characteristics.constitution += 1;
						CharacteristicsVector.erase(CharacteristicsVector.begin() + (userCharacteristicChoise - 1));
					}
					else if (chosenCharacteriscic == "Интелект")
					{
						characteristics.intelligence += 1;
						CharacteristicsVector.erase(CharacteristicsVector.begin() + (userCharacteristicChoise - 1));
					}
					else if (chosenCharacteriscic == "Мудрость")
					{
						characteristics.wisdom += 1;
						CharacteristicsVector.erase(CharacteristicsVector.begin() + (userCharacteristicChoise - 1));
					}
					else if (chosenCharacteriscic == "Харизма")
					{
						characteristics.charisma += 1;
						CharacteristicsVector.erase(CharacteristicsVector.begin() + (userCharacteristicChoise - 1));
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
				break;
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
		cin >> userInput;
		if (!(1 <= userInput <= BackgroundsVector.size()))
		{
			cout << "Неверный ввод. Попробуйте ещё раз" << endl;
			continue;
		}
		
		background = BackgroundsVector[userInput - 1];

		switch (userInput)
		{
		// Артист
		case 1:
			masterySkills.push_back("Акробатика");
			masterySkills.push_back("Выступление");
			otherProficienciesAndLanguages["Инструменты"] = { "Набор для грима", "Музыкальный инструмент на выбор" };
			inventory.push_back("Музыкальный инструмент на выбор");
			inventory.push_back("Подарок от поклонницы");
			inventory.push_back("Костюм");
			cash.gold += 15;
			skills.push_back("По многочисленным просьбам");
			break;
		// Беспризорник
		case 2:
			masterySkills.push_back("Ловкость рук");
			masterySkills.push_back("Скрытность");
			otherProficienciesAndLanguages["Инструменты"] = { "Воровские инструменты", "Набор для грима" };
			inventory.push_back("Маленький нож");
			inventory.push_back("Карта города, в котором вы выросли");
			inventory.push_back("Ручная мышь");
			inventory.push_back("Безделушка в память о родителях");
			inventory.push_back("комплект обычной одежды");
			cash.gold += 10;
			skills.push_back("Городские тайны");
			break;
		// Благородный
		case 3:
			masterySkills.push_back("История");
			masterySkills.push_back("Убеждение");
			otherProficienciesAndLanguages["Инструменты"] = { "Игровой набор на ваш выбор" };
			otherProficienciesAndLanguages["Языки"] = { "Любой на ваш выбор" };
			inventory.push_back("Комплект отличной одежды");
			inventory.push_back("Кольцо-печатка");
			inventory.push_back("Свиток с генеалогическим древом");
			cash.gold += 25;

			// Разновидности благородного
			int nestedUserInput;
			do
			{
				cout << "Выберите 1 из 2-х:\n1) Благородный\t2) Рыцарь" << endl;
				cin >> nestedUserInput;
				switch (nestedUserInput)
				{
				case 1:
					skills.push_back("Привилегированность");
					break;
				case 2:
					skills.push_back("Слуги");
					break;
				default:
					cout << "Неверный ввод. Попробуйте ещё раз" << endl;
				}
			} while (!(nestedUserInput == 1 || nestedUserInput == 2));
		// Гильдейский ремесленник
		//case 4:

		}
		
		

	} while (!(1 <= userInput <= BackgroundsVector.size()));
}

// Сделал Лев
void Character::SetWorldview()
{
	int userInput;
	cout << "Выберите 1 из 9-и:\n1) Законо-Добрый\t2) Нейтрально-Добрый\t3) Хаотично-Добрый\n4) Законо-Нейтральный\t5) Нейтральный\t6) Хаотично-Нейтральный\n7) Законо-Злой\t8) Нейтрально-Злой\t9) Хаотично-Злой" << endl;
	do
	{
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			worldview = "Законо-Добрый";
			break;
		case 2:
			worldview = "Нейтрально-Добрый";
			break;
		case 3:
			worldview = "Хаотично-Добрый";
			break;
		case 4:
			worldview = "Законо-Нейтральный";
			break;
		case 5:
			worldview = "Нейтральный";
			break;
		case 6:
			worldview = "Хаотично-Нейтральный";
			break;
		case 7:
			worldview = "Законо-Злой";
			break;
		case 8:
			worldview = "Нейтрально-Злой";
			break;
		case 9:
			worldview = "Хаотично-Злой";
			break;
		default:
			cout << "Неверный ввод. Попробуйте ещё раз" << endl;
		}
	} while (!(1 <= userInput <= 9));
}

// Сделал Лев
void Character::SetPlayerName()
{
	cout << "Введите ваше имя: ";
	getline(cin, playerName);
	cout << endl;
}

// Сделал Лев
void Character::SetExperience()
{
	// Так как программа ещё не подразумевает левелапы и т.п. вот так вот
	experience = 0;
}

// Сделал Лев
void Character::SetLevel(int _level)
{
	level = _level;

	// Расчёт бонуса мастерства
	if (1 <= level <= 4) masteryBonus = 2;
	else if (5 <= level <= 8) masteryBonus = 3;
	else if (9 <= level <= 12) masteryBonus = 4;
	else if (13 <= level <= 16) masteryBonus = 5;
	else if (17 <= level <= 20) masteryBonus = 6;
}

void Character::SetCharacteristics()
{
	int userInput;
	vector<int> standartChars = { 15, 14, 13, 12, 10, 8 };
	vector<int> fourD6;
	vector<int> randomChars;
	cout << "Выберите 1 из 2-х:\n1) Распределить стандартные значения\t2) Распределить случайные характеристики" << endl;
	do
	{
		cin >> userInput;
		switch (userInput)
		{
		// Стандартные хар-ки
		case 1:
			do
			{
				cout << "Характеристики: " << endl;
				for (int i = 1; i <= CharacteristicsVector.size(); i++)
				{
					cout << i << ". " << CharacteristicsVector[i - 1] << endl;
				}
				cout << endl << "Доступные значения: " << endl;
				for (int i = 1; i <= standartChars.size(); i++)
				{
					cout << i << ". " << standartChars[i - 1] << endl;
				}

				int chosenCharacteristics;
				cin >> chosenCharacteristics;

				if (chosenCharacteristics > CharacteristicsVector.size())
				{
					cout << "Неверный ввод. Попробуйте ещё раз" << endl;
					continue;
				}

				string chosenCharacteristicsString = CharacteristicsVector[chosenCharacteristics - 1];

				cout << "Выбранная характеристика: " << chosenCharacteristicsString << ". Выберите для неё значение: " << endl;
				for (int i = 1; i <= standartChars.size(); i++)
				{
					cout << i << ". " << standartChars[i - 1] << endl;
				}

				int chosenValueI;
				cin >> chosenValueI;

				if (chosenValueI > standartChars.size())
				{
					cout << "Неверный ввод. Попробуйте ещё раз" << endl;
					continue;
				}

				int chosenValue = standartChars[chosenValueI - 1];

				if (chosenCharacteristicsString == "Сила")
				{
					characteristics.strength += chosenValue;
					CharacteristicsVector.erase(CharacteristicsVector.begin() + (chosenCharacteristics - 1));
					standartChars.erase(standartChars.begin() + (chosenValueI - 1));
				}
				else if (chosenCharacteristicsString == "Ловкость")
				{
					characteristics.dexterity += chosenValue;
					CharacteristicsVector.erase(CharacteristicsVector.begin() + (chosenCharacteristics - 1));
					standartChars.erase(standartChars.begin() + (chosenValueI - 1));
				}
				else if (chosenCharacteristicsString == "Телосложение")
				{
					characteristics.constitution += chosenValue;
					CharacteristicsVector.erase(CharacteristicsVector.begin() + (chosenCharacteristics - 1));
					standartChars.erase(standartChars.begin() + (chosenValueI - 1));
				}
				else if (chosenCharacteristicsString == "Интелект")
				{
					characteristics.intelligence += chosenValue;
					CharacteristicsVector.erase(CharacteristicsVector.begin() + (chosenCharacteristics - 1));
					standartChars.erase(standartChars.begin() + (chosenValueI - 1));
				}
				else if (chosenCharacteristicsString == "Мудрость")
				{
					characteristics.wisdom += chosenValue;
					CharacteristicsVector.erase(CharacteristicsVector.begin() + (chosenCharacteristics - 1));
					standartChars.erase(standartChars.begin() + (chosenValueI - 1));
				}
				else if (chosenCharacteristicsString == "Харизма")
				{
					characteristics.charisma += chosenValue;
					CharacteristicsVector.erase(CharacteristicsVector.begin() + (chosenCharacteristics - 1));
					standartChars.erase(standartChars.begin() + (chosenValueI - 1));
				}
				
			} while (standartChars.size() != 0);

		default:
			break;
		}
	} while (!(1 <= userInput <= 2));
}