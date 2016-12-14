#include "stdafx.h"
#include "prograssBar.h"
prograssBar::prograssBar()
{
}
prograssBar::~prograssBar()
{
}


//ü�¹� �ʱ�ȭ
HRESULT prograssBar::init(char* frontImage, char* BackImage, float x, float y, int width, int height)
{
	//ü�¹� ��ġ �ʱ�ȭ
	_x = x;
	_y = y;

	//ü�¹� ��Ʈ �ʱ�ȭ
	_rcPrograss = RectMake(x, y, width, height);

	//Ű���̹��� �̸� 

	//ü�¹� �̹��� �ʱ�ȭ
	_prograssBarFront = new image;
	_prograssBarFront->init(frontImage, x, y, width, height, TRUE, RGB(255, 0, 255));
	_prograssBarBack = new image;
	_prograssBarBack->init(BackImage, x, y, width, height, TRUE, RGB(255, 0, 255));

	//���α��� �ʱ�ȭ
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
	//���α׷��� �� ���(�����ʿ� x)
	_prograssBarBack->render(getMemDC(),
		_rcPrograss.left,
		_y,
		0, 0,
		_prograssBarBack->getWidth(),
		_prograssBarBack->getHeight());
	//���α׷����� ����(���α��̸� �����ؾ��Ѵ�.
	_prograssBarFront->render(getMemDC(),
		_rcPrograss.left, _y,
		0, 0,
		_width,					//�̰��� �����
		_prograssBarFront->getHeight());
}

//���α׷����� ������ ����(�ʱ�ȭ�� �� �����)
void prograssBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _prograssBarFront->getWidth();
}
