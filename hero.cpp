# include "hero.h"

Hero::Hero(){
    mana = getMaxMana();
    exp = 0;
}

Hero::Hero(string name, int level) :Warrior(name, level) {
    mana = getMaxMana();
    exp = 0;
}

int Hero::getExp() const {
    return exp;
}

double Hero::getMana() const {
    return mana;
}

double Hero::getMaxMana() const {
    return level*8 + 20;
}
