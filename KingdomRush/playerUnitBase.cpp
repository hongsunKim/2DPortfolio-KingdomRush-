#include "stdafx.h"
#include "playerUnitBase.h"


playerUnitBase::playerUnitBase()
{
}


playerUnitBase::~playerUnitBase()
{
}

HRESULT playerUnitBase::init(void)
{
	_unitState = UNIT_STATE::STAY;
	_atkCheck = false;
	_isInfantry = false;
	_isMagician = false;
	_target = nullptr;
	_doubleAttack = false;
	_slowed = false;

	return S_OK;
}
void playerUnitBase::release(void)
{

}
void playerUnitBase::updateNormal(void)
{
	switch (_unitState)
	{
	case UNIT_STATE::ATTACK:
		if (_target != nullptr)
		{
			if (_target->getCurHp() <= 0)
			{
				_unitState = UNIT_STATE::STAY;
				_target = nullptr;
			}
		}
		break;
	}
}
void playerUnitBase::updateOnceUp(void)
{

}
void playerUnitBase::updateOnceDn(void)
{

}
void playerUnitBase::updateStayDn(void)
{

}
void playerUnitBase::renderObject(HDC getMemDC)
{

}
void playerUnitBase::renderUI(HDC getMemDC)
{

}