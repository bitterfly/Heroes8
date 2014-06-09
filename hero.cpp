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


void Hero::setMana(double mana){
    this->mana = mana;
    if(this->mana > getMaxMana())
        this->mana = getMaxMana();
    if(this->mana <= 0)
        this->mana = 0;
}

void Hero::setExp(int exp){
    this->exp = exp;
    if(exp >= 100)
        this->hp = getMaxhp();
    level += exp / 100;
    this->exp %= 100;
}


int Hero::getWeapons() const{
    int weapons = 0;
    for(int i = 0; i < backpack.size(); i++)
        if(backpack[i]->getDamage() > 0)
            weapons ++;
    return weapons;
}


int Hero::getExp() const {
    return exp;
}


double Hero::getMana() const {
    return mana;
}


double Hero::getMaxMana() const {
    return level*10 + 25;
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


void Hero::lifeBar(Coordinates position, bool all_items){
    COORD pos;
    pos.X = position.x;
    pos.Y = position.y;

    SetConsoleCursorPosition(rConsole, pos);
    cout<<getName()<<" ["<<getLevel()<<"]"<<endl;
    cout<<setfill(' ');


    pos.Y++;
    SetConsoleCursorPosition(rConsole, pos);
    cout<<"HP:   ";
    barizise(getHp(),getMaxhp(),2);
    cout<<' '<<setw(4)<<getHp()<<endl;

    pos.Y++;
    SetConsoleCursorPosition(rConsole, pos);
    cout<<"Mana: ";
    barizise(getMana(),getMaxMana(),3);
    cout<<' '<<setw(4)<<getMana()<<endl;

    pos.Y++;
    SetConsoleCursorPosition(rConsole, pos);
    cout<<"Exp:  "<<setw(4)<<getExp()<<endl;


    for(int i = 0; i < (int)backpack.size(); i++){
        if(((backpack[i]->getDamage() == 0 && backpack[i]->getDefense() == 0) || backpack[i]->getDamage() > 0) || all_items){
            pos.Y++;
            SetConsoleCursorPosition(rConsole, pos);
            cout<<"["<<i+1<<"]";
            backpack[i]->print();
        }
    }
}


bool Hero::hasItem(Item& item) {
    if(item.getName() == "Common sword" || item.getName() == "Common shield")
        return true;
    for(int i = 0; i < backpack.size(); i++) {
        if (&item == backpack[i]){
            cout<<"Phew, you already have a/n "<<item.getName()<<" What a luck! "<<endl;
            return true;
        }
    }
    return false;
}


void Hero::drop(int index){
    backpack.erase(backpack.begin() + index);
}


double Hero::weight(){
    double backpack_weight = 0;
    for(int i = 0; i < backpack.size(); i++){
        backpack_weight += backpack[i]->getWeight();
    }
    return backpack_weight;
}


double Hero::getDefense(){
    double defense = 0;
    for(int i = 0; i < backpack.size(); i++){
        defense += backpack[i]->getDefense();
    }
    return defense;
}
