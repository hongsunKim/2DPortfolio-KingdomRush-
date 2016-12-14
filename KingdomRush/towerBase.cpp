#include "stdafx.h"
#include "towerBase.h"
#include "stageBase.h"

towerBase::towerBase()
{
}


towerBase::~towerBase()
{
}

HRESULT towerBase::init(void)
{
	_towerState = TOWER_STATE::READY;
	_towerChange = TOWER_CHANGE::CURRENT;

	_selectBoardImage = IMAGEMANAGER->addImage("건물선택판", "image/건물/선택판.bmp", 116, 117, TRUE, RGB(1, 0, 0));

	_fullReadyTime = _curReadyTime = 2 * 60 * TIMEMANAGER->getElapsedTime();
	_fullReadyTimeBar = IMAGEMANAGER->addFrameImage("준비시간막대배경", "image/건물/준비시간막대배경.bmp", 43, 20, 1, 2, TRUE, RGB(1, 0, 0));
	_timeBarAni.init(43, 20, 1, 2);
	_curReadyTimeBar = IMAGEMANAGER->addImage("준비시간막대속", "image/건물/준비시간막대속.bmp", 43, 10, TRUE, RGB(1, 0, 0));

	_isCannonTower = false;
	_isLocked = true;

	_speedIcon = IMAGEMANAGER->addImage("속도아이콘", "image/건물/속도아이콘.bmp", 18, 18, FALSE, RGB(1, 0, 0));
	_atkRangeIcon = IMAGEMANAGER->addImage("사정거리아이콘", "image/건물/사정거리아이콘.bmp", 18, 18, FALSE, RGB(1, 0, 0));

	return S_OK;
}
void towerBase::release(void)
{

}

void towerBase::updateNormal1(void)
{
	switch (_towerState)
	{
	case TOWER_STATE::NORMAL:
		break;
	case TOWER_STATE::SHOW_SELECT:
		_stageGold = _belongedStage->getGold();
		for (int i = 0; i < 6; i++)
		{
			if (_selectButtonImage[i] != nullptr)
			{
				if (PtInRect(&_selectButtonRect[i], _ptMouse))
				{
					_selectButtonAni[i].setPlayX(1);
				}
				else
				{
					_selectButtonAni[i].setPlayX(0);
				}
			}
		}
		break;
	case TOWER_STATE::READY:
		_curReadyTime -= TIMEMANAGER->getElapsedTime();
		if (_curReadyTime < 0)
		{
			_curReadyTime = _fullReadyTime;
			_towerState = TOWER_STATE::NORMAL;
		}
		if (PtInRect(&_buttonRect, _ptMouse))
		{
			_animation.setPlayX(1, TRUE);
			_timeBarAni.setPlayX(1, TRUE);
		}
		else
		{
			_animation.setPlayX(0, TRUE);
			_timeBarAni.setPlayX(0, TRUE);
		}
		break;
	}
}

void towerBase::updateNormal(void)
{
	switch (_towerState)
	{
	case TOWER_STATE::NORMAL:
		if (PtInRect(&_buttonRect, _ptMouse))
			_animation.setPlayX(1, TRUE);
		else
			_animation.setPlayX(0, TRUE);
		break;
	case TOWER_STATE::SHOW_SELECT:
		_stageGold = _belongedStage->getGold();
		for (int i = 0; i < 6; i++)
		{
			if (_selectButtonImage[i] != nullptr)
			{
				if (PtInRect(&_selectButtonRect[i], _ptMouse))
				{
					_selectButtonAni[i].setPlayX(1);
				}
				else
				{
					_selectButtonAni[i].setPlayX(0);
				}
			}
		}
		break;
	case TOWER_STATE::READY:
		_curReadyTime -= TIMEMANAGER->getElapsedTime();
		if (_curReadyTime < 0)
		{
			_curReadyTime = _fullReadyTime;
			_towerState = TOWER_STATE::NORMAL;
		}
		if (PtInRect(&_buttonRect, _ptMouse))
		{
			_animation.setPlayX(1, TRUE);
			_timeBarAni.setPlayX(1, TRUE);
		}
		else
		{
			_animation.setPlayX(0, TRUE);
			_timeBarAni.setPlayX(0, TRUE);
		}
		break;
	}
}
void towerBase::updateOnceUp1(void)
{
	if (PtInRect(&_buttonRect, _ptMouse))
	{
		_belongedStage->setSelectedTower(this);
		_animation.setPlayX(1);
		_towerState = TOWER_STATE::SHOW_SELECT;
	}
}

void towerBase::updateOnceUp(void)
{
	switch (_towerState)
	{
	case TOWER_STATE::NORMAL:
		if (PtInRect(&_buttonRect, _ptMouse))
		{
			_belongedStage->setSelectedTower(this);
			_animation.setPlayX(1);
			_towerState = TOWER_STATE::SHOW_SELECT;
		}
		break;
	case TOWER_STATE::SHOW_SELECT:
		_towerState = TOWER_STATE::NORMAL;
		_belongedStage->setSelectedTower(nullptr);
		break;
	}
}
void towerBase::updateOnceDn(void)
{

}
void towerBase::updateStayDn(void)
{

}
void towerBase::renderObject(HDC getMemDC)
{

}
void towerBase::renderUI(HDC getMemDC)
{
	switch (_towerState)
	{
	case TOWER_STATE::NORMAL:
		break;
	case TOWER_STATE::SHOW_SELECT:
		_selectBoardImage->render(getMemDC, _x - _selectBoardImage->getWidth() / 2, _centerY - _selectBoardImage->getHeight() / 2);
		for (int i = 0; i < 6; i++)
		{
			if (_selectButtonImage[i] != nullptr)
				_selectButtonImage[i]->aniRender(getMemDC, (_selectButtonRect[i].right + _selectButtonRect[i].left) / 2 - _selectButtonImage[i]->getFrameWidth() / 2,
				(_selectButtonRect[i].bottom + _selectButtonRect[i].top) / 2 - _selectButtonImage[i]->getFrameHeight() / 2, &_selectButtonAni[i]);
		}
		break;
	case TOWER_STATE::READY:
		_fullReadyTimeBar->aniRender(getMemDC, (_buttonRect.left + _buttonRect.right) / 2 - _fullReadyTimeBar->getFrameWidth() / 2, _buttonRect.top - _fullReadyTimeBar->getFrameHeight(), &_timeBarAni);
		_curReadyTimeBar->render(getMemDC, (_buttonRect.left + _buttonRect.right) / 2 - _fullReadyTimeBar->getFrameWidth() / 2, _buttonRect.top - _fullReadyTimeBar->getFrameHeight(), 0, 0, 43 * (_curReadyTime / _fullReadyTime), 10);
	}
}