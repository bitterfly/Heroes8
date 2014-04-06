#pragma once
# include <iostream>
# include <string>
using namespace std;

class Monster{
private:
    string name;
    double hp;
    double maxhp;
    double damage;
public:
    Monster();
    Monster(string, double, double, double);

    string getName() const{
    return this->name;
    };

    double getHp() const{
    return this->hp;
    };

    double getMaxhp() const{
    return this->maxhp;
    };

    double getDamage() const{
    return this->damage;
    };
};
