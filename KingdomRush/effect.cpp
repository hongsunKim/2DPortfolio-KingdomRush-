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
	//이미지 없으면 종료
	if (!effectImage) return E_FAIL;

	//변수 초기화
	_effectImage = effectImage;
	_elapsedTime = elapsedTime;
	_isRunnig = false;

	//이펙트 에니 없음 생성
	if (!_effectAni) _effectAni = new animation;
	//에니 초기화
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

	//에니가 종료되면 멈춘다
	if (!_effectAni->isPlay()) stopEffect();
}

void effect::render(void)
{
	if (_isRunnig) _effectImage->aniRender(getMemDC(), _x, _y, _effectAni);
}

//이펙트 터트릴 위치
void effect::startEffect(int x, int y)
{
	//위치좌표를 센터로
	_x = x - (_effectAni->getFrameWidth() / 2);
	_y = y - (_effectAni->getFrameHeight() / 2);

	_isRunnig = true;
	_effectAni->start();
}

//이펙트 멈춤
void effect::stopEffect(void)
{
	_isRunnig = false;
}