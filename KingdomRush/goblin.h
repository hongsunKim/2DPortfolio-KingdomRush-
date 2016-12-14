#pragma once
#include "enemyUnitBase.h"
class goblin :
	public enemyUnitBase
{
public:
	goblin();
	~goblin();

	HRESULT init(void);
	void release(void);
	void updateNormal(void);
	void updateOnceUp(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);

	enemyUnitBase* copyUnit(void);
};

