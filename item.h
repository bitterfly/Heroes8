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
    double damage;
    double defense;

public:
    Item(){
    };

    Item(double w, double m, double dm, double def, string n, string d){
    name = n;
    description = d;
    weight = w;
    manaCost = m;
    damage = dm;
    defense = def;
    }

    Item(istream & stream){
    stream>>weight>>manaCost>>damage>>defense>>name;
    getline(stream, description);
    };

    string getName() const{
    return this->name;
    };

    string getDescription() const{
    return this->description;
    };

    double getWeight() const{
    return this->weight;
    };

    double getManaCost() const{
    return this->manaCost;
    };

    double getDamage() const{
    return this->damage;
    };

    double getDefense() const{
    return this->defense;
    };

    void print(){
    cout<<name<<endl;
    };
};
