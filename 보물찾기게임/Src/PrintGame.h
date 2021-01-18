#ifndef __PRINT_GAME_H__
#define __PRINT_GAME_H__
#include <stdio.h>
#include "CursorControl.h"

#define ROAD 0 //길
#define WALL 1 //벽
#define GEM 2 //보석

//GameProcess.c 외부변수 사용
extern int map[10][10];
extern int heroX;
extern int heroY;

void PrintGame(); //맵, 보석, 플레이어를 그려줌
void GameClear(); //보석을 찾았을 시 결과화면
void Title(); //게임 타이틀 화면

#endif // !__PRINT_GAME_H__