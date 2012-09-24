#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "MyRectangle.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "Resources.h"


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
	void mouseUp( MouseEvent event );
	void mouseMove( MouseEvent event );
	void mouseDrag( MouseEvent event );
	void keyDown( KeyEvent event );
	void update();
	void draw();
	
	Vec2i mMouseLoc;
	Vec2f mMouseVel;
	bool mouseClicked;
	bool drawImage;
	
private:

	MyRectangle* mRect_;

	Surface* mySurface_;
	gl::Texture *myTexture;
	static const int appWidth = 800; 
	static const int appHeight = 600;
	static const int size = 1024;
	static const Vec2f kUnitX;
	static const Vec2f kUnitY;
	int frame_num;

};

const Vec2f HW2App::kUnitX = Vec2f(0.7071f,-0.7071f);
const Vec2f HW2App::kUnitY = Vec2f(0.7071f,0.7071f);



void HW2App::prepareSettings(Settings* settings)
{
	settings->setWindowSize(appWidth, appHeight);
	settings->setResizable(false);
	settings->setFrameRate(60.0f);
}

/*
void HW2App::drawNode() {
	cur = sentinel->getNext();
	do {
		cur->getData()->draw();
		cur = cur->getNext();
	} while(cur != sentinel);

} */


void HW2App::setup()
{
	Vec2f trans = (appWidth/2.0f)*kUnitX + (appHeight/2.0f)*kUnitY;
	mRect_ = new MyRectangle(4, trans, Vec2f(0,0), 20.0f);

	frame_num = 0;

	mMouseLoc = Vec2i( 0, 0 );
	mMouseVel = Vec2f::zero();
	mouseClicked = false;
	drawImage = false;
}

void HW2App::mouseDown( MouseEvent event )
{
	mouseClicked = true;
}

void HW2App::mouseUp( MouseEvent event )
{
	mouseClicked = false;
}

void HW2App::mouseMove( MouseEvent event )
{
	mMouseVel = ( event.getPos() - mMouseLoc );
	mMouseLoc = event.getPos();
}

void HW2App::mouseDrag( MouseEvent event )
{
	mouseMove( event );
}

void HW2App::keyDown( KeyEvent event )
{
	if( event.getChar() == '?' ){
		drawImage = ! drawImage;
	}
}


void HW2App::update()
{
	MyRectangle* cur = mRect_; 
	Vec2f center = kUnitX*appWidth/2.0 + kUnitY*appHeight/2.0;

	if( cur != NULL ) {
		do{
		cur->update(center, appWidth/2.0);
		cur = cur->next_;
		}while( cur!= mRect_ );
	}
	frame_num++;
}

void HW2App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ), true ); 

	MyRectangle* cur = mRect_;
	if( cur != NULL ) {
		do {
			cur->draw(getMousePos());
			cur = cur->next_;
		}while( cur != mRect_ );
	}

}

CINDER_APP_BASIC( HW2App, RendererGl )
