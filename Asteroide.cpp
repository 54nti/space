#include "Asteroide.h"

Asteroide::Asteroide(int x, int y) {
    this->x = x;
    this->y = y;
}

void Asteroide::update() {
    this->y = this->y + 1;
    if (this->y >= LINES - 1) {
        this->x = rand() % (COLS - 1) + 1;
        this->y = 1;
    }
}

void Asteroide::draw() {
    mvaddch(this->y, this->x, '*');
}
