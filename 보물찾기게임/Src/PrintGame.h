#ifndef __PRINT_GAME_H__
#define __PRINT_GAME_H__
#include <stdio.h>
#include "CursorControl.h"

#define ROAD 0 //��
#define WALL 1 //��
#define GEM 2 //����

//GameProcess.c �ܺκ��� ���
extern int map[10][10];
extern int heroX;
extern int heroY;

void PrintGame(); //��, ����, �÷��̾ �׷���
void GameClear(); //������ ã���� �� ���ȭ��
void Title(); //���� Ÿ��Ʋ ȭ��

#endif // !__PRINT_GAME_H__