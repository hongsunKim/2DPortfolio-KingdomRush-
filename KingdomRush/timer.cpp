#include "stdafx.h"
#include "timer.h"
//timeGetTime �Լ��� ����ϱ� ���� ���̺귯�� �߰�
//�����찡 ���۵ǰ� ���� �ð��� ������
#include <mmsystem.h>
#pragma  comment(lib, "winmm.lib")

timer::timer()
{
}
timer::~timer()
{
}



//Ÿ�̸� �ʱ�ȭ
HRESULT timer::init(void)
{
	//���� Ÿ�̸� �������� üũ
	//���� Ÿ�̸Ӹ� �����ϸ� �ʴ� ����ũ�μ�������� ���� ����(1 / 1000000)
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency))
	{
		_isHardward = true;
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

		//�ʴ� �ð���� ����
		_timeScale = 1.0f / _periodFrequency;
	}
	else
	{
		_isHardward = false;
		//�и������� ������ �ð����� ī��Ʈ
		_lastTime = timeGetTime();
		_timeScale = 0.001f;
	}

	//Ÿ�̸� ���� ���� �ʱ�ȭ
	_frameRate = 0;
	_FPSTimeElapsed = 0.0f;
	_FPSFrameCount = 0;
	_worldTime = 0.0f;

	return S_OK;
}


//����ð� ���
void timer::tick(float lockFPS)
{
	//���� Ÿ�̸Ӹ� �����Ѵٸ�
	if (_isHardward)
	{
		//����ũ�μ��� ������ ����Ѵ�.
		QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	}
	else
	{
		//�� time�Լ��� �̿��Ѵ�.
		_curTime = timeGetTime();
	}

	//�������ð��� ����ð��� �����
	_timeElapsed = (_curTime - _lastTime) * _timeScale;

	if (lockFPS > 0.0f)
	{
		while (_timeElapsed < (1.0f / lockFPS))
		{
			if (_isHardward) QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			else _curTime = timeGetTime();

			//������ �ð��� ����ð��� �����
			_timeElapsed = (_curTime - _lastTime) * _timeScale;
		}
	}

	_lastTime = _curTime;
	_FPSFrameCount++;
	_FPSTimeElapsed += _timeElapsed;
	_worldTime += _timeElapsed;

	//������ �ʱ�ȭ�� 1�ʸ��� �����ϱ�
	if (_FPSTimeElapsed > 1.0f)
	{
		_frameRate = _FPSFrameCount;
		_FPSFrameCount = 0;
		_FPSTimeElapsed = 0.0f;
	}
}

//���� FPS ��������
unsigned long timer::getFrameRate(char* str) const
{
	if (str != NULL)
	{
		wsprintf(str, "FPS: %d", _frameRate);
	}

	return _frameRate;
}