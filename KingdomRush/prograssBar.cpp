#include "stdafx.h"
#include "prograssBar.h"
prograssBar::prograssBar()
{
}
prograssBar::~prograssBar()
{
}


//체력바 초기화
HRESULT prograssBar::init(char* frontImage, char* BackImage, float x, float y, int width, int height)
{
	//체력바 위치 초기화
	_x = x;
	_y = y;

	//체력바 렉트 초기화
	_rcPrograss = RectMake(x, y, width, height);

	//키값이미지 이름 

	//체력바 이미지 초기화
	_prograssBarFront = new image;
	_prograssBarFront->init(frontImage, x, y, width, height, TRUE, RGB(255, 0, 255));
	_prograssBarBack = new image;
	_prograssBarBack->init(BackImage, x, y, width, height, TRUE, RGB(255, 0, 255));

	//가로길이 초기화
	_width = _prograssBarFront->getWidth();

	return S_OK;
}

void prograssBar::release(void)
{
	SAFE_DELETE(_prograssBarFront);
	SAFE_DELETE(_prograssBarBack);
}

void prograssBar::update(void)
{
	_rcPrograss = RectMakeCenter(
		_x + _prograssBarBack->getWidth() / 2,
		_y + _prograssBarBack->getHeight() / 2,
		_prograssBarBack->getWidth(),
		_prograssBarBack->getHeight());
}

void prograssBar::render(void)
{
	//프로그래스 바 배경(변경필요 x)
	_prograssBarBack->render(getMemDC(),
		_rcPrograss.left,
		_y,
		0, 0,
		_prograssBarBack->getWidth(),
		_prograssBarBack->getHeight());
	//프로그래스바 전경(가로길이를 변경해야한다.
	_prograssBarFront->render(getMemDC(),
		_rcPrograss.left, _y,
		0, 0,
		_width,					//이값이 변경됨
		_prograssBarFront->getHeight());
}

//프로그래스바 게이지 세팅(초기화시 꼭 해줘야)
void prograssBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _prograssBarFront->getWidth();
}
