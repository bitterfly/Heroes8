# include "warrior.h"

Warrior::Warrior(){
name = "";
level = 1;
hp = getMaxhp();
}


Warrior::Warrior(string s, int l){
    name = s;
    level = l;
    hp = getMaxhp();
}


void Warrior::setHp(double hp){
    this->hp = hp;
    if(this->hp>getMaxhp())
        hp = getMaxhp();
}


void Warrior::setName(string n){
    this->name = n;
}


string Warrior::getName() const{
    return name;
}


int Warrior::getLevel() const {
    return level;
}


double Warrior::getHp() const {
    return hp;
}



double Warrior::getMaxhp() const {
    return (level*20 + 100);
}
