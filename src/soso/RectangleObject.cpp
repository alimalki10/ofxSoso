/*
 *  RectangleObject.cpp
 *  HBOSnowApp
 *
 *  Created by Eric Gunther on 11/17/09.
 *  Copyright 2009 Sosolimited. All rights reserved.
 *
 */

#include "soso/RectangleObject.h"

using namespace cinder;
using namespace soso;

RectangleObject::RectangleObject(float iW, float iH)
{
	dimensions = vec2(iW, iH);
	isCentered = false;
	isFilled = true;

	strokeAlpha = 0.0;
	fillAlpha = 255.0;

}

RectangleObject::~RectangleObject(){

}

void RectangleObject::render()
{

	auto color = getColor();
	color.a = fillAlpha * drawMaterial->color.a;
	gl::color( color );
	// was:
	// gl::color( color.x, color.y, color.z, fillAlpha * drawMaterial->color.a/255.0 );

	if(isCentered)  {

		if (fillAlpha > 0.0) {
			gl::drawSolidRect( Rectf( -dimensions / 2.0f, dimensions / 2.0f ) );
		}

		if (strokeAlpha > 0.0) {
			gl::drawStrokedRect( Rectf( -dimensions / 2.0f, dimensions / 2.0f ) );
		}

	} else {

		if (fillAlpha > 0.0) {
			gl::drawSolidRect( Rectf( vec2(0), dimensions ) );
		}
		if (strokeAlpha > 0.0) {
			gl::drawStrokedRect( Rectf( vec2(0), dimensions ) );
		}

	}

}

void RectangleObject::setCentered(bool iB)
{
	isCentered = iB;
}

