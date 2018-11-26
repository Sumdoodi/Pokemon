#include <iostream>
#include "Stats.h"

Stats::Stats()
{
	HP = 0;
	ATK = 0;
	DEF = 0;
	SpATK = 0;
	SpDEF = 0;
	SPD = 0;
	acc = 0;
	eva = 0;
}

Stats::Stats(int newHP, int newATK, int newDEF, int newSpATK, int newSpDEF, int newSPD)
{
	HP = newHP;
	ATK = newATK;
	DEF = newDEF;
	SpATK = newSpATK;
	SpDEF = newSpDEF;
	SPD = newSPD;
}

Stats::Stats(int newHP, int newATK, int newDEF, int newSpATK, int newSpDEF, int newSPD, double newACC, double newEVA)
{
	HP = newHP;
	ATK = newATK;
	DEF = newDEF;
	SpATK = newSpATK;
	SpDEF = newSpDEF;
	SPD = newSPD;
	acc = newACC;
	eva = newEVA;
}

int Stats::getHP()
{
	return HP;
}

void Stats::setHP(int newHP)
{
	HP = newHP;
}

int Stats::getATK()
{
	return ATK;
}

void Stats::setATK(int newATK)
{
	ATK = newATK;
}

int Stats::getDEF()
{
	return DEF;
}

void Stats::setDEF(int newDEF)
{
	DEF = newDEF;
}

int Stats::getSpATK()
{
	return SpATK;
}

void Stats::setSpATK(int newSpATK)
{
	SpATK = newSpATK;
}

int Stats::getSpDEF()
{
	return SpDEF;
}

void Stats::setSpDEF(int SpDEF)
{
	DEF = SpDEF;
}

int Stats::getSPD()
{
	return SPD;
}

void Stats::setSPD(int newSPD)
{
	SPD = newSPD;
}

double Stats::getACC()
{
	return acc;
}

void Stats::setACC(double newACC)
{
	acc = newACC;
}

double Stats::getEVA()
{
	return eva;
}

void Stats::setEVA(double newACC)
{
	acc = newACC;
}