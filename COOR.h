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
	~COOR() = default; //����������������ʵ��ǰ����
};
#endif // !COOR_h#pragma once
