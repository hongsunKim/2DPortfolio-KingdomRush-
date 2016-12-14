#include "stdafx.h"
#include "barracks.h"


barracks::barracks()
{
}


barracks::~barracks()
{
}

HRESULT barracks::init(void)
{
	towerBase::init();

	_infoIcon = IMAGEMANAGER->addImage("배럭스인포아이콘", "image/건물/배럭스인포아이콘.bmp", 36, 35, TRUE, RGB(1, 0, 0));
	_atkTypeIcon = IMAGEMANAGER->addImage("물리공격아이콘", "image/건물/물리공격아이콘.bmp", 18, 18, FALSE, RGB(1, 0, 0));
	_infantryInfoIcon = IMAGEMANAGER->addImage("보병인포아이콘", "image/건물/보병인포아이콘.bmp", 36, 35, TRUE, RGB(1, 0, 0));
	_hpIcon = IMAGEMANAGER->addImage("체력아이콘", "image/건물/체력아이콘.bmp", 18, 18, FALSE, RGB(1, 0, 0));
	_armorIcon = IMAGEMANAGER->addImage("방어아이콘", "image/건물/방어아이콘.bmp", 18, 18, FALSE, RGB(1, 0, 0));
	_regenIcon = IMAGEMANAGER->addImage("리젠아이콘", "image/건물/리젠아이콘.bmp", 18, 18, FALSE, RGB(1, 0, 0));

	IMAGEMANAGER->addImage("랠리포인트깃발", "image/건물/랠리포인트깃발.bmp", 15, 16, TRUE, RGB(1, 0, 0));

	_towerImage = IMAGEMANAGER->addImage("배럭스준비", "image/건물/배럭스준비.bmp", 80, 120, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("배럭스", "image/건물/배럭.bmp", 320, 120, TRUE, RGB(1, 0, 0));
	_animation.init(320, 120, 4, 2);
	_animation.setFPS(1);

	_selectButtonImage[0] = nullptr;
	_selectButtonImage[1] = IMAGEMANAGER->addFrameImage("건물업그레이드아이콘", "image/건물/건물업그레이드아이콘.bmp", 52, 116, 1, 2, TRUE, RGB(1, 0, 0));
	_selectButtonImage[2] = nullptr;
	_selectButtonImage[3] = nullptr;
	_selectButtonImage[4] = IMAGEMANAGER->addFrameImage("판매아이콘", "image/건물/판매아이콘.bmp", 52, 116, 1, 2, TRUE, RGB(1, 0, 0));
	_selectButtonImage[5] = IMAGEMANAGER->addFrameImage("랠리포인트아이콘", "image/건물/랠리포인트아이콘.bmp", 52, 116, 1, 2, TRUE, RGB(1, 0, 0));

	for (int i = 0; i < 6; i++)
	{
		_selectButtonAni[i].init(52, 116, 1, 2);
	}

	_pointDst = false;

	_buyPrice = 70;
	_sellPrice = 42;

	_barracksState = BARRACKS_STATE::NORMAL;

	return S_OK;
}
void barracks::release(void)
{

}

void barracks::updateNormal1(void)
{
	switch (_towerState)
	{
	case TOWER_STATE::READY:
		_towerImage = IMAGEMANAGER->findImage("배럭스준비");
		_animation.init(80, 120, 1, 2);
		break;
	case TOWER_STATE::NORMAL:
		_towerImage = IMAGEMANAGER->findImage("배럭스");
		_animation.init(320, 120, 4, 2);
		break;
	}


	switch (_barracksState)
	{
	case BARRACKS_STATE::NORMAL:
		towerBase::updateNormal1();
		break;
	case BARRACKS_STATE::OPEN_DOOR:
		towerBase::updateNormal1();
		_animation.start();
		_animation.frameUpdate(0.1);
		break;
	default:
		break;
	}
}

void barracks::updateNormal(void)
{
	switch (_towerState)
	{
	case TOWER_STATE::READY:
		_towerImage = IMAGEMANAGER->findImage("배럭스준비");
		_animation.init(80, 120, 1, 2);
		break;
	case TOWER_STATE::NORMAL:
		_towerImage = IMAGEMANAGER->findImage("배럭스");
		_animation.init(320, 120, 4, 2);
		break;
	}


	switch (_barracksState)
	{
	case BARRACKS_STATE::NORMAL:
		towerBase::updateNormal();
		break;
	case BARRACKS_STATE::OPEN_DOOR:
		towerBase::updateNormal();
		_animation.start();
		_animation.frameUpdate(0.1);
		break;
	default:
		break;
	}

}

void barracks::updateOnceUp1(void)
{
	towerBase::updateOnceUp1();
}

void barracks::updateOnceUp(void)
{
	if (_towerState == TOWER_STATE::SHOW_SELECT)
	{
		if (PtInRect(&_selectButtonRect[4], _ptMouse))
		{
			_towerChange = TOWER_CHANGE::TOWER_SPOT;
		}
		if (PtInRect(&_selectButtonRect[5], _ptMouse))
		{
			_pointDst = true;
		}
	}
	towerBase::updateOnceUp();
}
void barracks::updateOnceDn(void)
{
	if (_pointDst == true)
	{
		_dst.x = _ptMouse.x;
		_dst.y = _ptMouse.y;

		_pointDst = false;
	}
}
void barracks::updateStayDn(void)
{

}
void barracks::renderObject(HDC getMemDC)
{
	towerBase::renderObject(getMemDC);
	_animation.start();
	_towerImage->aniRender(getMemDC, _x - 40, _centerY - 30, &_animation);
}
void barracks::renderUI(HDC getMemDC)
{
	towerBase::renderUI(getMemDC);
	if (_pointDst == true)
	{
		IMAGEMANAGER->alphaRender("랠리포인트깃발", getMemDC, _ptMouse.x - 7, _ptMouse.y - 16, 200);
	}
}

towerBase* barracks::copyTower(void)
{
	towerBase* tempTower = new barracks;
	tempTower->init();
	tempTower->setPosition(_x, _y);
	return tempTower;
}
void barracks::setPosition(float x, float y)
{
	//가상함수 되어야함...
	_x = _dst.x = x;
	_showY = _y = _dst.y = y;
	_centerY = _y - 21;
	_buttonRect = RectMakeCenter(_x, _centerY, 30, 30);
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
			_selectButtonRect[i] = RectMakeCenter(56 * cos((45 + i * 45) * PI / 180) + _x, 56 * -sin((45 + i * 45) * PI / 180) + _centerY, 30, 30);
		else
			_selectButtonRect[i] = RectMakeCenter(56 * cos((225 + (i - 3) * 45) * PI / 180) + _x, 56 * -sin((225 + (i - 3) * 45) * PI / 180) + _centerY, 30, 30);
	}
}

