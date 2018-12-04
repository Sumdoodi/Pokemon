#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "picture.h"
#include "Pokemon.h"
#include "Moves.h"
#include "Stats.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "BattleScreen.h"
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <MMsystem.h>

bool story = false, multiplayer = false, extra = false;
bool p1Alive = true, p2Alive = true, trainerAlive = true;
int num;
int pkm = 0;
unsigned int stage = 1;

std::vector<Pokemon> pokemonList;
std::vector<Pokemon> trainer;
std::string trainerName;


Picture venusaur_img(" +----------------+", " |                |",  " |      |--|      |", " |     +----+     |", " |       ||       |", " |    +------+    |", " |   +o o    ++   |", " |    +------+    |", " |     ||   ||    |", " +----------------+");
Picture blastoise_img(" +----------------+", " |                |", " |  ++    ++      |", " |   +------+     |", " |   |    +---+   |", " |   | +  |o o|   |", " |   | |  +---+   |", " |   +------+     |", " |    ||  ||      |", " +----------------+");
Picture charizard_img(" +----------------+", " |                |", " | +---+ ++ +---+ |", " |  +--||oo||--+  |", " |    |------|    |", " |  <---------->  |", " |      |--|      |", " |   +--+--+      |", " |      |  |      |", " +----------------+");
Picture butterfree_img(" +----------------+", " |                |", " | +----+  +----+ |", " | |    +--+    | |", " | |    |--|    | |", " | +-+--------+-+ |", " |   |  +--+  |   |", " |   +--+  +--+   |", " |                |", " +----------------+");
Picture beedrill_img(" +----------------+", " |                |", " |    +-- +       |", " |    |oo |+ +    |", " |    +------ +   |", " |     |---- +    |", " |      |-- +     |", " |      +-+       |", " |       V        |", " +----------------+");
Picture pidgeot_img(" +----------------+", " |        +--|	 |", " |    +---+ |o-+  |", " |  +-+   +--|    |", " |     +-----+    |", " |  +-------+     |", " |  |--+ | |      |", " | +-+   | |      |", " |       ++++     |", " +----------------+");
Picture raticate_img(" +----------------+", " |       ()_--_() |", " |        |o  o|  |", " |    +---|    |  |", " | x +    | VV |  |", " | |+ u  u| ^^ |  |", " | |+     +----+  |", " |  +-----+       |", " |   U   U        |", " +----------------+");
Picture arbok_img(" +----------------+", " |   +---+        |", " |  |     |       |", " |  | o o |       |", " |  | VVV |   ^^  |", " |  + VVV +   ||  |", " |   +---+  +--+  |", " |     +-----+    |", " |      |---|     |", " +----------------+");
Picture raichu_img(" +----------------+", " |        ^  ^    |", " |        |  |    |", " |  +    ++--++   |", " |  ++ +-+ o o|   |", " |  ++ | +----+   |", " |   +-+ u   u|   |", " |     ++---+-+   |", " |      |   |     |", " +----------------+");
Picture sandslash_img(" +----------------+", " |     ^    ^     |", " |     |----|     |", " |   <-| oo |->   |", " |  <---|  |--->  |", " |   +--------+   |", " |   v |    | v   |", " |     +----+     |", " |   +-+    +-+   |", " +----------------+");
Picture nidoking_img(" +----------------+", " |   | +----+ |   |", " |   +-+\  /+-+   |", " |  +----------+  |", " | +--+      +--+ |", " | +- +-    -+ -+ |", " |    |------|    |", " |   +-|    |-+   |", " |   |-|    |-|   |", " +----------------+");
Picture clefable_img(" +----------------+", " | ||   |--|   || |", " | +------------+ |", " |  ++   +-+  +   |", " |   |  o  o  |   |", " | <-+   ww   +-> |", " |    +      +    |", " |    +------+    |", " |    ||    ||    |", " +----------------+");
Picture arcanine_img(" +----------------+", " | +----+     ||  |", " | |\  /|   +---+ |", " | | -- +-------| |", " | ++---+  +---++ |", " |  +          +  |", " |   +--------+   |", " |   +-|   +--+   |", " |    ||    ||    |", " +----------------+");
Picture poliwrath_img(" +----------------+", " |                |", " |     +----+     |", " |    +      +    |", " |  ++  \  /  ++  |", " | +-+   __   +-+ |", " | + +        + + |", " |    +------+    |", " |   +-|    |-+   |", " +----------------+");
Picture alakazam_img(" +----------------+", " |    ++    ++    |", " |     +----+     |", " | <--++ oo ++--> |", " |      +  +   +  |", " |  +--+ ++ +--++ |", " | + +  +  +      |", " |      +--+      |", " |      |  |      |", " +----------------+");
Picture machamp_img(" +----------------+", " |                |", " |  +-+      +-+  |", " |    | +--+ |    |", " |    +-(..)+-+   |", " |  +----------+  |", " |  +  +----+  +  |", " |      |  |      |", " |      |  |      |", " +----------------+");
Picture tentacruel_img(" +----------------+", " |   +--+  +--+   |", " |  |   +--+   |  |", " |   +--+  +--+   |", " |  +  ++  ++  +  |", " | + --(o++o)-- + |", " | v | ++--++ | v |", " |   v  |  |  v   |", " |      v  v      |", " +----------------+");
Picture golem_img(" +----------------+", " |                |", " |  |          |  |", " |     +----+     |", " |    + _  _ +    |", " | ++ | o  o | ++ |", " | +  +      +  + |", " |     +----+     |", " |   ++      ++   |", " +----------------+");
Picture magneton_img(" +----------------+", " |   |   ||   |   |", " |  +++------+++  |", " |    |  (o) |    |", " | ++-+      +-++ |", " |  | +-+--+-+ |  |", " |  |o) |  | (o|  |", " |  +---+  +---+  |", " |                |", " +----------------+");
Picture gengar_img(" +----------------+", " | ||   |--|   || |", " | +----    ----+ |", " |  ++|\    /|++  |", " |   ||o\  /o||   |", " |  ++  ____  ++  |", " |  v + VVVV + v  |", " |    +------+    |", " |    ||    ||    |", " +----------------+");
Picture onix_img(" +----------------+", " |                |", " |            |   |", " |          +-+-+ |", " | +   +--+ | ,,| |", " | +-+ |  +-+   | |", " | +- -  +- +-+-+ |", " |   |  | |   |   ||", " |   +--+ +---+   |", " +----------------+");
Picture exeggutor_img(" +----------------+", " |   |   ||   |   |", " |  +++ +--+ +++  |", " |    +------+    |", " |     O () O     |", " |      ----      |", " |      |--|      |", " |     +----+     |", " |     |    |     |", " +----------------+");
Picture weezing_img(" +----------------+", " |   +---+        |", " |  + T T +       |", " |  |  ^  +---+   |", " |  +     | T T+  |", " |    +--+   ^ +  |", " |      |-+---+   |", " |      +--+      |", " |                |", " +----------------+");
Picture scyther_img(" +----------------+", " |       ||       |", " |  +-+ +oo+ +-+  |", " |   ++  ||  ++   |", " |   +--------+   |", " |  ++  +--+  ++  |", " | +-+   ||   +-+ |", " | ++   +--+   ++ |", " |      |  |      |", " +----------------+");
Picture jynx_img(" +----------------+", " |    ~~~~~~~~    |", " |  ~~~+----+~~~  |", " | ~~~~|O  U|~~~~ |", " | ++~+- == -+~++ |", " | ++~~ +--+ ~~++ |", " |   +~~    ~~+   |", " |  +          +  |", " |  +----------+  |", " +----------------+");
Picture gyarados_img(" +----------------+", " |   |            |", " |++ | ++     --+ |", " | +-+-+  +--+  | |", " | |\ /|--      | |", " | +VVV++   -+  | |", " |  | | +--+  + + |", " |  VVV      +++  |", " |         +-+    |", " +----------------+");
Picture lapras_img(" +----------------+", " |         ||  || |", " |         +----+ |", " |          |u u| |", " |          +---+ |", " |    +--+  ||    |", " |   +    ---|    |", " |  -  ++   |-+   |", " | |--++-------+  |", " +----------------+");
Picture aerodactyl_img(" +----------------+", " | +--+     |---| |", " | +   --  +O|VVV |", " |  |    ----+    |", " |  +--   +-+VVV  |", " |     +  |  +-+  |", " | +---+--++      |", " |      ++  ++    |", " |                |", " +----------------+");
Picture snorlax_img(" +----------------+", " |     +----+     |", " |     |~  ~|     |", " |   +--------+   |", " |  +          +  |", " |  | U      U |  |", " |  +          +  |", " |   +--------+   |", " |   ||      ||   |", " +----------------+");
Picture articuno_img(" +----------------+", " | |-|        |-| |", " | +-|   ++   |-+ |", " |  |-+  ||  +-|  |", " |  +----------+  |", " |      +--+    + |", " |     ++  +-+ ++ |", " |     ++  ++ ++  |", " |    ++    ++    |", " +----------------+");
Picture zapdos_img(" +----------------+", " |                |", " | <+ ^  ++  ^ +> |", " |  +-+  || +-+   |", " | <------------> |", " |   <-------->   |", " |      +--+      |", " |   +-+ || +-+   |", " |      +--+      |", " +----------------+");
Picture moltres_img(" +----------------+", " | ++    <>    ++ |", " | V+-+  |-> +-+V |", " | +------------+ |", " | VV+--------+VV |", " |   VV +--+ VV   |", " |     + ++ +     |", " |    ++ VV ++    |", " |      VVVV      |", " +----------------+");
Picture dragonite_img(" +----------------+", " |      +--+      |", " | +--+ |oo| +--+ |", " | +  +-+  +-+  + |", " |  +--+ ++ +--+  |", " | +-+ |    | +-+ |", " | ++ +      + ++ |", " |    | ---- |    |", " |    ||    ||    |", " +----------------+");
Picture mewtwo_img(" +----------------+", " |      ^  ^      |", " |      +--+  ++  |", " |      ----  ++  |", " |   +-+ || +-+   |", " | ++   +--+      |", " | ++   +--+      |", " |     ++  ++     |", " |     ||  ||     |", " +----------------+");
Picture ampharos_img(" +----------------+", " |        |  |    |", " |        |--.+   |", " |         |o-o   |", " |   o      +--+  |", " |   +    _| |    |", " |    + _|+-  |-+ |", " |     +-----+    |", " |        |  |    |", " +----------------+");




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
Stats gyarados_stats(95, 125, 79, 60, 100, 81);
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
Moves quickattack("Quick Attack", 40, 30, 1.f, "normal", "P", "first");
Moves extremespeed("Extreme Speed", 80, 5, 1.0f, "normal", "P", "first");
Moves slash("Slash", 70, 20, 1.0f, "normal", "P", "crit");
Moves stomp("Stomp", 65, 15, 1.0f, "normal", "P", "flinch30");
Moves bodyslam("Body Slam", 85, 15, 1.0f, "normal", "P", "par30");
Moves hyperfang("Hyper Fang", 80, 15, 0.9f, "normal", "P", "flinch10");
Moves takedown("Take Down", 90, 20, 0.85f, "normal", "P", "coil25");
Moves smokescreen("Smokescreen", 0, 15, 1.0f, "normal", "S", "dAcc1");
Moves focusenergy("Focus Energy", 0, 30, 0.0f, "normal", "S", "crit");
Moves doubleteam("Double Team", 0, 15, 0.0f, "normal", "S", "iEVA1");
Moves sworddance("Sword Dance", 0, 20, 0.0f, "normal", "S", "iATK2");
Moves recover("Recover", 0, 10, 0.0f, "normal", "S", "heal50");
Moves screech("Screech", 0, 40, 0.85f, "normal", "S", "dDEF2");
Moves scaryface("Scary Face", 0, 20, 1.0f, "normal", "S", "dSPD2");
Moves supersonic("Supersonic", 0, 20, 0.55f, "normal", "S", "conf100");
Moves sing("Sing", 0, 15, 0.55f, "normal", "S", "sleep100");
Moves glare("Glare", 0, 30, 1.0f, "normal", "S", "par100");
Moves explosion("Explosion", 250, 5, 1.0f, "normal", "P", "death");

