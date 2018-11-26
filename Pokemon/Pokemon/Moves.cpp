#include "Moves.h"
#include "Pokemon.h"

Moves::Moves(){
	pow = 0;
	pp = 0;
	acc = 0.f;
	ty = "none";
	cat = "none";
	sec = "none";
}

Moves::Moves(int newPOW, int newPP, float newACC, std::string newTY, std::string newCAT, std::string newSEC){
	pow = newPOW;
	pp = newPP;
	acc = newACC;
	ty = newTY;
	cat = newCAT;
	sec = newSEC;
	maxPP = pp;
}

Moves::Moves(std::string newName, int newPOW, int newPP, float newACC, std::string newTY, std::string newCAT, std::string newSEC) {
	name = newName;
	pow = newPOW;
	pp = newPP;
	acc = newACC;
	ty = newTY;
	cat = newCAT;
	sec = newSEC;
	maxPP = pp;
}

void Moves::typecompare(Pokemon other)
{

	if (ty == "normal")
	{
		if (other.ty == "rock" || other.ty == "steel")
			typemodifier = 0.5f;
		else if (other.ty == "ghost")
			typemodifier = 0.0f;
		else
			typemodifier = 1.0f;
	}

	if (ty == "fighting")
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
	if (ty == "flying")
	{
		if (other.ty == "rock" || other.ty == "steel" || other.ty == "electric" || other.ty == "fairy")
			typemodifier = 0.5f;
		else if (other.ty == "fighting" || other.ty == "bug" || other.ty == "grass")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	if (ty == "poison")
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
	if (ty == "ground")
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
	if (ty == "rock")
	{
		if (other.ty == "fighting" || other.ty == "ground" || other.ty == "steel")
			typemodifier = 0.5f;
		else if (other.ty == "flying" || other.ty == "bug" || other.ty == "fire" || other.ty == "ice")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	if (ty == "bug")
	{
		if (other.ty == "fighting" || other.ty == "flying" || other.ty == "poison" || other.ty == "ghost" || other.ty == "steel" || other.ty == "fire" || other.ty == "fairy")
			typemodifier = 0.5f;
		else if (other.ty == "grass" || other.ty == "psychic" || other.ty == "dark")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	if (ty == "ghost")
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
	if (ty == "steel")
	{
		if (other.ty == "steel" || other.ty == "fire" || other.ty == "water" || other.ty == "electric")
			typemodifier = 0.5f;
		else if (other.ty == "rock" || other.ty == "ice" || other.ty == "fairy")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	if (ty == "steel")
	{
		if (other.ty == "rock" || other.ty == "fire" || other.ty == "water" || other.ty == "dragon")
			typemodifier = 0.5f;
		else if (other.ty == "bug" || other.ty == "steel" || other.ty == "grass" || other.ty == "ice")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	if (ty == "water")
	{
		if (other.ty == "water" || other.ty == "grass" || other.ty == "dragon")
			typemodifier = 0.5f;
		else if (other.ty == "ground" || other.ty == "rock" || other.ty == "fire")
			typemodifier = 2.0f;
		else
			typemodifier = 1.0f;
	}
	if (ty == "grass")
	{
		if (other.ty == "flying" || other.ty == "poison" || other.ty == "bug" || other.ty == "steel" || other.ty == "fire" || other.ty == "grass" || other.ty == "dragon")
			typemodifier = 0.5f;
		else if (other.ty == "ground" || other.ty == "rock" || other.ty == "water")
			typemodifier = 2.0;
		else
			typemodifier = 1.0f;
	}
	if (ty == "electric")
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
	if (ty == "psychic")
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
	if (ty == "ice")
	{
		if (other.ty == "steel" || other.ty == "fire" || other.ty == "water" || other.ty == "ice")
			typemodifier = 0.5f;
		else if (other.ty == "flying" || other.ty == "ground" || other.ty == "grass" || other.ty == "dragon")
			typemodifier = 2.0;
		else
			typemodifier = 1.0f;
	}
	if (ty == "dragon")
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
	if (ty == "dark")
	{
		if (other.ty == "fighting" || other.ty == "dark" || other.ty == "fairy")
			typemodifier = 0.5f;
		else if (other.ty == "ghost" || other.ty == "psychic")
			typemodifier = 2.0;
		else
			typemodifier = 1.0f;
	}
	if (ty == "fairy")
	{
		if (other.ty == "poison" || other.ty == "steel" || other.ty == "fire")
			typemodifier = 0.5f;
		else if (other.ty == "fighting" || other.ty == "dragon" || other.ty == "dark")
			typemodifier = 2.0;
		else
			typemodifier = 1.0f;
	}
}

void Moves::setPOW(int newPOW){
	pow = newPOW;
}

int Moves::getPOW(){
	return pow;
}

void Moves::setPP(int newPP){
	pp = newPP;
}

int Moves::getPP(){
	return pp;
}

void Moves::setACC(float newACC){
	acc = newACC;
}

float Moves::getACC(){
	return acc;
}

void Moves::setTY(std::string newTY){
	ty = newTY;
}

std::string Moves::getTY(){
	return ty;
}

void Moves::setCAT(std::string newCAT){
	cat = newCAT;
}

std::string Moves::getCAT(){
	return cat;
}

void Moves::setSEC(std::string newSEC){
	sec = newSEC;
}

std::string Moves::getSEC(){
	return sec;
}
