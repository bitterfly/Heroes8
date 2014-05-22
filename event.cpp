# include "event.h"

Event::Event(){
}

Event::Event(istream & stream){
stream>>exp>>hp>>mana;
getline(stream, txt);
}

void Event::print(){
cout<<exp<<' '<<txt<<endl;
}