//Grass 5 moves
Moves seedbomb("Seed Bomb", 80, 15, 1.0f, "grass", "P", "none");
Moves solarbeam("Solar Beam", 120, 10, 1.0f, "grass", "Sp", "charge");
Moves leafstorm("Leaf Storm", 130, 5, 0.9f, "grass", "Sp", "sdSpDEF2");
Moves megadrain("Mega Drain", 40, 15, 1.0f, "grass", "Sp", "drain50");
Moves gigadrain("Giga Drain", 75, 10, 1.0f, "grass", "Sp", "drain50");
Moves sleeppowder("Sleep Powder", 0, 15, 0.75f, "grass", "S", "sleep100");
Moves stunspore("Stun Spore", 0, 30, 0.75f, "grass", "S", "par100");

//Fire 3 moves
Moves firefang("Fire Fang", 65, 15, 0.95f, "fire", "P", "burn10+flinch10");
Moves flamethrower("Flame Thrower", 90, 15, 1.0f, "fire", "Sp", "burn10");
Moves flareblitz("Flare Blitz", 120, 15, 1.0f, "fire", "Sp", "coil33+burn10");
Moves willowisp("Will-O-Wisp", 0, 15, 0.85f, "fire", "Sp", "burn100");

//Water 4 moves
Moves surf("Surf", 90, 15, 1.0f, "water", "Sp", "none");
Moves hydropump("Hydro Pump", 110, 5, 0.8f, "water", "Sp", "none");
Moves aquatail("Aqua Tail", 90, 10, 0.9f, "water", "P", "none");
Moves waterfall("Waterfall", 80, 15, 1.0f, "water", "P", "flinch20");

//Bug 5 moves
Moves bugbuzz("Bug Buzz", 90, 20, 1.0f, "bug", "Sp", "lSpDEF10");
Moves xscissor("X=Scissor", 80, 15, 1.0f, "bug", "P", "none");
Moves megahorn("Megahorn", 120, 10, 1.0f, "bug", "P", "none");
Moves signalbeam("Signal Beam", 75, 15, 1.0f, "bug", "Sp", "conf10");
Moves quiverdance("Quiver Dance", 0, 20, 0.0f, "bug", "S", "iSpATK1+SpDEF1+SPD1");

//Flying 6 moves
Moves aerialace("Aerial Ace", 60, 20, 0.0f, "flying", "P", "100");
Moves airslash("Air Slash", 75, 15, 0.95f, "flying", "Sp", "flinch30");
Moves aircutter("Air Cutter", 60, 25, 0.95f, "flying", "Sp", "crit");
Moves hurricane("Hurricane", 110, 10, 0.75f, "flying", "Sp", "conf30");
Moves featherdance("Feather Dance", 0, 15, 1.0f, "flying", "S", "dATK2");
Moves roost("Roost", 0, 10, 0.0f, "flying", "S", "heal50");

//Dark 3 moves
Moves crunch("Crunch", 80, 15, 1.0f, "dark", "P", "lSpDEF20");
Moves darkpulse("Dark Pulse", 80, 15, 1.0f, "dark", "Sp", "flinch20");
Moves assurance("Assurance", 60, 20, 1.0f, "dark", "P", "none");
Moves nightslash("Night Slash", 70, 15, 1.0f, "dark", "P", "crit");

//Psychic 8 moves
Moves psychic("Psychic", 90, 10, 1.0f, "psychic", "Sp", "lSpDEF10");
Moves psychocut("Psycho Cut", 70, 10, 1.0f, "psychic", "P", "crit");
Moves psystrike("Psystrike", 120, 10, 1.0f, "psychic", "Sp", "none");
Moves amnesia("Amnesia", 0, 20, 0.0f, "psychic", "S", "iSpDEF2");
Moves cosmicpower("Cosmic Power", 0, 20, 0.0f, "psychic", "S", "iDEF1+SpDEF1");
Moves agility("Agility", 0, 20, 0.0f, "psychic", "S", "iSPD2");
Moves calmmind("Calm Mind", 0, 20, 0.0f, "psychic", "S", "iSpATK1+SpDEF1");
Moves barrier("Barrier", 0, 20, 0.0f, "psychic", "S", "iDEF2");
Moves hypnosis("Hypnosis", 0, 20, 0.6f, "psychic", "S", "sleep100");
Moves rest("Rest", 0, 10, 1.0f, "psychic", "S", "sSleep100+heal100");

//Poison 5 moves
Moves poisonjab("Poison Jab", 80, 20, 1.0f, "poison", "P", "poison30");
Moves sludgebomb("Sludge Bomb", 90, 10, 1.0f, "poison", "Sp", "poison30");
Moves sludgewave("Sludge Wave", 95, 10, 1.0f, "poison", "Sp", "poison10");
Moves coil("Coil", 0, 20, 0.0f, "poison", "S", "iATK1+DEF1+ACC1");
Moves poisonpowder("Poison Powder", 0, 35, 0.75f, "poison", "S", "poison100");
//Electric 4 moves
Moves thunderbolt("Thunderbolt", 90, 15, 1.0f, "electric", "Sp", "par10");
Moves thunder("Thunder", 110, 5, 0.7f, "electric", "Sp", "par30");
Moves zapcannon("Zap Cannon", 120, 5, 0.5f, "electric", "Sp", "par100");
Moves thunderpunch("Thunder Punch", 75, 15, 1.0f, "electric", "Sp", "par10");
Moves thunderwave("Thunder Wave", 0, 20, 0.9f, "electric", "S", "par100");

//Fighting 4 moves
Moves crosschop("Cross Chop", 100, 5, 0.8f, "fighting", "P", "crit");
Moves aurasphere("Aura Sphere", 80, 5, 0.0f, "fighting", "Sp", "100");
Moves lowsweep("Low Sweep", 65, 20, 1.0f, "fighting", "P", "dSPD1");
Moves bulkup("Bulk Up", 0, 20, 0.0f, "fighting", "S", "iATK1+DEF1");

//Steel 4 moves
Moves flashcannon("Flash Cannon", 80, 10, 1.0f, "steel", "Sp", "lSpDEF10");
Moves irontail("Iron Tail", 100, 15, 1.0f, "steel", "P", "flinch30");
Moves ironhead("Iron Head", 80, 15, 0.75f, "steel", "P", "lDEF30");
Moves irondefense("Iron Defense", 0, 15, 0.0f, "steel", "S", "iDEF2");

//Ghost 4 moves
Moves lick("Lick", 30, 30, 1.0f, "ghost", "P", "par30");
Moves shadowball("Shadow Ball", 80, 15, 1.0f, "ghost", "Sp", "lSpDEF20");
Moves nightshade("Night Shade", 0, 15, 1.0f, "ghost", "Sp", "deal50");
Moves confuseray("Confuse Ray", 0, 10, 1.0f, "ghost", "P", "conf100");

