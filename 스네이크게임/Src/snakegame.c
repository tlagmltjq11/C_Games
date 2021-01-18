#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//Ű���� �Է°���
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

//�� ������
#define MAP_WIDTH 30
#define MAP_HEIGHT 20
#define MAP_OFFSET_X 3
#define MAP_OFFSET_Y 2
#define BASE_SPEED 100

CONSOLE_CURSOR_INFO CurInfo; //Ŀ�� ���� ����ü

int x[100], y[100]; //�� ���������� ��ġ x��ǥ y��ǥ
int food_x, food_y; //������ ��ġ
int length; //���� ����
int speed; //�ӵ�
int score; //����
int best_score = 0; //�ְ�����
int last_score = 0; //����������
int dir; //����
int key; //�Է°�

void Init(); //�ʱ�ȭ
void KeyProcess2(); //Ű�Է�ó��
void Title2(); //Ÿ��Ʋȭ�� ���
void DrawMap(); //�� ���
void MakeFood(); //���� ����
void DrawSnake(int dir); //�� ���
void Pause(); //�Ͻ� ����
void GameProcess2(); //���� �̵� �� ����ó��
void GameOver(); //���� ��� ȭ��


void DrawChar(int x, int y, char* s) //Ŀ����ġ�� �Ű� �ش� ��ġ�� ������ִ� �Լ�
{
	COORD pos = { 2 * x, y }; //��ǥ ����ü
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //ǥ������� �ڵ�� ��ǥ���� �Ѱ� ���� Ŀ����ġ�� ����
	printf("%s", s); //���� Ŀ����ġ�� ���
}

int main()
{
	//---------------Ŀ���� �������ʰ� ���� Start-----------------//
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
	//---------------Ŀ���� �������ʰ� ���� End-----------------//

	Title(); //Ÿ��Ʋȭ�� ���

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
	//������ �����ϱ� ���� �������� �����
	for (int i = MAP_OFFSET_Y + 1; i < MAP_OFFSET_Y + MAP_HEIGHT - 1; i++)
	{
		for (int j = MAP_OFFSET_X + 1; j < MAP_OFFSET_X + MAP_WIDTH - 1; j++)
		{
			DrawChar(j, i, "  ");
		}
	}

	while (_kbhit()) //���� ����
	{
		_getch();
	}

	dir = LEFT; //���ʹ������� �ʱ�ȭ
	speed = BASE_SPEED;
	length = 5; //�������̸� 5�� �ʱ�ȭ
	score = 0;

	for (int i = 0; i < length; i++) //���� ù ��ġ�� ������ �׷��ش�.
	{
		x[i] = MAP_WIDTH / 2 + i;
		y[i] = MAP_HEIGHT / 2;

		if (i == 0) //�Ӹ�
		{
			DrawChar(MAP_OFFSET_X + x[i], MAP_OFFSET_Y + y[i], "��");
		}
		else //����
		{
			DrawChar(MAP_OFFSET_X + x[i], MAP_OFFSET_Y + y[i], "��");
		}
	}

	MakeFood(); //���� ����
}

void Title()
{
	int cnt = 0;

	DrawMap();

	//�������� Ÿ��Ʋ�� ǥ���ϱ� ���� �������� �����
	for (int i = MAP_OFFSET_Y + 1; i < MAP_OFFSET_Y + MAP_HEIGHT - 1; i++)
	{
		for (int j = MAP_OFFSET_X + 1; j < MAP_OFFSET_X + MAP_WIDTH - 1; j++)
		{
			DrawChar(j, i, "  ");
		}
	}

	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 5, "****************************");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 6, "*      ������ũ ����       *");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 7, "****************************");

	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 11, "     ��,��,��,�� : Move    ");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 12, "     P : Pause             ");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 13, "     ESC : Quit              ");

	while (1)
	{
		cnt++; //������ ī��Ʈ

		if (_kbhit()) //Ű���� �Է��� ���� ���
		{
			key = _getch();

			if (key == ESC) //Esc �Է� �� ����
			{
				exit(0);
			}
			else //�� �� �Է½� ���� ������ ���� break
			{
				break;
			}
		}

		if (cnt % 2 == 0) //�Ʒ� ������ �����״� �ݺ�
		{
			DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 9, " < PRESS ANY KEY TO START > ");
		}
		else
		{
			DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 9, "                            ");
		}

		Sleep(200); //�ʹ� ���� �ݺ��� ����
	}

	while (_kbhit()) //Ű���۸� ���
	{
		_getch();
	}

	Init();
}

void DrawMap()
{
	//�� ������
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		DrawChar(MAP_OFFSET_X + i, MAP_OFFSET_Y, "��");
	}

	//�� �߰�
	for (int i = MAP_OFFSET_Y + 1; i < MAP_OFFSET_Y + MAP_HEIGHT - 1; i++)
	{
		DrawChar(MAP_OFFSET_X, i, "��");
		DrawChar(MAP_OFFSET_X + MAP_WIDTH - 1, i, "��");
	}

	//�� �ǾƷ���
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		DrawChar(MAP_OFFSET_X + i, MAP_OFFSET_Y + MAP_HEIGHT - 1, "��");
	}
}

