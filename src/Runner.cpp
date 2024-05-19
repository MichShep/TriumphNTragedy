#include "Runner.h"

bool Runner::initMap(string map_name){
    fstream map_file(map_name, std::ios_base::in);

    if (!map_file.is_open()){
        printf("Unable to open map file!\n");
        exit(EXIT_FAILURE);
    }

    //- Read in number of cities in map
    size_t num_cities, num_countries;

    map_file >> num_cities;

    map_file >> num_countries;

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
        switch (tempS[0]+tempS[1]){ // {GREAT, MAJOR, COLONIES, MINOR, NONE, SEA}
            case 'G' + 'r': //great
                power_type = GREAT;
                break;
            case 'M'+'a': //major
                power_type = MAJOR;
                break;
            case 'C'+'o': //colony
                power_type = COLONY;
                break;
            case 'M'+'i': //minor
                power_type = MINOR;
                break;
            case 'N'+'o': //none
                power_type = NONE;
                break;
            default:
                printf("Unkown powertype!\n");
                exit(1);
                break;
        }

        char naty;
        UnitCountry nationality;
        map_file >> naty;
        switch (naty)
        {
        case ('B'): //britian
            nationality = BRITIAN_U;
            break;
        case ('U'): //usa
            nationality = USA_U;
            break;
        case ('F'): //france
            nationality = FRANCE_U;
            break;
        case ('G'): //germany
            nationality = GERMANY_U;
            break;
        case ('I'): //italy
            nationality = ITALY_U;
            break;
        case ('S'): //uSsr
            nationality = USSR_U;
            break;
        case ('N'): //uSsr
            nationality = NEUTRAL_U;
            break;
        default:
            nationality = NEUTRAL_U;
            break;
        }

        PopulationType population_type;
        map_file >> tempS;

        size_t population;

        size_t muster;

        if (tempS == "Empty"){
            population_type = EMPTY;
            population = 0; muster = 0;
        }
        else if (tempS == "Town"){
            population_type = TOWN;
            population = 0; muster = 1;
        }
        else if (tempS == "City"){
            population_type = CITY;
            population = 1; muster = 2;
        }
        else if (tempS == "CapitalCity"){
            population_type = CAPITAL_CITY;
            population = 1; muster = 3;
        }
        else if (tempS == "SubCapital"){
            population_type = SUB_CAPITAL;
            population = 2; muster = 0;
        }
        else if (tempS == "MainCapital"){
            population_type = MAIN_CAPITAL;
            population = 3; muster = 0;
        }
        else{
            population_type = EMPTY;
            population = 0; muster = 0;
        }

        

        size_t resource;
        map_file >> resource;

        ResourceType resource_type;
        map_file >> tempS;
        switch (tempS[0]){ //
            case 'N': //normal
                resource_type = NORMAL;
                break;
            case 'T': //Transatlantic
                resource_type = TRANS_ATLANTIC;
                break;
        }
        City* c = new City{ID, name, city_type, power_type, population_type, nationality, population, muster, resource, resource_type};

        int x, y;
        map_file >> x;
        map_file >> y;

        c->x = x;
        c->y = y;

        map.addCity(c);
        
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

            BorderType border_type=NA;
            switch (border[0]){ //NA, OCEAN, DEEP_OCEAN, COAST, COAST_MOUNTAIN, COAST_FOREST, COAST_RIVER, COAST_PLAINS, MOUNTAIN, FOREST, RIVER, PLAINS, STRAIT
                case ('N'):
                    border_type = NA;
                    break;
                case ('O'):
                    border_type = OCEAN;
                    break;
                case ('D'):
                    border_type = DEEP_OCEAN;
                    break;
                case ('C'):{ //C..
                    switch (border[1]){
                        case 'o': //cOast
                            border_type = COAST;
                            break;
                        case ('M'): //cMount
                            border_type = COAST_MOUNTAIN;
                            break;
                        case ('F'): //cForest
                            border_type = COAST_FOREST;
                            break;
                        case ('R'): //cRiver
                            border_type = COAST_RIVER;
                            break;
                        case ('P'): //cPlain
                            border_type = COAST_PLAINS;
                            break; 
                        default:
                            break;
                        }
                    }
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
                case ('L'):
                    border_type = LAND_STRAIT;
                    break;
                case ('W'):
                    border_type = WATER_STRAIT;
                    break;
                default:
                    printf("Unkown border type");
                    exit(1);

                
            }

            //- Add each pair
            size_t cityIdx = map.findCity(city);
            map.connect(idx, cityIdx, border_type);
        }

    }
    //map.print();

    //- Add cities to certain Countries
    string country_line;
    for (size_t curr_country = 0; curr_country < num_countries; curr_country++){
        string name; //first is country name
        string capital; //second is the capital
        string city;
        map_file >> name;
        map_file >> capital;
        name.pop_back();

        //Construct incomplete country
        Country* country = new Country(curr_country, name, capital);

        country->pushback(map[capital]);

        getline(map_file, country_line);
        std::istringstream ss(country_line);
        while (ss >> city){
            country->pushback(map[city]);
        }

        map.addCountry(country);
    }

    return true;
}
bool Runner::initCards(const string invest_name, const string action_name){
    fstream invest_file(invest_name, std::ios_base::in);
    fstream action_file(action_name, std::ios_base::in);

    unordered_map<string, size_t> sprite_offsets;
    sprite_offsets["Czechoslovakia"] = 0;
    sprite_offsets["Bulgaria"] = 1;
    sprite_offsets["Rumania"] = 2;
    sprite_offsets["Austria"] = 3;
    sprite_offsets["Sweden"] = 4;
    sprite_offsets["Baltic_States"] = 4;
    sprite_offsets["Poland"] = 6;
    sprite_offsets["Hungary"] = 7;
    sprite_offsets["Greece"] = 8;
    sprite_offsets["Latin_America"] = 9;
    sprite_offsets["USA"] = 10;
    sprite_offsets["Yugoslavia"] = 11;
    sprite_offsets["Spain"] = 12;
    sprite_offsets["Finland"] = 13;
    sprite_offsets["Low_Countries"] = 14;
    sprite_offsets["Denmark"] = 15;
    sprite_offsets["Afghanistan"] = 16;
    sprite_offsets["Norway"] = 17;
    sprite_offsets["Turkey"] = 18;
    sprite_offsets["Persia"] = 19;
    sprite_offsets["Portugal"] = 20;
    sprite_offsets["Empty_Action"] = 21;

    sprite_offsets["LSTs"] = 0;
    sprite_offsets["Motorized_Infantry"] = 1;
    sprite_offsets["AirDefense_Radar"] = 9;
    sprite_offsets["Naval_Radar"] = 2;
    sprite_offsets["Rocket_Artillery"] = 3;
    sprite_offsets["Heavy_Tanks"] = 4;
    sprite_offsets["Heavy_Bombers"] = 5;
    sprite_offsets["Percision_Bombsight"] = 6;
    sprite_offsets["Spy_Ring"] = 15;
    sprite_offsets["Code_Breaker"] = 11;
    sprite_offsets["Agent"] = 12;
    sprite_offsets["Jets"] = 7;
    sprite_offsets["Double_Agent"] = 16;
    sprite_offsets["Mole"] = 13;
    sprite_offsets["1944"] = 24;
    sprite_offsets["Sonar"] = 8;
    sprite_offsets["Atomic_Research_1"] = 17;
    sprite_offsets["Industrial_Espionage"] = 0;
    sprite_offsets["Atomic_Research_2"] = 18;
    sprite_offsets["Atomic_Research_3"] = 19;
    sprite_offsets["Atomic_Research_4"] = 20;
    sprite_offsets["1938"] = 21;
    sprite_offsets["Sabotage"] = 14;
    sprite_offsets["Coup"] = 10;
    sprite_offsets["1942"] = 23;
    sprite_offsets["1940"] = 22;
    sprite_offsets["Empty_Invest"] = 29;
    

    if (!invest_file.is_open()){
        printf("Unable to open invest card file!\n");
        return false;
    }

    if (!action_file.is_open()){
        printf("Unable to open action card file!\n");
        return false;
    }

    size_t invest_size, action_size;
    invest_file >> invest_size;
    action_file >> action_size;

    for (size_t curr_card = 0; curr_card < invest_size; curr_card++){
        size_t type=0, cost=0, year=0;
        invest_file >> type;
        string tech1="Empty_Invest", tech2="Empty_Invest";
        
        if (type == 2){ //need a year
            invest_file >> year;
            tech1 = std::to_string(year);
        }
        else{
            invest_file >> tech1;
            if (type == 0)
                invest_file >> tech2;
        }

        invest_file >> cost; //all have a cost

        //InvestmentCard(const InvestType type - 1, const string tech1 - 2, const string tech2 - 3, const Tech tech - 4, const int amount - 5, const size_t year - 6): 
        invest_discard.push_back(new InvestmentCard((InvestType)type, tech1, tech2, cost, year, sprite_offsets[tech1], sprite_offsets[tech2]));
    }

    for (size_t curr_card = 0; curr_card < action_size; curr_card++){
        int type, number = 0;
        string countryA="Empty_Action", countryB="Empty_Action", seasonString="";
        Season season;
        char letter;

        action_file >> type;

        action_file >> countryA;
        if (!type){ //is !1 = 0 means a normal card then take second country
            action_file >> countryB;
        }

        action_file >> seasonString;
        switch (seasonString[1]){
        case 'u': //sUmmer
            season = SUMMER;
            break;
        case 'p': //sPring
            season = SPRING;
            break;
        case 'a': //fAll
            season = FALL;
            break;
        default:
            printf("Unkown Season!\n");
            return false;
        }

        action_file >> letter;
        action_file >> number;

        action_discard.push_back(new ActionCard((ActionType)type, countryA, countryB, season, letter, number, sprite_offsets[countryA], sprite_offsets[countryB]));
    }

    reshuffle(false);

    return true;
}


