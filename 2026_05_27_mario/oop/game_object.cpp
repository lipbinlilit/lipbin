#include "game_object.hpp"
#include <math.h>

GameObject::GameObject() : x(0), y(0), width(1), height(1),
vertSpeed(0), horizonSpeed(0.2f),
IsFly(FALSE), cType(' ') {
}

void GameObject::init(float xPos, float yPos, float oWidth, float oHeight, char inType) {
    x = xPos;
    y = yPos;
    width = oWidth;
    height = oHeight;
    vertSpeed = 0;
    horizonSpeed = 0.2f;
    IsFly = FALSE;
    cType = inType;
}

float GameObject::getX() const { return x; }
float GameObject::getY() const { return y; }
float GameObject::getWidth() const { return width; }
float GameObject::getHeight() const { return height; }
float GameObject::getVertSpeed() const { return vertSpeed; }
float GameObject::getHorizonSpeed() const { return horizonSpeed; }
BOOL GameObject::getIsFly() const { return IsFly; }
char GameObject::getType() const { return cType; }

void GameObject::setPos(float xPos, float yPos) { x = xPos; y = yPos; }
void GameObject::setVertSpeed(float speed) { vertSpeed = speed; }
void GameObject::setHorizonSpeed(float speed) { horizonSpeed = speed; }
void GameObject::setIsFly(BOOL fly) { IsFly = fly; }
void GameObject::setType(char type) { cType = type; }
void GameObject::addVertSpeed(float delta) { vertSpeed += delta; }

BOOL GameObject::isCollision(const GameObject& other) const {
    return ((x + width) > other.x) && (x < (other.x + other.width)) &&
        ((y + height) > other.y) && (y < (other.y + other.height));
}

