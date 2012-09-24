#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "ShapeNode.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeNode.h";

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace ci::gl;

class HW2App : public AppBasic {
  public:

	void prepareSettings(Settings* settings);
	void drawNode();
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	

	Surface* mySurface_;
	gl::Texture *myTexture;
	static const int appWidth = 800; 
	static const int appHeight = 600;
	ShapeNode* sentinel;
	ShapeNode* cur;

};

void HW2App::prepareSettings(Settings* settings)
{
	settings->setWindowSize(appWidth, appHeight);
	settings->setResizable(false);
	settings->setFrameRate(60.0f);
}

void HW2App::drawNode() {
	cur = sentinel->getNext();
	do {
		cur->getData()->draw();
		cur = cur->getNext();
	} while(cur != sentinel);

}

void HW2App::setup()
{
	*mySurface_ = new Surface(appWidth, appHeight);
	sentinel = new ShapeNode();
}

void HW2App::mouseDown( MouseEvent event )
{
}

void HW2App::update()
{
}

void HW2App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
	gl::draw( myTexture, getWindowBounds() );

	ShapeNode* cur = cur->next_;
}

CINDER_APP_BASIC( HW2App, RendererGl )
