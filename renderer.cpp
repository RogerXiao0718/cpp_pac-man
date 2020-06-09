#include <iostream>
#include <windows.h>
#include <sstream>
#include <string>
#include "map.h"
#include "renderer.h"
#include "beanCounter.h"
#include "gameStatus.h"

using namespace std;

HANDLE handler;
COORD xyPoint = {};
HANDLE output = CreateConsoleScreenBuffer(GENERIC_WRITE, FILE_SHARE_WRITE, NULL,CONSOLE_TEXTMODE_BUFFER, NULL);//輸出緩衝1
HANDLE outbuf = CreateConsoleScreenBuffer(GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); //輸出緩衝2
DWORD bytes = 0;

int score = 0;
int bonusTime = 0;

void screenCls() {
     handler = GetStdHandle(STD_OUTPUT_HANDLE);
     xyPoint;
    xyPoint.X = 0;
    xyPoint.Y = 0;
    SetConsoleCursorPosition(handler, xyPoint);
}

void updateMap() {
    //做雙緩衝輸出
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
        string score_s = "分數: ";
         score_s = score_s + to_string(score);
        COORD scorePos = { MAP_WIDTH * 2 + 10, 0 };
        WriteConsoleOutputCharacterA(outbuf, score_s.c_str(), (DWORD)(score_s.size() +1), scorePos, &bytes);
        string beanCounter_s = "剩餘的豆子數量: ";
        beanCounter_s = beanCounter_s + to_string(beanCounter);
        COORD bcPos = { MAP_WIDTH * 2 + 10, 1 };
        WriteConsoleOutputCharacterA(outbuf, beanCounter_s.c_str(), (DWORD)(beanCounter_s.size() + 1), bcPos, &bytes);
        if (beanCounter <= 0) {
            string winOutput = "WINNER WINNER CHICKEN DINNER!";
            COORD winnerPos = { MAP_WIDTH * 2 + 10, 2 };
            WriteConsoleOutputCharacterA(outbuf, winOutput.c_str(), (DWORD)(winOutput.size() + 1), winnerPos, &bytes);
        }
        if (isLose == true) {
            string loseOutput = "YOU ARE LOSER!!";
            COORD loserPos = { MAP_WIDTH * 2 + 10, 2 };
            WriteConsoleOutputCharacterA(outbuf, loseOutput.c_str(), (DWORD)(loseOutput.size() + 1), loserPos, &bytes);
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
        string score_s = "分數: ";
         score_s = score_s + to_string(score);
         COORD scorePos = { MAP_WIDTH * 2 + 10, 0 };
        WriteConsoleOutputCharacterA(output, score_s.c_str(), (DWORD)(score_s.size() + 1), scorePos, &bytes);
        string beanCounter_s = "剩餘的豆子數量: ";
        beanCounter_s = beanCounter_s + to_string(beanCounter);
        COORD bcPos = { MAP_WIDTH * 2 + 10, 1};
        WriteConsoleOutputCharacterA(output, beanCounter_s.c_str(), (DWORD)(beanCounter_s.size() + 1), bcPos, &bytes);
        if (beanCounter <= 0) {
            string winOutput = "WINNER WINNER CHICKEN DINNER!";
            COORD winnerPos = { MAP_WIDTH * 2 + 10, 2 };
            WriteConsoleOutputCharacterA(output, winOutput.c_str() , (DWORD)(winOutput.size()+1), winnerPos, &bytes);
        }
        if (isLose == true) {
            string loseOutput = "YOU ARE LOSER!!";
            COORD loserPos = { MAP_WIDTH * 2 + 10, 2 };
            WriteConsoleOutputCharacterA(output, loseOutput.c_str(), (DWORD)(loseOutput.size() + 1), loserPos, &bytes);
        }
        SetConsoleActiveScreenBuffer(output);
    }
    flip_flop = !flip_flop;
    return;
}