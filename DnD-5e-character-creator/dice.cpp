#include "dice.h"

int RollDice(int face)
{
	return rand() % face + 1;
}