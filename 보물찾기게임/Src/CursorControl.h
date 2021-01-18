#ifndef __CURSOR_CONTROL_H__
#define __CURSOR_CONTROL_H__
#include <Windows.h> //Ŀ������

//Ŀ�� Ÿ�� ����
typedef enum
{
	NOCURSOR = 1,
	SOLIDCURSOR,
	NORMALCURSOR
} CURSOR_TYPE;

void gotoxy(int x, int y); //Ŀ�� ��ǥ �̵�
void setcusortype(CURSOR_TYPE c); //Ŀ�� ����

#endif // !__CURSOR_CONTROL_H__
