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

    int getWeapons() const;
    int getExp() const;
    double getMana() const;
    double getMaxMana() const;

    void lifeBar();
    void lifeBar(Coordinates, bool all_items = true);
    bool hasItem(Item& item);
    void drop(int index);
    double weight();
    double getDefense();
    vector <Item* > backpack;
};
