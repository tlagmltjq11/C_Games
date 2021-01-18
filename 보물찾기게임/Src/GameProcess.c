#include "GameProcess.h"

//Player의 현재 위치
int heroX = 0;
int heroY = 0;

//맵 구성
int map[10][10] =
{
	{0,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,0,0,1},
	{1,0,0,0,0,0,1,1,0,1},
	{1,0,0,0,2,0,1,1,0,1},
	{1,1,1,1,1,0,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

void GameProcess() //플레이어 이동 및 상태처리
{
	switch (_select) //keyProcess에서 입력받은 방향키에 따라 분기문 처리
	{
	case 1: //Up
		if ((heroY - 1) >= 0) //맵 내의 이동인지 판별
		{
			if (map[heroY - 1][heroX] == ROAD) //길이라면 이동
			{
				heroY--;
			}
			else if (map[heroY - 1][heroX] == WALL) //벽이라면 이동 x
			{
				printf("이동할 수 없습니다.\n");
			}
			else if (map[heroY - 1][heroX] == GEM) //보석이라면 게임 클리어
			{
				printf("보석을 찾았습니다 !.\n");
				GameClear();
				heroX = heroY = 0;//플레이어 위치 초기화
			}
		}
		else
		{
			printf("이동할 수 없습니다.\n");
		}
		break;

	case 2: //Down
		if ((heroY + 1) <= 9) //맵 내의 이동인지 판별
		{
			if (map[heroY + 1][heroX] == ROAD)
			{
				heroY++;
			}
			else if (map[heroY + 1][heroX] == WALL)
			{
				printf("이동할 수 없습니다.\n");
			}
			else if (map[heroY + 1][heroX] == GEM)
			{
				printf("보석을 찾았습니다 !.\n");
				GameClear();
				heroX = heroY = 0;
			}
		}
		else
		{
			printf("이동할 수 없습니다.\n");
		}
		break;

	case 3: //Left
		if ((heroX - 1) >= 0)
		{
			if (map[heroY][heroX - 1] == ROAD)
			{
				heroX--;
			}
			else if (map[heroY][heroX - 1] == WALL)
			{
				printf("이동할 수 없습니다.\n");
			}
			else if (map[heroY][heroX - 1] == GEM)
			{
				printf("보석을 찾았습니다 !.\n");
				GameClear();
				heroX = heroY = 0;
			}
		}
		else
		{
			printf("이동할 수 없습니다.\n");
		}
		break;

	case 4: //Right
		if ((heroX + 1) <= 9)
		{
			if (map[heroY][heroX + 1] == ROAD)
			{
				heroX++;
			}
			else if (map[heroY][heroX + 1] == WALL)
			{
				printf("이동할 수 없습니다.\n");
			}
			else if (map[heroY][heroX + 1] == GEM)
			{
				printf("보석을 찾았습니다 !.\n");
				GameClear();
				heroX = heroY = 0;
			}
		}
		else
		{
			printf("이동할 수 없습니다.\n");
		}
		break;

	default:
		break;
	}

	_select = 0;
}