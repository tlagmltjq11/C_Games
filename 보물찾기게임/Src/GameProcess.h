#ifndef __GAME_PROCESS_H__
#define __GAME_PROCESS_H__
#include "KeyProcess.h" // _select를 참조하기 위함.
#include "PrintGame.h"
#include <stdio.h> // printf

void GameProcess();

#define ROAD 0
#define WALL 1
#define GEM 2

extern int map[10][10]; // 3변수 전부 PrintGame에서 참조하기 위함. 헤더자체에 맵을 선언하면 안되냐고 여쭤봤는데, 다른 곳에서도 써야하는 변수기 때문에 extern을 설정해주려면 이런 방식을 사용한다 하심.
extern int heroX;
extern int heroY;

#endif // !__GAME_PROCESS_H__
