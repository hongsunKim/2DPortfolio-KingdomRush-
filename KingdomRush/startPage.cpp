#include "stdafx.h"
#include "startPage.h"


startPage::startPage()
{
}


startPage::~startPage()
{
}

HRESULT startPage::init(void)
{
	_currentPage = STARTPAGE::OPEN;

	_startButtonPos = _creditButtonPos = 100;
	_startPageImage = IMAGEMANAGER->addImage("���۹��", "image/���۹��.bmp", 700, 600, FALSE, RGB(0, 0, 0));
	_titleImage = IMAGEMANAGER->addImage("Ÿ��Ʋ", "image/Ÿ��Ʋ.bmp", 429, 295, TRUE, RGB(1, 0, 0));
	_startImage = IMAGEMANAGER->addImage("���۹�ư(�⺻)", "image/���۹�ư(�⺻).bmp", 199, 96, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("���۹�ư(��)", "image/���۹�ư(��).bmp", 199, 96, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("���۹�ư(Ŭ��)", "image/���۹�ư(Ŭ��).bmp", 199, 96, TRUE, RGB(1, 0, 0));
	_creditImage = IMAGEMANAGER->addImage("ũ������ư(�⺻)", "image/ũ������ư(�⺻).bmp", 166, 72, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("ũ������ư(��)", "image/ũ������ư(��).bmp", 166, 72, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("ũ������ư(Ŭ��)", "image/ũ������ư(Ŭ��).bmp", 166, 72, TRUE, RGB(1, 0, 0));

	_startButton = RectMake((WINSIZEX / 2) - _startImage->getWidth() / 2, 385, 199, 96);
	_creditButton = RectMake((WINSIZEX / 2) - _creditImage->getWidth() / 2, 485, 166, 72);


	_leftDoorImage = IMAGEMANAGER->addImage("���ʹ�", "image/��ü����/���ʹ�.bmp", 470, 655, TRUE, RGB(1, 0, 0));
	_rightDoorImage = IMAGEMANAGER->addImage("�����ʹ�", "image/��ü����/�����ʹ�.bmp", 464, 655, TRUE, RGB(1, 0, 0));
	_leftDoorPos = -110;
	_rightDoorPos = 340;


	_selectBoardImage = IMAGEMANAGER->addImage("������", "image/����������/������.bmp", 218, 257, TRUE, RGB(1, 0, 0));
	_selectBoardPos = 600;
	_saveGameImage0 = _saveGameImage1 = _saveGameImage2 = IMAGEMANAGER->addImage("���ù�ư(�⺻)", "image/����������/���ù�ư(�⺻).bmp", 169, 57, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("���ù�ư(��)", "image/����������/���ù�ư(��).bmp", 169, 57, TRUE, RGB(1, 0, 0));
	for (int i = 0; i < 3; i++)
	{
		_load[i] = RectMake(WINSIZEX / 2 - _saveGameImage0->getWidth() / 2, 335 + (65 * i) + 48, _saveGameImage0->getWidth(), _saveGameImage0->getHeight());
	}

	_selectSlotNum = 0;


	//�ε����� ����� �ϴ� �κ�
	TOWERMANAGER->addTower("Ÿ������", new towerSpot);
	TOWERMANAGER->addTower("�跰��", new barracks);
	TOWERMANAGER->addTower("����Ÿ��", new archerTower);
	TOWERMANAGER->addTower("������Ÿ��", new magicianTower);
	TOWERMANAGER->addTower("ĳ��Ÿ��", new cannonTower);
	PLAYERUNITMANAGER->addUnit("�ü�", new archer);
	PLAYERUNITMANAGER->addUnit("����", new infantry);
	PLAYERUNITMANAGER->addUnit("������", new magician);
	ENEMYUNITMANAGER->addUnit("���", new goblin);
	ENEMYUNITMANAGER->addUnit("��ũ", new orc);
	ENEMYUNITMANAGER->addUnit("����", new wlilf);

	return S_OK;
}
void startPage::release(void)
{

}
void startPage::update(void)
{
	switch (_currentPage)
	{
	case STARTPAGE::READY:
		_startButtonPos += 8;
		_creditButtonPos += 8;

		if (_startButtonPos >= 385)
		{
			_startButtonPos = 385;
			//_creditButtonPos += 2;
		}
		if (_creditButtonPos > 485)
		{
			_creditButtonPos = 485;
			_currentPage = STARTPAGE::START;
		}
		break;
	case STARTPAGE::START:
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&_startButton, _ptMouse))
			{
				_startImage = IMAGEMANAGER->findImage("���۹�ư(Ŭ��)");
			}
			if (PtInRect(&_creditButton, _ptMouse))
			{
				_creditImage = IMAGEMANAGER->findImage("ũ������ư(Ŭ��)");
			}
		}
		else
		{
			if (PtInRect(&_startButton, _ptMouse))
			{
				_startImage = IMAGEMANAGER->findImage("���۹�ư(��)");
			}
			else
			{
				_startImage = IMAGEMANAGER->findImage("���۹�ư(�⺻)");
			}

			if (PtInRect(&_creditButton, _ptMouse))
			{
				_creditImage = IMAGEMANAGER->findImage("ũ������ư(��)");
			}
			else
			{
				_creditImage = IMAGEMANAGER->findImage("ũ������ư(�⺻)");
			}
		}

		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			if (PtInRect(&_startButton, _ptMouse))
			{
				_currentPage = STARTPAGE::READYSELECT;
			}
			if (PtInRect(&_creditButton, _ptMouse))
			{
				_currentPage = STARTPAGE::CLOSE_FOR_CREDIT;
			}
		}
		break;
	case STARTPAGE::CLOSE_FOR_CREDIT:
		_leftDoorPos += 10;
		_rightDoorPos -= 10;
		if (_leftDoorPos > -110 && _rightDoorPos < 340)
		{
			_leftDoorPos = -110;
			_rightDoorPos = 340;
			SCENEMANAGER->changeScene("ũ����ȭ��");
		}
		break;
	case STARTPAGE::READYSELECT:
		_creditButtonPos -= 8;
		if (_creditButtonPos < 385)
		{
			_startButtonPos = _creditButtonPos;
		}
		if (_startButtonPos < 100)
		{
			_startButtonPos = _creditButtonPos = 100;
			_currentPage = STARTPAGE::SETSELECT;
		}
		break;
	case STARTPAGE::SETSELECT:
		_selectBoardPos -= 10;
		if (_selectBoardPos < 335)
		{
			_selectBoardPos = 600;
			_currentPage = STARTPAGE::SELECT;
		}
		break;
	case STARTPAGE::SELECT:
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			for (int i = 0; i < 3; i++)
			{
				if (PtInRect(&_load[i], _ptMouse))
				{
					_selectSlotNum = i + 1;
					_currentPage = STARTPAGE::CLOSE_FOR_MAIN;
				}
			}
		}
		
		if ((PtInRect(&_load[0], _ptMouse)) || (PtInRect(&_load[1], _ptMouse)) || (PtInRect(&_load[2], _ptMouse)))
		{
			if (PtInRect(&_load[0], _ptMouse))
			{
				_saveGameImage0 = IMAGEMANAGER->findImage("���ù�ư(��)");
				_saveGameImage1 = IMAGEMANAGER->findImage("���ù�ư(�⺻)");
				_saveGameImage2 = IMAGEMANAGER->findImage("���ù�ư(�⺻)");
			}
			if (PtInRect(&_load[1], _ptMouse))
			{
				_saveGameImage0 = IMAGEMANAGER->findImage("���ù�ư(�⺻)");
				_saveGameImage1 = IMAGEMANAGER->findImage("���ù�ư(��)");
				_saveGameImage2 = IMAGEMANAGER->findImage("���ù�ư(�⺻)");
			}
			if (PtInRect(&_load[2], _ptMouse))
			{
				_saveGameImage0 = IMAGEMANAGER->findImage("���ù�ư(�⺻)");
				_saveGameImage1 = IMAGEMANAGER->findImage("���ù�ư(�⺻)");
				_saveGameImage2 = IMAGEMANAGER->findImage("���ù�ư(��)");
			}
		}
		else
		{
			_saveGameImage0 = _saveGameImage1 = _saveGameImage2 = IMAGEMANAGER->findImage("���ù�ư(�⺻)");
		}
		break;
	case STARTPAGE::OPEN:
		_leftDoorPos -= 10;
		_rightDoorPos += 10;
		if (_leftDoorPos < -470 && _rightDoorPos > 700)
		{
			_leftDoorPos = -470;
			_rightDoorPos = 700;
			_currentPage = STARTPAGE::READY;
		}
		break;
	case STARTPAGE::CLOSE_FOR_MAIN:
		_leftDoorPos += 10;
		_rightDoorPos -= 10;
		if (_leftDoorPos > -110 && _rightDoorPos < 340)
		{
			_leftDoorPos = -110;
			_rightDoorPos = 340;
			SCENEMANAGER->loadMainPage(_selectSlotNum);
		}
		break;
	}
}
void startPage::render(void)
{
	switch (_currentPage)
	{
	case STARTPAGE::READYSELECT:
	case STARTPAGE::READY:
		_startPageImage->render(getMemDC());
		_creditImage->render(getMemDC(), (WINSIZEX / 2) - _creditImage->getWidth() / 2, _creditButtonPos);
		_startImage->render(getMemDC(), (WINSIZEX / 2) - _startImage->getWidth() / 2, _startButtonPos);
		_titleImage->render(getMemDC(), (WINSIZEX / 2) - _titleImage->getWidth() / 2, 40);
		break;
	case STARTPAGE::SETSELECT:
		_startPageImage->render(getMemDC());
		_selectBoardImage->render(getMemDC(), (WINSIZEX / 2) - _selectBoardImage->getWidth() / 2, _selectBoardPos);
		_saveGameImage0->render(getMemDC(), (WINSIZEX /2) - _saveGameImage0->getWidth() / 2, _selectBoardPos + 48);
		_saveGameImage1->render(getMemDC(), (WINSIZEX / 2) - _saveGameImage1->getWidth() / 2, _selectBoardPos + 65 + 48);
		_saveGameImage2->render(getMemDC(), (WINSIZEX / 2) - _saveGameImage2->getWidth() / 2, _selectBoardPos + 130 + 48);
		_titleImage->render(getMemDC(), (WINSIZEX / 2) - _titleImage->getWidth() / 2, 40);
		break;
	case STARTPAGE::SELECT:
		_startPageImage->render(getMemDC());
		_selectBoardImage->render(getMemDC(), (WINSIZEX / 2) - _selectBoardImage->getWidth() / 2, 335);
		_saveGameImage0->render(getMemDC(), (WINSIZEX / 2) - _saveGameImage0->getWidth() / 2, 335 + 48);
		_saveGameImage1->render(getMemDC(), (WINSIZEX / 2) - _saveGameImage1->getWidth() / 2, 335 + 65 + 48);
		_saveGameImage2->render(getMemDC(), (WINSIZEX / 2) - _saveGameImage2->getWidth() / 2, 335 + 130 + 48);
		_titleImage->render(getMemDC(), (WINSIZEX / 2) - _titleImage->getWidth() / 2, 40);
		break;
	case STARTPAGE::START:
		_startPageImage->render(getMemDC());
		_creditImage->render(getMemDC(), (WINSIZEX / 2) - _creditImage->getWidth() / 2, 485);
		_startImage->render(getMemDC(), (WINSIZEX / 2) - _startImage->getWidth() / 2, 385);
		_titleImage->render(getMemDC(), (WINSIZEX / 2) - _titleImage->getWidth() / 2, 40);
		break;
	case STARTPAGE::CLOSE_FOR_MAIN:
		_startPageImage->render(getMemDC());
		_selectBoardImage->render(getMemDC(), (WINSIZEX / 2) - _selectBoardImage->getWidth() / 2, 335);
		_saveGameImage0->render(getMemDC(), (WINSIZEX / 2) - _saveGameImage0->getWidth() / 2, 335 + 48);
		_saveGameImage1->render(getMemDC(), (WINSIZEX / 2) - _saveGameImage1->getWidth() / 2, 335 + 65 + 48);
		_saveGameImage2->render(getMemDC(), (WINSIZEX / 2) - _saveGameImage2->getWidth() / 2, 335 + 130 + 48);
		_titleImage->render(getMemDC(), (WINSIZEX / 2) - _titleImage->getWidth() / 2, 40);
		_leftDoorImage->render(getMemDC(), _leftDoorPos, -20);
		_rightDoorImage->render(getMemDC(), _rightDoorPos, -20);
		break;
	case STARTPAGE::CLOSE_FOR_CREDIT:
		_startPageImage->render(getMemDC());
		_creditImage->render(getMemDC(), (WINSIZEX / 2) - _creditImage->getWidth() / 2, 485);
		_startImage->render(getMemDC(), (WINSIZEX / 2) - _startImage->getWidth() / 2, 385);
		_titleImage->render(getMemDC(), (WINSIZEX / 2) - _titleImage->getWidth() / 2, 40);
		_leftDoorImage->render(getMemDC(), _leftDoorPos, -20);
		_rightDoorImage->render(getMemDC(), _rightDoorPos, -20);
		break;
	case STARTPAGE::OPEN:
		_startPageImage->render(getMemDC());

		_leftDoorImage->render(getMemDC(), _leftDoorPos, -20);
		_rightDoorImage->render(getMemDC(), _rightDoorPos, -20);
		
		break;
	}
}