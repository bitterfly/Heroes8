# pragma once

# include "warrior.h"
# include "item.h"
# include "coordinates.h"
# include <windows.h>
# include <iomanip>
# include <cmath>

using namespace std;


class Hero: public Warrior
{
private:
    int exp;
    double mana;
public:
    vector <Item* > backpack;
    Hero();
    Hero(string name, int level);
    int getExp() const;
    double getMana() const;
    double getMaxMana() const;
    void setMana(double mana);
    void setExp(int exp);
    void lifeBar();
    void lifeBar(Coordinates);
    bool hasItem(Item& item);
};
