#pragma once
# include "monster.h"
# include "coordinates.h"
# include <vector>
# include <map>
class Map
{
    private:
    public:
        Map();
        Map(string filename);
        map<Coordinates, int> field;
};
