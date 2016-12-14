#pragma once
#include "gameNode.h"
class scene2 :
	public gameNode
{
private:
	char _text[64];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	scene2();
	~scene2();
};

