#include "Proyectil.h"

Proyectil::Proyectil(int x, int y) :
    x(x),
    y(y)
{}

void Proyectil::update() {
    if (1 <= this->y) {
        this->y--;
    }
}

void Proyectil::draw() {
    mvaddch(this->y, this->x, '^');
}

bool Proyectil::limite() {
    return (this->y < 1);
}

int Proyectil::getX() { return this->x; }

int Proyectil::getY() { return this->y; }