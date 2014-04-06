#pragma once
# include <iostream>
# include <string>
using namespace std;


class Item
{
private:
    string name;
    string description;
    double weight;
    double manaCost;

public:
    Item(){
    };
    Item(string name, string descripiton, double weight, double manaCost);
    string getName() const{
    return this->name;
    };
    string getdescription() const{
    return this->description;
    };
    double getWeight() const{
    return this->weight;
    };
    double getManaCost() const{
    return this->manaCost;
    };
};
