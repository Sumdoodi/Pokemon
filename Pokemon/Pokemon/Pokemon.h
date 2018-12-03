#pragma once
#include <iostream>
#include <string>
#include "picture.h"
#include "Stats.h"
#include "Moves.h"

class Pokemon {
private:

public:
	std::string num; //Pokemon num
	std::string name; //Pokemon name

	Stats stat; //Statistics
	Picture img; //image
	std::string ty; //Type 1
	std::string ty2; //Type 2
	std::string status; //Status Effect
	bool confused;
	bool dontmove; //used for status effects
	bool flinched;
	bool charge = false;
	int chargeturn = 0;
	int chance;

	int accStage;
	float accMod;

	int evaStage;
	float evaMod;

	int atkStage;
	float atkMod;

	int defStage;
	float defMod;

	int spATKStage;
	float spATKMod;

	int spDEFStage;
	float spDEFMod;

	int spdStage;
	float spdMod;

	int sleepturrns; //how long the pokemon will be asleep for
	int confusionturns;//how long the pokemon will be confused for

	Moves move1; //First Move
	Moves move2; //Second Move
	Moves move3; //Third Move
	Moves move4; //Fourth Move

	float typemodifier;
	void typecompare(Pokemon, Moves);
	int critical(Moves);
	int stab(Moves);
	int burn(Moves);

	Pokemon();
	Pokemon(std::string, std::string, Stats, std::string, std::string, std::string, Moves, Moves, Moves, Moves, Picture);
	Pokemon(const Pokemon&);

	void changeMod(int&, float&);
	void changeAcc(int&, float&);
	void useMove(Moves&, Pokemon&);

	void statusEffectBP(Moves &usedMove);
	void statusEffect(Moves&);
	void secondaryEffect(Pokemon&, Moves&);

	void resetStages();

	std::string getName() {
		return name;
	}

};

