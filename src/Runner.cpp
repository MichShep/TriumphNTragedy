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
            case 'U'+'S': //uSsr 232
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

        PopulationType population_type;
        map_file >> tempS;

        if (tempS == "Empty"){
            population_type = EMPTY;
        }
        else if (tempS == "Town"){
            population_type = TOWN;
        }
        else if (tempS == "City"){
            population_type = CITY;
        }
        else if (tempS == "CapitalCity"){
            population_type = CAPITAL_CITY;
        }
        else if (tempS == "SubCapital"){
            population_type = SUB_CAPITAL;
        }
        else if (tempS == "MainCapital"){
            population_type = MAIN_CAPITAL;
        }
        else{
            population_type = EMPTY;
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
        City* c = new City{ID, name, city_type, power_type, population_type, population, muster, resource, resource_type};
        map.addCity(c);

        int x, y;
        map_file >> x;
        map_file >> y;

        c->x = x;
        c->y = y;
        
        c->color[0] = COLOR_TABLE[city_type][0];
        c->color[1] = COLOR_TABLE[city_type][1];
        c->color[2] = COLOR_TABLE[city_type][2];

    }

    //- Read and make connections
    for (size_t curr_city = 0; curr_city < num_cities; curr_city++){
        if (map_file.eof()){ //not all cities need to have connections
            break;
        }
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
        if (city.second->ruler_type == player.getAllegiance()){ 
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

bool Runner::move(Unit* unit, const string start, const string target){
    //look for type of movement
    if (map[start]->isConflict()){ //if the starting city is in conflict then disengage
        return disengage(unit, start, target);
    }   

    //- Check if the city is within movement range
    size_t move_result = canMove(unit, start, target);
    if (move_result == SIZE_MAX){ //can't move to target
        return false;
    }

    //- If in battle than disengage
        //- Check if friendly
    
    //- Check if its neutral and needs to deploy Neutral Forces

    //- Check if its enemy and need to declare war

    //- After all checks move player in

    map[start]->removeUnit(unit);
    map[target]->addUnit(unit);
    return true;
}

bool Runner::disengage(Unit* unit, const string start, const string end){
    //TODO Add checking how many troops have gone over border
    if (canDisengage(unit, start, end)){
        map.getCity(start)->removeUnit(unit);
        map.getCity(end)->addUnit(unit);
        return true;
    }
        
    return false;
}

bool Runner::canDisengage(Unit* unit, const string start, const string end){
    //- Check if you the two are connected (0 means they aren't)
    auto city = map.getCity(end);
    return map.checkConnection(start, end) &&

    //- Check if end is friendly or open sea
    (unit->allegiance == city->ruler_type || (city->city_type == WATER && !city->isEnemy((unit->allegiance)))) && 

    //- Cant go into map with friendly units if in combat
    !city->isConflict()
    ;     
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
    size_t memo[num_city+1][5];

    //- Init each row in memo
    for (auto&v : memo){
        v[0] = INFI; v[1] = INFI; v[2] = INFI; v[3] = 0; v[4] = 0;
    }

    //- Set Starting Node
    size_t city_indx = map.findCity(start);
    memo[city_indx][0] = 0; memo[city_indx][1] = movement; memo[city_indx][2] = 0; memo[city_indx][3] = 1; memo[city_indx][4] = 1;
    
    //- Until all cities are visited
    while (num_visited != num_city){
        //printMemo(memo);
        //- Set to visited;
        num_visited++;
        memo[city_indx][4] = 1;

        if (memo[city_indx][0] == 18446744073709551615UL){ //is next to but unreachable
            continue;
        }
        //- Go thourgh each adjacent node
        for (size_t connect_id = 1; connect_id <= num_city; connect_id++){ 
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
        while (!indx_to_go.empty() && memo[indx_to_go.front()][4] == 1)
            indx_to_go.pop();
        if (indx_to_go.empty()) //smth's wrong
            continue;
        city_indx = indx_to_go.front();
        indx_to_go.pop();
    }

    //printf("Final Memo:\n");
    //printMemo(memo);
    vector<SDL_Rect*> reachable_cities;
    for (size_t i = 1; i <= num_city; i++){
        if (memo[i][0] != 18446744073709551615UL){ //able to move
            auto city = map.getCity(i);
            reachable_cities.push_back(new SDL_Rect{city->x, city->y, city->HEIGHT/2, city->WIDTH/2});

        }
    }

    //! Draw the available cities
    SDL_SetRenderDrawColor(app.renderer, 255, 255, 0, 255);


    for (auto city : reachable_cities){

        SDL_RenderFillRect(app.renderer, city);

    }

    SDL_RenderPresent(app.renderer);    

    return memo[city->getID()][0];
}

void Runner::printMemo(size_t memo[][5]) const{
    printf("\tDist\tMove\tPrev\tS\tV\n");
    for (size_t i = 1; i <= map.getNumCity(); i++){
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





//!!! Methods for combat round !!!


void Runner::combatRound(){
    //- Get all battles the player is in
    vector<City*> battles = getBattles(active_player->getAllegiance());

    //- Have player choose until all battles are dealt with (taken or passed)
    while (battles.size()){
        //- Print out the battles
        size_t i = 0;
        for (auto city : battles){ //TODO repalce so each city is highlited on map
            printf("%zu:%s ", i++, city->name.c_str());
        }
        printf("\n");

        printf("Which city to target\n"); //TODO replace with player clicking on city
        size_t target;
        cin >> target;
        printf("Skip (0) or battle (1)\n"); //TODO reaplce with player clicking the option
        bool choice;
        cin >> choice;
        if (choice){ //choose to have a battle
            if (battles[target]->city_type == WATER){
                while (seaCombat(battles[target])); //plays out until completion
            }
            else{
                landCombat(battles[target]);
                for(vector <City* >::iterator it(battles.begin()); it != battles.end(); ++it){ //TODO change to index type
                if (*it == battles[target]){
                    it = battles.erase(it);
                    break;
                } //if
            } //foe
            }

        }
        else{ //choose to skip from having a battle
            for(vector <City* >::iterator it(battles.begin()); it != battles.end(); ++it){
                if (*it == battles[target]){
                    it = battles.erase(it);
                    break;
                } //if
            } //foe
        } //else
    } //while
}

void Runner::landCombat(City* battlefield){
    //- Go through each unit
    CityType attacker = active_player->getAllegiance(); //Defender goes after attacker (the one who started the battle, i.e. the active_player)
    for (size_t i = 0; i < CONVOY; i++){ //convoys don't have CA
        printf("%zu are now acting!\n", i);
        //Attacker chooses target if enemies is greater than 1
        CityType defender;
        if (battlefield->numEnemies(attacker) > 1){
            printf("\tChoose who to target\n");
            int temp;
            cin >> temp; //TODO replace with clicking on screen
            defender = (CityType)temp;
        } 
        else{
            defender = battlefield->getEnemy(attacker);
        }

        //-Combat Action
        CityType firer;
        CityType receiver;
        int count = 0;
        while (count++ < 2){
            if (count == 1){
                firer = defender;
                receiver = attacker;
                printf("\tdefender is shooting\n");
            }
            else if (count == 2){
                firer = attacker;
                receiver = defender;
                printf("\tattcker is shooting\n");
            }
            else{
                exit(1);
            }
            
            for (Unit* unit : battlefield->occupants[firer]){
                if (unit->unit_type != (UnitType)i )
                    continue;
                
                printf("\t%zu: Retreat(0) or Fire(1)?\n", unit->id);
                bool combat_action;
                cin >> combat_action; //TODO make palyer click
                //- Retreat ->
                if (!combat_action){
                    //TODO add retreating
                    continue;
                }

                //- Fire

                //-Choose target
                UnitType target;
                int temp;
                printf("\tChoose unit to attack \n"); //FORTRESS, AIR, CARRIER, SUB, FLEET, TANK, INFANTRY, CONVOY
                cin >> temp; //TODO have player click on type
                target = (UnitType)temp;

                //-Roll #CV dices
                for (size_t k = 0; k < unit->combat_value; k++){
                    if (die.roll() <= FIREPOWER_TABLE[(size_t)unit->unit_type][(size_t)target]){
                        printf("\tHit!\n");
                        //- Highest of that type loses one CV
                        size_t maxCV;
                        Unit* victim;
                        for (Unit* potential_victim : battlefield->occupants[receiver]){
                            if (potential_victim->unit_type == target && potential_victim->combat_value > maxCV){
                                maxCV = potential_victim->combat_value;
                                victim = potential_victim;
                            }
                        }

                        victim->combat_value--;

                        //- Remove units with 0 CV
                        if(victim->combat_value == 0){
                            battlefield->removeUnit(victim);
                        }
                    }
                }
            }
        }
        
        
            





        //-Check Ground support
            //- No support then ANS retreat

            //- End

        //- ANS may ReBase
    }

    
}

bool Runner::seaCombat(City* battlefield){

    return false;
}

vector<City*> Runner::getBattles(const CityType allegiance){
    auto cities = map.getCities();

    vector<City*> battles;

    for (auto city : cities){
        if (city.second->occupants[allegiance].size() > 0 && city.second->isEnemy(active_player->getAllegiance())){
            battles.push_back(city.second);
        }
    }

    return battles;
}