bool Runner::mapPlayer(Player& player){
    auto temp_map = map.getCities();

    size_t temp_resources = 0;
    size_t temp_population = 0;

    //- Go through each city
    for (auto& city : temp_map){
        //- If it belongs to the player
        if (city.second->ruler_type == player.getAllegiance() && !city.second->blockcade){ 
            //- Add to temp variables
            temp_resources += city.second->resource;
            temp_population += city.second->population;
            player.add(city.second);
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


bool Runner::checkTradeRoutes(Player& player, string main_capital){
    const vector<vector<BorderType>>& adjacency = map.getAdjacency();
    const size_t num_city = adjacency.size();
    vector<City*> freed_cities;
    size_t num_blockcaded = player.getNumBlockaded(); //number of cities that are blockaded and that need to be checked
    freed_cities.reserve(num_blockcaded);
    size_t check = num_blockcaded;
    size_t city_indx = map.findCity(main_capital); //starting index
    queue<size_t> indx_to_go; // priority queue can be used and not a heap since everything is unweighted

    size_t memo [map.getNumCity()+1][6]; //0: visited? 1: previous 1: previous border 3: distance 4: land segment? 5: sea segment?

    size_t VISITED=0, PREVIOUS=1, PREVIOUS_BORDER=2, DISTANCE=3, LAND=4, SEA=5, infi=INFI;
    for (size_t i = 0; i < map.getNumCity()+1; i++){ //initalize all memo entries
        memo[i][0] = false;
        memo[i][1] = infi;
        memo[i][2] = NA;
        memo[i][3] = infi;
        memo[i][4] = false;
        memo[i][5] = false;
    }

    memo[city_indx][0] = false;
    memo[city_indx][1] = 0;
    memo[city_indx][2] = NA;
    memo[city_indx][3] = 0;
    memo[city_indx][4] = false; // Set both segments to false bcause we don't know yet if it will go on a land or seas segment, so the ones connected will change these
    memo[city_indx][5] = false;

    indx_to_go.push(city_indx);

    printf("\n\n\n");

    //? (14.1) The Sea Segment can only cross Coastal Straits, Sea and Ocean borders
    //? (14.1) The Land Segment can only cross Land and Straits borders.
    // Like Dijkstras and will have the main capital find a path to all the cities it controls and runs through it until all those blockcaded is visited
    while (num_blockcaded && !indx_to_go.empty()){ //- While there are still blockaded cities to check
        city_indx = indx_to_go.front();
        indx_to_go.pop();

        //- See if has been visited since time it was added to the queue
        if (memo[city_indx][VISITED])
            continue;

        //- For straits since you can pass through it can add rival land so need to check
        if (map.getCity(city_indx)->ruler_type != player.getAllegiance() && map.getCity(city_indx)->ruler_type != NEUTRAL && map.getCity(city_indx)->ruler_type != WATER)
            continue;

        //- Set to visited
        memo[city_indx][VISITED] = true;
        printf("Now at %s\n", map.getCity(city_indx)->name.c_str());

        //- If the city visited is one blockaded it means we can visit and can decreae the count
        if (map.getCity(city_indx)->blockcade && map.getCity(city_indx)->ruler_type == player.getAllegiance()){
            printf("%s was found and connected!\n", map.getCity(city_indx)->name.c_str());
            map.getCity(city_indx)->blockcade = false;
            freed_cities.push_back(map.getCity(city_indx));
            num_blockcaded--;
        }

        //- Go thourgh each adjacent node
        for (size_t connect_indx = 1; connect_indx <= num_city; connect_indx++){  
            //- Check what border connects them
            auto& border = adjacency[city_indx][connect_indx];

            //- Check if its connected and not visited
            if (border == NA || memo[connect_indx][VISITED]){
                continue;
            }

            //- Check if there it is an enemy controlled city (in cases of straits it can only go through rivals, not enemies)
            if (border == LAND_STRAIT || border == WATER_STRAIT){ //if a strait then it can't iff its an ENEMY (not rival)
                if (player.isEnemy(map.getCity(city_indx)->ruler_type)){ //if an enemy with the strait ruler
                    continue;
                }
            }
            else{
                if (map.getCity(connect_indx)->ruler_type != player.getAllegiance() && map.getCity(connect_indx)->ruler_type != NEUTRAL && map.getCity(connect_indx)->ruler_type != WATER){ //if its a regular spot then it can;t pass through rival OR enemy
                    continue;
                }
            }

            bool unchanged_sea=true, unchanged_land=true;

            //- Basically for the first node only to set where things are
            if (memo[city_indx][PREVIOUS_BORDER] == NA){
                if (border <= WATER_STRAIT){ //- if starting sea
                    unchanged_sea=false;
                    memo[connect_indx][SEA] = true;
                    memo[connect_indx][PREVIOUS_BORDER] = border;
                }
                else if (border <= COAST_PLAINS){ //- if coastal movement could be both so ignore
                    memo[connect_indx][PREVIOUS_BORDER] = border;
                }
                else if (border >= MOUNTAIN){
                    unchanged_land = false;
                    memo[connect_indx][LAND] = true;
                    memo[connect_indx][PREVIOUS_BORDER] = border;
                }

            }

            //- CONTINUING land segment
            else if (border >= MOUNTAIN && memo[city_indx][PREVIOUS_BORDER] >= MOUNTAIN){
                memo[connect_indx][PREVIOUS_BORDER] = border;
            }
            
            //- CONTINUING sea segment
            else if (border <= WATER_STRAIT && memo[city_indx][PREVIOUS_BORDER] <= WATER_STRAIT){
                memo[connect_indx][PREVIOUS_BORDER] = border;
            }

            // - STARTING land 
            else if (border >= MOUNTAIN && memo[city_indx][PREVIOUS_BORDER] <= WATER_STRAIT){ //check that by seeing if the previous movement was a sea one
                if (!memo[city_indx][LAND]){ //if land hasn't started yet then okay!
                    memo[connect_indx][LAND] = true; //change
                    unchanged_land = false;
                    memo[connect_indx][SEA] = memo[city_indx][SEA]; //set to what the connector has
                    memo[connect_indx][PREVIOUS_BORDER] = border;
                }
                else{ //if the land segment has already started then no on
                    continue;
                }
            }

            // - Starting sea segment
            else if (border <= WATER_STRAIT && memo[city_indx][PREVIOUS_BORDER] >= MOUNTAIN){
                if (!memo[city_indx][SEA]){ //if land hasn't started yet then okay!
                    memo[connect_indx][SEA] = true;
                    unchanged_sea = false;
                    memo[connect_indx][LAND] = memo[city_indx][LAND];
                    memo[connect_indx][PREVIOUS_BORDER] = border;
                }
                else{ //if the sea segment has already started then no on
                    continue;
                }
            }
            else if (COAST_MOUNTAIN <= border){ //if its a coastal movement it could be either and won't count
                memo[connect_indx][PREVIOUS_BORDER] = border;
            }
            else{ //- It can't move to this area since it woudl start a preexisting segment!
                continue;
            }

            //- If the land and sea segmetns weren't changes then copy from the old
            if (unchanged_land){
                memo[connect_indx][LAND] = memo[city_indx][LAND];
            }

            if (unchanged_sea){
                memo[connect_indx][SEA] = memo[city_indx][SEA];
            }

            //- If this is reahed it means its a valid continuation of the trade route!
            memo[connect_indx][DISTANCE] = memo[city_indx][DISTANCE]+1;
            memo[connect_indx][PREVIOUS] = city_indx;

            indx_to_go.push(connect_indx);
        }
    }

    drawMemoResolution(memo, freed_cities);

    return num_blockcaded == check; //if the starting equals the end
}







//Dijkstra's algorithm knock-off I
size_t Runner::canMove(Unit* unit, const string start, const string target){
    City* city = map.getCity(target);
    const vector<vector<BorderType>>& adjacency = map.getAdjacency();
    size_t movement = unit->movement*2; //assume can strategic move
    size_t num_city = map.getNumCity();
    size_t num_visited = 0;

    queue<size_t> indx_to_go; // priority queue

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