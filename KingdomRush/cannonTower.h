#pragma once
#include "towerBase.h"
#include "cannon.h"

class unitBase;

enum class CANNON_TOWER_STATE
{
	NORMAL,
	ATTACK
};

class cannonTower :
	public towerBase
{
private:
	int _atk;
	int _atkMin;
	int _atkMax;

	float _atkSpeed;

	float _atkRange;

	bool _shotCheck;

	CANNON_TOWER_STATE _cannonTowerState;

	unitBase* _target;

	vector<cannon*> _vCannon;
	vector<cannon*>::iterator _viCannon;

public:
	inline float getAtkRange() { return _atkRange; }
	inline unitBase* getTarget() { return _target; }
	vector<cannon*> getVCannon() { return _vCannon; }
	inline int getAtk() { return _atk; }

	inline void setTarget(unitBase* target) { _target = target; }
	inline void setAtkMin(int atkMin) { _atkMin = atkMin; }
	inline void setAtkMax(int atkMax) { _atkMax = atkMax; }
	inline void setAtkRange(float atkRange) { _atkRange = atkRange; }

	cannonTower();
	~cannonTower();

	HRESULT init(void);
	void release(void);
	void updateNormal(void);
	void updateNormal1(void);
	void updateOnceUp(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);
	void renderInfo(HDC getMemDC);

	towerBase* copyTower(void);
	void setPosition(float x, float y);
};

