#pragma once
# include "item.h"
# include <vector>
using namespace std;


class Backpack
{
private:
    double capacity;
public:
    double getCapacity() const {
    return this->capacity;
    };
    vector<Item> items;
    Backpack();
    Backpack(double capacity);
};