void KeyProcess()
{
	if (_kbhit())
	{
		do
		{
			key = _getch();
		} while (key == 224); //����Ű �Է½� 224 ���� ���ڰ��� ���� -> 224���� �����ش�.
	}

	Sleep(speed); //sleep�� �̿��ؼ� �ӵ��� ������

	switch (key)
	{
	case LEFT:
	case RIGHT:
	case UP:
	case DOWN:

		if ((dir == LEFT && key != RIGHT) || (dir == RIGHT && key != LEFT) || (dir == UP && key != DOWN) || (dir == DOWN && key != UP)) //�������� ���ݴ��� ������ �� �� ������ ó��
		{
			dir = key;
		}

		key = 0;
		break;

	case PAUSE:
		Pause(); //�Ͻ�����
		break;

	case ESC:
		exit(0); //��������
	}
}

void GameProcess()
{
	//������ �浹 �˻�
	if (x[0] == 0 || x[0] == MAP_WIDTH - 1 || y[0] == 0 || y[0] == MAP_HEIGHT - 1)
	{
		GameOver();
	}

	//�Ӹ��� ���뿡 ��Ҵ°�
	for (int i = 1; i < length; i++)
	{
		if (x[0] == x[i] && y[0] == y[i])
		{
			GameOver();
		}
	}

	//���̿��� �浹 �˻�
	if (x[0] == food_x && y[0] == food_y)
	{
		score += 10;
		MakeFood(); //���� �����
		length++; //������ ��ĭ �÷��ش�.
		x[length - 1] = x[length - 2]; //�þ ������ ��ǥ�� �ٷ� ���� ������ ��ǥ������ �������ش�.
		y[length - 1] = y[length - 2];
	}
}

void DrawSnake(int dir)
{
	DrawChar(MAP_OFFSET_X + x[length - 1], MAP_OFFSET_Y + y[length - 1], "  "); //���� ������ �����κ��� �����ش�.

	//�ڽ��� ��ǥ���� ��ĭ���� �Ѱ��ָ鼭 ���� �̵��� ��Ÿ����. 
	//-> ex) x[5] = x[4]�϶� 5��° ������ 4��° ������ ��ǥ���� ������ �ǹǷ� ȭ��� ������ �̵��ϰԵ�.
	for (int i = length - 1; i > 0; i--)
	{
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}

	DrawChar(MAP_OFFSET_X + x[0], MAP_OFFSET_Y + y[0], "��"); //�� ���ڸ����� ������ �׷��ش�.

	//�̵������� ��ǥ�� ����
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

	DrawChar(MAP_OFFSET_X + x[0], MAP_OFFSET_Y + y[0], "��"); //�̵� ���� �Ӹ��� �׷��ش�.
}

void GameOver()
{
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 6, MAP_OFFSET_Y + 5, "*************************");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 6, MAP_OFFSET_Y + 6, "*       GAME OVER       *");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 6, MAP_OFFSET_Y + 7, "*************************");
	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 6, MAP_OFFSET_Y + 8, " YOUR SCORE : ");
	printf("%d", last_score = score);

	DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 7, MAP_OFFSET_Y + 12, " Press any keys to restart.. ");

	if (score > best_score) //�ְ��� ����
	{
		best_score = score;
		DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 4, MAP_OFFSET_Y + 10, "�� BEST SCORE ��"); //�ְ������� �˸�
	}

	Sleep(400); //���ȭ���� ��ö� �����ֱ����� Ű�Է��� ����.

	while (_kbhit()) //Ű���۸� ���
	{
		_getch();
	}

	key = _getch();

	Title(); //���� �����
}

void MakeFood() //���� ���̸� ������ǥ�� ����
{
	int iscrush = 0; //���� ��ü�� �浹�ϴ� ��ǥ���� üũ�ϴ� ����

	while (1)
	{
		iscrush = 0;

		srand((unsigned)time(NULL)); //����ð��� �õ�� �־��ش�.

		food_x = (rand() % (MAP_WIDTH - 2)) + 1;    //������ ��ǥ���� ����, ������ ������ �̿��ؼ� �ʳ��� ��ǥ�� �̾Ƴ���.
		food_y = (rand() % (MAP_HEIGHT - 2)) + 1;

		for (int i = 0; i < length; i++)
		{
			if (food_x == x[i] && food_y == y[i]) //�ش� ��ǥ�� ���� ��ġ�� ������ ���
			{
				iscrush = 1; //�浹������ �˸�
				break;
			}
		}

		if (iscrush == 1)
		{
			continue; //��ǥ�� �ٽ� �����ϵ��� ����
		}

		DrawChar(MAP_OFFSET_X + food_x, MAP_OFFSET_Y + food_y, "��"); //��� �浹�Ǵ� ��ġ�� �ƴ϶�� ���������� ���̻���

		speed -= 3; //���� �̵��ӵ� ����
		if (speed < 0)
		{
			speed = 0;
		}

		break;
	}
}

void Pause(void) //���� �Ͻ�����
{
	int cnt = 0;

	while (1) //���ѹݺ��� ���� �Ͻ�����
	{
		cnt++;

		if (cnt % 2 == 0) //�Ʒ� ������ �����״� �ݺ�
		{
			DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 9, MAP_OFFSET_Y, "< PAUSE : PRESS ANY KEY TO RESUME > ");
		}
		else
		{
			DrawChar(MAP_OFFSET_X + (MAP_WIDTH / 2) - 9, MAP_OFFSET_Y, "                                    ");
		}

		Sleep(200); //�ʹ� ���� �ݺ��� ����

		if (_kbhit()) //Ű���� �Է��� ���� ���
		{
			key = _getch();
			if (key == ESC) //��������
			{
				exit(0);
			}
			else //�����
			{
				DrawMap();
				break;
			}
		}
	}

	while (_kbhit()) //Ű���۸� ���
	{
		_getch();
	}
}