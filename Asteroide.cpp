#include "Asteroide.h"

Asteroide::Asteroide(int x, int y) {
    this->x = x;
    this->y = y;
}

void Asteroide::update() {
    this->y = this->y + 0.2f;
    if (this->y >= LINES - 1) {
        this->x = rand() % (COLS - 1) + 1;
        this->y = 1;
    }
}

void Asteroide::draw() {
    mvaddch(this->y, this->x, '*');
}

void Asteroide::colision(Nave& nave) {
    if ((nave.getX() <= this->x) && (this->x <= (nave.getX() + 4)) &&
        (nave.getY() <= this->y) && (this->y <= (nave.getY() + 3)))
    {
        nave.setEnergia(nave.getEnergia() - 1);
        this->x = rand() % (COLS - 1) + 1;
        this->y = 1;
    }
}

int Asteroide::getX() { return this->x; }

int Asteroide::getY() { return this->y; }
