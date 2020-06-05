#include <iostream>
#include <windows.h>
#include <vector>
#include <cmath>
#include <ctime>
#include "direction.h"
#include "map.h"
#include "ghost.h"

using namespace std;

COORD Ghost::GetPos() {
	COORD currPos = { currX, currY };
	return currPos;
}

char Ghost::GetStyle() {
	char style;
	switch (currDirection) {
	case DIR_UP:
		style = 'v';
		break;
	case DIR_DOWN:
		style = '^';
		break;
	case DIR_LEFT:
		style = '>';
		break;
	case DIR_RIGHT:
		style = '<';
		break;
	}
	return style;
}

void Ghost::Move() {
		if ((currDirection == DIR_UP && map[currY - 1][currX] == WALL) ||
			(currDirection == DIR_DOWN && map[currY + 1][currX] == WALL) ||
			(currDirection == DIR_LEFT && map[currY][currX - 1] == WALL) ||
			(currDirection == DIR_RIGHT && map[currY][currX + 1] == WALL)
			) {
			//若下一步會碰到牆就改變移動方向
			ChangeDirection();
		}

		if (currStepPutBean) {
			//放置豆子在Ghost原先出現的位置
			map[currY][currX] = BEAN;
			currStepPutBean = nextStepHasBean;
		}
		switch (currDirection) {
		case DIR_UP:
			if (map[currY - 1][currX] != WALL) {
				//判斷移動方向是否有豆子
				if (map[currY - 1][currX] == BEAN) {
					nextStepHasBean = true;
				}
				else {
					nextStepHasBean = false;
				}
				//將鬼的座標移動
				currY--;
				map[currY][currX] = GetStyle();
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
			}
			break;
		}
}
void Ghost::ChangeDirection() { //變換移動方向
	vector<int> directions; //代表所有可以移動的方向
	long randDirection;
	if (map[currY - 1][currX] != WALL) {
		directions.push_back(DIR_UP);
	}
	if (map[currY + 1][currX] != WALL) {
		directions.push_back(DIR_DOWN);
	}
	if (map[currY][currX - 1] != WALL) {
		directions.push_back(DIR_LEFT);
	}
	if (map[currY][currX + 1] != WALL)
	{
		directions.push_back(DIR_RIGHT);
	}
	if ((int)directions.size() != 0) {
		srand(time(NULL));
		randDirection = rand() % (int)directions.size(); //用亂數決定方向
		currDirection = directions[randDirection];
	}
}