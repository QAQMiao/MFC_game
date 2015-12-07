#include "stdafx.h"
#include "Animal.h"


Animal::Animal()
{
	sx = rand() % 640;
	sy = rand() % 480;
	fx = rand() % 640;
	fy = rand() % 480;
	v = rand() % 10;
	cc = 0;
	cnow = 0;
	type = 3;
}

void Animal::setDes()
{
	fx = rand() % 640;
	fy = rand() % 480;
}

Animal::~Animal()
{
}
