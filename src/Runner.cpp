#include "Runner.h"

//&&& Initalizing the Game

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
        switch (tempS[0]+tempS[1]){ // {GREAT, MAJOR, COLONIES, MINOR, NONE}
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
                printf("Unkown powertype: %s!\n", tempS.c_str());
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
            printf("Unkown nationality: %c!\n", naty);
            exit(1);
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
            printf("Unkown population: %s!\n", tempS.c_str());
            exit(1);
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
            default:
                printf("Unkown resource type: %s!\n", tempS.c_str());
                exit(1);
            break;
        }
        City* c = new City{ID, name, city_type, power_type, population_type, nationality, population, muster, resource, resource_type};

        int x, y;
        map_file >> x;
        map_file >> y;

        c->x = x;
        c->y = y+20;

        map_file >> x;
        map_file >> y;

        c->res_x = x;
        c->res_y = y;

        map.addCity(c);
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
                    printf("Unkown border type: %s", border.c_str());
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
        Country* country = new Country(curr_country, name, map.getCity(capital));

        country->pushback(map[capital]);
        map[capital]->country = name;

        getline(map_file, country_line);
        std::istringstream ss(country_line);
        while (ss >> city){
            country->pushback(map[city]);
            map[city]->country = name;
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

    sprite_offsets["LSTs"] = LSTs;
    sprite_offsets["Motorized_Infantry"] = MOTORIZED_INFANTRY;
    sprite_offsets["AirDefense_Radar"] = AIRDEFENCE_RADAR;
    sprite_offsets["Naval_Radar"] = NAVAL_RADAR;
    sprite_offsets["Rocket_Artillery"] = ROCKET_ARTILLERY;
    sprite_offsets["Heavy_Tanks"] = HEAVY_TANKS;
    sprite_offsets["Heavy_Bombers"] = HEAVY_BOMBERS;
    sprite_offsets["Percision_Bombsight"] = PERCISION_BOMBERS;
    sprite_offsets["Spy_Ring"] = SPY_RING;
    sprite_offsets["Code_Breaker"] = CODE_BREAKER;
    sprite_offsets["Agent"] = AGENT;
    sprite_offsets["Jets"] = JETs;
    sprite_offsets["Double_Agent"] = DOUBLE_AGENT;
    sprite_offsets["Mole"] = MOLE;
    sprite_offsets["1944"] = Y_1944;
    sprite_offsets["Sonar"] = SONAR;
    sprite_offsets["Atomic_Research_1"] = ATOMIC_ONE;
    sprite_offsets["Industrial_Espionage"] = INDUSTRIAL_ESPIONAGE;
    sprite_offsets["Atomic_Research_2"] = ATOMIC_TWO;
    sprite_offsets["Atomic_Research_3"] = ATOMIC_THREE;
    sprite_offsets["Atomic_Research_4"] = ATOMIC_FOUR;
    sprite_offsets["1938"] = Y_1938;
    sprite_offsets["Sabotage"] = SABOTAGE;
    sprite_offsets["Coup"] = COUP;
    sprite_offsets["1942"] = Y_1942;
    sprite_offsets["1940"] = Y_1940;
    sprite_offsets["Empty_Invest"] = FACT_BLANK;
    

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
    const auto& temp_map = map.getCities();
    const auto& allegiance = player.getAllegiance();

    size_t temp_resources = 0;
    size_t temp_population = 0;

    //- Go through each city thats owned by the city
    for (auto& city : temp_map){
        //- If it belongs to the player
        if (city.second->ruler_type == allegiance && !city.second->blockcade){ 
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

void Runner::mapPlayerResPop(Player& player){
    const auto& temp_map = map.getCities();
    const auto& temp_countries = map.getCountries();
    const auto& allegiance = player.getAllegiance();

    size_t temp_resources = 0;
    size_t temp_population = 0;

    //- Go through each city thats owned by the city
    for (auto& city : temp_map){
        //- If it belongs to the player
        if (city.second->ruler_type == allegiance && !city.second->blockcade){ 
            //- Add to player
            temp_resources += city.second->resource;
            //if (city.second->resource>0) cout << city.first << " adds " << city.second->resource <<"R" << endl;
            temp_population += city.second->population;
            //if (city.second->population>0) cout << city.first << " adds " << city.second->population <<"P" << endl;
        }
    }

    //- Go through each influenced country 
    for (const auto& country : temp_countries){
        if (player == country.second->allegiance &&country.second->influence_level <= PROTECTORATES){
            for (const auto& city : country.second->cities){
                temp_resources += city->resource;
                //if (city->resource>0) cout << city->name << " adds " << city->resource <<"R" << endl;
                temp_population += city->population;
                //if (city->population>0) cout << city->name << " adds " << city->population <<"P" << endl;
            }
        }
    }
    //cout << endl;

    player.setPopulation(temp_population);
    player.setResource(temp_resources);
}

//! Logic Checks
//& Unit Actions

void Runner::buildUnit(Player&player, City* city, const UnitType unit, const int cv){
    Unit* cadre = new Unit(player.getNextID(), city->ruler_nationality, unit); //build new unit
    city->addUnit(cadre); //add the unit to the city it was built in
    player.add(cadre); //add is to the players ML of all of its units
    cadre->combat_value = cv-1;

}

//& Deciders

City* Runner::getClosestCity(const Player& player, const int x, const int y) const{
    City* closest = nullptr;
    size_t dist = INFI;
    const auto& cities = map.getCities();
    constexpr int limit = 7500;
    for (const auto& city : cities){
        size_t possible_dist = (player.app->screen.getX(city.second->x+city.second->WIDTH/2) - x)*(player.app->screen.getX(city.second->x+city.second->WIDTH/2) - x) + 
            (player.app->screen.getY(city.second->y+city.second->HEIGHT/2) - y)*(player.app->screen.getY(city.second->y+city.second->HEIGHT/2) - y);
        if (possible_dist < dist && possible_dist <= limit){
            dist = possible_dist;
            closest = city.second;
        }

    }

    return closest;
}

bool Runner::canDisengage(Unit* unit, const string start, const string end){
    //- Check if you the two are connected (0 means they aren't)
    auto city = map.getCity(end);
    return map.checkConnection(start, end) &&

    //- Check if end is friendly or open sea
    (unit->allegiance == city->ruler_type || (city->city_type == WATER && !city->hasEnemy((unit->allegiance)))) && 

    //- Cant go into map with friendly units if in combat
    !city->isConflict()
    ;     
}

bool Runner::checkTradeRoutes(Player& player, const string& main_capital){
    const auto& adjacency = map.getAdjacency();
    const size_t num_city = adjacency.size()-1;
    vector<City*> freed_cities;
    size_t num_blockaded = player.getNumBlockaded();
    const size_t check = num_blockaded;
    freed_cities.reserve(num_blockaded);

    constexpr size_t VISITED = 0, PREVIOUS = 1, PREVIOUS_BORDER = 2, DISTANCE = 3, LAND = 4, SEA = 5, infi = INFI;

    const size_t num_cities = map.getNumCity();
    vector<std::array<size_t, 6>> memo(num_cities + 1, {false, infi, NA, infi, false, false});

    size_t city_index = map.findCity(main_capital);
    memo[city_index] = {false, 0, NA, 0, false, false};

    queue<size_t> index_to_go;
    index_to_go.push(city_index);

    //printf("\n\n\n");

    //? (14.1) The Sea Segment can only cross Coastal Straits, Sea and Ocean borders
    //? (14.1) The Land Segment can only cross Land and Straits borders.
    // Like Dijkstras and will have the main capital find a path to all the cities it controls and runs through it until all those blockcaded is visited
    bool new_sea, new_land;
    while (num_blockaded && !index_to_go.empty()){ //- While there are still blockaded cities to check
        city_index = index_to_go.front();
        index_to_go.pop();

        //- See if has been visited since time it was added to the queue
        if (memo[city_index][VISITED])
            continue;

        //- Can only pass through straits if the ruler isn't an enemy
        if ((memo[city_index][PREVIOUS_BORDER] == LAND_STRAIT || memo[city_index][PREVIOUS_BORDER] == WATER_STRAIT) && !player.isEnemy(map.getCity(city_index)->ruler_type)){
        }

        //- Check a non-strait if the ruler is a rival (not the current player ruler)
        else if (map.getCity(city_index)->ruler_type != player.getAllegiance() && map.getCity(city_index)->ruler_type != NEUTRAL && map.getCity(city_index)->ruler_type != WATER)
            continue;

        //- Set to visited
        memo[city_index][VISITED] = true;
        //printf("Now at %s\n", map.getCity(city_index)->name.c_str());

        //- If the city visited is one blockaded it means we can visit and can decreae the count
        if (map.getCity(city_index)->blockcade && map.getCity(city_index)->ruler_type == player.getAllegiance()){
            //printf("%s was found and connected!\n", map.getCity(city_index)->name.c_str());
            map.getCity(city_index)->blockcade = false;
            freed_cities.push_back(map.getCity(city_index));
            num_blockaded--;
        }

        //- Go thourgh each adjacent node
        for (size_t connect_indx = 1; connect_indx <= num_city; connect_indx++){  
            //- Check what border connects them
            auto& border = adjacency[city_index][connect_indx];

            //- Check if its connected and not visited
            if (border == NA || memo[connect_indx][VISITED]){
                continue;
            }

            //- Check if there it is an enemy controlled city (in cases of straits it can only go through rivals, not enemies)
            if (border == LAND_STRAIT || border == WATER_STRAIT){ //if a strait then it can't iff its an ENEMY (not rival)
                if (player.isEnemy(map.getCity(city_index)->ruler_type)){ //if an enemy with the strait ruler
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
            if (memo[city_index][PREVIOUS_BORDER] == NA){
                if (border <= WATER_STRAIT){ //- if starting sea
                    unchanged_sea=false;
                    new_sea = true;
                }
                else if (border <= COAST_PLAINS){ //- if coastal movement could be both so ignore
                }
                else if (border >= MOUNTAIN){
                    unchanged_land = false;
                    new_land = true;
                }

            }

            //- CONTINUING land segment
            else if (border >= MOUNTAIN && memo[city_index][PREVIOUS_BORDER] >= MOUNTAIN){
            }
            
            //- CONTINUING sea segment
            else if (border <= WATER_STRAIT && memo[city_index][PREVIOUS_BORDER] <= WATER_STRAIT){
            }

            // - STARTING land 
            else if (border >= MOUNTAIN && memo[city_index][PREVIOUS_BORDER] <= WATER_STRAIT){ //check that by seeing if the previous movement was a sea one
                if (!memo[city_index][LAND]){ //if land hasn't started yet then okay!
                    new_land = true; //change
                    unchanged_land = false;
                }
                else{ //if the land segment has already started then no on
                    continue;
                }
            }

            // - Starting sea segment
            else if (border <= WATER_STRAIT && memo[city_index][PREVIOUS_BORDER] >= MOUNTAIN){
                if (!memo[city_index][SEA]){ //if land hasn't started yet then okay!
                    new_sea = true;
                    unchanged_sea = false;
                }
                else{ //if the sea segment has already started then no on
                    continue;
                }
            }
            else if (COAST_MOUNTAIN <= border){ //if its a coastal movement it could be either and won't count
            }
            else{ //- It can't move to this area since it woudl start a preexisting segment!
                continue;
            }

            //- If the land and sea segmetns weren't changes then copy from the old
            if (unchanged_land){
                new_land = memo[city_index][LAND];
            }

            if (unchanged_sea){
                new_sea = memo[city_index][SEA];
            }

            index_to_go.push(connect_indx);

            //- Compare to the current values (if NA always rewrite) if they are the same then take the shorter distance
            if (memo[connect_indx][PREVIOUS_BORDER] != NA || (memo[connect_indx][SEA] == new_sea && memo[connect_indx][LAND] == new_land && memo[connect_indx][DISTANCE] < memo[city_index][DISTANCE]+1)){
                continue;
            }

            //- If this is reahed it means its a valid continuation of the trade route!
            memo[connect_indx][SEA] = new_sea;
            memo[connect_indx][LAND] = new_land;
            memo[connect_indx][DISTANCE] = memo[city_index][DISTANCE]+1;
            memo[connect_indx][PREVIOUS] = city_index;
            memo[connect_indx][PREVIOUS_BORDER] = border;
        }
    }

    drawMemoResolution(memo, freed_cities);

    return num_blockaded == check; //if the starting equals the end
}

ProductionError Runner::canBuild(const Player& player,  City* city, const UnitType unit){
    const CityType allegiance = player.getAllegiance();
    //? 7.231 Building Fortresses Fortress Cadres/steps can be built anywhere in undisputed Friendly Territory, even where Unsupplied
    if (unit == FORTRESS){
        if (city->ruler_type != allegiance){ 
            //cout << "enemy fort" << endl;
            return ENEMY_FORTRESS;
        }
    }
    else{
        //? 2.3 Home Territory Land Areas within the national boundaries of a Great or Major Power (colorcoded) are termed its Home Territory. Except for Fortresses (3.241) all new units (Cadres) must be built within Home Territory.
        if (city->power_type > MAJOR || city->city_type != allegiance || city->ruler_type != allegiance){ 
            //cout << "outside home" << endl;
            return OUTSIDE_HOME;
        }
    }
    //? 7.231 Building Fortresses ... Only one Fortress is allowed per Land Area
    if (unit == FORTRESS){
        for (const auto& city_units : city->occupants[allegiance]){
            if (city_units->unit_type == FORTRESS){
                //cout << "pre_fort" << endl;
                return PRE_FORTRESS;
            }
        }
    }

    //*https://boardgamegeek.com/thread/2974529/article/41205622#41205622 (CARRIER, SUB, FLEET must be build on shores)
    if (unit >= CARRIER && unit <= FLEET){
        const auto& adjacecny = map.getAdjacency()[city->getID()]; //todo optomize
        for (const auto& border : adjacecny){
            if (border > COAST_PLAINS && border != LAND_STRAIT)
                return NAVAL_INLAND;
        }
    } 

    //? 7.23 Building Unit Steps Units cannot be built if they are Unsupplied (14.1), but see 7.231
    if (city->year_supplied == year && city->season_supplied == season && !city->supllied){ //if it was already checked this season for supply lines then use result
        //cout << "unsupplied1" << endl;
        return UNSUPPLIED;
    }

    if ((city->year_supplied != year || city->season_supplied != season) && !isSupllied(player, city, allegiance)){ //if it hasn't been checked this season then need to run check
        //cout << "unsupplied2" << endl;
        return UNSUPPLIED;
    }

    //? Can't use more blocks then you have
    if (player.unit_counts[city->ruler_nationality][unit]+1 > UNIT_COUNTS[unit][city->ruler_nationality]){
        //cout << "unit maxed" << endl;
        return UNIT_MAXED;
    }

    return ABLE;

}

bool Runner::setBuildable(Player& player){
    const auto& city = player.building_city;
    player.unit_buildable[FORTRESS] = (canBuild(player, city, FORTRESS) == ABLE); //top

    player.unit_buildable[AIR] = (canBuild(player, city, AIR) == ABLE); //top right

    player.unit_buildable[CARRIER] = (canBuild(player, city, CARRIER) == ABLE); //right

    player.unit_buildable[SUB] = (canBuild(player, city, SUB) == ABLE); //bottom right

    player.unit_buildable[FLEET] = (canBuild(player, city, FLEET) == ABLE); //bottom

    player.unit_buildable[TANK] = (canBuild(player, city, TANK) == ABLE); //bottom left

    player.unit_buildable[INFANTRY] = (canBuild(player, city, INFANTRY) == ABLE); //left*/

    return player.unit_buildable[FORTRESS] || player.unit_buildable[AIR] || player.unit_buildable[CARRIER] || player.unit_buildable[SUB] || player.unit_buildable[FLEET] || player.unit_buildable[TANK] || player.unit_buildable[INFANTRY];
}

ProductionError Runner::canUpgrade(const Player& player, City* city, const UnitCountry nationality, const Unit* unit){
    //? 7.23 Building Unit Steps Units cannot be built if they are at Sea
    if (city->city_type == WATER || player.getAllegiance() != unit->allegiance){
        return AT_SEA;
    }

    //? 7.23 Building Unit Steps Units cannot be built if Engaged in battle
    if (city->isConflict()){
        return ENGAGED;
    }

    //? 7.23 Building Unit Steps Units cannot be built if they are Unsupplied (14.1), but see 7.231
    if (city->year_supplied == year && city->season_supplied == season && !city->supllied){ //if it was already checked this season for supply lines then use result
        return UNSUPPLIED;
    }

    if ((city->year_supplied != year || city->season_supplied != season) && !isSupllied(player, city, unit->allegiance)){ //if it hasn't been checked this season then need to run check
        return UNSUPPLIED;
    }

    if (unit->combat_value+1 > unit->max_combat_value){
        return MAX_CV;
    }

    return ABLE;
}

bool Runner::isSupllied(const Player& player, City* city, const CityType allegiance){
    //? 14.11 Supply Lines Supply Lines can only pass through Friendly Territory (including Disputed Areas that are Friendly-controlled) and Open Seas.
    //? They cannot pass through Enemy-controlled areas or Rival/Neutral Territory (except Straits, 1.3).
    const auto& adjacency = map.getAdjacency();
    const size_t num_city = adjacency.size()-1;

    constexpr size_t VISITED = 0, PREVIOUS = 1, DISTANCE = 2, STRAIT = 3, infi = INFI;

    const size_t num_cities = map.getNumCity();
    vector<std::array<size_t, 4>> memo(num_cities + 1, {false, infi, infi, false});

    size_t city_index = city->getID();
    memo[city_index] = {0, 0, 0, false};

    queue<size_t> index_to_go;
    index_to_go.push(city_index);

    City* supplier= (city->population_type  >= SUB_CAPITAL)? city : nullptr; //will get set to true if an adjacent city is found

    //Basically, since the supply lines can go to a Capital OR Subcapital, it has more freedom as a trade route, but it can only go through friendly (ruler_type==allegiance) or
    // water areas. Finding the route will be easy since run it until it hits either, but also it can have that all cities on the route to that subcapital or captial can be set as supplied
    // since they can take the same route but starting later on
    while (!index_to_go.empty()){
        city_index = index_to_go.front();
        index_to_go.pop();

        const CityType city_ruler_type = map.getCity(city_index)->ruler_type;

        //- See if has been visited since time it was added to the queue
        if (memo[city_index][VISITED])
            continue;

        //- Can only pass through straits if the ruler isn't an enemy
        if (memo[city_index][STRAIT] && !player.isEnemy(city_ruler_type)){
        }

        //- Check that for non straits it can only go through friendly areas (not neutral or enemy) or water
        else if (map.getCity(city_index)->ruler_type != allegiance && city_ruler_type != WATER)
            continue;

        //- If the city is friendly controlled (if is then is a strait) then visit
        memo[city_index][VISITED] = true;

        //- Go thourgh each adjacent node
        for (size_t connect_indx = 1; connect_indx <= num_city; connect_indx++){  
            //- Check what border connects them
            auto& border = adjacency[city_index][connect_indx];

            if (border == NA || memo[connect_indx][VISITED]){
                continue;
            }
            
            //- If the border is a strait then set that this city is connected by a strait
            memo[connect_indx][STRAIT] = border == WATER_STRAIT;

            //- Check if there it is an enemy controlled city (in cases of straits it can only go through rivals, not enemies)
            if (memo[connect_indx][STRAIT]){ //if a strait then it can't iff its an ENEMY (not rival)
                if (player.isEnemy(map.getCity(connect_indx)->ruler_type)){ //if an enemy with the strait ruler
                    continue;
                }
            }
            else{
                if (map.getCity(connect_indx)->ruler_type != player.getAllegiance() && map.getCity(connect_indx)->ruler_type != WATER){ //if its a regular spot then it can't pass through rival OR enemy
                    continue;
                }
            }

            //- If a subcapital or capital is found it means that the city is suppliable
            if (map.getCity(connect_indx)->population_type >= SUB_CAPITAL){
                supplier = map.getCity(connect_indx);
            }

            //- If this is reahed it means its a valid continuation of the trade route!
            memo[connect_indx][DISTANCE] = memo[city_index][DISTANCE]+1;
            memo[connect_indx][PREVIOUS] = city_index;
            index_to_go.push(connect_indx);
        }
    }

    bool supplied = supplier != nullptr;
    for (size_t connect_indx = 1; connect_indx < num_city; connect_indx++){  

        if (memo[connect_indx][VISITED]){
            const auto& lucky_one = map.getCity(connect_indx);
            lucky_one->year_supplied = year;
            lucky_one->season_supplied = season;
            lucky_one->supllied = supplied;
        }
    }

    return supplied;
}

void Runner::addStop(Player& player, City* city){
    //check for connection and if it hasn't been added before
    const auto& index = std::find(player.movement_memo.begin(), player.movement_memo.end(), city);

    if (index == player.movement_memo.end()){ //if not in then check if its added
        if (canLandMove(player, player.moving_unit.second, player.movement_memo.back(), player.closest_map_city)){
            player.movement_memo.push_back(player.closest_map_city);
        } 
    }
    else{ //if its already in the memo then truncate everything past 
        player.movement_memo.erase(index, player.movement_memo.end());
    }
}

bool Runner::checkRoute(Player& player){ 
    const Unit* moving_unit = player.moving_unit.second;
    
    if (player.movement_memo[0]->isConflict()){ //can disengage
        return canDisengage(player, player.moving_unit.second);
    }

    switch (moving_unit->class_type){
        case CLASS_A:
            return canAirMove(player, moving_unit);
            break;
        case CLASS_G:
            return canLandMove(player, moving_unit);
            break;
        case CLASS_S:
            return canSeaMove(player, moving_unit);
            break;
        case CLASS_N:
            return canSeaMove(player, moving_unit);
            break;

        default:
            exit(1);
    }

    return true;  
}

bool Runner::canLandMove(const Player& player, const Unit* unit) const{
    //- Check if the unit is able to move
    if (unit->current_movement.first == year && unit->current_movement.second > 0 && unit->movement > 0)
        return false;

    //- Check if they are even connected
    if (!isLand(map.getAdjacency()[start->ID][end->ID]))
        return false;

    auto checkBorderLimits = [&]() {
        return BORDER_LIMITS[map.getBorder(start, end)] > map.getBorderLimit(start, end, player.getAllegiance());
    };

    if (player == end->ruler_type) { // Player owned
        return !end->isConflict() || checkBorderLimits();
    }

    if (end->ruler_type != NEUTRAL) { // Rival owned
        if (player.isEnemy(end->ruler_type)) {
            if (end->hasEnemy(player.getAllegiance())) {
                if (end->isFighting(player.getAllegiance())) { //old engagement
                    return checkBorderLimits();
                } 
                else { //new engagement
                    return !player.usedEmergency() && checkBorderLimits();
                }
            } 
            else {
                return true;
            }
        } 
        else {
            return false;
        }
    }

    if (end->ruler_type == NEUTRAL) { // NEUTRAL owned
        if (end->voilation_of_neutrality != NEUTRAL) { // VoN
            if (end->hasEnemy(player.getAllegiance())) {
                if (end->isFighting(player.getAllegiance())) { // Old engagement
                    return checkBorderLimits();
                } 
                else { // New engagement
                    return !player.usedEmergency() && checkBorderLimits();
                }
            } 
            else {
                return true;
            }
        } 
        else { //!VoN
            if (end->armed) {
                if (end->hasEnemy(player.getAllegiance())) {
                    if (end->isFighting(player.getAllegiance())) { // Old engagement
                        return checkBorderLimits();
                    } 
                    else { // New engagement
                        return !player.usedEmergency() && checkBorderLimits();
                    }
                } 
                else {
                    return true;
                }
            } 
            else {
                return false;
            }
        }
    }

    std::cerr << "Escaped if-chain somehow" << endl;
    exit(1);
    return true;

}

bool Runner::canSeaMove(const Player& player, const Unit* unit) const{

    return false;
}

bool Runner::canAirMove(const Player& player, const Unit* unit) const{

    return false;
}

bool Runner::canDisengage(const Player& player, const Unit* unit) const{
    
    return false;
}

//& Dev tools

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
