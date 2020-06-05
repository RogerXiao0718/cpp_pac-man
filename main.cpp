#include <windows.h>
#include <iostream>
#include "direction.h"
#include "initApp.h"
#include "map.h"
#include "renderer.h"
using namespace std;

int main()
{
    initApp();
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t按空白鍵開始這糞Game!" << endl;
    for (;;) {
        if (GetAsyncKeyState(VK_SPACE) != 0) {
            system("cls");
            break;
        }
        Sleep(400);
    }
    for (;;)
    {
        //updateMap();
        updateMap();
        if (GetAsyncKeyState(VK_SPACE) != 0) {
            screenCls();
        }
        if (GetAsyncKeyState(87) != 0 || GetAsyncKeyState(VK_UP) != 0) //讀取UP輸入
        { 
            // pecMan.changeDirection(DIR_UP);
        }
        if (GetAsyncKeyState(83) != 0 || GetAsyncKeyState(VK_DOWN) != 0)//讀取DOWN輸入
        {
            //pecMan.changeDirection(DIR_DOWN);
        }
        if (GetAsyncKeyState(65) != 0 || GetAsyncKeyState(VK_LEFT) != 0 )//讀取LEFT輸入
        {
            // pecMan.changeDirection(DIR_LEFT);
        }
        if (GetAsyncKeyState(68) != 0 || GetAsyncKeyState(VK_RIGHT) != 0)//讀取RIGHT輸入
        {
            // pecMan.changeDirection(DIR_RIGHT);
        }
        Sleep(400);
    }
    
    return 0;
}

