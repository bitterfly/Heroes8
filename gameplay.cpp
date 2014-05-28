# include "gameplay.h"
/*
Gameplay()
prompt()
printMap()
printSpot()
move(Direction)
event()
fight()
printUnderMap()
heroLifeBar()
read
print
*/

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Gameplay::Gameplay()
{
    treasures = 0;
    the_map = new Map("map.txt");
    readMonsterNames("names.txt");
    readEvents("event.txt");
    readItems("items.txt");
    /* Създаване на герой. */
    dobrincho.position = the_map->getStartPos();
    string name;
    cout<<"Enter your name: ";
    getline(cin, name);
    dobrincho.setName(name);
    system("CLS");
    /* Произволно разпределяне на чудовища. */
    for (int i = 0; i < (int)the_map->getAllMonstersCoordinates().size(); i++){
        monstersInc[the_map->getAllMonstersCoordinates()[i]] = Monster(monster_names[rand() % monster_names.size()]);
    }
    /* Стартов пакет. */
    items.push_back(Item(10, 0, 3, 0, "Common sword", "Newbie package"));
    items.push_back(Item(10, 0, 0, 3, "Common shield", "Newbie package"));
    dobrincho.backpack.push_back(&(items[items.size()-1]));
    dobrincho.backpack.push_back(&(items[items.size()-2]));
    /* Пинтиране на карта. */
    printMap();
    printUnderMap();
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
    if(dobrincho.getHp() <= 0){
        system("CLS");
        cout<<"GAME OVER"<<endl;
        return false;
    }

    if(treasures == the_map->getTreasures()){
        system("CLS");
        cout<<"You win! "<<endl;
        return false;
    }

    return true;
}


void Gameplay::printMap() {
        /* Горна рамка. */
        cout<<(char)201;
        for(int y = 0;y < ((the_map->getYSize())*2)+6; y++){
            cout<<(char)205;
        }
        cout<<(char)187<<endl;
        /* Край на горна рамка. */
        for(int y = 0;y < the_map->getYSize(); y++){
            cout<<(char)186;
            for(int x = 0; x < the_map->getXSize(); x++){
                printSpot(Coordinates(x, y));
            }
            SetConsoleTextAttribute(hConsole, 7);
            cout<<(char)186;
            cout<<endl;
        }
    /* Долна рамка. */
        cout<<(char)200;
        for(int y = 0;y < ((the_map->getYSize())*2)+6; y++){
            cout<<(char)205;
        }
    cout<<(char)188<<endl;
    /* Край на долна рамка. */
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
            printUnderMap();
            switch(the_map->field[newPosition]) {
                case 2:
                    the_map->field[newPosition] = 0;
                    fight();
                    break;
                case 3:
                    the_map->field[newPosition] = 0;
                    event();

                    break;
                case 7:
                    cout<<"You found a trasure!"<<endl;
                    treasures++;
                    break;
            }

            return true;
        }

    }
    else
        return false;

}


void Gameplay::event(){
    char choice;
    printUnderMap(true);
    Event& event = events[rand() % events.size()];
    cout<<event.getTxt();
    if(event.getHasItem()){
        Item& item = items[rand() % items.size()];
        if(!dobrincho.hasItem(item)){
            cout<<endl<<"You found a/n "<<item.getName()<<" which gives you"<<item.getDescription()<<endl;
            cout<<"Do you want to keep it? y/n ";
            cin>>choice;
            if(choice == 'y')
                dobrincho.add(item);
            }
    }
    dobrincho.setHp(dobrincho.getHp() + event.getHp());
    dobrincho.setMana(dobrincho.getMana() + event.getMana());
    dobrincho.setExp(dobrincho.getExp() + event.getExp());
}


void Gameplay::fight(){
    double hero_damage;
    int choice;
    Monster& monster = monstersInc[dobrincho.position];
    COORD pos;
    system("CLS");
    cout<<"There's a monster on your way! "<<endl;
    getch();
    system("CLS");
    pos.Y = 10;
    pos.X = 0;

    while(dobrincho.getHp() > 0 && monster.getHp() > 0){

        monster.lifeBar(Coordinates(25, 0));
        dobrincho.lifeBar(Coordinates(0, 0));

        SetConsoleCursorPosition(hConsole, pos);
        cout<<endl<<"Choose wisely: ";
        cin>>choice;
        Item* item = dobrincho.backpack[choice - 1];

        // Health & Mana potion:
        if(item->getDamage() == 0 && item->getDefense() == 0){
            if(item->getWeight() == 1)
                dobrincho.setHp(dobrincho.getHp() + 25);
            else
                dobrincho.setMana(dobrincho.getMana() + 25);
            cin>>choice;
            Item* item = dobrincho.backpack[choice - 1];
        }
        //End.

        dobrincho.setMana(dobrincho.getMana() - item->getManaCost());

        if(dobrincho.getMana() > 0)
            hero_damage = item->getDamage() + dobrincho.getLevel()*5;
        else{
            dobrincho.setMana(0);
            hero_damage = item->getDamage();
        }

        monster.setHp(monster.getHp() - hero_damage);
        dobrincho.setHp(dobrincho.getHp() - monster.getDamage() + item->getDefense());
    }
    system("CLS");
    if (dobrincho.getHp() > 0) {
        printMap();
        printUnderMap();
    }
}


void Gameplay::printUnderMap(bool clear) {
    COORD pos;
    if (clear) {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        int columns = csbi.srWindow.Right - csbi.srWindow.Left, rows = csbi.srWindow.Bottom - csbi.srWindow.Top;
        pos.X = 0;
        pos.Y = the_map->getYSize() + 2;
        SetConsoleCursorPosition(hConsole, pos);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < columns; j++) {
                cout<<' ';
            }
            cout<<endl;
        }
        pos.X = 0;
        pos.Y = the_map->getYSize() + 2;
        SetConsoleCursorPosition(hConsole, pos);
    }
    dobrincho.lifeBar(Coordinates(0, the_map->getYSize()+10));
    pos.X = 0;
    pos.Y = the_map->getYSize() + 2;
    SetConsoleCursorPosition(hConsole, pos);
}


void Gameplay::readItems(string filename){
    ifstream stream;
    stream.open(filename.c_str());
    if(!stream.is_open()){
        cout<<"File not found."<<endl;
        return;
    }
    while(!stream.eof()){
        items.push_back(Item(stream));
    }
    stream.close();
}


void Gameplay::readEvents(string filename){
    ifstream stream;
    stream.open(filename.c_str());
    if(!stream.is_open()){
        cout<< "File not found." <<endl;
        return;
    }
    int i = 0;
    while(!stream.eof()){
        events.push_back(Event(stream));
    }
    stream.close();
}


void Gameplay::readMonsterNames(string filename){
    ifstream f;
    f.open(filename.c_str());
    if (!f.is_open()) {
        cout << "File not found." << endl;
        return;
    }
    string line;
    while(getline(f, line)) {
        monster_names.push_back(line);
    }
    f.close();
}


void Gameplay::printMonsters(){
    for (map<Coordinates, Monster>::iterator iter = monstersInc.begin(); iter != monstersInc.end(); iter++) {
        (*iter).first.print();
        cout<<" ";
        (*iter).second.print();
    }
}

void Gameplay::printEvents(){
    for (int i = 0; i < (int)events.size(); i++){
        events[i].print();
    }
}


void Gameplay::printItems(){
    for(int i = 0; i < (int)items.size(); i++){
        items[i].print();
    }
}
