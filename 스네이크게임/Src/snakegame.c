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

//맵 조정값
#define MAP_WIDTH 30
#define MAP_HEIGHT 20
#define MAP_OFFSET_X 3
#define MAP_OFFSET_Y 2
#define BASE_SPEED 100

CONSOLE_CURSOR_INFO CurInfo; //커서 정보 구조체

int x[100], y[100]; //뱀 꼬리까지의 위치 x좌표 y좌표
int food_x, food_y; //먹이의 위치
int length; //뱀의 길이
int speed; //속도
int score; //점수
int best_score = 0; //최고점수
int last_score = 0; //마지막점수
int dir; //방향
int key; //입력값

void Init(); //초기화
void KeyProcess2(); //키입력처리
void Title2(); //타이틀화면 출력
void DrawMap(); //맵 출력
void MakeFood(); //먹이 생성
void DrawSnake(int dir); //뱀 출력
void Pause(); //일시 중지
void GameProcess2(); //뱀의 이동 후 상태처리
void GameOver(); //게임 결과 화면


void DrawChar(int x, int y, char* s) //커서위치를 옮겨 해당 위치에 출력해주는 함수
{
	COORD pos = { 2 * x, y }; //좌표 구조체
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //표준출력의 핸들과 좌표값을 넘겨 현재 커서위치를 설정
	printf("%s", s); //현재 커서위치에 출력
}

int main()
{
	//---------------커서를 보이지않게 설정 Start-----------------//
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
	//---------------커서를 보이지않게 설정 End-----------------//

	Title(); //타이틀화면 출력

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
	//게임을 시작하기 위해 공백으로 지우기
	for (int i = MAP_OFFSET_Y + 1; i < MAP_OFFSET_Y + MAP_HEIGHT - 1; i++)
	{
		for (int j = MAP_OFFSET_X + 1; j < MAP_OFFSET_X + MAP_WIDTH - 1; j++)
		{
			DrawChar(j, i, "  ");
		}
	}

	while (_kbhit()) //버퍼 비우기
	{
		_getch();
	}

	dir = LEFT; //왼쪽방향으로 초기화
	speed = BASE_SPEED;
	length = 5; //꼬리길이를 5로 초기화
	score = 0;

	for (int i = 0; i < length; i++) //뱀의 첫 위치를 설정해 그려준다.
	{
		x[i] = MAP_WIDTH / 2 + i;
		y[i] = MAP_HEIGHT / 2;

		if (i == 0) //머리
		{
			DrawChar(MAP_OFFSET_X + x[i], MAP_OFFSET_Y + y[i], "◆");
		}
		else //꼬리
		{
			DrawChar(MAP_OFFSET_X + x[i], MAP_OFFSET_Y + y[i], "○");
		}
	}

	MakeFood(); //먹이 생성
}

void Title()
{
	int cnt = 0;

	DrawMap();

	//새게임의 타이틀을 표시하기 위해 공백으로 지우기
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
		cnt++; //프레임 카운트

		if (_kbhit()) //키보드 입력이 들어온 경우
		{
			key = _getch();

			if (key == ESC) //Esc 입력 시 종료
			{
				exit(0);
			}
			else //그 외 입력시 게임 시작을 위해 break
			{
				break;
			}
		}

		if (cnt % 2 == 0) //아래 문구를 껐다켰다 반복
		{
			DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 9, " < PRESS ANY KEY TO START > ");
		}
		else
		{
			DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 9, "                            ");
		}

		Sleep(200); //너무 빠른 반복을 방지
	}

	while (_kbhit()) //키버퍼를 비움
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
		} while (key == 224); //방향키 입력시 224 이후 각자값이 들어옴 -> 224값을 빼내준다.
	}

	Sleep(speed); //sleep을 이용해서 속도를 제한함

	switch (key)
	{
	case LEFT:
	case RIGHT:
	case UP:
	case DOWN:

		if ((dir == LEFT && key != RIGHT) || (dir == RIGHT && key != LEFT) || (dir == UP && key != DOWN) || (dir == DOWN && key != UP)) //진행방향과 정반대의 방향은 갈 수 없도록 처리
		{
			dir = key;
		}

		key = 0;
		break;

	case PAUSE:
		Pause(); //일시정지
		break;

	case ESC:
		exit(0); //게임종료
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
		MakeFood(); //먹이 재생성
		length++; //꼬리를 한칸 늘려준다.
		x[length - 1] = x[length - 2]; //늘어난 꼬리의 좌표를 바로 이전 꼬리의 좌표값으로 설정해준다.
		y[length - 1] = y[length - 2];
	}
}

