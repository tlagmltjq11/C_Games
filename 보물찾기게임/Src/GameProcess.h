#ifndef __GAME_PROCESS_H__
#define __GAME_PROCESS_H__
#include "KeyProcess.h" // _select�� �����ϱ� ����.
#include "PrintGame.h"
#include <stdio.h> // printf

void GameProcess();

#define ROAD 0
#define WALL 1
#define GEM 2

extern int map[10][10]; // 3���� ���� PrintGame���� �����ϱ� ����. �����ü�� ���� �����ϸ� �ȵǳİ� ����ôµ�, �ٸ� �������� ����ϴ� ������ ������ extern�� �������ַ��� �̷� ����� ����Ѵ� �Ͻ�.
extern int heroX;
extern int heroY;

#endif // !__GAME_PROCESS_H__
