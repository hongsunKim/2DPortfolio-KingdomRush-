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

	_stageMap = IMAGEMANAGER->addImage("��������1��", "image/��������/��������1.bmp", 700, 600, FALSE, RGB(1, 0, 0));

	//Ÿ������
	//�÷��̾��
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 240, 200));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 170, 230));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 250, 325));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 245, 380));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 320, 381));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 380, 478));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 465, 395));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 585, 455));

	//���ʹ̼���
	//_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("����", 1));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 1));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 1));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 1));

	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 2));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 2));

	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("��ũ", 3));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("��ũ", 3));

	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 4));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 4));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 4));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("��ũ", 4));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("��ũ", 4));

	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("��ũ", 5));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("��ũ", 5));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("��ũ", 5));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("��ũ", 5));

	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("��ũ", 6));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("��ũ", 6));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("��ũ", 6));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 6));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 6));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 6));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 6));

	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));
	_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 7));

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

			//�����ϸ鼭 ������� �ҰŽô�~~~
			//� ����ҷ� �����°��� �˷���
			//��� ������ ���� ���� ��ȣ�� ������ �־�� �� �� ����.
			//��������...???.....
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

			//�����ϸ鼭 ������� �ҰŽô�~~~
			//� ����ҷ� �����°��� �˷���
			//��� ������ ���� ���� ��ȣ�� ������ �־�� �� �� ����.
			//��������...???.....
			/////////////////////////////////////////////////////////////////////
			SCENEMANAGER->changeScene("ũ����ȭ��");
			SCENEMANAGER->changeScene("��������1");
		}
		break;
	}
}
void stage1::render(void)
{
	stageBase::render();
}