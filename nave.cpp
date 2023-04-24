#include "nave.h"

void Nave::setup() {
    m_x = 60;
    m_y = 20;
}

void Nave::draw() {
    mvaddch(m_y, m_x + 2, '^');
    mvaddch(m_y + 1, m_x + 1, '^');
}
