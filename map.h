#pragma once
# include <string>
# include <vector>
# include <map>
# include <climits>
# include <fstream>
# include <iostream>
# include <cstdlib>
# include <time.h>
# include "coordinates.h"
# include "hero.h"

using namespace std;

class Map
{
    private:
        int xSize, ySize;
        Coordinates startPos;
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
        void print();
        void randomise(vector<Coordinates> &way);
        Coordinates getStartPos() const { return startPos; };

};
