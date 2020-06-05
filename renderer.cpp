#include <iostream>
#include <windows.h>
#include "map.h"
#include "renderer.h"

using namespace std;

HANDLE handler;
COORD xyPoint = {};
HANDLE output = CreateConsoleScreenBuffer(GENERIC_WRITE, FILE_SHARE_WRITE, NULL,CONSOLE_TEXTMODE_BUFFER, NULL);//¿é¥X½w½Ä1
HANDLE outbuf = CreateConsoleScreenBuffer(GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); //¿é¥X½w½Ä2
DWORD bytes = 0;

void screenCls() {
     handler = GetStdHandle(STD_OUTPUT_HANDLE);
     xyPoint;
    xyPoint.X = 0;
    xyPoint.Y = 0;
    SetConsoleCursorPosition(handler, xyPoint);
}

void updateMap() {
    //°µÂù½w½Ä¿é¥X
    static bool flip_flop = true;
    if (flip_flop) {
        for (int i = 0; i < MAP_HEIGHT; i++) {
            xyPoint.Y = i;
            vector<char> v;
            for (int j = 0; j < MAP_WIDTH; j++) {
                v.push_back(map[i][j]);
                v.push_back(' ');
            }
            WriteConsoleOutputCharacterA(outbuf, &v[0], (DWORD)MAP_WIDTH * 2, xyPoint, &bytes);
        }
        SetConsoleActiveScreenBuffer(outbuf);
    }
    else {
        for (int i = 0; i < MAP_HEIGHT; i++) {
            xyPoint.Y = i;
            vector<char> v;
            for (int j = 0; j < MAP_WIDTH; j++) {
                v.push_back(map[i][j]);
                v.push_back(' ');
            }
            WriteConsoleOutputCharacterA(output, &v[0], (DWORD)MAP_WIDTH * 2, xyPoint, &bytes);
        }
        SetConsoleActiveScreenBuffer(output);
    }
    flip_flop = !flip_flop;
    return;
}