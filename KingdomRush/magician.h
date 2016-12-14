#pragma once
#include "playerUnitBase.h"
#include "magicEnergy.h"

class magician :
	public playerUnitBase
{
private:
	vector<magicEnergy*> _vMagicEnergy;
	vector<magicEnergy*>::iterator _viMagicEnergy;

	bool _isUp;

	bool _slowSkill;

public:
	void setSlowSkill(bool slowSkill) { _slowSkill = slowSkill; }

	magician();
	~magician();

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

