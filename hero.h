# pragma once

# include "warrior.h"

using namespace std;


class Hero: public Warrior
{
private:
    int exp;
    double mana;
public:
    Hero();
    Hero(string name, int level);
    int getExp() const;
    double getMana() const;
    double getMaxMana() const;
};
