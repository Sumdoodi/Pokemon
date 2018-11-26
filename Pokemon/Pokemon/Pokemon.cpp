#include "Pokemon.h"

Pokemon::Pokemon()
{
	stat = Stats();
	ty = "none";
	ty2 = "none";
	status = "none";
	move1 = Moves();
	move2 = Moves();
	move3 = Moves();
	move4 = Moves();
}

Pokemon::Pokemon(std::string, Stats newStats, std::string newTY, std::string newTY2, std::string newSTATUS, Moves newMove1, Moves newMove2, Moves newMove3, Moves newMove4)
{
	stat = newStats;
	ty = newTY;
	ty2 = newTY2;
	status = newSTATUS;
	move1 = newMove1;
	move2 = newMove2;
	move3 = newMove3;
	move4 = newMove4;
}
