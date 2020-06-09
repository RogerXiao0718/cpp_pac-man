#include <iostream>
#include "direction.h"
#include "pacman.h"
#include "map.h"
#include "beanCounter.h"
#include <windows.h>
#include "gameStatus.h"

using namespace std;

PacMan::PacMan(int _x, int _y, int _direction) : currX(_x), currY(_y), currDirection(_direction) {
	char style;
	switch (_direction) {
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
	map[_y][_x] = style;
}

PacMan::PacMan() = default;

void PacMan::Init(int _x, int _y, int _direction) {
	currX = _x;
	currY = _y;
	currDirection = _direction;
		char style;
		switch (_direction) {
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
		map[_y][_x] = style;

}


void PacMan::AddScore() {
		score += 10;
}

COORD PacMan::GetPos() {
	COORD currPos = { currX, currY };
	return currPos;
}

char PacMan::GetStyle() {
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
	default:
		style = 'X';
	}
	return style;
}
void PacMan::ChangeDirection(int direction) {
	currDirection = direction;
}

void PacMan::Move() {
	switch (currDirection) {
	case DIR_UP:
		if (map[currY - 1][currX] != WALL) {
			//判斷移動方向是否有豆子
			if (map[currY - 1][currX] == BEAN || map[currY - 1][currX] == SUPER_BEAN) {
				AddScore();
				beanCounter--;
			}
			map[currY][currX] = ' ';
			currY--;
			if (map[currY][currX] == 'M') {
				isLose = true;
			}
			else {
				map[currY][currX] = GetStyle();
			}
		}
		break;
	case DIR_DOWN:
		if (map[currY + 1][currX] != WALL) {
			if (map[currY + 1][currX] == BEAN || map[currY ][currX + 1] == SUPER_BEAN) {
				AddScore();
				beanCounter--;
			}
			map[currY][currX] = ' ';
			currY++;
			if (map[currY][currX] == 'M') {
				isLose = true;
			}
			else {
				map[currY][currX] = GetStyle();
			}
		}
		break;
	case DIR_LEFT:
		if (map[currY][currX - 1] != WALL) {
			if (map[currY][currX - 1] == BEAN || map[currY][currX - 1] == SUPER_BEAN) {
				AddScore();
				beanCounter--;
			}
			map[currY][currX] = ' ';
			currX--;
			if (map[currY][currX] == 'M') {
				isLose = true;
			}
			else {
				map[currY][currX] = GetStyle();
			}
		}
		break;
	case DIR_RIGHT:
		if (map[currY][currX + 1] != WALL) {
			if (map[currY][currX + 1] == BEAN || map[currY ][currX + 1] == SUPER_BEAN) {
				AddScore();
				beanCounter--;
			}
			map[currY][currX] = ' ';
			currX++;
			if (map[currY][currX] == 'M') {
				isLose = true;
			}
			else {
				map[currY][currX] = GetStyle();
			}
		}
		break;
	}
}