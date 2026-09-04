#include "game.hpp"
#include "board.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

Game::Game() : brick(NULL), moving(NULL), brickLength(0), movingLength(0),
level(1), score(0), maxLvl(3) {
    createLevel(level);
}

Game::~Game() {
    free(brick);
    free(moving);
}

void Game::run() {
    do {
        board.clearMap();

        if ((mario.getIsFly() == FALSE) && (GetKeyState(VK_SPACE) < 0))
            mario.setVertSpeed(-1);

        if (GetKeyState('A') < 0) horizonMoveMap(1);
        if (GetKeyState('D') < 0) horizonMoveMap(-1);

        if (mario.getY() > mapHeight) playerDead();

        vertMoveObject(&mario);
        marioCollision();

        for (int i = 0; i < brickLength; ++i)
            board.putObject(&brick[i]);

        for (int i = 0; i < movingLength; ++i) {
            vertMoveObject(&moving[i]);
            horizonMoveObject(&moving[i]);
            if (moving[i].getY() > mapHeight) {
                deleteMoving(i);
                i--;
                continue;
            }
            board.putObject(&moving[i]);
        }

        board.putObject(&mario);
        board.putScoreOnMap(score);

        board.setCur(0, 0);
        board.showMap();

        Sleep(10);
    } while (GetKeyState(VK_ESCAPE) >= 0);
}


void Game::horizonMoveMap(float dx) {
    float newX = mario.getX() - dx;
    mario.setPos(newX, mario.getY());

    for (int i = 0; i < brickLength; ++i) {
        if (mario.isCollision(brick[i])) {
            mario.setPos(newX + dx, mario.getY());
            return;
        }
    }

    mario.setPos(newX, mario.getY());

    for (int i = 0; i < brickLength; i++)
        brick[i].setPos(brick[i].getX() + dx, brick[i].getY());

    for (int i = 0; i < movingLength; i++)
        moving[i].setPos(moving[i].getX() + dx, moving[i].getY());
}

void Game::horizonMoveObject(GameObject* obj) {
    obj->setPos(obj->getX() + obj->getHorizonSpeed(), obj->getY());

    for (int i = 0; i < brickLength; ++i) {
        if (obj->isCollision(brick[i])) {
            obj->setPos(obj->getX() - obj->getHorizonSpeed(), obj->getY());
            obj->setHorizonSpeed(-obj->getHorizonSpeed());
            return;
        }
    }

    if (obj->getType() == 'o') {
        GameObject tmp = *obj;
        vertMoveObject(&tmp);
        if (tmp.getIsFly() == TRUE) {
            obj->setPos(obj->getX() - obj->getHorizonSpeed(), obj->getY());
            obj->setHorizonSpeed(-obj->getHorizonSpeed());
        }
    }
}

void Game::vertMoveObject(GameObject* obj) {
    obj->setIsFly(TRUE);

    if (obj->getType() != '=') {
        obj->addVertSpeed(0.05f);
    }

    obj->setPos(obj->getX(), obj->getY() + obj->getVertSpeed());

    for (int i = 0; i < brickLength; ++i) {
        if (obj->isCollision(brick[i])) {
            if (obj->getVertSpeed() > 0)
                obj->setIsFly(FALSE);

            if ((brick[i].getType() == '?') && (obj->getVertSpeed() < 0) && (obj == &mario)) {
                brick[i].setType('-');
                GameObject* newMoving = getNewMoving();
                newMoving->init(brick[i].getX(), brick[i].getY() - 3, 3, 2, '$');
                newMoving->setVertSpeed(-0.7f);
            }

            obj->setPos(obj->getX(), obj->getY() - obj->getVertSpeed());
            obj->setVertSpeed(0);

            if (brick[i].getType() == '+') {
                level++;
                if (level > maxLvl) level = 1;
                system("color 2F");
                Sleep(500);
                createLevel(level);
            }
            break;
        }
    }
}

