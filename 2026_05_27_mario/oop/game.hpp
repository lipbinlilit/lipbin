#ifndef GAME_HPP
#define GAME_HPP

#include "game_object.hpp"

class Game {
private:
    char map[mapHeight][mapWidth + 1];
    GameObject mario;
    GameObject* brick;
    GameObject* moving;
    int brickLength;
    int movingLength;
    int level;
    int score;
    int maxLvl;

public:
    Game();
    ~Game();
    void run();

private:
    void clearMap();
    void showMap();
    void setCur(int x, int y);
    void horizonMoveMap(float dx);
    void horizonMoveObject(GameObject* obj);
    void vertMoveObject(GameObject* obj);
    void marioCollision();
    void playerDead();
    void deleteMoving(int i);
    GameObject* getNewBrick();
    GameObject* getNewMoving();
    void createLevel(int lvl);
    void putScoreOnMap();
};

#endif