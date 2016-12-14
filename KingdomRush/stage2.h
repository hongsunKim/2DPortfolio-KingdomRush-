#pragma once
#include "stageBase.h"
class stage2 :
	public stageBase
{
public:
	stage2();
	~stage2();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};