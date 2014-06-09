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
    hero.position = the_map->getStartPos();
    string name;
    cout<<"Enter your name: ";
    getline(cin, name);
    hero.setName(name);
    system("CLS");
    /* Произволно разпределяне на чудовища. */
    for (int i = 0; i < (int)the_map->getAllMonstersCoordinates().size(); i++){
        monstersInc[the_map->getAllMonstersCoordinates()[i]] = Monster(monster_names[rand() % monster_names.size()]);
    }
    /* Стартов пакет. */
    items.push_back(Item(10, 0, 3, 0, "Common sword", "Newbie package"));
    items.push_back(Item(10, 0, 0, 3, "Common shield", "Newbie package"));
    hero.backpack.push_back(&(items[items.size()-1]));
    hero.backpack.push_back(&(items[items.size()-2]));
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
    if(hero.getHp() <= 0){
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
    if (hero.position == position) {
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
            SetConsoleTextAttribute(hConsole, 3);
            cout<<monstersInc[position].getLevel();
            break;
        case 7:
            SetConsoleTextAttribute(hConsole, 12);
            cout<<(char)233;
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
    hero.setHp(hero.getHp() + 0.1);
    Coordinates newPosition = hero.position.move(where);
    Coordinates oldPosition = hero.position;
    if (the_map->field[newPosition] != 1)
    {
        if (newPosition.x < 0 || newPosition.x >= the_map->getXSize()
        || newPosition.y < 0 || newPosition.y >= the_map->getYSize()) {
            return false;
        }
        else {
            hero.position = newPosition;
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
                    the_map->field[newPosition] = 0;
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
    // printUnderMap(true);
    Event& event = events[rand() % events.size()];
    cout<<event.getTxt();
    if(event.getHasItem()){
        add();
    }
    hero.setHp(hero.getHp() + event.getHp());
    hero.setMana(hero.getMana() + event.getMana());
    hero.setExp(hero.getExp() + event.getExp());
    printUnderMap(false);
}


void Gameplay::fight(){
    double hero_damage;
    int choice;
    Monster& monster = monstersInc[hero.position];
    COORD pos;
    system("CLS");
    cout<<"There's a monster on your way! "<<endl;
    getch();
    system("CLS");
    pos.X = 0;
    if(hero.getWeapons() == 0){
        pos.Y = 30;
        SetConsoleCursorPosition(hConsole, pos);
        cout<<"It seems you don't have any weapons. You search your pockets and find a spoon inside!"<<endl;
        hero.backpack.push_back(new Item(0, 0, 0.3, 0, "Spoon!", "Not the sex position."));
    }
    pos.Y = 10;
    while(hero.getHp() > 0 && monster.getHp() > 0){
        monster.lifeBar(Coordinates(25, 0));
        hero.lifeBar(Coordinates(0, 0), false);

        do {
            SetConsoleCursorPosition(hConsole, pos);
            cout<<endl<<"Choose wisely: ";
            COORD pos2 = pos;
            pos2.X += strlen("Choose wisely: ");
            pos2.Y++;
            cout<<"   ";
            SetConsoleCursorPosition(hConsole, pos2);
            cin>>choice;
        } while (choice < 0 || choice > hero.backpack.size());
        Item* item = hero.backpack[choice - 1];

        if(hero.backpack[0]->getName() == "Spoon!")
            cout<<"...and again..."<<endl;

        // Health & Mana potion:
        if(item->getDamage() == 0 && item->getDefense() == 0){
            if(item->getWeight() == 1)
                hero.setHp(hero.getHp() + 25);
            else
                hero.setMana(hero.getMana() + 25);
            hero.drop(choice - 1);
            // printUnderMap(true);
            // cin>>choice;
            // Item* item = hero.backpack[choice - 1];
        } else {
            //End.

            hero.setMana(hero.getMana() - item->getManaCost());

            if(hero.getMana() > 0)
                hero_damage = item->getDamage() + hero.getLevel()*5;
            else{
                hero.setMana(0);
                hero_damage = item->getDamage();
            }

            monster.setHp(monster.getHp() - hero_damage);
            double monster_damage = monster.getDamage() - hero.getDefense();
            if(monster_damage < 0)
                monster_damage = 0;
            hero.setHp(hero.getHp() - monster_damage);
        }
    }
    system("CLS");
    if (hero.getHp() > 0) {
        hero.setExp(hero.getExp() + monster.getLevel()*50);
        printUnderMap(true);
        add();
        system("CLS");
        printMap();
        printUnderMap();
    }
}


void Gameplay::add(){
    Item& item = items[rand() % items.size()];
    if(!hero.hasItem(item)){
        cout<<endl<<"You receive a/n "<<item.getName()<<": "<<item.getDescription()<<endl;
        cout<<"Do you want to keep it? y/n ";
        char choice;
        cin>>choice;
        if(choice != 'y')
            return;
    } else {
        getch();
        return;
    }

    int choice;
    int capacity = hero.getLevel()*20 + 30;
    if(item.getWeight() > capacity){
        cout<<"The item is too heavy for you."<<endl;
        return;
    }
    while(hero.weight() + item.getWeight() > capacity){
        cout<<"current weight: "<<hero.weight()<<endl;
        cout<<"Your backpack is too heavy. You should drop an item: ";
        cin>>choice;
        hero.drop(choice - 1);
        printUnderMap(true);
    }
    hero.backpack.push_back(&(item));

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
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j <= columns; j++) {
                cout<<' ';
            }
        }
        pos.X = 0;
        pos.Y = the_map->getYSize() + 2;
        SetConsoleCursorPosition(hConsole, pos);
    }
    hero.lifeBar(Coordinates(0, the_map->getYSize()+10));
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
