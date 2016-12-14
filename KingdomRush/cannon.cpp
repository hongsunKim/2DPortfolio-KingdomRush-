#include "stdafx.h"
#include "cannon.h"


cannon::cannon()
{
}


cannon::~cannon()
{
}

HRESULT cannon::init(void)
{
	return S_OK;
}
HRESULT cannon::init(float x, float y, float targetX, float targetY)
{
	_cannonImage = IMAGEMANAGER->findImage("Æ÷Åº");
	_explode = IMAGEMANAGER->findImage("Æ÷Åº¿¬±â");
	_explodeAni.init(500, 70, 10, 1);
	_explodeAni.setPlayX(0);
	_explodeAni.setFPS(1);

	_explosionRange = 30;

	_aimFrame = 15;

	_targetX = targetX;
	_targetY = targetY;

	_lastX = _x = x;
	_lastY = _y = y - 40;

	float tempRadius = getDistance(x, y, targetX, targetY) / 3;
	float tempAngle = getAngle(x, y, targetX, targetY);

	float tempAimX = _x + tempRadius * cosf(tempAngle);
	float tempAimY = _y - tempRadius - tempRadius * sinf(tempAngle);

	_speedY = (tempAimY - y) / ((_aimFrame + 1) - sum(_aimFrame) / _aimFrame);

	_gravity = _speedY / _aimFrame;

	float tempNum = 0;
	for (tempNum = 0; ; tempNum += 1)
	{
		if (sum(tempNum) <= abs((_targetY - tempAimY) / (-_gravity)) && abs((_targetY - tempAimY) / (-_gravity)) <= sum(tempNum + 1))
		{
			break;
		}
	}

	_speedX = (targetX - _x) / (_aimFrame + tempNum) * 150;

	_shotTime = 0;

	_isArrived = false;
	_lastingTime = 0;
	_remove = false;
	_isDropping = false;
	_dmgCheck = false;

	return S_OK;
}
void cannon::release(void)
{
	_explodeAni.release();
}
void cannon::updateNormal(void)
{
	//¼¦Å¸ÀÓ Áõ°¡·® ¼öÁ¤ÇÊ¿ä
	if (_isArrived == false)
	{
		_lastX = _x;
		_lastY = _y;
		_speedX = (_targetX - _x) / _aimFrame / 2;
		_x = _x + _speedX;
		_speedY -= _gravity;
		_y = _y + _speedY;
		_angle = getAngle(_lastX, _lastY, _x, _y);
		if (_lastY < _y)
		{
			_isDropping = true;
		}
		_aimFrame -= 0.4;
	}

	if (_isDropping == true && _y >= _targetY)
	{
		_isArrived = true;
	}

	if (_isArrived)
	{
		_explodeAni.frameUpdate(0.2);
		_explodeAni.start();
		if (_explodeAni.getFramePos().x == 450)
		{
			_remove = true;
		}
	}
}
void cannon::updateOnceUp(void)
{

}
void cannon::updateOnceDn(void)
{

}
void cannon::updateStayDn(void)
{

}
void cannon::renderObject(HDC getMemDC)
{
	
}
void cannon::renderUI(HDC getMemDC)
{
	if (!_isArrived)
		_cannonImage->render(getMemDC, _x - 6, _y - 6);
	if (_isArrived)
		_explode->aniRender(getMemDC, _x - 25, _y - 58, &_explodeAni);
}

float cannon::sum(float num)
{
	float tempSum = 0;
	do {
		tempSum += num;
		num -= 1;
	} while (num > 0);

	return tempSum;
}