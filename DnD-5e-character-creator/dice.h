#pragma once
#include <ctime>
#include <cstdlib>

#define D4 RollDice(4)
#define D6 RollDice(6)

int RollDice(int face)
{
	return rand() % face + 1;
}