#pragma once

#include <iostream>
#include "ncurses.h"

class Nave {
    private:
        int m_x;
        int m_y;
    public:
        void setup();
        void draw();
        void setX(int);
        void setY(int);
        int getX();
        int getY();
};
