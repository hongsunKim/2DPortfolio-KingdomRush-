#pragma once
#include "enemyUnitBase.h"
class wlilf :
	public enemyUnitBase
{
public:
	wlilf();
	~wlilf();

	HRESULT init(void);
	void release(void);
	void updateNormal(void);
	void updateOnceUp(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);

	enemyUnitBase* copyUnit(void);

	void moveTo(float x, float y);
};

