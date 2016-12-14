#pragma once
#include "singletonBase.h"
#include "timer.h"
//==================================================================
//		## timeManager ## (타임매니져)
//==================================================================

class timeManager : public singletonBase<timeManager>
{
private:
	timer* _timer;

public:
	HRESULT init(void);
	void release(void);
	void update(float lock);
	void render(HDC hdc);

	//한프레임당경과시간 가져오기
	float getElapsedTime(void) const { return _timer->getElapsedTime(); }
	//전체 경과시간 가져오기
	float getWorlTime(void) const { return _timer->getWorldTime(); }


	timeManager();
	~timeManager();
};

