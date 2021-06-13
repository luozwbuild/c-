#pragma once
#ifndef COOR_H
#define COOR_H
#include<iostream>
using namespace std;
class COOR
{
public:
	int x;
	int y;
	COOR() = default;
	COOR(int a, int b) :x(a), y(b) {}
	~COOR() = default; //析构函数，销毁类实例前调用
};
#endif // !COOR_h#pragma once
