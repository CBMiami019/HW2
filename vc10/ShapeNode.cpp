#include "ShapeNode.h"


ShapeNode::ShapeNode(void)
{
	data_ = NULL;
	prev_ = NULL;
	next_ = NULL;
}

ShapeNode::ShapeNode(ShapeNode* data, ShapeNode *prev, ShapeNode *next) {
	data_ = data;
	prev_ = prev;
	next_ = next;
}


void ShapeNode::setData(ShapeNode *data) {
	data_ = data;
}

ShapeNode* ShapeNode::getData() {
	return this->data_;
}


void ShapeNode::setPrev(ShapeNode *prev) {
	this->prev_ = prev;
}

void ShapeNode::setNext(ShapeNode *next) {
	this->next_ = next;
}

ShapeNode* ShapeNode::getPrev() {
	return prev_;
}

ShapeNode* ShapeNode::getNext() {
	return next_;
}

void ShapeNode::update() {
	data_->update();
}

void ShapeNode::draw() {
	data_->draw();
}

ShapeNode::~ShapeNode(void)
{

}
