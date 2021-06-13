#pragma once
#ifndef MAKE_H
#define MAKE_H
#undef UNICODE
#undef _UNICODE
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<math.h>
#include<string.h>
#include<easyx.h>
#include<graphics.h>//图形库头文件
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include"FOOD.h"
#include"SNAKE.h"
using namespace std;
class MAKE
{
protected:
	char KEY_UP = int(119);
	char KEY_DOWN = int(115);
	char KEY_LEFT = int(97);
	char KEY_RIGHT = int(100);
	char KEY_SPACE = int(32);//空格
	char KEY_PAUSE = int(81);
	char KEY_EXIT = int(69);
	const int MAX = 1000;  //蛇最大是1000节
	const int radius = 10;//蛇每节是个圆型，每个圆的半径为10
	char str[50];
	int ID;   //获取窗口句柄选择操作的整形数字
	int score[100] = { 0 };  //游戏中蛇的得分
	int sequence = 0;//分数的个数
	HWND hwnd;  //创建的图形界面的句柄
	char key;  //用来暂时存储玩家每次按下的键，以便于更新蛇的默认键，或者操作菜单界面
	int snakehead;//用来改变蛇头颜色
	int snakebody;//同上，针对蛇身
	int food1;//.....
	int flag_head = 0;//标识符，改变蛇头颜色后做进一步的判断
	int flag_body = 0;//同上，针对蛇身
	int flag_food = 0;
	int flag_barriers = 0;
	int SP = 100;  //蛇移动的速度
	int isGame;//判断是否进入了游戏界面，当进入游戏界面时这个值是1，在菜单界面值是0，进入游戏界面才可以进行暂停的操作
	int num;//按了几次空格键，一次就暂停游戏，二
	int barrier[740][1000] = { 0 };
	SNAKE snake;
	FOOD food;
public:
	MAKE() = default;
	void KeyBoard();
	void GameInit();
	void DrawMenu();
	void DrawColor();
	void Draw_choose_barriers();
	void Drawbarriers();
	void Check_the_record();
	void DrawMap();
	char* inttowchar(int xnum);
	void DrawData();
	void DrawSnake();
	void DrawFood();
	void CreateFood();
	void SnakeMove();
	void SnakeEatFood();
	void SnakeDeath();
	void GameOver();
	~MAKE() = default;
};
#endif // !MAKE_H#pragma once
