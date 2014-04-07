#pragma once
# include <iostream>
# include <string>
# include <conio.h>
# include "coordinates.h"
# include "hero.h"
# include "map.h"

using namespace std;

class Gameplay{
public:
    void prompt();
    bool move(Direction);
    Gameplay();
private:
    Hero dobrincho;
    Map *map;
};
