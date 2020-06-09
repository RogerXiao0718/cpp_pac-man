#include<iostream>
#include "beanCounter.h"
#include "map.h"
using namespace std;

int beanCounter;

int initBeanCounter() {
	beanCounter = 0;
	
	for (int x = 0; x < MAP_WIDTH; x++) {
		for (int y = 0; y < MAP_HEIGHT; y++) {
			if (map[y][x] == BEAN || map[y][x] == SUPER_BEAN)
				beanCounter++;
		}
	}
	
	return beanCounter;
}