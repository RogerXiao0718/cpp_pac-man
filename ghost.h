#ifndef GHOST_H
#define GHOST_H
#include <iostream>
#include <windows.h>
#include <vector>
#include <cmath>
#include <ctime>
#include "direction.h"
#include "map.h"

class Ghost {
	int currDirection;  //目前移動方向
	int currX;
	int currY;
	bool currStepPutBean = false; //判斷鬼這一步離開時是否要放回豆子
	bool nextStepHasBean = false; //判斷鬼的下一步是否有豆子
public:
	Ghost(int, int, int);
	COORD GetPos();
	void Move();
	void ChangeDirection();
	char GetStyle();
};
#endif
