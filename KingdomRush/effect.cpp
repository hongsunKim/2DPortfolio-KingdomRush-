#include "stdafx.h"
#include "effect.h"
effect::effect() : _effectImage(NULL), _effectAni(NULL), _isRunnig(false), _x(0), _y(0)
{
}
effect::~effect()
{
}


HRESULT effect::init(image* effectImage, int frameW, int frameH, int FPS, float elapsedTime)
{
	//�̹��� ������ ����
	if (!effectImage) return E_FAIL;

	//���� �ʱ�ȭ
	_effectImage = effectImage;
	_elapsedTime = elapsedTime;
	_isRunnig = false;

	//����Ʈ ���� ���� ����
	if (!_effectAni) _effectAni = new animation;
	//���� �ʱ�ȭ
	_effectAni->init(_effectImage->getWidth(), _effectImage->getHeight(), frameW, frameH);
	_effectAni->setDefPlayFrame();
	_effectAni->setFPS(FPS);

	return S_OK;
}

void effect::release(void)
{
	SAFE_DELETE(_effectAni);
}

void effect::update(void)
{
	if (_isRunnig)
	{
		_effectAni->frameUpdate(_elapsedTime);
	}

	//���ϰ� ����Ǹ� �����
	if (!_effectAni->isPlay()) stopEffect();
}

void effect::render(void)
{
	if (_isRunnig) _effectImage->aniRender(getMemDC(), _x, _y, _effectAni);
}

//����Ʈ ��Ʈ�� ��ġ
void effect::startEffect(int x, int y)
{
	//��ġ��ǥ�� ���ͷ�
	_x = x - (_effectAni->getFrameWidth() / 2);
	_y = y - (_effectAni->getFrameHeight() / 2);

	_isRunnig = true;
	_effectAni->start();
}

//����Ʈ ����
void effect::stopEffect(void)
{
	_isRunnig = false;
}