#pragma once

#include <iostream>
#include <ncurses.h>

class Proyectil {
    private:
        int x;
        int y;
    public:
        Proyectil(int, int);
        void update();
        void draw();
        bool limite();
        int getX();
        int getY();
};
