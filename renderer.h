#pragma once
#include <windows.h>
extern HANDLE handler;
extern CURSORINFO cursorInfo;
extern COORD xyPoint;
extern HANDLE output, outbuf;

void screenCls();
void updateMap();

