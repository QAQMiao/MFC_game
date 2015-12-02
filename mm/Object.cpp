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
int Object::getIndex()
{
	return index;
}

void Object::setIndex(int i)
{
	index = i;
}
int Object::getType()
{
	return type;
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
bool Object::operator < (Object& w) const {
	return (sy + height) < (w.getY() + w.getH());
}
