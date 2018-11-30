#pragma once
#include <string>
#include "Pokemon.h"
using namespace std;

string formater(string str, int width);
string formater(string str, int width);

class display {
public:
	display(string pPokeName, string oPokeName, int pMaxHP, int oMaxHP, int pCurHP, int oCurHP);
	display(Pokemon &player, Pokemon &opponent);

	string pPokeName;
	string oPokeName;
	int pMaxHP;
	int oMaxHP;
	int pCurHP;
	int oCurHP;


	// full HP bar:  |********************| 
	// empty HP bar: |____________________|

	string pHPBar;
	string oHPBar;

	void setPlayerPokemonName(string name);
	void setOpponentPokemonName(string name);
	void setPlayerMaxHP(int hp);
	void setOpponentMaxHP(int hp);
	void setPlayerCurHP(int hp);
	void setOpponentCurHP(int hp);

	string HPBar(int mhp, int chp);
	void updateHP();
	//void testPrint(string hpb);
	void printScreen();
};