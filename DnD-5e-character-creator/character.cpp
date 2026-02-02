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

vector<string> SkillsVector = 
{ 
	"Акробатика", 
	"Анализ", 
	"Атлетика", 
	"Восприятие", 
	"Выживание", 
	"Выступление", 
	"Запугивание", 
	"История", 
	"Ловкость рук", 
	"Магия", 
	"Медицина", 
	"Обман", 
	"Природа", 
	"Проницательность", 
	"Религия", 
	"Скрытность", 
	"Убеждение", 
	"Уход за животными" 
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
		maxHits = hitDice + characteristics.constitutionMod;
		otherProficienciesAndLanguages["Доспехи"] = { "Лёгкие доспехи" };
		otherProficienciesAndLanguages["Оружие"] = { "Простое оружие", "Длинный меч", "Короткий меч", "Рапиры", "Ручной арбалет" };
		otherProficienciesAndLanguages["Инструменты"] = { "Музыкальный инструмент на выбор", "Музыкальный инструмент на выбор", "Музыкальный инструмент на выбор" };
		savingThrowsSkills.push_back("Ловкость");
		savingThrowsSkills.push_back("Харизма");

		for (int i = 0; i < masterySkills.size(); i++)
		{
			for (int j = 0; j < SkillsVector.size(); j++)
			{
				if (masterySkills[i] == SkillsVector[j])
				{
					SkillsVector.erase(SkillsVector.begin() + j);
					break;
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			cout << "Выберите " << i + 1 << "-й навык (из 3-х) для изучения: " << endl;
			for (int j = 1; j <= SkillsVector.size(); j++)
			{
				cout << j << ". " << SkillsVector[j - 1] << endl;
			}
			int chosenSkill;
			cin >> chosenSkill;
			if (chosenSkill <= SkillsVector.size())
			{
				masterySkills.push_back(SkillsVector[chosenSkill - 1]);
				SkillsVector.erase(SkillsVector.begin() + (chosenSkill - 1));
			}
			else
			{
				cout << "Неверный ввод. Попробуйте ещё раз" << endl;
				i--;
			}
		}

		int userInput;
		cout << "Выберите 1 из 2-х:\n1) Выбрать начальное снаряжение\t2) Получить 5d4 * 10 золотых монет" << endl;
		do
		{
			cin >> userInput;
			switch (userInput)
			{
			case 1:
				cout << "Выберите 1 из 3-х:\n1) Рапира\t2) Длинный меч\t3) Любое простое оружие" << endl;
				int nestedUserInput;
				do
				{
					cin >> nestedUserInput;
					switch (nestedUserInput)
					{
					case 1:
						inventory.push_back("Рапира");
						break;
					case 2:
						inventory.push_back("Длинный меч");
						break;
					case 3:
						inventory.push_back("Любое простое оружие");
						break;
					default:
						cout << "Неверный ввод. Попробуйте ещё раз" << endl;
					}
				} while (!(1 <= nestedUserInput <= 3));

				cout << "Выберите 1 из 2-х:\n1) Набор дипломата\t2) Набор артиста" << endl;
				do
				{
					cin >> nestedUserInput;
					switch (nestedUserInput)
					{
					case 1:
						inventory.push_back("Набор дипломата");
						break;
					case 2:
						inventory.push_back("Набор артиста");
						break;
					default:
						cout << "Неверный ввод. Попробуйте ещё раз" << endl;
					}
				} while (!(1 <= nestedUserInput <= 2));

				inventory.push_back("Любой музыкальный инструмент");
				inventory.push_back("Кожаный доспех");
				inventory.push_back("Кинжал");

				skills.push_back("Использование заклинаний");
				skills.push_back("Вдохновение барда (к6)");
			case 2:
				cash.gold += (D4, D4, D4, D4, D4) * 10;
				break;
			default:
				cout << "Неверный ввод. Попробуйте ещё раз" << endl;
			}
		} while (!(1 <= userInput <= 2));
	}
	// Варвар
	else if (chosenClass == 2)
	{

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

// Сделала Рия
void Character::SetBackground()
{
	cout << "Выберите предысторию (цифрой): " << endl;
	for (int i = 1; i <= BackgroundsVector.size(); i++)
	{
		cout << i << ". " << BackgroundsVector[i - 1] << endl;
	}

	int userInput;
	bool endCycle = true;
	do
	{
		cin >> userInput;
		if (!(userInput >= 1 && userInput <= BackgroundsVector.size()))
		{
			cout << "Неверный ввод. Попробуйте ещё раз" << endl;
			endCycle = false;
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
			endCycle = true;
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
			endCycle = true;
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
			endCycle = true;
			break;
		// Гильдейский ремесленник
		case 4:
			masterySkills.push_back("Проницательность");
			masterySkills.push_back("Убеждение");
			otherProficienciesAndLanguages["Инструменты"] = { "Один вид ремесленных инструментов на выбор" };
			otherProficienciesAndLanguages["Языки"] = { "Один на выбор" };
			inventory.push_back("Один вид ремесленных инструментов");
			inventory.push_back("Рекомендательное письмо из гильдии");
			inventory.push_back("Комплект дорожной одежды");
			cash.gold += 15;
			skills.push_back("Членство в гильдии");
			endCycle = true;
			break;
		// Моряк
		case 5:
			masterySkills.push_back("Атлетика");
			masterySkills.push_back("Восприятие");
			otherProficienciesAndLanguages["Инструменты"] = { "Инструменты навигатора", "Транспорт (водный)" };
			inventory.push_back("Дубинка");
			inventory.push_back("50 футов шёлковой верёвки");
			inventory.push_back("Талисман");
			inventory.push_back("Комплект обычной обежды");
			cash.gold += 10;
			skills.push_back("Поездка на корабле");
			endCycle = true;
			break;
		// Мудрец
		case 6:
			masterySkills.push_back("История");
			masterySkills.push_back("Магия");
			otherProficienciesAndLanguages["Языки"] = { "Язык на ваш выбор", "Язык на ваш выбор" };
			inventory.push_back("Бутылочка чернил");
			inventory.push_back("Писчее перо");
			inventory.push_back("Небольшой нож");
			inventory.push_back("Письмо от мёртвого коллеги с вопросом, на который вы пока не можете ответить");
			inventory.push_back("Комплект обычной одежды");
			cash.gold += 10;
			skills.push_back("Исследователь");
			endCycle = true;
			break;
		// Народный герой
		case 7:
			masterySkills.push_back("Выживание");
			masterySkills.push_back("Уход за животными");
			otherProficienciesAndLanguages["Инструменты"] = { "Один вид ремесленных инструментов", "Транспортное средство (наземное)" };
			inventory.push_back("Ремесленный инструмент на выбор");
			inventory.push_back("Лопата");
			inventory.push_back("Железный горшок");
			inventory.push_back("Комплект обычной одежды");
			cash.gold += 10;
			skills.push_back("Деревенское гостеприимство");
			endCycle = true;
			break;
		// Отшельник
		case 8:
			masterySkills.push_back("Медицина");
			masterySkills.push_back("Религия");
			otherProficienciesAndLanguages["Инструменты"] = { "Набор травника" };
			otherProficienciesAndLanguages["Языки"] = { "Один на выбор" };
			inventory.push_back("Контейнер для свитков, битком набитый вашими молитвами и изысканиями");
			inventory.push_back("Тёплое одеяло");
			inventory.push_back("Комплект обычной одежды");
			inventory.push_back("Набор травника");
			cash.gold += 5;
			skills.push_back("Откровение");
			endCycle = true;
			break;
		// Пират
		case 9:
			masterySkills.push_back("Атлетика");
			masterySkills.push_back("Восприятие");
			otherProficienciesAndLanguages["Инструменты"] = { "Инструменты навигатора", "Транспорт (водяной)" };
			inventory.push_back("Дубинка");
			inventory.push_back("50 футов шёлковой верёвки");
			inventory.push_back("Талисман");
			inventory.push_back("Комплект обычной обежды");
			cash.gold += 10;
			skills.push_back("Дурная репутация");
			endCycle = true;
			break;
		// Преступник
		case 10:
			masterySkills.push_back("Обман");
			masterySkills.push_back("Скрытность");
			otherProficienciesAndLanguages["Инструменты"] = { "Воровские инструменты", "Игровой набор на выбор" };
			inventory.push_back("Ломик");
			inventory.push_back("Ломик");
			cash.gold += 15;
			skills.push_back("Криминальные связи");
			endCycle = true;
			break;
		// Прислужник
		case 11:
			masterySkills.push_back("Проницательность");
			masterySkills.push_back("Религия");
			otherProficienciesAndLanguages["Языки"] = { "Один на ваш выбор", "Один на ваш выбор" };
			inventory.push_back("Священный символ");
			inventory.push_back("Молитвенник или молитвенный барабан");
			inventory.push_back("5 палочек благовоний");
			inventory.push_back("Ряса");
			inventory.push_back("Комплект обычной одежды");
			cash.gold += 15;
			skills.push_back("Приют для верующих");
			endCycle = true;
			break;
		// Солдат
		case 12:
			masterySkills.push_back("Атлетика");
			masterySkills.push_back("Запугивание");
			otherProficienciesAndLanguages["Инструменты"] = { "Игровой набор на выбор", "Транспорт (сухопутный)" };
			inventory.push_back("Знак отличия");
			inventory.push_back("Трофей с убитого врага");
			inventory.push_back("Набор игровых костей или колода карт");
			inventory.push_back("Комплект обычной одежды");
			cash.gold += 10;
			skills.push_back("Воинское звание");
			endCycle = true;
			break;
		// Чужеземец
		case 13:
			masterySkills.push_back("Атлетика");
			masterySkills.push_back("Выживание");
			otherProficienciesAndLanguages["Инструменты"] = { "Музыкальный инструмент на выбор" };
			otherProficienciesAndLanguages["Языки"] = { "Один на выбор" };
			inventory.push_back("Посох");
			inventory.push_back("Капкан");
			inventory.push_back("Трофей с убитого животного");
			inventory.push_back("Комплект дорожной одежды");
			cash.gold += 10;
			skills.push_back("Странник");
			endCycle = true;
			break;
		// Шарлатан
		case 14:
			masterySkills.push_back("Ловкость рук");
			masterySkills.push_back("Обман");
			otherProficienciesAndLanguages["Инструменты"] = { "Набор для грима", "Набор для фальсификации" };
			inventory.push_back("Комплект отличной одежды");
			inventory.push_back("Набор для грима");
			inventory.push_back("Приспособление для жульничества на ваш выбор");
			cash.gold += 15;
			skills.push_back("Персонализация");
			endCycle = true;
			break;
		}
	} while (!endCycle);
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

// Сделал Лев
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
				cout << "Выберите характеристику: ";
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
			break;
		case 2:
			for (int i = 0; i < 6; i++)
			{
				fourD6.push_back(D6);
				fourD6.push_back(D6);
				fourD6.push_back(D6);
				fourD6.push_back(D6);

				int minInFourD6 = fourD6[0];
				for (int j = 1; j < fourD6.size(); j++)
				{
					if (minInFourD6 > fourD6[j]) minInFourD6 = fourD6[j];
				}

				int sumAllD6 = 0;
				for (int j = 0; j < fourD6.size(); j++)
				{
					sumAllD6 += fourD6[j];
				}
				sumAllD6 -= minInFourD6;

				randomChars.push_back(sumAllD6);

				sumAllD6 = 0;
				fourD6.clear();
			}
			do
			{
				cout << "Характеристики: " << endl;
				for (int i = 1; i <= CharacteristicsVector.size(); i++)
				{
					cout << i << ". " << CharacteristicsVector[i - 1] << endl;
				}
				cout << endl << "Доступные значения: " << endl;
				for (int i = 1; i <= randomChars.size(); i++)
				{
					cout << i << ". " << randomChars[i - 1] << endl;
				}

				cout << "Выберите характеристику: ";
				int chosenCharacteristics;
				cin >> chosenCharacteristics;
				cout << endl;

				if (chosenCharacteristics > CharacteristicsVector.size())
				{
					cout << "Неверный ввод. Попробуйте ещё раз" << endl;
					continue;
				}

				string chosenCharacteristicsString = CharacteristicsVector[chosenCharacteristics - 1];

				cout << "Выбранная характеристика: " << chosenCharacteristicsString << ". Выберите для неё значение: " << endl;
				for (int i = 1; i <= randomChars.size(); i++)
				{
					cout << i << ". " << randomChars[i - 1] << endl;
				}

				int chosenValueI;
				cin >> chosenValueI;

				if (chosenValueI > randomChars.size())
				{
					cout << "Неверный ввод. Попробуйте ещё раз" << endl;
					continue;
				}

				int chosenValue = randomChars[chosenValueI - 1];

				if (chosenCharacteristicsString == "Сила")
				{
					characteristics.strength += chosenValue;
					CharacteristicsVector.erase(CharacteristicsVector.begin() + (chosenCharacteristics - 1));
					randomChars.erase(randomChars.begin() + (chosenValueI - 1));
				}
				else if (chosenCharacteristicsString == "Ловкость")
				{
					characteristics.dexterity += chosenValue;
					CharacteristicsVector.erase(CharacteristicsVector.begin() + (chosenCharacteristics - 1));
					randomChars.erase(randomChars.begin() + (chosenValueI - 1));
				}
				else if (chosenCharacteristicsString == "Телосложение")
				{
					characteristics.constitution += chosenValue;
					CharacteristicsVector.erase(CharacteristicsVector.begin() + (chosenCharacteristics - 1));
					randomChars.erase(randomChars.begin() + (chosenValueI - 1));
				}
				else if (chosenCharacteristicsString == "Интелект")
				{
					characteristics.intelligence += chosenValue;
					CharacteristicsVector.erase(CharacteristicsVector.begin() + (chosenCharacteristics - 1));
					randomChars.erase(randomChars.begin() + (chosenValueI - 1));
				}
				else if (chosenCharacteristicsString == "Мудрость")
				{
					characteristics.wisdom += chosenValue;
					CharacteristicsVector.erase(CharacteristicsVector.begin() + (chosenCharacteristics - 1));
					randomChars.erase(randomChars.begin() + (chosenValueI - 1));
				}
				else if (chosenCharacteristicsString == "Харизма")
				{
					characteristics.charisma += chosenValue;
					CharacteristicsVector.erase(CharacteristicsVector.begin() + (chosenCharacteristics - 1));
					randomChars.erase(randomChars.begin() + (chosenValueI - 1));
				}

			} while (CharacteristicsVector.size() != 0);
			break;
		default:
			cout << "Неверный ввод. Попробуйте ещё раз" << endl;
		}
	} while (!(1 <= userInput <= 2));
}

// Сделал Лев
void Character::SetModifficators()
{
	characteristics.strengthMod = (characteristics.strength - 10) / 2;
	characteristics.dexterityMod = (characteristics.dexterity - 10) / 2;
	characteristics.constitutionMod = (characteristics.constitution - 10) / 2;
	characteristics.intelligenceMod = (characteristics.intelligence - 10) / 2;
	characteristics.wisdomMod = (characteristics.wisdom - 10) / 2;
	characteristics.charismaMod = (characteristics.charisma - 10) / 2;
}

// Сделала Рия
void Character::SetPassivePerception()
{
	bool havePerception = false;
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i] == "Восприятие") havePerception = true;
	}
	if (havePerception) passivePerception = 10 + characteristics.wisdom + masteryBonus;
	else passivePerception = 10 + characteristics.wisdom;
}

