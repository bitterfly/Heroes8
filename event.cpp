# include "event.h"

Event::Event(){
}

Event::Event(istream & stream){
stream>>exp>>hp>>mana>>has_item;
getline(stream, txt);
}

void Event::print(){
cout<<exp<<' '<<txt<<endl;
}

string const & Event::getTxt()const{
    return txt;
}
double Event::getHp() const {
    return hp;
}

double Event::getMana() const {
    return mana;
}

int Event::getExp() const {
    return exp;
}

bool Event::getHasItem() const {
    return has_item;
}
