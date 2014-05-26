# include "monster.h"

HANDLE pConsole = GetStdHandle(STD_OUTPUT_HANDLE);


Monster::Monster(){
    level = rand() % 5 + 1;
}

Monster::Monster(string name) {
    this->name = name;
    level = rand() % 5 + 1;
    hp = getMaxhp();
}

double Monster::getDamage() const{
return level*2 + 5;
}

void Monster::print() const {
    cout<<"Monster "<<name<<" ["<<level<<"]"<<endl;
}

void Monster::printSelfie(){
  ifstream f;
    f.open("monster_selfie.txt");
    if (!f.is_open()) {
        return;
    }
    string line;
    while(getline(f, line)) {
        cout<<line<<endl;
    }
    f.close();
}

void Monster::lifeBar(){
cout<<getName()<<" ["<<getLevel()<<"]"<<endl;
cout<<setfill(' ');
cout<<"HP: "<<setw(4)<<getHp()<<endl;
}

void Monster::lifeBar(Coordinates position){
COORD pos;
pos.X = position.x;
pos.Y = position.y;

SetConsoleCursorPosition(pConsole, pos);
cout<<getName()<<" ["<<getLevel()<<"]"<<endl;
cout<<setfill(' ');

pos.Y++;
SetConsoleCursorPosition(pConsole, pos);
cout<<"HP: "<<setw(4)<<getHp()<<endl;
}
