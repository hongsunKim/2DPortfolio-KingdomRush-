#pragma once
#include "gameNode.h"

class prograssBar :public gameNode
{
private:
	RECT _rcPrograss;			//체력바 랙트	
	int _x, _y;					//체력바 위치
	int _width;					//체력바 길이

	image* _prograssBarFront;	//체력바 앞이미지
	image* _prograssBarBack;	//체력바 배경


public:
	//체력바 초기화
	HRESULT init(char* frontImage, char* BackImage, float x, float y, int width, int height);
	void release(void);
	void update(void);
	void render(void);

	//프로그래스바 게이지 세팅(초기화시 꼭 해줘야)
	void setGauge(float currentGauge, float maxGauge);

	//프로그래스바 위치 세팅
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

	//체력바 렉트 가져오기
	RECT getRect(void) { return _rcPrograss; }


	prograssBar();
	~prograssBar();
};

