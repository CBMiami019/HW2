#pragma once
#include "cinder\gl\gl.h"
#include "Shapes.h"

using namespace ci;

class MyRectangle
{
public:
	MyRectangle(float x1, float y1, float x2, float y2, Color8u color);
	void update();
	void draw();
	bool isInside(Vec2i mouse_pos);

	MyRectangle(void);
	~MyRectangle(void);

private:
	float x1_, y1_, x2_, y2_;
	Color8u color_;
};

