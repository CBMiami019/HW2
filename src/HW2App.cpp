#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "MyRectangle.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "Resources.h"

//Carter Beil doing the code review on this code


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

/*First off, I just want to say that your code is hard to review because you haven't commented any 
	of your methods. It has taken me a long time just to figure out what your methods do and 
	how they are related to one another. Consider in the future adding more comments so that anyone
	who is reviewing your code knows what is going on.
*/


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

/* 
	I ran a CRTL+F and searched for "Clicked" to find all the times that mouseClicked is used, and I
	am still unable to figure out why you have this method in here.

	To my knowledge, mouseDown simply changed the bool value from false to true and serves
	no other purpose in this program
*/
void HW2App::mouseDown( MouseEvent event )
{
	mouseClicked = true;
}

/*
	Same thing with this mouseUp method -- I see the variable mouseClicked in your code, but I do not 
	know why it is here.

	It is used neither in HW2APP.cpp or MyRectangle.cpp more than these two methods.
*/

void HW2App::mouseUp( MouseEvent event )
{
	mouseClicked = false;
}


/*
	Also having the same problem with mMouseVel and mMouseLoc. I can see that you're changing the value
	of each of them, but you don't use them at all.
*/
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

	/*
		All I'm seeing when I run your program is the black of your gl:clear(Color(0,0,0),true); and 
		even when I clear that out, the screen is still just black. I don't know why your program
		isn't working on my computer.
	*/

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
