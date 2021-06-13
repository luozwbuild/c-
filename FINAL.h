#pragma once
#ifndef  FINAL_H
#define FINAL_H
#include<iostream>
#include"MAKE.h"
using namespace std;
class FINAL :public MAKE
{
public:
	FINAL() = default;
	void show();
	~FINAL() = default;
};
#endif // ! FINAL_H


