# include "hero.h"

Hero::Hero(){
}

Hero::Hero(string name){
    name = name;
    hp = 100;
    maxhp = 100;
    mana = 100;
    maxmana = 100;
    level = 1;
    exp = 0;
}
