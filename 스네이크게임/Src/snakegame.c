#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//키보드 입력값들
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

#define MAP_WIDTH 30
#define MAP_HEIGHT 20
#define MAP_OFFSET_X 3
#define MAP_OFFSET_Y 2
#define BASE_SPEED 100

CONSOLE_CURSOR_INFO CurInfo;

int x[100], y[100];
int food_x, food_y;
int length;
int speed;
int score;
int best_score = 0;
int last_score = 0;
int dir;
int key;

void Init();
void KeyProcess();
void Title();
void DrawMap();
void MakeFood();
void DrawSnake(int dir);
void Pause();
void GameProcess();
void GameOver();

void DrawChar(int x, int y, char* s)
{
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}

int main()
{
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);

	Title();
	while (1)
	{
		KeyProcess();
		GameProcess();
		DrawSnake(dir);
	}

	return 0;
}

void Init()
{
	system("cls");
	DrawMap();

	while (_kbhit())
	{
		_getch();
	}

	dir = LEFT;
	speed = BASE_SPEED;
	length = 5;
	score = 0;

	for (int i = 0; i < length; i++)
	{
		x[i] = MAP_WIDTH / 2 + i;
		y[i] = MAP_HEIGHT / 2;

		if (i == 0)
		{
			DrawChar(MAP_OFFSET_X + x[i], MAP_OFFSET_Y + y[i], "◆");
		}
		else
		{
			DrawChar(MAP_OFFSET_X + x[i], MAP_OFFSET_Y + y[i], "○");
		}
	}

	MakeFood();
}

void Title()
{
	int cnt = 0;
	DrawMap();

	//공백으로 지우기
	for (int i = MAP_OFFSET_Y + 1; i < MAP_OFFSET_Y + MAP_HEIGHT - 1; i++)
	{
		for (int j = MAP_OFFSET_X + 1; j < MAP_OFFSET_X + MAP_WIDTH - 1; j++)
		{
			DrawChar(j, i, "  ");
		}
	}

	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 5, "****************************");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 6, "*      스네이크 게임       *");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 7, "****************************");

	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 11, "     ◁,▷,△,▽ : Move    ");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 12, "     P : Pause             ");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 13, "     ESC : Quit              ");

	while (1)
	{
		cnt++;
		if (_kbhit())
		{
			key = _getch();

			if (key == ESC)
			{
				exit(0);
			}
			else
			{
				break;
			}
		}

		if (cnt % 2 == 0)
		{
			DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 9, " < PRESS ANY KEY TO START > ");
		}
		else
		{
			DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 9, "                            ");
		}

		Sleep(200);
	}

	while (_kbhit())
	{
		_getch();
	}

	Init();
}

void DrawMap()
{
	//맵 맨윗줄
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		DrawChar(MAP_OFFSET_X + i, MAP_OFFSET_Y, "■");
	}

	//맵 중간
	for (int i = MAP_OFFSET_Y + 1; i < MAP_OFFSET_Y + MAP_HEIGHT - 1; i++)
	{
		DrawChar(MAP_OFFSET_X, i, "■");
		DrawChar(MAP_OFFSET_X + MAP_WIDTH - 1, i, "■");
	}

	//맵 맨아랫줄
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		DrawChar(MAP_OFFSET_X + i, MAP_OFFSET_Y + MAP_HEIGHT - 1, "■");
	}
}

void KeyProcess()
{
	if (_kbhit())
	{
		do
		{
			key = _getch();
		} while (key == 224);
	}

	Sleep(speed);

	switch (key)
	{
	case LEFT:
	case RIGHT:
	case UP:
	case DOWN:

		if ((dir == LEFT && key != RIGHT) || (dir == RIGHT && key != LEFT) || (dir == UP && key != DOWN) || (dir == DOWN && key != UP))
		{
			dir = key;
		}

		key = 0;
		break;

	case PAUSE:
		Pause();
		break;

	case ESC:
		exit(0);
	}
}

void GameProcess()
{
	//벽과의 충돌 검사
	if (x[0] == 0 || x[0] == MAP_WIDTH - 1 || y[0] == 0 || y[0] == MAP_HEIGHT - 1)
	{
		GameOver();
	}

	//머리가 몸통에 닿았는가
	for (int i = 1; i < length; i++)
	{
		if (x[0] == x[i] && y[0] == y[i])
		{
			GameOver();
		}
	}

	//먹이와의 충돌 검사
	if (x[0] == food_x && y[0] == food_y)
	{
		score += 10;
		MakeFood();
		length++;
		x[length - 1] = x[length - 2];
		y[length - 1] = y[length - 2];
	}
}

void DrawSnake(int dir)
{
	DrawChar(MAP_OFFSET_X + x[length - 1], MAP_OFFSET_Y + y[length - 1], "  ");

	for (int i = length - 1; i > 0; i--)
	{
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}

	DrawChar(MAP_OFFSET_X + x[0], MAP_OFFSET_Y + y[0], "○");

	if (dir == LEFT)
	{
		--x[0];
	}

	if (dir == RIGHT)
	{
		++x[0];
	}

	if (dir == UP)
	{
		--y[0];
	}

	if (dir == DOWN)
	{
		++y[0];
	}

	DrawChar(MAP_OFFSET_X + x[0], MAP_OFFSET_Y + y[0], "◆");
}

void GameOver()
{
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 6, MAP_OFFSET_Y + 5, "*************************");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 6, MAP_OFFSET_Y + 6, "*       GAME OVER       *");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 6, MAP_OFFSET_Y + 7, "*************************");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 6, MAP_OFFSET_Y + 8, " YOUR SCORE : ");
	printf("%d", last_score = score);

	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 12, " Press any keys to restart.. ");

	if (score > best_score)
	{
		best_score = score;
		DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 4, MAP_OFFSET_Y + 10, "☆ BEST SCORE ☆");
	}

	Sleep(400);

	while (_kbhit())
	{
		_getch();
	}

	key = _getch();
	Title();
}

void MakeFood()
{
	int iscrush = 0;

	while (1)
	{
		iscrush = 0;
		srand((unsigned)time(NULL));
		food_x = (rand() % (MAP_WIDTH - 2)) + 1;    //난수를 좌표값에 넣음
		food_y = (rand() % (MAP_HEIGHT - 2)) + 1;

		for (int i = 0; i < length; i++)
		{
			if (food_x == x[i] && food_y == y[i])
			{
				iscrush = 1;
				break;
			}
		}

		if (iscrush == 1)
		{
			continue;
		}

		DrawChar(MAP_OFFSET_X + food_x, MAP_OFFSET_Y + food_y, "♪");

		speed -= 3; //속도 증가
		if (speed < 0)
		{
			speed = 0;
		}

		break;
	}
}

void Pause(void)
{
	int cnt = 0;
	while (1)
	{
		cnt++;

		if (cnt % 2 == 0)
		{
			DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 9, MAP_OFFSET_Y, "< PAUSE : PRESS ANY KEY TO RESUME > ");
		}
		else
		{
			DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 9, MAP_OFFSET_Y, "                                    ");
		}

		Sleep(200);

		if (_kbhit())
		{
			key = _getch();
			if (key == ESC)
			{
				exit(0);
			}
			else
			{
				DrawMap();
				break;
			}
		}
	}

	while (_kbhit())
	{
		_getch();
	}
}