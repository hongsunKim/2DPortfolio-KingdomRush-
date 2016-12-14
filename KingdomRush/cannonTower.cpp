#include "stdafx.h"
#include "cannonTower.h"


cannonTower::cannonTower()
{
}


cannonTower::~cannonTower()
{
}

HRESULT cannonTower::init(void)
{
	towerBase::init();

	_infoIcon = IMAGEMANAGER->addImage("캐논타워인포아이콘", "image/건물/캐논타워인포아이콘.bmp", 36, 35, TRUE, RGB(1, 0, 0));
	_atkTypeIcon = IMAGEMANAGER->addImage("물리공격아이콘", "image/건물/물리공격아이콘.bmp", 18, 18, FALSE, RGB(1, 0, 0));

	_towerImage = IMAGEMANAGER->addImage("캐논타워준비", "image/건물/캐논타워준비.bmp", 80, 112, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("캐논타워", "image/건물/캐논타워.bmp", 1440, 112, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("포탄", "image/건물/포탄.bmp", 12, 12, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("포탄연기", "image/건물/포탄연기.bmp", 500, 70, TRUE, RGB(1, 0, 0));
	_animation.init(1440, 112, 18, 2);
	_animation.setFPS(1);


	_selectButtonImage[0] = nullptr;
	_selectButtonImage[1] = IMAGEMANAGER->addFrameImage("건물업그레이드아이콘", "image/건물/건물업그레이드아이콘.bmp", 52, 116, 1, 2, TRUE, RGB(1, 0, 0));
	_selectButtonImage[2] = nullptr;
	_selectButtonImage[3] = nullptr;
	_selectButtonImage[4] = IMAGEMANAGER->addFrameImage("판매아이콘", "image/건물/판매아이콘.bmp", 52, 116, 1, 2, TRUE, RGB(1, 0, 0));
	_selectButtonImage[5] = nullptr;

	for (int i = 0; i < 6; i++)
	{
		_selectButtonAni[i].init(52, 116, 1, 2);
	}

	_buyPrice = 125;
	_sellPrice = 75;

	_isCannonTower = true;

	//이 조건이 지금은 일단 어택 영상 보느라 이렇게 해놨지만
	//적 유닛이 사정거리 안으로 들어오면 공격모션으로 바꾸는 것으로 바꿔줘야한다.
	_cannonTowerState = CANNON_TOWER_STATE::NORMAL;
	_target = nullptr;

	_atkRange = 100;
	_atkMin = 8;
	_atkMax = 16;

	_atkSpeed = 0.2;

	_shotCheck = false;

	return S_OK;
}
void cannonTower::release(void)
{
}
void cannonTower::updateNormal1(void)
{
	_atk = RND->getFromIntTo(_atkMin, _atkMax);

	switch (_towerState)
	{
	case TOWER_STATE::READY:
		_towerImage = IMAGEMANAGER->findImage("캐논타워준비");
		_animation.init(80, 112, 1, 2);
		_animation.setPlayX(0);
		break;
	case TOWER_STATE::NORMAL:
		_towerImage = IMAGEMANAGER->findImage("캐논타워");
		_animation.init(1440, 112, 18, 2);
		_animation.setPlayX(0);
		break;
	}

	switch (_cannonTowerState)
	{
	case CANNON_TOWER_STATE::NORMAL:
		_animation.stop();
		towerBase::updateNormal1();
		if (_target != nullptr)
		{
			_cannonTowerState = CANNON_TOWER_STATE::ATTACK;
		}
		break;
	case CANNON_TOWER_STATE::ATTACK:
		if (_target == nullptr)
		{
			_cannonTowerState = CANNON_TOWER_STATE::NORMAL;
			break;
		}
		towerBase::updateNormal1();
		_animation.start();
		_animation.frameUpdate(_atkSpeed);
		if (_shotCheck == false && _animation.getFramePos().x == 800)
		{

		}
		if (_target != nullptr)
		{
			if (_shotCheck == false && _animation.getFramePos().x == 800)
			{
				cannon* tempCannon;
				tempCannon = new cannon;
				tempCannon->init(_x, _y, _target->getX(), _target->getY());
				_vCannon.push_back(tempCannon);
				//tempArrow
				/*_atk = RND->getFromIntTo(_atkMin, _atkMax);
				attackTarget();*/
				_shotCheck = true;
			}
			if (_animation.getFramePos().x != 800)
			{
				_shotCheck = false;
			}
			if (_target != nullptr)
			{
				if (_target->getCurHp() <= 0)
				{
					_target = nullptr;
					_cannonTowerState = CANNON_TOWER_STATE::NORMAL;
				}
			}
			if (_target != nullptr)
			{
				if (getDistance(_x, _y, _target->getX(), _target->getY()) > _atkRange)
				{
					_target = nullptr;
					_cannonTowerState = CANNON_TOWER_STATE::NORMAL;
				}
			}
		}
		break;
	default:
		break;
	}
	_viCannon = _vCannon.begin();
	for (; _viCannon != _vCannon.end();)
	{
		(*_viCannon)->updateNormal();
		if ((*_viCannon)->getRemove())
		{
			(*_viCannon)->release();
			SAFE_DELETE(*_viCannon);
			_viCannon = _vCannon.erase(_viCannon);
		}
		else
		{
			++_viCannon;
		}
	}

	if (_target != nullptr)
	{
		_cannonTowerState = CANNON_TOWER_STATE::ATTACK;
	}

}

void cannonTower::updateNormal(void)
{
	_atk = RND->getFromIntTo(_atkMin, _atkMax);

	switch (_towerState)
	{
	case TOWER_STATE::READY:
		_towerImage = IMAGEMANAGER->findImage("캐논타워준비");
		_animation.init(80, 112, 1, 2);
		if (PtInRect(&_buttonRect, _ptMouse))
			_animation.setPlayX(1);
		else
			_animation.setPlayX(0);
		break;
	case TOWER_STATE::NORMAL:
		_towerImage = IMAGEMANAGER->findImage("캐논타워");
		_animation.init(1440, 112, 18, 2);
		if (PtInRect(&_buttonRect, _ptMouse))
			_animation.setPlayX(1);
		else
			_animation.setPlayX(0);
		break;
	}

	switch (_cannonTowerState)
	{
	case CANNON_TOWER_STATE::NORMAL:
		_animation.stop();
		towerBase::updateNormal();
		if (_target != nullptr)
		{
			_cannonTowerState = CANNON_TOWER_STATE::ATTACK;
		}
		break;
	case CANNON_TOWER_STATE::ATTACK:
		if (_target == nullptr)
		{
			_cannonTowerState = CANNON_TOWER_STATE::NORMAL;
			break;
		}
		towerBase::updateNormal();
		_animation.start();
		_animation.frameUpdate(_atkSpeed);
		if (_shotCheck == false && _animation.getFramePos().x == 800)
		{

		}
		if (_target != nullptr)
		{
			if (_shotCheck == false && _animation.getFramePos().x == 800)
			{
				cannon* tempCannon;
				tempCannon = new cannon;
				tempCannon->init(_x, _y, _target->getX(), _target->getY());
				_vCannon.push_back(tempCannon);
				//tempArrow
				/*_atk = RND->getFromIntTo(_atkMin, _atkMax);
				attackTarget();*/
				_shotCheck = true;
			}
			if (_animation.getFramePos().x != 800)
			{
				_shotCheck = false;
			}
			if (_target != nullptr)
			{
				if (_target->getCurHp() <= 0)
				{
					_target = nullptr;
					_cannonTowerState = CANNON_TOWER_STATE::NORMAL;
				}
			}
			if (_target != nullptr)
			{
				if (getDistance(_x, _y, _target->getX(), _target->getY()) > _atkRange)
				{
					_target = nullptr;
					_cannonTowerState = CANNON_TOWER_STATE::NORMAL;
				}
			}
		}
		break;
	default:
		break;
	}

	_viCannon = _vCannon.begin();
	for (; _viCannon != _vCannon.end();)
	{
		(*_viCannon)->updateNormal();
		if ((*_viCannon)->getRemove())
		{
			(*_viCannon)->release();
			SAFE_DELETE(*_viCannon);
			_viCannon = _vCannon.erase(_viCannon);
		}
		else
		{
			++_viCannon;
		}
	}

	if (_target != nullptr)
	{
		_cannonTowerState = CANNON_TOWER_STATE::ATTACK;
	}
}
void cannonTower::updateOnceUp(void)
{
	if (_towerState == TOWER_STATE::SHOW_SELECT)
	{
		if (PtInRect(&_selectButtonRect[4], _ptMouse))
		{
			_towerChange = TOWER_CHANGE::TOWER_SPOT;
		}
	}
	towerBase::updateOnceUp();
}
void cannonTower::updateOnceDn(void)
{
}
void cannonTower::updateStayDn(void)
{
}
void cannonTower::renderObject(HDC getMemDC)
{
	_animation.start();
	_towerImage->aniRender(getMemDC, _x - 40, _centerY - 28, &_animation);
	for (int i = 0; i < _vCannon.size(); ++i)
	{
		_vCannon[i]->renderObject(getMemDC);
	}
}
void cannonTower::renderUI(HDC getMemDC)
{
	for (int i = 0; i < _vCannon.size(); ++i)
	{
		_vCannon[i]->renderUI(getMemDC);
	}
	towerBase::renderUI(getMemDC);
}

towerBase* cannonTower::copyTower(void)
{
	towerBase* tempTower = new cannonTower;
	tempTower->init();
	tempTower->setPosition(_x, _y);
	((cannonTower*)tempTower)->setAtkMin(_atkMin);
	((cannonTower*)tempTower)->setAtkMax(_atkMax);
	((cannonTower*)tempTower)->setAtkRange(_atkRange);
	tempTower->setBuyPrice(_buyPrice);
	return tempTower;
}

void cannonTower::setPosition(float x, float y)
{
	//가상함수 되어야함...
	_x = x;
	_showY = _y = y;
	_centerY = _y - 25;
	_buttonRect = RectMakeCenter(_x, _centerY, 30, 30);
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
			_selectButtonRect[i] = RectMakeCenter(56 * cos((45 + i * 45) * PI / 180) + _x, 56 * -sin((45 + i * 45) * PI / 180) + _centerY, 30, 30);
		else
			_selectButtonRect[i] = RectMakeCenter(56 * cos((225 + (i - 3) * 45) * PI / 180) + _x, 56 * -sin((225 + (i - 3) * 45) * PI / 180) + _centerY, 30, 30);
	}
	/*for (int i = 0; i < 3; i++)
	{
	if (_unit[i] != nullptr)
	{
	_unit[i]->setX(x + (i - 1) * 5);
	_unit[i]->setY(y);
	}
	}*/
}

void cannonTower::renderInfo(HDC getMemDC)
{
	_infoIcon->render(getMemDC, 205, 565);

	HFONT font = CreateFont(18, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "Magneto");
	HFONT oldfont = (HFONT)SelectObject(getMemDC, font);
	SetTextColor(getMemDC, RGB(200, 200, 200));
	SetTextAlign(getMemDC, TA_LEFT);
	SetBkMode(getMemDC, TRANSPARENT);

	wsprintf(_towerName, "Dwarven");
	TextOut(getMemDC, 250, 572, _towerName, lstrlen(_towerName));

	_atkTypeIcon->render(getMemDC, 370, 573);

	HFONT font1 = CreateFont(15, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "Magneto");
	(HFONT)SelectObject(getMemDC, font1);

	wsprintf(_atkDamage, "%d~%d", _atkMin, _atkMax);
	TextOut(getMemDC, 389, 574, _atkDamage, lstrlen(_atkDamage));

	_speedIcon->render(getMemDC, 446, 573);

	wsprintf(_atkSpeedChar, "Very Slow");
	TextOut(getMemDC, 465, 573, _atkSpeedChar, lstrlen(_atkSpeedChar));

	_atkRangeIcon->render(getMemDC, 550, 573);
	
	wsprintf(_atkRangeChar, "%d", (int)_atkRange);
	TextOut(getMemDC, 569, 574, _atkRangeChar, lstrlen(_atkRangeChar));

	SelectObject(getMemDC, oldfont);
	DeleteObject(font);
	DeleteObject(font1);
}