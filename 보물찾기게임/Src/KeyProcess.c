#include "KeyProcess.h"

int _select; //입력된 키

void KeyProcess() //키입력을 담당
{
	if (_kbhit()) // 입력을 대기하는것이 아니라 확인만 하는것 주의.
	{
		_select = _getch();

		if (_select == 224) //방향키는 특수키로 인식되어 입력이 두 개의 수로 들어간다. 224 후 각자 값
		{
			_select = _getch();

			switch (_select)
			{
			case  UP:
				_select = 1;
				break;
			case DOWN:
				_select = 2;
				break;
			case LEFT:
				_select = 3;
				break;
			case RIGHT:
				_select = 4;
				break;
			default:
				break;
			}
		}
		else if (_select == ESC)
		{
			exit(0);
		}
	}
}