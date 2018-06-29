#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "rph/DisplayObjectContainer.h"

#include "Square.h"
#include "Circle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BasicSampleApp : public App {
  public:
	void setup();
	void mouseDown( MouseEvent event );
	void mouseUp(MouseEvent event);
	void mouseDrag(MouseEvent event);
	void update();
	void draw();
    
    rph::DisplayObjectContainer mContainer;
	void createShape(vec2 pos);
	bool mouseIsDown=false;
	vec2 mousePos;
};

void BasicSampleApp::setup()
{
    ci::gl::enableAlphaBlending();
}
void BasicSampleApp::mouseUp(MouseEvent event)
{
	mouseIsDown = false;
}
void BasicSampleApp::mouseDown( MouseEvent event )
{
	mouseIsDown = true;
	mousePos = event.getPos();
}
void BasicSampleApp::mouseDrag(MouseEvent event)
{
	mousePos = event.getPos();
}

void BasicSampleApp::update()
{
    mContainer.update();
	if (mouseIsDown) {
		for (int i = 0; i < 1; i++) {
			float range = 0;// 30.0f;
			createShape(mousePos + vec2(Rand::randFloat(-range, range), Rand::randFloat(-range, range)));
		}
	}
}
void BasicSampleApp::createShape(vec2 pos) {
	if (Rand::randFloat() > 0.5) {
		CircleRef c = Circle::create();
		c->setup();
		c->setRegPoint(rph::DisplayObject2D::RegistrationPoint::CENTERCENTER);
		c->setColor(Color(Rand::randFloat(), Rand::randFloat(), Rand::randFloat()));
		c->setScale(Rand::randInt(50, 100));
		c->setPos(pos);
		c->fadeOutAndDie();
		mContainer.addChild(c);
	}
	else {
		SquareRef s = Square::create();
		s->setup();
		s->setRegPoint(rph::DisplayObject2D::RegistrationPoint::CENTERCENTER);
		s->setColor(Color(Rand::randFloat(), Rand::randFloat(), Rand::randFloat()));
		s->setSize(Rand::randInt(50, 100), Rand::randInt(50, 100));
		s->setPos(pos);
		s->fadeOutAndDie();
		mContainer.addChild(s);
	}
}

void BasicSampleApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    mContainer.draw();
}

CINDER_APP( BasicSampleApp, RendererGl )
