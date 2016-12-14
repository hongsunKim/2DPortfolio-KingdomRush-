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
	//가로프레임
	if (_frameWidth == totalW / frameX && _frameWidth == frameX && _frameHeight == totalH / frameY && _frameHeightNum == frameY) {}
	else
	{
		_frameWidth = totalW / frameX;
		_frameWidthNum = frameX;
		//세로프레임
		_frameHeight = totalH / frameY;
		_frameHeightNum = frameY;

		//총 프레임 수 
		_frameNum = _frameWidthNum * _frameHeightNum;

		//프레임 위치 목록 세팅하기
		_frameList.clear();
		for (int i = 0; i < _frameHeightNum; i++)
		{
			for (int j = 0; j < _frameWidthNum; j++)
			{
				POINT framePos;
				framePos.x = j * _frameWidth;
				framePos.y = i * _frameHeight;

				//프레임 위치 목록 추가
				_frameList.push_back(framePos);
			}
		}

		//기본 프레임으로 세팅
		setDefPlayFrame();
	}
	return S_OK;
}

void animation::release(void)
{

}


//처음부터 끝까지 재생하는 에니메이션
void animation::setDefPlayFrame(BOOL reverse, BOOL loop)
{
	//루프여부
	_loop = loop;

	//플레이 목록 초기화
	_playList.clear();

	if (reverse)
	{
		if (_loop)//리버스 후 1번 인덱스 까지
		{
			//정방향
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			//역방향
			for (int i = _frameNum - 2; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			//정방향
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			//역방향
			for (int i = _frameNum - 2; i >= 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else//정방향
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
		//루프여부
		_loop = loop;

		//플레이 목록 초기화
		_playList.clear();

		for (int i = y*_frameWidthNum; i < (y + 1) * _frameWidthNum; i++)
		{
			_playList.push_back(i);
		}
		if (_playList.size() <= _nowPlayIdx)
			_nowPlayIdx = 0;
	}
}

//배열에 담아서 담겨있는 구간만
void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop)
{
	//루프
	_loop = loop;
	//플레이목록 초기화
	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}
}

//시작과 끝 구간을 정해서 애니메이션 세팅
void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop)
{
	//루프
	_loop = loop;
	//플레이목록 초기화
	_playList.clear();

	//시작과 끝이 같은 경우는 재생할 필요 없다.
	if (start == end)
	{
		_playList.clear();
		stop();
		return;
	}
	else if (start > end)//시작 프레임이 종료 프레임 보다 큰경우
	{
		if (reverse)
		{
			if (_loop)//리버스 후 1번 인덱스 까지
			{
				//정방향
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
				//역방향
				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
			else//리버스 후 0번 인덱스 까지
			{
				//정방향
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}
				//역방향
				for (int i = end + 1; i <= start; i++)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			//정방향
			for (int i = start; i >= end; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else//스타트가 엔드보다 작을떄(일반적인 경우)
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


//초당 갱신 횟수
void animation::setFPS(int framePerSec)
{
	_frameUpdateSec = 1.0f / framePerSec;
}

//프레임 업데이트
void animation::frameUpdate(float elapsedTime)
{
	//플레이 중이냐?
	if (_play)
	{
		_elapsedSec += elapsedTime;

		//프레임 업뎃 시간이 되었다면
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


//에니 플레이
void animation::start(void)
{
	if (this->isPlay()) {}
	else
	{
		_play = TRUE;
		_nowPlayIdx = 0;
	}
}

//에니 정지
void animation::stop(void)
{
	_play = FALSE;
	_nowPlayIdx = 0;
}

//에니 일시정지
void animation::pause(void)
{
	_play = FALSE;
}

//에니 다시재생
void animation::resume(void)
{
	_play = TRUE;
}