# pragma once
# include <iostream>

using namespace std;


enum Direction {
    Left,
    Right,
    Up,
    Down
};

struct Coordinates{
    int x;
    int y;
    Coordinates(){
        x = 0;
        y = 0;
    };
    Coordinates(int x, int y){
        this->x = x;
        this->y = y;
    };
    int cantorise() const {
        return (x + y) * (x + y + 1) / 2 + x;
    };
    bool operator<(const Coordinates& other) const {
        return (this->cantorise() < other.cantorise());
    };
    bool operator==(const Coordinates& other) const {
        return (this->x == other.x && this->y == other.y);
    }
    Coordinates move(Direction where) {
        switch(where) {
        case Left:
            return Coordinates(x - 1, y);
            break;
        case Right:
            return Coordinates(x + 1, y);
            break;
        case Up:
            return Coordinates(x, y - 1);
            break;
        case Down:
            return Coordinates(x, y + 1);
            break;
        }
    };
    void print() const {
        cout<<"<"<<y<<", "<<x<<">";
    }
};
