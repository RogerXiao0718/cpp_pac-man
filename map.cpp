#include <iostream>
#include <vector>
#include "map.h"
#include <Windows.h>

using namespace std;

vector<vector<char>> map;

void initMap() {
    //��l�Ʀa��
    for (int i = 0; i < MAP_HEIGHT; i++) {
        //���t�@�ӪŪ�vector���C�@�C
        vector<char> row;
        map.push_back(row);
    }

    //ø�s�Ĥ@�C
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        map[0].push_back(WALL);
    }
    //ø�s�ĤG�C
    map[1] = { WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL, ' ', WALL, WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL };
    //ø�s�ĤT�C
    map[2] = { WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL, ' ', WALL, WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL };
    //ø�s�ĥ|�C
    map[3] = { WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL };
    //ø�s�Ĥ��C
    map[4] = { WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //ø�s��6�C
    map[5] = { WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //ø�s��7�C
    map[6] = { WALL, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //��8�C
    map[7] = { WALL, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //��9�C
    map[8] = { WALL, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //��10�C
    map[9] = { WALL, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, BEAN, WALL };
    //��11�C
    map[10] = { WALL, BEAN, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, BEAN, WALL };
    //��12�C
    map[11] = { WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //��13�C
    map[12] = { WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //��14�C(�p���F���X���I)
    for (int i = 0; i < 13; i++)
    {
        map[13].push_back(BEAN);
    }
    map[13].push_back(' ');
    for (int i = 0; i < 13; i++)
    {
        map[13].push_back(BEAN);
    }
    //��15�C
    map[14] = { WALL, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, WALL, WALL, WALL, WALL, ' ', BEAN, ' ', WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, WALL };
    //��16�C
    map[15] = { WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, ' ', BEAN, ' ', WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //��17�C
    map[16] = { WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //��18�C
    map[17] = { WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //��19�C
    map[18] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //��20�C
    map[19] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //��21�C
    map[20] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //��22�C
    map[21] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //��23�C
    map[22] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //��24�C
    map[23] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //��25�C
    map[24] = { WALL, BEAN, BEAN, BEAN, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL };
    //��26�C
    map[25] = { WALL, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, BEAN, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, BEAN, WALL };
    //��27�C
    map[26] = { WALL, WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL, WALL, WALL, BEAN, WALL, WALL, WALL, WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL };
    //��28�C
    map[27] = { WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL, WALL, WALL, BEAN, WALL, WALL, WALL, WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL };
    //��29�C
    map[28] = { WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL, WALL, WALL, BEAN, WALL, WALL, WALL, WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL };
    //��30�C (�ڪ��y��...)
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        map[29].push_back(WALL);
    }
    return;
}



