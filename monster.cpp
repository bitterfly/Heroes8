# include "monster.h"

Monster::Monster(){
    level = rand() % 5 + 1;
}

Monster::Monster(string name) {
    this->name = name;
    level = rand() % 5 + 1;
}

double Monster::getDamage() const{
return level*2 + 5;
}

void Monster::print() const {
    cout<<"Monster "<<name<<" ["<<level<<"]"<<endl;
}
