#pragma once
#ifndef SNAKE_H
#define SNKE_H
#include<iostream>
#include"COOR.h"
using namespace std;
class SNAKE
{
public:
	int node;  //蛇的节数
	struct COOR Spos[1000];  //记录每节的坐标
	char key;  //此时蛇处于的移动按键状态
	SNAKE() = default;
	~SNAKE() = default;
};
#endif // !SNAKE_H#pragma once
