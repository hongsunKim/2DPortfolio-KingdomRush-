#include "stdafx.h"
#include "scene1.h"


scene1::scene1()
{
}


scene1::~scene1()
{
}


HRESULT scene1::init(void)
{
	wsprintf(_text, "1¹ø ¾ÀÀÌ´Ù~!!!");

	return S_OK;
}

void scene1::release(void)
{

}

void scene1::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		//¾Àº¯°æ
		SCENEMANAGER->changeScene("scene2");
	}
}

void scene1::render(void)
{
	TextOut(getMemDC(), 100, 100, _text, strlen(_text));
}