//Ground 2 moves
Moves earthquake("Earthquake", 100, 10, 1.0f, "ground", "P", "none");
Moves sandattack("Sand Attack", 0, 15, 1.0f, "ground", "S", "dACC1");

//Rock 3 moves
Moves rockslide("Rock Slide", 75, 10, 0.9f, "rock", "P", "flinch30");
Moves stoneedge("Stone Edge", 100, 10, 0.8f, "rock", "P", "crit");
Moves rockpolish("Rock Polish", 0, 20, 0.0f, "rock", "S", "iSPD2");
//Ice 2 moves
Moves icepunch("Ice Punch", 75, 10, 1.0f, "ice", "P", "freeze10");
Moves icebeam("Ice Beam", 90, 10, 1.0f, "ice", "P", "freeze10");
Moves icefang("Ice Fang", 65, 15, 0.95f, "ice", "P", "freeze10+flinch10");
Moves blizzard("Blizzard", 120, 5, 0.7f, "ice", "Sp", "freeze10");

//Dragon 2 moves
Moves dragonrush("Dragon Rush", 100, 10, 0.75f, "dragon", "P", "conf20");
Moves dragonpulse("Dragon Pulse", 85, 10, 1.0f, "dragon", "P", "none");
Moves dragondance("Dragon Dance", 0, 20, 0.0f, "dragon", "S", "iATK1+SPD1");

//Fairy 2 moves
Moves moonblast("Moonblast", 95, 15, 1.0f, "fairy", "Sp", "lSpATK30");
Moves moonlight("Moonlight", 0, 10, 0.0f, "fairy", "S", "heal50");

//Generate Pokemon
Pokemon venusaur("1", "Venusaur", venusaur_stats, "grass", "poison", "none", takedown, sludgebomb, gigadrain, poisonpowder, venusaur_img);
Pokemon charizard("2", "Charizard",charizard_stats, "fire", "flying", "none", slash, flamethrower, airslash, scaryface, charizard_img);
Pokemon blastoise("3", "Blastoise", blastoise_stats, "water", "none", "none", bodyslam, surf, irondefense, crunch, blastoise_img);
Pokemon butterfree("4", "Butterfree", butterfree_stats, "bug", "flying", "none", bugbuzz, sleeppowder, quiverdance, aircutter, butterfree_img);
Pokemon beedrill("5", "Beedrill",beedrill_stats, "bug", "poison", "none", poisonjab, agility, xscissor, assurance, beedrill_img);
Pokemon pidgeot("6", "Pidgeot", pidgeot_stats, "normal", "flying", "none", quickattack, airslash, sandattack, featherdance, pidgeot_img);
Pokemon raticate("7", "Raticate", raticate_stats, "normal", "none", "none", hyperfang, crunch, sworddance, focusenergy, raticate_img);
Pokemon arbok("8", "Arbok", arbok_stats, "poison", "none", "none", sludgebomb, coil, screech, glare, arbok_img);
Pokemon raichu("9", "Raichu", raichu_stats, "electric", "none", "none", thunderbolt, thunder, thunderwave, doubleteam, raichu_img);
Pokemon sandslash("10", "Sandslash",sandslash_stats, "ground", "none", "none", slash, earthquake, sandattack, sworddance, sandslash_img);
Pokemon nidoking("11", "Nidoking", nidoking_stats, "ground", "poison", "none", earthquake, megahorn, focusenergy, bodyslam, nidoking_img);
Pokemon clefable("12", "Clefable", clefable_stats, "fairy", "none", "none", bodyslam, moonblast, cosmicpower, moonlight, clefable_img);
Pokemon arcanine("13", "Arcanine", arcanine_stats, "fire", "none", "none", flareblitz, agility, crunch, extremespeed, arcanine_img);
Pokemon poliwrath("14", "Poliwrath", poliwrath_stats, "water", "fighting", "none", waterfall, amnesia, bodyslam, lowsweep, poliwrath_img);
Pokemon alakazam("15", "Alakazam", alakazam_stats, "psychic", "none", "none", calmmind, psychic, recover, shadowball, alakazam_img);
Pokemon machamp("16", "Machamp", machamp_stats, "fighting", "none", "none", crosschop, bulkup, focusenergy, lowsweep, machamp_img);
Pokemon tentacruel("17", "Tentacruel", tentacruel_stats, "water", "poison", "none", sludgewave, hydropump, barrier, supersonic, tentacruel_img);
Pokemon golem("18", "Golem", golem_stats, "rock", "ground", "none", earthquake, stoneedge, explosion, rockpolish, golem_img);
Pokemon magneton("19", "Magneton",magneton_stats, "electric", "steel", "none", supersonic, thunderbolt, flashcannon, zapcannon, magneton_img);
Pokemon gengar("20", "Gengar",gengar_stats, "ghost", "poison", "none", shadowball, sludgebomb, hypnosis, darkpulse, gengar_img);
Pokemon onix("21", "Onix",onix_stats, "rock", "ground", "none", rockslide, earthquake, irontail, rockpolish, onix_img);
Pokemon exeggutor("22", "Exeggutor", exeggutor_stats, "grass", "psychic", "none", leafstorm, stomp, psychic, stunspore, exeggutor_img);
Pokemon weezing("23", "Weezing",weezing_stats, "poison", "none", "none", sludgebomb, explosion, assurance, smokescreen, weezing_img);
Pokemon scyther("24", "Scyther",scyther_stats, "bug", "flying", "none", airslash, xscissor, agility, nightslash, scyther_img);
Pokemon jynx("25", "Jynx",jynx_stats, "psychic", "ice", "none", icepunch, bodyslam, psychic, blizzard, jynx_img);
Pokemon gyarados("26", "Gyarados",gyarados_stats, "water", "flying", "none", dragondance, irontail, icefang, aquatail, gyarados_img);
Pokemon lapras("27", "Lapras",lapras_stats, "water", "ice", "none", hydropump, icebeam, bodyslam, confuseray, lapras_img);
Pokemon aerodactyl("28", "Aerodactyl",aerodactyl_stats, "rock", "flying", "none", crunch, rockslide, ironhead, aerialace, aerodactyl_img);
Pokemon snorlax("29", "Snorlax",snorlax_stats, "normal", "none", "none", bodyslam, amnesia, rest, crunch, snorlax_img);
Pokemon articuno("30", "Articuno",articuno_stats, "ice", "flying", "none", icebeam, roost, hurricane, agility, articuno_img);
Pokemon zapdos("31", "Zapdos",zapdos_stats, "electric", "flying", "none", thunderbolt, roost, agility, aircutter, zapdos_img);
Pokemon moltres("32", "Moltres",moltres_stats, "fire", "flying", "none", flamethrower, airslash, roost, willowisp, moltres_img);
Pokemon dragonite("33", "Dragonite",dragonite_stats, "dragon", "flying", "none", dragonrush, thunderwave, dragondance, hurricane, dragonite_img);
Pokemon mewtwo("34", "Mewtwo",mewtwo_stats, "psychic", "none", "none", psystrike, shadowball, recover, aurasphere, mewtwo_img);
Pokemon ampharos("35", "Ampharos",ampharos_stats, "electric", "none", "none", thunderpunch, thunderwave, signalbeam, dragonpulse, ampharos_img);


