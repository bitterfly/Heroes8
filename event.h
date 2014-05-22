# pragma once

# include <iostream>
# include <string>

using namespace std;

class Event{
private:
    double hp,mana;
    int exp;
    string txt;
public:
    Event();
    Event(istream & stream);
    void print();
};
