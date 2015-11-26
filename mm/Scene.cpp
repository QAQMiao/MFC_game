#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
	sx = rand() % 640;
	sy = rand() % 480;
	index = 0;
}

Scene::~Scene()
{

}

void Scene::setX(int x)
{
	sx = x;
}
void Scene::setY(int y)
{
	sy = y;
}
void Scene::setIndex(int i)
{
	index = i;
}
int Scene::getIndex()
{
	return index;
}
void Scene::changePo()
{
	sx = rand() % 640;
	sy = rand() % 480;
}
bool Scene::operator < (Scene& w) const {
	return (sy + height) < (w.getY() + w.getH());
}