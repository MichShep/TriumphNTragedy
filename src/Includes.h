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


enum CityType {ALLIES, AXIS, USSR, NEUTRAL, WATER};

enum PowerType {GREAT, HOME, MINOR, NONE};

enum ResourceType {NORMAL, TRANS_ATLANTIC};

enum BorderType {NA, COAST, STRAIT, MOUNTAIN, FOREST, RIVER, PLAINS, OCEAN}; //NA means not connected