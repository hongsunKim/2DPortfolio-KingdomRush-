#pragma once
#include "image.h"
#include "animation.h"

class gameObject
{
protected:
	float _x, _y;
	float _centerY;
	float _showY;

	image* _info;

public:
	inline float getX() { return _x; }
	inline float getY() { return _y; }
	inline float getCenterY() { return _centerY; }
	inline float getShowY() { return _showY; }

	inline void setX(float x) { _x = x; }
	inline void setY(float y) { _y = y; }
	inline void setCenterY(float centerY) { _centerY = centerY; }
	inline void setShowY(float showY) { _showY = showY; }

	gameObject();
	~gameObject();

	virtual HRESULT init(void) = 0;
	virtual void release(void) = 0;
	virtual void updateNormal(void) = 0;
	virtual void updateOnceUp(void) = 0;
	virtual void updateOnceDn(void) = 0;
	virtual void updateStayDn(void) = 0;
	virtual void renderObject(HDC getMemDC) = 0;
	virtual void renderUI(HDC getMemDC) = 0;
};

