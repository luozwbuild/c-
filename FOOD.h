#pragma once
#ifndef FOOD_H
#define FOOD_H
#include<iostream>
#include"COOR.h"
using namespace std;
class FOOD
{
public:
	COOR Fpos; //ʳ�������
	bool iseat=1; //��Ϸ��ʳ���Ƿ񱻳Ե�,Ĭ���Ǳ��ԣ����ڴ���ʳ��
	FOOD() = default;
	~FOOD() = default;
};
#endif // !FOOD_H
