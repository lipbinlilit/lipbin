#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <windows.h>

#define mapWidth 80    
#define mapHeight 25      

class GameObject {
private:
    float x, y;
    float width, height;
    float vertSpeed;
    float horizonSpeed;
    BOOL IsFly;
    char cType;

public:
    GameObject();

    void init(float xPos, float yPos, float oWidth, float oHeight, char inType);

    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    float getVertSpeed() const;
    float getHorizonSpeed() const;
    BOOL getIsFly() const;
    char getType() const;

    void setPos(float xPos, float yPos);
    void setVertSpeed(float speed);
    void setHorizonSpeed(float speed);
    void setIsFly(BOOL fly);
    void setType(char type);
    void addVertSpeed(float delta);

    BOOL isCollision(const GameObject& other) const;
    void putOnMap(char map[mapHeight][mapWidth + 1]) const;
    static BOOL isPosInMap(int x, int y);
};

#endif