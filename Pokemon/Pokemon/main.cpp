#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "Pokemon.h"
#include "Moves.h"
#include "Stats.h"
#include <ctime>
#include <cstdlib>

bool story = false, multiplayer = false;
bool p1Alive = true, trainerAlive = true;
std::vector<Pokemon> pokemonList;
std::vector<Pokemon> trainer;


//Generate Pokemon stats
Stats venusaur_stats(80, 82, 83, 100, 100, 80);
Stats charizard_stats(78, 84, 78, 109, 85, 100);
Stats blastoise_stats(79, 83, 100, 85, 105, 78);
Stats butterfree_stats(60, 45, 50, 90, 80, 70);
Stats beedrill_stats(65, 90, 40, 45, 80, 75);
Stats pidgeot_stats(83, 80, 75, 70, 70, 101);
Stats raticate_stats(55, 81, 60, 50, 70, 97);
Stats arbok_stats(60, 85, 55, 90, 80, 100);
Stats raichu_stats(60, 90, 55, 90, 80, 100);
Stats sandslash_stats(75, 100, 110, 45, 55, 65);
Stats nidoking_stats(81, 102, 77, 85, 75, 85);
Stats clefable_stats(95, 70, 73, 95, 90, 60);
Stats arcanine_stats(90, 110, 80, 100, 80, 95);
Stats poliwrath_stats(90, 95, 95, 70, 90, 70);
Stats alakazam_stats(55, 50, 45, 135, 95, 120);
Stats machamp_stats(90, 130, 80, 65, 85, 55);
Stats tentacruel_stats(80, 70, 65, 80, 120, 100);
Stats golem_stats(80, 120, 130, 55, 65, 65);
Stats magneton_stats(50, 60, 95, 120, 70, 70);
Stats gengar_stats(60, 65, 60, 130, 75, 110);
Stats onix_stats(35, 45, 160, 30, 45, 70);
Stats exeggutor_stats(95, 95, 85, 125, 65, 125);
Stats weezing_stats(65, 90, 120, 85, 70, 60);
Stats scyther_stats(70, 110, 80, 55, 80, 105);
Stats jynx_stats(65, 50, 35, 115, 95, 95);
Stats gyrados_stats(95, 125, 79, 60, 100, 81);
Stats lapras_stats(130, 85, 80, 85, 95, 60);
Stats aerodactyl_stats(80, 105, 65, 60, 75, 130);
Stats snorlax_stats(160, 110, 65, 65, 110, 30);
Stats articuno_stats(90, 85, 100, 95, 125, 85);
Stats zapdos_stats(90, 90, 85, 125, 90, 100);
Stats moltres_stats(90, 100, 90, 125, 85, 90);
Stats dragonite_stats(91, 134, 95, 100, 100, 80);
Stats mewtwo_stats(106, 110, 90, 154, 90, 130);
Stats ampharos_stats(90, 75, 85, 115, 90, 55);

//Generate Moves
//Normal moves 18 moves
Moves quickattack("Quick Attack", 40, 30, 1.0f, "normal", "P", "first");
Moves extremespeed("Extreme Speed", 80, 5, 1.0f, "normal", "P", "first");
Moves slash("Slash", 70, 20, 1.0f, "normal", "P", "crit");
Moves stomp("Stomp", 65, 15, 1.0f, "normal", "P", "flinch");
Moves bodyslam("Body Slam", 85, 15, 1.0f, "normal", "P", "par");
Moves hyperfang("Hyper Fang", 80, 15, 0.9f, "normal", "P", "flinch");
Moves takedown("Take Down", 90, 20, 0.85f, "normal", "P", "coil");
Moves smokescreen("Smokescreen", 0, 15, 1.0f, "normal", "S", "dAcc");
Moves focusenergy("Focus Energy", 0, 30, 0.0f, "normal", "S", "crit");
Moves doubleteam("Double Team", 0, 15, 0.0f, "normal", "S", "iEVA");
Moves sworddance("Sword Dance", 0, 20, 0.0f, "normal", "S", "iATK");
Moves recover("Recover", 0, 10, 0.0f, "normal", "S", "heal");
Moves screech("Screech", 0, 40, 0.85f, "normal", "S", "dDEF");
Moves scaryface("Scary Face", 0, 20, 1.0f, "normal", "S", "dSPD");
Moves supersonic("Supersonic", 0, 20, 0.55f, "normal", "S", "conf");
Moves sing("Sing", 0, 15, 0.55f, "normal", "S", "sleep");
Moves glare("Glare", 0, 30, 1.0f, "normal", "S", "par");
Moves explosion("Explosion", 250, 5, 1.0f, "normal", "P", "death");

