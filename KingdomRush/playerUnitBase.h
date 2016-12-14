#pragma once
#include "unitBase.h"

class towerBase;

class playerUnitBase :
	public unitBase
{
protected:
	towerBase* _belongedTower;

	bool _isInfantry;
	bool _isMagician;


	bool _doubleAttack;

public:
	inline void setDoubleAttack(bool doubleAttack) { _doubleAttack = doubleAttack; }
	inline bool getDoubleAttack() { return _doubleAttack; }

	towerBase* getBelongedTower() { return _belongedTower; }
	bool getIsInfantry() { return _isInfantry; }
	bool getIsMagician() { return _isMagician; }

	void setBelongedTower(towerBase* belongedTower) { _belongedTower = belongedTower; }

	playerUnitBase();
	~playerUnitBase();

	HRESULT init(void);
	void release(void);
	void updateNormal(void);
	void updateOnceUp(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);

	virtual playerUnitBase* copyUnit(void) = 0;
};

