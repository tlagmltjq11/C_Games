#include "GameProcess.h"

int heroX = 0;
int heroY = 0;

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

void GameProcess()
{
	switch (_select)
	{
	case 1:
		if ((heroY - 1) >= 0)
		{
			if (map[heroY - 1][heroX] == ROAD)
			{
				heroY--;
			}
			else if (map[heroY - 1][heroX] == WALL)
			{
				printf("�̵��� �� �����ϴ�.\n");
			}
			else if (map[heroY - 1][heroX] == GEM)
			{
				printf("������ ã�ҽ��ϴ� !.\n");
				GameClear();
				heroX = heroY = 0;
			}
		}
		else
		{
			printf("�̵��� �� �����ϴ�.\n");
		}
		break;

	case 2:
		if ((heroY + 1) <= 9)
		{
			if (map[heroY + 1][heroX] == ROAD)
			{
				heroY++;
			}
			else if (map[heroY + 1][heroX] == WALL)
			{
				printf("�̵��� �� �����ϴ�.\n");
			}
			else if (map[heroY + 1][heroX] == GEM)
			{
				printf("������ ã�ҽ��ϴ� !.\n");
				GameClear();
				heroX = heroY = 0;
			}
		}
		else
		{
			printf("�̵��� �� �����ϴ�.\n");
		}
		break;

	case 3:
		if ((heroX - 1) >= 0)
		{
			if (map[heroY][heroX - 1] == ROAD)
			{
				heroX--;
			}
			else if (map[heroY][heroX - 1] == WALL)
			{
				printf("�̵��� �� �����ϴ�.\n");
			}
			else if (map[heroY][heroX - 1] == GEM)
			{
				printf("������ ã�ҽ��ϴ� !.\n");
				GameClear();
				heroX = heroY = 0;
			}
		}
		else
		{
			printf("�̵��� �� �����ϴ�.\n");
		}
		break;

	case 4:
		if ((heroX + 1) <= 9)
		{
			if (map[heroY][heroX + 1] == ROAD)
			{
				heroX++;
			}
			else if (map[heroY][heroX + 1] == WALL)
			{
				printf("�̵��� �� �����ϴ�.\n");
			}
			else if (map[heroY][heroX + 1] == GEM)
			{
				printf("������ ã�ҽ��ϴ� !.\n");
				GameClear();
				heroX = heroY = 0;
			}
		}
		else
		{
			printf("�̵��� �� �����ϴ�.\n");
		}
		break;

	default:
		break;
	}

	_select = 0;
}