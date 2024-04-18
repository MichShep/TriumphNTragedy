#pragma once

#include "Unit.h"

/**
 * @brief Each segment of the map where troops are stationed 
 * 
 */
struct City{
public:
    //#ID Name            Type    Status  Pop     Muster  Resource    ResourceType
    size_t ID;

    string name ="";

    CityType city_type;

    PowerType power_type;

    CityType ruler_type;

    size_t population;

    size_t muster;

    size_t resource;

    ResourceType resource_type;

    vector<Unit*> occupants[3]; //holds the occupants here

    //For influence
    size_t influence;

    CityType influencer;

    void freeMemory(){
        if (name != ""){
            for (auto occ : occupants){
                for(auto un : occ)
                    delete un;
                occ.clear();
            } 
        }
    }
public:

    City(const size_t ID=0, const string name="City", const CityType city_type=WATER, const PowerType power_type=NONE, const size_t population=0, const size_t muster=0, const size_t resource=0, const ResourceType resource_type=NORMAL):
    ID(ID), name(name), city_type(city_type), power_type(power_type), population(population), muster(muster), resource(resource), resource_type(resource_type){
        ruler_type=city_type; //set it be ruled by who starts with it
        influence = 0;

    }

    string getName() const{
        return name;
    }

    size_t getID() const{
        return ID;
    }

    void removeUnit(Unit* unit);

    void addUnit(Unit* unit);

    void printOccupants() const;

    /**
     * @brief Prints out all attributes of the city
     * 
     */
    void print() const;
};

class Map{
private:
    unordered_map<string, City*> cities; //the total graph where the key is the name

    vector<City*> city_masterlist;

    vector<vector<BorderType>> adjacency;

public:
    void initLists(const size_t size);

    void addCity(City* city){
        cities.insert(std::make_pair(city->getName(), city));
        city_masterlist.insert(city_masterlist.begin()+city->getID(), city);
    }

    void connect(const size_t& idx1, const size_t& idx2, const BorderType border);

    size_t findCity(const string name) const;

    City* getCity(const string name) const;

    City* getCity(const size_t id) const;

    const size_t getNumCity() const{
        return cities.size();
    }

    const unordered_map<string, City*>& getCities() const{
        return cities;
    }

    const vector<vector<BorderType>>& getAdjacency() const{
        return adjacency;
    }

    void print() const; // prints all cities

    void freeMemory(){
        for (auto city : city_masterlist){
            if (city == nullptr)
                continue;
            city->freeMemory();
            delete city;
        }
        city_masterlist.clear();
        cities.clear();
    }

};