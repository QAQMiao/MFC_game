#include "StdAfx.h"
#include "miao.h"

miao::miao(void)
{
	sx = 0;
	sy = 0;
	fy = 100;
	fx = 100;
	state = 1;
	prestate = 1;
	cc = true;
	type = 1;
}

miao::~miao(void)
{
}



void miao::setDes(int x, int y)
{
	fx = x;
	fy = y;
}

void miao::move()
{
	if (sx == fx && sy > fy)
		state = 5;
	if (sx < fx && sy >fy)
		state = 6;
	if (sx < fx && sy == fy)
		state = 7;
	if (sx < fx && sy < fy)
		state = 8;
	if (sx == fx && sy < fy)
		state = 1;
	if (sx > fx && sy < fy)
		state = 2;
	if (sx > fx && sy == fy)
		state = 3;
	if (sx > fx && sy > fy)
		state = 4;
	if (sx == fx && sy == fy)
		state = 0;
	if (fy < sy)
		sy = max(sy - 4, fy);
	else if (fy > sy)
		sy = min(sy + 4, fy);
	if (fx < sx)
		sx = max(sx - 4, fx);
	else if (fx > sx)
		sx = min(sx + 4, fx);
}
int miao::getState()
{
	return state;
}

int miao::getPreState()
{
	return prestate;
}

void miao::setPreState(int pre)
{
	prestate = pre;
}
