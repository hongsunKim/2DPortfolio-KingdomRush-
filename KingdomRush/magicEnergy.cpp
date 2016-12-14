#include "stdafx.h"
#include "magicEnergy.h"


magicEnergy::magicEnergy()
{
}


magicEnergy::~magicEnergy()
{
}

HRESULT magicEnergy::init(void)
{

	return S_OK;
}
HRESULT magicEnergy::init(float x, float y, bool isUp, unitBase* target, int atk)
{
	if (isUp)
	{
		_x = x + 5;
		_y = y - 50;
	}
	else
	{
		_x = x - 5;
		_y = y - 48;
	}
	_speed = 4;
	_isArrived = false;
	_target = target;
	_targetX = _target->getX();
	_targetY = _target->getY();
	_atk = atk;
	_magicEnergyImage = IMAGEMANAGER->findImage("마법에너지");
	return S_OK;
}
void magicEnergy::release(void)
{
}
void magicEnergy::updateNormal(void)
{
	if (_target != nullptr)
	{
		if (_target->getUnitState() != UNIT_STATE::COUNTED || _target->getUnitState() != UNIT_STATE::DEAD)
		{
			_targetX = _target->getX();
			_targetY = _target->getY();
		}
	}
	else{}
	_angle = getAngle(_x, _y, _targetX, _targetY);
	_x = _x + _speed * cosf(_angle);
	_y = _y - _speed * sinf(_angle);

	if (_targetX - _speed <= _x && _x <= _targetX + _speed && _targetY - _speed <= _y && _y <= _targetY + _speed)
	{
		_x = _targetX;
		_y = _targetY;
		_isArrived = true;
		attackTarget();
		if (PLAYERUNITMANAGER->findUnit("마법사")->getDoubleAttack())
		{
			switch (_target->getArmor())
			{
			case ARMOR::NONE:
				break;
			case ARMOR::LOW:
				_target->setArmor(ARMOR::NONE);
				break;
			case ARMOR::MEDIUM:
				_target->setArmor(ARMOR::LOW);
				break;
			case ARMOR::HIGH:
				_target->setArmor(ARMOR::MEDIUM);
				break;
			}
		}

	}
}
void magicEnergy::updateOnceUp(void)
{

}
void magicEnergy::updateOnceDn(void)
{

}
void magicEnergy::updateStayDn(void)
{

}
void magicEnergy::renderObject(HDC getMemDC)
{
	_magicEnergyImage->render(getMemDC, _x - 6, _y - 6);
}
void magicEnergy::renderUI(HDC getMemDC)
{

}

void magicEnergy::attackTarget(void)
{
	if (_target != nullptr)
	{
		switch (_target->getMagicResist())
		{
		case MAGIC_RESISTENCE::NONE:
			_target->setCurHp(_target->getCurHp() - (_atk));
			break;
		case MAGIC_RESISTENCE::LOW:
			_target->setCurHp(_target->getCurHp() - ((_atk)*0.9));
			break;
		case MAGIC_RESISTENCE::MEDIUM:
			_target->setCurHp(_target->getCurHp() - ((_atk)*0.7));
			break;
		case MAGIC_RESISTENCE::HIGH:
			_target->setCurHp(_target->getCurHp() - ((_atk)*0.5));
			break;
		}
	}
}