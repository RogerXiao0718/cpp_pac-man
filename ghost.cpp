#include <iostream>
#include <windows.h>
#include <vector>
#include <cmath>
#include <ctime>
#include "direction.h"
#include "map.h"
#include "ghost.h"
#include "initApp.h"
#include "gameStatus.h"

using namespace std;

Ghost::Ghost(int _x, int _y, int _direction) : currX(_x), currY(_y), currDirection(_direction) {
	map[currY][currX] = GetStyle();
}

COORD Ghost::GetPos() {
	COORD currPos = { currX, currY };
	return currPos;
}

char Ghost::GetStyle() {
	char style = 'M';
	return style;
}

void Ghost::Move() {
	COORD playerPos = player.GetPos();
	 int randTick;
	srand(time(NULL));
	randTick =((int)rand()) % 4;
	int pX = playerPos.X;
	int pY = playerPos.Y;
		if ((currDirection == DIR_UP && map[currY - 1][currX] == WALL) ||
			(currDirection == DIR_DOWN && map[currY + 1][currX] == WALL) ||
			(currDirection == DIR_LEFT && map[currY][currX - 1] == WALL) ||
			(currDirection == DIR_RIGHT && map[currY][currX + 1] == WALL) ||
			(currDirection == DIR_UP && map[currY - 1][currX] == GetStyle()) ||
			(currDirection == DIR_DOWN && map[currY + 1][currX] == GetStyle()) ||
			(currDirection == DIR_LEFT && map[currY][currX - 1] == GetStyle()) ||
			(currDirection == DIR_RIGHT && map[currY][currX + 1] == GetStyle())
			) {
			//�Y�U�@�B�|�I����N���ܲ��ʤ�V
			ChangeDirection();
		}

		if (randTick == 1) {
			ChangeDirection();
		}

		if (nextStepHasBean ) {
			//��m���l�bGhost����X�{����m
			map[currY][currX] = BEAN;
			currStepPutBean = nextStepHasBean;
		}
		else {
			map[currY][currX] = ' ';
		}
		switch (currDirection) {
		case DIR_UP:
			if (map[currY - 1][currX] != WALL) {
				//�P�_���ʤ�V�O�_�����l
				if (map[currY - 1][currX] == BEAN) {
					nextStepHasBean = true;
				}
				else {
					nextStepHasBean = false;
				}
				//�N�����y�в���
				currY--;
				map[currY][currX] = GetStyle();
				if (currX == pX && currY == pY) {
					isLose = true;
				}
			}
			break;
		case DIR_DOWN:
			if (map[currY + 1][currX] != WALL) {
				if (map[currY + 1][currX] == BEAN) {
					nextStepHasBean = true;
				}
				else {
					nextStepHasBean = false;
				}
				currY++;
				map[currY][currX] = GetStyle();
				if (currX == pX && currY == pY) {
					isLose = true;
				}
			}
			break;
		case DIR_LEFT:
			if (map[currY][currX - 1] != WALL) {
				if (map[currY][currX - 1] == BEAN) {
					nextStepHasBean = true;
				}
				else {
					nextStepHasBean = false;
				}
				currX--;
				map[currY][currX] = GetStyle();
				if (currX == pX && currY == pY) {
					isLose = true;
				}
			}
			break;
		case DIR_RIGHT:
			if (map[currY][currX + 1] != WALL) {
				if (map[currY][currX+1] == BEAN) {
					nextStepHasBean = true;
				}
				else {
					nextStepHasBean = false;
				}
				currX++;
				map[currY][currX] = GetStyle();
				if (currX == pX && currY == pY) {
					isLose = true;
				}
			}
			break;
		}
}
void Ghost::ChangeDirection() { //�ܴ����ʤ�V
	vector<int> directions; //�N��Ҧ��i�H���ʪ���V
	long randDirection;
	if (map[currY - 1][currX] != WALL && map[currY - 1][currX] != GetStyle()) {
		directions.push_back(DIR_UP);
	}
	if (map[currY + 1][currX] != WALL && map[currY + 1][currX] != GetStyle()) {
		directions.push_back(DIR_DOWN);
	}
	if (map[currY][currX - 1] != WALL && map[currY][currX - 1] != GetStyle()) {
		directions.push_back(DIR_LEFT);
	}
	if (map[currY][currX + 1] != WALL && map[currY][currX + 1] != GetStyle())
	{
		directions.push_back(DIR_RIGHT);
	}
	if ((int)directions.size() != 0) {
		srand(time(NULL));
		randDirection = rand() % (int)(directions.size()); //�ζüƨM�w��V
		currDirection = directions[randDirection];
	}
}