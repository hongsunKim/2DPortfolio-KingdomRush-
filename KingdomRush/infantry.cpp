#include "stdafx.h"
#include "infantry.h"


infantry::infantry()
{
}


infantry::~infantry()
{
}

HRESULT infantry::init(void)
{
	playerUnitBase::init();
	_unitState = UNIT_STATE::MOVE;
	_team = TEAM::PLAYER;

	_atkType = ATK_TYPE::PHYSICAL;
	_armor = ARMOR::NONE;
	_magicResistence = MAGIC_RESISTENCE::NONE;
	_speed = 0.7;//미디엄
	_type = TYPE::GROUND;
	_atkAble = ATTACKABLE::ABLE;

	_isInfantry = true;

	_atk = 1;//1~3
	_atkMin = 1;
	_atkMax = 3;
	_fullHp = _currentHp = 50;
	_regenSec = 10;
	_elapsedTime = TIMEMANAGER->getElapsedTime();
	_regenTime = _regenSec * 60 * _elapsedTime;
	
	_isRight = true;

	_realAttackRange = 20;
	_atkRange = 40;

	_unitImage = IMAGEMANAGER->addImage("보병이동", "image/유닛/보병/보병이동.bmp", 210, 46, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("보병공격", "image/유닛/보병/보병공격.bmp", 105, 46, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("보병죽음", "image/유닛/보병/보병죽음.bmp", 210, 46, TRUE, RGB(1, 0, 0));
	_unitAni.init(210, 46, 6, 2);
	_unitAni.setFPS(1);

	_doubleAttack = false;

	//디버그용
	/*_dstX = _x = WINSIZEX / 2;
	_dstY = _y = WINSIZEY / 2;*/

	return S_OK;
}
void infantry::release(void)
{

}
void infantry::updateNormal(void)
{
	_centerY = _y - 10;

	_prevDstX = _dstX;
	_prevDstY = _dstY;
	switch (_unitNum)
	{
	case 0:
		_dstX = ((barracks*)(_belongedTower))->getDst().x + 18 * cosf(PI / 2 + PI / 3 * 2 * 0);
		_dstY = ((barracks*)(_belongedTower))->getDst().y - 18 * sinf(PI / 2 + PI / 3 * 2 * 0);
		break;
	case 1:
		_dstX = ((barracks*)(_belongedTower))->getDst().x + 18 * cosf(PI / 2 + PI / 3 * 2 * 1);
		_dstY = ((barracks*)(_belongedTower))->getDst().y - 18 * sinf(PI / 2 + PI / 3 * 2 * 1);
		break;
	case 2:
		_dstX = ((barracks*)(_belongedTower))->getDst().x + 18 * cosf(PI / 2 + PI / 3 * 2 * 2);
		_dstY = ((barracks*)(_belongedTower))->getDst().y - 18 * sinf(PI / 2 + PI / 3 * 2 * 2);
		break;
	}
	
	if (_belongedTower->getTowerState() == TOWER_STATE::READY){}
	else
	{
		switch (_unitState)
		{
		case UNIT_STATE::DEAD:
			_unitImage = IMAGEMANAGER->findImage("보병죽음");
			_unitAni.init(210, 46, 6, 2);
			if (_isRight)
				_unitAni.setPlayX(0);
			else
				_unitAni.setPlayX(1);
			_unitAni.start();
			_unitAni.frameUpdate(0.1);
			if (_unitAni.getFramePos().x == 175)
				_unitState = UNIT_STATE::READY;
			break;
		case UNIT_STATE::READY:
			_regenTime -= _elapsedTime;
			if (_regenTime < 0)
			{
				_regenTime = _regenSec * 60 * _elapsedTime;
				_unitState = UNIT_STATE::STAY;
				_x = _belongedTower->getX();
				_y = _belongedTower->getY();
				_unitImage = IMAGEMANAGER->findImage("보병이동");
				_currentHp = _fullHp;
			}
			break;
		case UNIT_STATE::STAY:
			_unitImage = IMAGEMANAGER->findImage("보병이동");
			_unitAni.init(210, 46, 6, 2);
			if (_isRight)
			{
				_unitAni.setPlayX(0);
			}
			else
			{
				_unitAni.setPlayX(1);
			}

			if (_dstX != _x || _dstY != _y)
			{
				_unitState = UNIT_STATE::MOVE;
				//break;
			}

			if (_target != nullptr)
			{
				_unitState = UNIT_STATE::ATTACK;
			}
			break;
		case UNIT_STATE::MOVE:
			_unitImage = IMAGEMANAGER->findImage("보병이동");
			_unitAni.init(210, 46, 6, 2);
			_unitAni.start();
			_unitAni.frameUpdate(0.3);
			moveTo(_dstX, _dstY);
			if (getDistance(_x, _y, _dstX, _dstY) <= 0.7)
			{
				_x = _dstX;
				_y = _dstY;
				_unitState = UNIT_STATE::STAY;
			}
			break;
		case UNIT_STATE::ATTACK:
			if (_prevDstX != _dstX || _prevDstY != _dstY)
			{
				_unitState = UNIT_STATE::MOVE;
				break;
			}
			if(_target==nullptr)
			{
				if (_currentHp > 0)
				{
					_unitState = UNIT_STATE::STAY;
					_unitImage = IMAGEMANAGER->findImage("보병이동");
					_unitAni.init(210, 46, 6, 2);
					if (_isRight)
					{
						_unitAni.setPlayX(0);
					}
					else
					{
						_unitAni.setPlayX(1);
					}
				}
				else
				{
					_unitState = UNIT_STATE::DEAD;
				}
			}
			else
			{
				if (_target->getUnitState() == UNIT_STATE::MOVE)
				{
					_target->setUnitState(UNIT_STATE::STAY);
				}


				if (getDistance(_x, _y, _target->getX(), _target->getY()) <= _realAttackRange)
				{
					_unitImage = IMAGEMANAGER->findImage("보병공격");
					_unitAni.init(105, 46, 3, 2);
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
					_unitAni.start();
					_unitAni.frameUpdate(0.1);
					if (_atkCheck == false && _unitAni.getFramePos().x == 70)
					{
						_atk = RND->getFromIntTo(_atkMin, _atkMax);
						attackTarget();
						_atkCheck = true;
					}
					if (_unitAni.getFramePos().x != 70)
					{
						_atkCheck = false;
					}
				}
				else
				{
					_unitImage = IMAGEMANAGER->findImage("보병이동");
					_unitAni.init(210, 46, 6, 2);
					_unitAni.start();
					_unitAni.frameUpdate(0.3);
					if (_x <= _target->getX())
					{
						moveTo(_target->getX() - 20, _target->getY());
					}
					else
					{
						moveTo(_target->getX() + 20, _target->getY());
					}

				}
			}
			break;
		}

		playerUnitBase::updateNormal();

		if (_unitState != UNIT_STATE::READY)
		{
			if (_currentHp <= 0)
			{
				_atkAble = ATTACKABLE::UNABLE;
				_unitState = UNIT_STATE::DEAD;
			}
		}
	}
}
void infantry::updateOnceUp(void)
{

}
void infantry::updateOnceDn(void)
{

}
void infantry::updateStayDn(void)
{

}
void infantry::renderObject(HDC getMemDC)
{
	if (_belongedTower->getTowerState() == TOWER_STATE::READY){}
	else
	{
		if (_unitState == UNIT_STATE::READY) {}
		else
		{
			_unitImage->aniRender(getMemDC, _x - 17, _y - 19, &_unitAni);
			//Rectangle(getMemDC, _x, _y, _x + 20, _y + 20);
		}
	}
}
void infantry::renderUI(HDC getMemDC)
{

}

playerUnitBase* infantry::copyUnit(void)
{
	playerUnitBase* tempUnit = new infantry;
	tempUnit->init();
	tempUnit->setX(_x);
	tempUnit->setY(_y);
	tempUnit->setFullHp(_fullHp);
	tempUnit->setCurHp(_currentHp);
	tempUnit->setArmor(_armor);
	((infantry*)(tempUnit))->setRegen(_regenSec);
	tempUnit->setDoubleAttack(_doubleAttack);
	return tempUnit;
}

void infantry::moveTo(float x, float y)
{
	float angle = getAngle(_x, _y, x, y);
	if (angle < PI / 2 || PI / 2 * 3 < angle)
	{
		_isRight = true;
		_unitAni.setPlayX(0);
	}
	else
	{
		_isRight = false;
		_unitAni.setPlayX(1);
	}
	_x = _x + _speed * cosf(angle);
	_y = _y - _speed * sinf(angle);
}

void infantry::setRegen(float regen)
{
	_regenSec = regen;
	_regenTime = _regenSec * 60 * _elapsedTime;
}