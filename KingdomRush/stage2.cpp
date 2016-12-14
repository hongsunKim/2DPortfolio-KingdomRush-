#include "stdafx.h"
#include "stage2.h"


stage2::stage2()
{
}


stage2::~stage2()
{
}

HRESULT stage2::init(void)
{
	_currentStageNum = 2;

	_stageMap = IMAGEMANAGER->addImage("��������2��", "image/��������/��������2.bmp", 700, 600, FALSE, RGB(1, 0, 0));

	//Ÿ������
	//�÷��̾��
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 436, 155));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 436, 210));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 295, 177));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 242, 286));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 385, 381));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 302, 398));
	_vTower.push_back(TOWERMANAGER->copyTower("Ÿ������", 383, 495));

	//���ʹ̼���
	for (int i = 0; i < 14; i++)
	{
		_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 1));
	}
	for (int i = 0; i < 24; i++)
	{
		_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 2));
	}
	for (int i = 0; i < 4; i++)
	{
		_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("��ũ", 3));
	}
	for (int i = 0; i < 12; i++)
	{
		_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("���", 3));
	}

	for (int i = 0; i < 8; i++)
	{
		_vEnemyUnit.push_back(ENEMYUNITMANAGER->copyUnit("����", 4));
	}


	vPOINT wayPoint;
	wayPoint.push_back(point(730, 215));
	wayPoint.push_back(point(550, 212));
	wayPoint.push_back(point(523, 205));
	wayPoint.push_back(point(520, 194));
	wayPoint.push_back(point(484, 102));
	wayPoint.push_back(point(433, 90));
	wayPoint.push_back(point(377, 127));
	wayPoint.push_back(point(368, 183));
	wayPoint.push_back(point(350, 207));
	wayPoint.push_back(point(309, 214));
	wayPoint.push_back(point(232, 215));
	wayPoint.push_back(point(187, 235));
	wayPoint.push_back(point(171, 278));
	wayPoint.push_back(point(193, 315));
	wayPoint.push_back(point(256, 339));
	wayPoint.push_back(point(387, 316));
	wayPoint.push_back(point(450, 344));
	wayPoint.push_back(point(456, 382));
	wayPoint.push_back(point(439, 415));
	wayPoint.push_back(point(405, 429));
	wayPoint.push_back(point(363, 432));
	wayPoint.push_back(point(317, 461));
	wayPoint.push_back(point(311, 600));

	vPOINT wayPoint1;
	wayPoint1.push_back(point(730, 235));
	wayPoint1.push_back(point(514, 229));
	wayPoint1.push_back(point(496, 201));
	wayPoint1.push_back(point(480, 127));
	wayPoint1.push_back(point(438, 111));
	wayPoint1.push_back(point(392, 127));
	wayPoint1.push_back(point(385, 183));
	wayPoint1.push_back(point(372, 219));
	wayPoint1.push_back(point(323, 235));
	wayPoint1.push_back(point(225, 235));
	wayPoint1.push_back(point(195, 257));
	wayPoint1.push_back(point(186, 295));
	wayPoint1.push_back(point(235, 323));
	wayPoint1.push_back(point(297, 317));
	wayPoint1.push_back(point(387, 299));
	wayPoint1.push_back(point(450, 321));
	wayPoint1.push_back(point(480, 370));
	wayPoint1.push_back(point(470, 406));
	wayPoint1.push_back(point(426, 447));
	wayPoint1.push_back(point(350, 455));
	wayPoint1.push_back(point(330, 486));
	wayPoint1.push_back(point(330, 600));

	vPOINT wayPoint2;
	wayPoint2.push_back(point(730, 195));
	wayPoint2.push_back(point(568, 198));
	wayPoint2.push_back(point(533, 189));
	wayPoint2.push_back(point(499, 95));
	wayPoint2.push_back(point(437, 72));
	wayPoint2.push_back(point(381, 88));
	wayPoint2.push_back(point(361, 123));
	wayPoint2.push_back(point(353, 180));
	wayPoint2.push_back(point(317, 204));
	wayPoint2.push_back(point(226, 203));
	wayPoint2.push_back(point(168, 232));
	wayPoint2.push_back(point(151, 280));
	wayPoint2.push_back(point(171, 324));
	wayPoint2.push_back(point(253, 357));
	wayPoint2.push_back(point(394, 333));
	wayPoint2.push_back(point(442, 359));
	wayPoint2.push_back(point(437, 390));
	wayPoint2.push_back(point(409, 412));
	wayPoint2.push_back(point(358, 418));
	wayPoint2.push_back(point(322, 432));
	wayPoint2.push_back(point(294, 456));
	wayPoint2.push_back(point(292, 600));


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

	_fullWaveNum = 4;
	_currentWaveNum = 0;

	_gold = 220;

	stageBase::init();

	return S_OK;
}
void stage2::release(void)
{
	stageBase::release();
}
void stage2::update(void)
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
			SCENEMANAGER->changeScene("��������2");
		}
		break;
	}
}
void stage2::render(void)
{
	stageBase::render();
}