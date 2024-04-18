#include "Runner.h"

bool Runner::initMap(string map_name){
    fstream map_file(map_name, std::ios_base::in);

    if (!map_file.is_open()){
        printf("Unable to open map file!\n");
        exit(1);
    }

    //- Read in number of cities in map
    size_t num_cities;

    map_file >> num_cities;

    //- Resize adjacency and border lists
    map.initLists(num_cities+1); //is one more so that the first is 1 not 0
    
    if (map_file.fail()){
        printf("First line needs to be number of cities!\n");
        exit(1);
    }

    map_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //- Read and store map
    for (size_t curr_city = 0; curr_city < num_cities; curr_city++){
        int temp;
        string tempS;

        size_t ID;
        map_file >> temp;
        ID = (size_t)temp;

        if (map_file.fail()){ //is a comment
            string junk;
            map_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
            curr_city--;
            continue;
        }
        string name;
        map_file >> name;
        
        CityType city_type;
        map_file >> tempS;
        switch (tempS[1]){
            case 'l': //aLlies
                city_type = ALLIES;
                break;
            case 'x': //aXis
                city_type = AXIS;
                break;
            case 's': //uSsr
                city_type = USSR;
                break;
            case 'e': //nEutral
                city_type = NEUTRAL;
                break;
            case 'a': //wAter
                city_type = WATER;
                break;
        }

        PowerType power_type;
        map_file >> tempS;
        switch (tempS[0]){ // {GREAT, HOME, MINOR, NONE}
            case 'G': //great
                power_type = GREAT;
                break;
            case 'H': //home
                power_type = HOME;
                break;
            case 'M': //minor
                power_type = MINOR;
                break;
            case 'N': //none
                power_type = NONE;
                break;
        }

        size_t population;
        map_file >> population;

        size_t muster;
        map_file >> muster;

        size_t resource;
        map_file >> resource;

        ResourceType resource_type;
        map_file >> tempS;
        switch (tempS[0]){ // {GREAT, HOME, MINOR, NONE}
            case 'N': //normal
                resource_type = NORMAL;
                break;
            case 'T': //Transatlantic
                resource_type = TRANS_ATLANTIC;
                break;
        }

        map.addCity(City{ID, name, city_type, power_type, population, muster, resource, resource_type});
    }
    //- Read and make connections
    for (size_t curr_city = 0; curr_city < num_cities; curr_city++){
        //- Get City Origin
        string name;
        map_file >> name;
        size_t idx = (size_t)atoi(name.c_str());
        if (idx == 0){ //if the name is provided than find it
            idx = map.findCity(name);
        }
        else if (idx > num_cities){ //city DNE
            printf("City ID is out of range! (max is%d but gave %d)", num_cities, atoi(name.c_str()));
            exit(1);
        }
        printf("%d\n\n", idx);

        //- Go through each connection pair [ID/NAME] and add to lists
        string connections;
        getline(map_file, connections);
        size_t start_pos = connections.find('[');
        size_t end_pos = connections.find(']');
        string city;
        string border;

        while (start_pos != string::npos){
            string pair = connections.substr(start_pos + 1, end_pos - start_pos - 1);
            std::istringstream iss(pair);
            iss >> city >> border;

            connections = connections.substr(end_pos+1);

            start_pos = connections.find('[');
            end_pos = connections.find(']');

            BorderType border_type;
            switch (border[0]){ //NA, COAST, STRAIT, MOUNTAIN, FOREST, RIVER, PLAINS, OCEAN
                case ('N'):
                    border_type = NA;
                    break;
                case ('C'):
                    border_type = COAST;
                    break;
                case ('S'):
                    border_type = STRAIT;
                    break;
                case ('M'):
                    border_type = MOUNTAIN;
                    break;
                case ('F'):
                    border_type = FOREST;
                    break;
                case ('R'):
                    border_type = RIVER;
                    break;
                case ('P'):
                    border_type = PLAINS;
                    break;
                case ('O'):
                    border_type = OCEAN;
                    break;
            }

            //- Add each pair
            size_t cityIdx = map.findCity(city);
            map.connect(idx, cityIdx, border_type);
        }

    }
    map.print();
}