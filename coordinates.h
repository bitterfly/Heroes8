#pragma once
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
    bool operator<(const Coordinates& b) const {
        return (this->cantorise() < b.cantorise());
    };
};

