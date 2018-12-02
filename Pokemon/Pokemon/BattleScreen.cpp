#include "BattleScreen.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

string formater(string str, int width) {
	if (str.length() >= width) {
		return str;
	}
	else {
		string temp = str;
		for (int i = 0; i < (width - str.length()); i++) {
			temp.append(" ");
		}
		return temp;
	}
}

display::display(string pPokeName, int pMaxHP, int pCurHP) {
	display::setPlayerPokemonName(pPokeName);
	display::setPlayerMaxHP(pMaxHP);
	display::setPlayerCurHP(pCurHP);
}

display::display(string pPokeName, string oPokeName, int pMaxHP, int oMaxHP, int pCurHP, int oCurHP) {
	display::setPlayerPokemonName(pPokeName);
	display::setOpponentPokemonName(oPokeName);
	display::setPlayerMaxHP(pMaxHP);
	display::setOpponentMaxHP(oMaxHP);
	display::setPlayerCurHP(pCurHP);
	display::setOpponentCurHP(oCurHP);
}

display::display(Pokemon &player, Pokemon &opponent) {
	display::setPlayerPokemonName(player.name);
	display::setOpponentPokemonName(opponent.name);
	display::setOpponentPokemonName(opponent.name);
	display::setPlayerMaxHP(player.stat.IHP);
	display::setOpponentMaxHP(opponent.stat.IHP);
	display::setPlayerCurHP(player.stat.HP);
	display::setOpponentCurHP(opponent.stat.HP);
}

void display::setPlayerPokemonName(string name) {
	this->pPokeName = name;
}

void display::setOpponentPokemonName(string name) {
	this->oPokeName = name;
}

void display::setPlayerMaxHP(int pmhp) {
	this->pMaxHP = pmhp;
}

void display::setOpponentMaxHP(int omhp) {
	this->oMaxHP = omhp;
}

void display::setPlayerCurHP(int pchp) {
	this->pCurHP = pchp;
}

void display::setOpponentCurHP(int ochp) {
	this->oCurHP = ochp;
}

string display::HPBar(int mhp, int chp) {
	int ast = (chp * 20) / mhp;
	int und = 20 - ast;
	string hpb;

	hpb.append("|");
	for (int i = 0; i < ast; i++) {
		hpb.append("#");
	}
	for (int i = 0; i < und; i++) {
		hpb.append("_");
	}
	hpb.append("|");

	return hpb;
}

void display::updateHP() {
	this->pHPBar = this->HPBar(this->pMaxHP, this->pCurHP);
	this->oHPBar = this->HPBar(this->oMaxHP, this->oCurHP);
}

//void display::testPrint(string hpb) {
//	cout << hpb << endl;
//}

void display::printScreen() {
	//system("CLS");
	cout << endl;
	cout << formater(("[ " + formater(this->oPokeName, 23) + "]"), 64) << "\n";
	cout << formater(("[ " + formater(this->oHPBar, 23) + "]"), 64) << "\n";
	cout << formater(("[ " + formater((to_string(this->oCurHP) + "/" + to_string(this->oMaxHP)), 23) + "]"), 64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	/*cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";
	cout << setw(64) << "\n";*/
	//cout << setw(64) << "\n";
	//cout << setw(64) << "\n";
	//cout << setw(64) << "\n";
	cout << "							" << "\n";
	cout << "							" << ("[ " + formater(this->pPokeName, 23) + "]\n");
	cout << "							" << "[ " << formater(this->pHPBar, 23) << "]\n";
	cout << "							" << ("[ " + formater((to_string(this->pCurHP) + "/" + to_string(this->pMaxHP)), 23) + "]\n");
	cout << "\n";
	//cout << setw(64) << "[  Attack  ]\n";
	//cout << setw(64) << "[  Item    ]\n";
	//cout << setw(64) << "[  Pokemon ]\n";
	//cout << setw(64) << "[  Run     ]\n";
}

void display::printPokemon()
{
	std::cout << formater(("[ " + formater(this->pPokeName, 23) + "]"), 64) << "\n";
	std::cout << formater(("[ " + formater(this->pHPBar, 23) + "]"), 64) << "\n";
	std::cout << formater(("[ " + formater((to_string(this->pMaxHP) + "/" + to_string(this->pCurHP)), 23) + "]"), 64) << "\n";
}
