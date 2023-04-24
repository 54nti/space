#pragma once

#include <iostream>
#include <ncurses.h>

class Asteroide {
    private:
        float x;
        float y;
    public:
        Asteroide(int, int);
        void update();
        void draw();
};