#pragma once
#include "gameObject.h"
class bulletBase :
	public gameObject
{
public:
	bulletBase();
	~bulletBase();

	HRESULT init(void) = 0;
	void release(void) = 0;
	void updateNormal(void) = 0;
	void updateOnceUp(void) = 0;
	void updateOnceDn(void) = 0;
	void updateStayDn(void) = 0;
	void renderObject(HDC getMemDC) = 0;
	void renderUI(HDC getMemDC) = 0;
};