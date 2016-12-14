#pragma once
#include "gameNode.h"
#include "startPage.h"
#include "creditPage.h"
#include "mainPage.h"
#include "stage1.h"
#include "stageBase.h"
#include "stage2.h"

class mainGame : public gameNode
{
private:
	char debug[16];
public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);


	mainGame();
	~mainGame();
};

