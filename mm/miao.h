#pragma once
#include "Object.h"

class miao:public Object
{
public:
	miao(void);
	~miao(void);
	void setDes(int x, int y);
	void move();
	int getState();
	int getPreState();
	void setPreState(int pre);
	bool cc;
private:
	int fx,fy;
	int prestate;
	int state;
};
