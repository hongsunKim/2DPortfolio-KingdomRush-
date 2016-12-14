#include "stdafx.h"
#include "towerSpot.h"


towerSpot::towerSpot()
{
}


towerSpot::~towerSpot()
{
}

HRESULT towerSpot::init(void)
{
	towerBase::init();
	_towerState = TOWER_STATE::NORMAL;

	_towerImage = IMAGEMANAGER->addImage("타워스폿", "image/건물/타워스폿.bmp", 84, 104, TRUE, RGB(1, 0, 0));
	_animation.init(84, 104, 1, 2);

	_selectButtonImage[0] = IMAGEMANAGER->addFrameImage("배럭아이콘", "image/건물/배럭아이콘2.bmp", 52, 174, 1, 3, TRUE, RGB(1, 0, 0));
	_selectButtonImage[1] = nullptr;
	_selectButtonImage[2] = IMAGEMANAGER->addFrameImage("궁수타워아이콘", "image/건물/궁수타워아이콘2.bmp", 52, 174, 1, 3, TRUE, RGB(1, 0, 0));
	_selectButtonImage[3] = IMAGEMANAGER->addFrameImage("마법사타워아이콘", "image/건물/마법사타워아이콘2.bmp", 52, 174, 1, 3, TRUE, RGB(1, 0, 0));
	_selectButtonImage[4] = nullptr;
	_selectButtonImage[5] = IMAGEMANAGER->addFrameImage("캐논타워아이콘", "image/건물/캐논타워아이콘2.bmp", 52, 174, 1, 3, TRUE, RGB(1, 0, 0));

	for (int i = 0; i < 6; i++)
	{
		_selectButtonAni[i].init(52, 174, 1, 3);
	}

	_buyPrice = 0;
	_sellPrice = 0;

	return S_OK;
}
void towerSpot::release(void)
{
	towerBase::release();
}

void towerSpot::updateNormal(void)
{
	towerBase::updateNormal();
	if (_towerState == TOWER_STATE::SHOW_SELECT)
	{
		if (TOWERMANAGER->findTower("배럭스")->getBuyPrice() > _stageGold)
		{
			_selectButtonAni[0].setPlayX(2);
		}
		if (TOWERMANAGER->findTower("아쳐타워")->getBuyPrice() > _stageGold)
		{
			_selectButtonAni[2].setPlayX(2);
		}
		if (TOWERMANAGER->findTower("마법사타워")->getBuyPrice() > _stageGold)
		{
			_selectButtonAni[3].setPlayX(2);
		}
		if (TOWERMANAGER->findTower("캐논타워")->getBuyPrice() > _stageGold)
		{
			_selectButtonAni[5].setPlayX(2);
		}
	}
}

void towerSpot::updateOnceUp(void)
{
	if (_towerState == TOWER_STATE::SHOW_SELECT)
	{
		if (PtInRect(&_selectButtonRect[0], _ptMouse))
		{
			_towerChange = TOWER_CHANGE::BARRACKS_TOWER;
		}
		if (PtInRect(&_selectButtonRect[2], _ptMouse))
		{
			_towerChange = TOWER_CHANGE::ARCHER_TOWER;
		}
		if (PtInRect(&_selectButtonRect[3], _ptMouse))
		{
			_towerChange = TOWER_CHANGE::MAGICIAN_TOWER;
		}
		if (PtInRect(&_selectButtonRect[5], _ptMouse))
		{
			_towerChange = TOWER_CHANGE::CANNON_TOWER;
		}
	}
	towerBase::updateOnceUp();
}
void towerSpot::updateOnceDn(void)
{
	towerBase::updateOnceDn();
}
void towerSpot::updateStayDn(void)
{
	towerBase::updateStayDn();
}
void towerSpot::renderObject(HDC getMemDC)
{
	towerBase::renderObject(getMemDC);
	_animation.start();
	_towerImage->aniRender(getMemDC, _x - 42, _centerY - 26, &_animation);
}
void towerSpot::renderUI(HDC getMemDC)
{
	towerBase::renderUI(getMemDC);
	if (_towerState == TOWER_STATE::SHOW_SELECT)
	{
		HFONT font = CreateFont(12, 0, 0, 0, 0, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "Arial Regular");
		HFONT oldfont = (HFONT)SelectObject(getMemDC, font);
		char str[8];
		SetTextColor(getMemDC, RGB(255, 255, 255));
		SetTextAlign(getMemDC, TA_CENTER);
		SetBkMode(getMemDC, TRANSPARENT);
		wsprintf(str, "%d", TOWERMANAGER->findTower("배럭스")->getBuyPrice());
		TextOut(getMemDC, (_selectButtonRect[0].left + _selectButtonRect[0].right) / 2, _selectButtonRect[0].bottom - 4, str, strlen(str));
		wsprintf(str, "%d", TOWERMANAGER->findTower("아쳐타워")->getBuyPrice());
		TextOut(getMemDC, (_selectButtonRect[2].left + _selectButtonRect[2].right) / 2, _selectButtonRect[2].bottom - 4, str, strlen(str));
		wsprintf(str, "%d", TOWERMANAGER->findTower("마법사타워")->getBuyPrice());
		TextOut(getMemDC, (_selectButtonRect[3].left + _selectButtonRect[3].right) / 2, _selectButtonRect[3].bottom - 4, str, strlen(str));
		wsprintf(str, "%d", TOWERMANAGER->findTower("캐논타워")->getBuyPrice());
		TextOut(getMemDC, (_selectButtonRect[5].left + _selectButtonRect[5].right) / 2, _selectButtonRect[5].bottom - 4, str, strlen(str));
		SelectObject(getMemDC, oldfont);
		DeleteObject(font);
	}
}

towerBase* towerSpot::copyTower(void)
{
	towerBase* tempTower = new towerSpot;
	tempTower->init();
	tempTower->setPosition(_x, _y);
	return tempTower;
}

void towerSpot::setPosition(float x, float y)
{
	//가상함수 되어야함...
	_x = x;
	_y = y;
	_showY = 0;
	_centerY = _y - 18;
	_buttonRect = RectMakeCenter(_x, _centerY, 30, 30);
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
			_selectButtonRect[i] = RectMakeCenter(56 * cos((45 + i * 45) * PI / 180) + _x, 56 * -sin((45 + i * 45) * PI / 180) + _centerY, 30, 30);
		else
			_selectButtonRect[i] = RectMakeCenter(56 * cos((225 + (i - 3) * 45) * PI / 180) + _x, 56 * -sin((225 + (i - 3) * 45) * PI / 180) + _centerY, 30, 30);
	}
}

void towerSpot::renderInfo(HDC getMemDC)
{

}