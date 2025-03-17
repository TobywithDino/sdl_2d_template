#pragma once

class Coord2D
{
public:
    Coord2D() {this->x=0;this->y=0;}
    Coord2D(int x, int y) {this->x=x;this->y=y;}
    int x=0;
    int y=0;
};