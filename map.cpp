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
    for(int i = 0; i < xSize; i++){
        for(int j = 0; j < ySize; j++){
            cout<<field[Coordinates(i,j)]<<' ';
        }
        cout<<endl;
    }
}
