#pragma once

#include "Player.h"

/**
 * @brief Since controllers can have stick drift, it will flood the SDL_PollEvent Queue with joystick moves and delay user inputs. 
 * The filter will only allow significant movements to be placed in queue
 * 
 * @param userdata ???
 * @param event The event picked up
 * @return int 1: if the event should be recorded 0: if to be ignored
 */
static int SDLCALL event_filter(void* userdata, SDL_Event* event) {
    if (event->type == SDL_JOYAXISMOTION) {
        /*int value = event->jaxis.value;
        // Apply deadzone filtering
        if (value > -JOYSTICK_DEADZONE && value < JOYSTICK_DEADZONE) {
            return false; // Filter out this event
        }*/
       return false;
    }

    // Allow other events to pass through
    return true;
}

class PublicAnimation{
public:
    //Which animation
    SeasonAnimation which;

    // Position of the sprite in the spritesheet
    Target sprite_postion;

    uint random;

    int value1;

    //Position of animation
    int screen_x;
    int screen_y;

    int scale;

    uint8_t alpha=255;


    //Sprite Translations
    int sprite_off_x=0;
    int sprite_off_y=0;

    //Duration
    tick_t start;
    tick_t tpu=0;
    tick_t last_upadate=0;

    //Calls when done
    using Callback = std::function<void()>;

    Callback on_finish;


    //Collection of phases
    vector<pair<AnimationPhase,  tick_t>> phases;

    PublicAnimation(const SeasonAnimation& which, const int& x_side, const int& y_bottom, const int& sprite_x, const int& sprite_y, const int& width, const int& height, const int& scale, const tick_t& start, const tick_t& tpu):which(which), screen_x(x_side), screen_y(y_bottom), scale(scale), start(start), tpu(tpu){
        sprite_postion = {sprite_x, sprite_y, width, height};
        last_upadate = start;
        random = (rand()%start)*1000;
    }

    void addPhase(const AnimationPhase a_phase, const tick_t duration){
        phases.push_back({a_phase, duration});
    }

    void setRandom(const int& num_sprites){
        value1 = num_sprites;
    }

    void setFinishCallback(Callback callback) {
        on_finish = callback;
    }

    /**
     * @brief 
     * 
     * @param player 
     * @param clock 
     * @return true There is no more to the animations
     * @return false Animation should continue
     */
    void animate(const Player& player, const tick_t& clock){
        Target temp_target = {(screen_x < 0)? player.app->screen.WIDTH/2+screen_x : screen_x, (screen_y < 0)? player.app->screen.HEIGHT+screen_y : screen_y, sprite_postion.w*scale, sprite_postion.h*scale};
        
        //translations for effects

        if (clock-last_upadate >= tpu){
            last_upadate = clock;
            switch (phases[0].first){
                case AnimationPhase::STILL:
                    //do nothing just show the image!
                    break;
                case AnimationPhase::SHAKE_X:
                    //offset the x val by a sin function
                    temp_target.x += 5*((sin(1/600.0)*clock+random));
                    break;
                case AnimationPhase::SHAKE_Y:
                    temp_target.y += 5*((cos(1/600.0)*clock+random));
                    break;
                case AnimationPhase::SHAKE_ALL:
                    temp_target.x += 5*((sin(1/600.0)*clock+random));
                    temp_target.y += 5*((cos(1/600.0)*clock+random));
                    break;
                case AnimationPhase::FADE_IN:
                
                    break;
                case AnimationPhase::FADE_OUT:

                    break;
                case AnimationPhase::FLICKER:
                    alpha = alpha == 255? 0 : 255;
                    break;
                case AnimationPhase::RANDOM:
                    sprite_off_x = (rand()%value1)*sprite_postion.w;
                    break;
                default:
                    break;
            }
        }
        
        player.sprite_sheet->drawArea(&temp_target, sprite_postion.x+sprite_off_x, sprite_postion.y+sprite_off_y, sprite_postion.w, sprite_postion.h, alpha);
    }

    bool updateNext(const tick_t& clock){
        if (pastWait(start, clock, phases[0].second)){
            phases.erase(phases.begin());

            if (!phases.empty()){
                if (phases[0].first == AnimationPhase::FLICKER)
                    tpu = 500;

                start = clock;
                return false;
            }

            if (on_finish)
                on_finish(); //call funciton on finish when it will be deleted

            return true;
        }

        return false;
    }


    inline SeasonAnimation getWhich(){
        return which;
    }
};

/**
 * @brief The main controller of the game and controls sequence of play
 * 
 */
class Runner{
private:
    int num_players; /**< Number of player in game (3 but hopefully can make a 1)*/

    Player* west_player; /**< Pointer to the Player Obj that represents the West player */

    Player* axis_player; /**< Pointer to the Player Obj that represents the Axis player */

    Player* ussr_player; /**< Pointer to the Player Obj that represents the USSR player */

    Player players[3]; /**Holds each playe object with allegiance as index 0: West 1: Axis 2: USSR*/ 

    Map map; /**< Map of the game and nations/waters*/

    year_t year; /**< Current year the player is in (goes from 1936 to 1945)*/

    year_t end_year; /**< Year the game will end (usually 1945)*/

    Season season=NEW_YEAR; /**< The current season being playes */

    Dice die; /**< Dice used to roll decisions, default a D6*/

    vector<ActionCard*> action_deck; /**< Draw deck of the action cards*/

    vector<ActionCard*> action_discard; /**< Draw deck of the action cards*/

    vector<InvestmentCard*> invest_deck; /**< Draw deck of the invest cards*/

    vector<InvestmentCard*> invest_discard; /**< Discard pile of investment cards*/

    vector<PeaceChit> peace_dividends_bag; /**< Holds all the unpulled peace dividends*/

    unordered_map<string, int> starting_cities; /**< Key:Name of city  Value:Number of units possible*/

    //& Combat and Battle Attributes
    vector<Unit*> neutral_units;

    vector<pair<City*, CityType>> battles; /**< Vector of the current battles the acting player is going to enact and which rival it'll be against */

    pair<City*, CityType> current_battle; /**< The current battle where battle actions are directed to */
    
    bool end_phase=false;

    CityType acting_player;
    
    CityType watching_player;

    UnitClass target_class=CLASS_NULL;

    vector<Unit*> fire_order; /**< Priority Queue for order of units acting in a battle */

    int action_bought = 0; /**< Number of actions card that have been purchaced by players for the production round*/

    int invest_bought = 0; /**< Number of investment card that have been purchaced by players for the production round*/

    Player* start_player; /**< Player who will start the turn*/

    Player* current_player; /**< The player's who current turn it is*/

    Player* turn_order[3]; /**< Array with the first player at 0 and the last player in the loop at 2*/
    Player* temp_order[3]; /**< Temporary order of players used for animating and will become the new turn order */

    int current_index = 0; /**< Index into the turn order array of the current player */

    const unsigned int seed = 872706816; /**< The set (or time set seed) for all randomness*/
    
    std::mt19937 g; /**< The random generator for shuffling*/

