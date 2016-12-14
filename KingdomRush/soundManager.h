#pragma once
#include "singletonBase.h"
#include "inc/fmod.hpp"
#pragma comment(lib, "lib/fmodex_vc.lib")
using namespace FMOD;


//==================================================================
//		## soundManager ## (���� �Ŵ���)
//==================================================================

//ä�ι���, �������
#define EXTRACHANNELBUFFER 5
#define SOUNDBUFFER 20
//��Ż������� ���� : ���۰� �۾Ƽ� ������ ���� �ذ�
#define TOTALSOUNDBUFFER SOUNDBUFFER + EXTRACHANNELBUFFER

class soundManager : public singletonBase<soundManager>
{
private:
	typedef map<string, Sound**> arrSounds;
	typedef map<string, Sound**>::iterator arrSoundIter;

private:
	System* _system;		//fmod�� �ý���Ŭ����
	Sound** _sound;			//fmod�� ����Ŭ����
	Channel** _channel;		//fmod�� ä��Ŭ����

	arrSounds _mTotalSound;	//����� ���� ���

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//���� �߰�(Ű��, �����̸�, bgm�̳�?, �ݺ��̳�?)
	void addSound(string keyName, string soundName, bool bgm = false, bool loop = false);

	//���� �÷���
	void play(string keyName, float volume = 1.0f);

	//���� ����
	void stop(string keyName);

	//���� �Ͻ�����
	void pause(string keyName);

	//���� �ٽ����
	void resume(string keyName);

	//�÷��� ���̳�?
	bool isPlaySound(string keyName);
	//�Ͻ����� ���̳�?
	bool isPauseSound(string keyName);
	

	soundManager();
	~soundManager();
};

