#pragma once
#include "bulletBase.h"
class cannon :
	public bulletBase
{
private:
	//unitBase* _target;

	float _targetX, _targetY;

	float _lastX, _lastY;

	image* _cannonImage;
	image* _explode;
	animation _explodeAni;
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
	bool _dmgCheck;

	float _aimFrame;

	float _explosionRange;

public:

	inline bool getRemove(void) { return _remove; }
	inline bool getArrived(void) { return _isArrived; }
	inline float getExplosionRange(void) { return _explosionRange; }
	inline bool getDamageCheck(void) { return _dmgCheck; }

	inline void setDamageCheck(bool dmgCheck) { _dmgCheck = dmgCheck; }

	cannon();
	~cannon();

	HRESULT init(void);
	HRESULT init(float x, float y, float targetX, float targetY);
	void release(void);
	void updateNormal(void);
	void updateOnceUp(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);

	float sum(float num);
};

