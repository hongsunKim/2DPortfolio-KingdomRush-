#include "stdafx.h"
#include "creditPage.h"


creditPage::creditPage()
{
}

creditPage::~creditPage()
{
}

HRESULT creditPage::init(void)
{
	_creditPage = CREDITPAGE::OPEN;

	_creditImage = IMAGEMANAGER->addImage("ũ����", "image/ũ����������/ũ����.bmp", 700, 600, FALSE, RGB(1, 0, 0));

	_backButtonImage = IMAGEMANAGER->addImage("�ڷι�ư(�⺻)", "image/ũ����������/�ڷι�ư(�⺻).bmp", 98, 43, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("�ڷι�ư(��)", "image/ũ����������/�ڷι�ư(��).bmp", 98, 43, TRUE, RGB(1, 0, 0));
	_backButtonRect = RectMake((WINSIZEX / 2) - (_backButtonImage->getWidth() / 2), 540, _backButtonImage->getWidth(), _backButtonImage->getHeight());

	_leftDoorImage = IMAGEMANAGER->findImage("���ʹ�");
	_rightDoorImage = IMAGEMANAGER->findImage("�����ʹ�");
	_leftDoorPos = -110;
	_rightDoorPos = 340;

	return S_OK;
}
void creditPage::release(void)
{

}
void creditPage::update(void)
{
	switch (_creditPage)
	{
	case CREDITPAGE::OPEN:
		_leftDoorPos -= 10;
		_rightDoorPos += 10;
		if (_leftDoorPos < -470 && _rightDoorPos > 700)
		{
			_leftDoorPos = -470;
			_rightDoorPos = 700;
			_creditPage = CREDITPAGE::CREDIT;
		}
		break;
	case CREDITPAGE::CREDIT:
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			if (PtInRect(&_backButtonRect, _ptMouse))
			{
				_creditPage = CREDITPAGE::CLOSE;
			}
		}
		if (PtInRect(&_backButtonRect, _ptMouse))
		{
			_backButtonImage = IMAGEMANAGER->findImage("�ڷι�ư(��)");
		}
		else
		{
			_backButtonImage = IMAGEMANAGER->findImage("�ڷι�ư(�⺻)");
		}
		break;
	case CREDITPAGE::CLOSE:
		_leftDoorPos += 10;
		_rightDoorPos -= 10;
		if (_leftDoorPos > -110 && _rightDoorPos < 340)
		{
			_leftDoorPos = -110;
			_rightDoorPos = 340;
			SCENEMANAGER->changeScene("����ȭ��");
		}
		break;
	}
}
void creditPage::render(void)
{
	switch (_creditPage)
	{
	case CREDITPAGE::OPEN:
		_creditImage->render(getMemDC());
		_backButtonImage->render(getMemDC(), (WINSIZEX / 2) - (_backButtonImage->getWidth() / 2), 540);
		_leftDoorImage->render(getMemDC(), _leftDoorPos, -20);
		_rightDoorImage->render(getMemDC(), _rightDoorPos, -20);
		break;
	case CREDITPAGE::CREDIT:
		_creditImage->render(getMemDC());
		_backButtonImage->render(getMemDC(), (WINSIZEX / 2) - (_backButtonImage->getWidth() / 2), 540);
		break;
	case CREDITPAGE::CLOSE:
		_creditImage->render(getMemDC());
		_backButtonImage->render(getMemDC(), (WINSIZEX / 2) - (_backButtonImage->getWidth() / 2), 540);
		_leftDoorImage->render(getMemDC(), _leftDoorPos, -20);
		_rightDoorImage->render(getMemDC(), _rightDoorPos, -20);
		break;
	}
}