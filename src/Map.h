#pragma once

#include "Includes.h"

/**
 * @brief Each segment of the map where troops are stationed 
 * 
 */
struct City{
private:
    //#ID Name            Type    Status  Pop     Muster  Resource    ResourceType
    size_t ID;

    string name;

    CityType city_type;

    PowerType power_type;

    CityType ruler_type;

    size_t population;

    size_t muster;

    size_t resource;

    ResourceType resource_type;
public:

    City(const size_t ID=0, const string name="City", const CityType city_type=WATER, const PowerType power_type=NONE, const size_t population=0, const size_t muster=0, const size_t resource=0, const ResourceType resource_type=NORMAL):
    ID(ID), name(name), city_type(city_type), power_type(power_type), population(population), muster(muster), resource(resource), resource_type(resource_type){
        ruler_type=city_type; //set it be ruled by who starts with it
    }

    string getName() const{
        return name;
    }

    size_t getID() const{
        return ID;
    }

    /**
     * @brief Prints out all attributes of the city
     * 
     */
    void print() const;
};

class Map{
private:
    unordered_map<string, City> cities; //the total graph where the key is the name

    vector<vector<BorderType>> adjacency;

public:
    void initLists(const size_t size);

    void addCity(const City city){
        cities.insert(std::make_pair(city.getName(), city));
    }

    void connect(const size_t& idx1, const size_t& idx2, const BorderType border);

    size_t findCity(const string name) const;

    void print() const; // prints all cities

};