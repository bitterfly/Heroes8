# pragma once

# include <cmath>
# include <iomanip>
# include <windows.h>

# include "warrior.h"
# include "item.h"
# include "coordinates.h"



using namespace std;


class Hero: public Warrior
{
private:
    int exp;
    double mana;
public:
    Hero();
    Hero(string name, int level);

    void setMana(double mana);
    void setExp(int exp);

    int getExp() const;
    double getMana() const;
    double getMaxMana() const;

    void lifeBar();
    void lifeBar(Coordinates);
    bool hasItem(Item& item);
    void add(Item &item);
    void drop(int index);
    double weight();
    vector <Item* > backpack;
};
