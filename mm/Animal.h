#pragma once
#include"miao.h"

class Animal:public miao
{
public:
	Animal();
	~Animal();
	void setDes();
	int cc;
	int cnow;
private:
	int v;
};

