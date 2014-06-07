#pragma once

# include <conio.h>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <map>
# include <string>
# include <windows.h>

# include "coordinates.h"
# include "event.h"
# include "hero.h"
# include "map.h"

using namespace std;

class Gameplay{
private:
    Hero dobrincho;
    int treasures;
    Map *the_map;
    vector<Event> events;
    vector<Item> items;
    vector<string> monster_names;
    map <Coordinates, Monster> monstersInc;

    void printSpot(Coordinates position, bool single = false);
    void event();
    void fight();
    void add(Item &);
    void printUnderMap(bool clear = false);
public:
    Gameplay();
    bool prompt();
    void printMap();
    bool move(Direction);
    void readMonsterNames(string filename);
    void readEvents(string filename);
    void readItems(string filename);
    void printMonsters();
    void printEvents();
    void printItems();
};
