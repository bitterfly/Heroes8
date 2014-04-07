#pragma once
# include <string>
# include <vector>
# include <map>
# include <climits>
# include <fstream>
# include <iostream>
# include "coordinates.h"
# include "hero.h"

using namespace std;

class Map
{
    private:
        int xSize, ySize;
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
};