void printScreen() {
	int choice;

	std::cout << std::endl << "========================================================================================================================" << std::endl;
	std::cout << "  			                                .::." << std::endl;
	std::cout << "  					              .;:**'               " << std::endl;
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

	PlaySound(TEXT(NULL), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	if (story == true) {
		if (stage == 1) {
			pokemonList.clear();
			pokemonList.push_back(butterfree);
			//pokemonList.back().img = butterfree.img;
			pokemonList.push_back(beedrill);
			//pokemonList.back().img = beedrill.img;
			pokemonList.push_back(pidgeot);
			//pokemonList.back().img = pidgeot.img;
			pokemonList.push_back(arbok);
			//pokemonList.back().img = arbok.img;
			pokemonList.push_back(raichu);
			//pokemonList.back().img = raichu.img;
			pokemonList.push_back(onix);
			//pokemonList.back().img = onix.img;
		}

		else if (stage == 2) {
			pokemonList.clear();
			pokemonList.push_back(venusaur);
			pokemonList.push_back(butterfree);
			pokemonList.push_back(beedrill);
			pokemonList.push_back(pidgeot);
			pokemonList.push_back(raticate);
			pokemonList.push_back(arbok);
			pokemonList.push_back(raichu);
			pokemonList.push_back(sandslash);
			pokemonList.push_back(onix);
		}

		else if (stage == 3) {
			pokemonList.clear();
			pokemonList.push_back(venusaur);
			pokemonList.push_back(blastoise);
			pokemonList.push_back(butterfree);
			pokemonList.push_back(beedrill);
			pokemonList.push_back(pidgeot);
			pokemonList.push_back(raticate);
			pokemonList.push_back(arbok);
			pokemonList.push_back(raichu);
			pokemonList.push_back(sandslash);
			pokemonList.push_back(tentacruel);
			pokemonList.push_back(onix);
		}

		else if (stage == 4) {
			pokemonList.clear();
			pokemonList.push_back(venusaur);
			pokemonList.push_back(charizard);
			pokemonList.push_back(blastoise);
			pokemonList.push_back(butterfree);
			pokemonList.push_back(beedrill);
			pokemonList.push_back(pidgeot);
			pokemonList.push_back(raticate);
			pokemonList.push_back(arbok);
			pokemonList.push_back(raichu);
			pokemonList.push_back(sandslash);
			pokemonList.push_back(nidoking);
			pokemonList.push_back(machamp);
			pokemonList.push_back(tentacruel);
			pokemonList.push_back(onix);
		}

		else if (stage == 5) {
			pokemonList.clear();
			pokemonList.push_back(venusaur);
			pokemonList.push_back(charizard);
			pokemonList.push_back(blastoise);
			pokemonList.push_back(butterfree);
			pokemonList.push_back(beedrill);
			pokemonList.push_back(pidgeot);
			pokemonList.push_back(raticate);
			pokemonList.push_back(arbok);
			pokemonList.push_back(raichu);
			pokemonList.push_back(sandslash);
			pokemonList.push_back(nidoking);
			pokemonList.push_back(machamp);
			pokemonList.push_back(tentacruel);
			pokemonList.push_back(onix);
			pokemonList.push_back(jynx);
			pokemonList.push_back(lapras);
		}

		else if (stage == 6) {
			pokemonList.clear();
			pokemonList.push_back(venusaur);
			pokemonList.push_back(charizard);
			pokemonList.push_back(blastoise);
			pokemonList.push_back(butterfree);
			pokemonList.push_back(beedrill);
			pokemonList.push_back(pidgeot);
			pokemonList.push_back(raticate);
			pokemonList.push_back(arbok);
			pokemonList.push_back(raichu);
			pokemonList.push_back(sandslash);
			pokemonList.push_back(nidoking);
			pokemonList.push_back(clefable);
			pokemonList.push_back(poliwrath);
			pokemonList.push_back(machamp);
			pokemonList.push_back(tentacruel);
			pokemonList.push_back(magneton);
			pokemonList.push_back(onix);
			pokemonList.push_back(exeggutor);
			pokemonList.push_back(jynx);
			pokemonList.push_back(lapras);
			pokemonList.push_back(snorlax);
		}

		else if (stage == 7) {
			pokemonList.clear();
			pokemonList.push_back(venusaur);
			pokemonList.push_back(charizard);
			pokemonList.push_back(blastoise);
			pokemonList.push_back(butterfree);
			pokemonList.push_back(beedrill);
			pokemonList.push_back(pidgeot);
			pokemonList.push_back(raticate);
			pokemonList.push_back(arbok);
			pokemonList.push_back(raichu);
			pokemonList.push_back(sandslash);
			pokemonList.push_back(nidoking);
			pokemonList.push_back(clefable);
			pokemonList.push_back(poliwrath);
			pokemonList.push_back(machamp);
			pokemonList.push_back(tentacruel);
			pokemonList.push_back(golem);
			pokemonList.push_back(magneton);
			pokemonList.push_back(onix);
			pokemonList.push_back(exeggutor);
			pokemonList.push_back(jynx);
			pokemonList.push_back(lapras);
			pokemonList.push_back(snorlax);
		}

		else if (stage == 8) {
			pokemonList.clear();
			pokemonList.push_back(venusaur);
			pokemonList.push_back(charizard);
			pokemonList.push_back(blastoise);
			pokemonList.push_back(butterfree);
			pokemonList.push_back(beedrill);
			pokemonList.push_back(pidgeot);
			pokemonList.push_back(raticate);
			pokemonList.push_back(arbok);
			pokemonList.push_back(raichu);
			pokemonList.push_back(sandslash);
			pokemonList.push_back(nidoking);
			pokemonList.push_back(clefable);
			pokemonList.push_back(arcanine);
			pokemonList.push_back(poliwrath);
			pokemonList.push_back(machamp);
			pokemonList.push_back(tentacruel);
			pokemonList.push_back(golem);
			pokemonList.push_back(magneton);
			pokemonList.push_back(onix);
			pokemonList.push_back(exeggutor);
			pokemonList.push_back(weezing);
			pokemonList.push_back(scyther);
			pokemonList.push_back(jynx);
			pokemonList.push_back(lapras);
			pokemonList.push_back(snorlax);
		}

		else if (stage == 9 || 10) {
			pokemonList.clear();
			pokemonList.push_back(venusaur);
			pokemonList.push_back(charizard);
			pokemonList.push_back(blastoise);
			pokemonList.push_back(butterfree);
			pokemonList.push_back(beedrill);
			pokemonList.push_back(pidgeot);
			pokemonList.push_back(raticate);
			pokemonList.push_back(arbok);
			pokemonList.push_back(raichu);
			pokemonList.push_back(sandslash);
			pokemonList.push_back(nidoking);
			pokemonList.push_back(clefable);
			pokemonList.push_back(arcanine);
			pokemonList.push_back(poliwrath);
			pokemonList.push_back(alakazam);
			pokemonList.push_back(machamp);
			pokemonList.push_back(tentacruel);
			pokemonList.push_back(golem);
			pokemonList.push_back(magneton);
			pokemonList.push_back(gengar);
			pokemonList.push_back(onix);
			pokemonList.push_back(exeggutor);
			pokemonList.push_back(weezing);
			pokemonList.push_back(scyther);
			pokemonList.push_back(jynx);
			pokemonList.push_back(lapras);
			pokemonList.push_back(aerodactyl);
			pokemonList.push_back(snorlax);
		}
	}

	if (multiplayer == true && pkm == 0) {
		pokemonList.push_back(venusaur);
		pokemonList.push_back(blastoise);
		pokemonList.push_back(charizard);
		pokemonList.push_back(butterfree);
		pokemonList.push_back(beedrill);
		pokemonList.push_back(pidgeot);
		pokemonList.push_back(raticate);
		pokemonList.push_back(arbok);
		pokemonList.push_back(raichu);
		pokemonList.push_back(sandslash);
		pokemonList.push_back(nidoking);
		pokemonList.push_back(clefable);
		pokemonList.push_back(arcanine);
		pokemonList.push_back(poliwrath);
		pokemonList.push_back(alakazam);
		pokemonList.push_back(machamp);
		pokemonList.push_back(tentacruel);
		pokemonList.push_back(golem);
		pokemonList.push_back(magneton);
		pokemonList.push_back(gengar);
		pokemonList.push_back(onix);
		pokemonList.push_back(exeggutor);
		pokemonList.push_back(weezing);
		pokemonList.push_back(scyther);
		pokemonList.push_back(jynx);
		pokemonList.push_back(gyarados);
		pokemonList.push_back(lapras);
		pokemonList.push_back(aerodactyl);
		pokemonList.push_back(snorlax);
		pokemonList.push_back(articuno);
		pokemonList.push_back(zapdos);
		pokemonList.push_back(moltres);
		pokemonList.push_back(dragonite);
		pokemonList.push_back(mewtwo);
		pokemonList.push_back(ampharos);

		pkm = 1;
		num = 1;
	}

	bool poke = false;
	bool duplicate = false;

	for (int i = 0; i < num; i++) {
		poke = false;
		duplicate = false;

		system("CLS");

		int tempCount = 0;

		for (int i = 0; i < pokemonList.size(); i++) {
			std::cout << formater((pokemonList[i].num + ". " + pokemonList[i].name), 20);
			tempCount += 1;
			if (tempCount % 4 == 0 || i == pokemonList.size() - 1) {
				std::cout << "\n";
			}
		}

		std::cout << "Current Team: " << std::endl;
		for (int i = 0; i < player.size(); i++)
			std::cout << player[i].name << std::endl;

		std::cout << "Choose a pokemon: ";
		std::cin >> name;

		if (name.length() > 2) {
			for (int i = 0; i < name.length(); i++) {
				name[i] |= 32; //Changes each character of the string to lower case
			}
			name[0] ^= 32; //Changes the first character in the string to upper case
		}

		for (int x = 0; x < pokemonList.size(); x++) {
			if (name == pokemonList[x].name || name == pokemonList[x].num) {
				if (player.size() == 0) {
					player.push_back(Pokemon(pokemonList[x]));

					poke = true;
				}
				else {
					for (int f = 0; f < player.size(); f++) {
						if (name == player[f].name || name == player[f].num) {
							duplicate = true;
						}
					}
					if (duplicate == false)
					{
						player.push_back(Pokemon(pokemonList[x]));
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

void printChooseMPokemon(std::vector<Pokemon> &player, std::vector<Pokemon> &player2, std::string pName) {
	std::string name;

	PlaySound(TEXT(NULL), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	if (pkm == 0) {
		pokemonList.push_back(venusaur);
		pokemonList.push_back(charizard);
		pokemonList.push_back(blastoise);
		pokemonList.push_back(butterfree);
		pokemonList.push_back(beedrill);
		pokemonList.push_back(pidgeot);
		pokemonList.push_back(raticate);
		pokemonList.push_back(arbok);
		pokemonList.push_back(raichu);
		pokemonList.push_back(sandslash);
		pokemonList.push_back(nidoking);
		pokemonList.push_back(clefable);
		pokemonList.push_back(arcanine);
		pokemonList.push_back(poliwrath);
		pokemonList.push_back(alakazam);
		pokemonList.push_back(machamp);
		pokemonList.push_back(tentacruel);
		pokemonList.push_back(golem);
		pokemonList.push_back(magneton);
		pokemonList.push_back(gengar);
		pokemonList.push_back(onix);
		pokemonList.push_back(exeggutor);
		pokemonList.push_back(weezing);
		pokemonList.push_back(scyther);
		pokemonList.push_back(jynx);
		pokemonList.push_back(gyarados);
		pokemonList.push_back(lapras);
		pokemonList.push_back(aerodactyl);
		pokemonList.push_back(snorlax);
		pokemonList.push_back(articuno);
		pokemonList.push_back(zapdos);
		pokemonList.push_back(moltres);
		pokemonList.push_back(dragonite);
		pokemonList.push_back(mewtwo);
		pokemonList.push_back(ampharos);

		pkm = 1;
	}

	num = 1;

	bool poke = false;
	bool duplicate = false;

	for (int i = 0; i < num; i++) {
		poke = false;
		duplicate = false;

		system("CLS");

		int tempCount = 0;

		for (int i = 0; i < pokemonList.size(); i++) {
			std::cout << formater((pokemonList[i].num + ". " + pokemonList[i].name), 20);
			tempCount += 1;
			if (tempCount % 4 == 0 || i == pokemonList.size() - 1) {
				std::cout << "\n";
			}
		}

		std::cout << pName << "'s Current Team: " << std::endl;
		for (int i = 0; i < player.size(); i++)
			std::cout << player[i].name << std::endl;

		std::cout << "Choose a pokemon: ";
		std::cin >> name;

		if (name.length() > 2) {
			for (int i = 0; i < name.length(); i++) {
				name[i] |= 32; //Changes each character of the string to lower case
			}
			name[0] ^= 32; //Changes the first character in the string to upper case
		}

		for (int x = 0; x < pokemonList.size(); x++) {
			if (name == pokemonList[x].name || name == pokemonList[x].num) {
				player.push_back(Pokemon(pokemonList[x]));
				pokemonList.erase(pokemonList.begin() + x);
				poke = true;
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
	bool worked = false;
	while (worked == false) {
		if (moveChoice == 1) {
			if (one.move1.getPP() > 0) {
				std::cout << one.name << " used " << one.move1.name << "!" << std::endl;
				one.useMove(one.move1, two);
				one.move1.setPP(one.move1.getPP() - 1);
				worked = true;
			}
			else {
				std::cout << "|============================|" << std::endl;
				std::cout << formater(("| 1. " + one.move1.name + " " + to_string(one.move1.getPP()) + "/" + to_string(one.move1.maxPP)), 29) << "|" << std::endl;
				std::cout << formater(("| 2. " + one.move2.name + " " + to_string(one.move2.getPP()) + "/" + to_string(one.move2.maxPP)), 29) << "|" << std::endl;
				std::cout << formater(("| 3. " + one.move3.name + " " + to_string(one.move3.getPP()) + "/" + to_string(one.move3.maxPP)), 29) << "|" << std::endl;
				std::cout << formater(("| 4. " + one.move4.name + " " + to_string(one.move4.getPP()) + "/" + to_string(one.move4.maxPP)), 29) << "|" << std::endl;
				std::cout << "|============================|" << std::endl;
				std::cout << "What will " << one.name << " do?" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cin >> moveChoice;
			}
		}
		else if (moveChoice == 2) {
			if (one.move2.getPP() > 0) {
				std::cout << one.name << " used " << one.move2.name << "!" << std::endl;
				one.useMove(one.move2, two);
				one.move2.setPP(one.move2.getPP() - 1);
				worked = true;
			}
			else {
				std::cout << "|============================|" << std::endl;
				std::cout << formater(("| 1. " + one.move1.name + " " + to_string(one.move1.getPP()) + "/" + to_string(one.move1.maxPP)), 29) << "|" << std::endl;
				std::cout << formater(("| 2. " + one.move2.name + " " + to_string(one.move2.getPP()) + "/" + to_string(one.move2.maxPP)), 29) << "|" << std::endl;
				std::cout << formater(("| 3. " + one.move3.name + " " + to_string(one.move3.getPP()) + "/" + to_string(one.move3.maxPP)), 29) << "|" << std::endl;
				std::cout << formater(("| 4. " + one.move4.name + " " + to_string(one.move4.getPP()) + "/" + to_string(one.move4.maxPP)), 29) << "|" << std::endl;
				std::cout << "|============================|" << std::endl;
				std::cout << "What will " << one.name << " do?" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cin >> moveChoice;
			}
		}
		else if (moveChoice == 3) {
			if (one.move3.getPP() > 0) {
				std::cout << one.name << " used " << one.move3.name << "!" << std::endl;
				one.useMove(one.move3, two);
				one.move3.setPP(one.move3.getPP() - 1);
				worked = true;
			}
			else {
				std::cout << "|============================|" << std::endl;
				std::cout << formater(("| 1. " + one.move1.name + " " + to_string(one.move1.getPP()) + "/" + to_string(one.move1.maxPP)), 29) << "|" << std::endl;
				std::cout << formater(("| 2. " + one.move2.name + " " + to_string(one.move2.getPP()) + "/" + to_string(one.move2.maxPP)), 29) << "|" << std::endl;
				std::cout << formater(("| 3. " + one.move3.name + " " + to_string(one.move3.getPP()) + "/" + to_string(one.move3.maxPP)), 29) << "|" << std::endl;
				std::cout << formater(("| 4. " + one.move4.name + " " + to_string(one.move4.getPP()) + "/" + to_string(one.move4.maxPP)), 29) << "|" << std::endl;
				std::cout << "|============================|" << std::endl;
				std::cout << "What will " << one.name << " do?" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cin >> moveChoice;
			}
		}
		else if (moveChoice == 4) {
			if (one.move4.getPP() > 0) {
				std::cout << one.name << " used " << one.move4.name << "!" << std::endl;
				one.useMove(one.move4, two);
				one.move4.setPP(one.move4.getPP() - 1);
				worked = true;
			}
			else {
				std::cout << "|============================|" << std::endl;
				std::cout << formater(("| 1. " + one.move1.name + " " + to_string(one.move1.getPP()) + "/" + to_string(one.move1.maxPP)), 29) << "|" << std::endl;
				std::cout << formater(("| 2. " + one.move2.name + " " + to_string(one.move2.getPP()) + "/" + to_string(one.move2.maxPP)), 29) << "|" << std::endl;
				std::cout << formater(("| 3. " + one.move3.name + " " + to_string(one.move3.getPP()) + "/" + to_string(one.move3.maxPP)), 29) << "|" << std::endl;
				std::cout << formater(("| 4. " + one.move4.name + " " + to_string(one.move4.getPP()) + "/" + to_string(one.move4.maxPP)), 29) << "|" << std::endl;
				std::cout << "|============================|" << std::endl;
				std::cout << "What will " << one.name << " do?" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cin >> moveChoice;
			}
		}
	}
}

void choosePokemon(int &currentPokemon, std::vector<Pokemon> &player) {
	int tempCount = 0;
	bool poke = false;
	std::string name;

	while (poke == false) {
		system("CLS");
		for (int i = 0; i < player.size(); i++) {
			display pokemon(player[i].name, player[i].stat.HP, player[i].stat.IHP);

			pokemon.printPokemon();

			tempCount += 1;
			if (tempCount % 1 == 0 || i == player.size() - 1) {
				std::cout << "\n";
			}
		}

		std::cout << "Choose a pokemon: ";
		std::cin >> name;

		if (name.length() > 2) {
			for (int i = 0; i < name.length(); i++) {
				name[i] |= 32; //Changes each character of the string to lower case
			}
			name[0] ^= 32; //Changes the first character in the string to upper case
		}

		for (int x = 1; x < player.size() + 1; x++) {
			if ((name == player[x - 1].name || name == std::to_string(x)) && player[x - 1].stat.getHP() > 0) {
				player[currentPokemon].resetStages();
				currentPokemon = x - 1;
				std::cout << "Player has sent out " << player[currentPokemon].name << "!" << std::endl;
				poke = true;
				break;
			}
		}
		if (poke == false) {
			std::cout << "\a";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
	}
	system("CLS");
}

void faint(int &currentPokemon, int &opponentCurrent, std::vector<Pokemon> &player, std::vector<Pokemon> &trainer) {
	if (currentPokemon < player.size() && player[currentPokemon].stat.HP <= 0) {
		std::cout << player[currentPokemon].name << " has fainted!" << std::endl;
		player[currentPokemon].stat.setHP(0);
		int count = 0;
		for (int f = 0; f < player.size(); f++) {
			if (player[f].stat.getHP() <= 0) {
				count++;
			}
		}

		if (count >= player.size()) {
			std::cout << "Player has sent out " << player[currentPokemon].name << "!" << std::endl;
		}
	}
	if (opponentCurrent < trainer.size() && trainer[opponentCurrent].stat.HP <= 0) {
		std::cout << trainer[opponentCurrent].name << " has fainted!" << std::endl;
		trainer[opponentCurrent].stat.setHP(0);
		opponentCurrent++;
		if (opponentCurrent < trainer.size()) {
			std::cout << "Trainer has sent out " << trainer[opponentCurrent].name << "!" << std::endl;
		}
	}
}

void faintM(int &currentPokemon, int &opponentCurrent, std::vector<Pokemon> &player, std::vector<Pokemon> &trainer) {
	if (currentPokemon < player.size() && player[currentPokemon].stat.HP <= 0) {
		std::cout << player[currentPokemon].name << " has fainted!" << std::endl;
		player[currentPokemon].stat.setHP(0);
		int count = 0;
		for (int f = 0; f < player.size(); f++) {
			if (player[f].stat.getHP() <= 0) {
				count++;
			}
		}

		if (count >= player.size()) {
			std::cout << "Player has sent out " << player[currentPokemon].name << "!" << std::endl;
		}
	}
	if (opponentCurrent < trainer.size() && trainer[opponentCurrent].stat.HP <= 0) {
		std::cout << trainer[opponentCurrent].name << " has fainted!" << std::endl;
		trainer[opponentCurrent].stat.setHP(0);
		if (opponentCurrent < trainer.size()) {
			std::cout << "Trainer has sent out " << trainer[opponentCurrent].name << "!" << std::endl;
		}
	}
}

void oppMove(int &currentPokemon, int &opponentCurrent, std::vector<Pokemon> &trainer, std::vector<Pokemon> &player) {
	int oppMoveChoice = rand() % 4 + 1;

	trainer[opponentCurrent].changeMod(trainer[opponentCurrent].spdStage, trainer[opponentCurrent].spdMod);
	useTheMove(oppMoveChoice, trainer[opponentCurrent], player[currentPokemon]);
	faint(currentPokemon, opponentCurrent, player, trainer);

	if (opponentCurrent < trainer.size() && currentPokemon < player.size()) {
		display battleScreen(player[currentPokemon], trainer[opponentCurrent]);
		battleScreen.updateHP();
		battleScreen.printScreen();
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

	std::cout << "Press any key to continue...\n";
	std::cin.ignore();
	std::cin.get();
}

void oppMMove(int &currentPokemon, int &opponentCurrent, std::vector<Pokemon> &trainer, std::vector<Pokemon> &player, int moveChoice) {

	trainer[opponentCurrent].changeMod(trainer[opponentCurrent].spdStage, trainer[opponentCurrent].spdMod);
	useTheMove(moveChoice, trainer[opponentCurrent], player[currentPokemon]);
	faint(currentPokemon, opponentCurrent, player, trainer);

	if (opponentCurrent < trainer.size() && currentPokemon < player.size()) {
		display battleScreen(player[currentPokemon], trainer[opponentCurrent]);
		battleScreen.updateHP();
		battleScreen.printScreen();
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

	std::cout << "Press any key to continue...\n";
	std::cin.ignore();
	std::cin.get();
}

void selectMove(int &currentPokemon, int &opponentCurrent, std::vector<Pokemon> &player, std::vector<Pokemon> &trainer) {
	int moveChoice = 0;
	int oppMoveChoice = 0;
	bool p1first = false;
	bool tfirst = false;
	player[currentPokemon].flinched = false;
	trainer[opponentCurrent].flinched = false;
	if (currentPokemon < player.size()) {

	while (moveChoice != 1 && moveChoice != 2 && moveChoice != 3 && moveChoice != 4) {

		std::cout << "|============================|" << std::endl;
		std::cout << formater(("| 1. " + player[currentPokemon].move1.name + " " + to_string(player[currentPokemon].move1.getPP()) + "/" + to_string(player[currentPokemon].move1.maxPP)), 29) << "|" << std::endl;
		std::cout << formater(("| 2. " + player[currentPokemon].move2.name + " " + to_string(player[currentPokemon].move2.getPP()) + "/" + to_string(player[currentPokemon].move2.maxPP)), 29) << "|" << std::endl;
		std::cout << formater(("| 3. " + player[currentPokemon].move3.name + " " + to_string(player[currentPokemon].move3.getPP()) + "/" + to_string(player[currentPokemon].move3.maxPP)), 29) << "|" << std::endl;
		std::cout << formater(("| 4. " + player[currentPokemon].move4.name + " " + to_string(player[currentPokemon].move4.getPP()) + "/" + to_string(player[currentPokemon].move4.maxPP)), 29) << "|" << std::endl;
		std::cout << "|============================|" << std::endl;
		std::cout << "What will " << player[currentPokemon].name << " do?" << std::endl;
		std::cin >> moveChoice;

		if (moveChoice != 1 && moveChoice != 2 && moveChoice != 3 && moveChoice != 4) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			system("CLS");
		}
	}

	system("CLS");

		oppMoveChoice = rand() % 4 + 1;

		player[currentPokemon].changeMod(player[currentPokemon].spdStage, player[currentPokemon].spdMod);
		trainer[opponentCurrent].changeMod(trainer[opponentCurrent].spdStage, trainer[opponentCurrent].spdMod);

		if ((player[currentPokemon].move1.name == quickattack.name && moveChoice == 1) || (player[currentPokemon].move4.name == extremespeed.name && moveChoice == 4)) {
			p1first = true;
		}

		if ((trainer[opponentCurrent].move1.name == quickattack.name && moveChoice == 1) || (trainer[opponentCurrent].move4.name == extremespeed.name && moveChoice == 4)) {
			tfirst = true;
		}

		if ((player[currentPokemon].stat.SPD * player[currentPokemon].spdMod > trainer[opponentCurrent].stat.SPD * trainer[opponentCurrent].spdMod || p1first == true) && tfirst == false) {
			int temp = opponentCurrent;
			int temp2 = currentPokemon;

			if (player[currentPokemon].flinched == true)
				player[currentPokemon].flinched == false;


			useTheMove(moveChoice, player[currentPokemon], trainer[opponentCurrent]);


			faint(currentPokemon, opponentCurrent, player, trainer);

			if (opponentCurrent == temp && currentPokemon == temp2) {

				useTheMove(oppMoveChoice, trainer[opponentCurrent], player[currentPokemon]);

			}
		}
		else {
			int temp = opponentCurrent;
			int temp2 = currentPokemon;

			if (trainer[opponentCurrent].flinched == true)
				trainer[opponentCurrent].flinched == false;

			useTheMove(oppMoveChoice, trainer[opponentCurrent], player[currentPokemon]);

			faint(currentPokemon, opponentCurrent, player, trainer);

			if (opponentCurrent == temp && currentPokemon == temp2) {

				useTheMove(moveChoice, player[currentPokemon], trainer[opponentCurrent]);
			}
		}

		faint(currentPokemon, opponentCurrent, player, trainer);

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

		if (player[currentPokemon].stat.getHP() <= 0 && player.size() > count && trainer.size() > count2) {
			choosePokemon(currentPokemon, player);
		}

		if (opponentCurrent < trainer.size() && currentPokemon < player.size()) {
			display battleScreen(player[currentPokemon], trainer[opponentCurrent]);
			battleScreen.updateHP();
			battleScreen.printScreen();
		}

		if (count >= player.size()) {
			p1Alive = false;
		}
		if (count2 >= trainer.size()) {
			trainerAlive = false;
		}
	}
	if (p1Alive == true && trainerAlive == true) {
		std::cout << "Press any key to continue...\n";
		std::cin.ignore();
		std::cin.get();
	}
}

void startBattle(std::vector<Pokemon> player, std::vector<Pokemon> trainer) {
	int currentPokemon = 0, opponentCurrent = 0;
	int choice = 0;
	while (p1Alive == true && trainerAlive == true) {
		PlaySound(TEXT("red.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		std::cout << "Press any key to continue...\n";
		std::cin.ignore();
		std::cin.get();

		while (choice != 1 || choice != 2 && p1Alive == true && trainerAlive == true) {
			system("CLS");
			display battleScreen(player[currentPokemon], trainer[opponentCurrent]);
			battleScreen.updateHP();
			battleScreen.printScreen();

			std::cout << "1. Move \n2. Pokemon" << std::endl;
			std::cin >> choice;

			if (choice == 1) {
				system("CLS");
				selectMove(currentPokemon, opponentCurrent, player, trainer);
			}
			if (choice == 2) {
				system("CLS");
				choosePokemon(currentPokemon, player);
				std::cout << "Player 1 sent out " << player[currentPokemon].name << "!\n";
				oppMove(currentPokemon, opponentCurrent, trainer, player);
				//Pokemon screen
			}
			else {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
	}
}

void selectMMove(int &currentPokemon, int &currentPokemon2, std::vector<Pokemon> &player, std::vector<Pokemon> &player2, int moveChoice, int moveChoice2) {
	bool p1first = false;
	bool p2first = false;
	player[currentPokemon].flinched = false;
	player2[currentPokemon2].flinched = false;
	if (currentPokemon < player.size()) {

		player[currentPokemon].changeMod(player[currentPokemon].spdStage, player[currentPokemon].spdMod);
		player2[currentPokemon2].changeMod(player2[currentPokemon2].spdStage, player2[currentPokemon].spdMod);

		if ((player[currentPokemon].move1.name == quickattack.name && moveChoice == 1) || (player[currentPokemon].move4.name == extremespeed.name && moveChoice == 4)) {
			p1first = true;
		}

		if ((player2[currentPokemon2].move1.name == quickattack.name && moveChoice == 1) || (player2[currentPokemon2].move4.name == extremespeed.name && moveChoice == 4)) {
			p2first = true;
		}

		if ((player[currentPokemon].stat.SPD * player[currentPokemon].spdMod > player2[currentPokemon2].stat.SPD * player2[currentPokemon2].spdMod || p1first == true) && p2first == false) {
			int temp = currentPokemon2;
			int temp2 = currentPokemon;

			if (player[currentPokemon].flinched == true)
				player[currentPokemon].flinched == false;


			useTheMove(moveChoice, player[currentPokemon], player2[currentPokemon2]);


			faintM(currentPokemon, currentPokemon2, player, player2);

			if (currentPokemon2 == temp && currentPokemon == temp2) {

				useTheMove(moveChoice2, player2[currentPokemon2], player[currentPokemon]);

			}
		}
		else {
			int temp = currentPokemon;
			int temp2 = currentPokemon;

			if (player2[currentPokemon2].flinched == true)
				player2[currentPokemon2].flinched == false;

			useTheMove(moveChoice2, player2[currentPokemon2], player[currentPokemon]);

			faintM(currentPokemon, currentPokemon2, player, player2);

			if (currentPokemon == temp && currentPokemon == temp2) {

				useTheMove(moveChoice, player[currentPokemon], player2[currentPokemon2]);
			}
		}

		faintM(currentPokemon, currentPokemon2, player, player2);

		int count = 0;
		int count2 = 0;

		for (int f = 0; f < player.size(); f++) {
			if (player[f].stat.getHP() <= 0) {
				count++;
			}
		}

		for (int f = 0; f < player2.size(); f++) {
			if (player2[f].stat.getHP() <= 0) {
				count2++;
			}
		}

		if (player[currentPokemon].stat.getHP() <= 0 && player.size() > count && player2.size() > count2) {
			choosePokemon(currentPokemon, player);
		}

		if (player2[currentPokemon2].stat.getHP() <= 0 && player.size() > count && player2.size() > count2) {
			choosePokemon(currentPokemon2, player2);
		}

		if (currentPokemon2 < player2.size() && currentPokemon < player.size()) {
			display battleScreen(player[currentPokemon], player2[currentPokemon2]);
			battleScreen.updateHP();
			battleScreen.printScreen();
		}

		if (count >= player.size()) {
			p1Alive = false;
		}
		if (count2 >= player2.size()) {
			p2Alive = false;
		}
	}
	if (p1Alive == true && p2Alive == true) {
		std::cout << "Press any key to continue...\n";
		std::cin.ignore();
		std::cin.get();
	}
}

void startMBattle(std::vector<Pokemon> &player1, std::vector<Pokemon> &player2) {
	int currentPokemon = 0, opponentCurrent = 0;
	int choice = 0, choice2 = 0;
	int moveChoice = 0, moveChoice2 = 0;
	PlaySound(TEXT("red.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	while (p1Alive == true && p2Alive == true) {
		choice = 0;
		choice2 = 0;
		while (choice != 1 && choice != 2 && p1Alive == true && p2Alive == true) {
			system("CLS");
			display battleScreen(player1[currentPokemon], player2[opponentCurrent]);
			battleScreen.updateHP();
			battleScreen.printScreen();

			std::cout << "Player1:\n1. Move \n2. Pokemon" << std::endl;
			std::cin >> choice;

			if (choice == 1) {
				system("CLS");
				moveChoice = 0;
				while (moveChoice != 1 && moveChoice != 2 && moveChoice != 3 && moveChoice != 4) {

					std::cout << "|============================|" << std::endl;
					//std::cout << formater(("| Player 1"), 29) << "|" << std::endl;
					std::cout << formater(("| 1. " + player1[currentPokemon].move1.name + " " + to_string(player1[currentPokemon].move1.getPP()) + "/" + to_string(player1[currentPokemon].move1.maxPP)), 29) << "|" << std::endl;
					std::cout << formater(("| 2. " + player1[currentPokemon].move2.name + " " + to_string(player1[currentPokemon].move2.getPP()) + "/" + to_string(player1[currentPokemon].move2.maxPP)), 29) << "|" << std::endl;
					std::cout << formater(("| 3. " + player1[currentPokemon].move3.name + " " + to_string(player1[currentPokemon].move3.getPP()) + "/" + to_string(player1[currentPokemon].move3.maxPP)), 29) << "|" << std::endl;
					std::cout << formater(("| 4. " + player1[currentPokemon].move4.name + " " + to_string(player1[currentPokemon].move4.getPP()) + "/" + to_string(player1[currentPokemon].move4.maxPP)), 29) << "|" << std::endl;
					std::cout << "|============================|" << std::endl;
					std::cout << "What will " << player1[currentPokemon].name << " do?" << std::endl;
					std::cin >> moveChoice;

					if (moveChoice != 1 && moveChoice != 2 && moveChoice != 3 && moveChoice != 4) {
						std::cin.clear();
						std::cin.ignore(INT_MAX, '\n');
						system("CLS");
					}
				}
			}
			else if (choice == 2) {
				system("CLS");
				choosePokemon(currentPokemon, player1);
				std::cout << "Player 1 sent out " << player1[currentPokemon].name << "!\n";
				//oppMMove(currentPokemon, opponentCurrent, player2, player1);
				//Pokemon screen
			}
			else {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		}
		while (choice2 != 1 && choice2 != 2 && p1Alive == true && p2Alive == true) {
			system("CLS");
			display battleScreen(player1[currentPokemon], player2[opponentCurrent]);
			battleScreen.updateHP();
			battleScreen.printScreen();

			std::cout << "Player2:\n1. Move \n2. Pokemon" << std::endl;
			std::cin >> choice2;

			if (choice2 == 1) {
				system("CLS");
				moveChoice2 = 0;
				while (moveChoice2 != 1 && moveChoice2 != 2 && moveChoice2 != 3 && moveChoice2 != 4) {
					std::cout << "|============================|" << std::endl;
					//std::cout << formater(("| Player 2"), 29) << "|" << std::endl;
					std::cout << formater(("| 1. " + player2[opponentCurrent].move1.name + " " + to_string(player2[opponentCurrent].move1.getPP()) + "/" + to_string(player2[opponentCurrent].move1.maxPP)), 29) << "|" << std::endl;
					std::cout << formater(("| 2. " + player2[opponentCurrent].move2.name + " " + to_string(player2[opponentCurrent].move2.getPP()) + "/" + to_string(player2[opponentCurrent].move2.maxPP)), 29) << "|" << std::endl;
					std::cout << formater(("| 3. " + player2[opponentCurrent].move3.name + " " + to_string(player2[opponentCurrent].move3.getPP()) + "/" + to_string(player2[opponentCurrent].move3.maxPP)), 29) << "|" << std::endl;
					std::cout << formater(("| 4. " + player2[opponentCurrent].move4.name + " " + to_string(player2[opponentCurrent].move4.getPP()) + "/" + to_string(player2[opponentCurrent].move4.maxPP)), 29) << "|" << std::endl;
					std::cout << "|============================|" << std::endl;
					std::cout << "What will " << player2[opponentCurrent].name << " do?" << std::endl;
					std::cin >> moveChoice2;

					if (moveChoice2 != 1 && moveChoice2 != 2 && moveChoice2 != 3 && moveChoice2 != 4) {
						std::cin.clear();
						std::cin.ignore(INT_MAX, '\n');
						system("CLS");
					}
				}
			}

			else if (choice2 == 2) {
				system("CLS");
				choosePokemon(opponentCurrent, player2);
				std::cout << "Player 2 sent out " << player2[currentPokemon].name << "!\n";
				//oppMMove(currentPokemon, opponentCurrent, player2, player1);
				//Pokemon screen
			}
			else {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
			system("CLS");
		}

		if (choice != 2 && choice2 != 2) {
			selectMMove(currentPokemon, opponentCurrent, player1, player2, moveChoice, moveChoice2);
		}
		if (choice == 2 && choice2 != 2) {
			oppMMove(currentPokemon, opponentCurrent, player2, player1, moveChoice2);
		}
		if (choice != 2 && choice2 == 2) {
			oppMMove(opponentCurrent, currentPokemon, player1, player2, moveChoice);
		}
	}
}

void endBattle() {
	p1Alive = true;
	p2Alive = true;
	trainerAlive = true;
}

int main() {
	srand(time(NULL)); //Random seed

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1000, 650, TRUE); // set console exactly 38 lines in height

	while (1) { //Game loop
		system("CLS");

		printScreen();

		while(story == true) {
			std::vector<Pokemon> player1;

			if (p1Alive == true) {
				if (stage == 1) {
					//Stage 1
					num = 3;
					printChoosePokemon(player1);

					std::vector<Pokemon> trainer;

					trainerName = "Youngster Jiminy";
					trainer.push_back(raticate);
					trainer.push_back(sandslash);
					trainer.push_back(venusaur);

					startBattle(player1, trainer);

					if (p1Alive == true) {
						PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
						std::cout << "Jiminy: 'How did this happen!?'" << std::endl;
						std::cout << "You defeated " << trainerName << ". Congratulations!" << std::endl;
						std::cout << "You unlocked some new Pokemon: | 1. Venusaur | 7. Raticate | 10. Sandslash |" << std::endl;
						stage++;
						endBattle();
					}
					else {
						system("CLS");
						std::cout << "You were defeated by " << trainerName << "!" << std::endl;
					}
					player1.clear();
				}
				else if (stage == 2) {
					//Stage 2
					num = 3;
					printChoosePokemon(player1);

					std::vector<Pokemon> trainer2;

					trainerName = "Berry Farmer Robert";
					trainer2.push_back(blastoise);
					trainer2.push_back(tentacruel);
					trainer2.push_back(beedrill);

					startBattle(player1, trainer2);

					if (p1Alive == true) {
						PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
						std::cout << "Robert: 'You know sometimes it really be like that.'" << std::endl;
						std::cout << "You defeated " << trainerName << ". Congratulations!" << std::endl;
						std::cout << "You unlocked some new Pokemon: | 3. Blastoise | 17. Tentacruel |" << std::endl;
						stage++;
						endBattle();
					}
					else {
						system("CLS");
						std::cout << "You were defeated by " << trainerName << "!" << std::endl;
					}
					player1.clear();
				}

				else if (stage == 3) {
					//Stage 3
					num = 3;
					printChoosePokemon(player1);

					std::vector<Pokemon> trainer3;

					trainerName = "Math Teacher Myles";
					trainer3.push_back(charizard);
					trainer3.push_back(machamp);
					trainer3.push_back(nidoking);

					startBattle(player1, trainer3);

					if (p1Alive == true) {
						PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
						std::cout << "Myles: 'Really??? That shouldn't have happened... I'll need to rethink my strategy. I'll give you it though!'" << std::endl;
						std::cout << "You defeated " << trainerName << ". Congratulations!" << std::endl;
						std::cout << "You unlocked some new Pokemon: | 2. Charizard | 11. Nidoking | 16. Machamp |" << std::endl;
						stage++;
						endBattle();
					}
					else {
						system("CLS");
						std::cout << "You were defeated by " << trainerName << "!" << std::endl;
					}
					player1.clear();
				}

				else if (stage == 4) {
					//Stage 4
					num = 3;
					printChoosePokemon(player1);

					std::vector<Pokemon> trainer4;

					trainerName = "Painter Charley";
					trainer4.push_back(jynx);
					trainer4.push_back(lapras);
					trainer4.push_back(gengar);

					startBattle(player1, trainer4);

					if (p1Alive == true) {
						PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
						std::cout << "Charley: 'Oh wow! That was really fun, thanks for the match!'" << std::endl;
						std::cout << "You defeated " << trainerName << ". Congratulations!" << std::endl;
						std::cout << "You unlocked some new Pokemon: | 25. Jynx | 27 Lapras |" << std::endl;
						stage++;
						endBattle();
					}
					else {
						system("CLS");
						std::cout << "You were defeated by " << trainerName << "!" << std::endl;
					}
					player1.clear();
				}

				else if (stage == 5) {
					//Stage 5
					num = 6;
					printChoosePokemon(player1);

					std::vector<Pokemon> trainer5;

					trainerName = "No Frills Enthusiast Kennedy";
					trainer5.push_back(butterfree);
					trainer5.push_back(snorlax);
					trainer5.push_back(exeggutor);
					trainer5.push_back(magneton);
					trainer5.push_back(poliwrath);
					trainer5.push_back(clefable);

					startBattle(player1, trainer5);

					if (p1Alive == true) {
						PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
						std::cout << "Kennedy: 'NO WAY okay good job.'" << std::endl;
						std::cout << "You defeated " << trainerName << ". Congratulations!" << std::endl;
						std::cout << "You unlocked some new Pokemon: | 12. Clefable | 14. Poliwrath | 19. Magneton | 22. Exeguutor | 29. Snorlax |" << std::endl;
						stage++;
						endBattle();
					}
					else {
						system("CLS");
						std::cout << "You were defeated by " << trainerName << "!" << std::endl;
					}
					player1.clear();
				}

				else if (stage == 6) {
					//Stage 6
					num = 6;
					printChoosePokemon(player1);

					std::vector<Pokemon> trainer6;

					trainerName = "Queen Ryan";
					trainer6.push_back(arbok);
					trainer6.push_back(exeggutor);
					trainer6.push_back(tentacruel);
					trainer6.push_back(golem);
					trainer6.push_back(alakazam);
					trainer6.push_back(weezing);

					startBattle(player1, trainer6);

					if (p1Alive == true) {
						PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
						std::cout << "Ryan: 'Oh dear, that was certainly unexpected. You played beautifully, good job!'" << std::endl;
						std::cout << "You defeated " << trainerName << ". Congratulations!" << std::endl;
						std::cout << "You unlocked some new Pokemon: | 18. Golem | 23. Weezing |" << std::endl;
						stage++;
						endBattle();
					}
					else {
						system("CLS");
						std::cout << "You were defeated by " << trainerName << "!" << std::endl;
					}
					player1.clear();
				}

				else if (stage == 7) {
					//Stage 7
					num = 6;
					printChoosePokemon(player1);

					std::vector<Pokemon> trainer7;

					trainerName = "Bird Keeper Steph";
					trainer7.push_back(pidgeot);
					trainer7.push_back(aerodactyl);
					trainer7.push_back(gyarados);
					trainer7.push_back(arcanine);
					trainer7.push_back(scyther);
					trainer7.push_back(articuno);

					startBattle(player1, trainer7);

					if (p1Alive == true) {
						PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
						std::cout << "Steph: 'That's a big oof, my beautiful birds have been defeated!'" << std::endl;
						std::cout << "You defeated " << trainerName << ". Congratulations!" << std::endl;
						std::cout << "You unlocked some new Pokemon: | 13. Arcanine | 24. Scyther |" << std::endl;
						stage++;
						endBattle();
					}
					else {
						system("CLS");
						std::cout << "You were defeated by " << trainerName << "!" << std::endl;
					}
					player1.clear();
				}

				else if (stage == 8) {
					//Stage 8
					num = 6;
					printChoosePokemon(player1);

					std::vector<Pokemon> trainer8;

					trainerName = "Bodybuilder Cob";
					trainer8.push_back(poliwrath);
					trainer8.push_back(machamp);
					trainer8.push_back(golem);
					trainer8.push_back(onix);
					trainer8.push_back(nidoking);
					trainer8.push_back(dragonite);

					startBattle(player1, trainer8);

					if (p1Alive == true) {
						system("CLS");
						PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
						std::cout << "'Cob: Ahaha! Nice teambuilding, I'll get you next time though.'" << std::endl;
						std::cout << "You defeated " << trainerName << ". Congratulations!" << std::endl;
						std::cout << "You unlocked some new Pokemon: | 15. Alakazam | 20. Gengar | 28. Aerodactyl |" << std::endl;
						stage++;
						endBattle();
					}
					else {
						std::cout << "You were defeated by " << trainerName << "!" << std::endl;
					}
					player1.clear();
				}

				else if (stage == 9) {
					//Stage 9
					num = 6;
					printChoosePokemon(player1);

					std::vector<Pokemon> trainer9;

					trainerName = "Dark Lord Jonah";
					trainer9.push_back(venusaur);
					trainer9.push_back(moltres);
					trainer9.push_back(blastoise);
					trainer9.push_back(articuno);
					trainer9.push_back(charizard);
					trainer9.push_back(zapdos);

					startBattle(player1, trainer9);

					if (p1Alive == true) {
						PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
						std::cout << "Jonah: 'Oh, okay I'll give you it. Good luck with your next opponent.'" << std::endl;
						std::cout << "You defeated " << trainerName << ". Congratulations!" << std::endl;
						stage++;
						endBattle();
						std::cin.ignore();
						std::cin.get();
					}
					else {
						system("CLS");
						std::cout << "You were defeated by " << trainerName << "!" << std::endl;
					}
					player1.clear();
				}

				else if (stage == 10) {
					//Stage 10
					num = 6;
					printChoosePokemon(player1);

					std::vector<Pokemon> trainer10;

					trainerName = "Champion Rhyss";
					trainer10.push_back(gyarados);
					trainer10.push_back(clefable);
					trainer10.push_back(gengar);
					trainer10.push_back(dragonite);
					trainer10.push_back(mewtwo);
					trainer10.push_back(ampharos);

					startBattle(player1, trainer10);

					if (p1Alive == true) {
						PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
						std::cout << "Rhyss: 'You're now the Pokemon champion! Congratulations my friend!'" << std::endl;
						std::cout << "You defeated " << trainerName << ". You're the new Pokemon League Champion!" << std::endl;
						stage++;
						endBattle();
					}
					else {
						system("CLS");
						std::cout << "You were defeated by " << trainerName << "!" << std::endl;
					}
					player1.clear();
				}

				else if (stage == 11) {
					std::cout << "You defeated EVERYONE!";
					std::cout << "In return, you unlocked Ampharos for multiplayer mode. This was Rhyss's favourite Pokemon.";
					std::cout << "This game is dedicated to Rhyss Glenfield, our best friend.";
					story = false;
					extra = true;
				}
			}

			if(p1Alive == false){
				std::cout << "You were defeated on stage " << stage << "!\n";
				story = false;
			}
			std::cin.ignore();
			std::cin.get();
			pokemonList.clear();
		}

		while (multiplayer == true) {
			std::vector<Pokemon> player1;
			std::vector<Pokemon> player2;

			//Select Pokemon Order
			printChooseMPokemon(player1, player2, "Player 1");
			printChooseMPokemon(player2, player1, "Player 2");
			printChooseMPokemon(player2, player1, "Player 2");
			printChooseMPokemon(player1, player2, "Player 1");
			printChooseMPokemon(player1, player2, "Player 1");
			printChooseMPokemon(player2, player1, "Player 2");
			printChooseMPokemon(player2, player1, "Player 2");
			printChooseMPokemon(player1, player2, "Player 1");
			printChooseMPokemon(player1, player2, "Player 1");
			printChooseMPokemon(player2, player1, "Player 2");
			printChooseMPokemon(player2, player1, "Player 2");
			printChooseMPokemon(player1, player2, "Player 1");

			startMBattle(player1, player2);
			endBattle();

			multiplayer = false;
		}

		stage = 1;
		p1Alive = true;
		p2Alive = true;
		trainerAlive = true;
	}
}