#pragma once
#include "gameNode.h"
class camel : public gameNode
{
private:
	/*image* _camel;			//��Ÿ ��������Ʈ

	animation* _ani1;
	animation* _ani2;
	animation* _ani3;*/

	//�޴��� ���
	image* _camel;
	animation* _ani;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	camel();
	~camel();
};

