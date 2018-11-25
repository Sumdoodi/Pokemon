#include "Moves.h"

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
