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
#include<graphics.h>//ͼ�ο�ͷ�ļ�
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
	char KEY_SPACE = int(32);//�ո�
	char KEY_PAUSE = int(81);
	char KEY_EXIT = int(69);
	const int MAX = 1000;  //�������1000��
	const int radius = 10;//��ÿ���Ǹ�Բ�ͣ�ÿ��Բ�İ뾶Ϊ10
	char str[50];
	int ID;   //��ȡ���ھ��ѡ���������������
	int score[100] = { 0 };  //��Ϸ���ߵĵ÷�
	int sequence = 0;//�����ĸ���
	HWND hwnd;  //������ͼ�ν���ľ��
	char key;  //������ʱ�洢���ÿ�ΰ��µļ����Ա��ڸ����ߵ�Ĭ�ϼ������߲����˵�����
	int snakehead;//�����ı���ͷ��ɫ
	int snakebody;//ͬ�ϣ��������
	int food1;//.....
	int flag_head = 0;//��ʶ�����ı���ͷ��ɫ������һ�����ж�
	int flag_body = 0;//ͬ�ϣ��������
	int flag_food = 0;
	int flag_barriers = 0;
	int SP = 100;  //���ƶ����ٶ�
	int isGame;//�ж��Ƿ��������Ϸ���棬��������Ϸ����ʱ���ֵ��1���ڲ˵�����ֵ��0��������Ϸ����ſ��Խ�����ͣ�Ĳ���
	int num;//���˼��οո����һ�ξ���ͣ��Ϸ����
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
