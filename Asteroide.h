#pragma once

#include <iostream>
#include <ncurses.h>
#include "Nave.h"

class Asteroide {
    private:
        float x;
        float y;
    public:
        Asteroide(int, int);
        void update();
        void draw();
        void colision(Nave& nave);
        int getX();
        int getY();
};