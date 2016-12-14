#pragma once
#include "gameNode.h"

//==================================================================
//		## effect ## (이펙트 클래스)
//==================================================================

class effect : public gameNode
{
private:
	image* _effectImage;		//이펙트 이미지
	animation* _effectAni;		//이펙스 에니

	int _x, _y;					//이펙트 터트릴 자리
	float _elapsedTime;			//이펙트 경과 시간
	bool _isRunnig;				//이펙트 재생중이냐?

public:
	HRESULT init(image* effectImage, int frameW, int frameH, int FPS, float elapsedTime);
	void release(void);
	void update(void);
	void render(void);

	//이펙트 터트릴 위치
	void startEffect(int x, int y);
	//이펙트 멈춤
	void stopEffect(void);

	//이펙트 재생중이냐?
	bool getIsRunning(void) { return _isRunnig; }
	

	effect();
	~effect();
};

