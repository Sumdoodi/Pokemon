#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "Pokemon.h"
#include "Moves.h"
#include "Stats.h"

bool story = false, multiplayer = false;
std::vector<Pokemon> pokemonList;

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
Moves quickattack(40, 30, 1.0f, "normal", "P", "first");
Moves extremespeed(80, 5, 1.0f, "normal", "P", "first");
Moves slash(70, 20, 1.0f, "normal", "P", "crit");
Moves stomp(65, 15, 1.0f, "normal", "P", "flinch");
Moves bodyslam(85, 15, 1.0f, "normal", "P", "par");
Moves hyperfang(80, 15, 0.9f, "normal", "P", "flinch");
Moves takedown(90, 20, 0.85f, "normal", "P", "coil");
Moves smokescreen(0, 15, 1.0f, "normal", "S", "dAcc");
Moves focusenergy(0, 30, 1.0f, "normal", "S", "crit");
Moves doubleteam(0, 15, 1.0f, "normal", "S", "iEVA");
Moves sworddance(0, 20, 1.0f, "normal", "S", "iATK");
Moves recover(0, 10, 1.0f, "normal", "S", "heal");
Moves screech(0, 40, 0.85f, "normal", "S", "dDEF");
Moves scaryface(0, 20, 1.0f, "normal", "S", "dSPD");
Moves supersonic(0, 20, 0.55f, "normal", "S", "conf");
Moves sing(0, 15, 0.55f, "normal", "S", "sleep");
Moves glare(0, 30, 1.0f, "normal", "S", "par");
Moves explosion(250, 5, 1.0f, "normal", "P", "death");

//Grass 5 moves
Moves seedbomb(80, 15, 1.0f, "grass", "P", "none");
Moves solarbeam(120, 10, 1.0f, "grass", "Sp", "charge");
Moves megadrain(40, 15, 1.0f, "grass", "Sp", "drain");
Moves gigadrain(75, 10, 1.0f, "grass", "Sp", "drain");
Moves sleeppowder(0, 15, 0.75f, "grass", "S", "sleep");

//Fire 3 moves
Moves firefang(65, 15, 0.95f, "fire", "P", "burn+flinch");
Moves flamethrower(90, 15, 1.0f, "fire", "Sp", "burn");
Moves flareblitz(120, 15, 1.0f, "fire", "Sp", "coil+burn");

//Water 4 moves
Moves surf(90, 15, 1.0f, "water", "Sp", "none");
Moves hydropump(110, 5, 0.8f, "water", "Sp", "none");
Moves aquatail(90, 10, 0.9f, "water", "P", "none");
Moves waterfall(80, 15, 1.0f, "water", "P", "flinch");

//Bug 5 moves
Moves bugbuzz(90, 20, 1.0f, "bug", "Sp", "lSpDEF");
Moves xscissor(80, 15, 1.0f, "bug", "P", "none");
Moves megahorn(120, 10, 1.0f, "bug", "P", "none");
Moves signalbeam(75, 15, 1.0f, "bug", "Sp", "conf");
Moves quiverdance(0, 20, 1.0f, "bug", "S", "iSpATK,SpDEF, SPD");

//Flying 6 moves
Moves aerialace(60, 20, 1.0f, "flying", "P", "100");
Moves airslash(75, 15, 0.95f, "flying", "P", "flinch");
Moves aircutter(60, 25, 0.95f, "flying", "Sp", "crit");
Moves hurricane(110, 10, 0.75f, "flying", "Sp", "conf");
Moves featherdance(0, 15, 1.0f, "flying", "S", "dATK");
Moves roost(0, 10, 1.0f, "flying", "S", "heal");

//Dark 3 moves
Moves crunch(80, 15, 1.0f, "dark", "P", "lSpDEF");
Moves darkpulse(80, 15, 1.0f, "dark", "Sp", "flinch");
Moves assurance(60, 20, 1.0f, "dark", "P", "none");
Moves nightslash(70, 15, 1.0f, "dark", "P", "crit");

//Psychic 8 moves
Moves psychic(90, 10, 1.0f, "psychic", "Sp", "lSpDEF");
Moves psychocut(70, 10, 1.0f, "psychic", "P", "crit");
Moves psystrike(120, 10, 1.0f, "psychic", "Sp", "none");
Moves amnesia(0, 20, 1.0f, "psychic", "S", "iSpDEF");
Moves cosmicpower(0, 20, 1.0f, "psychic", "S", "iDEF, SpDEF");
Moves agility(0, 20, 1.0f, "psychic", "S", "iSPD");
Moves calmmind(0, 20, 1.0f, "psychic", "S", "iSpATK, SpDEF");
Moves barrier(0, 20, 0.0f, "psychic", "S", "iDEF");
Moves hypnosis(0, 20, 0.6f, "psychic", "S", "sleep");
Moves rest(0, 10, 1.0f, "psychic", "S", "sleep+heal");

//Poison 5 moves
Moves poisonjab(80, 20, 1.0f, "poison", "P", "poison");
Moves sludgebomb(90, 10, 1.0f, "poison", "Sp", "poison");
Moves sludgewave(95, 10, 1.0f, "poison", "Sp", "poison");
Moves coil(0, 20, 1.0f, "poison", "S", "iATK, DEF, ACC");
Moves poisonpowder(0, 35, 0.75f, "poison", "S", "poison");

//Electric 4 moves
Moves thunderbolt(90, 15, 1.0f, "electric", "Sp", "par");
Moves thunder(110, 5, 0.7f, "electric", "Sp", "par");
Moves zapcannon(120, 5, 0.5f, "electric", "Sp", "par");
Moves thunderpunch(75, 15, 1.0f, "electric", "Sp", "par");
Moves thunderwave(0, 20, 0.9f, "electric", "S", "par");

