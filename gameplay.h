#pragma once

# include <conio.h>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <map>
# include <string>
# include <windows.h>
# include "coordinates.h"
# include "hero.h"
# include "map.h"
# include "event.h"

using namespace std;

class Gameplay{
private:
    Hero dobrincho;
    Map *the_map;
    map <Coordinates, Monster> monstersInc;
    void printSpot(Coordinates position, bool single = false);
    vector<string> monster_names;
    vector<Event> events;

    void event();
    void fight();
public:
    Gameplay();
    void printMap();
    bool prompt();
    void printMonsters();
    void printEvents();
    void readMonsterNames(string filename);
    void readEvents(string filename);
    bool move(Direction);
};
