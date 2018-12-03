#include "Pokemon.h"

Pokemon::Pokemon()
{
	stat = Stats();
	img = Picture();
	ty = "none";
	ty2 = "none";
	status = "none";
	move1 = Moves();
	move2 = Moves();
	move3 = Moves();
	move4 = Moves();
	confused = false;
	flinched = false;
	accStage = 0;
	evaStage = 0;
	atkStage = 0;
	spATKStage = 0;
	defStage = 0;
	spDEFStage = 0;
}

Pokemon::Pokemon(std::string newNum, std::string newName, Stats newStats, std::string newTY, std::string newTY2, std::string newSTATUS, Moves newMove1, Moves newMove2, Moves newMove3, Moves newMove4, Picture newimg)
{
	num = newNum;
	name = newName;
	stat = newStats;
	ty = newTY;
	ty2 = newTY2;
	status = newSTATUS;
	move1 = newMove1;
	move2 = newMove2;
	move3 = newMove3;
	move4 = newMove4;
	img.L1 = newimg.L1;
	img.L2 = newimg.L2;
	img.L3 = newimg.L3;
	img.L4 = newimg.L4;
	img.L5 = newimg.L5;
	img.L6 = newimg.L6;
	img.L7 = newimg.L7;
	img.L8 = newimg.L8;
	img.L9 = newimg.L9;
	img.L10 = newimg.L10;
	confused = false;
	flinched = false;

	accStage = 0;
	evaStage = 0;
	atkStage = 0;
	spATKStage = 0;
	defStage = 0;
	spDEFStage = 0;
	spdStage = 0;
}

Pokemon::Pokemon(const Pokemon &poke) {
	num = poke.num;
	name = poke.name;
	stat = poke.stat;
	ty = poke.ty;
	ty2 = poke.ty2;
	status = poke.status;
	move1 = poke.move1;
	move2 = poke.move2;
	move3 = poke.move3;
	move4 = poke.move4;
	img.L1 = poke.img.L1;
	img.L2 = poke.img.L2;
	img.L3 = poke.img.L3;
	img.L4 = poke.img.L4;
	img.L5 = poke.img.L5;
	img.L6 = poke.img.L6;
	img.L7 = poke.img.L7;
	img.L8 = poke.img.L8;
	img.L9 = poke.img.L9;
	img.L10 = poke.img.L10;
	confused = false;
	flinched = false;

	accStage = 0;
	evaStage = 0;
	atkStage = 0;
	spATKStage = 0;
	defStage = 0;
	spDEFStage = 0;
	spdStage = 0;
}

void Pokemon::changeMod(int &stage, float &mod) {
	if (stage == -6) {
		mod = 2.0f / 8.0f;
	}
	if (stage == -5) {
		mod = 2.0f / 7.0f;
	}
	if (stage == -4) {
		mod = 2.0f / 6.0f;
	}
	if (stage == -3) {
		mod = 2.0f / 5.0f;
	}
	if (stage == -2) {
		mod = 2.0f / 4.0f;
	}
	if (stage == -1) {
		mod = 2.0f / 3.0f;
	}
	if (stage == 0) {
		mod = 1.0f;
	}
	if (stage == 1) {
		mod = 3.0f / 2.0f;
	}
	if (stage == 2) {
		mod = 4.0f / 2.0f;
	}
	if (stage == 3) {
		mod = 5.0f / 2.0f;
	}
	if (stage == 4) {
		mod = 6.0f / 2.0f;
	}
	if (stage == 5) {
		mod = 7.0f / 2.0f;
	}
	if (stage == 6) {
		mod = 8.0f / 2.0f;
	}
}

