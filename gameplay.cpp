# include "gameplay.h"

bool Gameplay::move(Direction where){
    Coordinates newPosition = dobrincho.position.move(where);
    if (the_map->field[newPosition] != 1)
    {
        if (newPosition.x < 0 || newPosition.x >= the_map->getXSize()
        || newPosition.y < 0 || newPosition.y >= the_map->getYSize()) {
            return false;
        }
        else {
            dobrincho.position = newPosition;
            return true;
        }
    }
    else {
        return false;
    }
}


void Gameplay::printMap() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
            if (dobrincho.position == Coordinates(x, y)) {
                SetConsoleTextAttribute(hConsole, 14);
                cout<<(char)2;

            }
            else {
                switch(the_map->field[Coordinates(x,y)]) {
                    case 1:
                        SetConsoleTextAttribute(hConsole, 2);
                        cout<<(char)176;
                        break;
                    default:
                        SetConsoleTextAttribute(hConsole, 7);
                        cout<<' ';
                }
            }
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
    system("CLS");

    printMap();
/*
    if (dobrincho.position.move(Left).x >= 0) {
        cout << "Left: " << the_map->field[dobrincho.position.move(Left)]<<endl;
    }
    if (dobrincho.position.move(Right).x < the_map->getXSize()) {
        cout << "Right: " << the_map->field[dobrincho.position.move(Right)]<<endl;
    }
    if (dobrincho.position.move(Up).y >= 0) {
        cout << "Up: " << the_map->field[dobrincho.position.move(Up)]<<endl;
    }
    if (dobrincho.position.move(Down).y < the_map->getYSize()) {
        cout << "Down: " << the_map->field[dobrincho.position.move(Down)]<<endl;
    }

    */
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

Gameplay::Gameplay()
{
    the_map = new Map("map.txt");

    // spawn the hero
    dobrincho.position = the_map->getStartPos();

    // spawn a monster at every monster spot
    for (int i = 0; i < the_map->getAllMonstersCoordinates().size(); i++){
        monstersInc[the_map->getAllMonstersCoordinates()[i]] = Monster();
    }
}

void Gameplay::printMonsters()
{
    for (map<Coordinates, Monster>::iterator iter = monstersInc.begin(); iter != monstersInc.end(); iter++) {
        (*iter).first.print();
        cout<<" ";
        (*iter).second.print();
    }
}
