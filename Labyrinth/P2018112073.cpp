#include <cstdlib>
#include "P2018112073.h"
#include "Maze.h"
#include "GameManager.h"
#include "Point.h"
P2018112073::P2018112073() {
	GameManager gameManager;
	gameManager.init();

	Point startpoint = maze.getStartPoint(); //������ġ �Է¹���
	point[cnt++] = startpoint; //������ġ�� �迭�� ����.
	if (startpoint.getX() == 0) { //������ġ�� ������
		point[cnt++] = (startpoint.getX() + 1, startpoint.getY()); //�迭�� �������ҿ� ��ĭ �Ʒ��� �̵��� ����Ʈ�� ����.
		dir = 1; //������ �Ʒ�

	}
	else if (startpoint.getX() == MAZE_HEIGHT - 1) { //������ġ�� �ǾƷ���
		point[cnt++] = (startpoint.getX() - 1, startpoint.getY()); //�迭�� �������ҿ� ��ĭ ���� �̵��� ����Ʈ�� ����.
		dir = 2; //������ ��

	}
	else if (startpoint.getY() == 0) { //������ġ�� �� �����̸�
		point[cnt++] = (startpoint.getX(), startpoint.getY() + 1); //�迭�� �������ҿ� ��ĭ ���������� �̵��� ����Ʈ�� ����.
		dir = 4; //������ ������

	}
	else if (startpoint.getY() == MAZE_WIDTH - 1) { //������ġ�� �� �������̸�
		point[cnt++] = (startpoint.getX(), startpoint.getY() - 1); //�迭�� �������ҿ� ��ĭ �������� �̵��� ����Ʈ�� ����.
		dir = 3; //������ ����

	}
	while (1) { //Ż���Ҷ����� ���������� ������ �켱���Ͽ� ���� ã��.
		if (dir == 1) { 
			if (Point(point[cnt].getX(), point[cnt].getY() + 1) != '��') {
				point[cnt + 1] = (point[cnt].getX(), point[cnt].getY() + 1); cnt++;
				dir = 4;
				if (maze.isGoal(point[cnt])) return; //���� ������ġ�� ���ΰ�� return
				continue; //������ġ�� ���� �ƴѰ�� �ݺ��� ó����ġ�� ���ư�.
			}
			else if (Point(point[cnt].getX() + 1, point[cnt].getY()) != '��') {
				point[cnt + 1] = (point[cnt].getX() + 1, point[cnt].getY()); cnt++;
				dir = 1;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX(), point[cnt].getY() - 1) != '��') {
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
			if (Point(point[cnt].getX(), point[cnt].getY() - 1) != '��') {
				point[cnt + 1] = (point[cnt].getX(), point[cnt].getY() - 1); cnt++;
				dir = 3;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX() - 1, point[cnt].getY()) != '��') {
				point[cnt + 1] = (point[cnt].getX() - 1, point[cnt].getY()); cnt++;
				dir = 2;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX(), point[cnt].getY() + 1) != '��') {
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
			if (Point(point[cnt].getX() + 1, point[cnt].getY()) != '��') {
				point[cnt + 1] = (point[cnt].getX() + 1, point[cnt].getY()); cnt++;
				dir = 1;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX(), point[cnt].getY() - 1) != '��') {
				point[cnt + 1] = (point[cnt].getX(), point[cnt].getY() - 1); cnt++;
				dir = 3;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX() - 1, point[cnt].getY()) != '��') {
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
			if (Point(point[cnt].getX() - 1, point[cnt].getY()) != '��') {
				point[cnt + 1] = (point[cnt].getX() - 1, point[cnt].getY()); cnt++;
				dir = 2;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX(), point[cnt].getY() + 1) != '��') {
				point[cnt + 1] = (point[cnt].getX(), point[cnt].getY() + 1); cnt++;
				dir = 4;
				if (maze.isGoal(point[cnt])) return;
				continue;
			}
			else if (Point(point[cnt].getX() + 1, point[cnt].getY()) != '��') {
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
void P2018112073::gameStart(Point player/*������ġ*/, int height, int width) {
	std::cout << "���ӽ���" << std::endl;
}
Action P2018112073::nextMove() {
	if (point[f + 1].getX() - point[f].getX() == 1) { //���� ������ġ�� ������ġ���� �Ʒ��ϰ��
		f++; return Action::MOVE_DOWN; //MOVE_DOWN
	}
	else if (point[f + 1].getX() - point[f].getX() == -1) { //���� ������ġ�� ������ġ���� ���ϰ��
		f++; return Action::MOVE_UP; //MOVE_UP
	}
	else if (point[f + 1].getY() - point[f].getY() == 1) { //���� ������ġ�� ������ġ���� �������ϰ��
		f++; return Action::MOVE_RIGHT; //MOVE_RIGHT
	}
	else { //���� ������ġ�� ������ġ���� �����ϰ��
		f++; return Action::MOVE_LEFT; //MOVE_LEFT
	}
}
void P2018112073::ableToMove(Point point/* nextpoint */, Point prevPoint/* playerpoint(������ǥ) */) {
	std::cout << "�̵�����" << std::endl;
}
void P2018112073::notAbleToMove(Point point) {
	std::cout << "�̵��Ұ���" << std::endl;
}