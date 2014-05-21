#pragma once

# include "warrior.h"

using namespace std;

class Monster:Warrior {
public:
    Monster();
    double getDamage() const;
    void print() const;
};
