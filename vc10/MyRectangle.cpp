#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "MyRectangle.h"
#include "cinder/Rand.h";


using namespace ci;
using namespace ci::app;
using namespace std;

MyRectangle::MyRectangle(int depth, Vec2f position, Vec2f offset, float radius) {
	next_ = prev_ = this;
	children_ = NULL;

	offset_ = offset;
	position_ = position;
	radius_ = radius;

}

void insertAfter( MyRectangle* new_rect, MyRectangle* insert_here) {
		new_rect->next_ = insert_here->next_;
		new_rect->prev_ = insert_here;
		insert_here->next_->prev_ = new_rect;
		insert_here->next_ = new_rect;
}

void Square::update(vec2f parent_position, float parent_r) {
	Vec2f new_offset = offset_ + velocity_;

	float cur_distance = parent_position.distance(parent_position + offset_);
	float new_distance = parent_position.distance(parent_position + new_offset);
	if(new_distance > parent_r/2.0 && new_distance > cur_distance){
		new_offset = offset_;
	}

	offset_ = new_offset;
	position_ = parent_position + offset_;

	/*//TODO Add a bounds check here, so stuff doesn't drift away
	velocity_ = 0.95*velocity_ +0.05*randVec2f();
	velocity_.safeNormalize();*/

	MyRectangle* cur = children_;
	if(cur != NULL){
		do {
			cur->update(position_,radius_);
			cur = cur->next_;
		} while (cur->next_ != children_);
	}
}

void Square::draw(Vec2i mp) {
	gl::color(Color8u(255, 0, 255) );
	gl::drawSolidRect( Rectf( position_.x-radius_,position_.y-radius_,
		position_.x+radius_,position_.y+radius_));

	MyRectangle* cur = children_;
	if( cur != NULL ) {
		do {
			cur->draw(mp);
			cur = cur->next_;
		}while( cur->next_ != chilren_ );
	}
}

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

