#pragma once
#define NULL 0
#include "ShapeNode.h"

class ShapeNode
{
public:
	ShapeNode();
	ShapeNode( ShapeNode *data, ShapeNode *prev, ShapeNode *next);
	void setData(ShapeNode *data);
	ShapeNode* getData();
	void setPrev(ShapeNode *prev);
	void setNext(ShapeNode *next);
	ShapeNode* getPrev();
	ShapeNode* getNext();
	void update();
	void draw();
	ShapeNode(void);
	~ShapeNode(void);

private:
	ShapeNode *data_;
	ShapeNode *prev_, *next_;


};