void Game::marioCollision() {
    for (int i = 0; i < movingLength; ++i) {
        if (mario.isCollision(moving[i])) {
            if (moving[i].getType() == 'o') {
                if ((mario.getIsFly() == TRUE) && (mario.getVertSpeed() > 0) &&
                    (mario.getY() + mario.getHeight() < moving[i].getY() + moving[i].getHeight() * 0.5)) {
                    score += 50;
                    deleteMoving(i);
                    i--;
                    continue;
                }
                else {
                    playerDead();
                }
            }

            if (moving[i].getType() == '$') {
                score += 100;
                deleteMoving(i);
                i--;
                continue;
            }
        }
    }
}

void Game::playerDead() {
    system("color 4F");
    Sleep(500);
    createLevel(level);
}

void Game::deleteMoving(int i) {
    movingLength--;
    moving[i] = moving[movingLength];
    moving = (GameObject*)realloc(moving, sizeof(GameObject) * movingLength);
}

GameObject* Game::getNewBrick() {
    brickLength++;
    brick = (GameObject*)realloc(brick, sizeof(GameObject) * brickLength);
    return &brick[brickLength - 1];
}

GameObject* Game::getNewMoving() {
    movingLength++;
    moving = (GameObject*)realloc(moving, sizeof(GameObject) * movingLength);
    return &moving[movingLength - 1];
}

void Game::createLevel(int lvl) {
    system("color 9F");

    brickLength = 0;
    brick = (GameObject*)realloc(brick, 0);
    movingLength = 0;
    moving = (GameObject*)realloc(moving, 0);

    mario.init(39, 10, 3, 3, '@');
    score = 0;

    if (lvl == 1) {
        getNewBrick()->init(20, 20, 40, 5, '#');
        getNewBrick()->init(30, 10, 5, 3, '?');
        getNewBrick()->init(50, 10, 5, 3, '?');
        getNewBrick()->init(60, 15, 40, 10, '#');
        getNewBrick()->init(60, 5, 10, 3, '-');
        getNewBrick()->init(70, 5, 5, 3, '?');
        getNewBrick()->init(75, 5, 5, 3, '-');
        getNewBrick()->init(80, 5, 5, 3, '?');
        getNewBrick()->init(85, 5, 10, 3, '-');
        getNewBrick()->init(100, 20, 20, 5, '#');
        getNewBrick()->init(120, 15, 10, 10, '#');
        getNewBrick()->init(150, 20, 40, 5, '#');
        getNewBrick()->init(210, 15, 10, 10, '+');
        getNewMoving()->init(25, 10, 3, 2, 'o');
        getNewMoving()->init(80, 10, 3, 2, 'o');

        GameObject* platform = getNewMoving();
        platform->init(40, 15, 8, 1, '=');
        platform->setHorizonSpeed(0.1f);
    }

    if (lvl == 2) {
        getNewBrick()->init(20, 20, 40, 5, '#');
        getNewBrick()->init(60, 15, 10, 10, '#');
        getNewBrick()->init(80, 20, 20, 5, '#');
        getNewBrick()->init(120, 15, 10, 10, '#');
        getNewBrick()->init(150, 20, 40, 5, '#');
        getNewBrick()->init(210, 15, 10, 10, '+');
        getNewMoving()->init(25, 10, 3, 2, 'o');
        getNewMoving()->init(80, 10, 3, 2, 'o');
        getNewMoving()->init(65, 10, 3, 2, 'o');
        getNewMoving()->init(120, 10, 3, 2, 'o');
        getNewMoving()->init(160, 10, 3, 2, 'o');
        getNewMoving()->init(175, 10, 3, 2, 'o');
    }

    if (lvl == 3) {
        getNewBrick()->init(20, 20, 40, 5, '#');
        getNewBrick()->init(80, 20, 15, 5, '#');
        getNewBrick()->init(120, 15, 15, 10, '#');
        getNewBrick()->init(160, 10, 15, 15, '+');
        getNewMoving()->init(25, 10, 3, 2, 'o');
        getNewMoving()->init(50, 10, 3, 2, 'o');
        getNewMoving()->init(80, 10, 3, 2, 'o');
        getNewMoving()->init(90, 10, 3, 2, 'o');
        getNewMoving()->init(120, 10, 3, 2, 'o');
        getNewMoving()->init(130, 10, 3, 2, 'o');
    }
}

