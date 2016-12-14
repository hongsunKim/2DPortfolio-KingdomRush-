#pragma once
#include "towerBase.h"
class magicianTower :
	public towerBase
{
public:
	magicianTower();
	~magicianTower();

	HRESULT init(void);
	void release(void);
	void updateNormal(void);
	void updateNormal1(void);
	void updateOnceUp(void);
	void updateOnceUp1(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);
	void renderInfo(HDC getMemDC);

	towerBase* copyTower(void);
	void setPosition(float x, float y);
};

