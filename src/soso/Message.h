/*
Message

Class used by Object and Animation to animate Objects.

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

namespace soso
{

enum{
	OF_RELATIVE_VAL = 9999
};

enum{
	OF_TRANSLATE,
	OF_ROTATE,
	OF_SCALE,
	OF_SCALE3,
	OF_SETCOLOR,
	OF_SETALPHA,
	OF_SHOW,
	OF_HIDE,
    OF_FUNCTION //LM
};

enum{
	OF_LINEAR,
	OF_EASE_IN,
	OF_EASE_OUT,
	OF_EASE_INOUT
};

enum{
	OF_LINEAR_PATH,
	OF_BEZIER_PATH,
	OF_SPLINE_PATH
};

enum{
	OF_ONE_TIME_PLAY,
	OF_LOOP_PLAY,
	OF_LOOP_PALINDROME_PLAY
};

class Message
{
public:
	Message(int iID, void *iVals, int iInterpolation, float iDuration, float iDelay=0, int iPlayMode=OF_ONE_TIME_PLAY);
	Message(int iID, int iInterpolation, int iPath, std::vector<ci::vec4> iPathPoints, float iDuration, float iDelay=0, int iPlayMode=OF_ONE_TIME_PLAY);
	Message(int iID, float (*iFunction)(void *), void *iArgs, float iDelay, int iPlayMode=OF_ONE_TIME_PLAY); //LM

	~Message();

	float					getFinishTime();
	void					setStartTime(float iTime);
	static float			interpolateTime(int iInterp, float iTime);

	void					enableMessage(bool iEnable);
	void					setStartVals(float iX);
	void					setStartVals(float iX, float iY, float iZ);
	void					setStartVals(float iX, float iY, float iZ, float iW);

	void					setBaseStartVals(float iX);
	void					setBaseStartVals(float iX, float iY, float iZ);
	void					setBaseStartVals(float iX, float iY, float iZ, float iW);

	void					setEndVals(float iX);
	void					setEndVals(float iX, float iY, float iZ);
	void					setEndVals(float iX, float iY, float iZ, float iW);

	static ci::vec4			bezier(float iM, std::vector<ci::vec4> iPath);
	static ci::vec4			spline(float iM, std::vector<ci::vec4> iPath);



public:
	int						id;
	int						path;
	int						interpolation;
	int						playMode;
	bool					loopDirection;
	float					startTime,
							startDelay,
							duration;
	void					*endVals,
							*baseEndVals,
							*startVals,
							*baseStartVals;
    float                   (*functionPtr)(void *);
	bool					autoDelete;
	bool					isEnabled;
	bool					isRunning;

	std::vector<ci::vec4>		pathPoints;
};

}
