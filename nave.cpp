#include "nave.h"

void Nave::setup() {
    this->x = 60;
    this->y = 20;
}

void Nave::draw() {
    mvaddch(this->y, this->x + 2, '^');
    mvaddch(this->y + 1, this->x + 1, '(');
    mvaddch(this->y + 1, this->x + 2, ACS_PLMINUS);
    mvaddch(this->y + 1, this->x + 3, ')');
    mvaddch(this->y + 2, this->x, ACS_ULCORNER);
    mvaddch(this->y + 2, this->x + 1, '#');
    mvaddch(this->y + 2, this->x + 2, ' ');
    mvaddch(this->y + 2, this->x + 3, '#');
    mvaddch(this->y + 2, this->x + 4, ACS_URCORNER);
}

void Nave::setX(int x) { this->x = x; }

void Nave::setY(int y) { this->y = y; }

int Nave::getX() { return this->x; }

int Nave::getY() { return this->y; }