//Grass 5 moves
Moves seedbomb("Seed Bomb", 80, 15, 1.0f, "grass", "P", "none");
Moves solarbeam("Solar Beam", 120, 10, 1.0f, "grass", "Sp", "charge");
Moves megadrain("Mega Drain", 40, 15, 1.0f, "grass", "Sp", "drain");
Moves gigadrain("Giga Drain", 75, 10, 1.0f, "grass", "Sp", "drain");
Moves sleeppowder("Sleep Powder", 0, 15, 0.75f, "grass", "S", "sleep");
Moves stunspore("Stun Spore", 0, 30, 0.75f, "grass", "S", "par");

//Fire 3 moves
Moves firefang("Fire Fang", 65, 15, 0.95f, "fire", "P", "burn+flinch");
Moves flamethrower("Flame Thrower", 90, 15, 1.0f, "fire", "Sp", "burn");
Moves flareblitz("Flare Blitz", 120, 15, 1.0f, "fire", "Sp", "coil+burn");

//Water 4 moves
Moves surf("Surf", 90, 15, 1.0f, "water", "Sp", "none");
Moves hydropump("Hydro Pump", 110, 5, 0.8f, "water", "Sp", "none");
Moves aquatail("Aqua Tail", 90, 10, 0.9f, "water", "P", "none");
Moves waterfall("Waterfall", 80, 15, 1.0f, "water", "P", "flinch");

//Bug 5 moves
Moves bugbuzz("Bug Buzz", 90, 20, 1.0f, "bug", "Sp", "lSpDEF");
Moves xscissor("X=Scissor", 80, 15, 1.0f, "bug", "P", "none");
Moves megahorn("Megahorn", 120, 10, 1.0f, "bug", "P", "none");
Moves signalbeam("Signal Beam", 75, 15, 1.0f, "bug", "Sp", "conf");
Moves quiverdance("Quiver Dance", 0, 20, 0.0f, "bug", "S", "iSpATK,SpDEF, SPD");

//Flying 6 moves
Moves aerialace("Aerial Ace", 60, 20, 0.0f, "flying", "P", "100");
Moves airslash("Air Slash", 75, 15, 0.95f, "flying", "P", "flinch");
Moves aircutter("Air Cutter", 60, 25, 0.95f, "flying", "Sp", "crit");
Moves hurricane("Hurricane", 110, 10, 0.75f, "flying", "Sp", "conf");
Moves featherdance("Feather Dance", 0, 15, 1.0f, "flying", "S", "dATK");
Moves roost("Roost", 0, 10, 0.0f, "flying", "S", "heal");

//Dark 3 moves
Moves crunch("Crunch", 80, 15, 1.0f, "dark", "P", "lSpDEF");
Moves darkpulse("Dark Pulse", 80, 15, 1.0f, "dark", "Sp", "flinch");
Moves assurance("Assurance", 60, 20, 1.0f, "dark", "P", "none");
Moves nightslash("Night Slash", 70, 15, 1.0f, "dark", "P", "crit");

