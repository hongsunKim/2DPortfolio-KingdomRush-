#pragma once
#include "gameObject.h"

class stageBase;

enum class TOWER_CHANGE
{
	CURRENT,
	TOWER_SPOT,
	BARRACKS_TOWER,
	ARCHER_TOWER,
	MAGICIAN_TOWER,
	CANNON_TOWER
};

enum class TOWER_STATE
{
	READY,
	NORMAL,
	SHOW_SELECT
};

class towerBase : public gameObject
{
protected:
	
	stageBase* _belongedStage;
	int _stageGold;

	TOWER_STATE _towerState;
	TOWER_CHANGE _towerChange;

	image* _towerImage;
	animation _animation;
	RECT _buttonRect;

	image* _selectBoardImage;//셀렉트보드이미지는 그냥 이미지
	RECT _selectButtonRect[6];
	image* _selectButtonImage[6];//셀렉트버튼이미지는 프레임 이미지(기본, 온)
	animation _selectButtonAni[6];

	image* _rangeCircle;

	float _fullReadyTime;
	float _curReadyTime;
	image* _fullReadyTimeBar;
	animation _timeBarAni;
	image* _curReadyTimeBar;
	image* _readyTowerImage;

	int _atkMin;
	int _atkMax;

	int _buyPrice;
	int _sellPrice;

	bool _isLocked;

	bool _isCannonTower;

	image* _infoIcon;
	char _towerName[16];
	image* _atkTypeIcon;
	char _atkDamage[16];
	image* _speedIcon;
	char _atkSpeedChar[16];
	image* _atkRangeIcon;
	char _atkRangeChar[16];

public:
	inline void setBelongedStage(stageBase* stage) { _belongedStage = stage; }

	inline bool getIsLocked() { return _isLocked; }
	inline void setIsLocked(bool isLocked) { _isLocked = isLocked; }

	inline TOWER_STATE getTowerState() { return _towerState; }
	inline void setTwerState(TOWER_STATE towerState) { _towerState = towerState; }

	inline int getBuyPrice() { return _buyPrice; }
	inline int getSellPrice() { return _sellPrice; }

	inline void setSellPrice(int sellPrice) { _sellPrice = sellPrice; }
	inline void setBuyPrice(int buyPrice) { _buyPrice = buyPrice; }

	inline bool getIsCannonTower() { return _isCannonTower; }

	towerBase();
	~towerBase();

	TOWER_CHANGE getTowerChange() { return _towerChange; }
	void setTowerChangeDef() { _towerChange = TOWER_CHANGE::CURRENT; }

	HRESULT init(void);
	void release(void);
	void updateNormal(void);
	virtual void updateNormal1(void);
	void updateOnceUp(void);
	virtual void updateOnceUp1(void);
	void updateOnceDn(void);
	void updateStayDn(void);
	void renderObject(HDC getMemDC);
	void renderUI(HDC getMemDC);
	virtual void renderInfo(HDC getMemDC) = 0;

	virtual towerBase* copyTower(void) = 0;
	virtual void setPosition(float x, float y) = 0;
	
	//virtual void checkBuyable(int gold) = 0;
};

