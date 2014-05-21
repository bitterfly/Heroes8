# pragma once
# include <string>
# include <iostream>
# include <ctime>
# include <cstdlib>
# include "coordinates.h"

using namespace std;

class Warrior{
protected:
    string name;
    int level;
    double hp;
public:
    Coordinates position;

    string getName() const{
        return name;
    };

    int getLevel() const {
        return level;
    };

    double getHp() const {
        return hp;
    };

    double getMaxhp() const {
        return (level*20 + 100);
    };

    Warrior();

    Warrior(string, int);
};
