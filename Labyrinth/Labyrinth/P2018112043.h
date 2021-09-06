#pragma once
#include "Player.h"

class P2018112043 : public Player
{
public:
	P2018112043();
	void gameStart(Point player, int height, int width);
	Action nextMove();
	void ableToMove(Point point, Point prevPoint);
	void notAbleToMove(Point point);

private:
	Point point;
};