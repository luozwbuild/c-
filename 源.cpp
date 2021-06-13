#include<iostream>
#include"FINAL.h"
using namespace std;
int main()
{
	FINAL* p;
	p=new FINAL;
	p->show();
	delete p;
	return 0;
}