#include <cstdlib>
#include "P2018112073.h"
#include "Maze.h"
#include "GameManager.h"
#include "Point.h"
P2018112073::P2018112073() {
	GameManager gameManager;
	gameManager.init();

	Point startpoint = maze.getStartPoint(); //시작위치 입력받음
	point[cnt++] = startpoint; //시작위치를 배열에 넣음.
	if (startpoint.getX() == 0) { //시작위치가 맨위면
		point[cnt++] = (startpoint.getX() + 1, startpoint.getY()); //배열의 다음원소엔 한칸 아래로 이동한 포인트를 넣음.
		dir = 1; //방향은 아래

	}
	else if (startpoint.getX() == MAZE_HEIGHT - 1) { //시작위치가 맨아래면
		point[cnt++] = (startpoint.getX() - 1, startpoint.getY()); //배열의 다음원소엔 한칸 위로 이동한 포인트를 넣음.
		dir = 2; //방향은 위

	}
	else if (startpoint.getY() == 0) { //시작위치가 맨 왼쪽이면
		point[cnt++] = (startpoint.getX(), startpoint.getY() + 1); //배열의 다음원소엔 한칸 오른쪽으로 이동한 포인트를 넣음.
		dir = 4; //방향은 오른쪽

	}
	else if (startpoint.getY() == MAZE_WIDTH - 1) { //시작위치가 맨 오른쪽이면
		point[cnt++] = (startpoint.getX(), startpoint.getY() - 1); //배열의 다음원소엔 한칸 왼쪽으로 이동한 포인트를 넣음.
		dir = 3; //방향은 왼쪽

	}
	while (1) { //탈출할때까지 진행방향기준 왼쪽을 우선시하여 길을 찾음.
		if (dir == 1) { 
			if (Point(point[cnt].getX(), point[cnt].getY() + 1) != '■') {
				point[cnt + 1] = (point[cnt].getX(), point[cnt].getY() + 1); cnt++;
				dir = 4;
				if (maze.isGoal(point[cnt])) return; //만약 다음위치가 골인경우 return
				continue; //다음위치가 골이 아닌경우 반복문 처음위치로 돌아감.
			}
			else if (Point(point[cnt].getX() + 1, point[cnt].getY()) != '■') {
				point[cnt + 1] = (point[cnt].getX() + 1, point[cnt].getY()); cnt++;
				dir = 1;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX(), point[cnt].getY() - 1) != '■') {
				point[cnt + 1] = (point[cnt].getX(), point[cnt].getY() - 1); cnt++;
				dir = 3;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else {
				point[cnt + 1] = (point[cnt].getX() - 1, point[cnt].getY()); cnt++;
				dir = 2;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
		}
		else if (dir == 2) {
			if (Point(point[cnt].getX(), point[cnt].getY() - 1) != '■') {
				point[cnt + 1] = (point[cnt].getX(), point[cnt].getY() - 1); cnt++;
				dir = 3;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX() - 1, point[cnt].getY()) != '■') {
				point[cnt + 1] = (point[cnt].getX() - 1, point[cnt].getY()); cnt++;
				dir = 2;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX(), point[cnt].getY() + 1) != '■') {
				point[cnt + 1] = (point[cnt].getX(), point[cnt].getY() + 1); cnt++;
				dir = 4;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else {
				point[cnt + 1] = (point[cnt].getX() + 1, point[cnt].getY()); cnt++;
				dir = 1;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
		}
		else if (dir == 3) {
			if (Point(point[cnt].getX() + 1, point[cnt].getY()) != '■') {
				point[cnt + 1] = (point[cnt].getX() + 1, point[cnt].getY()); cnt++;
				dir = 1;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX(), point[cnt].getY() - 1) != '■') {
				point[cnt + 1] = (point[cnt].getX(), point[cnt].getY() - 1); cnt++;
				dir = 3;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX() - 1, point[cnt].getY()) != '■') {
				point[cnt + 1] = (point[cnt].getX() - 1, point[cnt].getY()); cnt++;
				dir = 2;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else {
				point[cnt + 1] = (point[cnt].getX(), point[cnt].getY() + 1); cnt++;
				dir = 4;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
		}
		else {
			if (Point(point[cnt].getX() - 1, point[cnt].getY()) != '■') {
				point[cnt + 1] = (point[cnt].getX() - 1, point[cnt].getY()); cnt++;
				dir = 2;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX(), point[cnt].getY() + 1) != '■') {
				point[cnt + 1] = (point[cnt].getX(), point[cnt].getY() + 1); cnt++;
				dir = 4;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX() + 1, point[cnt].getY()) != '■') {
				point[cnt + 1] = (point[cnt].getX() + 1, point[cnt].getY()); cnt++;
				dir = 1;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else {
				point[cnt + 1] = (point[cnt].getX(), point[cnt].getY() - 1); cnt++;
				dir = 3;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
		}
	}
}
void P2018112073::gameStart(Point player/*시작위치*/, int height, int width) {
	std::cout << "게임시작" << std::endl;
}
Action P2018112073::nextMove() {
	if (point[f + 1].getX() - point[f].getX() == 1) { //만약 다음위치가 현재위치보다 아래일경우
		f++; return Action::MOVE_DOWN; //MOVE_DOWN
	}
	else if (point[f + 1].getX() - point[f].getX() == -1) { //만약 다음위치가 현재위치보다 위일경우
		f++; return Action::MOVE_UP; //MOVE_UP
	}
	else if (point[f + 1].getY() - point[f].getY() == 1) { //만약 다음위치가 현재위치보다 오른쪽일경우
		f++; return Action::MOVE_RIGHT; //MOVE_RIGHT
	}
	else { //만약 다음위치가 현재위치보다 왼쪽일경우
		f++; return Action::MOVE_LEFT; //MOVE_LEFT
	}
}
void P2018112073::ableToMove(Point point/* nextpoint */, Point prevPoint/* playerpoint(현재좌표) */) {
	std::cout << "이동가능" << std::endl;
}
void P2018112073::notAbleToMove(Point point) {
	std::cout << "이동불가능" << std::endl;
}