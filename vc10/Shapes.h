#ifndef SHAPES_H
#define SHAPES_H

#include "cinder\gl\gl.h"

class Shapes {

public:
	virtual void update();
	virtual void draw();
	virtual bool isInside(ci::Vec2i mouse_pos);

};

#endif