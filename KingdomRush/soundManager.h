#pragma once
#include "singletonBase.h"
#include "inc/fmod.hpp"
#pragma comment(lib, "lib/fmodex_vc.lib")
using namespace FMOD;


//==================================================================
//		## soundManager ## (사운드 매니져)
//==================================================================

//채널버퍼, 사운드버퍼
#define EXTRACHANNELBUFFER 5
#define SOUNDBUFFER 20
//토탈사운드버퍼 설정 : 버퍼가 작아서 씹히는 문제 해결
#define TOTALSOUNDBUFFER SOUNDBUFFER + EXTRACHANNELBUFFER

class soundManager : public singletonBase<soundManager>
{
private:
	typedef map<string, Sound**> arrSounds;
	typedef map<string, Sound**>::iterator arrSoundIter;

private:
	System* _system;		//fmod의 시스템클래스
	Sound** _sound;			//fmod의 사운드클래스
	Channel** _channel;		//fmod의 채널클래스

	arrSounds _mTotalSound;	//사용할 사운드 목록

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//사운드 추가(키값, 파일이름, bgm이냐?, 반복이냐?)
	void addSound(string keyName, string soundName, bool bgm = false, bool loop = false);

	//사운드 플레이
	void play(string keyName, float volume = 1.0f);

	//사운드 정지
	void stop(string keyName);

	//사운드 일시정지
	void pause(string keyName);

	//사운드 다시재생
	void resume(string keyName);

	//플레이 중이냐?
	bool isPlaySound(string keyName);
	//일시정지 중이냐?
	bool isPauseSound(string keyName);
	

	soundManager();
	~soundManager();
};

