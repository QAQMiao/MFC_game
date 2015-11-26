#include "stdafx.h"
#include "Object.h"


Object::Object()
{
	sx = 0;
	sy = 0;
}
void Object::setSize(int w, int h)
{
	width = w;
	height = h;
}
int Object::getW()
{
	return width;
}
int Object::getH()
{
	return height;
}

Object::~Object()
{
}

int Object::getX()
{
	return sx;
}
int Object::getY()
{
	return sy;
}