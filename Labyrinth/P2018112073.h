#pragma once
#include "Player.h"
#include "Maze.h"
#include "Point.h"

class P2018112073 : public Player {
public:
	P2018112073();
	void gameStart(Point player, int height, int width);
	Action nextMove();
	void ableToMove(Point point, Point prevPoint);
	void notAbleToMove(Point point);
	int dir;//1이면 down 2면 up 3이면 left 4이면 right
	int cnt = 0; //gamestart에서 Point배열을 이용할때 쓰는 변수
	int f = 0;//nextmove에서 Point배열을 이용할때 쓰는 변수
private:
	Point point[100000];
	Maze maze;
};

