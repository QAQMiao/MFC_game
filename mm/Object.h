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
	int getType();
	int getH();
	int getIndex();
	void setIndex(int i);
	bool operator < (Object &w) const;
	int now;
protected:
	int sx, sy;
	int type;
	int width, height;
	int index;
};

