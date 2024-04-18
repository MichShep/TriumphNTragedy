#pragma once

#include <iostream>
using std::cout;
using std::endl;
using std::cout;
using std::string;

#include <fstream>
using std::fstream;

#include <vector>
using std::vector;
using std::find;

#include <unordered_map> 
using std::unordered_map;

#include <cstdio>
using std::printf;

#include <sstream>


#define END_YEAR 1946;

#define START_YEAR 1936;

enum CityType {ALLIES, AXIS, USSR, NEUTRAL, WATER};

enum PowerType {GREAT, HOME, MINOR, NONE};

enum ResourceType {NORMAL, TRANS_ATLANTIC};

enum BorderType {NA, COAST, STRAIT, MOUNTAIN, FOREST, RIVER, PLAINS, OCEAN}; //NA means not connected

enum UnitClass {CLASS_A, CLASS_N, CLASS_G, CLASS_S};

enum UnitType {FORTRESS, AIR, CARRIER, SUB, FLEET, TANK, INFANTRY, CONVOY};

const int FIREPOWER_TABLE[8][4] = { // Damage against {A N G S}
    {2, 3, 4, 3}, //Fort
    {3, 1, 1, 1}, //Air
    {2, 2, 1, 2}, //Carrir
    {2, 2, 1, 2}, //Sub
    {1, 3, 1, 2}, //Fleet
    {0, 0, 2, 0}, //Tank
    {1, 1, 3, 0}, //Infantry
    {0, 0, 0, 0}  //Convoy
};