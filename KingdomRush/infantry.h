#pragma once
#include "playerUnitBase.h"

class infantry :
	public playerUnitBase
{
private:
	int _unitNum;

	float _elapsedTime;
	float _regenTime;
	float _regenSec;

	float _realAttackRange;

	float _prevDstX, _prevDstY;
	float _dstX, _dstY;

	bool _isRight;

public:
	inline float getRegen() { return _regenSec; }

	void setRegen(float regen);

	inline void setDstX(float dstX) { _dstX = dstX; }
	inline void setDstY(float dstY) { _dstY = dstY; }

	inline void setUnitNum(int unitNum) { _unitNum = unitNum; }

	inline int getUnitNum() { return _unitNum; }

	infantry();
	~infantry();

	HRESULT init(void);
	void release(void);
	void updateNormal(void);
	void updateOnceUp(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);

	playerUnitBase* copyUnit(void);

	void moveTo(float x, float y);
};

