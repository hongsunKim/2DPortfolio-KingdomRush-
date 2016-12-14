#include "stdafx.h"
#include "effectManager.h"
#include "effect.h"
effectManager::effectManager()
{
}
effectManager::~effectManager()
{
}

HRESULT effectManager::init(void)
{
	return S_OK;
}

void effectManager::release(void)
{
	viTotalEffect vIter;
	miEffect mIter;

	for (vIter = _vTotalEffect.begin(); vIter != _vTotalEffect.end(); ++vIter)
	{
		mIter = vIter->begin();
		for (; mIter != vIter->end();)
		{
			if (mIter->second.size() != 0)
			{
				viEffect vArrIter = mIter->second.begin();
				for (; vArrIter != mIter->second.end();)
				{
					//이펙트 클래스 릴리즈
					(*vArrIter)->release();
					//이펙트 클래스 해제
					SAFE_DELETE(*vArrIter);
					//반복자 해제
					vArrIter = mIter->second.erase(vArrIter);
				}
			}
			else
			{
				++mIter;
			}
		}
	}
}

void effectManager::update(void)
{
	viTotalEffect vIter;
	miEffect mIter;

	for (vIter = _vTotalEffect.begin(); vIter != _vTotalEffect.end(); ++vIter)
	{
		
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			viEffect vArrIter;
			for (vArrIter = mIter->second.begin();
				vArrIter != mIter->second.end();
				++vArrIter)
			{
				(*vArrIter)->update();
			}
		}
	}
}

void effectManager::render(void)
{
	viTotalEffect vIter;
	miEffect mIter;

	for (vIter = _vTotalEffect.begin(); vIter != _vTotalEffect.end(); ++vIter)
	{

		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			viEffect vArrIter;
			for (vArrIter = mIter->second.begin();
				vArrIter != mIter->second.end();
				++vArrIter)
			{
				(*vArrIter)->render();
			}
		}
	}
}


//이펙트 추가
void effectManager::addEffect(string effectKey, char* imageName, int imageW, int imageH,
	int frameW, int frameH, int fps, float elapsedTime, int buffer)
{
	image* img;
	vEffect vEffectBuffer;
	mEffect mArrEffect;

	//이미지가 매니져에 있냐?
	if (IMAGEMANAGER->findImage(imageName))
	{
		img = IMAGEMANAGER->findImage(imageName);
	}
	else
	{
		//등록
		img = IMAGEMANAGER->addImage(imageName, imageName, imageW, imageH, TRUE, RGB(255, 0, 255));
	}

	//버퍼사이즈 만큼 이펙트를 동적할당 초기화 후 백터에 담자
	for (int i = 0; i < buffer; i++)
	{
		vEffectBuffer.push_back(new effect);
		vEffectBuffer[i]->init(img, frameW, frameH, fps, elapsedTime);
	}

	//백터에 담긴 이펙트버퍼를 맵에 담자
	mArrEffect.insert(make_pair(effectKey, vEffectBuffer));

	//맵을 토탈 백터에 담기
	_vTotalEffect.push_back(mArrEffect);
}


//이펙트 플레이
void effectManager::play(string effectKey, int x, int y)
{
	viTotalEffect vIter;
	miEffect mIter;

	//전체 백터
	for (vIter = _vTotalEffect.begin(); vIter != _vTotalEffect.end(); ++vIter)
	{
		//그안에 맵
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			//맵안에 백터
			if (!(mIter->first == effectKey)) break;

			viEffect vArrIter;
			for (vArrIter = mIter->second.begin();
				vArrIter != mIter->second.end();
				++vArrIter)
			{
				//백터안의 이펙트
				if ((*vArrIter)->getIsRunning()) continue;
				(*vArrIter)->startEffect(x, y);
				return;
			}
		}
	}
}
