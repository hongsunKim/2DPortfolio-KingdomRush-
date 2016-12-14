#pragma once
#include "gameNode.h"

//==================================================================
//		## effect ## (����Ʈ Ŭ����)
//==================================================================

class effect : public gameNode
{
private:
	image* _effectImage;		//����Ʈ �̹���
	animation* _effectAni;		//���彺 ����

	int _x, _y;					//����Ʈ ��Ʈ�� �ڸ�
	float _elapsedTime;			//����Ʈ ��� �ð�
	bool _isRunnig;				//����Ʈ ������̳�?

public:
	HRESULT init(image* effectImage, int frameW, int frameH, int FPS, float elapsedTime);
	void release(void);
	void update(void);
	void render(void);

	//����Ʈ ��Ʈ�� ��ġ
	void startEffect(int x, int y);
	//����Ʈ ����
	void stopEffect(void);

	//����Ʈ ������̳�?
	bool getIsRunning(void) { return _isRunnig; }
	

	effect();
	~effect();
};

