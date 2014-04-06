# include <iostream>
# include <string>
using namespace std;


class Hero
{
private:
    string name;
    int level, exp;
    double hp, maxhp, mana, maxmana;
public:
    int getLevel() const {
        return this->level;
    };

    int getExp() const {
        return this->exp;
    };


    double getHp() const {
        return this->hp;
    };

    double getMaxhp() const {
        return this->maxhp;
    };

    double getMana() const {
        return this->mana;
    };

      double getMaxmana() const {
        return this->maxmana;
    };

    string getName();

    Hero();

    Hero(string name);
};
