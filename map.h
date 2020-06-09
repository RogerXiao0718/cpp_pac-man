
#ifndef MAP_H
#define MAP_H
#include <vector>
#define MAP_WIDTH 27
#define MAP_HEIGHT 30
#define BEAN '.'
#define WALL '#'
#define SUPER_BEAN 'o'

extern std::vector<std::vector<char>> map;
void initMap();

#endif