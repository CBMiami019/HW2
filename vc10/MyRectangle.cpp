#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "MyRectangle.h"
#include "cinder/Rand.h"


//Carter Beil doing the code review on this code


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

void MyRectangle::update(Vec2f parent_position, float parent_r) {
	Vec2f new_offset = offset_ + velocity_;

	float cur_distance = parent_position.distance(parent_position + offset_);
	float new_distance = parent_position.distance(parent_position + new_offset);
	if(new_distance > parent_r/2.0 && new_distance > cur_distance){
		new_offset = offset_;
	}

	offset_ = new_offset;
	position_ = parent_position + offset_;

	
	velocity_ = 0.95*velocity_ +0.05*randVec2f();
	velocity_.safeNormalize();

	MyRectangle* cur = children_;
	if(cur != NULL){
		do {
			cur->update(position_,radius_);
			cur = cur->next_;
		} while (cur->next_ != children_);
	}
}

void MyRectangle::addRandomChild(int depth){
	MyRectangle* new_item = new MyRectangle(depth,position_,Vec2f(0.0,0.0),0.45*radius_);

	if(children_ != NULL){
		insertAfter(new_item, children_);
	} else {
		children_ = new_item;
	}
}


/*
	As I run your program, all I get is a black screen. I have tried modifying your
	appWidth and appHeight as well as texture size, but nothing seems to fix the problem
	so I'll try to just fix the code as I see it in writing
*/

void MyRectangle::draw(Vec2i mp) {

	/*bool is_inside = isInside(mp.x, mp.y);

	if(is_inside){
		gl::color(Color8u(255,127,00));
	} else {
		gl::color(Color8u(255,0,0));
	}*/


	gl::color(Color8u(255, 255, 0 ) );
	gl::drawSolidRect( Rectf( position_.x-radius_,position_.y-radius_,
		position_.x+radius_,position_.y+radius_));

	MyRectangle* cur = children_;
	if( cur != NULL ) {
		do {
			cur->draw(mp);
			cur = cur->next_;
		}while( cur->next_ != children_ );
	}
}


