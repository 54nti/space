#include "nave.h"

void Nave::setup() {
    this->x = 60;
    this->y = 20;
    this->energia = 3;
    this->vidas = 3;
    this->explotar = false;
}

void Nave::update() {
    if (this->energia == 0) {
        this->explotar = true;
        this->vidas--;
        this->energia = 3;
    }
}

void Nave::draw() {
    if (!this->explotar) {
        mvaddch(this->y, this->x + 2, '^');
        mvaddch(this->y + 1, this->x + 1, '(');
        mvaddch(this->y + 1, this->x + 2, ACS_PLMINUS);
        mvaddch(this->y + 1, this->x + 3, ')');
        mvaddch(this->y + 2, this->x, ACS_ULCORNER);
        mvaddch(this->y + 2, this->x + 1, '#');
        mvaddch(this->y + 2, this->x + 2, ' ');
        mvaddch(this->y + 2, this->x + 3, '#');
        mvaddch(this->y + 2, this->x + 4, ACS_URCORNER);
    } else {
        mvprintw(this->y, this->x - 2, "   ***   ");
        mvprintw(this->y + 1, this->x - 2, "   *****   ");
        mvprintw(this->y + 2, this->x - 2, "   ***   ");
        refresh();
        delay_output(200);
        mvprintw(this->y - 1, this->x - 3, ".    *    .");
        mvprintw(this->y, this->x - 2, "**    *   **");
        mvprintw(this->y + 1, this->x - 3, "*  *    *  *");
        mvprintw(this->y + 2, this->x - 2, "**    *   **");
        mvprintw(this->y + 1, this->x - 3, ".    *    .");
        refresh();
        delay_output(200);
        this->explotar = false;
    }
}

void Nave::setX(int x) { this->x = x; }

void Nave::setY(int y) { this->y = y; }

int Nave::getX() { return this->x; }

int Nave::getY() { return this->y; }

void Nave::setEnergia(int energia) {
    this->energia = energia;
}

int Nave::getEnergia() { return this->energia; }

void Nave::setVidas(int vidas) {
    this->vidas = vidas;
}

int Nave::getVidas() { return this->vidas; }
