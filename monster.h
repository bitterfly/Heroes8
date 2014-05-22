#pragma once

# include "warrior.h"

using namespace std;

class Monster:Warrior {
public:
    Monster();
    Monster(string name);
    double getDamage() const;
    void print() const;
};
