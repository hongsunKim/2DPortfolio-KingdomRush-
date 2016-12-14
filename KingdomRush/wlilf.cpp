#include "stdafx.h"
#include "wlilf.h"


wlilf::wlilf()
{
}


wlilf::~wlilf()
{
}

HRESULT wlilf::init(void)
{
	enemyUnitBase::init();
	_atkType = ATK_TYPE::PHYSICAL;
	_armor = ARMOR::NONE;
	_magicResistence = MAGIC_RESISTENCE::NONE;
	_speed = 0.7;//미디엄 보다 느림
	_normalSpeed = 0.9;
	_slowedSpeed = 0.45;
	_type = TYPE::GROUND;

	_atk = 1;//1~4
	_atkMin = 1;
	_atkMax = 3;

	_atkRange = 20;
	_fullHp = _currentHp = 35;

	_unitImage = IMAGEMANAGER->addImage("릴프이동", "image/유닛/릴프/릴프이동.bmp", 232, 88, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("릴프이동상하", "image/유닛/릴프/릴프이동상하.bmp", 145, 44, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("릴프이동좌우", "image/유닛/릴프/릴프이동좌우.bmp", 232, 44, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("릴프공격", "image/유닛/릴프/릴프공격.bmp", 290, 44, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("릴프죽음", "image/유닛/릴프/릴프죽음.bmp", 261, 44, TRUE, RGB(1, 0, 0));
	_unitAni.init(232, 88, 8, 4);

	_gold = 5;

	return S_OK;
}
void wlilf::release(void)
{

}
void wlilf::updateNormal(void)
{
	//이동경로 포인트가 다 저장되어 있는 상황
	//시간되면 ALIVE, MOVE로 바꿔주기~!

	_centerY = _y - 6;



	switch (_unitState)
	{
	case UNIT_STATE::READY:
		break;
	case UNIT_STATE::MOVE:
		break;
	case UNIT_STATE::ATTACK:
		//모션 바꿔주는 것 및 데미지 입히는 것
		_unitImage = IMAGEMANAGER->findImage("릴프공격");
		_unitAni.init(290, 44, 10, 2);
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
		_unitImage = IMAGEMANAGER->findImage("릴프이동");
		_unitAni.init(232, 88, 8, 4);
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
		_unitImage = IMAGEMANAGER->findImage("릴프죽음");
		_unitAni.init(261, 44, 9, 2);
		if (_isRight)
		{
			_unitAni.setPlayX(0);
		}
		else
		{
			_unitAni.setPlayX(1);
		}
		_unitAni.start();
		_unitAni.frameUpdate(0.2);
		break;
	case UNIT_STATE::ARRIVED:
		break;
	}

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
void wlilf::updateOnceUp(void)
{

}
void wlilf::updateOnceDn(void)
{

}
void wlilf::updateStayDn(void)
{

}
void wlilf::renderObject(HDC getMemDC)
{
	if (_unitState == UNIT_STATE::READY || _unitState == UNIT_STATE::ARRIVED) {}
	else
	{
		_unitImage->aniRender(getMemDC, _x - 15, _y - 17, &_unitAni);
		//Rectangle(getMemDC, _x, _y, _x + 20, _y + 20);
	}
	enemyUnitBase::renderObject(getMemDC);
}
void wlilf::renderUI(HDC getMemDC)
{
	enemyUnitBase::renderUI(getMemDC);
}

enemyUnitBase* wlilf::copyUnit(void)
{
	enemyUnitBase* tempUnit = new wlilf;
	tempUnit->init();
	tempUnit->setX(_x);
	tempUnit->setY(_y);
	return tempUnit;
}

void wlilf::moveTo(float x, float y)
{
	float angle = getAngle(_x, _y, x, y);
	if (angle < PI / 4 || PI / 4 * 7 <= angle)
	{
		_unitImage = IMAGEMANAGER->findImage("릴프이동좌우");
		_unitAni.init(232, 44, 8, 2);
		_unitAni.start();
		if (_slowed)
			_unitAni.frameUpdate(0.15);
		else
			_unitAni.frameUpdate(0.3);

		_isRight = true;
		_unitAni.setPlayX(0);
	}
	else if (PI / 4 <= angle && angle < PI / 4 * 3)
	{
		_unitImage = IMAGEMANAGER->findImage("릴프이동상하");
		_unitAni.init(145, 44, 5, 2);
		_unitAni.start();
		if (_slowed)
			_unitAni.frameUpdate(0.1);
		else
			_unitAni.frameUpdate(0.2);

		if (angle < PI / 2)
			_isRight = true;
		else
			_isRight = false;
		_unitAni.setPlayX(0);
	}
	else if (PI / 4 * 3 <= angle && angle < PI / 4 * 5)
	{
		_unitImage = IMAGEMANAGER->findImage("릴프이동좌우");
		_unitAni.init(232, 44, 8, 2);
		_unitAni.start();
		if (_slowed)
			_unitAni.frameUpdate(0.15);
		else
			_unitAni.frameUpdate(0.3);

		_isRight = false;
		_unitAni.setPlayX(1);
	}
	else if (PI / 4 * 5 <= angle && angle < PI / 4 * 7)
	{
		_unitImage = IMAGEMANAGER->findImage("릴프이동상하");
		_unitAni.init(145, 44, 5, 2);
		_unitAni.start();
		if (_slowed)
			_unitAni.frameUpdate(0.1);
		else
			_unitAni.frameUpdate(0.2);


		if (angle < PI / 2 * 3)
			_isRight = false;
		else
			_isRight = true;
		_unitAni.setPlayX(1);
	}
	_x = _x + _speed * cosf(angle);
	_y = _y - _speed * sinf(angle);
}