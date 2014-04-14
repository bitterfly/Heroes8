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

    vector<Coordinates> way;
    while(getline(f, line)) {
        for(x = 0; x < (int)line.size(); x++){
            field[Coordinates(x, y)] = (int)(line[x]) - '0';
            if(field[Coordinates(x, y)] == 0){
                way.push_back(Coordinates(x, y));
            }
            if(field[Coordinates(x, y)] == 8){
                startPos = Coordinates(x, y);
            }
        }
        y++;
    }
    xSize = x;
    ySize = y;

    randomise(way);
}

void Map::print() {
    for(int y = 0;y < ySize; y++){
        for(int x = 0; x < xSize; x++){
            cout<<field[Coordinates(x,y)]<<' ';
        }
        cout<<endl;
    }
}

void Map::randomise(vector<Coordinates> &way){
srand(time(NULL));
int index;

 for(int i = 0; i < 5 && !way.empty(); i ++){
    index = rand() % way.size();
    field[way[index]] = rand() % 2 + 2;
    way.erase(way.begin() + index);
    }
}