//Psychic 8 moves
Moves psychic("Psychic", 90, 10, 1.0f, "psychic", "Sp", "lSpDEF");
Moves psychocut("Psycho Cut", 70, 10, 1.0f, "psychic", "P", "crit");
Moves psystrike("Psystrike", 120, 10, 1.0f, "psychic", "Sp", "none");
Moves amnesia("Amnesia", 0, 20, 0.0f, "psychic", "S", "iSpDEF");
Moves cosmicpower("Cosmic Power", 0, 20, 0.0f, "psychic", "S", "iDEF, SpDEF");
Moves agility("Agility", 0, 20, 0.0f, "psychic", "S", "iSPD");
Moves calmmind("Calm Mind", 0, 20, 0.0f, "psychic", "S", "iSpATK, SpDEF");
Moves barrier("Barrier", 0, 20, 0.0f, "psychic", "S", "iDEF");
Moves hypnosis("Hypnosis", 0, 20, 0.6f, "psychic", "S", "sleep");
Moves rest("Rest", 0, 10, 1.0f, "psychic", "S", "sleep+heal");

//Poison 5 moves
Moves poisonjab("Poison Jab", 80, 20, 1.0f, "poison", "P", "poison");
Moves sludgebomb("Sludge Bomb", 90, 10, 1.0f, "poison", "Sp", "poison");
Moves sludgewave("Sludge Wave", 95, 10, 1.0f, "poison", "Sp", "poison");
Moves coil("Coil", 0, 20, 0.0f, "poison", "S", "iATK, DEF, ACC");
Moves poisonpowder("Poison Powder", 0, 35, 0.75f, "poison", "S", "poison");

//Electric 4 moves
Moves thunderbolt("Thunderbolt", 90, 15, 1.0f, "electric", "Sp", "par");
Moves thunder("Thunder", 110, 5, 0.7f, "electric", "Sp", "par");
Moves zapcannon("Zap Cannon", 120, 5, 0.5f, "electric", "Sp", "par");
Moves thunderpunch("Thunder Punch", 75, 15, 1.0f, "electric", "Sp", "par");
Moves thunderwave("Thunder Wave", 0, 20, 0.9f, "electric", "S", "par");

//Fighting 4 moves
Moves crosschop("Cross Chop", 100, 5, 0.8f, "fighting", "P", "crit");
Moves aurasphere("Aura Sphere", 80, 5, 0.0f, "fighting", "Sp", "100");
Moves lowsweep("Low Sweep", 65, 20, 1.0f, "fighting", "P", "dSPD");
Moves bulkup("Bulk Up", 0, 20, 0.0f, "fighting", "S", "iATK, DEF");

//Steel 4 moves
Moves flashcannon("Flash Cannon", 80, 10, 1.0f, "steel", "Sp", "lSpDEF");
Moves irontail("Iron Tail", 100, 15, 1.0f, "steel", "P", "flinch");
Moves ironhead("Iron Head", 80, 15, 0.75f, "steel", "P", "lDEF");
Moves irondefense("Iron Defense", 0, 15, 0.0f, "steel", "S", "iDEF");

//Ghost 4 moves
Moves lick("Lick", 30, 30, 1.0f, "ghost", "P", "lSpDEF");
Moves shadowball("Shadow Ball", 80, 15, 1.0f, "ghost", "Sp", "lSpDEF");
Moves nightshade("Night Shade", 0, 15, 1.0f, "ghost", "Sp", "50");
Moves confuseray("Confuse Ray", 0, 10, 1.0f, "ghost", "P", "conf");

//Ground 2 moves
Moves earthquake("Earthquake", 100, 10, 1.0f, "ground", "P", "none");
Moves sandattack("Sand Attack", 0, 15, 1.0f, "ground", "S", "dACC");

//Rock 3 moves
Moves rockslide("Rock Slide", 75, 10, 0.9f, "rock", "P", "flinch");
Moves stoneedge("Stone Edge", 100, 10, 0.8f, "rock", "P", "crit");
Moves rockpolish("Rock Polish", 0, 20, 0.0f, "rock", "S", "iSPD");

//Ice 2 moves
Moves icepunch("Ice Punch", 75, 10, 1.0f, "ice", "P", "freeze");
Moves icebeam("Ice Beam", 90, 10, 1.0f, "ice", "P", "freeze");
Moves icefang("Ice Fang", 65, 15, 0.95f, "ice", "P", "freeze+flinch");
Moves blizzard("Blizzard", 120, 5, 0.7f, "ice", "Sp", "freeze");

