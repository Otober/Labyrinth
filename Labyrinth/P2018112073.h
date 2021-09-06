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
	int dir;//1�̸� down 2�� up 3�̸� left 4�̸� right
	int cnt = 0; //gamestart���� Point�迭�� �̿��Ҷ� ���� ����
	int f = 0;//nextmove���� Point�迭�� �̿��Ҷ� ���� ����
private:
	Point point[100000];
	Maze maze;
};

