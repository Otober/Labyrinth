#include "P2018112043.h"

P2018112043::P2018112043()
{
}

void P2018112043::gameStart(Point player, int height, int width)
{
	//std::cout << "���� ��ġ" << player << ' ' << height << ' ' << width << std::endl;
}

Action P2018112043::nextMove()
{
	// �����ϰ� �̵�
	switch (rand()%4)
	{
	case 0:
		return Action::MOVE_DOWN;
	case 1:
		return Action::MOVE_UP;
	case 2:
		return Action::MOVE_LEFT;
	case 3:
		return Action::MOVE_RIGHT;
	}
}

void P2018112043::ableToMove(Point point, Point prevPoint)
{
	//std::cout << point << "����" << prevPoint <<std::endl;
}

void P2018112043::notAbleToMove(Point point)
{
	//std::cout << point << "�Ұ�" << std::endl;
}