// Сделала Рия
void Character::SetInitiative()
{
	initiative = characteristics.dexterityMod;
}

// Сделала Рия
void Character::SetClassArmor()
{
	for (int i = 0; i < inventory.size(); i++)
	{
		// Лёгкий доспех
		if (inventory[i] == "Стёганый доспех") classArmor = 11 + characteristics.dexterityMod;
		if (inventory[i] == "Кожаный доспех") classArmor = 11 + characteristics.dexterityMod;
		if (inventory[i] == "Проклёпанный кожаный доспех") classArmor = 12 + characteristics.dexterityMod;
		// Средний доспех
		if (inventory[i] == "Шкурный доспех")
		{
			if (characteristics.dexterityMod > 2) classArmor = 12 + 2;
			else classArmor = 12 + characteristics.dexterityMod;
		}
		if (inventory[i] == "Кольчужная рубаха")
		{
			if (characteristics.dexterityMod > 2) classArmor = 13 + 2;
			else classArmor = 13 + characteristics.dexterityMod;
		}
		if (inventory[i] == "Чешуйчатый доспех")
		{
			if (characteristics.dexterityMod > 2) classArmor = 14 + 2;
			else classArmor = 14 + characteristics.dexterityMod;
		}
		if (inventory[i] == "Кираса")
		{
			if (characteristics.dexterityMod > 2) classArmor = 14 + 2;
			else classArmor = 14 + characteristics.dexterityMod;
		}
		if (inventory[i] == "Полулаты")
		{
			if (characteristics.dexterityMod > 2) classArmor = 15 + 2;
			else classArmor = 15 + characteristics.dexterityMod;
		}
		// Тяжёлый доспех
		if (inventory[i] == "Колечный доспех") classArmor = 14;
		if (inventory[i] == "Кольчуга") classArmor = 16;
		if (inventory[i] == "Наборный доспех") classArmor = 17;
		if (inventory[i] == "Латы") classArmor = 18;
		// Щит
		if (inventory[i] == "Щит") classArmor += 2;
	}
}

