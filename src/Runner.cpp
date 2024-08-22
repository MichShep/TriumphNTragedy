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

        bool deep=false;
        
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
            case 'D'+'W':
                city_type = WATER;
                deep = true;
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
        
        c->deep = deep;

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
        map[capital]->capital = true;

        getline(map_file, country_line);
        std::istringstream ss(country_line);
        while (ss >> city){
            country->pushback(map[city]);
            map[city]->country = name;
        }
        country->allegiance = map[capital]->start_allegiance;
        country->starter_allegiance = country->allegiance;

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

    sprite_offsets["Isolationism"] = 24;
    sprite_offsets["Intimidation"] = 25;
    sprite_offsets["Guarantee"] = 26;
    sprite_offsets["Foreign_Aid"] = 27;
    sprite_offsets["Ties_That_Bind"] = 28;
    sprite_offsets["Fear_And_Loathing"] = 29;
    sprite_offsets["Versailles"] = 30;
    sprite_offsets["Ethnic_Ties"] = 31;
    sprite_offsets["Brothers_In_Arms"] = 32;
    sprite_offsets["Birds_Of_A_Feather"] = 33;

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
    sprite_offsets["Jets"] = JETS;
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

        if (sprite_offsets.find(countryA) == sprite_offsets.end()){
            cout << "No instance of " << countryA << " offset" << endl;
        }

        if (sprite_offsets.find(countryB) == sprite_offsets.end()){
            cout << "No instance of " << countryB << " offset" << endl;
        }

        const auto res = new ActionCard((ActionType)type, countryA, countryB, season, letter, number, sprite_offsets[countryA], sprite_offsets[countryB]);
        action_discard.push_back(res);
        if (res->type){
            res->wild_type = (WildActionType)(sprite_offsets[countryA]-24);
        }
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
        if (city.second->ruler_allegiance == allegiance && !city.second->blockcade){ 
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
        if (city.second->ruler_allegiance == allegiance && !city.second->blockcade){ 
            //- Add to player
            temp_resources += city.second->resource;
            //if (city.second->resource>0) cout << city.first << " adds " << city.second->resource <<"R" << endl;
            temp_population += city.second->population;
            //if (city.second->population>0) cout << city.first << " adds " << city.second->population <<"P" << endl;
        }
    }

    //- Go through each influenced country 
    for (const auto& country : temp_countries){
        if (player == country.second->allegiance && country.second->influence_level <= PROTECTORATES && country.second->starter_allegiance != country.second->allegiance){ //to stop double count of starter 
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

//& Unit Actions

Unit* Runner::buildCadre(Player&player, City* city, const UnitType unit){
    Unit* cadre = new Unit(player.getNextID(), city->ruler_nationality, unit, year); //build new unit
    city->addUnit(cadre); //add the unit to the city it was built in
    player.add(cadre); //add is to the players ML of all of its units
    cadre->combat_value = 0;

    return cadre;
}

Unit* Runner::buildUnit(Player&player, City* city, const UnitType unit, const int cv){
    Unit* unit_obj = new Unit(player.getNextID(), city->ruler_nationality, unit, year); //build new unit
    city->addUnit(unit_obj); //add the unit to the city it was built in
    player.add(unit_obj); //add is to the players ML of all of its units
    unit_obj->combat_value = cv;

    unit_obj->upgrading = false;

    return unit_obj;
}

//& Card Actions

//&^ Espionage
void Runner::selectTechCard(Player& player){
    if (player.widget == INVEST_HAND && player == player.invest_view && player.popped_invest_card != nullptr && player.a_held_tick != 0){
        player.popped_invest_card->selected = !player.popped_invest_card->selected;
    }
}

void Runner::peakRivalAction(Player& player){
    player.peakAction(clock);
}

void Runner::peakRivalUnit(Player& player){
    player.peakUnit(clock);
}

void Runner::coupRival(Player& player){
    coup(player);
}

void Runner::sabotageRival(Player& player){
    sabotage(player);
}

void Runner::spyRingRival(Player& player){
    spyRing(player);
}

//&^ Wild Action Cards

bool Runner::canWildAction(Player& player){
    if (player.popped_action_card == nullptr || player.popped_action_card->wild_type == NOT_WILD || player.closest_map_city == nullptr)
        return false;

    switch(player.popped_action_card->wild_type) {
        case ISOLATIONISM:
            return handleIsolationism(player);
            break;
        case INTIMIDATION:
            return handleIntimidation(player);
            break;
        case GUARANTEE:
            return handleGuarantee(player);
            break;
        case FOREIGN_AID:
            return handleForeignAid(player);
            break;
        case TIES_THAT_BIND:
            return handleTiesThatBind(player);
            break;
        case FEAR_AND_LOATHING:
            return handleFearAndLoathing(player);
            break;
        case VERSAILLES:
            return handleVersailles(player);
            break;
        case ETHNIC_TIES:
            return handleEthnicTies(player);
            break;
        case BROTHERS_IN_ARMS:
            return handleBrothersInArms(player);
            break;
        case BIRDS_OF_A_FEATHER:
            return handleBirdsOfAFeather(player);
            break;
        default:
            exit(1);
            std::cerr << "Uknown wild type card '" << player.popped_action_card->wild_type << "'" << endl;
            return false;
            break;
    }

}

bool Runner::handleIsolationism(Player& player){
    const auto& selected_city = player.closest_map_city->name;
    Country* target_country = nullptr;
    switch (selected_city[0] + selected_city[1] + selected_city[2]){
        case 'W'+'a'+'s': //Washington
        case 'M'+'a'+'d': //Madris
        case 'A'+'m'+'s': //Amsterdam
        case 'W'+'a'+'r': //Poland
        case 'S'+'t'+'o': //Stockholm
        case 'A'+'n'+'k': //Ankara
            target_country = map.getCountry(player.closest_map_city->country);
            break;
        
        default:
            return false;
            break;
    }

    if (target_country->influence < 1 || target_country->allegiance == player || target_country->influence_level == SATELLITES || target_country->armed_minor)
        return false;

    target_country->directAdd(player);

    target_country->resolveDiplomacy();

    return true;
    //remove rival influence from USA, Spain, Low Countries, Poland, Sweden, Turkey
}

bool Runner::handleForeignAid(Player& player){
    if (player.getIndustry() < 1)
        return false;

    const auto& selected_city = player.closest_map_city;

    if (!(selected_city->occupier_allegiance == NEUTRAL && !selected_city->armed && selected_city->capital))
        return false;

    Country* selected_country = map.getCountry(selected_city->country);

    if (selected_country->armed_minor)
        return false;

    selected_country->directAdd(player);

    player.lowerIND();

    return true;
}

bool Runner::handleGuarantee(Player& player){
    const auto& selected_city = player.closest_map_city;

    if (!(selected_city->occupier_allegiance == NEUTRAL && selected_city->capital))
        return false;

    Country* selected_country = map.getCountry(selected_city->country);

    if (selected_country->influence_level == SATELLITES || selected_country->name == "USA" || selected_country->armed_minor)
        return false;

    //check for the rival territory
    bool found_rival=false;
    for (const auto& city : selected_country->cities){
        const auto& adjacencies = map.getAdjacency()[city->ID];
        const size_t& id = city->ID;

        for (size_t i = 0; i < adjacencies.size(); i++){
            if (map.getBorder(id, i) && isRival(player, map.getCity(i)->occupier_allegiance)){
                found_rival = true;
            }
        }
    }

    if (!found_rival)
        return false;

    selected_country->directAdd(player);


    cout << selected_country->influence << " " << selected_country->influence_level << endl;

    return true;
}

bool Runner::handleIntimidation(Player& player){
    const auto& selected_city = player.closest_map_city;

    if (!(selected_city->occupier_allegiance == NEUTRAL && selected_city->capital))
        return false;

    Country* selected_country = map.getCountry(selected_city->country);

    if (selected_country->name == "USA" || selected_country->armed_minor)
        return false;

    //check for the rival territory
    bool found_rival=false;
    for (const auto& city : selected_country->cities){
        const auto& adjacencies = map.getAdjacency()[city->ID];
        const size_t& id = city->ID;

        for (size_t i = 0; i < adjacencies.size(); i++){
            if (map.getBorder(id, i) && player == map.getCity(i)->occupier_allegiance){
                found_rival = true;
            }
        }
    }

    if (!found_rival)
        return false;

    selected_country->directAdd(player);
    
    return true;
}

bool Runner::handleBirdsOfAFeather(Player& player){
    const string options[3][4] = {{"USA", "Norway", "Denmark", "Sweden"}, //west
                                {"Portugal", "Spain", "Yugoslavia", "Latin_America"}, //axis
                                {"Spain", "Dongland", "Dongland", "Dongland"}}; //ussr

    const auto& selected_city = player.closest_map_city;

    if (!(selected_city->occupier_allegiance == NEUTRAL && selected_city->capital))
        return false;

        //dev michael write that the country should be checked for arm not the city

    Country* selected_country = map.getCountry(selected_city->country);
    const string& name = selected_country->name;

    if (selected_country->armed_minor) //if armed can't be influenced
        return false;

    for (const auto& country : options[(int)player]){
        if (country == name){
            selected_country->directAdd(player);
            return true;
        }
    }

    return false;
}

bool Runner::handleTiesThatBind(Player& player){
    const string options[3][3] = {{"USA", "Low_Countries", "Czechoslovakia"}, //west
                                {"Austria", "Hungary", "Bulgaria"}, //axis
                                {"Spain", "Yugoslavia", "Dongland"}}; //ussr

    const auto& selected_city = player.closest_map_city;

    if (!(selected_city->occupier_allegiance == NEUTRAL && selected_city->capital))
        return false;

        //dev michael write that the country should be checked for arm not the city

    Country* selected_country = map.getCountry(selected_city->country);
    const string& name = selected_country->name;

    if (selected_country->armed_minor) //if armed can't be influenced
        return false;

    for (const auto& country : options[(int)player]){
        if (country == name){
            selected_country->directAdd(player);
            return true;
        }
    }

    return false;
}

bool Runner::handleFearAndLoathing(Player& player){
    const string options[3][7] = {{"Austria", "Hungary", "Bulgaria", "Latin_America", "Turkey", "Persia", "Dongland"}, //west
                                {"Low_Countries", "Czechoslovakia", "Poland", "Yugoslavia", "Norway", "Rumania", "USA"}, //axis
                                {"Poland", "Rumania", "Turkey", "Finland", "Sweden", "Baltic_States", "USA"}}; //ussr

    const auto& selected_city = player.closest_map_city;

    if (!(selected_city->occupier_allegiance == NEUTRAL && selected_city->capital))
        return false;

    Country* selected_country = map.getCountry(selected_city->country);
    const string& name = selected_country->name;

    if (selected_country->influence < 1 || selected_country->allegiance == player || selected_country->armed_minor) //since its only removing not adding  
        return false;

    for (const auto& country : options[(int)player]){
        if (country == name){
            selected_country->directAdd(player);
            return true;
        }
    }

    return false;
}

bool Runner::handleVersailles(Player& player){
    const string options[3][3] = {{"Poland", "Czechoslovakia", "Yugoslavia"}, //west
                                {"Austria", "Hungary", "Turkey"}, //axis
                                {"Yugoslavia", "Dongland", "Dongland"}}; //ussr

    const auto& selected_city = player.closest_map_city;

    if (!(selected_city->occupier_allegiance == NEUTRAL && selected_city->capital))
        return false;

        //dev michael write that the country should be checked for arm not the city

    Country* selected_country = map.getCountry(selected_city->country);
    const string& name = selected_country->name;

    if (selected_country->armed_minor) //if armed can't be influenced
        return false;

    for (const auto& country : options[(int)player]){
        if (country == name){
            selected_country->directAdd(player);
            return true;
        }
    }

    return false;
}

bool Runner::handleEthnicTies(Player& player){
    const string options[3][4] = {{"USA", "Norway", "Low_Countries", "Rumania"}, //west
                                {"Austria", "Sweden", "Norway", "dongland"}, //axis
                                {"Yugoslavia", "Poland", "Bulgaria", "dongland"}}; //ussr

    const auto& selected_city = player.closest_map_city;

    if (!(selected_city->occupier_allegiance == NEUTRAL && selected_city->capital))
        return false;

        //dev michael write that the country should be checked for arm not the city

    Country* selected_country = map.getCountry(selected_city->country);
    const string& name = selected_country->name;

    if (selected_country->armed_minor)
        return false;

    for (const auto& country : options[(int)player]){
        if (country == name){
            selected_country->directAdd(player);
            return true;
        }
    }

    return false;
}

bool Runner::handleBrothersInArms(Player& player){
    const string options[3][3] = {{"USA", "Low_Countries", "Rumania"}, //west
                                {"Austria", "Hungary", "Bulgaria"}, //axis
                                {"Spain", "Czechoslovakia", "Dongland"}}; //ussr

    const auto& selected_city = player.closest_map_city;

    if (!(selected_city->occupier_allegiance == NEUTRAL && selected_city->capital))
        return false;

        //dev michael write that the country should be checked for arm not the city

    Country* selected_country = map.getCountry(selected_city->country);
    const string& name = selected_country->name;

    if (selected_country->armed_minor)
        return false;

    for (const auto& country : options[(int)player]){
        if (country == name){
            selected_country->directAdd(player);
            return true;
        }
    }

    return false;
}

//& Battle Actions

bool Runner::addBattle(const Player& player, const CityType& defender){
    if (player != current_player || player.a_held_tick == 0)
        return false;

    //if there is a selected unit that isn't selected and is the players then select it for movement
    City* target = player.closest_map_city;

    if (target == nullptr)
        return false;

    const auto& index = std::find_if(battles.begin(), battles.end(), [&target](const pair<City*, CityType> p1){ return p1.first == target;});;

    if (index == battles.end() && target->isFighting(player.getAllegiance())){ //not in
        battles.push_back({target, defender}); //todo

        return true;
    }
    else if (index != battles.end()){ //if in then remove
        if (defender != (*index).second){
            (*index).second = defender;
        }
        else{
            battles.erase(index);
        }
    }

    return false;
}

void Runner::hitUnit(City* city, Unit* unit){
    if (!(--unit->combat_value)){
        city->removeUnit(unit);
        if (unit->allegiance == NEUTRAL){
            neutral_units.erase(find(neutral_units.begin(), neutral_units.end(), unit));
            delete unit;
        }
        else
            players[unit->allegiance].remove(unit);
    }

    handleUnitActionEnd();
}

void Runner::finalizeBattleGroup(Player& player){
    //make sure at least one
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
        if ((memo[city_index][PREVIOUS_BORDER] == LAND_STRAIT || memo[city_index][PREVIOUS_BORDER] == WATER_STRAIT) && !player.isEnemy(map.getCity(city_index)->ruler_allegiance)){
        }

        //- Check a non-strait if the ruler is a rival (not the current player ruler)
        else if (map.getCity(city_index)->ruler_allegiance != player.getAllegiance() && map.getCity(city_index)->ruler_allegiance != NEUTRAL && map.getCity(city_index)->ruler_allegiance != WATER)
            continue;

        //- Set to visited
        memo[city_index][VISITED] = true;
        //printf("Now at %s\n", map.getCity(city_index)->name.c_str());

        //- If the city visited is one blockaded it means we can visit and can decreae the count
        if (map.getCity(city_index)->blockcade && map.getCity(city_index)->ruler_allegiance == player.getAllegiance()){
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
                if (player.isEnemy(map.getCity(city_index)->ruler_allegiance)){ //if an enemy with the strait ruler
                    continue;
                }
            }
            else{
                if (map.getCity(connect_indx)->ruler_allegiance != player.getAllegiance() && map.getCity(connect_indx)->ruler_allegiance != NEUTRAL && map.getCity(connect_indx)->ruler_allegiance != WATER){ //if its a regular spot then it can;t pass through rival OR enemy
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

//&^ Production

ProductionError Runner::canBuild(const Player& player,  City* city, const UnitType unit){
    const CityType allegiance = player.getAllegiance();

    //? 7.231 Building Fortresses Fortress Cadres/steps can be built anywhere in undisputed Friendly Territory, even where Unsupplied
    if (season != INIT_UNITS){
        if (unit == FORTRESS){
            if (city->occupier_allegiance != allegiance){ 
                //cout << "enemy fort" << endl;
                return ENEMY_FORTRESS;
            }
        }
        else{
            //? 2.3 Home Territory Land Areas within the national boundaries of a Great or Major Power (colorcoded) are termed its Home Territory. Except for Fortresses (3.241) all new units (Cadres) must be built within Home Territory.
            if (city->power_type > MAJOR || city->start_allegiance != allegiance || city->occupier_allegiance != allegiance){ 
                //cout << "outside home" << endl;
                return OUTSIDE_HOME;
            }
        }
    }
    else{
        if ( city->occupier_allegiance != allegiance){
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
    if (isN(unit)){
        const auto& adjacecny = map.getAdjacency()[city->getID()]; //todo optomize
        bool found_water = false;
        for (const auto& border : adjacecny){
            if (isNaval(border)){
                found_water = true;
                break;
            }
        }

        if (!found_water)
            return NAVAL_INLAND;
    } 

    //? 7.23 Building Unit Steps Units cannot be built if they are Unsupplied (14.1), but see 7.231
    if (season != INIT_UNITS && city->year_supplied == year && city->season_supplied == season && !city->supplied){ //if it was already checked this season for supply lines then use result
        //cout << "unsupplied1" << endl;
        return UNSUPPLIED;
    }

    if (season != INIT_UNITS && (city->year_supplied != year || city->season_supplied != season) && !isSupllied(player, city, allegiance)){ //if it hasn't been checked this season then need to run check
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
    const auto& city = player.option_select_city;

    //if in the init unit phase check if the current city can have more (more left && has any)
    if (season == INIT_UNITS && !(starting_cities.find(city->name) != starting_cities.end() && city->getUpgraded(player) < (*starting_cities.find(city->name)).second)){
        return false;
    }

    player.unit_available[FORTRESS] = (canBuild(player, city, FORTRESS) == ABLE); //top

    player.unit_available[AIR] = (canBuild(player, city, AIR) == ABLE); //top right

    player.unit_available[CARRIER] = (canBuild(player, city, CARRIER) == ABLE); //right

    player.unit_available[SUB] = (canBuild(player, city, SUB) == ABLE); //bottom right

    player.unit_available[FLEET] = (canBuild(player, city, FLEET) == ABLE); //bottom

    player.unit_available[TANK] = (canBuild(player, city, TANK) == ABLE); //bottom left

    player.unit_available[INFANTRY] = (canBuild(player, city, INFANTRY) == ABLE); //left*/

    return player.unit_available[FORTRESS] || player.unit_available[AIR] || player.unit_available[CARRIER] || player.unit_available[SUB] || player.unit_available[FLEET] || player.unit_available[TANK] || player.unit_available[INFANTRY];
}

ProductionError Runner::canUpgrade(const Player& player, City* city, const UnitCountry nationality, const Unit* unit){
    //? 7.23 Building Unit Steps Units cannot be built if they are at Sea
    if (city->start_allegiance == WATER || player.getAllegiance() != unit->allegiance){
        return AT_SEA;
    }

    //? 7.23 Building Unit Steps Units cannot be built if Engaged in battle
    if (city->isConflict()){
        return ENGAGED;
    }

    //? 7.23 Building Unit Steps Units cannot be built if they are Unsupplied (14.1), but see 7.231
    if (city->year_supplied == year && city->season_supplied == season && !city->supplied){ //if it was already checked this season for supply lines then use result
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

        const CityType city_ruler_type = map.getCity(city_index)->ruler_allegiance;

        //- See if has been visited since time it was added to the queue
        if (memo[city_index][VISITED])
            continue;

        //- Can only pass through straits if the ruler isn't an enemy
        if (memo[city_index][STRAIT] && !player.isEnemy(city_ruler_type)){
        }

        //- Check that for non straits it can only go through friendly areas (not neutral or enemy) or water
        else if (map.getCity(city_index)->ruler_allegiance != allegiance && city_ruler_type != WATER)
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
                if (player.isEnemy(map.getCity(connect_indx)->ruler_allegiance)){ //if an enemy with the strait ruler
                    continue;
                }
            }
            else{
                if (map.getCity(connect_indx)->ruler_allegiance != player.getAllegiance() && map.getCity(connect_indx)->ruler_allegiance != WATER){ //if its a regular spot then it can't pass through rival OR enemy
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
            lucky_one->supplied = supplied;
        }
    }

    return supplied;
}

//&^ Battle

void Runner::setLandBattleable(Player& attacker, Player& defender){
    const auto& city = battles.front();
    const int defend_allegiance = defender;

    for (const auto& unit : city.first->occupants[defend_allegiance]){
        attacker.unit_available[unit->class_type] = true;
    }
}

void Runner::sortFireOrder(){
    // Get participating player's units from the city
    const auto& attacker_units = current_battle.first->occupants[current_player->getAllegiance()];
    const auto& defender_units = current_battle.first->occupants[current_battle.second];

    // Load First Fire table
    bool ff_table[4][8] = {
        {false, false, false, false, false, false, false, false}, {false, false, false, false, false, false, false, false}, {false, false, false, false, false, false, false, false}, {false, false, false, false, false, false, false, false}
    };

    const CityType& attacker_allegiance = current_player->getAllegiance();
    const CityType& defender_allegiance = current_battle.second;
    int index = 0;

    for (const auto& b : current_player->getFirstFire()) {
        ff_table[attacker_allegiance][index] = b;
        index++;
    }
    index=0;

    if (defender_allegiance == NEUTRAL){
        for (auto& b : ff_table[defender_allegiance]) {
            b = true;
            index++;
        }
    }
    else{
        for (const auto& b : players[current_battle.second].getFirstFire()) {
            ff_table[defender_allegiance][index] = b;
            index++;
        }
    }

    fire_order.clear(); // Clear the fire_order vector before filling it
    fire_order.reserve(attacker_units.size() + defender_units.size()); // Reserve memory (may not be full from convoys but is a hard worst case)

    bool sea_battle = current_battle.first->start_allegiance == WATER;

    for (auto& unit : attacker_units){ // Add all of the attacker's units
        if (unit->landing != year && !unit->acted && !(sea_battle && !unit->battle_group)) //if the convoy landed on an enemy shore this year then they don't get to act womp womp
            fire_order.push_back(unit);
        else{
            unit->acted = true; //just to show its 'exhausted' and wont act
        }
    }
    for (auto& unit : defender_units){ // Add all of the defender's units
        if (!unit->acted && !(sea_battle && !unit->battle_group))
            fire_order.push_back(unit);
    }
    //dev reset neutral units after a round
    //Lambda function to compare
    auto compare = [&](const Unit* a, const Unit* b) {
        if (a->unit_type == b->unit_type){
            if (a->allegiance != b->allegiance){
                if (b->allegiance == defender_allegiance){
                    //cout << a->unit_type << ": " << ff_table[a->allegiance][a->unit_type] << " " << ff_table[b->allegiance][b->unit_type] << endl;
                    return !ff_table[a->allegiance][a->unit_type] || ff_table[b->allegiance][b->unit_type]; //swap equal lower priority?
                }
                else {
                    //cout << a->unit_type << " : " << ff_table[a->allegiance][a->unit_type] << " " << ff_table[b->allegiance][b->unit_type] << endl;
                    return ff_table[a->allegiance][a->unit_type] || !ff_table[b->allegiance][b->unit_type];
                }
            }

            return a->combat_value > b->combat_value;
            // A D R
            // 0 0 D
            // 0 1 D
            // 1 0 A
            // 1 1 D
        }
        
        return a->unit_type < b->unit_type;
    };

    // Sort fire_order using the comparator
    sort(fire_order.begin(), fire_order.end(), compare);
}

void Runner::sortReBaseOrder(const bool att, const bool def){
    // Get participating player's units from the city
    const CityType& attacker_allegiance = current_player->getAllegiance();
    const CityType& defender_allegiance = current_battle.second;

    const auto& attacker_units = current_battle.first->occupants[attacker_allegiance];
    const auto& defender_units = current_battle.first->occupants[defender_allegiance];

    fire_order.clear(); // Clear the fire_order vector before filling it
    fire_order.reserve(attacker_units.size() + defender_units.size()); // Reserve memory (may not be full from convoys but is a hard worst case)

    if (att){
        for (auto& unit : attacker_units){ // Add all of the attacker's units
            if (isANS(unit->class_type) && !unit->rebase){
                unit->acted = false;
                fire_order.push_back(unit);
            }
        }
    }
    if (def){
        for (auto& unit : defender_units){ // Add all of the defender's units
            if (isANS(unit->class_type)&& !unit->rebase){
                unit->acted = false;
                fire_order.push_back(unit);
            }
        }
    }

    //Lambda function to compare the priority of units to rebase (attacker goes first imo but could change)
    auto compare = [&](const Unit* a, const Unit* b) {
        if (a->unit_type == b->unit_type){
            if (a->allegiance != b->allegiance){
                return b->allegiance == attacker_allegiance && a->allegiance != attacker_allegiance;
            }

            return a->combat_value > b->combat_value;
            // A D R
            // 0 0 D
            // 0 1 D
            // 1 0 A
            // 1 1 D
        }
        
        return a->unit_type < b->unit_type;
    };

    // Sort fire_order using the comparator
    sort(fire_order.begin(), fire_order.end(), compare);
}

void Runner::setFireable(Player& player, const City* city, const CityType& victim){
    //reset
    player.unit_available[CLASS_A] = false; player.unit_available[CLASS_G] = false; player.unit_available[CLASS_N]= false; player.unit_available[CLASS_S]= false;
    //will doble purpose `unit_available` from production phase to get which Unit Class can be fired upon
    for (const auto& unit : city->occupants[victim]){
        player.unit_available[unit->class_type] = true;

        // if are all found then go ahead and quit earlt
        if (player.unit_available[CLASS_A] && player.unit_available[CLASS_G] && player.unit_available[CLASS_N] && player.unit_available[CLASS_S]){
            return;
        }
    }
}

Unit* Runner::checkHit(const CityType& victim_type, const UnitClass& victim_class) const{
     //if neutral they only have one unit or if they only have one unit then they don't have to pick which to deal hits
    if (victim_type == NEUTRAL || current_battle.first->occupants[victim_type].size() == 1){
        return current_battle.first->occupants[victim_type][0];
    }

    //if they have more than one unit check if the class needing to be hit has more than one
    Unit* found = nullptr;
    for (const auto& unit : current_battle.first->occupants[victim_type]){
        if (unit->class_type == victim_class){
            if (!found){
                found = unit;
            }
            else{ //another unit of the same class was found so need user input
                return nullptr;
            }
        }
    }

    return found; // if still only one was found (didn't return in loop then no need to check)
}

void Runner::checkHitRoll(){
    //set current unit to tired
    fire_order[0]->acted = true;

    if (die.last_result <= FIREPOWER_TABLE[fire_order[0]->unit_type][target_class]){ //if its a hit then go to selection mode
        //todo display hit message
        public_animations.push_back(PublicAnimation((SeasonAnimation)(HIT), -115, -210, 1354, 888, 230, 140, 1, clock, 100));
        public_animations.back().addPhase(AnimationPhase::STILL, 5000);
        
        if (watching_player != NEUTRAL){
            players[watching_player].combat_phase = COMBAT_DEAL_HITS;
            players[watching_player].popped_hit_unit = current_battle.first->occupants[watching_player][players[watching_player].popped_hit_index];
        }
        else{ //if its neutral then automatically hit unit
            hitUnit(current_battle.first, current_battle.first->occupants[NEUTRAL][0]);
        }
    }
    else{
        //todo display miss message
        public_animations.push_back(PublicAnimation((SeasonAnimation)(MISS), -115, -210, 1354+230, 888, 230, 140, 1, clock, 100));
        public_animations.back().addPhase(AnimationPhase::STILL, 5000);

        handleUnitActionEnd();
    }
}

bool Runner::canHitUnit(){
    const auto& hit_unit = watching_player == NEUTRAL? current_battle.first->occupants[NEUTRAL][0]: players[watching_player].popped_hit_unit;
    if (hit_unit->class_type == target_class){
        //go through all occupants and make sure it is or tied for the most cv
        int max_cv = -1;
        for (const auto& unit : current_battle.first->occupants[watching_player]){
            if (unit->class_type == target_class && unit->combat_value > max_cv)
                max_cv =  unit->combat_value;
        }

        return max_cv == hit_unit->combat_value;
    }

    return false;
}

void Runner::handleUnitActionEnd(){
    target_class = CLASS_NULL;

    auto check_rebase = [&](){
        end_phase = true;
        //? ANS units without ground support MUST rebase
        bool att = current_battle.first->mustRebase(current_player->getAllegiance());
        bool def = current_battle.first->mustRebase(current_battle.second);
        if (att || def){
            sortReBaseOrder(att, def);

            if (fire_order.empty())
                return false;

            acting_player = fire_order[0]->allegiance;
            watching_player = acting_player == current_player->getAllegiance()? current_battle.second : *current_player;
            
            players[acting_player].combat_phase = COMBAT_FINISHED_FORCED_REBASE;
            
            if (watching_player != NEUTRAL)
                players[watching_player].combat_phase = OBSERVING;

            players[acting_player].moving_units.push_back(fire_order[0]);
            players[acting_player].movement_memo.push_back(current_battle.first);

            return true;
        }

        //? 12.22 Active ANS units may always ReBase (13.12) if desired.
        if (current_battle.first->hasANS(current_player->getAllegiance())){
            current_player->combat_phase = COMBAT_SELECT_REBASE_OPT;

            sortReBaseOrder(true, false);

            if (fire_order.empty())
                return false;

            players[acting_player].moving_units.push_back(fire_order[0]);
            players[acting_player].movement_memo.push_back(current_battle.first);
            return true;
        }

        return false;
    };

    if (end_phase){
        if (check_rebase()){
            return;
        }
    }

    if (!end_phase && !fire_order.empty() && !current_battle.first->occupants[current_player->getAllegiance()].empty() && !current_battle.first->occupants[current_battle.second].empty()){ //if more units to fire set the new acting and watching
        sortFireOrder();

        if (fire_order.empty()){
            handleUnitActionEnd();
            return;
        }

        acting_player = fire_order[0]->allegiance;
        watching_player = acting_player == current_player->getAllegiance()? current_battle.second : *current_player;

        players[acting_player].combat_phase = COMBAT_SELECT_ACTION;
        
        if (current_battle.second != NEUTRAL)
            players[watching_player].combat_phase = OBSERVING;

        setFireable(players[acting_player], current_battle.first, watching_player);
    }
    else if (!battles.empty()){
        if (check_rebase()){
            return;
        }

        end_phase = false;
        current_battle.first = nullptr;        

        PublicAnimation p_a = PublicAnimation(NEXT_BATTLE, -50, 982/2, 1254, 928, 100, 100, 2, clock, 1000);
        p_a.addPhase(AnimationPhase::FLICKER, 5000);
        p_a.setFinishCallback([this]() { setNextBattle(); });
        public_animations.push_back(p_a);

    }
    else{
        if (check_rebase()){
            return;
        }

        end_phase = false;
        current_player->combat_phase = COMBAT_FINISHED;
        current_battle.first = nullptr;
        seasonActed(*current_player);
    }
}

void Runner::setNextBattle(){
    current_battle = battles.front();

    battles.erase(battles.begin());

    sortFireOrder();

    acting_player = fire_order[0]->allegiance;
    if (acting_player == NEUTRAL)
        setNeutralBattle();
    else{
        acting_player = fire_order[0]->allegiance;
        watching_player = acting_player == current_player->getAllegiance()? current_battle.second : *current_player;
    }

    players[acting_player].combat_phase = COMBAT_SELECT_ACTION;
    
    if (watching_player != NEUTRAL)
        players[watching_player].combat_phase = OBSERVING;

    setFireable(players[acting_player], current_battle.first, watching_player);
}

void Runner::retreatUnit(Player& player){
    auto& unit = player.moving_units[0];
    const MovementMessage res = canRetreat(player, unit);

    if (res < 0 ){ //negative means there was an error
        cout << "error moving: " << movementErrorNames[res+abs(EMPTY_MEMO)] << endl;
    }

    else{ //only accepted is TURN_TO_CONVOY or NO_EFFECT
        auto& memo =  player.movement_memo;

        memo[1]->addUnit(unit); 
        memo[0]->removeUnit(unit);

        unit->acted = true;

        if (unit->class_type == CLASS_G){
            map.increaseBorderLimit(memo[0], memo[1], player.getAllegiance());
        }

        if (res == TURN_CONVOY)
            unit->convoy = true;

        player.resetMovingUnit();
        player.movement_memo.clear();
        
        handleUnitActionEnd();
    }
}

void Runner::reBaseUnit(Player& player){
    auto& unit = player.moving_units[0];
    const MovementMessage res = canReBase(player, unit);

    if (res < 0 ){ //negative means there was an error
        cout << "error moving: " << res << " " << movementErrorNames[res+abs(EMPTY_MEMO)] << endl;
    }

    else{
        auto& memo =  player.movement_memo;
        const auto& last_city = memo.back();

        last_city->addUnit(unit); 
        memo[0]->removeUnit(unit); 

        memo.clear();
        player.resetMovingUnit();


        fire_order[0]->acted = true;
        handleUnitActionEnd();
    }    
}

//&^ Movement
void Runner::moveUnit(Player& player){
    if (player.moving_units.size() > player.getCommandNumber())
        return; //moving more units then required

    constexpr bool unit_checked=0;
    constexpr bool can_move=1;
    bool unit_checks[2][CONVOY];

    const auto& memo = player.movement_memo;
    const auto& start_city = player.start_city;
    const auto& last_city = player.movement_memo.back();

    for (auto& a : unit_checks)
        for (auto& b : a)
            b = false;

    bool disengaging = start_city->hasOther(player);

    bool landfall = false;
    bool turn_convoy = false;

    int num_ground = 0;
    int border_increases = 0;

    if (player.moving_units.empty() || player.movement_memo.empty())
        return;

    if (player.start_city->isConflict()){ //set flag if the units are disengaging
        disengaging = true;
    } 

    //go through each unit and check for errors and set flags 
    for (const auto& unit : player.moving_units){
        num_ground += unit->class_type == CLASS_G;

        if (unit_checks[unit_checked][unit->unit_type] && unit_checks[can_move][unit->unit_type]){ //use this to skip the same check
            border_increases += (unit->class_type == CLASS_G && (disengaging || last_city->hasOther(player.getAllegiance())));
            continue;
        }

        MovementMessage res;
        if (disengaging){
            res = canDisengage(player, unit);
        }
        else{
            switch (unit->class_type){
                case CLASS_A:
                    res = canAirMove(player, unit);
                    break;
                case CLASS_G:
                    res = (unit->convoy)? canSeaMove(player, unit) : canLandMove(player, unit);
                    break;
                case CLASS_S:
                    res = canSeaMove(player, unit);
                    break;
                case CLASS_N:
                    res = canSeaMove(player, unit);
                    break;

                default:
                    exit(1);
            }
        }

        if (res < 0 ){ //negative means there was an error
            cout << "error moving: " << movementErrorNames[res+abs(EMPTY_MEMO)] << endl;
            return;
        }

        else if (res == DOWED){ //need to get confirmation that its okay to DoW
            cout << "need a dow to enter " << player.movement_memo.back()->name << endl; 
            return;
        }

        else if (res == VONED){ //need to get confirmation that its okay to VoN
            cout << "need a von to enter " << player.movement_memo.back()->name << endl; 
            return;
        }

        else{
            if (res == LANDFALL)
                landfall = true;

            if (res == TURN_CONVOY)
                turn_convoy = true;

            border_increases += (unit->class_type == CLASS_G && (disengaging || last_city->hasOther(player.getAllegiance())));

            unit_checks[unit_checked][unit->unit_type] = true;
            unit_checks[can_move][unit->unit_type] = true;

        }
    }

    if (disengaging){
        if (BORDER_LIMITS[map.getBorder(memo[0], memo[1])] < map.getBorderLimit(memo[0], memo[1], player) + border_increases){
            cout << "Disengage Border limit violation" << endl;
            return;
        }
        map.increaseBorderLimit(memo[0], memo[1], player.getAllegiance(), border_increases);
    }
    else{
        if (BORDER_LIMITS[map.getBorder(memo[memo.size()-2], last_city)] < map.getBorderLimit(memo[memo.size()-2], last_city, player) + border_increases){
            cout << "Engage Border limit violation" << endl;
            return;
        }

        map.increaseBorderLimit(memo[memo.size()-2], last_city, player.getAllegiance(), border_increases);
    }

    int battlegroup = 0;
    if (num_ground == 0 && last_city->start_allegiance == WATER && last_city->hasOther(player)){
        battlegroup = player.num_battle_groups++;
    }

    //if reached here then can move units
    for (const auto& unit : player.moving_units){
        last_city->addUnit(unit);
        start_city->removeUnit(unit);
        unit->acted = true;

        if (landfall && unit->class_type == CLASS_G){
            unit->convoy = false;
            unit->landing = year;
        }

        if (turn_convoy && unit->class_type == CLASS_G){
            unit->convoy = true;
        }

        if (battlegroup){
            unit->battle_group = battlegroup;
            unit->landing = year; //will be doubled as the year when the battle group first engaged and will be forced to engage
        }
    }

    player.useCommand(player.moving_units.size());
    player.resetMovingUnit();

    //TODO add private message feature
}

void Runner::selectRetreat(Player& player){
    if (player.a_held_tick == 0)
        ;

    if (player.closest_map_city != nullptr){
        player.movement_memo[1] = player.closest_map_city;
    }
}

void Runner::addMovement(Player& player){
    if (!player.a_held_tick)
        return;
    const auto& pot_unit = player.selected_unit.second;
    auto& pot_city = player.selected_unit.first;
    auto& memo =  player.movement_memo;

    if (pot_unit){ //handle adding units
        if (pot_unit->allegiance != player)
            return;

        if (!player.inMove(pot_unit)){ //if not in the movement memo then check if its in a different city and to move it
            if (pot_city != player.start_city){ //if the city of the unit isn't the previous group then 
                player.resetMovingUnit();

                player.start_city = pot_city;
                player.option_select_city = pot_city;
                player.moving_units.push_back(pot_unit);
                memo.push_back(pot_city);
                pot_unit->moving = true;
            }
            else{ //simply add to the units that will be moving
                player.moving_units.push_back(pot_unit);
                pot_unit->moving = true;
            }
        }
        else{ //remove it from the group
            player.moving_units.erase(std::find(player.moving_units.begin(), player.moving_units.end(), pot_unit));
            pot_unit->moving = false;

            if (player.moving_units.empty())
                player.resetMovingUnit();
        }

        return;
    }

    pot_city = player.closest_map_city;

    if (pot_city){
        if (pot_city == player.start_city){ //if the city is the start clean memo and restart
            memo.erase(player.movement_memo.begin()+1, player.movement_memo.end());
            return;
        }

        const auto& result = find(memo.begin(), memo.end(), pot_city);
        if (result != memo.end()){ // if its in the memo then truncate
            memo.erase(result, memo.end());
        }

        else if (!memo.empty() && map.getBorder(memo.back(), pot_city)){ //if its not in and the city is connected at all (not specific just if its connected)
            memo.push_back(pot_city);
        }
    }
}

void Runner::addReBase(Player& player){
    if (player.a_held_tick == 0)
        return;

    //adding another stop
    if (player.closest_map_city != nullptr){
        const auto& index = std::find(player.movement_memo.begin(), player.movement_memo.end(), player.closest_map_city);
        auto& memo = player.movement_memo;

        if (index == memo.begin()){ //if selected the first one then reset 
            memo.clear();
            memo.push_back(player.closest_map_city);
        }
        else if (index == player.movement_memo.end()){ //if not in then check if its added
            memo.push_back(player.closest_map_city);
        }
        else{ //if its already in the memo then truncate everything past 
            memo.erase(index,memo.end());
        }
    }
}

MovementMessage Runner::canLandMove(const Player& player, const Unit* unit) const{
    if (player.getCommandNumber() <= 0){
        return NO_COMMAND;
    }

    if (unit->acted){
        return TIRED;
    }

    const auto& memo = player.movement_memo;

    if (memo.size() <= 1)
        return EMPTY_MEMO;

    const City* last_city = memo.back();

    const bool emergencied = player.usedEmergency();

    const auto& allegiance = player.getAllegiance();

    bool strategic = true;

    MovementMessage m_m = NO_EFFECT;

    // Lambda Function to check if the player would violate any movement restrictions 
    auto checkBorderLimits = [&](const City* start_c, const City* end_c) {
        //cout << "checked " << start_c->name << " " << end_c->name << " for " << BORDER_LIMITS[map.getBorder(start_c, end_c)] << " and found " << (int)map.getBorderLimit(start_c, end_c, player.getAllegiance()) << endl;
        return BORDER_LIMITS[map.getBorder(start_c, end_c)] > map.getBorderLimit(start_c, end_c, player.getAllegiance());
    };

    auto checkEngagement = [&](const City* start_c, const City* end_c){
        // If the end has enemies it would be an engagement
        if (end_c->hasOther(allegiance)) {
            // If going into a city with enemy units it MUST stop movement
            if (end_c != last_city)
                return ENGAGE_NOT_LAST;

            // If already fighting then is a reinfercoment (can happen when emergencied)
            if (end_c->isFighting(allegiance)){
                if (!checkBorderLimits(start_c, end_c))
                    return BORDER_LIMIT;
            }
            // If the player isn't there then its a 'new' engagement
            else {
                if (emergencied)
                    return EMERGENCY_ENGAGE;
                if (!checkBorderLimits(start_c, end_c))
                    return BORDER_LIMIT;
            }
        }
        // If empty then go ahead and occupy

        return NO_EFFECT;
    };

    // Check connections between each cities
    for (int i = 0; i < memo.size()-1; i++){
        const City* start = memo[i];
        const City* end   = memo[i+1];

        const CityType& ruler_type = end->ruler_allegiance;

        // Check if they are connected
        if (!isLand(map.getAdjacency()[start->ID][end->ID])){
            return NOT_CONNECTED;
        }

        // If end is rival owned then check for DoW
        if (player != ruler_type && ruler_type != NEUTRAL && !player.isEnemy(ruler_type)) {
            m_m = DOWED;
        }

        // If end is neutral owned then check if they are armed and if VoN is needed
        if (NEUTRAL == ruler_type && !map.getCountry(end->country)->armed_minor) {
            m_m = VONED;
        }

        if (ruler_type != allegiance){
            strategic = false;
        }

        // If there's an enemy in end then check engagement
        const auto res = checkEngagement(start, end);
        if (res < 0)
            return res;
    }

    // Check if the unit has movement left to make all moves
    if (memo.size()-1 > unit->movement*((strategic)?2:1)){
        return TOO_FAR;
    }

    if (m_m == NO_EFFECT && last_city->hasOther(allegiance)){
        m_m = ENGAGING;
    }

    return m_m;
}

MovementMessage Runner::canSeaMove(const Player& player, const Unit* unit) const{
    if (player.getCommandNumber() <= 0){
        return NO_COMMAND;
    }

    if (unit->acted){
        return TIRED;
    }

    const auto& memo = player.movement_memo;

    if (memo.size() <= 1)
        return EMPTY_MEMO;

    const City* last_city = memo.back();

    const bool emergencied = player.usedEmergency();

    const auto& allegiance = player.getAllegiance();

    bool strategic = true;
    int deep = 0;

    MovementMessage m_m = NO_EFFECT;

    auto checkBorderLimits = [&](const City* start_c, const City* end_c) {
        //cout << "checked " << start_c->name << " " << end_c->name << " for " << BORDER_LIMITS[map.getBorder(start_c, end_c)] << " and found " << (int)map.getBorderLimit(start_c, end_c, player.getAllegiance()) << endl;
        return BORDER_LIMITS[map.getBorder(start_c, end_c)] > map.getBorderLimit(start_c, end_c, player.getAllegiance());
    };

    auto checkEngagement = [&](const City* start_c, const City* end_c){
        // If the end has enemies it would be an engagement
        if (end_c->hasOther(allegiance)){
            if (unit->convoy && end_c->start_allegiance == WATER)
                return CONVOY_ENGAGE_AT_SEA;
            // If going into a city with enemy units it MUST stop movement
            if (end_c != last_city)
                return ENGAGE_NOT_LAST;

            // If already fighting then is a reinfercoment (can happen when emergencied)
            if (end_c->isFighting(allegiance)){
                if (unit->convoy && !checkBorderLimits(start_c, end_c))
                    return BORDER_LIMIT;
            }
            // If the player isn't there then its a 'new' engagement
            else {
                if (emergencied)
                    return EMERGENCY_ENGAGE;
                if (unit->convoy && !checkBorderLimits(start_c, end_c))
                    return BORDER_LIMIT;
            }
        }

        return NO_EFFECT;
    };

    // Check connections between each cities
    for (int i = 0; i < memo.size()-1; i++){
        const City* start = memo[i];
        const City* end   = memo[i+1];

        const CityType& ruler_type = end->ruler_allegiance;

        // Check if they are connected
        if (!isNaval(map.getAdjacency()[start->ID][end->ID])){
            return NOT_CONNECTED;
        }

        deep += end->deep;

        // If entering a coast they must stop and check if it warrants an attack
        if (map.getAdjacency()[start->ID][end->ID] == COAST && end->start_allegiance != WATER){
            if (end != last_city)
                return PAST_COAST;
            
            if (player != ruler_type && ruler_type != NEUTRAL && !player.isEnemy(ruler_type)) {
                return DOWED;
            }

            // If end is neutral owned then check if they are armed and if VoN is needed
            if (NEUTRAL == ruler_type && !map.getCountry(end->country)->armed_minor) {
                return VONED;
            }
                
            m_m = LANDFALL;
        }

        if (ruler_type != allegiance && ruler_type != WATER){
            strategic = false;
        }

        const auto res = checkEngagement(start, end);
        if (res < 0)
            return res;
    }

    // Check if the unit has movement left to make all moves
    if (memo.size()-1+deep > (unit->convoy? CONVOY_MOVEMENT: (unit->movement))*((strategic)?2:1)){
        return TIRED;
    }

    //? ANS units are prohibited from Raiding unoccupied Enemy Territory, except to do Strategic Bombing (see 12.62)
    //todo add raid check
    if (last_city->start_allegiance != WATER && last_city->ruler_allegiance != allegiance && !last_city->hasOther(allegiance) && unit->class_type != CLASS_G){
        return RAID_UNOCCUPIED;
    }

    if (m_m == NO_EFFECT && last_city->hasOther(allegiance)){
        m_m = ENGAGING;
    }

    return m_m;
}

MovementMessage Runner::canAirMove(const Player& player, const Unit* unit) const{
    if (player.getCommandNumber() <= 0){
        return NO_COMMAND;
    }

    if (unit->acted)
        return TIRED;

    const auto& memo = player.movement_memo;

    if (memo.size() <= 1)
        return EMPTY_MEMO;

    const City* last_city = memo.back();

    const bool emergencied = player.usedEmergency();

    const auto& allegiance = player.getAllegiance();

    bool strategic = true;

    // Check connections between each cities
    for (int i = 0; i < memo.size()-1; i++){
        const City* start = memo[i];
        const City* end   = memo[i+1];

        // Since air can move over all spaces wihtout border limit then check connection
        if (!isAir(map.getAdjacency()[start->ID][end->ID])){
            return NOT_CONNECTED;
        }

        // Check if VoN is needed to enter
        if (end->ruler_allegiance == NEUTRAL && !map.getCountry(end->country)->armed_minor){
            return VONED;
        }

        // Check if DoW is needed to enter
        if (end->ruler_allegiance != NEUTRAL && end->ruler_allegiance != allegiance && !player.isEnemy(end->ruler_allegiance))
            return DOWED;

        //check if in friendly territory
        if (end->ruler_allegiance != allegiance && end->ruler_allegiance != WATER){
            strategic = false;
        }

    }
    // Check if the unit has movement left to make all moves (if in friendly can double movement)
    if (memo.size()-1 > unit->movement*((strategic)?2:1)){
        return TOO_FAR;
    }

    // Can move through enemies but check the last one if its engaging with emergency restrictions
    if (last_city->hasRival(allegiance)){ //if there's a rival
        for (int i = WEST; i < USSR; i++){
            const auto& res = player.getDoW((CityType)i);
            if (res != PEACE && last_city->isFighting(allegiance) && emergencied)
                return EMERGENCY_ENGAGE;
        }
    }

    else if (last_city->ruler_allegiance == NEUTRAL && !last_city->isFighting(allegiance) && emergencied){ //stopping in a neutral city would reqquire a VoN
        return EMERGENCY_ENGAGE;
    }

    //? ANS units are prohibited from Raiding unoccupied Enemy Territory, except to do Strategic Bombing (see 12.62)
    //todo add raid check
    if (last_city->start_allegiance != WATER && last_city->ruler_allegiance != allegiance && !last_city->hasOther(allegiance)){
        return RAID_UNOCCUPIED;
    }

    if (!unit->acted && memo[0]->start_allegiance == WATER && last_city->start_allegiance == WATER){ //if its there first move and they're in the water must make it to land
        return AIR_OVER_WATER;
    }

    return last_city->hasOther(allegiance)? ENGAGING : NO_EFFECT;
}

MovementMessage Runner::canDisengage(const Player& player, const Unit* unit) const{
    if (player.getCommandNumber() <= 0){
        return NO_COMMAND;
    }

    if (unit->acted){
        return TIRED;
    }

    auto checkLand = [&](const BorderType& b){return isLand(b);};
    auto checkNaval = [&](const BorderType& b){return isNaval(b);};
    auto checkAir = [&](const BorderType& b){return isAir(b);};

    std::function<bool(const BorderType&)> borderCheck;
    switch (unit->class_type){
        case CLASS_A:
            borderCheck = checkAir;
            break;
        case CLASS_G:
            borderCheck = unit->convoy ? std::function<bool(const BorderType&)>(checkNaval) : std::function<bool(const BorderType&)>(checkLand);
            break;
        case CLASS_S:
            borderCheck = checkNaval;
            break;
        case CLASS_N:
            borderCheck = checkNaval;
            break;

        default:
            exit(1);
    }


    const auto& memo = player.movement_memo;

    if (memo.size() <= 1)
        return EMPTY_MEMO;

    const City* last_city = memo.back();

    const auto& allegiance = player.getAllegiance();

    const bool landStop = unit->convoy || unit->class_type == CLASS_N || unit->class_type == CLASS_S;

    if (last_city->hasOther(player)) //last city can't be an engage for any unit type
        return DISENGAGE_ENGAGE;

    if (BORDER_LIMITS[map.getBorder(memo[0], memo[1])] <= map.getBorderLimit(memo[0], memo[1], player.getAllegiance())){ //todo check if border limits apply for disengage
        return BORDER_LIMIT;
    }

    //auto landMove
    for (int i = 0; i < memo.size()-1; i++){
        const City* start = memo[i];
        const City* end   = memo[i+1];

        const CityType& ruler_type = end->ruler_allegiance;

        if (!borderCheck(map.getBorder(start, end))){
            return NOT_CONNECTED;
        }

        if (unit->class_type != CLASS_S && unit->class_type != CLASS_A && (!isFriendly(allegiance, ruler_type) || end->isConflict())){ //can only go through friendly areas (including open seas) (unless a sub or air)
            return DISENGAGE_ENGAGE;
        }

        //for NS Units make sure if landfall they stop immediatly
        if (landStop && map.getBorder(start, end) == COAST && end->start_allegiance != WATER && last_city != end){
            return PAST_COAST;
        }
    }

    if (memo.size()-1 > unit->movement){
        return TOO_FAR;
    }

    if (landStop && last_city->start_allegiance != WATER)
        return LANDFALL;

    return NO_EFFECT;
}

MovementMessage Runner::canRetreat(const Player& player, const Unit* unit) const{
    if (player.combat_phase != COMBAT_SELECT_RETREAT)
        return EMPTY_MEMO;

    const auto& memo = player.movement_memo;

    if (memo.size() <= 1)
        return EMPTY_MEMO;

    if (memo.size() > 2) //should only be the start and an adjacent
        return TOO_FAR;

    const auto& start = memo[0];
    const auto& end = memo[1];

    const auto& border = map.getBorder(start, end);
    //make sure connected
    if (!border)
        return NOT_CONNECTED;

    if (unit->class_type == CLASS_N && !isNaval(border))
        return PAST_COAST;

    //needs to abide by border limits
    const auto& border_limit = map.getBorderLimit(start, end, player);
    if (unit->class_type == CLASS_G && border_limit >= BORDER_LIMITS[border])
        return BORDER_LIMIT;

    //(a)
    if (!isFriendly(unit->allegiance, end->ruler_allegiance)){
        return NOT_FRIENDLY;
    }

    //(b)
    if (end->battling == year)
        return DISENGAGE_RETREAT;

    //(c)
    if (player != current_player && border_limit){ //if there is a border limit from the attacker it means they engaged from there
        return RETREAT_INTO_ENGAGER;
    }

    //(d)
    else if (player == current_player && end->ID != unit->engage_id && unit->last_engage == year){ // like (c) but if the border limit doesn't exist then it means they didn't engaged from there
        return RETREAT_INTO_NEW;
    }

    //(e)
    if (unit->class_type == CLASS_G && !unit->convoy && end->start_allegiance == WATER){
        return (end->hasOther(player))? RETREAT_TO_WATER : TURN_CONVOY;
    }

    return end->hasOther(player)? RETREAT_TO_DISPUTED : NO_EFFECT;

    /*Units cannot Retreat into:
    (a) Enemy, Rival, or Neutral areas (Open
    Seas OK),
    (b) Areas that contained Battles (other
    than Raids) that Player Turn [Raids do
    not block Retreats],
    (c) [Defenders only] Areas from which
    the Enemy Engaged them that Player
    Turn,
    (d) [Attackers only] Any area other than
    the one from which they Engaged into
    the Battle, if they Engaged that Turn,
    (e) [Ground units only] Sea Areas, unless
    they are Friendly-occupied. */
}

MovementMessage Runner::canReBase(const Player& player, const Unit* unit) const{
    auto checkNaval = [&](const BorderType& b){return isNaval(b);};
    auto checkAir = [&](const BorderType& b){return isAir(b);};

    std::function<bool(const BorderType&)> borderCheck;
    switch (unit->class_type){
        case CLASS_A:
            borderCheck = checkAir;
            break;
        case CLASS_S:
            borderCheck = checkNaval;
            break;
        case CLASS_N:
            borderCheck = checkNaval;
            break;

        default:
            exit(1);
    }


    const auto& memo = player.movement_memo;

    if (memo.size() <= 1)
        return EMPTY_MEMO;

    const City* last_city = memo.back();

    const auto& allegiance = player.getAllegiance();

    const bool landStop = unit->convoy || unit->class_type == CLASS_N || unit->class_type == CLASS_S;

    if (last_city->isConflict()) //last city can't be an engage for any unit type
        return REBASE_DISPUTED;

    //auto landMove
    for (int i = 0; i < memo.size()-1; i++){
        const City* start = memo[i];
        const City* end   = memo[i+1];

        const CityType& ruler_type = end->occupier_allegiance;

        if (!borderCheck(map.getBorder(start, end))){
            return NOT_CONNECTED;
        }

        if (unit->class_type != CLASS_S && unit->class_type != CLASS_A && (!isFriendly(allegiance, ruler_type) || end->isConflict())){ //can only go through friendly areas (including open seas) (unless a sub or air)
            return DISENGAGE_ENGAGE;
        }

        //for NS Units make sure if landfall they stop immediatly
        if (landStop && map.getBorder(start, end) == COAST && end->start_allegiance != WATER && last_city != end){
            return PAST_COAST;
        }
    }

    if (memo.size()-1 > unit->movement){
        return TOO_FAR;
    }

    return ((last_city->occupier_allegiance == player || (last_city->start_allegiance == WATER && !last_city->hasOther(allegiance))) && !last_city->isConflict())? NO_EFFECT : NOT_FRIENDLY;
}

//& Diplomacy

void Runner::updateCityRulers(){
    for (const auto& city_pair : map.getCities()){

        auto& city = city_pair.second;

        if (city->num_occupiers && city->occupants[city->ruler_allegiance].empty()){ //if there are occupiers then the one there the longest becomes the main occupier
            int min_priority = 999;
            CityType new_ruler=NULL_ALLEGIANCE;

            //get the longest occupier
            city->occupier_priority[NEUTRAL]=0;
            for (int i = 0; i < 4; i++){
                if (city->occupier_priority[i] != 0 && city->occupier_priority[i] < min_priority){ //the != 0 signafies not an occupier (ruler or not there)
                    new_ruler = (CityType)(i);
                    min_priority = city->occupier_priority[i];
                }
            }

            if (city->start_allegiance != WATER && city->capital){ //if the city is a capital then they rule all of the cities in the country
                map.getCountry(city->country)->conqueredCapital(new_ruler);
                for (auto& unit : city->occupants[NEUTRAL]){
                    neutral_units.erase(find(neutral_units.begin(), neutral_units.end(), unit));
                }
                city->occupants[NEUTRAL].clear();
            }
            else{
                city->occupier_allegiance = new_ruler;
            }

        }    
        else{ //if no occupiers then revert to capital's ruler
            const CityType& capital_allegiance = (city->start_allegiance != WATER)? map.getCountry(city->country)->allegiance : WATER;
            city->ruler_allegiance = capital_allegiance;
            city->occupier_allegiance = capital_allegiance;
        }

    }

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
