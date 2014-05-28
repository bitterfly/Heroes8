# pragma once

# include <cstdlib>
# include <ctime>
# include <iostream>
# include <string>
# include <vector>

# include "coordinates.h"

using namespace std;

class Warrior{
protected:
    string name;
    int level;
    double hp;
public:
    Warrior();

    Warrior(string, int);

    void setHp(double hp);

    void setName(string n);

    string getName() const;

    int getLevel() const;

    double getHp() const;

    double getMaxhp() const;

    Coordinates position;
};
