#include "stdafx.h"
#include "scene2.h"


scene2::scene2()
{
}


scene2::~scene2()
{
}



HRESULT scene2::init(void)
{
	wsprintf(_text, "2¹ø ¾ÀÀÌ´Ù~!!!");

	return S_OK;
}

void scene2::release(void)
{

}

void scene2::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		//¾Àº¯°æ
		SCENEMANAGER->changeScene("scene1");
	}
}

void scene2::render(void)
{
	TextOut(getMemDC(), 200, 200, _text, strlen(_text));
}