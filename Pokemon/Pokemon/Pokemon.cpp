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
	confused = false;
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
	confused = false;
}

void Pokemon::useMove(Moves &move, Pokemon &other) {
	int damage = 0;
	float Critical, Stab, Burn, Random = 0;
	Random = (fmod(rand(), 25) + 85) / 100;
	typecompare(other, move);
	Critical = critical(move);
	Stab = stab(move);
	Burn = burn(move);
	float modifier = Critical * Stab * typemodifier  * Random * Burn;

	//modifier = typemodifier;
	if (move.getCAT() == "P") {
		damage = (((22 * move.getPOW()*stat.getATK() / other.stat.getDEF()) / 50) + 2) * modifier;
	}
	else if (move.getCAT() == "Sp") {
		damage = (((22 * move.getPOW()*stat.getSpATK() / other.stat.getSpDEF()) / 50) + 2) * modifier;
	}

	other.stat.setHP(other.stat.getHP() - damage);
}

int Pokemon::critical(Moves usedMove)
{
	//when changes pokemon the crit resets
	bool crit;
	float chance;
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

void Pokemon::secondaryEffect(Pokemon &opp, Moves &move) {
	//Pokemon goes first
	if (move.getSEC() == "first") {

	}
	else if (move.getSEC() == "flinch10") {
		if (rand() % 100 + 1 < 10) {

		}
		else {

		}
	}
	//Opponent has 30% chance to flinch
	else if (move.getSEC() == "flinch30") {
		if (rand() % 100 + 1 < 30) {

		}
		else {

		}
	}
	//Opponent has 30% chance to be paralized
	else if (move.getSEC() == "par30") {
		if (rand() % 100 + 1 < 30) {
			opp.status = "par";
		}
		else {

		}
	}
	//Pokemon recieves 25% of damage as recoil
	else if (move.getSEC() == "coil25") {

	}
	//Opponents accuracy decreases a stage
	else if (move.getSEC() == "dAcc1") {

	}
	//Pokemons evasion increases a stage
	else if (move.getSEC() == "iEVA1") {

	}
	//Pokemons attack increases 2 stages
	else if (move.getSEC() == "iATK2") {

	}
	//Pokemon recovers 50% of max health
	else if (move.getSEC() == "heal50") {
		if(stat.HP + stat.IHP/2 > stat.IHP){
			stat.HP = stat.IHP;
		}
		else {
			stat.HP += stat.HP / 2;
		}
	}
	//Opponent decreases defense 2 stages
	else if (move.getSEC() == "dDEF2") {

	}
	//Opponent decreases speed 2 stages
	else if (move.getSEC() == "dSPD2") {

	}
	//100% chance to confuse opponent
	else if (move.getSEC() == "conf100") {
		opp.confused = true;
	}
	//100% chance to put opponent to sleep
	else if (move.getSEC() == "sleep100") {
		opp.status = "sleep";
	}
	//100% chance to paralize opponent
	else if (move.getSEC() == "par100") {
		opp.status = "par";
	}
	//Kills pokemon
	else if (move.getSEC() == "death") {
		stat.setHP(0);
	}
	//Charges move for one turn
	else if (move.getSEC() == "charge") {

	}
	//Takes 50% of damage done and recovers pokemon
	else if (move.getSEC() == "drain50") {

	}
	//10% chance to burn opponent
	else if (move.getSEC() == "burn10") {
		if (rand() % 100 + 1 < 10) {
			opp.status = "burn";
		}
		else {

		}
	}
	//20% chance for opponent to flinch
	else if (move.getSEC() == "flinch20") {
		if (rand() % 100 + 1 < 20) {

		}
		else {

		}
	}
	//10% chance to lower opponents speacial defense by 1 stage
	else if (move.getSEC() == "lSpDEF10") {
		if (rand() % 100 + 1 < 10) {

		}
		else {

		}
	}
	//10% chance to confuse opponent
	else if (move.getSEC() == "conf10") {
		if (rand() % 100 + 1 < 10) {
			opp.confused = true;
		}
		else {

		}
	}
	//Move always hits
	else if (move.getSEC() == "100") {

	}
	//30% chance to confuse opponent
	else if (move.getSEC() == "conf30") {
		if (rand() % 100 + 1 < 30) {
			opp.confused = true;
		}
		else {

		}
	}
	//Decreases opponent attack by 2 stages
	else if (move.getSEC() == "dATK2") {

	}
	//20% chance to lower opponents special defense by 1 stage
	else if (move.getSEC() == "lSpDEF20") {
		if (rand() % 100 + 1 < 10) {

		}
		else {

		}
	}
	//increases special defense by 2 stages
	else if (move.getSEC() == "iSpDEF2") {

	}
	//Increases speed by 2 stages
	else if (move.getSEC() == "iSPD2") {

	}
	//Increases defense by 2 stages
	else if (move.getSEC() == "iDEF2") {

	}
	//10% chance to poison opponent
	else if (move.getSEC() == "poison10") {
		if (rand() % 100 + 1 < 10) {
			opp.status = "poison";
		}
		else {

		}
	}
	//30% chance to poison opponent
	else if (move.getSEC() == "poison30") {
		if (rand() % 100 + 1 < 30) {
			opp.status = "poison";
		}
		else {

		}
	}
	//10% chance to paralize opponent
	else if (move.getSEC() == "par10") {
		if (rand() % 100 + 1 < 10) {
			opp.status = "par";
		}
		else {

		}
	}
	//decreases opponent speed by 1 stage
	else if (move.getSEC() == "dSPD1") {

	}
	//30% chance to lower opponent defense
	else if (move.getSEC() == "lDEF30") {
		if (rand() % 100 + 1 < 30) {

		}
		else {

		}
	}
	//Deal exactly 50 damage
	else if (move.getSEC() == "deal50") {

	}
	//decrease opponent accuracy by 1 stage
	else if (move.getSEC() == "dACC1") {

	}
	//10% chance to freeze opponnent
	else if (move.getSEC() == "freeze10") {
		if (rand() % 100 + 1 < 10) {
			opp.status = "freeze";
		}
		else {
	
		}
	}
	//30% chance to lower opponet special attack
	else if (move.getSEC() == "lSpATK30") {

	}
	//10% chance to freeze and 10% chance to flinch opponent
	else if (move.getSEC() == "freeze10+flinch10") {
		if (rand() % 100 + 1 < 10) {
			//Freeze
			opp.status = "freeze";
		}
		else {

		}
		if (rand() % 100 + 1 < 10) {
			//Flinch
		}
		else {

		}
	}
	//Increase attack and speed by 1 stage
	else if (move.getSEC() == "iATK1+SPD1") {

	}
	//Increase attack and defense by 1 stage
	else if (move.getSEC() == "iATK1+DEF1") {

	}
	//Put self to sleep and completely heal self
	else if (move.getSEC() == "sSleep100+heal100") {
		status = "sleep";
		stat.HP = stat.IHP;
	}
	//Increase speical attack and special defense by 1 stage
	else if (move.getSEC() == "iSpATK1+SpDEF1") {

	}
	//Increase defense and special defense by 1 stage
	else if (move.getSEC() == "iDEF1+SpDEF1") {

	}
	//Increase special attack, special defense and speed by 1 stage
	else if (move.getSEC() == "iSpATK1+SpDEF1+SPD1") {

	}
	//Increase attack, defense, and accuracy by 1 stage
	else if (move.getSEC() == "iATK1+DEF1+ACC1") {

	}
	//10% chance to burn and 10% chance to flinch
	else if (move.getSEC() == "burn10+flinch10") {
		if (rand() % 100 + 1 < 10) {
			//Brun
			opp.status = "burn";
		}
		else {

		}
		if (rand() % 100 + 1 < 10) {
			//Flinch
		}
		else {

		}
	}


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
