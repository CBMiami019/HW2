#include "MyRectangle.h"

using namespace ci;

MyRectangle::MyRectangle(float x1, float y1, float x2, float y2, Color8u color)
{
	x1_ = x1;
	y1_ = y1;
	x2_ = x2;
	y2_ = y2;
	color_ = color;
}

bool MyRectangle::isInside(Vec2i mouse_pos) {
	return ((mouse_pos.x >= x1_) && (mouse_pos.x <= x2_)
		&& (mouse_pos.y >= y1_) && (mouse_pos.y <= y2_));
}

void MyRectangle::update() {

}

void MyRectangle::draw(){
	gl::color(color_);
	gl::drawSolidRect(Rectf(x1_, y1_, x2_, y2_));
}


MyRectangle::~MyRectangle(void)
{
}
