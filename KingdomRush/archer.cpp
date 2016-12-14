#include "stdafx.h"
#include "archer.h"

archer::archer()
{
}

archer::~archer()
{
}

HRESULT archer::init(void)
{
	playerUnitBase::init();
	_team = TEAM::PLAYER;

	_atkType = ATK_TYPE::PHYSICAL;
	_armor = ARMOR::NONE;
	_magicResistence = MAGIC_RESISTENCE::NONE;
	_speed = 0;
	_type = TYPE::GROUND;
	_atkAble = ATTACKABLE::UNABLE;
	_atkMin = 4;//4~6
	_atkMax = 6;

	_unitImage = IMAGEMANAGER->addImage("궁수", "image/유닛/궁수/궁수.bmp", 90, 72, TRUE, RGB(1, 0, 0));
	_unitAni.init(90, 72, 5, 4);
	_unitAni.setFPS(1);

	_atkRange = 120;

	_atkCheck = false;

	_doubleAttack = false;

	_atkSpeed = 0.05;

	return S_OK;
}
void archer::release(void)
{
	_viArrow = _vArrow.begin();
	for (; _viArrow != _vArrow.end();)
	{
		if ((*_viArrow) != NULL)
		{
			(*_viArrow)->release();
			SAFE_DELETE(*_viArrow);
			_viArrow = _vArrow.erase(_viArrow);
		}
		else
		{
			++_viArrow;
		}
	}
	_vArrow.clear();
}
void archer::updateNormal(void)
{
	_centerY = _y - 37;

	//적이 사정거리 안에 들어온다면
	//스테이지에서 타겟으로 설정해 줄 것이다~~!!
	if(_belongedTower->getTowerState() == TOWER_STATE::READY)
	{
		_atkAble = ATTACKABLE::UNABLE;
	}
	else
	{
		_atkAble = ATTACKABLE::UNABLE;
		switch (_unitState)
		{
		case UNIT_STATE::STAY:
			_unitAni.stop();
			if (_target != nullptr)
				_unitState = UNIT_STATE::ATTACK;
			break;
		case UNIT_STATE::ATTACK:
			if (_target == nullptr)
			{
				_unitState = UNIT_STATE::STAY;
			}
			else
			{
				float tempAngle = getAngle(_x, _y, _target->getX(), _target->getY());
				if (0 <= tempAngle && tempAngle < PI / 2)
				{
					_unitAni.setPlayX(0);
					_isRight = true;
					_isUp = true;
				}
				else if (PI / 2 <= tempAngle && tempAngle < PI)
				{
					_unitAni.setPlayX(1);
					_isRight = false;
					_isUp = true;
				}
				else if (PI <= tempAngle && tempAngle < PI / 2 * 3)
				{
					_unitAni.setPlayX(3);
					_isRight = false;
					_isUp = false;
				}
				else
				{
					_unitAni.setPlayX(2);
					_isRight = true;
					_isUp = false;
				}
				_unitAni.start();
				_unitAni.frameUpdate(_atkSpeed);
				if (_target != nullptr)
				{
					if (_atkCheck == false && _unitAni.getFramePos().x == 72)
					{
						arrow* tempArrow;
						tempArrow = new arrow;
						tempArrow->init(_x, _y, _isRight, _target->getX(), _target->getY());
						_vArrow.push_back(tempArrow);
						//tempArrow
						/*_atk = RND->getFromIntTo(_atkMin, _atkMax);
						attackTarget();*/
						_atkCheck = true;
					}
				}
				if (_unitAni.getFramePos().x != 72)
				{
					_atkCheck = false;
				}
				if (_target != nullptr)
				{
					if (_target->getCurHp() <= 0)
					{
						_target = nullptr;
						_unitState = UNIT_STATE::STAY;
					}
				}
				if (_target != nullptr)
				{
					if (getDistance(_x, _y, _target->getX(), _target->getY()) > _atkRange)
					{
						_target = nullptr;
						_unitState = UNIT_STATE::STAY;
					}
				}
			}
			break;
		}
	}

	_viArrow = _vArrow.begin();
	for (; _viArrow != _vArrow.end();)
	{
		(*_viArrow)->updateNormal();
		if ((*_viArrow)->getArrived())
		{
			if (_target != nullptr)
			{
				_atk = RND->getFromIntTo(_atkMin, _atkMax);
				if (_doubleAttack && RND->getFromIntTo(1,10) == 1)
				{
					_atk *= 2;
				}
				attackTarget();
			}
			(*_viArrow)->release();
			SAFE_DELETE(*_viArrow);
			_viArrow = _vArrow.erase(_viArrow);
		}
		else
		{
			++_viArrow;
		}
	}

	if (_target != nullptr)
	{
		_unitState = UNIT_STATE::ATTACK;
	}
}
void archer::updateOnceUp(void)
{

}
void archer::updateOnceDn(void)
{

}
void archer::updateStayDn(void)
{

}
void archer::renderObject(HDC getMemDC)
{
	if (_belongedTower->getTowerState() == TOWER_STATE::READY) {}
	else
	{
		_unitImage->aniRender(getMemDC, _x - 9, _y - 47, &_unitAni);
		for (int i = 0; i < _vArrow.size(); ++i)
		{
			_vArrow[i]->renderObject(getMemDC);
		}
	}
	//Rectangle(getMemDC, _x, _y - 37, _x + 20, _y + 20 - 37);
}
void archer::renderUI(HDC getMemDC)
{

}

playerUnitBase* archer::copyUnit(void)
{
	playerUnitBase* tempUnit = new archer;
	tempUnit->init();
	tempUnit->setAtkRange(_atkRange);
	tempUnit->setAtkType(_atkType);
	tempUnit->setDoubleAttack(_doubleAttack);
	tempUnit->setX(_x);
	tempUnit->setY(_y);
	return tempUnit;
}