#ifndef __GAME_PROCESS_H__
#define __GAME_PROCESS_H__
#include "PrintGame.h"
#include <stdio.h>

#define ROAD 0 //길
#define WALL 1 //벽
#define GEM 2 //보석

//KeyProcess.c 외부변수 사용
extern int _select;

void GameProcess(); //플레이어 이동 및 상태처리

#endif // !__GAME_PROCESS_H__
