#include "stdafx.h"
#include "camel.h"
camel::camel()
{
}
camel::~camel()
{
}


HRESULT camel::init(void)
{
/*

	//��Ÿ�̹��� �ʱ�ȭ
	_camel = IMAGEMANAGER->addImage("camel", "camel.bmp", 300, 267, true, RGB(255, 0, 255));

	//����1 ó������ ������
	_ani1 = new animation;
	_ani1->init(_camel->getWidth(), _camel->getHeight(), 75, 89);
	_ani1->setDefPlayFrame(TRUE, TRUE);
	_ani1->setFPS(1);

	//����2 �迭��
	int arrAni[] = { 0, 2, 4, 6, 8, 10 };
	_ani2 = new animation;
	_ani2->init(_camel->getWidth(), _camel->getHeight(), 75, 89);
	_ani2->setPlayFrame(arrAni, 6, TRUE);
	_ani2->setFPS(1);
	//����3 ��������
	_ani3 = new animation;
	_ani3->init(_camel->getWidth(), _camel->getHeight(), 75, 89);
	_ani3->setPlayFrame(0, 4, FALSE, TRUE);
	_ani3->setFPS(1);
*/
	//�޴��� ���
	_camel = IMAGEMANAGER->addFrameImage("camel", "camel.bmp", 300, 267, 4, 3, true, RGB(255, 0, 255));

	//ó������ ��
	ANIMANAGER->addDefAnimation("ani1", "camel", 1, FALSE, TRUE);

	//�迭
	int arrAni[] = { 1, 3, 5, 7, 9 };
	ANIMANAGER->addAnimation("ani2", "camel", arrAni, 5, 3, TRUE);

	//����
	ANIMANAGER->addAnimation("ani3", "camel", 0, 4, 5, TRUE);

	//���ۿ��� ����
	_ani = ANIMANAGER->findAnimation("ani1");

	return S_OK;
}

void camel::release(void)
{
	/*SAFE_DELETE(_ani1);
	SAFE_DELETE(_ani2);
	SAFE_DELETE(_ani3);*/
}

void camel::update(void)
{
	/*if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_ani1->start();
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_ani2->start();
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_ani3->start();
	}

	_ani1->frameUpdate(0.5f);
	_ani2->frameUpdate(0.2f);
	_ani3->frameUpdate(0.05f);*/
	
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_ani = ANIMANAGER->findAnimation("ani1");
		ANIMANAGER->start("ani1");
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_ani = ANIMANAGER->findAnimation("ani2");
		ANIMANAGER->start("ani2");
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_ani = ANIMANAGER->findAnimation("ani3");
		ANIMANAGER->start("ani3");
	}
}

void camel::render(void)
{
	/*
	_camel->aniRender(getMemDC(), WINSIZEX / 2 - 200, WINSIZEY / 2, _ani1);
	_camel->aniRender(getMemDC(), WINSIZEX / 2 , WINSIZEY / 2, _ani2);
	_camel->aniRender(getMemDC(), WINSIZEX / 2 + 200, WINSIZEY / 2, _ani3);
	*/
	_camel->aniRender(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, _ani);
}

