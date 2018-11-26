#pragma once
#include <iostream>
#include <string>

class Moves {
private:
	int pow; //Power
	int pp; //Power Points
	float acc; //Accuracy
	std::string ty; //Type
	std::string cat; //Category
	std::string sec; //Secondary Effect

public:
	std::string name; //Name
	int maxPP;
	Moves();
	Moves(int, int, float, std::string, std::string, std::string);
	Moves(std::string, int, int, float, std::string, std::string, std::string);

	//Getters and Setters
	//=======================
	void setPOW(int);
	int getPOW();

	void setPP(int);
	int getPP();

	void setACC(float);
	float getACC();

	void setTY(std::string);
	std::string getTY();

	void setCAT(std::string);
	std::string getCAT();

	void setSEC(std::string);
	std::string getSEC();
	//=======================

};
