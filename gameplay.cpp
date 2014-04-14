# include "gameplay.h"

bool Gameplay::move(Direction where){
    Coordinates newPosition = dobrincho.position.move(where);
    if (map->field[newPosition] != 1)
    {
        if (newPosition.x < 0 || newPosition.x >= map->getXSize()
        || newPosition.y < 0 || newPosition.y >= map->getYSize()) {
            cout << "Can't go out of map."<<endl;
            return false;
        }
        else {
            dobrincho.position = newPosition;
            cout << "Dobrincho at ("<< dobrincho.position.x<<" , "<< dobrincho.position.y<<") yo."<<endl;
            return true;
        }
    }
    else {
        cout << "Can't step on 1, biatch!"<<endl;
        return false;
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
    dobrincho.position = map->getStartPos();
    map->print();
}
