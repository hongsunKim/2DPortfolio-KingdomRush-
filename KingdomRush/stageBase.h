#pragma once
#include "gameNode.h"
enum class STAGEPAGE
{
	OPEN,
	CLOSE_FOR_MENU,
	CLOSE_FOR_RESTART,
	SET_OPTIONS,
	OPTIONS,
	FOLD_OPTIONS,
	SET_DEFEAT,
	DEFEAT,
	CLOSE_FOR_RETRY,
	GIVE_UP,
	SET_VICTORY,
	VICTORY,
	VICTORY_RESTART,
	VICTORY_CONTINUE,
	PLAY,
	PAUSE
};

class stageBase :
	public gameNode
{
protected:
	STAGEPAGE _stagePage;

	int _currentStageNum;

	image* _pauseScreen;
	image* _pauseButtonImage;
	RECT _pauseButtonRect;
	image* _pauseBoard;

	image* _optionButtonImage;
	RECT _optionButtonRect;
	image* _optionBoard;
	int _optionBoardY;

	image* _resumeButtonImage;
	RECT _resumeButtonRect;

	image* _quitButtonImage;
	RECT _quitButtonRect;

	image* _restartButtonImage;
	RECT _restartButtonRect;

	image* _defeatBoard;
	int _defeatBoardY;

	image* _tryAgainButtonImage;
	RECT _tryAgainButtonRect;

	image* _giveUpButtonImage;
	RECT _giveUpButtonRect;

	image* _victoryImage;
	int _victoryFrame;
	int _frameCount;

	image* _victoryStarImage;
	animation _victoryStarAni;
	int _star;
	bool _stopStar;

	image* _leftFlowerPowderImage;
	image* _rightFlowerPowderImage;
	int _flowerPowderFrame;
	int _flowerPowderFrameCount;

	image* _continueButtonImage;
	int _continueButtonY;
	RECT _continueButtonRect;
	image* _reStartButtonImage;
	int _reStartButtonY;
	RECT _reStartButtonRect;

	image* _stageInfo;

	image* _stageMap;
	image* _underBar;
	image* _information;
	image* _waveButtonBoard;

	image* _waveButton;
	RECT _waveButtonRect;

	int _gold;
	char _goldText[8];
	int _waveCountMax;
	int _waveCountCur;
	int _currentLife;
	int _fullLife;
	char _lifeText[8];

	bool _waveStart;
	bool _waveButtonAvailable;

	float _waveCountTime;
	int _waveCurrentTime;
	int _waveTime;

	int _fullWaveNum;
	int _currentWaveNum;
	char _waveNumText[16];

	mPOINT _enemyWayPoint;
	miPOINT _enemyWayPointIter;


	//ø©¥›¿ÃπÆ
	image* _leftDoorImage;
	image* _rightDoorImage;
	int _leftDoorPos;
	int _rightDoorPos;

	bool _victory;

	bool _firstTouch;

	towerBase* _selectedTower;

	vector<towerBase*> _vTower;
	vector<towerBase*>::iterator _viTower;

	vector<enemyUnitBase*> _vEnemyUnit;
	vector<enemyUnitBase*>::iterator _viEnemyUnit;

	vector<playerUnitBase*> _vPlayerUnit;
	vector<playerUnitBase*>::iterator _viPlayerUnit;

	vector<gameObject*> _vStageObject;
	vector<gameObject*>::iterator _viStageObject;

public:
	inline void setSelectedTower(towerBase* selectedTower) { _selectedTower = selectedTower; }
	inline towerBase* getSelectedTower() { return _selectedTower; }

	inline int getCurrentStageNum() { return _currentStageNum; }

	inline int getStarNum() { return _star; }

	inline int getGold() { return _gold; }

	stageBase();
	~stageBase();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	virtual void deleteAll(void);
	virtual void checkTarget(void);
	virtual void towerChange(void);
	virtual void updateNormal(void);
	virtual void updateOnceKeyDown(void);
	virtual void updateOnceKeyUp(void);
	virtual void updateStayKeyDown(void);
	virtual void setStageObject(void);
	virtual void renderObject(void);
	virtual void generateWave(void);
	virtual void waveCount(void);
};

