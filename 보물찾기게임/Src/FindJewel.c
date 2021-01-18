#include "GameProcess.h"
#include "PrintGame.h"
#include "CursorControl.h"
#include "KeyProcess.h"

int main(void)
{
	setcursortype(NOCURSOR); //커서가 보이지 않도록 설정
	Title(); //타이틀화면 출력

	while (1)
	{
		PrintGame();
		KeyProcess();
		GameProcess();
	}

	return 0;
}