# include "map.h"
Map::Map(){
}
Map::Map(string filename){
    ifstream f;
    f.open(filename.c_str());
    if (!f.is_open()) {
        cout << "fuck you" << endl;
        return;
    }
    string line;
    int x, y = 0;
    while(getline(f, line)) {
        for(x = 0; x < (int)line.size(); x++){
            field[Coordinates(x, y)] = (int)(line[x]) - '0';
        }
        y++;
    }
    xSize = x;
    ySize = y;
}

void Map::print() {
    for(int y = 0;y < ySize; y++){
        for(int x = 0; x < xSize; x++){
            cout<<field[Coordinates(x,y)]<<' ';
        }
        cout<<endl;
    }
}
