class MyRectangle{
public:
	MyRectangle(int depth, ci::Vec2f position, ci::Vec2f offset, float radius);

	//Pointers to my siblings
	MyRectangle* next_;
	MyRectangle* prev_;

	//Pointer to the sentinel for my list of children.
	MyRectangle* children_;

	ci::Vec2f offset_; //From parent position
	ci::Vec2f position_; //position_ == parent's position + offset_
	float radius_;

	ci::Vec2f velocity_;

	//Return true of the (x,y) provided is inside the diamond
	bool isInside(float x, float y);
	void draw(ci::Vec2i mouse_pos);
	void update(ci::Vec2f parent_position, float parent_r);

	void addRandomChild(int depth);
};

void insertAfter(MyRectangle* new_item, MyRectangle* insert_here);