//Dragon 2 moves
Moves dragonrush("Dragon Rush", 100, 10, 0.75f, "dragon", "P", "conf");
Moves dragonpulse("Dragon Pulse", 85, 10, 1.0f, "dragon", "P", "none");
Moves dragondance("Dragon Dance", 0, 20, 0.0f, "dragon", "S", "iATK, SPD");

//Fairy 2 moves
Moves moonblast("Moonblast", 95, 15, 1.0f, "fairy", "Sp", "lSpATK");
Moves moonlight("Moonlight", 0, 10, 0.0f, "fairy", "S", "heal");

//Generate Pokemon
Pokemon venusaur("venusaur", venusaur_stats, "grass", "poison", "none", takedown, sludgebomb, gigadrain, poisonpowder);
Pokemon charizard("charizard",charizard_stats, "fire", "flying", "none", slash, flamethrower, airslash, scaryface);
Pokemon blastoise("blastoise", blastoise_stats, "water", "none", "none", bodyslam, surf, irondefense, crunch);
Pokemon butterfree("butterfree", butterfree_stats, "bug", "flying", "none", bugbuzz, sleeppowder, quiverdance, aircutter);
Pokemon beedrill("beedrill",beedrill_stats, "bug", "poison", "none", poisonjab, agility, xscissor, assurance);
Pokemon pidgeot("pidgeot", pidgeot_stats, "normal", "flying", "none", quickattack, airslash, sandattack, featherdance);
Pokemon raticate("raticate", raticate_stats, "normal", "none", "none", hyperfang, crunch, sworddance, focusenergy);
Pokemon arbok("arbok", arbok_stats, "poison", "none", "none", sludgebomb, coil, screech, glare);
Pokemon raichu("raichu", raichu_stats, "electric", "none", "none", thunderbolt, thunder, thunderwave, doubleteam);
Pokemon sandslash("sandslash",sandslash_stats, "ground", "none", "none", slash, earthquake, sandattack, sworddance);
Pokemon nidoking("nidoking", nidoking_stats, "ground", "poison", "none", earthquake, megahorn, focusenergy, bodyslam);
Pokemon clefable("clefable", clefable_stats, "fairy", "none", "none", bodyslam, moonblast, cosmicpower, moonlight);
Pokemon arcanine("arcanine", arcanine_stats, "fire", "none", "none", flareblitz, agility, crunch, extremespeed);
Pokemon poliwrath("poliwrath", poliwrath_stats, "water", "fighting", "none", waterfall, amnesia, bodyslam, lowsweep);
Pokemon alakazam("alakazam", alakazam_stats, "psychic", "none", "none", calmmind, psychic, recover, shadowball);
Pokemon machamp("machamp", machamp_stats, "fighting", "none", "none", crosschop, scaryface, focusenergy, lowsweep);
Pokemon tentacruel("tentacruel", tentacruel_stats, "water", "poison", "none", sludgewave, hydropump, barrier, supersonic);
Pokemon golem("golem", golem_stats, "rock", "ground", "none", earthquake, stoneedge, explosion, rockpolish);
Pokemon magneton("magneton",magneton_stats, "electric", "steel", "none", supersonic, thunderbolt, flashcannon, zapcannon);
Pokemon gengar("gengar",gengar_stats, "ghost", "poison", "none", shadowball, nightshade, hypnosis, darkpulse);
Pokemon onix("onix",onix_stats, "rock", "ground", "none", rockslide, earthquake, irontail, rockpolish);
Pokemon exeggutor("exeggutor",exeggutor_stats, "grass", "psychic", "none", solarbeam, stomp, psychic, stunspore);
Pokemon weezing("weezing",weezing_stats, "poison", "none", "none", sludgebomb, explosion, assurance, smokescreen);
Pokemon scyther("scyther",scyther_stats, "bug", "flying", "none", airslash, xscissor, agility, nightslash);
Pokemon jynx("jynx",jynx_stats, "psychic", "ice", "none", icepunch, bodyslam, psychic, blizzard);
Pokemon gyrados("gyrados",gyrados_stats, "water", "flying", "none", dragondance, irontail, icefang, aquatail);
Pokemon lapras("lapras",lapras_stats, "water", "ice", "none", hydropump, icebeam, bodyslam, confuseray);
Pokemon aerodactyl("aerodactyl",aerodactyl_stats, "rock", "flying", "none", crunch, rockslide, ironhead, aerialace);
Pokemon snorlax("snorlax",snorlax_stats, "normal", "none", "none", bodyslam, amnesia, rest, crunch);
Pokemon articuno("articuno",articuno_stats, "ice", "flying", "none", icebeam, roost, hurricane, agility);
Pokemon zapdos("zapdos",zapdos_stats, "electric", "flying", "none", thunderbolt, roost, agility, aircutter);
Pokemon moltres("moltres",moltres_stats, "fire", "flying", "none", flamethrower, airslash, roost, solarbeam);
Pokemon dragonite("dragonite",dragonite_stats, "dragon", "flying", "none", dragonrush, thunderwave, dragondance, hurricane);
Pokemon mewtwo("mewtwo",mewtwo_stats, "psychic", "none", "none", psystrike, shadowball, recover, aurasphere);
Pokemon ampharos("ampharos",ampharos_stats, "electric", "none", "none", thunderpunch, thunderwave, signalbeam, dragonpulse);


