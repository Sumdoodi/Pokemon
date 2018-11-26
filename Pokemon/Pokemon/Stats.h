#pragma once
#include <iostream>

class Stats {
private:

public:

	int HP; //Health
	int ATK; //Attack
	int DEF; //Defense
	int SpATK; //Special Attack
	int SpDEF; //Special Defense
	int SPD; //Speed
	double acc; //Accuracy
	double eva; //Evasiveness

	Stats();
	Stats(int, int, int, int, int, int);
	Stats(int, int, int, int, int, int, double, double);

	//Getters and Setters
	//===================
	int getHP();
	void setHP(int);

	int getATK();
	void setATK(int);

	int getDEF();
	void setDEF(int);

	int getSpATK();
	void setSpATK(int);
	
	int getSpDEF();
	void setSpDEF(int);
	
	int getSPD();
	void setSPD(int);
	
	double getACC();
	void setACC(double);
	
	double getEVA();
	void setEVA(double);
	//===================
};