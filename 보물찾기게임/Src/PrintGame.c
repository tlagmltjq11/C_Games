#include "PrintGame.h"

void PrintGame() //맵, 보석, 플레이어를 그려줌
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			gotoxy(j, i); // 커서를 직접 좌표이동하며 그림을 하나씩 그려주기 때문에, 뉴라인이나 cls가 따로 필요없게된다. 고로 깜빡거리지 않는 화면이 출력되게됨.

			if (map[i][j] == ROAD)
			{
				if (i == heroY && j == heroX) //플레이어일 경우
				{
					printf("♥");
				}
				else //길일 경우
				{
					printf("■");
				}
			}
			else if (map[i][j] == WALL) //벽일 경우
			{
				printf("▨");
			}
			else if (map[i][j] == GEM) //보석일 경우
			{
				printf("◆");
			}
		}
	}
}

void Title() //게임 타이틀 화면
{
	int x = 5;
	int y = 5;
	int cnt = 0; //타이틀 프레임을 세는 변수  

	gotoxy(x, y + 0);	printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
	gotoxy(x, y + 1);	printf("▤                              ▤");
	gotoxy(x, y + 2);	printf("▤  +-----------------------+   ▤");
	gotoxy(x, y + 3);	printf("▤  |    보석찾기 게임!     |   ▤");
	gotoxy(x, y + 4);	printf("▤  +-----------------------+   ▤");
	gotoxy(x, y + 5);	printf("▤                              ▤");
	gotoxy(x, y + 6);	printf("▤                              ▤");
	gotoxy(x, y + 7);	printf("▤                              ▤");
	gotoxy(x, y + 8);	printf("▤                              ▤");
	gotoxy(x, y + 9);	printf("▤                              ▤");
	gotoxy(x, y + 10);	printf("▤                              ▤");
	gotoxy(x, y + 11);	printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
	gotoxy(x + 3, y + 5); printf("  △   : Up");
	gotoxy(x + 3, y + 6); printf("◁  ▷ : Left | Right");
	gotoxy(x + 3, y + 7); printf("  ▽   : Down");
	gotoxy(x + 3, y + 8); printf("  ESC  : Exit Game");

	while (1)
	{
		cnt++;
		if (_kbhit()) //키입력이 들어오면 타이틀화면을 빠져나간다.
		{
			break;
		}

		if (cnt % 2 == 0) //아래 문구의 출력을 껐다켰다 해주는 효과
		{
			gotoxy(x + 1, y + 10); printf("    Press any key to start   ");
		}
		else
		{
			gotoxy(x + 1, y + 10); printf("                             ");
		}

		Sleep(200); //너무 빠른 반복을 막기 위해 Sleep
	}

	while (_kbhit()) //키버퍼를 비움
	{
		_getch();
	}

	system("cls"); //화면 초기화
}

void GameClear() //보석을 찾았을 시 결과화면
{
	int x = 2;
	int y = 3;
	gotoxy(x, y + 0); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
	gotoxy(x, y + 1); printf("▤                              ▤");
	gotoxy(x, y + 2); printf("▤          C L E A R !         ▤");
	gotoxy(x, y + 3); printf("▤                              ▤");
	gotoxy(x, y + 4); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");

	_getch(); //키입력이 들어오면 화면 클리어

	system("cls");
}