#include "board.hpp"
#include "game_object.hpp"
#include <math.h>
#include <string.h>
#include <cstdio>

Board::Board() {
    clearMap();
}

void Board::clearMap() {
    for (int i = 0; i < mapWidth; ++i)
        map[0][i] = ' ';
    map[0][mapWidth] = '\0';
    for (int j = 1; j < mapHeight; ++j)
        sprintf(map[j], map[0]);
}

void Board::showMap() {
    map[mapHeight - 1][mapWidth - 1] = '\0';
    for (int j = 0; j < mapHeight; ++j)
        printf("%s\n", map[j]);
}
void Board::putScoreOnMap(int score) {
    char c[30];
    sprintf(c, "Score: %d", score);
    int len = strlen(c);
    for (int i = 0; i < len; i++) {
        map[1][i + 5] = c[i];
    }
}
void Board::setCur(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Board::putObject(GameObject* obj){
    int ix = (int)round(obj->getX());
    int iy = (int)round(obj->getY());
    int iWidth = (int)round(obj->getWidth());
    int iHeight = (int)round(obj->getHeight());

    for (int i = ix; i < (ix + iWidth); ++i)
        for (int j = iy; j < (iy + iHeight); ++j)
            if (i >= 0 && i < mapWidth && j >= 0 && j < mapHeight)
                map[j][i] = obj->getType();
}