void printScreen() {
	int choice;

	std::cout << std::endl << "========================================================================================================================" << std::endl;
	std::cout << "  			                                .::." << std::endl;
	std::cout << "  					                      .;:**'               " << std::endl;
	std::cout << "  			                              `                   " << std::endl;
	std::cout << "  			  .:XHHHHk.              db.   .;;.     dH  MX    " << std::endl;
	std::cout << "  			oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN" << std::endl;
	std::cout << "  			QMMMMMb  \"MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM" << std::endl;
	std::cout << "  			`MMMM.  )M > :X!Hk.  MMMM   XMM.o\"  .  MMMMMMM X?XMMM MMM>!MMP" << std::endl;
	std::cout << "  			   'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `\" MX MMXXMM" << std::endl;
	std::cout << "  			    ~MMMMM~ XMM. .XM XM`\"MMMb.~*?**~ .MMX M t MMbooMM XMMMMMP" << std::endl;
	std::cout << "  			     ?MMM>  YMMMMMM! MM   `?MMRb.    `\"\"\"   !L\"MMMMM XM IMMM" << std::endl;
	std::cout << "  			      MMMX   \"MMMM\"  MM       ~%:           !Mh.\"\"\" dMI IMMP" << std::endl;
	std::cout << "  			      'MMM.                                             IMX" << std::endl;
	std::cout << "  			       ~M!M                                             IMP" << std::endl;
	std::cout << std::endl;
	std::cout << "========================================================================================================================" << std::endl;
	std::cout << std::endl << "						1. Story";
	std::cout << std::endl << "						2. Multiplayer";
	std::cout << std::endl << "						3. Exit" << std::endl;

	std::cout << "Enter choice: ";
	std::cin >> choice;

	while (choice != 1 && choice != 2 && choice != 3) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid! Enter again: ";
		std::cin >> choice;
	}

	if (choice == 1) {
		system("CLS");
		story = true;
	}
	else if (choice == 2) {
		system("CLS");
		multiplayer = true;

	}
	else if (choice == 3) {
		exit(1);
	}
}

