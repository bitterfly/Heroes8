#pragma once

# include "warrior.h"
# include "coordinates.h"
# include <fstream>
# include <windows.h>
# include <iomanip>

using namespace std;

class Monster:public Warrior {
public:
    Monster();
    Monster(string name);
    double getDamage() const;
    void print() const;
    void printSelfie();
    void lifeBar();
    void lifeBar(Coordinates);
};
