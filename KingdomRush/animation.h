#pragma once
//==================================================================
//		## animation ## (���ϸ��̼� Ŭ����)
//==================================================================

class animation
{
private:
	typedef vector<POINT> _vFrameList;		//������ ���� ������ ����
	typedef vector<int> _vPlayList;			//������ �÷��� ���

private:
	int _frameNum;			//������ ����
	_vFrameList _frameList;	//������ ��ġ
	_vPlayList _playList;	//������ ���

	int _frameWidthNum;		//���� ������ ��
	int _frameHeightNum;	//���� ������ ��

	int _frameWidth;		//������ ����ũ��
	int _frameHeight;		//������ ����ũ��
	BOOL _loop;				//������?

	float _frameUpdateSec;	//������ ���� ��
	float _elapsedSec;		//������ ��� ��
	DWORD _nowPlayIdx;		//���� �÷��� �ε���(�÷��̸���Ʈ �� ����)
	BOOL _play;				//���� �÷��� ����

	int _y;					//���� ������� ������ y(����)�ε��� ��

public:
	//�ʱ�ȭ
	HRESULT init(int totalW, int totalH, int frameX, int frameY);
	void release(void);

	//ó������ ������ ����ϴ� ���ϸ��̼�
	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);
	//�迭�� ��Ƽ� ����ִ� ������
	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);
	//���۰� �� ������ ���ؼ� �ִϸ��̼� ����
	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);

	//������ ��ȣ ���ؼ� �Ϸķ� ���
	void setPlayX(int y, BOOL loop = FALSE);

	//�ʴ� ���� Ƚ��
	void setFPS(int framePerSec);
	//������ ������Ʈ
	void frameUpdate(float elapsedTime);

	//���� �÷���
	void start(void);
	//���� ����
	void stop(void);
	//���� �Ͻ�����
	void pause(void);
	//���� �ٽ����
	void resume(void);

	//����
	inline BOOL isPlay(void) { return _play; }
	inline POINT getFramePos(void) { return _frameList[_playList[_nowPlayIdx]]; }
	inline int getFrameWidth(void) { return _frameWidth; }
	inline int getFrameHeight(void) { return _frameHeight; }
	inline int getXNum(void) { return _frameWidthNum; }
	inline int getYNum(void) { return _frameHeightNum; }

	animation();
	~animation();
};

