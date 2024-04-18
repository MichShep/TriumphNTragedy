#include "Runner.h"

bool Runner::initMap(string map_name){
    fstream map_file(map_name, std::ios_base::in);

    if (!map_file.is_open()){
        printf("Unable to open map file!\n");
        exit(EXIT_FAILURE);
    }

    //- Read in number of cities in map
    size_t num_cities;

    map_file >> num_cities;

    //- Resize adjacency and border lists
    map.initLists(num_cities+1); //is one more so that the first is 1 not 0
    
    if (map_file.fail()){
        printf("First line needs to be number of cities!\n");
        exit(EXIT_FAILURE);
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
        switch (tempS[0]+tempS[1]){
            case 'W'+'e': //west 220
                city_type = WEST;
                break;
            case 'A'+'x': //aXis 217
                city_type = AXIS;
                break;
            case 'U'+'s': //uSsr 232
                city_type = USSR;
                break;
            case 'N'+'e': //nEutral 211
                city_type = NEUTRAL;
                break;
            case 'W'+'a': //wAter 216
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
        City* c = new City{ID, name, city_type, power_type, population, muster, resource, resource_type};
        map.addCity(c);
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
            printf("City ID is out of range! (max is%d but gave %d)", (int)num_cities, atoi(name.c_str()));
            exit(EXIT_FAILURE);
        }
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

    return true;
}

bool Runner::mapPlayer(Player& player){
    auto temp_map = map.getCities();

    size_t temp_resources = 0;
    size_t temp_population = 0;

    //- Go through each city
    for (auto& city : temp_map){
        //- If it belongs to the player
        if (city.second->ruler_type == player.getNationality()){ 
            //- Add to temp variables
            temp_resources += city.second->resource;
            temp_population += city.second->population;
            
        }
    }
    bool check = false;
    if (temp_population != player.getPopulation()){
        player.setPopulation(temp_population);
        check = true;
    }

    if (temp_resources != player.getResource()){
        player.setResource(temp_resources);
        check = true;
    }

    return check;
}

void Runner::landMovement(Unit* unit, const string name){
    //- Check if the city is within movement range
        //- If only goes through friendly than strategic movement 

    //- If in battle than disengage
        //- Check if friendly
    
    //- Check if its neutral and needs to deploy Neutral Forces

    //- Check if its enemy and need to declare war

}

//Dijkstra's algorithm knock-off
size_t Runner::canMove(Unit* unit, const string start, const string target){
    City* city = map.getCity(target);
    const vector<vector<BorderType>>& adjacency = map.getAdjacency();
    size_t movement = unit->movement*2; //assume can strategic move
    size_t num_city = map.getNumCity();
    size_t num_visited = 0;

    queue<size_t> indx_to_go; //max priority queue

    //dist movement prev madeWithStrategic visited
    size_t memo[num_city][5];

    //- Init each row in memo
    for (auto&v : memo){
        v[0] = INFI; v[1] = INFI; v[2] = INFI; v[3] = 0; v[4] = 0;
    }

    //- Set Starting Node
    size_t city_indx = map.findCity(start);
    memo[city_indx][0] = 0; memo[city_indx][1] = movement; memo[city_indx][2] = 0; memo[city_indx][3] = 1; memo[city_indx][4] = 1;
    
    //- Until all cities are visited
    while (num_visited != num_city){
        printMemo(memo);
        //- Set to visited;
        num_visited++;
        memo[city_indx][4] = 1;

        if (memo[city_indx][0] == 18446744073709551615UL){ //is next to but unreachable
            continue;
        }
        //- Go thourgh each adjacent node
        for (size_t connect_id = 1; connect_id < num_city; connect_id++){ 
            //- If not visited and connected
            if (!memo[connect_id][4] && adjacency[city_indx][connect_id] != NA){ //if the value at [city_indx][connect_id] is not 0 then that means there is a connection
                //- Add to queue
                indx_to_go.push(connect_id);
                
                //- Calculate the cost to get there
                size_t cost = 1; //distance plus 1
                size_t temp_move = memo[city_indx][1];
                bool usedStrat = memo[city_indx][3];
                if (memo[city_indx][3] && (map.getCity(connect_id)->ruler_type != map.getCity(city_indx)->ruler_type) ){ //- If can't use strategic lose it (1/2)
                    temp_move = unit->movement - (2*unit->movement-temp_move);
                    usedStrat = 0;
                }
                //-If it can make it and lower than update it
                if (temp_move >= cost && (temp_move-cost > memo[connect_id][1] || memo[connect_id][1] == 18446744073709551615UL)){ //want to prioritize movement
                    memo[connect_id][1] = temp_move-cost;
                    memo[connect_id][0] = cost;
                    memo[connect_id][2] = city_indx;
                    memo[connect_id][3] = (size_t)usedStrat;
                }
            }
        }

        //- Update city_indx to any connected edge
        while (indx_to_go.empty() || memo[indx_to_go.front()][4] == 1)
            indx_to_go.pop();
        if (indx_to_go.empty())
            return 0;
        city_indx = indx_to_go.front();
        indx_to_go.pop();
    }

    return memo[city->getID()][0] != INFI;
}

void Runner::printMemo(size_t memo[][5]) const{
    printf("\tDist\tMove\tPrev\tS\tV\n");
    for (size_t i = 1; i < map.getNumCity(); i++){
        printf("%s\t", map.getCity(i)->name.substr(0, 5).c_str());
        if (memo[i][0] == 18446744073709551615UL){
            printf("-1\t");
        }
        else{
            printf("%zu\t", memo[i][0]);
        }
        if (memo[i][1] == 18446744073709551615UL){
            printf("-1\t");
        }
        else{
            printf("%zu\t", memo[i][1]);
        }
        if (memo[i][2] == 18446744073709551615UL){
            printf("-1\t");
        }
        else{
            printf("%zu\t", memo[i][2]);
        }
        if (memo[i][3] == 18446744073709551615UL){
            printf("-1\t");
        }
        else{
            printf("%zu\t", memo[i][3]);
        }
        if (memo[i][4] == 18446744073709551615UL){
            printf("-1\t");
        }
        else{
            printf("%zu\n", memo[i][4]);
        }
    }
            printf("\n\n");
}