void printChoosePokemon(std::vector<Pokemon> &player) {
	std::string name;
	std::locale loc;
	int playerSize = -1;

	pokemonList.push_back(aerodactyl);
	pokemonList.push_back(alakazam);
	pokemonList.push_back(ampharos);
	pokemonList.push_back(arbok);
	pokemonList.push_back(articuno);
	pokemonList.push_back(beedrill);
	pokemonList.push_back(blastoise);
	pokemonList.push_back(butterfree);
	pokemonList.push_back(charizard);
	pokemonList.push_back(clefable);
	pokemonList.push_back(dragonite);
	pokemonList.push_back(exeggutor);
	pokemonList.push_back(gengar);
	pokemonList.push_back(gyrados);
	pokemonList.push_back(jynx);
	pokemonList.push_back(lapras);
	pokemonList.push_back(machamp);
	pokemonList.push_back(magneton);
	pokemonList.push_back(mewtwo);
	pokemonList.push_back(moltres);
	pokemonList.push_back(nidoking);
	pokemonList.push_back(onix);
	pokemonList.push_back(pidgeot);
	pokemonList.push_back(poliwrath);
	pokemonList.push_back(raticate);
	pokemonList.push_back(sandslash);
	pokemonList.push_back(scyther);
	pokemonList.push_back(snorlax);
	pokemonList.push_back(tentacruel);
	pokemonList.push_back(golem);
	pokemonList.push_back(venusaur);
	pokemonList.push_back(weezing);
	pokemonList.push_back(zapdos);
	pokemonList.push_back(raichu);
	pokemonList.push_back(arcanine);

	bool poke = false;
	bool duplicate = false;
	int num;
	std::cout << "how many pokemon: ";
	std::cin >> num;

	for (int i = 0; i < num; i++) {
		poke = false;
		duplicate = false;

		system("CLS");

		std::cout << "Aerodactyl			Alakazam			Ampharos			Arbok" << std::endl;
		std::cout << "Arcanine			Articuno			Beedrill			Blastoise" << std::endl;
		std::cout << "Butterfree			Charizard			Clefable			Dragonite" << std::endl;
		std::cout << "Exeggutor			Gengar				Gyrados				Jynx" << std::endl;
		std::cout << "Lapras				Machamp				Magneton			Mewtwo" << std::endl;
		std::cout << "Moltres				Nidoking			Onix				Pidgeot" << std::endl;
		std::cout << "Poliwrath			Radicate			Raichu				Sandslash" << std::endl;
		std::cout << "Scyther				Snorlax				Tentacruel			Golem" << std::endl;
		std::cout << "Venusaur			Weezing				Zapdos" << std::endl;

		std::cout << "Current Team: " << std::endl;
		for (int i = 0; i < player.size(); i++)
			std::cout << player[i].name << std::endl;

		std::cout << "Choose a pokemon: ";
		std::cin >> name;
		for (int i = 0; i < name.length(); i++) {
			std::tolower(name[i], loc);
		}

		for (int x = 0; x < 35; x++) {
			if (name == pokemonList[x].name) {
				if (player.size() == 0) {
					player.push_back(pokemonList[x]);

					poke = true;
				}
				else {
					for (int f = 0; f < player.size(); f++) {
						if (name == player[f].name) {
							duplicate = true;
						}
					}
					if (duplicate == false)
					{
						player.push_back(pokemonList[x]);
						poke = true;
					}
				}

			}
		}
		if (poke == false) {
			std::cout << "\a";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			i--;
		}
	}
	system("CLS");
}

