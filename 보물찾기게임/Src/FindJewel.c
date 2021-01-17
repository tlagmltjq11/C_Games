#include "GameProcess.h"
#include "PrintGame.h"
#include "CursorControl.h"
#include "KeyProcess.h"

int main(void)
{
	setcursortype(NOCURSOR);
	Title();

	while (1)
	{
		PrintGame();
		KeyProcess();
		GameProcess();
	}

	return 0;
}
