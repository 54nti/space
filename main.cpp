#include <iostream>
#include <ncurses.h>
#include "nave.h"

const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 20;

bool game_over;
int puntaje;
bool salir;

Nave miNave;

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
}

void input() {
    int tecla = getch();
    switch (tecla) {
        case KEY_UP:
            miNave.setY(miNave.getY() - 1);
            break;
        case KEY_DOWN:
            miNave.setY(miNave.getY() + 1);
            break;
        case KEY_LEFT:
            miNave.setX(miNave.getX() - 1);
            break;
        case KEY_RIGHT:
            miNave.setX(miNave.getX() + 1);
            break;
        case 27:
            game_over = TRUE;
            break;
        default:
            break;
    }
}

void update() {}

void draw() {
    erase();
    box(stdscr, 0, 0);
    miNave.draw();
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
