void useTheMove(int moveChoice, Pokemon &one, Pokemon &two) {
	if (moveChoice == 1) {
		one.useMove(one.move1, two);
		std::cout << one.name << " used " << one.move1.name << "!" << std::endl;
	}
	else if (moveChoice == 2) {
		one.useMove(one.move2, two);
		std::cout << one.name << " used " << one.move2.name << "!" << std::endl;
	}
	else if (moveChoice == 3) {
		one.useMove(one.move3, two);
		std::cout << one.name << " used " << one.move3.name << "!" << std::endl;
	}
	else if (moveChoice == 4) {
		one.useMove(one.move4, two);
		std::cout << one.name << " used " << one.move4.name << "!" << std::endl;
	}
}
void selectMove(int &currentPokemon, int &opponentCurrent, std::vector<Pokemon> &player, std::vector<Pokemon> &trainer) {
	int moveChoice;
	int oppMoveChoice;

	if (currentPokemon < player.size()) {
		std::cout << "What will " << player[currentPokemon].name << " do?" << std::endl;
		std::cout << "1. " << player[currentPokemon].move1.name << "	" << player[currentPokemon].move1.getPP() << "/" << player[currentPokemon].move1.maxPP << std::endl;
		std::cout << "2. " << player[currentPokemon].move2.name << "	" << player[currentPokemon].move2.getPP() << "/" << player[currentPokemon].move2.maxPP << std::endl;
		std::cout << "3. " << player[currentPokemon].move3.name << "	" << player[currentPokemon].move3.getPP() << "/" << player[currentPokemon].move3.maxPP << std::endl;
		std::cout << "4. " << player[currentPokemon].move4.name << "	" << player[currentPokemon].move4.getPP() << "/" << player[currentPokemon].move4.maxPP << std::endl;
		std::cout << "Player 1 pick a move: ";
		std::cin >> moveChoice;

		system("CLS");

		oppMoveChoice = rand() % 4 + 1;

		std::cout << trainer[opponentCurrent].name << " HP: " << trainer[opponentCurrent].stat.getHP() << std::endl;

		std::cout << player[currentPokemon].name << " HP: " << player[currentPokemon].stat.getHP() << std::endl;

		if (player[currentPokemon].stat.SPD > trainer[opponentCurrent].stat.SPD) {
			int temp = opponentCurrent;
			int temp2 = currentPokemon;

			useTheMove(moveChoice, player[currentPokemon], trainer[opponentCurrent]);

			if (player[currentPokemon].stat.HP <= 0) {
				currentPokemon++;
			}
			else if (trainer[opponentCurrent].stat.HP <= 0) {
				opponentCurrent++;
			}

			if (opponentCurrent == temp && currentPokemon == temp2) {
				
				useTheMove(oppMoveChoice, trainer[opponentCurrent], player[currentPokemon]);

			}
		}
		else {
			int temp = opponentCurrent;
			int temp2 = currentPokemon;

			useTheMove(oppMoveChoice, trainer[opponentCurrent], player[currentPokemon]);

			if (player[currentPokemon].stat.HP <= 0) {
				currentPokemon++;
			}
			else if (trainer[opponentCurrent].stat.HP <= 0) {
				opponentCurrent++;
			}

			if (opponentCurrent == temp && currentPokemon == temp2) {

				useTheMove(moveChoice, player[currentPokemon], trainer[opponentCurrent]);
			}
		}
		int count = 0;
		int count2 = 0;

		for (int f = 0; f < player.size(); f++) {
			if (player[f].stat.getHP() <= 0) {
				count++;
			}
		}

		for (int f = 0; f < trainer.size(); f++) {
			if (trainer[f].stat.getHP() <= 0) {
				count2++;
			}
		}

		if (count >= player.size()) {
			p1Alive = false;
		}
		if (count2 >= trainer.size()) {
			trainerAlive = false;
		}

		std::cout << trainer[opponentCurrent].name << " HP: " << trainer[opponentCurrent].stat.getHP() << std::endl;

		std::cout << player[currentPokemon].name << " HP: " << player[currentPokemon].stat.getHP() << std::endl;
	}
}
void startBattle(std::vector<Pokemon> &player, std::vector<Pokemon> &trainer) {
	int currentPokemon = 0, opponentCurrent = 0;

	while (p1Alive == true && trainerAlive == true) {
		selectMove(currentPokemon, opponentCurrent, player, trainer);
	}
}

int main() {
	srand(time(NULL));

	printScreen();

	if (story == true) {
		std::vector<Pokemon> player1;
		printChoosePokemon(player1);

		std::vector<Pokemon> trainer;
		trainer.push_back(venusaur);
		trainer.push_back(blastoise);
		trainer.push_back(charizard);
		trainer.push_back(butterfree);
		trainer.push_back(beedrill);
		trainer.push_back(pidgeot);

		startBattle(player1, trainer);
	}
	
	if (multiplayer == true) {
		Pokemon player1;
		Pokemon player2;
	}
	std::cin.ignore();
	std::cin.get();

	return 0;
}

