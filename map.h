#pragma once
# include <string>
# include <vector>
# include <map>
# include <climits>
# include <fstream>
# include <iostream>
# include <cstdlib>
# include "coordinates.h"
# include "hero.h"
# include "monster.h"

using namespace std;

class Map
{
    private:
        int xSize, ySize;
        int treasures;
        Coordinates startPos;
        vector<Coordinates> monsters_coordinates;
    public:
        Map();
        Map(string filename);
        map<Coordinates, int> field;
        int getXSize() const {
            return xSize;
        };

        int getYSize() const {
            return ySize;
        };

        const vector <Coordinates>& getAllMonstersCoordinates()const{
        return monsters_coordinates;
        };
        void randomise(vector<Coordinates> &way);
        Coordinates getStartPos() const { return startPos; };
        int getTreasures();
};
