#pragma once
#ifndef FOOD_H
#define FOOD_H
#include<iostream>
#include"COOR.h"
using namespace std;
class FOOD
{
public:
	COOR Fpos; //食物的坐标
	bool iseat=1; //游戏中食物是否被吃掉,默认是被吃，便于创建食物
	FOOD() = default;
	~FOOD() = default;
};
#endif // !FOOD_H
