#include "KeyProcess.h"

int _select; //�Էµ� Ű

void KeyProcess() //Ű�Է��� ���
{
	if (_kbhit()) // �Է��� ����ϴ°��� �ƴ϶� Ȯ�θ� �ϴ°� ����.
	{
		_select = _getch();

		if (_select == 224) //����Ű�� Ư��Ű�� �νĵǾ� �Է��� �� ���� ���� ����. 224 �� ���� ��
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