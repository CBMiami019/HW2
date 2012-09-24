#pragma once
#include "Shapes.h"
#include "cinder\gl\gl.h"

using namespace ci;

class Circle
{
public:
	Circle(Vec2f center, float radius, Color8u color);
	void update();
	void draw();
	bool isInside(Vec2i mouse_pos);
	Circle(void);
	~Circle(void);

private:
	Vec2f center_;
	float radius_;
	Color8u color_;
};

