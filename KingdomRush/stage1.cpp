#include "stdafx.h"
#include "stage1.h"

stage1::stage1()
{
}

stage1::~stage1()
{
}

HRESULT stage1::init(void)
{
	_currentStageNum = 1;

	_stageMap = IMAGEMANAGER->addImage("스테이지1맵", "image/스테이지/스테이지1.bmp", 700, 600, FALSE, RGB(1, 0, 0));

	//타워세팅
	//플레이어세팅
	_vTower.push_back(TOWERMANAGER->copyTower("타워스폿", 240, 200));
	_vTower.push_back(TOWERMANAGER->copyTower("타워스폿", 170, 230));
	_vTower.push_back(TOWERMANAGER->copyTower("타워스폿", 250, 325));
	_vTower.push_back(TOWERMANAGER->copyTower("타워스폿", 245, 380));
	_vTower.push_back(TOWERMANAGER->copyTower("타워스폿", 320, 381));
	_vTower.push_back(TOWERMANAGER->copyTower("타워스폿", 380, 478));
	_vTower.push_back(TOWERMANAGER->copyTower("타워스폿", 465, 395));
	_vTower.push_back(TOWERMANAGER->copyTower("타워스폿", 585, 455));

	//에너미세팅
	//_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("릴프", 1));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 1));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 1));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 1));

	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 2));

	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("오크", 3));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("오크", 3));

	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 4));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 4));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 4));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("오크", 4));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("오크", 4));

	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("오크", 5));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("오크", 5));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("오크", 5));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("오크", 5));

	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("오크", 6));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("오크", 6));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("오크", 6));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 6));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 6));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 6));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 6));

	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("고블린", 7));

	vPOINT wayPoint;
	wayPoint.push_back(point(325, -20));
	wayPoint.push_back(point(325, 0));
	wayPoint.push_back(point(330, 167));
	wayPoint.push_back(point(302, 224));
	wayPoint.push_back(point(219, 257));
	wayPoint.push_back(point(179, 277));
	wayPoint.push_back(point(166, 325));
	wayPoint.push_back(point(168, 364));
	wayPoint.push_back(point(181, 389));
	wayPoint.push_back(point(205, 412));
	wayPoint.push_back(point(276, 419));
	wayPoint.push_back(point(333, 419));
	wayPoint.push_back(point(382, 407));
	wayPoint.push_back(point(485, 434));
	wayPoint.push_back(point(572, 363));
	wayPoint.push_back(point(690, 346));
	wayPoint.push_back(point(710, 346));

	vPOINT wayPoint1;
	wayPoint1.push_back(point(325 + 20, -20));
	wayPoint1.push_back(point(325 + 20, 0));
	wayPoint1.push_back(point(330 + 20, 167));
	wayPoint1.push_back(point(302 + 15, 224 + 15));
	wayPoint1.push_back(point(219 + 20, 257 + 15));
	wayPoint1.push_back(point(179 + 20, 277 + 10));
	wayPoint1.push_back(point(166 + 20, 325));
	wayPoint1.push_back(point(168 + 20, 364));
	wayPoint1.push_back(point(181 + 10, 389 - 10));
	wayPoint1.push_back(point(205, 412 - 15));
	wayPoint1.push_back(point(276, 419 - 15));
	wayPoint1.push_back(point(333, 419 - 15));
	wayPoint1.push_back(point(382, 407 - 15));
	wayPoint1.push_back(point(485, 434 - 15));
	wayPoint1.push_back(point(572, 363 - 15));
	wayPoint1.push_back(point(690, 346 - 15));
	wayPoint1.push_back(point(710, 346 - 10));

	vPOINT wayPoint2;
	wayPoint2.push_back(point(325 - 20, -20));
	wayPoint2.push_back(point(325 - 20, 0));
	wayPoint2.push_back(point(330 - 20, 167));
	wayPoint2.push_back(point(302 - 20, 224 - 15));
	wayPoint2.push_back(point(219 - 20, 257 - 15));
	wayPoint2.push_back(point(179 - 20, 277 - 10));
	wayPoint2.push_back(point(166 - 20, 325));
	wayPoint2.push_back(point(168 - 20, 364));
	wayPoint2.push_back(point(181 - 10, 389 + 10));
	wayPoint2.push_back(point(205, 412 + 15));
	wayPoint2.push_back(point(276, 419 + 15));
	wayPoint2.push_back(point(333, 419 + 15));
	wayPoint2.push_back(point(382, 407 + 15));
	wayPoint2.push_back(point(485, 434 + 15));
	wayPoint2.push_back(point(572, 363 + 15));
	wayPoint2.push_back(point(690, 346 + 15));
	wayPoint2.push_back(point(710, 346 + 10));

	_enemyWayPoint.insert(make_pair(0, wayPoint));
	_enemyWayPoint.insert(make_pair(1, wayPoint1));
	_enemyWayPoint.insert(make_pair(2, wayPoint2));

	for (int i = 0; i < _vEnemyUnit.size(); i++)
	{
		_enemyWayPointIter = _enemyWayPoint.find((_vEnemyUnit[i]->getWayNum()) / 4);
		_vEnemyUnit[i]->setWayPoint(_enemyWayPointIter->second);
		_vEnemyUnit[i]->setUnitState(UNIT_STATE::READY);
	}

	_waveCountTime = 0;
	_waveCurrentTime = 0;

	_fullWaveNum = 7;
	_currentWaveNum = 0;

	_gold = 265;

	stageBase::init();

	return S_OK;
}
void stage1::release(void)
{
	stageBase::release();
}
void stage1::update(void)
{
	stageBase::update();
	switch (_stagePage)
	{
	case STAGEPAGE::VICTORY_CONTINUE:
		if (_leftDoorPos > -110 && _rightDoorPos < 340)
		{
			_leftDoorPos = -110;
			_rightDoorPos = 340;

			//저장하면서 나가줘야 할거시다~~~
			//어떤 저장소로 나가는가를 알려면
			//멤버 변수로 현재 슬롯 번호를 가지고 있어야 할 것 같다.
			//괜찮겠지...???.....
			/////////////////////////////////////////////////////////////////////
			SCENEMANAGER->continueMainPage();
		}
		break;
	case STAGEPAGE::VICTORY_RESTART:
	case STAGEPAGE::CLOSE_FOR_RETRY:
	case STAGEPAGE::CLOSE_FOR_RESTART:
		if (_leftDoorPos > -110 && _rightDoorPos < 340)
		{
			_leftDoorPos = -110;
			_rightDoorPos = 340;

			//저장하면서 나가줘야 할거시다~~~
			//어떤 저장소로 나가는가를 알려면
			//멤버 변수로 현재 슬롯 번호를 가지고 있어야 할 것 같다.
			//괜찮겠지...???.....
			/////////////////////////////////////////////////////////////////////
			SCENEMANAGER->changeScene("크레딧화면");
			SCENEMANAGER->changeScene("스테이지1");
		}
		break;
	}
}
void stage1::render(void)
{
	stageBase::render();
}