void Pokemon::changeAcc(int &stage, float &mod) {
	if (stage == -6) {
		mod = 3.0f / 9.0f;
	}
	if (stage == -5) {
		mod = 3.0f / 8.0f;
	}
	if (stage == -4) {
		mod = 3.0f / 7.0f;
	}
	if (stage == -3) {
		mod = 3.0f / 6.0f;
	}
	if (stage == -2) {
		mod = 3.0f / 5.0f;
	}
	if (stage == -1) {
		mod = 3.0f / 4.0f;
	}
	if (stage == 0) {
		mod = 1.0f;
	}
	if (stage == 1) {
		mod = 4.0f / 3.0f;
	}
	if (stage == 2) {
		mod = 5.0f / 3.0f;
	}
	if (stage == 3) {
		mod = 6.0f / 3.0f;
	}
	if (stage == 4) {
		mod = 7.0f / 3.0f;
	}
	if (stage == 5) {
		mod = 8.0f / 3.0f;
	}
	if (stage == 6) {
		mod = 9.0f / 3.0f;
	}
}
void Pokemon::useMove(Moves &move, Pokemon &other) {
	move.damage = 0;
	statusEffect(move);

	changeAcc(accStage, accMod);
	changeAcc(evaStage, evaMod);

	changeMod(atkStage, atkMod);
	changeMod(spATKStage, spATKMod);

	other.changeAcc(other.accStage, other.accMod);
	other.changeAcc(other.evaStage, other.evaMod);

	other.changeMod(other.defStage, other.defMod);
	other.changeMod(other.spDEFStage, other.spDEFMod);

	float Critical, Stab, Burn, Random = 0;
	Random = (fmod(rand(), 25) + 85) / 100;
	typecompare(other, move);
	Critical = critical(move);
	Stab = stab(move);
	Burn = burn(move);
	float modifier = Critical * Stab * typemodifier  * Random * Burn;
	int missed = rand() % 100 + 1;

	if (move.getSEC() == "charge" && charge == false) {
		secondaryEffect(other, move);
	}

	if (charge == true && chargeturn == 0) {
		charge = false;
	}

	if (dontmove == false && flinched == false) {
		if (move.getACC() * accMod * other.evaMod * 100 < missed && move.getACC() != 0.0f) {
			std::cout << move.name << " missed!" << std::endl;
		}
		else {
			//modifier = typemodifier
			if (move.getCAT() == "P") {
				move.damage = (((22 * move.getPOW()*(stat.getATK() * atkMod) / (other.stat.getDEF() * other.defMod)) / 50) + 2) * modifier;
			}
			else if (move.getCAT() == "Sp") {
				move.damage = (((22 * move.getPOW()*(stat.getSpATK() * spATKMod) / (other.stat.getSpDEF() * other.spDEFMod)) / 50) + 2) * modifier;
			}
		}
		if (confusionturns > 0) {
			confusionturns--;
		}
		else if (confused == true){
			std::cout << name << " snapped out of its confusion!" << std::endl;
			confused = false;
		}
		if (confused == true) {
			chance = rand() % 10000;
			if (chance < 3333) {
				stat.setHP(stat.getHP() - ((((2*50 / 5 + 2)*stat.ATK * 40) / stat.DEF) / 50) + 2);

			}
			else if (move.getACC() * accMod * other.evaMod * 100 < missed && move.getACC() != 0.0f) {
				std::cout << move.name << " missed!" << std::endl;
			}
			else {
				other.stat.setHP(other.stat.getHP() - move.damage);
				secondaryEffect(other, move);
			}
		}
		else if (move.getACC() * accMod * other.evaMod * 100 < missed && move.getACC() != 0.0f) {
		}
		else {
			other.stat.setHP(other.stat.getHP() - move.damage);
			secondaryEffect(other, move);
			if (move.getCAT() != "S") {
				if (typemodifier == 0.0f) {
					std::cout << move.name << " had no effect!" << std::endl;
				}
				else if (typemodifier == 0.25f || typemodifier == 0.5f) {
					std::cout << move.name << " was not very effective!" << std::endl;
				}
				else if (typemodifier == 2.0f || typemodifier == 4.0f) {
					std::cout << move.name << " was super effective!" << std::endl;
				}
			}
		}
	}
	else {
		if (flinched == true) {
			std::cout << name << " flinched and could not move!" << std::endl;
			flinched = false;
			charge = false;
		}
	}
	statusEffectBP(move);
}


