#include "GameProcess.h"
#include "PrintGame.h"
#include "CursorControl.h"
#include "KeyProcess.h"

int main(void)
{
	setcursortype(NOCURSOR); //Ŀ���� ������ �ʵ��� ����
	Title(); //Ÿ��Ʋȭ�� ���

	while (1)
	{
		PrintGame();
		KeyProcess();
		GameProcess();
	}

	return 0;
}