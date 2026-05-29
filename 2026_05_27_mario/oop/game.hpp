#ifndef GAME_HPP
#define GAME_HPP

#include "game_object.hpp"
#include "board.hpp"

class Game {
private:
    Board board;
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
    
    void horizonMoveMap(float dx);
    void horizonMoveObject(GameObject* obj);
    void vertMoveObject(GameObject* obj);
    void marioCollision();
    void playerDead();
    void deleteMoving(int i);
    GameObject* getNewBrick();
    GameObject* getNewMoving();
    void createLevel(int lvl);
    
};
#endif