int Pokemon::critical(Moves usedMove)
{
	//when changes pokemon the crit resets
	bool crit;
	chance = rand() % 10000;

	if (usedMove.getSEC() == "crit" && usedMove.getCAT() == "S")
		stat.CRIT = 25;

	if (stat.CRIT == 25 && usedMove.getSEC() == "crit" && usedMove.getCAT() == "P") {
		if (chance < 3750)
			crit = true;
		else
			crit = false;
	}
	else if (stat.CRIT == 25) {
		if (chance < 2500)
			crit = true;
		else
			crit = false;
	}
	else if (usedMove.getSEC() == "crit" && stat.CRIT == 6.25 && usedMove.getCAT() == "P") {
		if (chance < 1250)
			crit = true;
		else
			crit = false;
	}
	else if (stat.CRIT == 6.25) {
		if (chance < 625)
			crit = true;
		else
			crit = false;
	}

	if (crit)
		return 1.5;
	if (!crit)
		return 1;
}

void Pokemon::statusEffectBP(Moves &usedMove) {
	if (status == "burn") {
		stat.setHP(stat.getHP() - (stat.IHP / 16));
		std::cout << name << " is burning!" << std::endl;
	}

	else if (status == "poison") {
		stat.setHP(stat.getHP() - (stat.IHP / 8));
		std::cout << name << " is poisoned!" << std::endl;
	}
	else if (usedMove.getSEC() == "coil33+burn10") {
		stat.HP -= usedMove.damage * 0.33;
		std::cout << name << " did " << usedMove.damage*0.33 << " damage to itself as recoil!" << std::endl;

	}
	//Pokemon recieves 25% of damage as recoil
	else if (usedMove.getSEC() == "coil25") {
		stat.HP -= usedMove.damage * 0.25;
		std::cout << name << " did " << usedMove.damage*0.25 << " damage to itself as recoil!" << std::endl;
	}
}
void Pokemon::statusEffect(Moves &usedmove)
{
	dontmove = false;
	chance = rand() % 10000;

	if (status == "sleep") {
		dontmove = true;
		if (sleepturrns > 0) {
			std::cout << name << " cannot move because they are asleep!" << std::endl;
			sleepturrns--;
		}
		else {
			std::cout << name << " woke up!" << std::endl;
			status = "none";
			dontmove = false;
		}
	}

	else if (status == "freeze") {
		dontmove = true;
		std::cout << name << " cannot move because they are frozon!" << std::endl;
		if (chance < 2000 || usedmove.getTY() == "fire") {
			std::cout << name << " thawed out!" << std::endl;
			status = "none";
			dontmove = false;
		}
	}

	else if (status == "par") {
		if (chance < 2500) {
			dontmove = true;
			std::cout << name << " cannot move because they are paralized!" << std::endl;
		}
	}


}