void DrawSnake(int dir)
{
	DrawChar(MAP_OFFSET_X + x[length - 1], MAP_OFFSET_Y + y[length - 1], "  "); //뱀의 마지막 꼬리부분을 지워준다.

	//자신의 좌표값을 뒤칸으로 넘겨주면서 뱀의 이동을 나타낸다. 
	//-> ex) x[5] = x[4]일때 5번째 꼬리는 4번째 꼬리의 좌표값을 가지게 되므로 화면상 앞으로 이동하게됨.
	for (int i = length - 1; i > 0; i--)
	{
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}

	DrawChar(MAP_OFFSET_X + x[0], MAP_OFFSET_Y + y[0], "○"); //맨 앞자리에도 꼬리를 그려준다.

	//이동방향대로 좌표값 수정
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

	DrawChar(MAP_OFFSET_X + x[0], MAP_OFFSET_Y + y[0], "◆"); //이동 후의 머리를 그려준다.
}

void GameOver()
{
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 6, MAP_OFFSET_Y + 5, "*************************");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 6, MAP_OFFSET_Y + 6, "*       GAME OVER       *");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 6, MAP_OFFSET_Y + 7, "*************************");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 6, MAP_OFFSET_Y + 8, " YOUR SCORE : ");
	printf("%d", last_score = score);

	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 12, " Press any keys to restart.. ");

	if (score > best_score) //최고기록 갱신
	{
		best_score = score;
		DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 4, MAP_OFFSET_Y + 10, "☆ BEST SCORE ☆"); //최고기록임을 알림
	}

	Sleep(400); //결과화면을 잠시라도 보여주기위해 키입력을 늦춤.

	while (_kbhit()) //키버퍼를 비움
	{
		_getch();
	}

	key = _getch();

	Title(); //게임 재시작
}

void MakeFood() //뱀의 먹이를 랜덤좌표로 생성
{
	int iscrush = 0; //뱀의 몸체와 충돌하는 좌표인지 체크하는 변수

	while (1)
	{
		iscrush = 0;

		srand((unsigned)time(NULL)); //현재시간을 시드로 넣어준다.

		food_x = (rand() % (MAP_WIDTH - 2)) + 1;    //난수를 좌표값에 넣음, 나머지 연산을 이용해서 맵내의 좌표로 뽑아낸다.
		food_y = (rand() % (MAP_HEIGHT - 2)) + 1;

		for (int i = 0; i < length; i++)
		{
			if (food_x == x[i] && food_y == y[i]) //해당 좌표가 뱀의 위치와 동일할 경우
			{
				iscrush = 1; //충돌했음을 알림
				break;
			}
		}

		if (iscrush == 1)
		{
			continue; //좌표를 다시 생성하도록 유도
		}

		DrawChar(MAP_OFFSET_X + food_x, MAP_OFFSET_Y + food_y, "♪"); //뱀과 충돌되는 위치가 아니라면 정상적으로 먹이생성

		speed -= 3; //뱀의 이동속도 증가
		if (speed < 0)
		{
			speed = 0;
		}

		break;
	}
}

void Pause(void) //게임 일시중지
{
	int cnt = 0;

	while (1) //무한반복을 통해 일시중지
	{
		cnt++;

		if (cnt % 2 == 0) //아래 문구를 껐다켰다 반복
		{
			DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 9, MAP_OFFSET_Y, "< PAUSE : PRESS ANY KEY TO RESUME > ");
		}
		else
		{
			DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 9, MAP_OFFSET_Y, "                                    ");
		}

		Sleep(200); //너무 빠른 반복을 방지

		if (_kbhit()) //키보드 입력이 들어온 경우
		{
			key = _getch();
			if (key == ESC) //게임종료
			{
				exit(0);
			}
			else //재시작
			{
				DrawMap();
				break;
			}
		}
	}

	while (_kbhit()) //키버퍼를 비움
	{
		_getch();
	}
}