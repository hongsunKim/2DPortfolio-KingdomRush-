#pragma once
#include "unitBase.h"

struct point
{
	int x, y;
	point(int inputX = 0, int inputY = 0)
	{
		x = inputX;
		y = inputY;
	}
};

typedef vector<point> vPOINT;
typedef vector<point>::iterator viPOINT;
typedef map<int, vPOINT> mPOINT;
typedef map<int, vPOINT>::iterator miPOINT;

class enemyUnitBase :
	public unitBase
{
protected:
	vector<point> _wayPoint;
	vector<point>::iterator _wayPointIter;

	int _wayNum;
	int _dstPoint;

	int _waveNum;

	image* _hpBar;
	image* _hp;

	bool _isRight;

	int _gold;

	bool _deadCheck;
	bool _arrivalCheck;

public:
	inline int getGold() { return _gold; }
	inline void setGold(int gold) { _gold = gold; }

	inline bool getDeadCheck() { return _deadCheck; }
	inline void setDeadCheck(bool deadCheck) { _deadCheck = deadCheck; }

	inline bool getArrivalCheck() { return _arrivalCheck; }
	inline void setArrivalCheck(bool arrivalCheck) { _arrivalCheck = arrivalCheck; }

	enemyUnitBase();
	~enemyUnitBase();

	HRESULT init(void);
	void release(void);
	void updateNormal(void);
	void updateOnceUp(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);

	virtual void moveTo(float x, float y);
	virtual enemyUnitBase* copyUnit(void) = 0;
	void setWayPoint(vPOINT wayPoint);
	int getWayNum() { return _wayNum; }
	inline int getWaveNum() { return _waveNum; }
	inline void setWaveNum(int waveNum) { _waveNum = waveNum; }
};

