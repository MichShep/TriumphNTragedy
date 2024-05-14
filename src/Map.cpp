#include "Map.h"


void City::removeUnit(Unit* unit){
    for(vector <Unit* >::iterator it(occupants[(size_t)unit->allegiance].begin()); it != occupants[(size_t)unit->allegiance].end(); ++it){
        if (*it == unit){
            it = occupants[(size_t)unit->allegiance].erase(it);
            return;
        }
    }

    printf("Unit isn't in %s!", name.c_str());
    exit(1);
}

void City::addUnit(Unit* unit){
    occupants[(size_t)unit->allegiance].push_back(unit);

    //- Check for aggresiveness 
    if (unit->allegiance != ruler_type && city_type != WATER){
        aggresor = unit->allegiance;
    }

    //- If undefended then take 
    //TODO Add conquering method

}

void City::print() const{
    printf("\tCity #%zu: %s is %d with %d pop, %d muster, %d resources of type %d\n", ID, name.c_str(), (int)city_type, (int)power_type, (int) population, (int)muster, (int)resource);
}

void City::printOccupants() const{
    printf("%s's Units: ", name.c_str());
    for (size_t nation = 0; nation < 3; nation++){
        printf("%zu:[ ", nation);
        for (auto&unit : occupants[nation]){
            printf("%d ", (int)unit->unit_type);
        }
        printf(" ] ");
    }
}


void Map::initLists(const size_t size){
    //- Resize adjacency list
    adjacency.resize(size);
    city_masterlist.resize(size);
    for (auto& v : adjacency)
        v.resize(size);
}


size_t Map::findCity(const string name) const{
    if (atoi(name.c_str()) != 0)
        return atoi(name.c_str());

    return cities.at(name)->getID();
}

City* Map::getCity(const string name) const{
    return cities.at(name);
}

City* Map::getCity(const size_t id) const{
    return city_masterlist[id];
}


void Map::connect(const size_t& idx1, const size_t& idx2, const BorderType border){
    adjacency[idx1][idx2] = border;
    adjacency[idx2][idx1] = border;
}

void Map::print() const{
    for (size_t j = 1; j < adjacency.size(); j++){
        printf("[ ");
        for (size_t i = 1; i < adjacency.size(); i++){
            printf("%d ", adjacency[j][i]);

        }
        printf("]\n");
    }
}