void barracks::renderInfo(HDC getMemDC)
{
	_infoIcon->render(getMemDC, 205, 565);

	HFONT font = CreateFont(18, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "Magneto");
	HFONT oldfont = (HFONT)SelectObject(getMemDC, font);
	SetTextColor(getMemDC, RGB(200, 200, 200));
	SetTextAlign(getMemDC, TA_LEFT);
	SetBkMode(getMemDC, TRANSPARENT);

	wsprintf(_towerName, "Barracks");
	TextOut(getMemDC, 250, 572, _towerName, lstrlen(_towerName));

	_infantryInfoIcon->render(getMemDC, 360, 565);

	_atkTypeIcon->render(getMemDC, 441, 573);

	HFONT font1 = CreateFont(14, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "Magneto");
	(HFONT)SelectObject(getMemDC, font1);

	//wsprintf(_atkDamage, "888~888");
	wsprintf(_atkDamage, "%d~%d", (int)(PLAYERUNITMANAGER->findUnit("보병")->getAtkMin()), (int)(PLAYERUNITMANAGER->findUnit("보병")->getAtkMax()));
	TextOut(getMemDC, 460, 574, _atkDamage, lstrlen(_atkDamage));

	_hpIcon->render(getMemDC, 397, 573);
	wsprintf(_hpChar, "%d", PLAYERUNITMANAGER->findUnit("보병")->getFullHp());
	TextOut(getMemDC, 414, 574, _hpChar, lstrlen(_hpChar));

	_armorIcon->render(getMemDC, 495, 572);
	switch (PLAYERUNITMANAGER->findUnit("보병")->getArmor())
	{
	case ARMOR::NONE:
		TextOut(getMemDC, 514, 574, "None", lstrlen("None"));
		break;
	case ARMOR::LOW:
		TextOut(getMemDC, 514, 574, "Low", lstrlen("Low"));
		break;
	case ARMOR::MEDIUM:
		TextOut(getMemDC, 514, 574, "Medium", lstrlen("Medium"));
		break;
	case ARMOR::HIGH:
		TextOut(getMemDC, 514, 574, "High", lstrlen("High"));
		break;
	}

	_regenIcon->render(getMemDC, 565, 573);
	wsprintf(_regenChar, "%d", ((int)((infantry*)PLAYERUNITMANAGER->findUnit("보병"))->getRegen()));
	TextOut(getMemDC, 584, 574, _regenChar, lstrlen(_regenChar));

	SelectObject(getMemDC, oldfont);
	DeleteObject(font);
	DeleteObject(font1);
}