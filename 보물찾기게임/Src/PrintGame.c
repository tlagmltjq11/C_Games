#include "PrintGame.h"

void PrintGame()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			gotoxy(j, i); // ��ǥ�� ���� Ŀ����ü�� �Űܼ� �׸��� �ϳ��� �׷��ֱ� ������ �������̳� cls�� ���� �ʿ���Եȴ�. ��� �����Ÿ��� �ʴ� ȭ���� ��µǰԵ�.

			if (map[i][j] == ROAD)
			{
				if (i == heroY && j == heroX)
				{
					printf("��");
				}
				else
				{
					printf("��");
				}
			}
			else if (map[i][j] == WALL)
			{
				printf("��");
			}
			else if (map[i][j] == GEM)
			{
				printf("��");
			}
		}
		//printf("\n");
	}
}

void Title()
{
	int x = 5;
	int y = 5;
	int cnt = 0; //Ÿ��Ʋ �������� ���� ����  

	gotoxy(x, y + 0);	printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�"); //���ӿ��� �޼��� 
	gotoxy(x, y + 1);	printf("��                              ��");
	gotoxy(x, y + 2);	printf("��  +-----------------------+   ��");
	gotoxy(x, y + 3);	printf("��  |    ����ã�� ����!     |   ��");
	gotoxy(x, y + 4);	printf("��  +-----------------------+   ��");
	gotoxy(x, y + 5);	printf("��                              ��");
	gotoxy(x, y + 6);	printf("��                              ��");
	gotoxy(x, y + 7);	printf("��                              ��");
	gotoxy(x, y + 8);	printf("��                              ��");
	gotoxy(x, y + 9);	printf("��                              ��");
	gotoxy(x, y + 10);	printf("��                              ��");
	gotoxy(x, y + 11);	printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
	gotoxy(x + 3, y + 5); printf("  ��   : Up");
	gotoxy(x + 3, y + 6); printf("��  �� : Left | Right");
	gotoxy(x + 3, y + 7); printf("  ��   : Down");
	gotoxy(x + 3, y + 8); printf("  ESC  : Exit Game");

	while (1)
	{
		cnt++;
		if (_kbhit())break;
		if (cnt % 2 == 0)
		{
			gotoxy(x + 1, y + 10); printf("    Press any key to start   ");
		}
		else
		{
			gotoxy(x + 1, y + 10); printf("                             ");
		}
		Sleep(200);
	}
	while (_kbhit()) _getch();
	system("cls");
}

void GameClear()
{
	int x = 2;
	int y = 3;
	gotoxy(x, y + 0); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
	gotoxy(x, y + 1); printf("��                              ��");
	gotoxy(x, y + 2); printf("��          C L E A R !         ��");
	gotoxy(x, y + 3); printf("��                              ��");
	gotoxy(x, y + 4); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
	_getch();
	system("cls");
}