void Pokemon::secondaryEffect(Pokemon &opp, Moves &move) {
	//Pokemon goes first
	if (move.getSEC() == "first") {

	}
	else if (move.getSEC() == "flinch10") {
		if (rand() % 100 + 1 < 10) {
			opp.flinched = true;
		}
		else {

		}
	}
	//Opponent has 30% chance to flinch
	else if (move.getSEC() == "flinch30") {
		if (rand() % 100 + 1 < 30) {
			opp.flinched = true;
		}
		else {

		}
	}
	//Opponent has 30% chance to be paralized
	else if (move.getSEC() == "par30" && (opp.ty != "electic" && opp.ty2 != "electric")) {
		if (opp.status == "none") {
			if (rand() % 100 + 1 < 30) {
				std::cout << opp.name << " has been paralized!" << std::endl;
				opp.status = "par";
				stat.SPD *= 0.5;
			}
		}
		
	}
	//Opponents accuracy decreases a stage
	else if (move.getSEC() == "dAcc1") {
		if (opp.accStage > -6) {
			opp.accStage -= 1;
			std::cout << name << "'s accuracy fell by 1 stage! It is now " << accStage << std::endl;
		}
	}
	//Pokemons evasion increases a stage
	else if (move.getSEC() == "iEVA1") {
		if (evaStage < 6) {
			evaStage += 1;
			std::cout << name << "'s evasion rose by 1 stage! It is now " << evaStage << std::endl;
		}
	}
	//Pokemons attack increases 2 stages
	else if (move.getSEC() == "iATK2") {
		if (atkStage < 5) {
			atkStage += 2;
		}
		else {
			atkStage = 6;
		}
		std::cout << name << "'s attack sharply rose by 2 stages! It is now " << atkStage << std::endl;
	}
	//Pokemon recovers 50% of max health
	else if (move.getSEC() == "heal50") {
		if(stat.HP + stat.IHP/2 >= stat.IHP){
			stat.HP = stat.IHP;
		}
		else {
			stat.HP += stat.IHP / 2;
		}
		std::cout << name << "'s health was increased by " << stat.HP / 2 << std::endl;
	}
	//Opponent decreases defense 2 stages
	else if (move.getSEC() == "dDEF2") {
		if (opp.defStage > -5) {
			opp.defStage -= 2;
		}
		else {
			opp.defStage = -6;
		}
		std::cout << opp.name << "'s defense sharply fell by 2 stages! It is now " << opp.defStage << std::endl;
	}
	//Opponent decreases speed 2 stages
	else if (move.getSEC() == "dSPD2") {
		if (opp.spdStage > -5) {
			opp.spdStage -= 2;
		}
		else {
			opp.spdStage = -6;
		}
		std::cout << opp.name << "'s speed sharply fell by 2 stages! It is now " << opp.spdStage << std::endl;
	}
	//100% chance to confuse opponent
	else if (move.getSEC() == "conf100") {
		if (opp.confused == false) {
			opp.confusionturns = rand() % 4 + 1;
		}
		opp.confused = true;
	}
	//100% chance to put opponent to sleep
	else if (move.getSEC() == "sleep100") {
		if (opp.status == "none") {
			opp.sleepturrns = rand() % 3 + 1;
			std::cout << opp.name << " has fallen asleep!" << std::endl;
			opp.status = "sleep";
		}
	}
	//100% chance to paralize opponent
	else if (move.getSEC() == "par100" && (opp.ty != "electic" && opp.ty2 != "electric")) {
		if (opp.status == "none") {
			std::cout << opp.name << " has been paralized!" << std::endl;
			opp.status = "par";
			stat.SPD *= 0.5;
		}
	}
	//Kills pokemon
	else if (move.getSEC() == "death") {
		stat.setHP(0);
	}
	//Charges move for one turn
	else if (move.getSEC() == "charge") {
		if (charge == false) {
			chargeturn = 1;
			charge = true;
		}
	}
	//Takes 50% of damage done and recovers pokemon
	else if (move.getSEC() == "drain50") {
		if (stat.HP + move.damage / 2 < stat.IHP) {
			stat.HP += move.damage / 2;
		}
		else {
			stat.HP = stat.IHP;
		}
	}
	//10% chance to burn opponent
	else if (move.getSEC() == "burn10" && (opp.ty != "fire" && opp.ty2 != "fire")) {
		if (rand() % 100 + 1 < 10 &&  opp.status == "none") {
			std::cout << opp.name << " has been burned!" << std::endl;
			opp.status = "burn";
		}
	}
	//100% chance to burn opponent
	else if (move.getSEC() == "burn100" && (opp.ty != "fire" && opp.ty2 != "fire")) {
	if (opp.status == "none") {
		std::cout << opp.name << " has been burned!" << std::endl;
		opp.status = "burn";
	}
	}
	//20% chance for opponent to flinch
	else if (move.getSEC() == "flinch20") {
		if (rand() % 100 + 1 < 20) {
			opp.flinched = true;
		}
	}
	//10% chance to lower opponents speacial defense by 1 stage
	else if (move.getSEC() == "lSpDEF10") {
		if (rand() % 100 + 1 < 10) {
			if (opp.spDEFStage > -6) {
				opp.spDEFStage -= 1;
				std::cout << opp.name << "'s special defense fell by 1 stage! It is now " << opp.spDEFStage << std::endl;
			}
		}
	}
	//Lowers users speacial defense by 2 stage
	else if (move.getSEC() == "sdSpDEF2") {
		if (spDEFStage > -5) {
			spDEFStage -= 2;
		}
		else {
			spDEFStage = -6;
		}
		std::cout << name << "'s special defense sharply fell by 2 stage! It is now " << spDEFStage << std::endl;
	}
	//10% chance to confuse opponent
	else if (move.getSEC() == "conf10") {
		if (rand() % 100 + 1 < 10) {
			if (opp.confused == false) {
				opp.confusionturns = rand() % 4 + 1;
			}
			opp.confused = true;
		}
	}
	//30% chance to confuse opponent
	else if (move.getSEC() == "conf30") {
		if (rand() % 100 + 1 < 30) {
			if (opp.confused == false) {
				opp.confusionturns = rand() % 4 + 1;
			}
			opp.confused = true;
		}
	}
	//Decreases opponent attack by 2 stages
	else if (move.getSEC() == "dATK2") {
		if (opp.atkStage > -5) {
			opp.atkStage -= 2;
		}
		else {
			opp.atkStage = -6;
		}
		std::cout << opp.name << "'s attack sharply fell by 2 stages! It is now " << opp.atkStage << std::endl;
	}
	//20% chance to lower opponents special defense by 1 stage
	else if (move.getSEC() == "lSpDEF20") {
		if (rand() % 100 + 1 < 10) {
			if (opp.spDEFStage > -6) {
				opp.spDEFStage -= 1;
				std::cout << opp.name << "'s special defense fell by 1 stage! It is now " << opp.spDEFStage << std::endl;
			}
		}
	}
	//increases special defense by 2 stages
	else if (move.getSEC() == "iSpDEF2") {
		if (spDEFStage < 5) {
			spDEFStage += 2;
		}
		else {
			spDEFStage = 6;
		}
		std::cout << name << "'s special defense sharply rose by 2 stages! It is now " << spDEFStage << std::endl;
	}
	//Increases speed by 2 stages
	else if (move.getSEC() == "iSPD2") {
		if (spdStage < 5) {
			spdStage += 2;
		}
		else {
			spdStage = 6;
		}
		std::cout << name << "'s speed sharply rose by 2 stages! It is now " << spdStage << std::endl;
	}
	//Increases defense by 2 stages
	else if (move.getSEC() == "iDEF2") {
		if (defStage < 5) {
			defStage += 2;
		}
		else {
			defStage = 6;
		}
		std::cout << name << "'s defense sharply rose by 2 stages! It is now " << defStage << std::endl;
	}
	//10% chance to poison opponent
	else if (move.getSEC() == "poison10" && (opp.ty != "poison" && opp.ty2 != "poison")) {
		if (rand() % 100 + 1 < 10 && opp.status == "none") {
			opp.status = "poison";
			std::cout << opp.name << " has been poisoned!" << std::endl;
		}
	}
	//100% chance to poison opponent
	else if (move.getSEC() == "poison100" && (opp.ty != "poison" && opp.ty2 != "poison")) {
	if (opp.status == "none") {
		opp.status = "poison";
		std::cout << opp.name << " has been poisoned!" << std::endl;
	}
	}
	//30% chance to poison opponent
	else if (move.getSEC() == "poison30" && (opp.ty != "poison" && opp.ty2 != "poison")) {
		if (rand() % 100 + 1 < 30 && opp.status == "none") {
			std::cout << opp.name << " has been poisoned!" << std::endl;
			opp.status = "poison";
		}
	}
	//10% chance to paralize opponent
	else if (move.getSEC() == "par10" && (opp.ty != "electic" && opp.ty2 != "electric")) {
		if (opp.status == "none") {
			if (rand() % 100 + 1 < 10) {
				std::cout << opp.name << " has been paralized!" << std::endl;
				opp.status = "par";
				stat.SPD *= 0.5;
			}
		}
	}
	//decreases opponent speed by 1 stage
	else if (move.getSEC() == "dSPD1") {
		if (opp.spdStage > -6) {
			opp.spdStage -= 1;
		}
		std::cout << opp.name << "'s speed fell by 1 stage! It is now " << opp.spdStage << std::endl;
	}
	//30% chance to lower opponent defense
	else if (move.getSEC() == "lDEF30") {
		if (rand() % 100 + 1 < 30) {
			if (opp.defStage > -6) {
				opp.defStage -= 1;
				std::cout << opp.name << "'s defense fell by 1 stage! It is now " << opp.defStage << std::endl;
			}
		}
	}
	//Deal exactly 50 damage
	else if (move.getSEC() == "deal50") {
		move.damage = 50;
	}
	//decrease opponent accuracy by 1 stage
	else if (move.getSEC() == "dACC1") {
		if (opp.accStage > -6) {
			opp.accStage -= 1;
			std::cout << opp.name << "'s accuracy fell by 1 stage! It is now " << opp.accStage << std::endl;
		}
	}
	//10% chance to freeze opponnent
	else if (move.getSEC() == "freeze10" && (opp.ty != "ice" && opp.ty2 != "ice")) {
		if (rand() % 100 + 1 < 10 && opp.status == "none") {
			std::cout << opp.name << " has been frozen!" << std::endl;
			opp.status = "freeze";
		}
		else {
	
		}
	}
	//30% chance to lower opponet special attack
	else if (move.getSEC() == "lSpATK30") {
		if (rand() % 100 + 1 < 30) {
			if (opp.spATKStage > -6) {
				opp.spATKStage -= 1;
				std::cout << opp.name << "'s special attack fell by 1 stage! It is now " << opp.spATKStage << std::endl;
			}
		}
		else {

		}
	}
	//10% chance to freeze and 10% chance to flinch opponent
	else if (move.getSEC() == "freeze10+flinch10") {
		if (rand() % 100 + 1 < 10 && (opp.ty != "ice" && opp.ty2 != "ice") && opp.status == "none") {
			//Freeze
			std::cout << opp.name << " has been frozen!" << std::endl;
			opp.status = "freeze";
		}
		else {

		}
		if (rand() % 100 + 1 < 10) {
			//Flinch
			opp.flinched = true;
		}
		else {

		}
	}
	//Increase attack and speed by 1 stage
	else if (move.getSEC() == "iATK1+SPD1") {
		if (atkStage < 6) {
			atkStage += 1;
			std::cout << name << "'s attack rose by 1 stage! It is now " << atkStage << std::endl;
		}
		if (spdStage < 6) {
			spdStage += 1;
			std::cout << name << "'s speed rose by 1 stage! It is now " << spdStage << std::endl;
		}
	}
	//Increase attack and defense by 1 stage
	else if (move.getSEC() == "iATK1+DEF1") {
		if (atkStage < 6) {
			atkStage += 1;
			std::cout << name << "'s attack rose by 1 stage! It is now " << atkStage << std::endl;
		}
		if (defStage < 6) {
			defStage += 1;
			std::cout << name << "'s defense rose by 1 stage! It is now " << defStage << std::endl;
		}
	}
	//Put self to sleep and completely heal self
	else if (move.getSEC() == "sSleep100+heal100") {
		if (status == "none") {
			sleepturrns = rand() % 3 + 1;
			std::cout << name << " has put themself to sleep!" << std::endl;
			status = "sleep";
			stat.HP = stat.IHP;
		}
	}
	//Increase speical attack and special defense by 1 stage
	else if (move.getSEC() == "iSpATK1+SpDEF1") {
		if (spATKStage < 6) {
			spATKStage += 1;
			std::cout << name << "'s special attack rose by 1 stage! It is now " << spATKStage << std::endl;
		}
		if (spDEFStage < 6) {
			spDEFStage += 1;
			std::cout << name << "'s special defense rose by 1 stage! It is now " << spDEFStage << std::endl;
		}
	}
	//Increase defense and special defense by 1 stage
	else if (move.getSEC() == "iDEF1+SpDEF1") {
		if (defStage < 6) {
			defStage += 1;
			std::cout << name << "'s defense rose by 1 stage! It is now " << defStage << std::endl;
		}
		if (spDEFStage < 6) {
			spDEFStage += 1;
			std::cout << name << "'s special defense rose by 1 stage! It is now " << spDEFStage << std::endl;
		}
	}
	//Increase special attack, special defense and speed by 1 stage
	else if (move.getSEC() == "iSpATK1+SpDEF1+SPD1") {
		if (spATKStage < 6) {
			spATKStage += 1;
			std::cout << name << "'s special attack rose by 1 stage! It is now " << spATKStage << std::endl;
		}
		if (spDEFStage < 6) {
			spDEFStage += 1;
			std::cout << name << "'s special defense rose by 1 stage! It is now " << spDEFStage << std::endl;
		}
		if (spdStage < 6) {
			spdStage += 1;
			std::cout << name << "'s speed rose by 1 stage! It is now " << spdStage << std::endl;
		}
	}
	//Increase attack, defense, and accuracy by 1 stage
	else if (move.getSEC() == "iATK1+DEF1+ACC1") {
		if (atkStage < 6) {
			atkStage += 1;
			std::cout << name << "'s attack rose by 1 stage! It is now " << atkStage << std::endl;
		}
		if (defStage < 6) {
			defStage += 1;
			std::cout << name << "'s defense rose by 1 stage! It is now " << defStage << std::endl;
		}
		if (accStage < 6) {
			accStage += 1;
			std::cout << name << "'s accuracy rose by 1 stage! It is now " << accStage << std::endl;
		}
	}
	//10% chance to burn and 10% chance to flinch
	else if (move.getSEC() == "burn10+flinch10") {
		if (rand() % 100 + 1 < 10 && (opp.ty != "fire" && opp.ty2 != "fire") && opp.status == "none") {
			//Brun
			std::cout << opp.name << " has been burned!" << std::endl;
			opp.status = "burn";
		}
		else {

		}
		if (rand() % 100 + 1 < 10) {
			//Flinch
			opp.flinched = true;
		}
		else {

		}
	}
	//33% Recoil and 10% chance to burn
	else if (move.getSEC() == "coil33+burn10") {
		if (rand() % 100 + 1 < 100 && (opp.ty != "fire" && opp.ty2 != "fire") && opp.status == "none") {
			//Brun
			std::cout << opp.name << " has been burned!" << std::endl;
			opp.status = "burn";
		}
	}

}

