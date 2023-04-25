#include <iostream>
#include <vector>
#include <ncurses.h>
#include "Nave.h"
#include "Asteroide.h"
#include "Proyectil.h"

//const int ANCHO = 10;
//const int ALTO = 10;
const int DELAY = 20;

bool game_over;
int puntaje;
bool salir;
Nave miNave;
std::vector<Asteroide> asteroides;
std::vector<Proyectil> proyectiles;

void setup();
void input();
void update();
void draw();
void gameOver();

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    /*
    if (LINES < ALTO || COLS < ANCHO) {
        endwin();
        printf("la terminal debe tener como minimo %dx%d\n\n", ANCHO, ALTO);
        exit(1);
    }
    */

    setup();
    salir = false;
    while (!salir) {
        while (!game_over) {
            input();
            update();
            draw();
        }
        gameOver();
    }
    endwin();
    std::cout << std::endl;
    return 0;
}

void setup() {
    game_over = false;
    puntaje = 0;
    miNave.setup();
    asteroides.clear();
    proyectiles.clear();
    for(int i = 0; i < 5; i++) {
        asteroides.push_back(Asteroide(rand() % (COLS + 1), 1));
    }
}

void input() {
    int tecla = getch();
    switch (tecla) {
        case KEY_UP:
            if (miNave.getY() > 1) {
                miNave.setY(miNave.getY() - 1);
            }
            break;
        case KEY_DOWN:
            if (miNave.getY() < LINES - 4) {
                miNave.setY(miNave.getY() + 1);
            }
            break;
        case KEY_LEFT:
            if (miNave.getX() > 1) {
                miNave.setX(miNave.getX() - 1);
            }
            break;
        case KEY_RIGHT:
            if (miNave.getX() < COLS - 6) {
                miNave.setX(miNave.getX() + 1);
            }
            break;
        case 27:
            game_over = TRUE;
            break;
        case 'e':
            miNave.setEnergia(miNave.getEnergia() - 1);
            break;
        case 'v':
            //proyectiles.push_back(Proyectil(miNave.getX() + 2, miNave.getY()));
            proyectiles.emplace_back(miNave.getX() + 2, miNave.getY());
        default:
            break;
    }
}

void update() {
    miNave.update();
    if (miNave.getVidas() <= 0) {
        game_over = true;
    }
    for(int i = 0; i < 5; i++) {
        asteroides[i].update();
        asteroides[i].colision(miNave);
    }
    for(int i = 0; i < proyectiles.size(); i++) {
        proyectiles[i].update();
        if (proyectiles[i].limite()) {
            proyectiles.erase(proyectiles.begin() + i);
        }
    }
    for (int i = 0; i < asteroides.size(); ++i) {
        for (int j = 0; j < proyectiles.size(); ++j) {
            if (asteroides[i].getX() == proyectiles[j].getX() and
                (asteroides[i].getY() == proyectiles[j].getY() or asteroides[i].getY() + 1 == proyectiles[j].getY()))
            {
                asteroides.erase(asteroides.begin() + i);
                asteroides.push_back(Asteroide(rand() % (COLS + 1), 1));
                puntaje++;
            }
        }
    }
}

void draw() {
    erase();
    box(stdscr, 0, 0);
    mvprintw(0, 80, "[ENERGIA:      ]");
    for(int i = 0; i < miNave.getEnergia(); i++) {
        mvaddch(0, 91 + i, ACS_CKBOARD);
    }
    mvprintw(0, 100, "[VIDAS:      ]");
    for(int i = 0; i < miNave.getVidas(); i++) {
        mvaddch(0, 109 + i, A_ALTCHARSET | 96);
    }
    mvprintw(0, 5, "[ PUNTOS:      ]");
    mvprintw(0, 15, "%d", puntaje);
    miNave.draw();
    for(int i = 0; i < 5; i++) {
        asteroides[i].draw();
    }
    for(int i = 0; i < proyectiles.size(); i++) {
        proyectiles[i].draw();
    }
    refresh();
    delay_output(DELAY);
}

void gameOver() {
    for(int y = 10; y < 16; y++) {
        mvhline(y, 40, ' ', 40);
    }
    mvaddch(9, 39, ACS_ULCORNER);
    mvaddch(9, 80, ACS_URCORNER);
    mvaddch(16, 39, ACS_LLCORNER);
    mvaddch(16, 80, ACS_LRCORNER);
    mvhline(9, 40, ACS_HLINE, 40);
    mvhline(16, 40, ACS_HLINE, 40);
    mvvline(10, 39, ACS_VLINE, 6);
    mvvline(10, 80, ACS_VLINE, 6);
    mvprintw(12, 55, "GAME OVER");
    mvprintw(13, 50, "VOLVER A JUGAR (S/N)");
    int option = getch();
    if (option == 's' || option == 'S') {
        game_over = false;
        setup();
    } else if (option == 'n' || option == 'N') {
        salir = true;
    }
}
















