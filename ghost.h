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
	int currDirection;  //�ثe���ʤ�V
	int currX;
	int currY;
	bool currStepPutBean = false; //�P�_���o�@�B���}�ɬO�_�n��^���l
	bool nextStepHasBean = false; //�P�_�����U�@�B�O�_�����l
public:
	Ghost(int, int, int);
	COORD GetPos();
	void Move();
	void ChangeDirection();
	char GetStyle();
};
#endif
