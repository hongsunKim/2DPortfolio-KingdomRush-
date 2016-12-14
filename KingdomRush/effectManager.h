#pragma once
#include "singletonBase.h"

class effect;

class effectManager : public singletonBase<effectManager>
{
private:
	//이펙트를 담을 벡터
	typedef vector<effect*> vEffect;
	typedef vector<effect*>::iterator viEffect;
	//이펙트 클래스가 담겨있는 백터를 담을 맵
	typedef map<string, vEffect> mEffect;
	typedef map<string, vEffect>::iterator miEffect;
	//모든 이펙트를 관리할 백터(맵을  담을 백터
	typedef vector<mEffect> vTotalEffect;
	typedef vector<mEffect>::iterator viTotalEffect;

private:
	//실제 모든 이펙트가 담길 백터
	vTotalEffect _vTotalEffect;
	
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	
	//이펙트 추가
	void addEffect(string effectKey, char* imageName, int imageW, int imageH,
		int frameW, int frameH, int fps, float elapsedTime, int buffer);

	//이펙트 플레이
	void play(string effectKey, int x, int y);

	effectManager();
	~effectManager();
};

