#pragma once
#include <iostream>
#include <string>
#include "Stats.h"
#include "Moves.h"

class Pokemon {
private:

public:
	std::string name; //Pokemon name

	Stats stat; //Statistics
	std::string ty; //Type 1
	std::string ty2; //Type 2
	std::string status; //Status Effect

	Moves move1; //First Move
	Moves move2; //Second Move
	Moves move3; //Third Move
	Moves move4; //Fourth Move

	float typemodifier;
	void typecompare(Pokemon, Moves);

	Pokemon();
	Pokemon(std::string, Stats, std::string, std::string, std::string, Moves, Moves, Moves, Moves);

	std::string getName() {
		return name;
	}

};

