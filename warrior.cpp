# include "warrior.h"

HANDLE jConsole = GetStdHandle(STD_OUTPUT_HANDLE);


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
        this->hp = getMaxhp();
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


void Warrior::barizise(double value, double max_value, int colour){
    SetConsoleTextAttribute(jConsole, colour);
    int total_length = 18;
    int bar_length = (value/max_value)*total_length;
    if(bar_length == 0 && value != 0)
        bar_length = 1;
    for(int i = 0; i < bar_length; i++){
        if(bar_length < 5){
            SetConsoleTextAttribute(jConsole, 12);
        }
        cout<<char(219);
    }
    for(int i = 0; i < total_length - bar_length; i++){
        cout<<' ';
    }
    SetConsoleTextAttribute(jConsole, 7);
}
