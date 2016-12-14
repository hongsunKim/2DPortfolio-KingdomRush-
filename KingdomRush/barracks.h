#pragma once
#include "towerBase.h"

enum class BARRACKS_STATE
{
	NORMAL,
	OPEN_DOOR,
};

class barracks :
	public towerBase
{
private:
	BARRACKS_STATE _barracksState;

	bool _pointDst;
	POINT _dst;

	image* _infantryInfoIcon;
	image* _hpIcon;
	char _hpChar[8];
	image* _armorIcon;
	image* _regenIcon;
	char _regenChar[8];
public:
	inline POINT getDst() { return _dst; }
	inline void setDst(POINT dst) { _dst = dst; }

	barracks();
	~barracks();

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

