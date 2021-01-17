#ifndef __CURSOR_CONTROL_H__
#define __CURSOR_CONTROL_H__

#include <Windows.h>

//Ŀ�� Ÿ�� ����
typedef enum
{
	NOCURSOR = 1,
	SOLIDCURSOR,
	NORMALCURSOR
} CURSOR_TYPE;

void gotoxy(int x, int y);
void setcusortype(CURSOR_TYPE c);

#endif // !__CURSOR_CONTROL_H__
