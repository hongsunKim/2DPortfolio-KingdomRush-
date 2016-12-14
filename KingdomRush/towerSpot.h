#pragma once
#include "towerBase.h"
class towerSpot :
	public towerBase
{
public:
	towerSpot();
	~towerSpot();

	HRESULT init(void);
	void release(void);
	void updateNormal(void);
	void updateOnceUp(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);
	void renderInfo(HDC getMemDC);

	towerBase* copyTower(void);
	void setPosition(float x, float y);
};

