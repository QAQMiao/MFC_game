#pragma once
class Object
{
public:
	Object();
	~Object();
	int getX();
	int getY();
	void setSize(int w, int h);
	int getW();
	int getH();
protected:
	int sx, sy;
	int width, height;
};

