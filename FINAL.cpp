#include<iostream>
#include"FINAL.h"
using namespace std;
void FINAL::show()
{
	GameInit();  //游戏初始化
	DrawMenu();  //进入菜单
	while (1)
	{
		DrawMap();
		DrawSnake();
		DrawData();
		if (num != 1)
		{
			SnakeMove();
			CreateFood();
			DrawFood();
			SnakeEatFood();
		}
		SnakeDeath();
		if (_kbhit() && isGame == 1)
		{
			key = _getch();
			KeyBoard();
		}
	}
}
