#pragma once
#ifndef SNAKE_H
#define SNKE_H
#include<iostream>
#include"COOR.h"
using namespace std;
class SNAKE
{
public:
	int node;  //�ߵĽ���
	struct COOR Spos[1000];  //��¼ÿ�ڵ�����
	char key;  //��ʱ�ߴ��ڵ��ƶ�����״̬
	SNAKE() = default;
	~SNAKE() = default;
};
#endif // !SNAKE_H#pragma once
