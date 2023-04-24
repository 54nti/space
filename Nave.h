#pragma once

#include <iostream>
#include "ncurses.h"

class Nave {
    private:
        int x;
        int y;
        int energia;
        int vidas;
        bool explotar;
    public:
        void setup();
        void update();
        void draw();
        void setX(int);
        void setY(int);
        int getX();
        int getY();
        void setEnergia(int);
        int getEnergia();
        void setVidas(int);
        int getVidas();
};
