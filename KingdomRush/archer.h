#pragma once
#include "playerUnitBase.h"

class arrow;

class archer :
	public playerUnitBase
{
private:
	bool _isRight;
	bool _isUp;

	vector<arrow*> _vArrow;
	vector<arrow*>::iterator _viArrow;

public:

	inline bool getIsRight(void) { return _isRight; }

	archer();
	~archer();

	HRESULT init(void);
	void release(void);
	void updateNormal(void);
	void updateOnceUp(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);

	playerUnitBase* copyUnit(void);
};

