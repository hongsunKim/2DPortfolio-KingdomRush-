#include "stdafx.h"
#include "magicianTower.h"


magicianTower::magicianTower()
{
}


magicianTower::~magicianTower()
{
}


HRESULT magicianTower::init(void)
{
	towerBase::init();

	_infoIcon = IMAGEMANAGER->addImage("마법사타워인포아이콘", "image/건물/마법사타워인포아이콘.bmp", 36, 35, TRUE, RGB(1, 0, 0));
	_atkTypeIcon = IMAGEMANAGER->addImage("마법공격아이콘", "image/건물/마법공격아이콘.bmp", 18, 18, FALSE, RGB(1, 0, 0));

	_towerImage = IMAGEMANAGER->addImage("마법사타워준비", "image/건물/마법사타워준비.bmp", 80, 140, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("마법사타워", "image/건물/마법사타워.bmp", 480, 140, TRUE, RGB(1, 0, 0));
	_animation.init(480, 140, 6, 2);
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

	_buyPrice = 90;
	_sellPrice = 54;

	return S_OK;
}
void magicianTower::release(void)
{

}

void magicianTower::updateNormal1(void)
{
	switch (_towerState)
	{
	case TOWER_STATE::READY:
		_towerImage = IMAGEMANAGER->findImage("마법사타워준비");
		_animation.init(80, 140, 1, 2);
		_animation.setPlayX(0);
		break;
	case TOWER_STATE::NORMAL:
		_towerImage = IMAGEMANAGER->findImage("마법사타워");
		_animation.init(480, 140, 6, 2);
		_animation.setPlayX(0);
		_animation.start();
		_animation.frameUpdate(0.1);
		break;
	}
	towerBase::updateNormal1();
}

void magicianTower::updateNormal(void)
{
	switch (_towerState)
	{
	case TOWER_STATE::READY:
		_towerImage = IMAGEMANAGER->findImage("마법사타워준비");
		_animation.init(80, 140, 1, 2);
		if (PtInRect(&_buttonRect, _ptMouse))
			_animation.setPlayX(1);
		else
			_animation.setPlayX(0);
		break;
	case TOWER_STATE::NORMAL:
		_towerImage = IMAGEMANAGER->findImage("마법사타워");
		_animation.init(480, 140, 6, 2);
		if (PtInRect(&_buttonRect, _ptMouse))
			_animation.setPlayX(1);
		else
			_animation.setPlayX(0);
		_animation.start();
		_animation.frameUpdate(0.1);
		break;
	}
	towerBase::updateNormal();
}

void magicianTower::updateOnceUp1(void)
{
	
	towerBase::updateOnceUp1();
}

void magicianTower::updateOnceUp(void)
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
void magicianTower::updateOnceDn(void)
{

}
void magicianTower::updateStayDn(void)
{

}
void magicianTower::renderObject(HDC getMemDC)
{
	_animation.start();
	_towerImage->aniRender(getMemDC, _x - 40, _centerY - 35, &_animation);
}
void magicianTower::renderUI(HDC getMemDC)
{
	towerBase::renderUI(getMemDC);
}

towerBase* magicianTower::copyTower(void)
{
	towerBase* tempTower = new magicianTower;
	tempTower->init();
	tempTower->setPosition(_x, _y);
	tempTower->setBuyPrice(_buyPrice);
	return tempTower;
}
void magicianTower::setPosition(float x, float y)
{
	//가상함수 되어야함...
	_x = x;
	_showY = _y = y;
	_centerY = _y - 24;
	_buttonRect = RectMakeCenter(_x, _centerY, 30, 30);
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
			_selectButtonRect[i] = RectMakeCenter(56 * cos((45 + i * 45) * PI / 180) + _x, 56 * -sin((45 + i * 45) * PI / 180) + _centerY, 30, 30);
		else
			_selectButtonRect[i] = RectMakeCenter(56 * cos((225 + (i - 3) * 45) * PI / 180) + _x, 56 * -sin((225 + (i - 3) * 45) * PI / 180) + _centerY, 30, 30);
	}
}

void magicianTower::renderInfo(HDC getMemDC)
{
	_infoIcon->render(getMemDC, 205, 565);

	HFONT font = CreateFont(18, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "Magneto");
	HFONT oldfont = (HFONT)SelectObject(getMemDC, font);
	SetTextColor(getMemDC, RGB(200, 200, 200));
	SetTextAlign(getMemDC, TA_LEFT);
	SetBkMode(getMemDC, TRANSPARENT);

	wsprintf(_towerName, "Mages");
	TextOut(getMemDC, 250, 572, _towerName, lstrlen(_towerName));

	_atkTypeIcon->render(getMemDC, 370, 573);

	HFONT font1 = CreateFont(15, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "Magneto");
	(HFONT)SelectObject(getMemDC, font1);

	//wsprintf(_atkDamage, "888~888");
	wsprintf(_atkDamage, "%d~%d", (int)(PLAYERUNITMANAGER->findUnit("마법사")->getAtkMin()), (int)(PLAYERUNITMANAGER->findUnit("마법사")->getAtkMax()));
	TextOut(getMemDC, 389, 574, _atkDamage, lstrlen(_atkDamage));

	_speedIcon = IMAGEMANAGER->findImage("속도아이콘");
	_speedIcon->render(getMemDC, 446, 573);

	wsprintf(_atkSpeedChar, "Slow");
	TextOut(getMemDC, 465, 573, _atkSpeedChar, lstrlen(_atkSpeedChar));

	_atkRangeIcon->render(getMemDC, 550, 573);

	wsprintf(_atkRangeChar, "%d", (int)(PLAYERUNITMANAGER->findUnit("마법사")->getAtkRange()));
	TextOut(getMemDC, 569, 574, _atkRangeChar, lstrlen(_atkRangeChar));

	SelectObject(getMemDC, oldfont);
	DeleteObject(font);
	DeleteObject(font1);
}