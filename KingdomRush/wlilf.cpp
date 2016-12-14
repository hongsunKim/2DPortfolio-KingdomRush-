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
	_speed = 0.7;//�̵�� ���� ����
	_normalSpeed = 0.9;
	_slowedSpeed = 0.45;
	_type = TYPE::GROUND;

	_atk = 1;//1~4
	_atkMin = 1;
	_atkMax = 3;

	_atkRange = 20;
	_fullHp = _currentHp = 35;

	_unitImage = IMAGEMANAGER->addImage("�����̵�", "image/����/����/�����̵�.bmp", 232, 88, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("�����̵�����", "image/����/����/�����̵�����.bmp", 145, 44, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("�����̵��¿�", "image/����/����/�����̵��¿�.bmp", 232, 44, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("��������", "image/����/����/��������.bmp", 290, 44, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("��������", "image/����/����/��������.bmp", 261, 44, TRUE, RGB(1, 0, 0));
	_unitAni.init(232, 88, 8, 4);

	_gold = 5;

	return S_OK;
}
void wlilf::release(void)
{

}
void wlilf::updateNormal(void)
{
	//�̵���� ����Ʈ�� �� ����Ǿ� �ִ� ��Ȳ
	//�ð��Ǹ� ALIVE, MOVE�� �ٲ��ֱ�~!

	_centerY = _y - 6;



	switch (_unitState)
	{
	case UNIT_STATE::READY:
		break;
	case UNIT_STATE::MOVE:
		break;
	case UNIT_STATE::ATTACK:
		//��� �ٲ��ִ� �� �� ������ ������ ��
		_unitImage = IMAGEMANAGER->findImage("��������");
		_unitAni.init(290, 44, 10, 2);
		//Ÿ�� ��ġ�� ����
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
		_unitImage = IMAGEMANAGER->findImage("�����̵�");
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
		//���� �� ����ϰ� ������ ������·�~
		_unitImage = IMAGEMANAGER->findImage("��������");
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
		//�����̷� �ٲ��ִ� ���� �Ʊ� ������ �����̷� �ٲ��ش�~!!
		//�����̷� �ٲ��ָ鼭 �ش� ������ �� ������ Ÿ������ ���ش�~!
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
		_unitImage = IMAGEMANAGER->findImage("�����̵��¿�");
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
		_unitImage = IMAGEMANAGER->findImage("�����̵�����");
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
		_unitImage = IMAGEMANAGER->findImage("�����̵��¿�");
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
		_unitImage = IMAGEMANAGER->findImage("�����̵�����");
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