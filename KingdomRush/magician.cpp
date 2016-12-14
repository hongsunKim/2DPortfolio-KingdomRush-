#include "stdafx.h"
#include "magician.h"


magician::magician()
{
}

magician::~magician()
{
}

HRESULT magician::init(void)
{
	playerUnitBase::init();
	_isMagician = true;
	_team = TEAM::PLAYER;

	_atkType = ATK_TYPE::MAGICAL;
	_armor = ARMOR::NONE;
	_magicResistence = MAGIC_RESISTENCE::NONE;
	_speed = 0;
	_type = TYPE::GROUND;
	_atkAble = ATTACKABLE::UNABLE;
	_atk = 9;//9~17
	_atkMin = 9;
	_atkMax = 17;
	_slowSkill = false;

	_unitImage = IMAGEMANAGER->addImage("마법사", "image/유닛/마법사/마법사.bmp", 330, 60, TRUE, RGB(37, 176, 210));
	IMAGEMANAGER->addImage("마법에너지", "image/유닛/마법사/마법에너지.bmp", 12, 12, TRUE, RGB(37, 176, 210));
	_unitAni.init(330, 60, 11, 2);
	_unitAni.setFPS(1);

	_atkRange = 120;

	_atkCheck = false;
	_isUp = true;

	return S_OK;
}
void magician::release(void)
{
	_viMagicEnergy = _vMagicEnergy.begin();
	for (; _viMagicEnergy != _vMagicEnergy.end();)
	{
		if ((*_viMagicEnergy) != NULL)
		{
			(*_viMagicEnergy)->release();
			SAFE_DELETE(*_viMagicEnergy);
			_viMagicEnergy = _vMagicEnergy.erase(_viMagicEnergy);
		}
		else
		{
			++_viMagicEnergy;
		}
	}
	_vMagicEnergy.clear();
}
void magician::updateNormal(void)
{
	_centerY = _y - 42;

	if (_belongedTower->getTowerState() == TOWER_STATE::READY)
	{
		_atkAble = ATTACKABLE::UNABLE;
	}
	else
	{
		//스테이지에 있는 스테이지 유닛 벡터에서 적을 설정해준다~
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
				break;
			}
			float tempAngle = getAngle(_x, _y, _target->getX(), _target->getY());
			if (0 <= tempAngle && tempAngle < PI)
			{
				_isUp = true;
				_unitAni.setPlayX(0);
			}
			else if (PI <= tempAngle && tempAngle < 2 * PI)
			{
				_isUp = false;
				_unitAni.setPlayX(1);
			}

			_unitAni.start();
			_unitAni.frameUpdate(0.1);

			if (_target != nullptr)
			{
				if (_atkCheck == false && _unitAni.getFramePos().x == 210)
				{
					magicEnergy* tempMagic;
					tempMagic = new magicEnergy;
					_atk = RND->getFromIntTo(_atkMin, _atkMax);
					tempMagic->init(_x, _y, _isUp, _target, _atk);
					_vMagicEnergy.push_back(tempMagic);
					//tempArrow
					/*_atk = RND->getFromIntTo(_atkMin, _atkMax);
					attackTarget();*/
					_atkCheck = true;
				}
			}
			if (_unitAni.getFramePos().x != 210)
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
			break;
		}
	}
	_viMagicEnergy = _vMagicEnergy.begin();
	for (; _viMagicEnergy != _vMagicEnergy.end();)
	{
		(*_viMagicEnergy)->updateNormal();
		if ((*_viMagicEnergy)->getArrived())
		{
			if (_slowSkill && _target != nullptr)
			{
				_target->setSlow(true);
			}
			(*_viMagicEnergy)->release();
			SAFE_DELETE(*_viMagicEnergy);
			_viMagicEnergy = _vMagicEnergy.erase(_viMagicEnergy);
		}
		else
		{
			++_viMagicEnergy;
		}
	}

	if (_target != nullptr)
	{
		_unitState = UNIT_STATE::ATTACK;
	}
}
void magician::updateOnceUp(void)
{

}
void magician::updateOnceDn(void)
{

}
void magician::updateStayDn(void)
{

}
void magician::renderObject(HDC getMemDC)
{
	if (_belongedTower->getTowerState() == TOWER_STATE::READY){}
	else
	{
		_unitImage->aniRender(getMemDC, _x - 15, _y - 34 - 24, &_unitAni);
		for (int i = 0; i < _vMagicEnergy.size(); ++i)
		{
			_vMagicEnergy[i]->renderObject(getMemDC);
		}
		//Rectangle(getMemDC, _x, _centerY, _x + 20, _centerY + 20);
	}
}
void magician::renderUI(HDC getMemDC)
{

}

playerUnitBase* magician::copyUnit(void)
{
	playerUnitBase* tempUnit = new magician;
	tempUnit->init();
	tempUnit->setX(_x);
	tempUnit->setY(_y);
	tempUnit->setAtkRange(_atkRange);
	tempUnit->setAtkMin(_atkMin);
	tempUnit->setAtkMax(_atkMax);
	((magician*)tempUnit)->setSlowSkill(_slowSkill);
	return tempUnit;
}