#pragma once
#include "bulletBase.h"
class arrow :
	public bulletBase
{
private:
	//unitBase* _target;

	float _targetX, _targetY;

	float _lastX, _lastY;

	image _arrowImage;
	float _angle;
	float _speed;
	float _speedX;
	float _speedY;
	float _gravity;

	float _shotTime;

	bool _isArrived;
	float _lastingTime;
	bool _remove;
	bool _isDropping;

	float _aimFrame;

public:
	void setBelongedArcher(archer* belongedArcher);
	void setTarget(enemyUnitBase* target);

	inline bool getRemove(void) { return _remove; }
	inline bool getArrived(void) { return _isArrived; }

	arrow();
	~arrow();

	HRESULT init(void);
	HRESULT init(float x, float y, bool isRight, float targetX, float targetY);
	void release(void);
	void updateNormal(void);
	void updateOnceUp(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);

	float sum(float num);
};

