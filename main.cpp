#include <windows.h>
#include <iostream>
#include <dinput.h>
#include "direction.h"
#include "initApp.h"
#include "map.h"
#include "renderer.h"
#include "gameStatus.h"
#include "pacman.h"
#include "ghost.h"
#include "beanCounter.h"
using namespace std;

int main()
{
    initApp();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t按空白鍵開始!" << endl;
    for (;;) {
        if (GetAsyncKeyState(VK_SPACE) != 0) {
            system("cls");
            break;
        }
        Sleep(400);
    }
    for (;;)
    {
        
        updateMap();
        
        if (isLose == true) {
            continue;
        }
        
        if (GetAsyncKeyState(VK_SPACE) != 0) {
            if (isLose) { 
                initApp();
            }
            isLose = false;
        }
        if (GetAsyncKeyState(87) != 0 || GetAsyncKeyState(VK_UP) != 0) //讀取UP輸入
        {
            player.ChangeDirection(DIR_UP);
            player.Move();
        }
        if (GetAsyncKeyState(83) != 0 || GetAsyncKeyState(VK_DOWN) != 0)//讀取DOWN輸入
        {
            player.ChangeDirection(DIR_DOWN);
            player.Move();
        }
        if (GetAsyncKeyState(65) != 0 || GetAsyncKeyState(VK_LEFT) != 0)//讀取LEFT輸入
        {
            player.ChangeDirection(DIR_LEFT);
            player.Move();
        }
        if (GetAsyncKeyState(68) != 0 || GetAsyncKeyState(VK_RIGHT) != 0)//讀取RIGHT輸入
        {
            player.ChangeDirection(DIR_RIGHT);
            player.Move();
        }
        for (int i = 0; i < ghosts.size(); i++) {
            ghosts[i].Move();
        }
        Sleep(200);
    }
 

    return 0;
}
