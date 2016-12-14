#pragma once
#include "bulletBase.h"
class magicEnergy :
	public bulletBase
{
private:
	unitBase* _target;

	float _targetX, _targetY;

	float _lastX, _lastY;

	image* _magicEnergyImage;
	float _angle;
	float _speed;
	int _atk;

	bool _isArrived;
	float _lastingTime;
	bool _remove;

public:
	inline bool getArrived(void) { return _isArrived; }

	magicEnergy();
	~magicEnergy();

	HRESULT init(void);
	HRESULT init(float x, float y, bool isUp, unitBase* target, int atk);
	void release(void);
	void updateNormal(void);
	void updateOnceUp(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);

	void attackTarget(void);
};

