#include "stdafx.h"
#include "effectMgrTest.h"


effectMgrTest::effectMgrTest()
{
}


effectMgrTest::~effectMgrTest()
{
}

HRESULT effectMgrTest::init(void)
{
	IMAGEMANAGER->addImage("��������Ʈ", "explosion.bmp", 832, 62, TRUE, RGB(255, 0, 255));

	_effect = new effect;
	_effect->init(IMAGEMANAGER->findImage("��������Ʈ"), 32, 62, 1, 0.3f);

	//�޴��� ���
	EFFECTMANAGER->addEffect("����", "explosion.bmp", 832, 62, 32, 62, 1, 0.3f, 100);

	return S_OK;
}

void effectMgrTest::release(void)
{
	SAFE_DELETE(_effect);
}

void effectMgrTest::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_effect->startEffect(_ptMouse.x, _ptMouse.y);
	}
	_effect->update();

	//�޴���
	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	{
		EFFECTMANAGER->play("����", _ptMouse.x, _ptMouse.y);
	}
}

void effectMgrTest::render(void)
{
	_effect->render();
}
