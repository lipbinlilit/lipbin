#ifndef BOARD_HPP
#define BOARD_HPP

#include "game_object.hpp"
#include <windows.h>

#define mapWidth 80    
#define mapHeight 25  

class Board {
private:
	char map[mapHeight][mapWidth + 1];
public:
	Board();
	void clearMap();
	void showMap();
	void setCur(int x, int y);
	void putScoreOnMap(int score);
	void putObject(GameObject* obj);
};

#endif
