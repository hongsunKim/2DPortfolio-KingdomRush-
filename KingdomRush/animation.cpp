#include "stdafx.h"
#include "animation.h"
animation::animation() : _frameNum(0), _frameWidth(0), _frameHeight(0), _loop(FALSE), _elapsedSec(0), _nowPlayIdx(0), _play(FALSE)
{
}
animation::~animation()
{
}

HRESULT animation::init(int totalW, int totalH, int frameX, int frameY)
{
	//����������
	if (_frameWidth == totalW / frameX && _frameWidth == frameX && _frameHeight == totalH / frameY && _frameHeightNum == frameY) {}
	else
	{
		_frameWidth = totalW / frameX;
		_frameWidthNum = frameX;
		//����������
		_frameHeight = totalH / frameY;
		_frameHeightNum = frameY;

		//�� ������ �� 
		_frameNum = _frameWidthNum * _frameHeightNum;

		//������ ��ġ ��� �����ϱ�
		_frameList.clear();
		for (int i = 0; i < _frameHeightNum; i++)
		{
			for (int j = 0; j < _frameWidthNum; j++)
			{
				POINT framePos;
				framePos.x = j * _frameWidth;
				framePos.y = i * _frameHeight;

				//������ ��ġ ��� �߰�
				_frameList.push_back(framePos);
			}
		}

		//�⺻ ���������� ����
		setDefPlayFrame();
	}
	return S_OK;
}

void animation::release(void)
{

}


//ó������ ������ ����ϴ� ���ϸ��̼�
void animation::setDefPlayFrame(BOOL reverse, BOOL loop)
{
	//��������
	_loop = loop;

	//�÷��� ��� �ʱ�ȭ
	_playList.clear();

	if (reverse)
	{
		if (_loop)//������ �� 1�� �ε��� ����
		{
			//������
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			//������
			for (int i = _frameNum - 2; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			//������
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			//������
			for (int i = _frameNum - 2; i >= 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else//������
	{
		for (int i = 0; i < _frameNum; i++)
		{
			_playList.push_back(i);
		}
	}
}

void animation::setPlayX(int y, BOOL loop)
{
	if (_y == y)
	{
	}
	else
	{
		//��������
		_loop = loop;

		//�÷��� ��� �ʱ�ȭ
		_playList.clear();

		for (int i = y*_frameWidthNum; i < (y + 1) * _frameWidthNum; i++)
		{
			_playList.push_back(i);
		}
		if (_playList.size() <= _nowPlayIdx)
			_nowPlayIdx = 0;
	}
}

//�迭�� ��Ƽ� ����ִ� ������
void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop)
{
	//����
	_loop = loop;
	//�÷��̸�� �ʱ�ȭ
	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}
}

//���۰� �� ������ ���ؼ� �ִϸ��̼� ����
void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop)
{
	//����
	_loop = loop;
	//�÷��̸�� �ʱ�ȭ
	_playList.clear();

	//���۰� ���� ���� ���� ����� �ʿ� ����.
	if (start == end)
	{
		_playList.clear();
		stop();
		return;
	}
	else if (start > end)//���� �������� ���� ������ ���� ū���
	{
		if (reverse)
		{
			if (_loop)//������ �� 1�� �ε��� ����
			{
				//������
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
				//������
				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
			else//������ �� 0�� �ε��� ����
			{
				//������
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
				//������
				for (int i = end + 1; i <= start; i++)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			//������
			for (int i = start; i >= end; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else//��ŸƮ�� ���庸�� ������(�Ϲ����� ���)
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i <= end; i++)
				{
					_playList.push_back(i);
				}
				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i <= end; i++)
				{
					_playList.push_back(i);
				}
				for (int i = end - 1; i >= start; i--)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			for (int i = start; i <= end; i++)
			{
				_playList.push_back(i);
			}
		}
	}
}


//�ʴ� ���� Ƚ��
void animation::setFPS(int framePerSec)
{
	_frameUpdateSec = 1.0f / framePerSec;
}

//������ ������Ʈ
void animation::frameUpdate(float elapsedTime)
{
	//�÷��� ���̳�?
	if (_play)
	{
		_elapsedSec += elapsedTime;

		//������ ���� �ð��� �Ǿ��ٸ�
		if (_elapsedSec >= _frameUpdateSec)
		{
			_elapsedSec -= _frameUpdateSec;
			_nowPlayIdx++;
			if (_nowPlayIdx == _playList.size())
			{
				if (_loop)
				{
					_nowPlayIdx = 0;
				}
				else
				{
					_nowPlayIdx--;
					_play = FALSE;
				}
			}
		}
	}
}


//���� �÷���
void animation::start(void)
{
	if (this->isPlay()) {}
	else
	{
		_play = TRUE;
		_nowPlayIdx = 0;
	}
}

//���� ����
void animation::stop(void)
{
	_play = FALSE;
	_nowPlayIdx = 0;
}

//���� �Ͻ�����
void animation::pause(void)
{
	_play = FALSE;
}

//���� �ٽ����
void animation::resume(void)
{
	_play = TRUE;
}