#include "CursorControl.h"


void gotoxy(int x, int y) //특정위치로 커서를 옮기는 함수
{
	COORD pos = { x * 2, y }; //x,y를 갖고있는 구조체, 자연스럽게 움직이도록 x좌표는 *2를 해준다.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //표준출력의 핸들, 좌표를 넘겨주어 해당 위치로 커서를 이동시킴.
}

void setcursortype(CURSOR_TYPE c) //커서 타입 설정
{
	CONSOLE_CURSOR_INFO CurInfo; //커서의 정보를 갖는 구조체

	switch (c)
	{
	case NOCURSOR:
		CurInfo.dwSize = 1; //커서 사이즈
		CurInfo.bVisible = FALSE; //커서를 안보이게 설정
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

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo); //표준출력의 핸들, 커서정보를 넘겨주어 커서 설정.
};

