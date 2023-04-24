#include "nave.h"

void Nave::setup() {
    m_x = 60;
    m_y = 20;
}

void Nave::draw() {
    mvaddch(m_y, m_x + 2, '^');
    mvaddch(m_y + 1, m_x + 1, '(');
    mvaddch(m_y + 1, m_x + 2, ACS_PLMINUS);
    mvaddch(m_y + 1, m_x + 3, ')');
    mvaddch(m_y + 2, m_x, ACS_ULCORNER);
    mvaddch(m_y + 2, m_x + 1, '#');
    mvaddch(m_y + 2, m_x + 2, ' ');
    mvaddch(m_y + 2, m_x + 3, '#');
    mvaddch(m_y + 2, m_x + 4, ACS_URCORNER);
}

void Nave::setX(int x) { m_x = x; }

void Nave::setY(int y) { m_y = y; }

int Nave::getX() { return m_x; }

int Nave::getY() { return m_y; }
