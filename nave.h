#pragma once

#include <iostream>
#include "ncurses.h"

class Nave {
    private:
        int x;
        int y;
    public:
        void setup();
        void draw();
        void setX(int);
        void setY(int);
        int getX();
        int getY();
};
