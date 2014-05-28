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
    if(this->exp >= 50){
        level++;
        this->exp = this->exp  - 100;
        hp = getMaxhp();
    }
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


bool Hero::hasItem(Item& item) {
    for(int i = 0; i < backpack.size(); i++) {
        if (&item == backpack[i])
            return true;
    }
    return false;
}


void Hero::add(Item &item){
    int choice;
    while(weight() + item.getWeight() > level*10 + 8){
        cout<<"Your backpack is too heavy. You should drop an item: ";
        cin>>choice;
        drop(choice);
    }
    backpack.push_back(&(item));

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
