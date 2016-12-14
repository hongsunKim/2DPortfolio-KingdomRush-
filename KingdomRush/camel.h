#pragma once
#include "gameNode.h"
class camel : public gameNode
{
private:
	/*image* _camel;			//낙타 스프라이트

	animation* _ani1;
	animation* _ani2;
	animation* _ani3;*/

	//메니저 사용
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