// Сделала Рия
void Character::SetCharacterTraits()
{
	cout << "Введите черты характера: " << endl;
	getline(cin, characterTraits);
	cout << endl;
}
void Character::SetIdeals()
{
	cout << "Введите идеалы: " << endl;
	getline(cin, ideals);
	cout << endl;
}
void Character::SetAffections()
{
	cout << "Введите привязанности: " << endl;
	getline(cin, affections);
	cout << endl;
}
void Character::SetWeaknesses()
{
	cout << "Введите слабости: " << endl;
	getline(cin, weaknesses);
	cout << endl;
}

void Character::PrintInfo()
{
	cout << "Имя персонажа: " << name << "\t\t Класс: " << characterClass << "   Предыстория: " << background << "   Имя игрока:" << playerName << endl;
	cout << "\t\t" << "Раса: " << race << "   Мировоззрение: " << worldview << "   Опыт: " << experience << "   Уровень: " << level << endl << endl;

	cout << "Сила\n" << characteristics.strength << endl << "(" << characteristics.strengthMod << ")" << endl;
	cout << "Ловкость\n" << characteristics.dexterity << endl << "(" << characteristics.dexterityMod << ")" << endl;
	cout << "Телосложение\n" << characteristics.constitution << endl << "(" << characteristics.constitutionMod << ")" << endl;
	cout << "Интелект\n" << characteristics.intelligence << endl << "(" << characteristics.intelligenceMod << ")" << endl;
	cout << "Мудрость\n" << characteristics.wisdom << endl << "(" << characteristics.wisdomMod << ")" << endl;
	cout << "Харизма\n" << characteristics.charisma << endl << "(" << characteristics.charismaMod << ")" << endl << endl;

	cout << "Бонус мастерства: +" << masteryBonus << endl;

	cout << "Владения спасбросками: ";
	for (int i = 0; i < savingThrowsSkills.size(); i++)
	{
		if (!(i == (savingThrowsSkills.size() - 1))) cout << savingThrowsSkills[i] << ", ";
		else cout << savingThrowsSkills[i];
	}
	cout << endl;

	cout << "Владения навыками: ";
	for (int i = 0; i < masterySkills.size(); i++)
	{
		if (!(i == (masterySkills.size() - 1))) cout << masterySkills[i] << ", ";
		else cout << masterySkills[i];
	}
	cout << endl;

	cout << "Прочие владения и языки:" << endl;
	for (const auto& pair : otherProficienciesAndLanguages)
	{
		cout << pair.first << ": ";
		for (int i = 0; i < pair.second.size(); i++)
		{
			if (i == (pair.second.size() - 1)) cout << pair.second[i];
			else cout << pair.second[i] << ", ";
		}
		cout << endl;
	}
	cout << endl << endl;

	cout << "Класс брони: " << classArmor << "  Инициатива: " << initiative << "  Скорость: " << speed << endl;

	cout << "Максимум хитов: " << maxHits << endl;

	cout << "Кость хитов: d" << hitDice << endl << endl;

	cout << "ММ  СМ  ЭМ  ЗМ  ПМ" << endl;
	cout << cash.copper << "    " << cash.silver << "    " << cash.electrum << "    " << cash.gold << "    " << cash.platinum << endl;

	cout << "Снаряжение: " << endl;
	for (int i = 0; i < inventory.size(); i++)
	{
		if (i == (inventory.size() - 1)) cout << inventory[i];
		else cout << inventory[i] << ", ";
	}
	cout << endl << endl;

	cout << "Черты характера:" << endl << characterTraits << endl << "Идеалы:" << endl << ideals << endl;
	cout << "Привязанности:" << endl << affections << endl << "Слабости:" << endl << weaknesses << endl << endl;

	cout << "Умения и способности: " << endl;
	for (int i = 0; i < skills.size(); i++)
	{
		cout << skills[i] << endl;
	}
}