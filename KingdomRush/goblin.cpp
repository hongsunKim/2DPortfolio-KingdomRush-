#include "stdafx.h"
#include "goblin.h"


goblin::goblin()
{
}


goblin::~goblin()
{
}

HRESULT goblin::init(void)
{
	enemyUnitBase::init();
	_atkType = ATK_TYPE::PHYSICAL;
	_armor = ARMOR::NONE;
	_magicResistence = MAGIC_RESISTENCE::NONE;
	_speed = 0.5;//미디엄 보다 느림
	_normalSpeed = 0.5;
	_slowedSpeed = 0.25;
	_type = TYPE::GROUND;

	_atk = 1;//1~4
	_atkMin = 1;
	_atkMax = 4;
	
	_atkRange = 20;
	_fullHp = _currentHp = 20;

	_unitImage = IMAGEMANAGER->addImage("고블린이동", "image/유닛/고블린/고블린이동.bmp", 420, 120, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("고블린공격", "image/유닛/고블린/고블린공격.bmp", 315, 60, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("고블린죽음", "image/유닛/고블린/고블린죽음.bmp", 175, 60, TRUE, RGB(1, 0, 0));
	_unitAni.init(420, 120, 12, 4);

	_gold = 3;

	return S_OK;
}
void goblin::release(void)
{

}
void goblin::updateNormal(void)
{
	//이동경로 포인트가 다 저장되어 있는 상황
	//시간되면 ALIVE, MOVE로 바꿔주기~!

	_centerY = _y - 12;

	

	switch (_unitState)
	{
	case UNIT_STATE::READY:
		break;
	case UNIT_STATE::MOVE:
		_unitImage = IMAGEMANAGER->findImage("고블린이동");
		_unitAni.init(420, 120, 12, 4);
		_unitAni.start();
		if(_slowed)
			_unitAni.frameUpdate(0.1);
		else
			_unitAni.frameUpdate(0.2);
		break;
	case UNIT_STATE::ATTACK:
		//모션 바꿔주는 것 및 데미지 입히는 것
		_unitImage = IMAGEMANAGER->findImage("고블린공격");
		_unitAni.init(315, 60, 9, 2);
		//타겟 위치에 따라
		if (_target != nullptr)
		{
			if (_x <= _target->getX())
			{
				_isRight = true;
				_unitAni.setPlayX(0);
			}
			else
			{
				_isRight = false;
				_unitAni.setPlayX(1);
			}
		}
		_unitAni.start();
		_unitAni.frameUpdate(0.3);
		break;
	case UNIT_STATE::STAY:
		_unitImage = IMAGEMANAGER->findImage("고블린이동");
		_unitAni.init(420, 120, 12, 4);
		if (_isRight)
			_unitAni.setPlayX(0);
		else
			_unitAni.setPlayX(1);
		_unitAni.stop();
		if (_target != nullptr)
		{
			if (getDistance(_x, _y, _target->getX(), _target->getY()) <= _atkRange)
				_unitState = UNIT_STATE::ATTACK;
		}
		break;
	case UNIT_STATE::DEAD:
		//데드 씬 재생하고 죽으면 레디상태로~
		_unitImage = IMAGEMANAGER->findImage("고블린죽음");
		_unitAni.init(175, 60, 5, 2);
		if (_isRight)
		{
			_unitAni.setPlayX(0);
		}
		else
		{
			_unitAni.setPlayX(1);
		}
		_unitAni.start();
		_unitAni.frameUpdate(0.1);
		break;
	case UNIT_STATE::ARRIVED:
		break;
	}

	enemyUnitBase::updateNormal();

}
void goblin::updateOnceUp(void)
{

}
void goblin::updateOnceDn(void)
{

}
void goblin::updateStayDn(void)
{

}
void goblin::renderObject(HDC getMemDC)
{
	if (_unitState == UNIT_STATE::READY || _unitState == UNIT_STATE::ARRIVED) {}
	else
	{
		_unitImage->aniRender(getMemDC, _x - 18, _y - 23, &_unitAni);
		//Rectangle(getMemDC, _x, _y, _x + 20, _y + 20);
	}
	enemyUnitBase::renderObject(getMemDC);
}
void goblin::renderUI(HDC getMemDC)
{
	enemyUnitBase::renderUI(getMemDC);
}

enemyUnitBase* goblin::copyUnit(void)
{
	enemyUnitBase* tempUnit = new goblin;
	tempUnit->init();
	tempUnit->setX(_x);
	tempUnit->setY(_y);
	return tempUnit;
}