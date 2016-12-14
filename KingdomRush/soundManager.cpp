#include "stdafx.h"
#include "soundManager.h"
soundManager::soundManager() : _system(NULL), _channel(NULL), _sound(NULL)
{
}
soundManager::~soundManager()
{
}

HRESULT soundManager::init(void)
{
	//���� �ý����� �����Ѵ�.
	System_Create(&_system);

	//���� ä�μ� ����
	_system->init(TOTALSOUNDBUFFER, FMOD_INIT_NORMAL, 0);

	//����� ä�� �����Ҵ�
	_sound = new Sound*[TOTALSOUNDBUFFER];
	_channel = new Channel*[TOTALSOUNDBUFFER];

	//�޸��ʱ�ȭ
	memset(_sound, 0, sizeof(Sound*) * (TOTALSOUNDBUFFER));
	memset(_channel, 0, sizeof(Channel*)* (TOTALSOUNDBUFFER));

	return S_OK;
}

void soundManager::release(void)
{
	//���� �� ä�� ����
	if (_channel != NULL || _sound != NULL)
	{
		for (int i = 0; i < TOTALSOUNDBUFFER; i++)
		{
			if (_sound != NULL)
			{
				if (_sound[i]) _sound[i]->release();
			}
			if (_channel != NULL)
			{
				if (_channel[i]) _channel[i]->stop();
			}
		}
	}

	//������ ����
	SAFE_DELETE(_channel);
	SAFE_DELETE(_sound);

	//�ý��� �ݱ�
	if (_system != NULL)
	{
		_system->release();
		_system->close();
	}
}

void soundManager::update(void)
{
	//

	//���ΰ��ӿ��� ����Ŵ��� ��������
	_system->update();
}

void soundManager::render(void)
{
}

//���� �߰�(Ű��, �����̸�, bgm�̳�?, �ݺ��̳�?)
void soundManager::addSound(string keyName, string soundName, bool bgm, bool loop)
{
	if (loop)
	{
		if (bgm)//������� ȿ��������
		{
			_system->createStream(soundName.c_str(),
				FMOD_LOOP_NORMAL,
				0,
				&_sound[_mTotalSound.size()]);
		}
		else
		{
			_system->createSound(soundName.c_str(),
				FMOD_LOOP_NORMAL,
				0,
				&_sound[_mTotalSound.size()]);
		}
	}
	else
	{
		_system->createSound(soundName.c_str(),
			FMOD_DEFAULT,
			0,
			&_sound[_mTotalSound.size()]);
	}

	//�ʿ� ���带 Ű���� �Բ� ��´�
	_mTotalSound.insert(make_pair(keyName, &_sound[_mTotalSound.size()]));
}

//���� �÷���
void soundManager::play(string keyName, float volume)
{
	int count = 0;
	arrSoundIter iter = _mTotalSound.begin();
	for (iter; iter != _mTotalSound.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			//���� �÷���
			_system->playSound(FMOD_CHANNEL_FREE,
				*iter->second,
				false,
				&_channel[count]);
			//�������� 0.0 ~ 1.0f
			_channel[count]->setVolume(volume);
		}
	}
}

//���� ����
void soundManager::stop(string keyName)
{
	int count = 0;
	arrSoundIter iter = _mTotalSound.begin();
	for (iter; iter != _mTotalSound.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			//���� ����
			_channel[count]->stop();
			break;
		}
	}
}

//���� �Ͻ�����
void soundManager::pause(string keyName)
{
	int count = 0;

	arrSoundIter iter = _mTotalSound.begin();

	for (iter; iter != _mTotalSound.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(true);
			break;
		}
	}
}

//���� �ٽ����
void soundManager::resume(string keyName)
{
	int count = 0;

	arrSoundIter iter = _mTotalSound.begin();

	for (iter; iter != _mTotalSound.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(false);
			break;
		}
	}
}

//�÷��� ���̳�?
bool soundManager::isPlaySound(string keyName)
{
	bool isPlay;
	int count = 0;
	arrSoundIter iter = _mTotalSound.begin();

	for (iter; iter != _mTotalSound.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->isPlaying(&isPlay);
			break;
		}
	}

	return isPlay;
}
//�Ͻ����� ���̳�?
bool soundManager::isPauseSound(string keyName)
{
	bool isPause;

	int count = 0;
	arrSoundIter iter = _mTotalSound.begin();
	for (iter; iter != _mTotalSound.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->isPlaying(&isPause);
		}
	}

	return isPause;
}