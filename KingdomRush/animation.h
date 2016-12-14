#pragma once
//==================================================================
//		## animation ## (에니메이션 클래스)
//==================================================================

class animation
{
private:
	typedef vector<POINT> _vFrameList;		//프레임 임의 접근을 위해
	typedef vector<int> _vPlayList;			//프레임 플레이 목록

private:
	int _frameNum;			//프레임 갯수
	_vFrameList _frameList;	//프레임 위치
	_vPlayList _playList;	//프레임 목록

	int _frameWidthNum;		//가로 프레임 수
	int _frameHeightNum;	//세로 프레임 수

	int _frameWidth;		//프레임 가로크기
	int _frameHeight;		//프레임 세로크기
	BOOL _loop;				//루프냐?

	float _frameUpdateSec;	//프레임 업뎃 초
	float _elapsedSec;		//프레임 경과 초
	DWORD _nowPlayIdx;		//현재 플레이 인덱스(플레이리스트 값 참조)
	BOOL _play;				//현재 플레이 여부

	int _y;					//현재 재생중인 라인의 y(세로)인덱스 값

public:
	//초기화
	HRESULT init(int totalW, int totalH, int frameX, int frameY);
	void release(void);

	//처음부터 끝까지 재생하는 에니메이션
	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);
	//배열에 담아서 담겨있는 구간만
	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);
	//시작과 끝 구간을 정해서 애니메이션 세팅
	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);

	//세로행 번호 정해서 일렬로 재생
	void setPlayX(int y, BOOL loop = FALSE);

	//초당 갱신 횟수
	void setFPS(int framePerSec);
	//프레임 업데이트
	void frameUpdate(float elapsedTime);

	//에니 플레이
	void start(void);
	//에니 정지
	void stop(void);
	//에니 일시정지
	void pause(void);
	//에니 다시재생
	void resume(void);

	//겟터
	inline BOOL isPlay(void) { return _play; }
	inline POINT getFramePos(void) { return _frameList[_playList[_nowPlayIdx]]; }
	inline int getFrameWidth(void) { return _frameWidth; }
	inline int getFrameHeight(void) { return _frameHeight; }
	inline int getXNum(void) { return _frameWidthNum; }
	inline int getYNum(void) { return _frameHeightNum; }

	animation();
	~animation();
};

