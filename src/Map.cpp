#pragma once

#include "Map.h"

void Map::initLists(const size_t size){
    //- Resize adjacency list
    adjacency.resize(size);
    for (auto& v : adjacency)
        v.resize(size);
}


size_t Map::findCity(const string name) const{
    if (atoi(name.c_str()) != 0)
        return atoi(name.c_str());

    return cities.at(name).getID();
}

void Map::connect(const size_t& idx1, const size_t& idx2, const BorderType border){
    adjacency[idx1][idx2] = border;
    adjacency[idx2][idx1] = border;
}

void City::print() const{
    printf("\tCity #%zu: %s is %u with %zu pop, %zu muster, %zu resources of type %u\n", ID, name.c_str(), city_type, power_type, population, muster, resource, resource_type);
}

void Map::print() const{
    for (size_t j = 1; j < adjacency.size(); j++){
        printf("[", j);
        for (size_t i = 1; i < adjacency.size(); i++){
            printf("%d ", adjacency[j][i]);

        }
        printf("]\n");
    }
}

