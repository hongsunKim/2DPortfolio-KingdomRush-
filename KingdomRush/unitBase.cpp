#include "stdafx.h"
#include "unitBase.h"


unitBase::unitBase()
{
}


unitBase::~unitBase()
{
}

void unitBase::attackTarget(void)
{
	switch (_atkType)
	{
	case ATK_TYPE::PHYSICAL_PIERCING:
		_target->setCurHp(_target->getCurHp() - (_atk));
		break;
	case ATK_TYPE::PHYSICAL:
		switch (_target->getArmor())
		{
		case ARMOR::NONE:
			_target->setCurHp(_target->getCurHp() - (_atk));
			break;
		case ARMOR::LOW:
			_target->setCurHp(_target->getCurHp() - ((_atk)*0.9));
			break;
		case ARMOR::MEDIUM:
			_target->setCurHp(_target->getCurHp() - ((_atk)*0.7));
			break;
		case ARMOR::HIGH:
			_target->setCurHp(_target->getCurHp() - ((_atk)*0.5));
			break;
		}
		break;
	case ATK_TYPE::MAGICAL_PIERCING:
		_target->setCurHp(_target->getCurHp() - (_atk));
		break;
	case ATK_TYPE::MAGICAL:
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
		break;
	}
}