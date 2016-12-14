#include "stdafx.h"
#include "enemyUnitBase.h"


enemyUnitBase::enemyUnitBase()
{
}


enemyUnitBase::~enemyUnitBase()
{
}

HRESULT enemyUnitBase::init(void)
{
	_team = TEAM::ENEMY;
	_unitState = UNIT_STATE::READY;
	_atkAble = ATTACKABLE::ABLE;
	_atkCheck = false;
	_target = nullptr;
	_wayNum = RND->getFromIntTo(1, 12) -1;
	_dstPoint = 1;
	_unitAni.setFPS(1);
	_hpBar = IMAGEMANAGER->addImage("체력틀", "image/유닛/체력틀.bmp", 18, 4, TRUE, RGB(1, 0, 0));
	_hp = IMAGEMANAGER->addImage("체력", "image/유닛/체력.bmp", 18, 4, TRUE, RGB(1, 0, 0));
	_deadCheck = false;
	_arrivalCheck = false;
	_slowed = false;
	_slowTime = 300;
	return S_OK;
}
void enemyUnitBase::release(void)
{

}
void enemyUnitBase::updateNormal(void)
{
	switch (_unitState)
	{
	case UNIT_STATE::READY:
		break;
	case UNIT_STATE::MOVE:
		if (_slowed)
			_speed = _slowedSpeed;
		else
			_speed = _normalSpeed;

		moveTo(_wayPoint[_dstPoint].x, _wayPoint[_dstPoint].y);
		if (getDistance(_x, _y, _wayPoint[_dstPoint].x, _wayPoint[_dstPoint].y) < _speed)
		{
			_x = _wayPoint[_dstPoint].x;
			_y = _wayPoint[_dstPoint].y;
			++_dstPoint;
		}
		if (_dstPoint == _wayPoint.size())
		{
			_unitState = UNIT_STATE::ARRIVED;
		}
		break;
	case UNIT_STATE::ATTACK:
		if (_target == nullptr)
		{
			if (_currentHp > 0)
			{
				_unitState = UNIT_STATE::MOVE;
			}
			else
			{
				_unitState = UNIT_STATE::DEAD;
			}
		}

		else
		{
			if (_atkCheck == false && _unitAni.getFramePos().x == _unitImage->getWidth() - _unitAni.getFrameWidth())
			{
				_atk = RND->getFromIntTo(_atkMin, _atkMax);
				attackTarget();
				if (((playerUnitBase*)(_target))->getDoubleAttack())
				{
					_currentHp -= (_atk * 0.04);
				}
				_atkCheck = true;
			}
			if (_unitAni.getFramePos().x != _unitImage->getWidth() - _unitAni.getFrameWidth())
			{
				_atkCheck = false;
			}
		}
		break;
	case UNIT_STATE::STAY:
		//스테이로 바꿔주는 것은 아군 유닛이 스테이로 바꿔준다~!!
		//스테이로 바꿔주면서 해당 유닛을 이 유닛의 타겟으로 해준다~!
		if (_target != nullptr)
		{
			if (getDistance(_x, _y, _target->getX(), _target->getY()) <= _atkRange)
			{
				_unitState = UNIT_STATE::ATTACK;
			}
		}
		else
		{
			if (_currentHp > 0)
			{
				_unitState = UNIT_STATE::MOVE;
			}
			else
			{
				_unitState = UNIT_STATE::DEAD;
			}
		}
		break;
	case UNIT_STATE::DEAD:
		if (_unitAni.getFramePos().x == _unitImage->getWidth() - _unitAni.getFrameWidth())
		{
			_x = _wayPoint[0].x;
			_y = _wayPoint[0].y;
			_unitState = UNIT_STATE::COUNTED;
		}
		break;
	case UNIT_STATE::ARRIVED:
		_unitState = UNIT_STATE::COUNTED;
		break;
	}
	if (_currentHp <= 0 && _unitState != UNIT_STATE::COUNTED)
	{
		_unitState = UNIT_STATE::DEAD;
	}

	if (_slowed)
	{
		--_slowTime;
		if (_slowTime < 0)
		{
			_slowed = false;
			_slowTime = 300;
		}
	}
}
void enemyUnitBase::updateOnceUp(void)
{

}
void enemyUnitBase::updateOnceDn(void)
{

}
void enemyUnitBase::updateStayDn(void)
{

}
void enemyUnitBase::renderObject(HDC getMemDC)
{
	_hpBar->render(getMemDC, _x, _y, 0, 0, 18, 4);
	//Rectangle(getMemDC, _x, _y, _x + 20, _y + 20);
	_hp->render(getMemDC, _x, _y, 0, 0, 18 * (float(_currentHp) / float(_fullHp)), 4);
}
void enemyUnitBase::renderUI(HDC getMemDC)
{
	
}

void enemyUnitBase::moveTo(float x, float y)
{
	float angle = getAngle(_x, _y, x, y);
	if (angle < PI / 4 || PI / 4 * 7 <= angle)
	{
		_isRight = true;
		_unitAni.setPlayX(0);
	}
	else if (PI / 4 <=  angle && angle < PI / 4 * 3)
	{
		if (angle < PI / 2)
			_isRight = true;
		else
			_isRight = false;
		_unitAni.setPlayX(2);
	}
	else if (PI / 4 * 3 <= angle && angle < PI / 4 * 5)
	{
		_isRight = false;
		_unitAni.setPlayX(1);
	}
	else if (PI / 4 * 5 <= angle && angle < PI / 4 * 7)
	{
		if (angle < PI / 2 * 3)
			_isRight = false;
		else
			_isRight = true;
		_unitAni.setPlayX(3);
	}
	_x = _x + _speed * cosf(angle);
	_y = _y - _speed * sinf(angle);
}

void enemyUnitBase::setWayPoint(vPOINT wayPoint)
{
	_wayPoint = wayPoint;
	_x = _wayPoint[0].x;
	_y = _wayPoint[0].y;
}