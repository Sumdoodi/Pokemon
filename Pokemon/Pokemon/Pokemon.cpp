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

Pokemon::Pokemon(std::string newName, Stats newStats, std::string newTY, std::string newTY2, std::string newSTATUS, Moves newMove1, Moves newMove2, Moves newMove3, Moves newMove4)
{
	name = newName;
	stat = newStats;
	ty = newTY;
	ty2 = newTY2;
	status = newSTATUS;
	move1 = newMove1;
	move2 = newMove2;
	move3 = newMove3;
	move4 = newMove4;
}

void Pokemon::useMove(Moves &move, Pokemon &other){
	int damage = 0;
	float modifier = 1;
	//typecompare(other, move);
	//modifier = typemodifier;
	if (move.getCAT() == "P") {
		damage = (((22 * move.getPOW()*stat.getATK() / other.stat.getDEF()) / 50) + 2) * modifier;
	}
	else if (move.getCAT() == "Sp") {
		damage = (((22 * move.getPOW()*stat.getSpATK() / other.stat.getSpDEF()) / 50) + 2) * modifier;
	}

	other.stat.setHP(other.stat.getHP() - damage);
}

void Pokemon::typecompare(Pokemon other, Moves usedMove)
{

	if (usedMove.getTY() == "normal")
	{
		if (other.ty == "rock" || other.ty == "steel")
			typemodifier = 0.5f;
		else if (other.ty == "ghost")
			typemodifier = 0.0f;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "fighting")
	{
		if (other.ty == "flying" || other.ty == "poison" || other.ty == "bug" || other.ty == "psychic" || other.ty == "fairy")
			typemodifier = 0.5f;
		else if (other.ty == "ghost")
			typemodifier = 0.0f;
		else if (other.ty == "normal" || other.ty == "rock" || other.ty == "ice" || other.ty == "dark")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "flying")
	{
		if (other.ty == "rock" || other.ty == "steel" || other.ty == "electric" || other.ty == "fairy")
			typemodifier = 0.5f;
		else if (other.ty == "fighting" || other.ty == "bug" || other.ty == "grass")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "poison")
	{
		if (other.ty == "poison" || other.ty == "ground" || other.ty == "rock" || other.ty == "ghost")
			typemodifier = 0.5f;
		else if (other.ty == "steel")
			typemodifier = 0.0f;
		else if (other.ty == "grass" || other.ty == "fairy")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "ground")
	{
		if (other.ty == "bug" || other.ty == "grass")
			typemodifier = 0.5f;
		else if (other.ty == "flying")
			typemodifier = 0.0f;
		else if (other.ty == "poison" || other.ty == "rock" || other.ty == "steel" || other.ty == "fire" || other.ty == "electric")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "rock")
	{
		if (other.ty == "fighting" || other.ty == "ground" || other.ty == "steel")
			typemodifier = 0.5f;
		else if (other.ty == "flying" || other.ty == "bug" || other.ty == "fire" || other.ty == "ice")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	if (usedMove.getTY() == "bug")
	{
		if (other.ty == "fighting" || other.ty == "flying" || other.ty == "poison" || other.ty == "ghost" || other.ty == "steel" || other.ty == "fire" || other.ty == "fairy")
			typemodifier = 0.5f;
		else if (other.ty == "grass" || other.ty == "psychic" || other.ty == "dark")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "ghost")
	{
		if (other.ty == "dark")
			typemodifier = 0.5f;
		else if (other.ty == "normal")
			typemodifier = 0.0;
		else if (other.ty == "ghost" || other.ty == "psychic")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "steel")
	{
		if (other.ty == "steel" || other.ty == "fire" || other.ty == "water" || other.ty == "electric")
			typemodifier = 0.5f;
		else if (other.ty == "rock" || other.ty == "ice" || other.ty == "fairy")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "steel")
	{
		if (other.ty == "rock" || other.ty == "fire" || other.ty == "water" || other.ty == "dragon")
			typemodifier = 0.5f;
		else if (other.ty == "bug" || other.ty == "steel" || other.ty == "grass" || other.ty == "ice")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "water")
	{
		if (other.ty == "water" || other.ty == "grass" || other.ty == "dragon")
			typemodifier = 0.5f;
		else if (other.ty == "ground" || other.ty == "rock" || other.ty == "fire")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "grass")
	{
		if (other.ty == "flying" || other.ty == "poison" || other.ty == "bug" || other.ty == "steel" || other.ty == "fire" || other.ty == "grass" || other.ty == "dragon")
			typemodifier = 0.5f;
		else if (other.ty == "ground" || other.ty == "rock" || other.ty == "water")
			typemodifier = 2.0;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "electric")
	{
		if (other.ty == "grass" || other.ty == "electric" || other.ty == "dragon")
			typemodifier = 0.5f;
		else if (other.ty == "flying" || other.ty == "water")
			typemodifier = 2.0;
		else if (other.ty == "ground")
			typemodifier = 0.0;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "psychic")
	{
		if (other.ty == "steel" || other.ty == "psychic")
			typemodifier = 0.5f;
		else if (other.ty == "fighting" || other.ty == "poison")
			typemodifier = 2.0;
		else if (other.ty == "dark")
			typemodifier = 0.0;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "ice")
	{
		if (other.ty == "steel" || other.ty == "fire" || other.ty == "water" || other.ty == "ice")
			typemodifier = 0.5f;
		else if (other.ty == "flying" || other.ty == "ground" || other.ty == "grass" || other.ty == "dragon")
			typemodifier = 2.0;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "dragon")
	{
		if (other.ty == "steel")
			typemodifier = 0.5f;
		else if (other.ty == "dragon")
			typemodifier = 2.0;
		else if (other.ty == "dark")
			typemodifier = 0.0;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "dark")
	{
		if (other.ty == "fighting" || other.ty == "dark" || other.ty == "fairy")
			typemodifier = 0.5f;
		else if (other.ty == "ghost" || other.ty == "psychic")
			typemodifier = 2.0;
		else
			typemodifier = 1.0f;
	}
	else if (usedMove.getTY() == "fairy")
	{
		if (other.ty == "poison" || other.ty == "steel" || other.ty == "fire")
			typemodifier = 0.5f;
		else if (other.ty == "fighting" || other.ty == "dragon" || other.ty == "dark")
			typemodifier = 2.0;
		else
			typemodifier = 1.0f;
	}
}