void Pokemon::resetStages(){
	accStage = 0;
	evaStage = 0;
	atkStage = 0;
	spATKStage = 0;
	defStage = 0;
	spDEFStage = 0;
	spdStage = 0;
}

int Pokemon::stab(Moves usedMove)
{
	if (usedMove.getTY() == ty || usedMove.getTY() == ty2)
		return 1.5;
	else
		return 1;
}

int Pokemon::burn(Moves usedMove)
{
	if (status == "burn" && usedMove.getCAT() == "P")
		return 0.5;
	else
		return 1;
}


void Pokemon::typecompare(Pokemon other, Moves usedMove)
{

	//First Type
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
	else if (usedMove.getTY() == "fire")
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

	if (other.ty2 != "none") {
		//Second Type
		if (usedMove.getTY() == "normal")
		{
			if (other.ty2 == "rock" || other.ty2 == "steel")
				typemodifier *= 0.5f;
			else if (other.ty2 == "ghost")
				typemodifier *= 0.0f;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "fighting")
		{
			if (other.ty2 == "flying" || other.ty2 == "poison" || other.ty2 == "bug" || other.ty2 == "psychic" || other.ty2 == "fairy")
				typemodifier *= 0.5f;
			else if (other.ty2 == "ghost")
				typemodifier *= 0.0f;
			else if (other.ty2 == "normal" || other.ty2 == "rock" || other.ty2 == "ice" || other.ty2 == "dark")
				typemodifier *= 2.0f;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "flying")
		{
			if (other.ty2 == "rock" || other.ty2 == "steel" || other.ty2 == "electric" || other.ty2 == "fairy")
				typemodifier *= 0.5f;
			else if (other.ty2 == "fighting" || other.ty2 == "bug" || other.ty2 == "grass")
				typemodifier *= 2.0f;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "poison")
		{
			if (other.ty2 == "poison" || other.ty2 == "ground" || other.ty2 == "rock" || other.ty2 == "ghost")
				typemodifier *= 0.5f;
			else if (other.ty2 == "steel")
				typemodifier *= 0.0f;
			else if (other.ty2 == "grass" || other.ty2 == "fairy")
				typemodifier *= 2.0f;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "ground")
		{
			if (other.ty2 == "bug" || other.ty2 == "grass")
				typemodifier *= 0.5f;
			else if (other.ty2 == "flying")
				typemodifier *= 0.0f;
			else if (other.ty2 == "poison" || other.ty2 == "rock" || other.ty2 == "steel" || other.ty2 == "fire" || other.ty2 == "electric")
				typemodifier *= 2.0f;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "rock")
		{
			if (other.ty2 == "fighting" || other.ty2 == "ground" || other.ty2 == "steel")
				typemodifier *= 0.5f;
			else if (other.ty2 == "flying" || other.ty2 == "bug" || other.ty2 == "fire" || other.ty2 == "ice")
				typemodifier *= 2.0f;
			else
				typemodifier *= 1.0f;
		}
		if (usedMove.getTY() == "bug")
		{
			if (other.ty2 == "fighting" || other.ty2 == "flying" || other.ty2 == "poison" || other.ty2 == "ghost" || other.ty2 == "steel" || other.ty2 == "fire" || other.ty2 == "fairy")
				typemodifier *= 0.5f;
			else if (other.ty2 == "grass" || other.ty2 == "psychic" || other.ty2 == "dark")
				typemodifier *= 2.0f;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "ghost")
		{
			if (other.ty2 == "dark")
				typemodifier *= 0.5f;
			else if (other.ty2 == "normal")
				typemodifier *= 0.0;
			else if (other.ty2 == "ghost" || other.ty2 == "psychic")
				typemodifier *= 2.0f;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "steel")
		{
			if (other.ty2 == "steel" || other.ty2 == "fire" || other.ty2 == "water" || other.ty2 == "electric")
				typemodifier *= 0.5f;
			else if (other.ty2 == "rock" || other.ty2 == "ice" || other.ty2 == "fairy")
				typemodifier *= 2.0f;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "fire")
		{
			if (other.ty2 == "rock" || other.ty2 == "fire" || other.ty2 == "water" || other.ty2 == "dragon")
				typemodifier = 0.5f;
			else if (other.ty2 == "bug" || other.ty2 == "steel" || other.ty2 == "grass" || other.ty2 == "ice")
				typemodifier *= 2.0f;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "water")
		{
			if (other.ty2 == "water" || other.ty2 == "grass" || other.ty2 == "dragon")
				typemodifier *= 0.5f;
			else if (other.ty2 == "ground" || other.ty2 == "rock" || other.ty2 == "fire")
				typemodifier *= 2.0f;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "grass")
		{
			if (other.ty2 == "flying" || other.ty2 == "poison" || other.ty2 == "bug" || other.ty2 == "steel" || other.ty2 == "fire" || other.ty2 == "grass" || other.ty2 == "dragon")
				typemodifier *= 0.5f;
			else if (other.ty2 == "ground" || other.ty2 == "rock" || other.ty2 == "water")
				typemodifier *= 2.0;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "electric")
		{
			if (other.ty2 == "grass" || other.ty2 == "electric" || other.ty2 == "dragon")
				typemodifier *= 0.5f;
			else if (other.ty2 == "flying" || other.ty2 == "water")
				typemodifier *= 2.0;
			else if (other.ty2 == "ground")
				typemodifier *= 0.0;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "psychic")
		{
			if (other.ty2 == "steel" || other.ty2 == "psychic")
				typemodifier *= 0.5f;
			else if (other.ty2 == "fighting" || other.ty2 == "poison")
				typemodifier *= 2.0;
			else if (other.ty2 == "dark")
				typemodifier *= 0.0;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "ice")
		{
			if (other.ty2 == "steel" || other.ty2 == "fire" || other.ty2 == "water" || other.ty2 == "ice")
				typemodifier *= 0.5f;
			else if (other.ty2 == "flying" || other.ty2 == "ground" || other.ty2 == "grass" || other.ty2 == "dragon")
				typemodifier *= 2.0;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "dragon")
		{
			if (other.ty2 == "steel")
				typemodifier *= 0.5f;
			else if (other.ty2 == "dragon")
				typemodifier *= 2.0;
			else if (other.ty2 == "dark")
				typemodifier *= 0.0;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "dark")
		{
			if (other.ty2 == "fighting" || other.ty2 == "dark" || other.ty2 == "fairy")
				typemodifier *= 0.5f;
			else if (other.ty2 == "ghost" || other.ty2 == "psychic")
				typemodifier *= 2.0;
			else
				typemodifier *= 1.0f;
		}
		else if (usedMove.getTY() == "fairy")
		{
			if (other.ty2 == "poison" || other.ty2 == "steel" || other.ty2 == "fire")
				typemodifier *= 0.5f;
			else if (other.ty2 == "fighting" || other.ty2 == "dragon" || other.ty2 == "dark")
				typemodifier *= 2.0;
			else
				typemodifier *= 1.0f;
		}
	}
}
