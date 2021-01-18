# C_Games
 
### About Snake Game.:snake:
콘솔창을 이용한 게임으로, 방향키로 뱀을 조종하여 먹이를 획득해 점수를 쌓는 방식입니다.<br>
먹이를 먹을수록 뱀의 길이와 속도는 증가하며, 뱀의 머리가 벽에 닿거나 자신의 꼬리에 닿게되면 Gameover 됩니다.<br>
<br>

### About Dev.:nut_and_bolt:
1. 커서를 직접 컨트롤해 화면을 출력하도록 하여, Clear Screen으로 인한 화면의 깜빡임을 방지했습니다.
2. 현재시간을 seed로 넣어 난수를 생성해, 랜덤한 위치에 먹이가 생성되도록 했습니다.
3. 뱀의 이동 로직 Code
```c#
//뱀의 몸체좌표는 int x[], y[]에 머리부터 순차적으로 저장되어있음.

void DrawSnake(int dir)
{
	DrawChar(MAP_OFFSET_X + x[length - 1], MAP_OFFSET_Y + y[length - 1], "  "); //뱀의 마지막 꼬리부분을 지워준다.

	//자신의 좌표값을 뒤칸으로 넘겨주면서 뱀의 이동을 나타낸다. 
	//-> ex) x[5] = x[4]일때 5번째 꼬리는 4번째 꼬리의 좌표값을 가지게 되므로 화면상 앞으로 이동하게됨.
	for (int i = length - 1; i > 0; i--)
	{
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}

	DrawChar(MAP_OFFSET_X + x[0], MAP_OFFSET_Y + y[0], "○"); //맨 앞자리에도 꼬리를 그려준다.

	//이동방향대로 좌표값 수정
	if (dir == LEFT)
	{
		--x[0];
	}

	if (dir == RIGHT)
	{
		++x[0];
	}

	if (dir == UP)
	{
		--y[0];
	}

	if (dir == DOWN)
	{
		++y[0];
	}

	DrawChar(MAP_OFFSET_X + x[0], MAP_OFFSET_Y + y[0], "◆"); //이동 후의 머리를 그려준다.
}
```
<br>

### About ScreenShot.:camera:
<br>Title 화면<br>
<center><img src="https://user-images.githubusercontent.com/43705434/104903264-1f169300-59c3-11eb-8d61-4c5e99c9dbe5.PNG" width="800" height="500"></center>
<br>Game 화면<br>
<center><img src="https://user-images.githubusercontent.com/43705434/104903249-1c1ba280-59c3-11eb-9e24-b8aa224a265f.PNG" width="800" height="500"></center>
<center><img src="https://user-images.githubusercontent.com/43705434/104903255-1de56600-59c3-11eb-940c-6f601b7c0fdd.PNG" width="800" height="500"></center>
<br>Pause 화면<br>
<center><img src="https://user-images.githubusercontent.com/43705434/104903254-1d4ccf80-59c3-11eb-82b5-4998098262bc.PNG" width="800" height="500"></center>
<br>GameOver 화면<br>
<center><img src="https://user-images.githubusercontent.com/43705434/104903251-1d4ccf80-59c3-11eb-933d-a6e94aa69b76.PNG" width="800" height="500"></center>
<br>
<br>
<br>
 
### About Jewel Game.:gem:
콘솔창을 이용한 미로찾기 게임으로, 보석의 위치까지 길을 찾아 이동하면 됩니다.<br>
<br>

### About Dev.:nut_and_bolt:
1. 모듈화를 위해서, 기능별로 파일을 분할하여 개발했습니다.
2. 헤더파일의 중복삽입을 방지했습니다.
3. 커서를 직접 컨트롤해 화면을 출력하도록 하여, Clear Screen으로 인한 화면의 깜빡임을 방지했습니다. 
<br>

### About ScreenShot.:camera:
<br>Title 화면<br>
<center><img src="https://user-images.githubusercontent.com/43705434/104903256-1de56600-59c3-11eb-889f-54949a3b09e5.PNG" width="800" height="500"></center>
<br>Game 화면<br>
<center><img src="https://user-images.githubusercontent.com/43705434/104903257-1e7dfc80-59c3-11eb-9844-3cb33e4ac25e.PNG" width="800" height="500"></center>
<center><img src="https://user-images.githubusercontent.com/43705434/104903258-1e7dfc80-59c3-11eb-9384-31f7532af543.PNG" width="800" height="500"></center>
<br>Clear 화면<br>
<center><img src="https://user-images.githubusercontent.com/43705434/104903262-1f169300-59c3-11eb-9671-63dfd43ebcec.PNG" width="800" height="500"></center>
<br>
