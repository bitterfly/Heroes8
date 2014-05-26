# include "hero.h"

HANDLE rConsole = GetStdHandle(STD_OUTPUT_HANDLE);


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

void Hero::setMana(double mana){
this->mana = mana;
if(this->mana > getMaxMana())
    this->mana = getMaxMana();
if(this->mana <= 0)
    this->mana = 0;
}

void Hero::setExp(int exp){
this->exp = exp;
if(this->exp >=100){
    level++;
    this->exp = this->exp  - 100;
    hp = getMaxhp();
}
}

bool Hero::hasItem(Item& item) {
    for (int i = 0; i < backpack.size(); i++) {
        if (&item == backpack[i])
            return true;
    }
    return false;
}

void Hero::lifeBar(){
cout<<getName()<<" ["<<getLevel()<<"]"<<endl;
cout<<setfill(' ')<<setw(4);
cout<<"HP:   "<<getHp()<<endl;
cout<<"Mana: "<<getMana()<<endl;
cout<<"Exp:  "<<getExp()<<endl;
    for(int i = 0; i < (int)backpack.size(); i++) {
        cout<<"["<<i+1<<"] ";
        backpack[i]->print();
    }
}


void Hero::lifeBar(Coordinates position){
COORD pos;
pos.X = position.x;
pos.Y = position.y;

SetConsoleCursorPosition(rConsole, pos);
cout<<getName()<<" ["<<getLevel()<<"]"<<endl;
cout<<setfill(' ');


pos.Y++;
SetConsoleCursorPosition(rConsole, pos);
cout<<"HP:   "<<setw(4)<<getHp()<<endl;

pos.Y++;
SetConsoleCursorPosition(rConsole, pos);
cout<<"Mana: "<<setw(4)<<getMana()<<endl;

pos.Y++;
SetConsoleCursorPosition(rConsole, pos);
cout<<"Exp:  "<<setw(4)<<getExp()<<endl;

    for(int i = 0; i < (int)backpack.size(); i++) {
        pos.Y++;
SetConsoleCursorPosition(rConsole, pos);
        cout<<"["<<i+1<<"]";
        backpack[i]->print();
    }
}
