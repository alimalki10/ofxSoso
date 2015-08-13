/*
PolygonObject

Object for creating and texturing arbitrary polygons. Also see DynamicPolygonObject for
an animatable version of Polygon.

Soso OpenFrameworks Addon
Copyright (C) 2012 Sosolimited

Permission is hereby granted, free of charge, to any person obtaining a copy of this software
and associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.
*/

#pragma once

#include "soso/Object.h"
#include "cinder/gl/Texture.h"

namespace soso
{

class PolygonObject : public Object
{
public:
	PolygonObject(int iNumVertices);
	~PolygonObject();

	void					render();

	void					setTexture(const ci::gl::TextureRef &iTex);
	virtual void			setVertexPos(int iVertexNum, ci::vec3 iPos);
	virtual void			setVertexTexCoords(int iVertexNum, float iU, float iV);
	virtual void			setVertexColor(int iVertexNum, float iR, float iG, float iB, float iA=255);

	ci::vec3					getVertexPos(int iVertexNum);
	ci::vec2					getVertexTexCoords(int iVertexNum);

	void					setDrawMode(int iDrawMode);	//OF_FILLED, OF_OUTLINE
	void					enableVertexColoring(bool iEnable);


	ci::gl::TextureRef				getTexture();

protected:
	int						numVertices;
	float					*vertices;
	float					*texCoords;
	float					*vertexColors;
	float					drawMode;
	ci::gl::TextureRef	texture;
	bool					vertexColoringEnabled;

};

} // namespace soso
