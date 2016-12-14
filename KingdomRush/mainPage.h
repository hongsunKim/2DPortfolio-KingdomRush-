#pragma once
#include "gameNode.h"

enum class MAINPAGE
{
	OPEN,
	PLAY,
	SET_ICONS,
	SET_UPGRADE,
	UPGRADE,
	FOLD_UPGRADE,
	SET_ENCYCLOPEDIA,
	ENCYCLOPEDIA,
	FOLD_ENCYCLOPEDIA,
	SET_STAGEINFO,
	STAGEINFO,
	FOLD_STAGEINFO,
	CLOSE_FOR_MENU,
	CLOSE_FOR_STAGE
};

enum class UPGRADE_STATE
{
	LOCKED,
	PURCHABLE_BASE,
	PURCHABLE_ON,
	ACTIVATED
};

enum class STAGE_STATE
{
	LOCKED,
	CURRENT_STAGE_BASE,
	CURRENT_STAGE_ON,
	COMPLETED_STAGE_BASE,
	COMPLETED_STAGE_ON
};

struct UPGRADE_INFO
{
	int id;
	UPGRADE_STATE upgradeState;
	int price;
	image* buttonImage;
	image* description;
	RECT buttonRect;
};

struct STAGE_INFO
{
	int stageNum;
	STAGE_STATE stageState;
	int starPoint;
	image* buttonImage;
	image* starImage;
	//animation buttonAni;
	RECT buttonRect;
};

class mainPage :
	public gameNode
{
private:
	MAINPAGE _mainPage;

	image* _mainPageImage;

	//vector<int> _vStar;
	//vector<int>::iterator _viStar;

	//�ʻ� ǥ�õǴ� ����
	int _star;
	image* _starBoard;
	char _starChar[8];
	int _purchableStar;
	char _purchableStarChar[4];

	int _currentStageNum;
	//�迭�̳� ���ͷ� ǥ�� �� ���׷��̵� ǥ;
	//�迭�̳� ���ͷ� ǥ�� �� �������� ȹ�� ��/ �ϼ� ���� ����;
	//���� ������������ �� �� �����ΰ�
	int _slotNum;

	int _openStageNum;

	//��������(���� ���� �ø��� �ȴ�~)
	STAGE_INFO _stage[8];

	/*vector<int> _vStageStar;
	vector<int>::iterator _viStageStar;*/

	//�޴��� ���ư��� ��ư
	image* _menuButtonImage;
	RECT _menuButtonRect;

	//���׷��̵� ��ư
	image* _upgradeButtonImage;
	RECT _upgradeButtonRect;

	//���׷��̵� �� ������ ����
	image* _upgradeBoardImage;
	UPGRADE_INFO _upgrade[30];
	int _upgradeBoardPos;
	image* _doneButtonImage;
	RECT _doneButtonRect;
	image* _resetButtonImage;
	RECT _resetButtonRect;
	char _upgradeDirectory[128];
	char _upgradeName[128];

	//�����̹�
	image* _leftDoorImage;
	image* _rightDoorImage;
	int _leftDoorPos;
	int _rightDoorPos;

public:
	void setStageInfo(int stageNum, int starNum);
	int getStageStar(int stageNum);

	inline int getStar() { return _star; }

	inline int getSlotNum() { return _slotNum; }
	inline STAGE_INFO* getStageInfo() { return _stage; }
	inline UPGRADE_INFO* getUpgradeInfo() { return _upgrade; }

	inline void setSlotNum(int slotNum) { _slotNum = slotNum; }
	void setStageInfo(STAGE_INFO stage[8]);
	void setUpgradeInfo(UPGRADE_INFO upgrade[30]);

	void setFlag();

	void sumStar();

	mainPage();
	~mainPage();

	HRESULT init(void);
	HRESULT init(int slotNum);
	HRESULT init(int slotNum, vector<int> vStageInfo);
	HRESULT init(int slotNum, STAGE_INFO stage[8], UPGRADE_INFO upgrade[30]);
	void release(void);
	void update(void);
	void render(void);
};