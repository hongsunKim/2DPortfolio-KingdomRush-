#pragma once
#include "stageBase.h"

class stage1 :
	public stageBase
{
public:
	stage1();
	~stage1();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

