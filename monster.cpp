# include "monster.h"

Monster::Monster(){
hp = 100;
maxhp = 100;
}
Monster::Monster(string name, double hp, double maxhp, double damage){
this->name = name;
this->hp = hp;
this->maxhp = maxhp;
this->damage = damage;
}
