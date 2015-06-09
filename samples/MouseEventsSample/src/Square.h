#pragma once

#include "poNodeContainer.h"
#include "poShape.h"

using namespace po::scene;

class Square;
typedef std::shared_ptr<Square> SquareRef;

class Square
: public po::scene::NodeContainer
{
public:
	static SquareRef create();
	virtual ~Square();

	virtual void setup();
	
	//	Show selected state
	void showSelected();

protected:
	Square();

private:
	//	Active state
	ShapeRef mActive;
	ci::Color mActiveColor;
	
	//	Selected state
	ShapeRef mSelected;
	ci::Color mSelectedColor;
	
};