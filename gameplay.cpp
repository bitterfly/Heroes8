# include "gameplay.h"

bool Gameplay::move(Direction where){
    Coordinates newPosition = dobrincho.position.move(where);
    if (map->field[newPosition] == 0) {
        dobrincho.position = newPosition;
        cout << "Dobrincho at ("<< dobrincho.position.x<<" , "<< dobrincho.position.y<<") yo."<<endl;
        return true;
    }
}

void Gameplay::prompt()
{
    if (dobrincho.position.move(Left).x >= 0) {
        cout << "Left: " << map->field[dobrincho.position.move(Left)]<<endl;
    }
    if (dobrincho.position.move(Right).x < map->getXSize()) {
        cout << "Right: " << map->field[dobrincho.position.move(Right)]<<endl;
    }
    if (dobrincho.position.move(Up).y >= 0) {
        cout << "Up: " << map->field[dobrincho.position.move(Up)]<<endl;
    }
    if (dobrincho.position.move(Down).y < map->getYSize()) {
        cout << "Down: " << map->field[dobrincho.position.move(Down)]<<endl;
    }

    char choice = getch();
    // cin.get(choice);

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
}

Gameplay::Gameplay()
{
    map = new Map("map.txt");
}
