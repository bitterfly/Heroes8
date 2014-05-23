# include "gameplay.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


Gameplay::Gameplay()
{
    the_map = new Map("map.txt");
    readMonsterNames("names.txt");
    readEvents("event.txt");
    // spawn the hero
    dobrincho.position = the_map->getStartPos();

    // spawn a monster at every monster spot
    for (int i = 0; i < the_map->getAllMonstersCoordinates().size(); i++){
        monstersInc[the_map->getAllMonstersCoordinates()[i]] = Monster(monster_names[rand() % monster_names.size()]);
    }
    printMap();
    heroLifeBar();
    //printMonsters();
    //printEvents();
}


bool Gameplay::move(Direction where){
    Coordinates newPosition = dobrincho.position.move(where);
    Coordinates oldPosition = dobrincho.position;
    if (the_map->field[newPosition] != 1)
    {
        if (newPosition.x < 0 || newPosition.x >= the_map->getXSize()
        || newPosition.y < 0 || newPosition.y >= the_map->getYSize()) {
            return false;
        }
        else {
            dobrincho.position = newPosition;
            printSpot(oldPosition, true);
            printSpot(newPosition, true);

            switch(the_map->field[newPosition]) {
                case 2:
                    the_map->field[newPosition] = 0;
                    fight();
                    break;
                case 3:
                    the_map->field[newPosition] = 0;
                    event();
                    break;
            }

            return true;
        }

    }
    else {
        return false;
    }
}


void Gameplay::heroLifeBar(){
COORD pos;
pos.X = 0;
pos.Y = the_map->getYSize() + 4;
SetConsoleCursorPosition(hConsole, pos);

cout<<dobrincho.getName()<<" ["<<dobrincho.getLevel()<<"]"<<endl;
cout<<setfill(' ')<<setw(4);
cout<<"HP:   "<<dobrincho.getHp()<<endl;
cout<<"Mana: "<<dobrincho.getMana()<<endl;
cout<<"Exp:  "<<dobrincho.getExp()<<endl;
}


void Gameplay::event(){
Event& event = events[rand() % events.size()];
cout<<event.getTxt();
dobrincho.setHp(dobrincho.getHp() + event.getHp());
dobrincho.setMana(dobrincho.getMana() + event.getMana());
dobrincho.setExp(dobrincho.getExp() + event.getExp());
heroLifeBar();
}


void Gameplay::fight(){
cout<<"FIGHT!"<<endl;
}


void Gameplay::printSpot(Coordinates position, bool single) {
    COORD pos;
    if (single) {
        pos.X = position.x + 1;
        pos.Y = position.y + 1;
        SetConsoleCursorPosition(hConsole, pos);
    }
    if (dobrincho.position == position) {
        SetConsoleTextAttribute(hConsole, 14);
        cout<<(char)2;
    }
    else {
        switch(the_map->field[position])
        {
        case 1:
            SetConsoleTextAttribute(hConsole, 2);
            cout<<(char)176;
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, 2);
            cout<<'!';
            break;
        case 3:
            SetConsoleTextAttribute(hConsole, 2);
            cout<<'*';
            break;
        default:
            SetConsoleTextAttribute(hConsole, 7);
            cout<<' ';
        }
    }
    if (single) {
        SetConsoleTextAttribute(hConsole, 7);
        pos.X = 0;
        pos.Y = the_map->getYSize() + 2;
        SetConsoleCursorPosition(hConsole, pos);
    }
}

void Gameplay::printMap() {
    //Горна рамка
    cout<<(char)201;
    for(int y = 0;y < ((the_map->getYSize())*2)+6; y++){
        cout<<(char)205;
    }
    cout<<(char)187<<endl;
    // Край на горна рамка
    for(int y = 0;y < the_map->getYSize(); y++){
        cout<<(char)186;
        for(int x = 0; x < the_map->getXSize(); x++){
            printSpot(Coordinates(x, y));
        }
        SetConsoleTextAttribute(hConsole, 7);
        cout<<(char)186;
        cout<<endl;
    }
//Долна рамка
    cout<<(char)200;
    for(int y = 0;y < ((the_map->getYSize())*2)+6; y++){
        cout<<(char)205;
    }
cout<<(char)188<<endl;
//Край на долна рамка.
}


bool Gameplay::prompt()
{
char choice = getch();
switch(choice) {
    case 'a':
        move(Left);
        break;
    case 'd':
        move(Right);
        break;
    case 'w':
        move(Up);
        break;
    case 's':
        move(Down);
        break;
}

return (dobrincho.getHp() > 0);
}


void Gameplay::readMonsterNames(string filename)
{
    ifstream f;
    f.open(filename.c_str());
    if (!f.is_open()) {
        cout << "fuck you" << endl;
        return;
    }
    string line;
    while(getline(f, line)) {
        monster_names.push_back(line);
    }
    f.close();
}


void Gameplay::readEvents(string filename){
ifstream stream;
stream.open(filename.c_str());
if(!stream.is_open()){
    cout<< "I won't fuck you" <<endl;
    return;
}
while(!stream.eof()){
    events.push_back(Event(stream));
}
stream.close();
}


void Gameplay::readItems(string filename){
    ifstream stream;
    stream.open(filename.c_str());
    if(!stream.is_open()){
        cout<<"Noo"<<endl;
        return;
    }
    while(!stram.eof()){
        items.push_back(Item(stream));
    }
    stream.close();
}


void Gameplay::printMonsters()
{
    for (map<Coordinates, Monster>::iterator iter = monstersInc.begin(); iter != monstersInc.end(); iter++) {
        (*iter).first.print();
        cout<<" ";
        (*iter).second.print();
    }
}

void Gameplay::printEvents()
{
    for (int i = 0; i < events.size(); i++){
    events[i].print();
    }

}
