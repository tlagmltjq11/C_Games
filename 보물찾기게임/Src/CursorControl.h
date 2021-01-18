#ifndef __CURSOR_CONTROL_H__
#define __CURSOR_CONTROL_H__
#include <Windows.h> //커서관련

//커서 타입 정의
typedef enum
{
	NOCURSOR = 1,
	SOLIDCURSOR,
	NORMALCURSOR
} CURSOR_TYPE;

void gotoxy(int x, int y); //커서 좌표 이동
void setcusortype(CURSOR_TYPE c); //커서 설정

#endif // !__CURSOR_CONTROL_H__
