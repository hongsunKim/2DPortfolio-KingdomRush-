#pragma once
#include "gameNode.h"

enum class CREDITPAGE
{
	OPEN,
	CLOSE,
	CREDIT
};

class creditPage :
	public gameNode
{
private:
	CREDITPAGE _creditPage;

	image* _creditImage;

	RECT _backButtonRect;
	image* _backButtonImage;

	image* _leftDoorImage;
	image* _rightDoorImage;
	int _leftDoorPos;
	int _rightDoorPos;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	creditPage();
	~creditPage();
};

