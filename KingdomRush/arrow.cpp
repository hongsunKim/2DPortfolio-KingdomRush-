#include "stdafx.h"
#include "arrow.h"


arrow::arrow()
{
}


arrow::~arrow()
{
}

HRESULT arrow::init(void)
{

	return S_OK;
}

HRESULT arrow::init(float x, float y, bool isRight,  float targetX, float targetY)
{
	//목표 도달 프레임 수: 60
	_aimFrame = 15;

	_targetX = targetX;
	_targetY = targetY;

	if (isRight)
	{
		_lastX = _x = x;
		_lastY = _y = y - 40;
	}
	else
	{
		_lastX = _x = x;
		_lastY = _y = y - 40;
	}

	float tempRadius = getDistance(x, y, targetX, targetY) / 5;
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
	
	_speedX = (targetX - _x) / (_aimFrame + tempNum) * 150;// getDistance(x, y, targetX, targetY) / 80;
	

	_arrowImage.init("image/유닛/궁수/화살.bmp", 264, 11, 24, 1, TRUE, RGB(1, 0, 0));

	//샷타임 증가는 업데이트에서... 증가량 수정필요
	_shotTime = 0;

	_isArrived = false;
	_lastingTime = 0;
	_remove = false;
	_isDropping = false;


	return S_OK;
}

void arrow::release(void)
{
	_arrowImage.release();
}
void arrow::updateNormal(void)
{
	//샷타임 증가량 수정필요
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

	if ( _isDropping == true && _y >= _targetY)
	{
		_isArrived = true;
	}
	
	if (_isArrived)
	{
		++_lastingTime;
		if (_lastingTime > 120)
		{
			_remove = true;
		}
	}
}
void arrow::updateOnceUp(void)
{

}
void arrow::updateOnceDn(void)
{

}
void arrow::updateStayDn(void)
{

}
void arrow::renderObject(HDC getMemDC)
{
	_arrowImage.frameRender(getMemDC, _x, _y, int((_angle / (PI / 180)) / 15), 1);
}
void arrow::renderUI(HDC getMemDC)
{

}

void arrow::setBelongedArcher(archer* belongedArcher)
{
	////_arrowImage.init()
	//_belongedArcher = belongedArcher;
	//_x = _belongedArcher->getX();
	//_y = _belongedArcher->getY();
	//if (_belongedArcher->getIsRight())
	//	_angle = PI / 12;
	//else
	//	_angle = PI / 12 * 11;
	//_target = _belongedArcher->getTarget();
	//_targetX = _target->getX();
	//_targetY = _target->getY();
	////스피드도 수정필요
	//_speed = (_targetX - _x) / 30;
	////수정필요
	//_gravity = 0.1;
	////샷타임의 증가분도 수정필요
	//_shotTime = 0;
	//_isArrived = false;
	//_lastingTime = 0;
	//_remove = false;
}
void arrow::setTarget(enemyUnitBase* target)
{

}

float arrow::sum(float num)
{
	float tempSum = 0;
	do {
		tempSum += num;
		num -= 1;
	} while (num > 0);

	return tempSum;
}