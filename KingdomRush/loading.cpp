#include "stdafx.h"
#include "loading.h"
//==================================================================
//		## loadItem ## �ε������
//==================================================================

//Ű������ �� ��Ʈ�� �ʱ�ȭ
HRESULT loadItem::initForImage(string keyName, int width, int height)
{
	_kind = LOAD_KIND_IMAGE_0;

	//�̹��� ����ü �ʱ�ȭ
	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.width = width;
	_imageResource.height = height;

	return S_OK;
}

//Ű������ �̹��� ���� �ʱ�ȭ(�ַ� ���)
HRESULT loadItem::initForImage(string keyName, const char* fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{
	_kind = LOAD_KIND_IMAGE_1;

	//�̹��� ����ü �ʱ�ȭ
	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForImage(string keyName, const char* fileName, int x, int y, int width, int height, BOOL isTrans, COLORREF transColor)
{
	_kind = LOAD_KIND_IMAGE_2;

	//�̹��� ����ü �ʱ�ȭ
	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}


//Ű������ ������ �̹��� ���� �ʱ�ȭ
HRESULT loadItem::initForFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL isTrans, COLORREF transColor)
{
	_kind = LOAD_KIND_FRAMEIMAGE_0;

	//�̹��� ����ü �ʱ�ȭ
	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForFrameImage(string keyName, const char* fileName, int x, int y, int width, int height, int frameX, int frameY, BOOL isTrans, COLORREF transColor)
{
	_kind = LOAD_KIND_FRAMEIMAGE_0;

	//�̹��� ����ü �ʱ�ȭ
	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}

//���� �ʱ�ȭ
HRESULT loadItem::initForSound(string keyName, const char* fileName, bool bgm, bool loop)
{
	_kind = LOAD_KIND_SOUND;

	//���� ����ü �ʱ�ȭ
	memset(&_soundResource, 0, sizeof(tagSoundResource));

	_soundResource.keyName = keyName;
	_soundResource.fileName = fileName;
	_soundResource.bgm = bgm;
	_soundResource.loop;

	return S_OK;
}


//==================================================================
//		## loading ## �ε�Ŭ����
//==================================================================
HRESULT loading::init(void)
{ 
	//�ε�ȭ�� ��׶��� �ʱ�ȭ
	_background = IMAGEMANAGER->addImage("bgLoadind", "bgLoadind.bmp", WINSIZEX, WINSIZEY);

	//�ε��� �ʱ�ȭ
	_loadingBar = new prograssBar;
	//����(�����̸��� �ְ� .bmp�ڵ����� ������)
	_loadingBar->init("loadingBarFront.bmp", "loadingBarBack.bmp", 100, 430, 600, 20);
	_loadingBar->setGauge(0, 0);
	_currentGauge = 0;

	return S_OK;
}

void loading::release(void)
{
	//�ε��� ����
	SAFE_DELETE(_loadingBar);
}

void loading::update(void)
{
	//�ε��� ����
	_loadingBar->update();
}

void loading::render(void)
{
	//��׶���
	_background->render(getMemDC());

	//�ε���
	_loadingBar->render();
}


void loading::loadImage(string keyName, int width, int height)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, width, height);

	_vLoadItem.push_back(item);
}

void loading::loadImage(string keyName, const char* fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, fileName, width, height, isTrans, transColor);

	_vLoadItem.push_back(item);
}

void loading::loadImage(string keyName, const char* fileName, int x, int y, int width, int height, BOOL isTran, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, fileName, x, y, width, height, isTran, transColor);

	_vLoadItem.push_back(item);
}

void loading::loadFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForFrameImage(keyName, fileName, width, height, frameX, frameY, isTrans, transColor);

	_vLoadItem.push_back(item);
}

void loading::loadFrameImage(string keyName, const char* fileName, int x, int y, int width, int height, int frameX, int frameY, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForFrameImage(keyName, fileName, x, y, width, height, frameX, frameY, isTrans, transColor);

	_vLoadItem.push_back(item);
}


//�ε����
void loading::loadSound(string keyName, const char* fileName, bool bgm, bool loop)
{
	loadItem* item = new loadItem;
	item->initForSound(keyName, fileName, bgm, loop);

	_vLoadItem.push_back(item);
}


//�߿�!!
//�ε��� �Ϸ� �Ƴ�?(�̰� Ȯ���ϰ� ������)
BOOL loading::loadingDone(void)
{
	if (_currentGauge >= _vLoadItem.size())
	{
		return TRUE;
	}

	loadItem* item = _vLoadItem[_currentGauge];
	switch (item->getLoadingKind())
	{
		case LOAD_KIND_IMAGE_0:
		{
			tagImageResource img = item->getImageResource();
			IMAGEMANAGER->addImage(img.keyName, img.width, img.height);
		}
			break;
		case LOAD_KIND_IMAGE_1:
		{
			tagImageResource img = item->getImageResource();
			IMAGEMANAGER->addImage(img.keyName, img.fileName, img.width, img.height, img.trans, img.transColor);
		}
			break;
		case LOAD_KIND_IMAGE_2:
		{
			tagImageResource img = item->getImageResource();
			IMAGEMANAGER->addImage(img.keyName, img.fileName, img.x, img.y, img.width, img.height, img.trans, img.transColor);
		}
			break;
		case LOAD_KIND_FRAMEIMAGE_0:
		{
			tagImageResource img = item->getImageResource();
			IMAGEMANAGER->addFrameImage(img.keyName, img.fileName, img.width, img.height, img.frameX, img.frameY, img.trans, img.transColor);
		}
			break;
		case LOAD_KIND_FRAMEIMAGE_1:
		{
			tagImageResource img = item->getImageResource();
			IMAGEMANAGER->addFrameImage(img.keyName, img.fileName, img.x, img.y, img.width, img.height, img.frameX, img.frameY, img.trans, img.transColor);
		}
			break;

		case LOAD_KIND_SOUND:
		{
			tagSoundResource soundResource = item->getSoundResource();
			SOUNDMANAGER->addSound(soundResource.keyName, soundResource.fileName, soundResource.bgm, soundResource.loop);
		}
			break;
	}

	//�ε��� �̹��� ����
	_loadingBar->setGauge(_currentGauge, _vLoadItem.size());

	//ī��Ʈ
	_currentGauge++;

	return FALSE;
}
