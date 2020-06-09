#pragma once
#include <Windows.h>
class PacMan {
	int currDirection;
	int currX;
	int currY;
	void AddScore();
public:
	PacMan();
	PacMan(int, int, int);
	void Init(int, int, int);
	void ChangeDirection(int);
	char GetStyle();
	COORD GetPos();
	void Move();
};