    App powers_app[3]; /**< The app (window, rendered, ect) of each player and their board*/

public:
    /**
     * @brief Construct a new Runner object that intializes the map and players
     * 
     * @param default_mode true if should go off of default or read in through the map
     */
    Runner(bool default_mode = true){
        if (InitApplication() == false){
            ShutdownApplication();
            exit(1);
        }

        //- Set random seed
        srand(seed);
        

        //- Init Dice
        die = Dice(1, 1); //dev change back to 1, 6 for chances of missing

        //- Set starting year
        year = START_YEAR;
        end_year = END_YEAR;
        year--;

        

        if (!default_mode){
            //setXY("./src/starter4.map");
            setResXY();
            exit(EXIT_SUCCESS);
        }

        //- Create Map
        initMap("./src/starter5.map");

        //- Create Cards
        initCards("./src/invest.card", "./src/action.card");

        start_player = &players[1]; //AXIS start
        
        //- Init Players
        players[0] = Player("Michael", WEST); //give 8 cards
        deal(&players[0], 8);
        players[1] = Player("Taiga", AXIS); //give 14 cards
        deal(&players[1], 14);
        players[2] = Player("Luke", USSR); //give 7 cards
        deal(&players[2], 7);

        
        mapPlayer(players[0]);
        mapPlayer(players[1]);
        mapPlayer(players[2]);
        
        std::mt19937 g(seed);

        peace_dividends_bag = {{2,0,0}, {2,0,0}, {2,0,0}, {2,0,0},
                               {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, 
                               {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}};
        shuffle(peace_dividends_bag.begin(), peace_dividends_bag.end(), g);
        
        string path = "./sprites/SpriteSheet0.png";

        const string path2 = "./sprites/MapSprite4.png";
        const string path3 = "./sprites/UnitSpritesZ1.png";
        const string path4 = "./sprites/UnitSpritesZ3.png";
        const string path6 = "./sprites/ControllerButtons.png";
        const string path7 = "./sprites/MessageAnimations.png";

        powers_sprite_map[0] = Spritesheet(path.c_str(), powers_app[0].renderer);
        players[WEST].sprite_sheet = &powers_sprite_map[0];
        powers_sprite_map[1] = Spritesheet(path.c_str(), powers_app[1].renderer);
        players[AXIS].sprite_sheet = &powers_sprite_map[1];
        powers_sprite_map[2] = Spritesheet(path.c_str(), powers_app[2].renderer);
        players[USSR].sprite_sheet = &powers_sprite_map[2];

        powers_map_sprite[0] = Spritesheet(path2.c_str(), powers_app[0].renderer);
        players[WEST].map_sprite = &powers_map_sprite[0];
        powers_map_sprite[1] = Spritesheet(path2.c_str(), powers_app[1].renderer);
        players[AXIS].map_sprite = &powers_map_sprite[1];
        powers_map_sprite[2] = Spritesheet(path2.c_str(), powers_app[2].renderer);
        players[USSR].map_sprite = &powers_map_sprite[2];

        powers_units_sprite_z1[0] = Spritesheet(path3.c_str(), powers_app[0].renderer);
        players[WEST].units_sprite_z1 = &powers_units_sprite_z1[0];
        powers_units_sprite_z1[1] = Spritesheet(path3.c_str(), powers_app[1].renderer);
        players[AXIS].units_sprite_z1 = &powers_units_sprite_z1[1];
        powers_units_sprite_z1[2] = Spritesheet(path3.c_str(), powers_app[2].renderer);
        players[USSR].units_sprite_z1 = &powers_units_sprite_z1[2];

        powers_units_sprite_z3[0] = Spritesheet(path4.c_str(), powers_app[0].renderer);
        players[WEST].units_sprite_z3 = &powers_units_sprite_z3[0];
        powers_units_sprite_z3[1] = Spritesheet(path4.c_str(), powers_app[1].renderer);
        players[AXIS].units_sprite_z3 = &powers_units_sprite_z3[1];
        powers_units_sprite_z3[2] = Spritesheet(path4.c_str(), powers_app[2].renderer);
        players[USSR].units_sprite_z3 = &powers_units_sprite_z3[2];

        powers_controller_button_sprite[0] = Spritesheet(path6.c_str(), powers_app[0].renderer);
        players[WEST].controller_button_sprites = &powers_controller_button_sprite[0];
        powers_controller_button_sprite[1] = Spritesheet(path6.c_str(), powers_app[1].renderer);
        players[AXIS].controller_button_sprites = &powers_controller_button_sprite[1];
        powers_controller_button_sprite[2] = Spritesheet(path6.c_str(), powers_app[2].renderer);
        players[USSR].controller_button_sprites = &powers_controller_button_sprite[2];

        powers_message_animations[0] = Spritesheet(path7.c_str(), powers_app[0].renderer);
        players[WEST].message_animation_sheets = &powers_message_animations[0];
        powers_message_animations[1] = Spritesheet(path7.c_str(), powers_app[1].renderer);
        players[AXIS].message_animation_sheets = &powers_message_animations[1];
        powers_message_animations[2] = Spritesheet(path7.c_str(), powers_app[2].renderer);
        players[USSR].message_animation_sheets = &powers_message_animations[2];


        west_player = &players[WEST];
        axis_player = &players[AXIS];
        ussr_player = &players[USSR];

        players[WEST].app = &powers_app[0];
        players[AXIS].app = &powers_app[1];
        players[USSR].app = &powers_app[2];

        //for handling stick drift
        SDL_SetEventFilter(event_filter, NULL);

        last_tick = SDL_GetTicks();
        

        players[0].cursor_x = players[0].app->screen.getX(map.getCapital("Britian")->x);
        players[0].cursor_y = players[0].app->screen.getY(map.getCapital("Britian")->y);
        players[0].closest_map_city = map.getCapital("Britian");

        players[2].cursor_x = players[2].app->screen.getX(map.getCapital("USSR")->x);
        players[2].cursor_y = players[2].app->screen.getY(map.getCapital("USSR")->y);
        players[2].closest_map_city = map.getCapital("USSR");

        players[1].cursor_x = players[1].app->screen.getX(map.getCapital("Germany")->x);
        players[1].cursor_y = players[1].app->screen.getX(map.getCapital("Germany")->y);
        players[1].closest_map_city = map.getCapital("Germany");

        players[0].calculateProduction();
        players[1].calculateProduction();
        players[2].calculateProduction();

        mapPlayerResPop(players[WEST]);
        mapPlayerResPop(players[AXIS]);
        mapPlayerResPop(players[USSR]);

        InitFonts();

        //initalize the cities that need to be initalized
        starting_cities["Berlin"] = 6;
        starting_cities["Ruhr"] = 4;
        starting_cities["Munich"] = 2;
        starting_cities["Könisberg"] = 2;
        starting_cities["Rome"] = 4;
        starting_cities["Milan"] = 2;
        starting_cities["Tripoli"] = 2;
        axis_player->num_start_units = 6+4+2+2+4+2+2;

        starting_cities["London"] = 3;
        starting_cities["Delhi"] = 2;
        starting_cities["Glasgow"] = 1;
        starting_cities["Bombay"] = 1;
        starting_cities["Suez"] = 1;
        starting_cities["Milan"] = 2;
        starting_cities["Tripoli"] = 2;
        west_player->num_start_units = 3+2+1+1+1+2+2;
        buildUnit(*west_player, map["London"], FLEET, 4);
        buildUnit(*west_player, map["Gibraltar"], FORTRESS);
        buildUnit(*west_player, map["Karachi"], INFANTRY);

        starting_cities["Paris"] = 2;
        starting_cities["Marseille"] = 1;
        starting_cities["Algiers"] = 1;
        west_player->num_start_units = 12;
        buildUnit(*west_player, map["Lorraine"], FORTRESS, 3);

        ussr_player->num_start_units = 3+2+2;
        //1 in each ussr city
        for (const auto& city : map.getCountry("USSR")->cities){
            starting_cities[city->name] = 1;
            ussr_player->num_start_units++;
        }
        starting_cities["Moscow"] = 3;
        starting_cities["Leningrad"] = 2;
        starting_cities["Baku,"] = 2;

        test();

        //6 4 3 2 1
    }

    size_t test(){
        //- Axis Setup
        buildCadre(players[AXIS], map["Berlin"], AIR);
        buildCadre(players[AXIS], map["Berlin"], INFANTRY);
        buildCadre(players[AXIS], map["Berlin"], INFANTRY);
        buildCadre(players[AXIS], map["Berlin"], FORTRESS);
        buildCadre(players[AXIS], map["Berlin"], TANK);
        buildCadre(players[AXIS], map["Berlin"], TANK);

        buildCadre(players[AXIS], map["Ruhr"], FLEET);
        buildCadre(players[AXIS], map["Ruhr"], INFANTRY);
        buildCadre(players[AXIS], map["Ruhr"], FORTRESS);
        buildCadre(players[AXIS], map["Ruhr"], AIR);

        buildCadre(players[AXIS], map["Munich"], INFANTRY);
        buildCadre(players[AXIS], map["Munich"], TANK);

        //for testing air movement
        //auto temp = new Unit(3, GERMANY_U, AIR, year);
        //axis_player->add(temp);
        //map["North_Sea"]->addUnit(temp);

        buildCadre(players[AXIS], map["Könisberg"], TANK);
        buildCadre(players[AXIS], map["Könisberg"], AIR);

        buildCadre(players[AXIS], map["Rome"], FORTRESS);
        buildCadre(players[AXIS], map["Rome"], TANK);
        buildCadre(players[AXIS], map["Rome"], FLEET);
        buildCadre(players[AXIS], map["Rome"], FLEET);

        buildCadre(players[AXIS], map["Milan"], FLEET);
        buildCadre(players[AXIS], map["Milan"], INFANTRY);

        buildCadre(players[AXIS], map["Tripoli"], TANK);
        buildCadre(players[AXIS], map["Tripoli"], TANK);

        for (int i  = 0; i < 2; i++){
            auto u2 = buildCadre(players[USSR], map["Berlin"], (UnitType)(FLEET));
            map["Berlin"]->removeUnit(u2);
            map["English_Channel"]->addUnit(u2);
        }

        auto u3 = buildCadre(players[USSR], map["Berlin"], (UnitType)(CARRIER));
        map["Berlin"]->removeUnit(u3);
        map["English_Channel"]->addUnit(u3);


        applyProduction(players[AXIS]);
        players[AXIS].passed = false;

        //- West Setup

        buildCadre(players[WEST], map["London"], TANK);
        buildCadre(players[WEST], map["London"], INFANTRY);
        buildCadre(players[WEST], map["London"], FORTRESS);

        buildCadre(players[WEST], map["Delhi"], FORTRESS);
        buildCadre(players[WEST], map["Delhi"], TANK);

        buildCadre(players[WEST], map["Glasgow"], AIR);

        buildCadre(players[WEST], map["Bombay"], FLEET);

        buildCadre(players[WEST], map["Suez"], CARRIER);

        buildCadre(players[WEST], map["Gibraltar"], FORTRESS);

        buildCadre(players[WEST], map["Karachi"], INFANTRY);

        buildCadre(players[WEST], map["Paris"], TANK);

        buildCadre(players[WEST], map["Gascony"], INFANTRY);

        buildCadre(players[WEST], map["Marseille"], AIR);

        buildCadre(players[WEST], map["Algiers"], FLEET);

        applyProduction(players[WEST]);
        players[WEST].passed = false;

        //- USSR Setup
        buildCadre(players[USSR], map["Moscow"], FORTRESS);
        buildCadre(players[USSR], map["Moscow"], INFANTRY);
        buildCadre(players[USSR], map["Moscow"], AIR);

        buildCadre(players[USSR], map["Leningrad"], FLEET);
        buildCadre(players[USSR], map["Leningrad"], FLEET);

        buildCadre(players[USSR], map["Baku"], FORTRESS);
        buildCadre(players[USSR], map["Baku"], INFANTRY);

        buildCadre(players[USSR], map["Kiev"], INFANTRY);

        buildCadre(players[USSR], map["Odessa"], INFANTRY);

        buildCadre(players[USSR], map["Kharkov"], TANK);

        buildCadre(players[USSR], map["Stalingrad"], TANK);

        buildCadre(players[USSR], map["Urals"], AIR);

        applyProduction(players[USSR]);
        players[USSR].passed = false;

        deal(west_player, 20, 'A');
        deal(west_player, 20, 'I');
        deal(axis_player, 6, 'I');

        map.getCountry("Greece")->setTest(WEST, 1);
        map.getCountry("Rumania")->setTest(WEST, 2);

        map.getCountry("Poland")->setTest(USSR, 1);
        map.getCountry("Bulgaria")->setTest(USSR, 1);
        map.getCountry("Baltic_States")->setTest(USSR, 2);
        map.getCountry("Finland")->setTest(USSR, 3);

        map.getCountry("Sweden")->setTest(AXIS, 1);
        map.getCountry("Norway")->setTest(AXIS, 2);
        map.getCountry("Turkey")->setTest(AXIS, 3);

        return 0;

    }

    /**
     * @brief Creates the game map including nations and cities and connections
     * 
     * @return true  Was able to succesfully make the map
     * @return false Encountered an error while making
     */
    bool initMap(string map_file);

    /**
     * @brief Creates the decks of cards
     * 
     * @return true 
     * @return false 
     */
    bool initCards(const string invest_file, const string action_file);

    //& Sequence of Play
    //- Round handler
    /**
     * @brief The main runner of the game loop
     * 
     * @return true The game is over with a winner
     * @return false The game is still going on 
     */
    bool run();

    /**
     * @brief The runner and handler for the title screen
     * 
     * @return true Able to run succesfully
     * @return false Encountered an error
     */
    bool runTitle();

    bool initUnits();

    //& New Year
    /**
     * @brief The first phase of the game loop where vicotry is checked, cards reshuffled, peace chits are distributed, USA influence, production, govenment phase occur
     * 
     * @see peaceDividends()
     * @see reshuffle()
     * @see newYearRes()
     * @see production()
     * @see government()
     * 
     * @return CityType  The player who won the game (CityType::Water if there is no winner)
     */
    CityType newYear();

    /**
     * @brief New Year phase where Cards in the discard piles will be added to both draw decks and then the whole deck will be reshuffled
     * 
     * @param animation Bool which will play the reshuffle animation if true
     */
    void reshuffle(const bool animation);
    
    /**
     * @brief All players who have been peacful (not DoW's or VoN in the past year) will recieve a random chit of 0, 1, or 2 VP's. This happens in the first year as well
     * 
     */
    void peaceDividends();

    /**
     * @brief New Year phase where the turn order of the players is decided for the following year. A D6 is rolled and depending on the number the strting player, and rotation is decided
     * 
     */
    void decideTurnOrder(const bool animation=false);

    /**
     * @brief In specific years 1 WEST influence will be added to the USA and if the USA is already a satellite then 
     * one of each unit will be automattically added to Washington and New York
     * 
     */
    void newYearRes();

    //- Production Phase
    /**
     * @brief Phase where players can spend there production (lowest of pop/res/ind) on buying cards, building cadres, and upgrading units. Runs on the turn order until all have gone through
     * 
     */
    void production();

    /**
     * @brief Once a player has passed, their choices in the production phase (card bought, cadres made, units upgraded) is finalized and applied
     * 
     * @param player The player who has passed and choices are applied
     */
    void applyProduction(Player& player);

    /**
     * @brief Deal a set amount of cards to the player of action or invest. Hand limit doesn't apply to card drawing. The player will draw up onto the amount or the number of cards remaining in the deck
     * 
     * @param player The player recieveing the cards
     * @param amount The amount of the card the player will recieve
     * @param state The type of card to deal 'A': action, 'I': invest
     * @return true The player was able to draw all cards
     * @return false The player wasn't able to draw all cards 
     */
    bool deal(Player* player, size_t amount, const char state='A');

    //- Government Phase
    /**
     * @brief Phase where players play action cards to add influence and play investment cards, goes in turn order until all have passed
     * 
     */
    void government();

    /**
     * @brief Handler for the player playing an action card to add influence to a country on an action card (assuming the player has a valid card with the country)
     * 
     * @param player The player adding the influence
     * @param country The country thats is having influence added to
     * @return true The player was able to add influence to the country and the card was removed
     * @return false The player was unable to add influence to the country
     */
    bool addDiplomacy(Player& player, Country* country);

    /**
     * @brief Initiates diplomacy resolutions at the end of the goverment phase, changing the influence level of the country and changing the population
     * 
     */
    void resolveDiplomacy();

    /**
     * @brief Handler for increasing the player's industry and removing the cards used for doing so
     * @see canIncreaseIND
     * 
     * @param player The player who is attempting to raise their industry
     * @return true Player was able to raise their industry and cards were removed
     * @return false Player was unable to raise their industry
     */
    bool increaseIndustry(Player& player);

    /**
     * @brief Decider for if the player can combine the two selected techs to achieve a new technology (also handles year cards)
     * 
     * @param player The player attempting to pair the techs
     * @param tech1 The first tech selected
     * @param tech2 The second tech selected
     * @return true Player is able to pair the two techs
     * @return false Player is unable to pair the two techs (already achieved or not the same)
     */
    bool canPair(const Player& player, const Tech* tech1, const Tech* tech2) const;

    /**
     * @brief Decider for if the player is able to coup on the current country selected 
     * 
     * @param player Player who is attempting to coup
     * @return true Player is able to coup at the current country with the correct selected card
     * @return false Player is unable to coup at the current country
     */
    bool canCoup(Player& player){
        return player.selected_tech1 != nullptr && *player.selected_tech1 == COUP 
            && player.closest_map_city != nullptr && map.getCapital(player.closest_map_city->country) == player.closest_map_city
            && player != (int)map.getCountry(player.closest_map_city->country)->allegiance  &&   map.getCountry(player.closest_map_city->country)->influence > 0;
    }

    /**
     * @brief Handler for couping (removing a rival's influence) 
     * @see canCoup
     * 
     * @param player 
     * @pre The Player is able to coup at the current selected country
     */
    void coup(Player& player){
        map.getCountry(player.closest_map_city->country)->resetDiplomacy();
        
        player.popped_invest_card->selected = false;
        player.remove(player.popped_invest_card);
        player.updatePoppedInvestCard();
    }

    /**
     * @brief Decider for if the play can sabotage (lower a rival's IND) the current selected rival
     * 
     * @param player Player who is attempting to sabotage
     * @return true Player would be able to sabotage the selected rival
     * @return false Player would be unable to sabotage a rival
     */
    inline bool canSabotage(Player& player){
        return player.selected_tech1 != nullptr && *player.selected_tech1 == SABOTAGE &&
               player != player.stat_view && players[player.stat_view].getIndustry() > 0;
    }

    /**
     * @brief Handler for sabotaging (lower a rival's IND) a rival and removing the card responsible
     * @see canSabotage 
     * 
     * @param player Player who is sabotaging a rival
     * @pre Player is able to sabotage the current selected rival
     */
    void sabotage(Player& player){
        players[player.stat_view].lowerIND();
        player.remove(player.popped_invest_card);
        player.updatePoppedInvestCard();
    }

    /**
     * @brief Decider for if the player can use a Spy Ring (take a random card from a Rival)
     * 
     * @param player Player attempting to use a Spy Ring
     * @return true Player is able to use Spy Ring against the selcted Rival
     * @return false Player is unable to use Spy Ring against a Rival
     */
    inline bool canSpyRing(Player& player){
        return player.selected_tech1 != nullptr && *player.selected_tech1 == SPY_RING &&
               player != player.stat_view && players[player.stat_view].getActionSize()+players[player.stat_view].getInvestSize() > 0;
    }

    /**
     * @brief Handler for using Spy Ring (take a random card from a rival)and removing the card responsible
     * @see canSpyRing
     * 
     * @param player Player who is playing the Spy Ring card
     * @pre Player is able to use Spy Ring
     */
    void spyRing(Player& player){
        //Random as either an industry card or action card
        auto& target = players[player.stat_view];
        if (rand()%2){ //invest
            InvestmentCard* stolen = target.getInvestCard(rand()%target.getInvestSize());
            player.deal(stolen);
            target.remove(stolen);
        }
        else{ // action
            ActionCard* stolen = target.getActionCard(rand()%target.getActionSize());
            player.deal(stolen);
            target.remove(stolen);
        }

        player.remove(player.popped_invest_card);
        player.updatePoppedInvestCard();
    }

    bool canWildAction(Player& player);

    bool handleIsolationism(Player& player);

    bool handleForeignAid(Player& player);

    bool handleGuarantee(Player& player);

    bool handleIntimidation(Player& player);

    bool handleBirdsOfAFeather(Player& player);

    bool handleTiesThatBind(Player& player);

    bool handleFearAndLoathing(Player& player);

    bool handleVersailles(Player& player);

    bool handleEthnicTies(Player& player);

    bool handleBrothersInArms(Player& player);

    /**
     * @brief TODO check players hand size
     * 
     */
    void checkHands();

    //& Seasons of War

    /**
     * @brief Sort the turn order of the players based on their played command cards (season->command priority->command value->random)
     * 
     */
    void sortCommand();

    /**
     * @brief Comparator for two Action Cards to see which has priority for command
     * 
     * @param lhs The left action card
     * @param rhs The right action card
     * @return true LHS has a higher priority
     * @return false RHS has a higher priority
     */
    bool compareCards(const ActionCard* lhs, const ActionCard* rhs);

    /**
     * @brief Handler for adding the current selected city to the player's movement memo (or removing)
     * 
     * @param player Player who is currently in their movement phase
     */
    void addMovement(Player& player);

    void selectRetreat(Player& player);

    void addReBase(Player& player);

    /**
     * @brief Set which Rivals/Minors are able to be attacked in the currently selected city
     * 
     * @param attacker Player who is currently selecting battles to enact
     */
    bool setDefenders(Player& attacker){
        auto& memo = attacker.unit_available;
        const auto& target_city = attacker.option_select_city;
        const CityType& allegiance = attacker;

        if (target_city->occupants[allegiance].empty()){
            return false;
        }

        memo[WEST] = target_city->occupants[WEST].size() && WEST!=allegiance; 

        memo[AXIS] = target_city->occupants[AXIS].size() && AXIS!=allegiance; 

        memo[USSR] = target_city->occupants[USSR].size() && USSR!=allegiance; 

        memo[NEUTRAL] = target_city->occupants[NEUTRAL].size() && NEUTRAL!=allegiance; 

        return  memo[WEST] || memo[AXIS] || memo[USSR] || memo[NEUTRAL];
    }

    /**
     * @brief Handler for user input on adding/removing battles for the combat phase
     * 
     * @param player The player who is attempting to change battles
     */
    void handleBattleSelect(Player& player);

    void handleActionSelect(Player& player);

    void handleTypeSelect(Player& player);

    void handleOptReBase(Player& player);

    void handleBattleGroupSelect(Player& player);

    /**
     * @brief Set which units are able to be attacked in a land battle
     * 
     * @param attacker Player who is currently attacking and choosing the target
     * @param defender Player whose units are under attack and being checked 
     */
    void setLandBattleable(Player& attacker, Player& defender);

    //- Spring
    /**
     * @brief Spring season of war where players will commence the war. Action cards with spring will have priority
     * 
     */
    void spring();

    //- Summer Season
    /**
     * @brief Summer season of war where players will commence the war and after which blockades will be added. Action cards with SUMMER will have priority
     * 
     */
    void summer();

    //- Checking Blockades
    /**
     * @brief At the end of summer, cities who cannot trace a trade route to the Main Capital of its ruler is blockaded and the pop/res won't be counted in production
     * 
     */
    void blockade();

    //- Fall Season
    /**
     * @brief Fall season of war where players will commence the war. Action cards with FALL will have priority
     * 
     */
    void fall();

    //- Winter Season
    /**
     * @brief The winter season of war where the USSR player can act inside of the bounds of the USSR. Only the USSR player can act during this turn
     * 
     */
    void winter();

    //&Checking on map

    /**
     * @brief Goes over the players holdings over the map and sums up their pop, res, CV
     * 
     * @param player The player whose cities will be checked
     * @return true No changes were made from the stored attributes
     * @return false Changes were made from stale attributes
     */
    bool mapPlayer(Player& player);

    /**
     * @brief Goes through each city and country the player owns and set the RES and POP of the player
     * 
     * @param player The player whose RES and POP are being set
     */
    void mapPlayerResPop(Player& player);

    /**
     * @brief During the production phase it needs to verify all cities controlled by the player that are blockaded are still blockaded (route can only include 1 land segment and 1 sea segment)
     * 
     * @param player The player whose trade routes are being checked
     * @param main_capital The capital of the player that the cities must conenct to 
     * @return true Blockades were removed 
     * @return false Blockades weren't removed
     */
    bool checkTradeRoutes(Player& player, const string& main_capital);

    /**
     * @brief A decider for if the city provided is supplied and can have steps built. All the cities on the route are marked as supplied to decrease redundancy
     * 
     * @param player The player who would build the unit
     * @param city The city where the unit wants to be built
     * @param allegiance The allegiance of the current city
     * @return true The city is suplliable
     * @return false The city is not suplliable
     */
    bool isSupllied(const Player& player, City* city, const CityType allegiance);

    /**
     * @brief Get the city closest to the provided coordinates
     * 
     * @param player The player whose screen is being looked at (since coords can be stretched with zoom)
     * @param x The x-coord of the desired point
     * @param y The y-coord of the desired point
     * @return City* The city that is closest to the point
     */
    City* getClosestCity(const Player& player, const int x, const int y) const;

    //&&&Unit Actions

    /**
     * @brief Decider for if a new unit of the given type is able to be built in the city provided
     * 
     * @param player Player whose troop will be added
     * @param city The city where the unit wants to be added
     * @param unit The type of unit that wants to be added (used to track limits)
     * @return ProductionError The error given as to why it can't be built (0 if no error)
     */
    ProductionError canBuild(const Player& player, City* city, const UnitType unit);

    /**
     * @brief Sets the array of booleans showing which units are buildable at the selected city
     * 
     * @param player The player whose selected city will be looking at
     * @return true At least one unit is buildable
     * @return false No units are buildable at the selected city
     */
    bool setBuildable(Player& player);

    /**
     * @brief Adds a new unit (cadre) to the city of the given type and to the player's unit master list
     * 
     * @param player The player whose unit is being built
     * @param city The city where the unit is being built
     * @param unit The type of unit that will be built
     * 
     * @return Unit* The unit created
     * 
     * @pre The unit follows all restrictions and can be built in the porvided city
     */
    Unit* buildCadre(Player&player, City* city, const UnitType unit);

    Unit* buildUnit(Player&player, City* city, const UnitType unit, const int cv=1);

    /**
     * @brief Decider for if an exisiting unit can be upgraded
     * 
     * @param player The player who wants to upgrade the unit
     * @param city The city where the unit is
     * @param nationality The nationality of the unit
     * @param unit The unit who would be upgraded
     * @return ProductionError The error given as to why it can't be upgrade (0 if no error)
     */
    ProductionError canUpgrade(const Player& player, City* city, const UnitCountry nationality, const Unit* unit);

    /**
     * @brief Handler for both adding new cadres and upgrading exisiting units when prompt on user input
     * 
     * @param player The player who initiated the building check
     */
    void handleUnitBuilding(Player& player);

    bool flipConvoy(Player& player, City* city, Unit* unit);

    //& Movement 
    void moveUnit(Player& player);

    void retreatUnit(Player& player);

    void reBaseUnit(Player& player);
    /**
     * @brief Decider for if the unit is able to move through the current movement memo with land movement (cannot go enter oceans and limited to straits and land borders and abide by border restrictions if engaging)
     * @see MovementMessage
     * 
     * @param player Player whose memo will be checked for validity
     * @param unit The unit who will be moving along the memo
     * @return MovementMessage Result of the player's memo, negative if an error, and positive if valid
     * @pre `player` is in movement phase
     */
    MovementMessage canLandMove(const Player& player, const Unit* unit) const;

    /**
     * @brief Decider for if the unit is able to move through the current movement memo with sea movement (can enter oceans and limited to onlt one 'land move' to an adjacent coastal city and doesn't abide by border restrictions)
     * @see MovementMessage
     * 
     * @param player Player whose memo will be checked for validity
     * @param unit The unit who will be moving along the memo
     * @return MovementMessage Result of the player's memo, negative if an error, and positive if valid
     * @pre `player` is in movement phase
     */
    MovementMessage canSeaMove(const Player& player, const Unit* unit) const;

    /**
     * @brief Decider for if the unit is able to move through the current movement memo (no restrictions on border types) (if starting in an ocean it must end it in a land city and doesn't abide by border restrictions)
     * @see MovementMessage
     * 
     * @param player Player whose memo will be checked for validity
     * @param unit The unit who will be moving along the memo
     * @return MovementMessage Result of the player's memo, negative if an error, and positive if valid
     * @pre `player` is in movement phase
     */
    MovementMessage canAirMove(const Player& player, const Unit* unit) const;

    /**
     * @brief Decider for if the player is able to disengage from the current battle (cannot re-engage the same turn)
     * @see MovementMessage
     * 
     * @param player Player whose memo will be checked for validity
     * @param unit The unit who will be moving along the memo
     * @return MovementMessage Result of the player's memo, negative if an error, and positive if valid
     * @pre `player` is in movement phase
     * @pre Unit is in conflict and needs to disengage
     */
    MovementMessage canDisengage(const Player& player, const Unit* unit) const;

    MovementMessage canRetreat(const Player& player, const Unit* unit) const;

    MovementMessage canReBase(const Player& player, const Unit* unit) const;

    //& Combat
    /**
     * @brief Decider and Handler for when a Player delcares a DoW on another Player and updates the DoW status
     * 
     * @param declarer Player who is declaring a DoW and will lose a VP (Set as DECLARED)
     * @param victim Player who is being declared on and a DoW and will have IND cost decreased (Set as VICTIM)
     * @return true `declarer` was able to declare the DoW (was at peace before)
     * @return false `declarer` was ubable to declare the DoW (wasn't at peace with the rival)
     */
    bool declareDoW(Player& declarer, Player& victim);

    /**
     * @brief Decider and Handler for when a Player delcares a VoB on a Neutral unarmed Minor and handles World Reaction (rivals draw cards based on the minor's capital POP)
     * 
     * @param aggresor The Player attempting to commit a VoN
     * @return true `aggresor` was able to declare the VoN and rivals gained cards
     * @return false `aggresor` was unable to declare the VoN
     */
    bool declareVoN(Player& aggresor);

    bool declareIntervention(Player& aggresor);

    void sortFireOrder();

    void sortReBaseOrder(const bool att, const bool def);

    void checkHitRoll();

    bool canHitUnit();

    Unit* checkHit(const CityType& victim_type, const UnitClass& victim_class) const;

    void setFireable(Player& player, const City* city, const CityType& victim);

    void hitUnit(City* city, Unit* unit);

    void finalizeBattleGroup(Player& player);

    void handleUnitActionEnd();

    void setNextBattle();

    void setNeutralBattle(){
        watching_player = *current_player;
        //? 15.42 Either Rival of the Violator can roll dice for an Armed Minor in Battle Resolution, but Neutral Fortresses must always target Ground units first.

        if (current_battle.first->hasType(watching_player, CLASS_G)){ //if it has ground then attack ground
            target_class = CLASS_G;
        }
        else{ //no ground then choose air then navy then choose random one next
            UnitClass check_order[3] = {CLASS_A, CLASS_N, CLASS_S};
            shuffle(&check_order[0], &check_order[2], g);

            for (const auto& u_class : check_order){
                if (current_battle.first->hasType(watching_player, u_class)){
                    target_class = u_class;
                    break;
                }
            }
        }

        //once the class target has been set put in the hit
        public_animations.push_back(PublicAnimation((SeasonAnimation)(WEST_DICE+acting_player), -48, -190, 512, 288+acting_player*32, 32, 32, 3, clock, 100));
        public_animations.back().addPhase(AnimationPhase::RANDOM, 5000);
        (public_animations.back()).setRandom(6);
        public_animations.back().setFinishCallback([this]() { decideDice(); });

        players[watching_player].combat_phase = OBSERVING;
    }

    void resetNeutralUnits(){
        for (auto& unit : neutral_units){
            unit->acted = false;
        }
    }
    /**
     * @brief Check which cities have a current battle happening
     * 
     * @param allegiance The allegiance of the current player 
     * @return vector<City*> Vector of all cities the player is batteling for
     */
    vector<City*> getBattles(const CityType allegiance); 

    //& Diplomacy

    void handleBattleResolution(City* battlefield);

    void updateCityRulers();

    //& Card 

    /**
     * @brief Handler for checking if the player can buy the preselected card when prompted by user input
     * 
     * @param player The player who prompted card buying
     */
    void handleCardBuying(Player& player);

    /**
     * @brief Handler for playing card during the `Government` phase
     * 
     * @param player The player who is playing a card
     */
    void handleCardPlaying(Player& player);

    /**
     * @brief Handler for player achieving the selected tech and removing the cards used if able
     * 
     * @param player Player attempting to achieve a new tech
     * @return true Player was able to achieve the tech and discarded the investment cards
     * @return false Player was ubable to achieve a tech
     */
    bool achieveTechnology(Player&player);

    //&^ Card Actions

    /**
     * @brief Handler for player selecting/deselecting investment cards to spend on raising IND
     * 
     * @param player Player who is attempting to change card selection
     */
    void selectTechCard(Player& player);

    /**
     * @brief Handler for Player peaking a rival's hand
     * 
     * @param player Player who is peaking at a rival's hand
     * @param ticks The tick the player is starting to view the rivals hand
     */
    void peakRivalAction(Player& player);

    /**
     * @brief Handler for Player peaking a rival's unit
     * 
     * @param player Player who is peaking at a rival's unit
     * @param ticks The tick the player is starting to view the rival's unit
     */
    void peakRivalUnit(Player& player);

    /**
     * @brief Handler for Player couping against a rival
     * 
     * @param player Player who is peaking at a rival's hand
     * @param ticks Unused but needed for lambda function
     */
    void coupRival(Player& player);

    /**
     * @brief Handler for Player sabotaging a rival
     * 
     * @param player Player who is peaking at a rival's hand
     * @param ticks Unused but needed for lambda function
     */
    void sabotageRival(Player& player);

    /**
     * @brief Handler for Player using Spy Ring against a rival
     * 
     * @param player Player who is Spy Ring-ing
     * @param ticks Unused but needed for lambda function
     */
    void spyRingRival(Player& player);

    //& Runner Getters and Setters
    /**
     * @brief Get the map of the game
     * 
     * @return const Map& A const reference to the game map and cities
     */
    const Map& getMap() const{
        return map;
    }

    /**
     * @brief Decider for if a card can be drawn from the action deck
     * 
     * @return true An action card can be bought
     * @return false There are no more action card to be bought
     */
    inline bool canBuyAction() const{
        return action_bought+1 <= action_deck.size();
    }

    /**
     * @brief Decider for if a card can be drawn from the investment deck
     * 
     * @return true An investment card can be bought
     * @return false There are no more investment card to be bought
     */
    inline bool canBuyInvest() const{
        return invest_bought+1 <= invest_deck.size();
    }

private:
    /**
     * @brief Free the allocated memory of the whole game
     * 
     */
    void freeMemory(){
        map.freeMemory();

        powers_sprite_map[0].freeMemory();
        powers_sprite_map[1].freeMemory();
        powers_sprite_map[2].freeMemory();
        powers_map_sprite[0].freeMemory();
        powers_map_sprite[1].freeMemory();
        powers_map_sprite[2].freeMemory();

        for (ActionCard* ac : action_deck){
            if (ac != nullptr) delete ac;
        }
        action_deck.clear();
        for (ActionCard* ac : action_discard){
            if (ac != nullptr) delete ac;
        }
        action_discard.clear();

        for (InvestmentCard* ac : invest_deck){
            if (ac != nullptr) delete ac;
        }
        invest_deck.clear();
        for (InvestmentCard* ac : invest_discard){
            if (ac != nullptr) delete ac;
        }
        invest_discard.clear();

        players[0].freeMemory();
        players[1].freeMemory();
        players[2].freeMemory();

        current_player = nullptr;
        start_player = nullptr;

        ShutdownApplication();
    }

    /**
     * @brief Print out the memo of the trade route algorithm
     * 
     * @param memo The completed memo of Dijkras algorithm
     */
    void printMemo(size_t memo[][5]) const;

private:  //!!! Graphics things
    //& Sprite Maps
    Spritesheet powers_sprite_map[3];  /**< A png that holds every sprite in the game and can be indexed into and a clip pulled from in for the player's seperate renderer*/

    Spritesheet powers_map_sprite[3]; /**< An array of the spritesheets initaliazed to the powers renderer that has the map */

    Spritesheet powers_units_sprite_z1[3]; /**< An array of the spritesheets initaliazed to the powers renderer that has the units at the first zoom level */

    Spritesheet powers_units_sprite_z3[3]; /**< An array of the spritesheets initaliazed to the powers renderer that has the units at the third zoom level */

    Spritesheet powers_controller_button_sprite[3]; /**< An array of the spritesheets initaliazed to the powers renderer that has the button input animations*/

    Spritesheet powers_message_animations[3];  /**< An array of the spritesheets initaliazed to the powers renderer that has the public messages animations*/    

    tick_t clock; /**< The tick the current frame is starting on and all logic checks in the frame should use */

    int fps; //dev

    //& Controller Things
    SDL_GameController *west_controller=nullptr; /**< The controller of the West player */

    SDL_GameController *axis_controller=nullptr;  /**< The controller of the Axis player */

    SDL_GameController *ussr_controller=nullptr;  /**< The controller of the USSR player */

    SDL_GameController* controllers[3]= {nullptr, nullptr, nullptr}; /**< Array of the controllers so that the controller.which can be used to index the controller obj*/
    
    bool map_changed=true; /**< Boolean that is true when an update has happened on the main screen and the main screen needs to be re-rendered */

    tick_t last_tick; /**< Used by animations to see how long has elapsed since started */
    
    int phase = 0; /**<  Used for animations on which phase of animating they should be on*/

    vector<PublicMessage> public_messages; /**< Vector of all current public messages that are being animated */

    vector<PublicRecord> log; /**< Vector of all logs on player messages, season starts, ect. */

    //& Init Functions
    /**
     * @brief Initalizes SDL2 and the window
     * 
     * @return true Initalized succesfully
     * @return false Failed to initalize
     */
    bool InitSDL();

    /**
     * @brief Initalizes the 'app', the struct that hlds the renderer and the window
     * 
     * @return true Initalized succesfully
     * @return false Failed to initalize
     */
    bool InitApplication();

    /**
     * @brief Initalizes the fonts for each player used to display text on screen
     * 
     * @return true Initalized succesfully
     * @return false Failed to initalize
     */
    bool InitFonts();

    /**
     * @brief Deletes the windows and frees memory specifically used by SDL
     * 
     */
    void ShutdownApplication();

    /**
     * @brief Clears the screen so the screen can 'update'
     * 
     */
    void ClearScreen(SDL_Renderer* renderer) const;

    /**
     * @brief Draws all buttons and titles for the title screen
     * 
     * @param player The player whose screen will be rendered on to
     * @param ticks The current tick of the program used for animating
     * @param alpha The alpha level of each sprite used for fading out
     */
    void drawTitle(Player& player, const uint8_t& alpha=255);

    //& Map Displaying
    /**
     * @brief Draws the map to the main rendered with different options to control what is shown
     * 
     * @param player The player whose screen will be rendered on to
     * @param cities Draws all cities if true
     * @param influence Draws the influence markers on each applicable city if true
     * @param resources Draw the resources of each city if true
     * @param connections Draw the line connections (colored by type) between connected cities if true
     * @param render Will render the map onto the renderer if true (used for when nothing will be added ontop of the map)
     * @param fps If a fps is provided it will draw it onto the renderer
     */
    void drawMap(Player& player, const bool cities, const bool influence, const bool resources, const bool connections, const bool render=true);

    /**
     * @brief Draws the private view of the player including cards and VP and production levels and acheived tech
     * 
     * @param player The player whose board (screen) is being drawn
     * @param render If the board should be rendered after all is drawn
     */
    void drawPlayerBoard(Player& player, const bool render=true);

    /**
     * @brief Draws the Investment Card hand of the currently viewed allegiance (either the icon or all the cards)
     * 
     * @param drawing_player The player whose screen will have the widget drawn onto
     * @param target_player  The player whose actual invest hands will be drawn (will hide cards if `drawing_player` != `target_player`)
     */
    void drawInvestWidget(Player& drawing_player, Player& target_player) const;

    /**
     * @brief Draws the Action Card hand of the currently viewed allegiance (either the icon or all the cards)
     * 
     * @param drawing_player The player whose screen will have the widget drawn onto
     * @param target_player  The player whose actual action hands will be drawn (will hide cards if `drawing_player` != `target_player`)
     */
    void drawActionWidget(Player& drawing_player, Player& target_player) const;

    /**
     * @brief Draws the Achieved Tech hand of the currently viewed allegiance (either the icon or all the cards)
     * 
     * @param drawing_player The player whose screen will have the widget drawn onto
     * @param target_player  The player whose actual tech will be drawn (will hide if `drawing_player` != `target_player` and secret)
     */
    void drawTechWidget(Player& drawing_player, Player& target_player) const;

    /**
     * @brief Draws the Player Stats hand of the currently viewed allegiance (either the icon or the POP, RES, IND, DOW, ect)
     * 
     * @param drawing_player The player whose screen will have the widget drawn onto
     * @param target_player  The player whose stats will be drawn
     */
    void drawStatWidget(Player& drawing_player, Player& target_player) const;

    /**
     * @brief Draws any season specific sprites onto the screen
     * 
     * @param drawing_player The player whose screen will be drawn onto
     */
    void drawSeasonSpecific(Player& drawing_player) const;

    /**
     * @brief Get the index of the sprite needed for the city
     * 
     * @param city The city being drawn
     * @return int The index of the sprite in the sprite map
     */
    int getCitySprite(City* city) const;

    /**
     * @brief Draws a city onto the players renderer and if opted the resources as well
     * 
     * @param player The player whose screen will have the city drawn on
     * @param city The city being drawn
     * @param resources If the resources should be drawn or not
     */
    void drawCity(Player& player, City* city, const bool resources=true, const bool units=true);

    void drawCity(Player& player, City* city, const bool resources=true) const;

    /**
     * @brief Draw a city marker (not tied to any specific city)
     * 
     * @param x The x-coord of the city
     * @param y The y-coord of the city
     * @param population_type The type of city to draw
     */
    void drawCity(Player& player, const int& x, const int& y, const PopulationType& population_type) const;

    /**
     * @brief Draws the unit building UI and the select line and selected unit
     * 
     * @param player The player whose screen will have the unit drawn
     */
    void drawBuild(Player& player) const;

    /**
     * @brief Draws all the currently selected battles onto the cities selected
     * 
     * @param player The player whose screen will have the battle tokens drawn
     */
    void drawBattleSelect(Player& player) const;

    void drawCombatWidget(Player& player) const;

    void drawCombatRug(Player& player) const;

    void drawCombatActionSelect(Player& player) const;

    void drawCombatOptReBaseSelect(Player& player) const;

    void drawCombatTypeSelect(Player& player) const;

    void drawCombatDealHits(Player& player) const;

    void drawCombatBattleGroupSelect(Player& player) const;

    /**
     * @brief Draws the unit onto the player's screen
     * 
     * @param player The player whose screen will have the unit drawn
     * @param unit The unit that will be drawn
     * @param x The x-coord of the unit to draw 
     * @param y The y-coord of the unit to draw 
     * @param zoom The zoom level of the player's map to determine units level of detail
     * @param secret If true the unit sprite will be a question mark only showing the nationality (for when not in combat and not the player's allegiance)
     * 
     * @pre x and y have already been scaled 
     */
    void drawUnit(const Player& player, const Unit* unit, const int& x, const int& y, const int& zoom, const bool secret=false) const;

    void drawFadeUnit(const Player& player, const Unit* unit, const int& x, const int& y, const int& zoom, const FadeDirection& fade_direct, const uint8_t& fade_r, const uint8_t& fade_g, const uint8_t& fade_b, const uint8_t& start_opacity, const uint8_t& end_opacity, const int& pixels_ignored) const;

    /**
     * @brief Draws a dummy unit onto the screen (not tied to a specific unit objecy)
     * 
     * @param player The player whose screen will have the unit drawn
     * @param unit_type The type of unit that's to be drawn
     * @param nationality The nationality (block color) of the block to be drawn
     * @param x The x-coord of the unit to draw 
     * @param y The y-coord of the unit to draw 
     * @param zoom The zoom level of the player's map to determine units level of detail
     * @param invalid If true the unit sprite will be a question mark only showing the nationality (for when not in combat and not the player's allegiance)
     * @param scale The scale of the unit to enlarge when drawn
     */
    void drawUnit(const Player& player, const UnitType& unit_type, const UnitCountry& nationality, const int& x, const int& y, const int& zoom, const bool invalid=false, const int& scale=1) const;

    /**
     * @brief Draws 5 units under the city, rotating to the next 5 every 5 seconds and will select a unit if the player's cursor is over one
     * 
     * @param player The player whose screen will have the units drawn (also affects which units are visible)
     * @param city The city whose occupants will be drawn
     */
    void drawCityUnits(Player& player, City* city);

    /**
     * @brief Draws the influence tokens onto the map
     * 
     * @param player The player whose screen will have the tokens rendered to
     */
    void drawInfluence(const Player& player) const;

    /**
     * @brief Draws the provided action card with the top-left corner being at the provided X and Y coords
     * 
     * @param draw_player The player whose screen will have the card rendered on to
     * @param card Pointer to the card that will be drawn
     * @param start_x The top-left X-Coord to start drawing the card
     * @param start_y  The top-left Y-Coord to start drawing the card
     * @param scaled_size  The scaled size each segment (three: left country, command, right country) should be
     * @param alpha The alpha (opacity) to render each segment
     */
    void drawActionCard(const Player* draw_player, const ActionCard* card, const int& start_x, const int& start_y, const int& scaled_size, const uint8_t alpha=255) const;

    /**
     * @brief Draws the provided investment card with the top-left corner being at the provided X and Y coords
     * 
     * @param draw_player The player whose screen will have the card rendered on to
     * @param card Pointer to the card that will be drawn
     * @param start_x The top-left X-Coord to start drawing the card
     * @param start_y  The top-left Y-Coord to start drawing the card
     * @param scaled_size  The scaled size each segment (three: left tech, IND, right tech) should be
     * @param alpha The alpha (opacity) to render each segment
     */
    void drawInvestCard(const Player* draw_player, const InvestmentCard* card, const int& start_x, const int& start_y, const int& scaled_size, const uint8_t alpha=255) const;

    /**
     * @brief Draws the action cards of the current viewed allegiance onto the players screen starting at the given x and y and decends
     * 
     * @param draw_player The player whose screen will have the cards rendered on to
     * @param target_player The player whose action cards will be drawn (will be hidden if not the `draw_player` or not  peaking)
     * @param start_x The top right x-coord corner of where cards should be drawn
     * @param start_y The top right y-coord corner of where cards should be drawn
     * @param count  The amount of cards to be drawn (max amount drawn will be XX)
     * @param scale The scale of the cards to draw
     */
    void drawActionCards(const Player* draw_player, const Player* target_player, const int& start_x, const int& start_y, const int& count, const int scale=1) const;

    /**
     * @brief Draws the invesetment cards of the current viewed allegiance onto the players screen starting at the given x and y and decends
     * 
     * @param draw_player The player whose screen will have the card rendered on to
     * @param start_x The top right x-coord corner of where cards should be drawn
     * @param start_y The top right y-coord corner of where cards should be drawn
     * @param count  The amount of cards to be drawn (max amount drawn will be XX)
     * @param scale The scale of the cards to draw
     */
    void drawInvestCards(const Player* player, const int& start_x, const int& start_y, const int& count, const int scale=1) const;

    void drawActionDeck(const Player& player) const;

    void drawInvestDeck(const Player& player) const;

    /**
     * @brief Draws the tech of the current viewed allegiance onto the players screen starting at the given x and y and decends

     * 
     * @param draw_player The player whose screen will have the card rendered on to
     * @param target_player The player whose tech will be drawn (will be hidden if secret and not the `draw_player`)
     * @param start_x 
     * @param start_y 
     */
    void drawAchievedTech(Player* player, const Player* target_player, const int& start_x, const int& start_y) const;

    /**
     * @brief Draw the current actions the player can take on the buttons that would initiate those actions
     * 
     * @param drawing_player The player whose actions are being drawn
     * @param ticks The current time since SDL was initalized and used to ttime animations  
     */
    void drawActionButtons(const Player& drawing_player) const; 

    /**
     * @brief Draws all the connections between the cities and colors them based on the type of border 
     * 
     * @param The player whose screen will have connections drawn on
     * 
     */
    void drawConnections(const Player& player) const;

    /**
     * @brief Draw the current turn order of the players and who has passed
     * 
     * @param player The player whose screen will have it drawn
     */
    void drawTurnOrder(const Player& player) const;

    /**
     * @brief Takes any length number and draws it as a 7-segment at the x,y as the top left. Origional scale is 7*13 for one digit. Default color is black
     * 
     * @param renderer The rendererer to draw the number onto
     * @param num Number to render
     * @param x X coord of number origin
     * @param y Y coord of number origin
     * @param scale Scales draw size of the number
     * @param r The red value of the color (0, 255)
     * @param g The green value of the color (0, 255)
     * @param b The blue value of the color (0, 255) 
     */
    void drawNumber(SDL_Renderer* renderer, int num, const int x, const int y, const float scale, const uint8_t r=255, const uint8_t g=255, const uint8_t b=255, const uint8_t a=255) const;

    /**
     * @brief Draws a 3 pixel wide line between the two points
     * 
     * @param player The players whose screen will have it drawn
     * @param x1 The x-coord of the first point
     * @param y1 The y-coord of the first point
     * @param x2 The x-coord of the second point
     * @param y2 The y-coord of the second point
     */
    void drawLine(const Player& player, const int x1, const int y1, const int x2, const int y2) const{
        auto& renderer = player.app->renderer;
        SDL_SetRenderDrawColor(renderer, 255, 193, 7, 255);
        SDL_RenderDrawLine(renderer, x1,    y1,     x2,     y2);
        SDL_RenderDrawLine(renderer, x1-1,  y1+1,   x2-1,   y2+1);
        SDL_RenderDrawLine(renderer, x1,    y1+1,   x2,     y2+1);
    }

    /**
     * @brief Draws a 3-pixel wide line between two cities
     * 
     * @param player The players whose screen will have it drawn 
     * @param city1 The city where the line starts
     * @param city2 The city where the line ends
     */
    void drawLine(const Player& player, const City* city1, const City* city2, const bool border=true) const{
        auto& renderer = player.app->renderer;
        const auto& temp = map.getBorder(city1, city2);
        const auto& x1 = player.app->screen.getX(city1->x+city1->WIDTH/2);
        const auto& y1 = player.app->screen.getY(city1->y+city1->HEIGHT/2);

        const auto& x2 = player.app->screen.getX(city2->x+city2->WIDTH/2);
        const auto& y2 = player.app->screen.getY(city2->y+city2->HEIGHT/2);
        if (border)
            SDL_SetRenderDrawColor(renderer, BORDER_COLOR[temp][0], BORDER_COLOR[temp][1], BORDER_COLOR[temp][2], 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 193, 7, 255);
        SDL_RenderDrawLine(renderer, x1,    y1,     x2,     y2);
        SDL_RenderDrawLine(renderer, x1-1,  y1+1,   x2-1,   y2+1);
        SDL_RenderDrawLine(renderer, x1,    y1+1,   x2,     y2+1);
    }

    /**
     * @brief Handles what to draw during the current phase
     * 
     */
    void drawPhase();

    //& Animations
    vector<PublicAnimation> public_animations;

    /**
     * @brief Animation for showing the command cards played and the new order
     * 
     * @param running Flag for if the current loop should continue
     * @param ticks The current tick to be used as a clock
     * @param west_start The starting turn order postion of the West player
     * @param axis_start The starting turn order postion of the Axis player
     * @param ussr_start The starting turn order postion of the USSR player
     * @param west_end The end turn order postion of the West player
     * @param axis_end The end turn order postion of the Axis player
     * @param ussr_end The end turn order postion of the USSR player
     */
    void animateCommandOrder(bool& running, const int west_start,  const int axis_start,  const int ussr_start, const int west_end,  const int axis_end,  const int ussr_end);

    /**
     * @brief Used the current time and the public message origin time to draw the frame the given animation is at
     * 
     * @param player The player whose screen will be drawn on
     * @param message The message that will be drawn on the screen
     * @param ticks The current time of the frame being drawn
     */
    void animateMessage(Player& player, PublicMessage& message);
    
    /**
     * @brief Animation of the cards from the discard pile being added back
     * 
     * @param action_size Number of action cards to add back
     * @param invest_size Number of invest cards to add back
     */
    void animateReshuffle(bool& running, const size_t& action_size, const size_t& invest_size);

    /**
     * @brief Takes the memo of the Dijkstra's knock-off II for finding trade routes and highlighting the route it takes
     * 
     * @param memo The completed memo
     * @param unblocked The list of cities who were unblockaded and there path will be shown
     */
    void drawMemoResolution(const vector<std::array<size_t, 6>>& memo, vector<City*> unblocked);

    /**
     * @brief Draws the memo of the Dijkstra's knock-off III for supply routes
     * 
     * @param player The player whose screen it will be drawn too
     * @param memo The completed memo of the algorithm
     */
    void drawMemoResolution(Player& player, const vector<std::array<size_t, 4>>& memo);

    /**
     * @brief Animation for rolling a D6 and form that the turn order that is decided
     * 
     * @param result The result of the dice roll
     */
    void drawTurnRoll(const int& result);

    /**
     * @brief Animation of the cities who were peacful receiving a peace chit
     * 
     * @param west Bool if the WEST player should be shown receiving a peace chit
     * @param axis Bool if the AXIS player should be shown receiving a peace chit
     * @param ussr Bool if the USSR player should be shown receiving a peace chit
     */
    void drawPeaceDividends(const bool west, const bool axis, const bool ussr);

    /**
     * @brief 
     * 
     * @param player 
     * @param ticks 
     */
    void animatePoem(Player& player) const;

    /**
     * @brief Used for button presses where a given mouse clip position will see if its in the rectangle provided
     * 
     * @param x The top left x-coord of the rectangle
     * @param y The top left y-coord of the rectangle
     * @param width The width of the button 
     * @param height The height of the button
     * @param target_x The x-coord where the mouse clicked
     * @param target_y The y-coord where the mouse clicked
     * @return true The click is in the button
     * @return false The click is not in the button
     */
    bool inBox(const int x, const int y, const int width, const int height, const int target_x, const int target_y) const{
        return (target_x >= x && target_x <= x+width) && (target_y >= y && target_y <= y+height);
    }

    bool inBox(const int x, const int y, const SDL_Rect* area) const{
        return (x >= area->x && x <= area->x+area->w) && (y >= area->y && y <= area->y+area->h);
    }

    //& User Input

    /**
     * @brief Main handler for all possible user input
     * 
     * @param running Reference to the check if the game loop should continue running and can be changed if player inputs it so
     */
    void handleUserInput(bool& running);

    /**
     * @brief Handler for all actions which have the X Button (only) held
     * 
     * @param player Player whose X-Button Actinos are checked
     * @param ticks The current tick to use as a clock
     */
    void handleXHeld(Player& player);

    /**
     * @brief Handler for all actions which have the Y Button (only) held
     * 
     * @param player Player whose Y-Button Actinos are checked
     * @param ticks The current tick to use as a clock
     */
    void handleYHeld(Player& player);

    /**
     * @brief Handler for all actions that occur during the Production Phase with the Y-Button
     * 
     * @param player The Player acting with the Y-Button in Production
     * @param ticks The current tick to use as a clock
     * @param y_wait_time The wait-time the Y-Button needs to be held for actions
     * @pre Current season is Production
     */
    void handleProductionSeason(Player& player);

    /**
     * @brief Handler for all actions that occur during the Government Phase with the A-Button
     * 
     * @param player The Player acting with the A-Button in Production
     * @param ticks The current tick to use as a clock
     * @param y_wait_time The wait-time the A-Button needs to be held for actions
     * @pre Current season is Government
     */
    void handleGovernmentSeason(Player& player);

    /**
     * @brief Handler for all actions that occur during the Command Phase with the Y-Button
     * 
     * @param player The Player acting with the Y-Button in the Command Phase
     * @param ticks The current tick to use as a clock
     * @param y_wait_time The wait-time the Y-Button needs to be held for actions
     * @pre Current season is Command
     */
    void handleCommandSeason(Player& player);

    /**
     * @brief Handler for all actions that occur during the Action Seasons with the Y-Button and A-Button
     * 
     * @param player The Player acting with the Y-Button or A-Button
     * @param ticks The current tick to use as a clock
     * @param a_wait_time The wait-time the A-Button needs to be held for actions
     * @param y_wait_time The wait-time the Y-Button needs to be held for actions
     * @pre Current season is in an Action Season
     */
    void handleRegularSeason(Player& player);

    void handleCombatActions(Player& player);

    void decideDice(){
        die.roll();

        public_animations.push_back(PublicAnimation((SeasonAnimation)(WEST_DICE+acting_player), -48, -190, 512+(die.last_result-1)*32, 288+acting_player*32, 32, 32, 3, clock, 300));
        public_animations.back().addPhase(AnimationPhase::FLICKER, 4000);
        public_animations.back().setFinishCallback([this]() { checkHitRoll(); });
    }
    /**
     * @brief Handler for preforming Intel related actions
     * 
     * @param player Player who is comitting an intel action
     * @param ticks The current tick to use as a clock
     * @param message_type The type of public message to display
     * @param espionageAction Function Pointer to the actual action the player is commiting
     */
    void performIntel(Player& player, Message message_type, void (Runner::*espionageAction)(Player&));

    /**
     * @brief Handler for 'pinning' (showing all troops) the selected city
     * 
     * @param player Player who is pinning a city
     */
    void pinCity(Player& player){
        if (player.closest_map_city != nullptr && season != TITLE_SCREEN){
                player.closest_map_city->full_display[player.getAllegiance()] = ! player.closest_map_city->full_display[player.getAllegiance()];
                player.widget = MAP;
        }
    }

    /**
     * @brief Handler for toggling the view of widgets (showing just the icon or showing all the data)
     * 
     * @param player Player who is toggling their view
     */
    void toggleView(Player& player){
        if (player.widget <= COMBAT_WIDGET){
            switch (player.widget){
                case ACTION_HAND:
                    player.show_action = !player.show_action;
                    player.popped_action_card_index = -1;
                    break;
                case INVEST_HAND:
                    player.show_invest = !player.show_invest;
                    player.popped_invest_card_index = -1;
                    break;
                case TECH_HAND:
                    player.show_tech = !player.show_tech;
                    player.popped_tech_index = -1;
                    break;
                case STAT_WIDGET:
                    player.show_stat = !player.show_stat;
                    break;
                case COMBAT_WIDGET:
                    player.show_combat = !player.show_combat;
                    break;
                
                default:
                    break;
            }
            player.board_change = true;
        }
    }
    
    /**
     * @brief Handler for adding new battles during the Combat Select Phase
     * 
     * @param player Player who is attempting to a new battle
     * @param defender Allegiance of the defender
     * @return true Able to add a new battle against the defender
     * @return false Unable to add a new battle against the defender
     * @pre Player phase is COMBAT_SELECT
     */
    bool addBattle(const Player& player, const CityType& defender);
    
    /**
     * @brief Handler for when an animation is happening and user input is limited
     * 
     * @param running Condition if the current loop should continue running
     * @param ticks The current time the frame is being drawn
     */
    void handleUserAnimationInput(bool& running);

    /**
     * @brief Handler for when at the title screen and user input is limited
     * 
     * @param running Condition if the current loop should continue running
     * @param ticks The current time the frame is being drawn
     */
    void handleTitleInput(bool& running);

    /**
     * @brief Handels the cases where the player pressed down on a button
     * 
     * @param player The player who commenced the event
     * @param event The button down event by the player
     */
    void handleButtonDown(Player& player, const SDL_Event& event);

    /**
     * @brief Handels the cases where the player lets up on a button (mostly for times events)
     * 
     * @param player The player who commenced the event
     * @param event The button up event by the player
     */
    void handleButtonUp(Player& player, const SDL_Event& event);

    /**
     * @brief Handels the players controller joystick movement the dictates cursor movement and is called only every frame to make the movement smoother
     * 
     * @param player The player whose controller is checked for movement
     */
    void handleCursorMovement(Player& player);

    void selectCity(Player& player){
        if (player.b_held_tick && player.closest_map_city){
            player.selected_city = player.closest_map_city;
        }
    }

    void handleUnitSelection(Player& player, const bool move_x, const bool move_y);
    /**
     * @brief Handler for the right joystick (used to select things) thats taken every frame
     * 
     * @param player The player whose controller will be read
     */
    void handleJoystickMovement(Player& player);

    /**
     * @brief Handler for scrolling on the Action Hand widget and updating the popped action card and selected countries
     * 
     * @param player Player whose movement is being checked
     * @param x_move Flag for if Player is able to move the x-axis again (on cooldwown)
     * @param y_move Flag for if Player is able to move the y-axis again (on cooldwown)
     */
    void handleActionHandMovement(Player& player, const bool x_move,  const bool y_move);

    /**
     * @brief Handler for scrolling on the Invesement Hand widget and updating the popped invest card and selected techs
     * 
     * @param player Player whose movement is being checked
     * @param x_move Flag for if Player is able to move the x-axis again (on cooldwown)
     * @param y_move Flag for if Player is able to move the y-axis again (on cooldwown)
     */
    void handleInvestHandMovement(Player& player, const bool x_move,  const bool y_move);

    /**
     * @brief Handler for scrolling on the tech widget and updating the popped tech
     * 
     * @param player Player whose movement is being checked
     * @param y_move Flag for if Player is able to move the y-axis (Scroll techs) (on cooldwown)
     */
    void handleTechMovement(Player& player, const bool y_move);

    /**
     * @brief Handler for the right joystick (used to select things) thats taken in set times
     * 
     * @param player The player whose controller is being read
     * @param ticks The current time of the program used to gauge the delta time
     */
    void handleTimedJoystick(Player& player);

    /**
     * @brief Handels the players controller trigger (L2, R2) movement that dictates zoom and is called only every frame to make game smoother
     * 
     * @param player The player whose controller is checked for movement
     */
    void handleTriggerMovement(Player& player);

    /**
     * @brief Handles inputs from moving between widgets (action hand, map, invest hand, ect) and is taken in set times to make movement managable
     * 
     * @param player The player whose buttons will be reaed
     * @param ticks The current time of the program used to gauge the delta time
     */
    void handleWidgetMovement(Player& player);

    /**
     * @brief Handler for inputs that rely on buttons being held for a set time
     * 
     * @param player The player whose buttons will be read
     * @param ticks The current time of the program used to gauge the delta time
     */
    void handleHeldButtons(Player& player);

    /**
     * @brief Handles player swapping controllers but need to make it so it actually works
     * 
     * @param player Player who is attempting to switch controllers
     */
    void handleControllerSwitch(Player& player);

    /**
     * @brief Handler for moving the cursor and either moving the screen or the cursor
     * 
     * @param player The player whose cursor is moving
     */
    void clampCursorX(Player& player, const double amount);

    /**
     * @brief Handler for moving the cursor and either moving the screen or the cursor
     * 
     * @param player The player whose cursor is moving
     */
    void clampCursorY(Player& player, const double amount);
    
private:

    //& Passing 
    /**
     * @brief Handler for when player's act during the government phase and to loop to the next non-passed player until all have passed
     * 
     */
    void playerActed(){
        if (west_player->passed && axis_player->passed && ussr_player->passed)
            return;
        while (turn_order[current_index = loopVal(current_index+1, 0, 2)]->passed);

        current_player = turn_order[current_index];
    }

    void initPass(Player& player){
        player.passed = true;
    }

    /**
     * @brief Handler for when player's pass during the Action Seasons and which stage of Movement/Combat they move to
     * 
     */
    void seasonActed(Player& player) {
        auto& curr = player.combat_phase;

        switch (curr) {
            case MOVEMENT:{
                //check if they intervened a country and
                if (!player.intervened_countries.empty()){
                    curr = INTERVENTION_SELECT;
                    player.curr_intervention = *player.intervened_countries.begin();
                    player.intervened_countries.erase(player.intervened_countries.begin());
                    return;
                }
                //check change of ownership
                updateCityRulers();
                curr = COMBAT_SELECT_BATTLE;
                //reset units who have moved
                current_player->resetMoves();
                break;
            }
            case INTERVENTION_SELECT:{
                if (!player.intervened_countries.empty()){
                    curr = INTERVENTION_SELECT;
                    player.curr_intervention = *player.intervened_countries.begin();
                    player.intervened_countries.erase(player.intervened_countries.begin());
                }
                else{
                    updateCityRulers();
                    curr = COMBAT_SELECT_BATTLE;
                }
                break;
            }
            case COMBAT_SELECT_BATTLE:{
                player.resetUnits();

                if (battles.empty()){
                    player.combat_phase = COMBAT_FINISHED;
                    seasonActed(player);
                    return;
                }

                current_battle = battles.front();
                current_battle.first->battling = year;

                if (current_battle.first->start_allegiance == WATER && !current_player->done_bg && !players[current_battle.second].done_bg){
                    watching_player = current_battle.second;
                    acting_player = current_player->getAllegiance();  
                    //todo deciding battle groups
                    players[acting_player].combat_phase = COMBAT_SELECT_BATTLE_GROUP;

                    players[watching_player].combat_phase = COMBAT_SELECT_BATTLE_GROUP;
                    return;
                }

                sortFireOrder();      

                acting_player = fire_order[0]->allegiance;

                if (acting_player == NEUTRAL){ //if the acting player is neutral then they will automatically send out a hit
                    setNeutralBattle();

                }
                else{
                    acting_player = fire_order[0]->allegiance;
                    watching_player = acting_player == current_player->getAllegiance()? current_battle.second : *current_player;

                    players[acting_player].combat_phase = COMBAT_SELECT_ACTION;
                    players[watching_player].combat_phase = OBSERVING;

                    setFireable(players[acting_player], current_battle.first, watching_player);
                }

                battles.erase(battles.begin());

                break;
            }
            
            case COMBAT_SELECT_BATTLE_GROUP:{
                
                break;
            
            }
            case COMBAT_FINISHED:{
                west_player->combat_phase = OBSERVING;
                axis_player->combat_phase = OBSERVING;
                ussr_player->combat_phase = OBSERVING;

                current_player->passed = true;
                resetNeutralUnits();

                if (current_index < 2){
                    current_player = turn_order[++current_index];
                    current_player->combat_phase = MOVEMENT;
                }
                break;
            }

            default:
                break;
        }
    }

    /**
     * @brief Handler for the playing command cards and turn order (all must be passed for it to end and will loop until so)
     * 
     * @param passed Flag for if the current player did not pass and then need to get confirmation from all other players again
     */
    void passedCommand(const bool passed){
        if (west_player->passed && axis_player->passed && ussr_player->passed) //if all have already passed then don't move anymore
            return;

        if (!passed){ //if the current player did not pass then need to get confirmation from all other players again
            west_player->passed = false;
            axis_player->passed = false;
            ussr_player->passed = false;
        }
        else
            current_player->passed = true;

        current_index = loopVal(current_index+1, 0, 2);
        current_player = turn_order[current_index];

        cout << turn_order[current_index]->getName() << endl;

        if (current_player->getCommandNumber() != -1){
            passedCommand(true);
        }
    }

    //& Dev Tools

    /**
     * @brief Get the sprite offset for the player's stat widget DoW
     * 
     * @param player Player whose DoW's need an offset
     * @param second Flag for if the second row DoW needs the offset (false if top row)
     * @return int The offset for the correseponding sprite
     */
    int getDoWOffset(const Player& player, const bool second) const{
        if (second){
            switch (player.getAllegiance()){ //bottom dow
                case WEST:
                    return 3*player.getUssrDow()+1;
                    break;
                case AXIS:
                    return 3*player.getUssrDow()+1;
                    break;
                case USSR:
                    return 3*player.getWestDow();
                    break;
                
                default:
                    break;
            }
        }

        else{
            switch (player.getAllegiance()){ //top dow
                case WEST:
                    return 3*player.getAxisDow()+2;
                    break;
                case AXIS:
                    return 3*player.getWestDow();
                    break;
                case USSR:
                    return 3*player.getAxisDow()+2;
                    break;
                
                default:
                    break;
            }
        }

        return -1;   
    }


    /**
     * @brief Dev tool for setup when deciding the X and Y of the city, it'll print which city and then record the clicked X and Y as the location of the city
     * 
     * @param path 
     */
    void setXY(const string& path){
        string path2 = "./sprites/MapSprite4.png";
        int width, height;
        SDL_GetWindowSize(west_player->app->window, &width, &height);
        string line;
        
        fstream map_file("./src/starter5.map", std::ios_base::in);
        fstream out_file("out.txt");

        if (!map_file.is_open()){
            cout << "failed to open file " << path << endl;
            exit(1);
        }

        if (!out_file.is_open()){
            cout << "failed to open file out.txt" << endl; 
            exit(1);
        }

        int num_cities, num_countries;

        map_file >> num_cities;
        map_file >> num_countries;
        getline(map_file, line); //junk line

        SDL_Event event;
        out_file << num_cities << " " << num_countries << "\n";
        for (int i = 0; i < num_cities; i++){
            bool running = true;
            getline(map_file, line);
            out_file << line << " ";
            cout <<  line << endl;
            while (running){
                ClearScreen(west_player->app->renderer);

                if (SDL_PollEvent(&event)){
                    switch (event.type) {
                        case SDL_MOUSEBUTTONDOWN:{
                            int mouseX,mouseY;
                            SDL_GetMouseState(&mouseX, &mouseY);
                            out_file << mouseX-16 << " " << mouseY-16 << "\n";
                            cout << line << " "<< mouseX << " " << mouseY << endl;
                            running = false;
                            break;
                        }
                        case SDL_KEYDOWN:{
                            goto Skip;
                            break;
                        }
                    }
                }
                SDL_RenderPresent(west_player->app->renderer);
            }
        }

        Skip:
        for (int i = 0; i < num_cities; i ++){
            getline(map_file, line);
            if (line[0] <= '9'){
                i--;
                continue;
            }
            std::istringstream iss(line);
            string starting_city;
            iss >> starting_city;
            out_file << starting_city << " ";

            string city, border;
            while (!iss.fail()){
                iss >> city;
                iss >> border;
                out_file << "[" << city << " " << border << "] ";
            }
            out_file << "\n";
        }
    }

    /**
     * @brief Dev tool to Set the resource x and y coords for each city that has a resource
     * 
     */
    void setResXY(){
        InitApplication();
        players[0] = Player("Michael", WEST); 
        players[WEST].app = &powers_app[0];
        string path = "./sprites/SpriteSheet0.png";
        const string path2 = "./sprites/MapSprite4.png";
        powers_sprite_map[0] = Spritesheet(path.c_str(), powers_app[0].renderer);
        players[WEST].sprite_sheet = &powers_sprite_map[0];
        powers_map_sprite[0] = Spritesheet(path2.c_str(), powers_app[0].renderer);
        players[WEST].map_sprite = &powers_map_sprite[0];
        initMap("./src/starter5.map");

        vector<std::pair<int, int>> coords;
        int width, height;
        SDL_GetWindowSize(players[WEST].app->window, &width, &height);
        SDL_Event event;
        for (int i = 1; i < map.getCities().size(); i++){
            const auto& city = map.getCity(i);
            bool running = true;
            if (city->resource > 0){
                cout << city->name << " has " << city->resource << " resources, place at ";
                while (running){
                    ClearScreen(players[WEST].app->renderer);

                    //players[WEST].map_sprite->drawSprite(&tar, 0, 0, 1512, 982);
                    drawCity(players[WEST], city->x, city->y, city->population_type);

                    if (SDL_PollEvent(&event)){
                        switch (event.type) {
                            case SDL_MOUSEBUTTONDOWN:{
                                int mouseX,mouseY;
                                SDL_GetMouseState(&mouseX, &mouseY);
                                coords.push_back(std::make_pair(mouseX, mouseY));
                                cout << mouseX << " " << mouseY << endl;
                                running = false;
                                break;
                            }
                            case SDL_KEYDOWN:{
                                goto Skip;
                                break;
                            }
                        }
                    }
                    SDL_RenderPresent(players[WEST].app->renderer);
                }            
            }
            else{
                coords.push_back(std::make_pair(0, 0));
            }
        }
        for (const auto& a : coords){
            cout << a.first << " " << a.second << endl;
        }

        Skip:
        exit(0);
    }

    /**
     * @brief Checks if the joy stick movement is within the accepted range of movement (fights stick drift)
     * 
     * @param move The degree of the joystick movement 
     * @return true The movement is acceptable 
     * @return false The movement is unacceptable (in the dead zone) 
     */
    bool pastDeadZone(const int& move) const{
        return !(move > -JOYSTICK_DEADZONE && move < JOYSTICK_DEADZONE);
    }
    
    /**
     * @brief Takes a joy axis movement and scales it to be from [0.0, 1.0] bases on a min movement of -32000 and max movement of 32000
     * 
     * @param x The joy axis movement
     * @return double The scaled joy axis movement
     */
    double scaleAxis(const double& x) const{
        return 2.0 * ((SDL_clamp(x, -32000, 32000) - -32000.f) / (32000 - - 32000.f)) - 1.0;
    
    }

    /**
     * @brief Gives an efficent way to determine the distance between the provided point on the screen and the cursor 
     * 
     * @param x1 The unsacled x-coord of the point
     * @param y1 The unsacled y-coord of the point
     * @param x2 The cursor x-coord
     * @param y2 The cursor y-coord
     * @param zoom_x The scale multiplier for x-values
     * @param zoom_y The scale multiplier for y-values
     * @return int The euclidian distance between the two points
     */
    int distCursor(const int& x1, const int& y1, const int& x2, const int& y2, const int& zoom_x, const int& zoom_y){
        return (zoom_x*x1 - x2)*(zoom_x*x1 - x2) + (zoom_y*y1 - y2)*(zoom_y*y1 - y2);
    }
};

