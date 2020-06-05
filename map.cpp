#include <iostream>
#include <vector>
#include "map.h"
#include <Windows.h>

using namespace std;

vector<vector<char>> map;

void initMap() {
    //初始化地圖
    for (int i = 0; i < MAP_HEIGHT; i++) {
        //分配一個空的vector給每一列
        vector<char> row;
        map.push_back(row);
    }

    //繪製第一列
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        map[0].push_back(WALL);
    }
    //繪製第二列
    map[1] = { WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL, ' ', WALL, WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL };
    //繪製第三列
    map[2] = { WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL, ' ', WALL, WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL };
    //繪製第四列
    map[3] = { WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL };
    //繪製第五列
    map[4] = { WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //繪製第6列
    map[5] = { WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //繪製第7列
    map[6] = { WALL, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //第8列
    map[7] = { WALL, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //第9列
    map[8] = { WALL, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //第10列
    map[9] = { WALL, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, BEAN, WALL };
    //第11列
    map[10] = { WALL, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, BEAN, WALL };
    //第12列
    map[11] = { WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //第13列
    map[12] = { WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //第14列(小精靈的出生點)
    for (int i = 0; i < 13; i++)
    {
        map[13].push_back(BEAN);
    }
    map[13].push_back(' ');
    for (int i = 0; i < 13; i++)
    {
        map[13].push_back(BEAN);
    }
    //第15列
    map[14] = { WALL, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, WALL, WALL, WALL, WALL, ' ', BEAN, ' ', WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, WALL };
    //第16列
    map[15] = { WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, ' ', BEAN, ' ', WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //第17列
    map[16] = { WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //第18列
    map[17] = { WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //第19列
    map[18] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //第20列
    map[19] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //第21列
    map[20] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //第22列
    map[21] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //第23列
    map[22] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //第24列
    map[23] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //第25列
    map[24] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //第26列
    map[25] = { WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //第27列
    map[26] = { WALL, WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL, WALL, WALL, BEAN, WALL, WALL, WALL, WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL };
    //第28列
    map[27] = { WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL, WALL, WALL, BEAN, WALL, WALL, WALL, WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL };
    //第29列
    map[28] = { WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL, WALL, WALL, BEAN, WALL, WALL, WALL, WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL };
    //第30列 (我的腰椎...)
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        map[29].push_back(WALL);
    }
    return;
}



