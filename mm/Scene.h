#pragma once
#include"Object.h"

class Scene :public Object
{
public:
	Scene();
	~Scene();
	void setX(int x);
	void setY(int y);
	void setIndex(int i);
	int getIndex();
	void changePo();
	bool operator < (Scene &w) const;
private:
	int index;
};

