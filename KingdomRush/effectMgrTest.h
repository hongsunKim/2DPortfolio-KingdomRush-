#pragma once
#include "gameNode.h"
#include "effect.h"

class effectMgrTest : public gameNode
{
private:
	effect* _effect;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	effectMgrTest();
	~effectMgrTest();
};

