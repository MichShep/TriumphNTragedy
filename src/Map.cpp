#include "Map.h"

//& City
//&^ City Handling Units

void City::removeUnit(Unit* unit){
    for(vector <Unit* >::iterator it(occupants[(size_t)unit->allegiance].begin()); it != occupants[(size_t)unit->allegiance].end(); ++it){
        if (*it == unit){
            it = occupants[(size_t)unit->allegiance].erase(it);
            country_counts[unit->nationality]--;
            num_occupants--;
            return;
        }
    }

    printf("Unit isn't in %s!", name.c_str());
    exit(1);
}

void City::addUnit(Unit* unit){
    occupants[(size_t)unit->allegiance].push_back(unit);
    num_occupants++;
}

void Map::initLists(const size_t size){
    //- Resize adjacency list
    adjacency.resize(size);
    sortedX.resize(size-1);
    sortedY.resize(size-1);
    city_masterlist.resize(size);
    for (auto& v : adjacency)
        v.resize(size);

    list_size = size-1;
}

//&^ City Getters

City* Map::getCity(const string name) const{
    return cities.at(name);
}

City* Map::getCity(const size_t id) const{
    return city_masterlist[id];
}

size_t Map::findCity(const string name) const{
    if (atoi(name.c_str()) != 0)
        return atoi(name.c_str());

    return cities.at(name)->getID();
}

City* Map::getClosestCity(const int x, const int y, const double zoom_x, const double zoom_y) const{
    City* closest;
    size_t dist = INFI;
    const int limit = 1000*zoom_x;
    for (int i = 1; i <= list_size; i++){
        size_t possible_dist = (zoom_x*city_masterlist[i]->x - x)*(zoom_x*city_masterlist[i]->x - x) + (zoom_y*city_masterlist[i]->y - y)*(zoom_y*city_masterlist[i]->y - y);
        if (possible_dist < dist && possible_dist <= limit){
            dist = possible_dist;
            closest = city_masterlist[i];
        }

    }

    return (dist == 18446744073709551615UL)? nullptr : closest;
}

//&^ City Dev tools

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

    printf("sortedX: [ ");
    for (size_t j = 0; j < list_size; j++){
        printf("%s, ", sortedX[j]->name.c_str());
    }

    printf("]\n");
    printf("sortedY: [ ");
    for (size_t j = 0; j < list_size; j++){
        printf("%s, ", sortedY[j]->name.c_str());
    }
    printf("]\n");
}