//Fighting 4 moves
Moves crosschop(100, 5, 0.8f, "fighting", "P", "crit");
Moves aurasphere(80, 5, 1.0f, "fighting", "Sp", "100");
Moves lowsweep(65, 20, 1.0f, "fighting", "P", "dSPD");
Moves bulkup(0, 20, 1.0f, "fighting", "S", "iATK, DEF");

//Steel 4 moves
Moves flashcannon(80, 10, 1.0f, "steel", "Sp", "lSpDEF");
Moves irontail(100, 15, 1.0f, "steel", "P", "flinch");
Moves ironhead(80, 15, 0.75f, "steel", "P", "lDEF");
Moves irondefense(0, 15, 1.0f, "steel", "S", "iDEF");

//Ghost 4 moves
Moves lick(30, 30, 1.0f, "ghost", "P", "lSpDEF");
Moves shadowball(80, 15, 1.0f, "ghost", "Sp", "lSpDEF");
Moves nightshade(0, 15, 1.0f, "ghost", "Sp", "50");
Moves confuseray(0, 10, 1.0f, "ghost", "P", "conf");

//Ground 2 moves
Moves earthquake(100, 10, 1.0f, "ground", "P", "none");
Moves sandattack(0, 15, 1.0f, "ground", "S", "dACC");

//Rock 3 moves
Moves rockslide(75, 10, 0.9f, "rock", "P", "flinch");
Moves stoneedge(100, 10, 0.8f, "rock", "P", "crit");
Moves rockpolish(0, 20, 1.0f, "rock", "S", "iSPD");

//Ice 2 moves
Moves icepunch(75, 10, 1.0f, "ice", "P", "freeze");
Moves icebeam(90, 10, 1.0f, "ice", "P", "freeze");
Moves icefang(65, 15, 0.95f, "ice", "P", "freeze+flinch");
Moves blizzard(120, 5, 0.7f, "ice", "Sp", "freeze");

//Dragon 2 moves
Moves dragonrush(100, 10, 0.75f, "dragon", "P", "conf");
Moves dragonpulse(85, 10, 1.0f, "dragon", "P", "none");
Moves dragondance(0, 20, 1.0f, "dragon", "S", "iATK, SPD");

//Fairy 2 moves
Moves moonblast(95, 15, 1.0f, "fairy", "Sp", "lSpATK");
Moves moonlight(0, 10, 1.0f, "fairy", "S", "heal");

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

	pokemonList[0] = aerodactyl;
	pokemonList[1] = alakazam;
	pokemonList[2] = ampharos;
	pokemonList[3] = arbok;
	pokemonList[4] = articuno;
	pokemonList[5] = beedrill;
	pokemonList[6] = blastoise;
	pokemonList[7] = butterfree;
	pokemonList[8] = charizard;
	pokemonList[9] = clefable;
	pokemonList[10] = dragonite;
	pokemonList[11] = exeggutor;
	pokemonList[12] = gengar;
	pokemonList[13] = gyrados;
	pokemonList[14] = jynx;
	pokemonList[15] = lapras;
	pokemonList[16] = machamp;
	pokemonList[17] = magneton;
	pokemonList[18] = mewtwo;
	pokemonList[19] = moltres;
	pokemonList[20] = nidoking;
	pokemonList[21] = onix;
	pokemonList[22] = pidgeot;
	pokemonList[23] = poliwrath;
	pokemonList[24] = raticate;
	pokemonList[25] = sandslash;
	pokemonList[26] = scyther;
	pokemonList[27] = snorlax;
	pokemonList[28] = tentacruel;
	pokemonList[29] = golem;
	pokemonList[30] = venusaur;
	pokemonList[31] = weezing;
	pokemonList[32] = zapdos;
	pokemonList[33] = raichu;
	pokemonList[34] = arcanine;

	std::cout << "Aerodactyl			Alakazam			Ampharos			Arbok" << std::endl;
	std::cout << "Arcanine			Articuno			Beedrill			Blastoise" << std::endl;
	std::cout << "Butterfree			Charizard			Clefable			Dragonite" << std::endl;
	std::cout << "Exeggutor			Gengar				Gyrados				Jynx" << std::endl;
	std::cout << "Lapras				Machamp				Magneton			Mewtwo" << std::endl;
	std::cout << "Moltres				Nidoking			Onix				Pidgeot" << std::endl;
	std::cout << "Poliwrath			Radicate			Raichu				Sandslash" << std::endl;
	std::cout << "Scyther				Snorlax				Tentacruel			Golem" << std::endl;
	std::cout << "Venusaur			Weezing				Zapdos" << std::endl;

	for (int i = 0; i < 6; i++) {
		std::cout << "Choose a pokemon: ";
		std::cin >> name;
		for (int i = 0; i < name.length(); i++) {
			std::tolower(name[i], loc);
		}
		for (int x = 0; x < pokemonList.size(); x++) {
			if (name == pokemonList[x].name) {
				for (int f = 0; f < player.size(); f++) {
					if (name != player[f].name) {
						player[i] = pokemonList[x];
					}
				}
			}
		}
	}

}
int main() {

	printScreen();

	if (story == true) {
		std::vector<Pokemon> player1;
		printChoosePokemon(player1);
	}

	if (multiplayer == true) {
		Pokemon player1;
		Pokemon player2;
	}
	std::cin.ignore();
	std::cin.get();

	return 0;
}
