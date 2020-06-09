#include "initApp.h"
#include "map.h"
#include "pacman.h"
#include <windows.h>
#include <iostream>
#include "beanCounter.h"
#include "gameStatus.h"
#include "ghost.h"

using namespace std;

PacMan player;
vector<Ghost> ghosts;
bool isLose = false;

void initGhosts() {

    Ghost ghost1(13, 3, DIR_DOWN);
    Ghost ghost2(13, 2, DIR_DOWN);
    Ghost ghost3(13, 26, DIR_UP);
    Ghost ghost4(13, 27, DIR_UP);
    ghosts.push_back(ghost1);
    ghosts.push_back(ghost2);
    ghosts.push_back(ghost3);
    ghosts.push_back(ghost4);
}

void initApp(void)
{
    HANDLE cmdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = 0;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(cmdHandle, &cursorInfo);
    initMap();
    initBeanCounter();
    player.Init(13, 13, DIR_DOWN);
    initGhosts();
    system("title Pac-Man");
    system("@echo off");
    system("cls");
    SetWindowPos(GetConsoleWindow(), HWND_TOPMOST, 500, 100, 700, 600, NULL);
}

