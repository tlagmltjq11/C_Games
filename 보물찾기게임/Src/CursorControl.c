#include "CursorControl.h"


void gotoxy(int x, int y) //Ư����ġ�� Ŀ���� �ű�� �Լ�
{
	COORD pos = { x * 2, y }; //x,y�� �����ִ� ����ü, �ڿ������� �����̵��� x��ǥ�� *2�� ���ش�.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //ǥ������� �ڵ�, ��ǥ�� �Ѱ��־� �ش� ��ġ�� Ŀ���� �̵���Ŵ.
}

void setcursortype(CURSOR_TYPE c) //Ŀ�� Ÿ�� ����
{
	CONSOLE_CURSOR_INFO CurInfo; //Ŀ���� ������ ���� ����ü

	switch (c)
	{
	case NOCURSOR:
		CurInfo.dwSize = 1; //Ŀ�� ������
		CurInfo.bVisible = FALSE; //Ŀ���� �Ⱥ��̰� ����
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	default:
		break;
	}

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo); //ǥ������� �ڵ�, Ŀ�������� �Ѱ��־� Ŀ�� ����.
};

