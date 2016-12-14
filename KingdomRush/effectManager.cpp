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
					//����Ʈ Ŭ���� ������
					(*vArrIter)->release();
					//����Ʈ Ŭ���� ����
					SAFE_DELETE(*vArrIter);
					//�ݺ��� ����
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


//����Ʈ �߰�
void effectManager::addEffect(string effectKey, char* imageName, int imageW, int imageH,
	int frameW, int frameH, int fps, float elapsedTime, int buffer)
{
	image* img;
	vEffect vEffectBuffer;
	mEffect mArrEffect;

	//�̹����� �Ŵ����� �ֳ�?
	if (IMAGEMANAGER->findImage(imageName))
	{
		img = IMAGEMANAGER->findImage(imageName);
	}
	else
	{
		//���
		img = IMAGEMANAGER->addImage(imageName, imageName, imageW, imageH, TRUE, RGB(255, 0, 255));
	}

	//���ۻ����� ��ŭ ����Ʈ�� �����Ҵ� �ʱ�ȭ �� ���Ϳ� ����
	for (int i = 0; i < buffer; i++)
	{
		vEffectBuffer.push_back(new effect);
		vEffectBuffer[i]->init(img, frameW, frameH, fps, elapsedTime);
	}

	//���Ϳ� ��� ����Ʈ���۸� �ʿ� ����
	mArrEffect.insert(make_pair(effectKey, vEffectBuffer));

	//���� ��Ż ���Ϳ� ���
	_vTotalEffect.push_back(mArrEffect);
}


//����Ʈ �÷���
void effectManager::play(string effectKey, int x, int y)
{
	viTotalEffect vIter;
	miEffect mIter;

	//��ü ����
	for (vIter = _vTotalEffect.begin(); vIter != _vTotalEffect.end(); ++vIter)
	{
		//�׾ȿ� ��
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			//�ʾȿ� ����
			if (!(mIter->first == effectKey)) break;

			viEffect vArrIter;
			for (vArrIter = mIter->second.begin();
				vArrIter != mIter->second.end();
				++vArrIter)
			{
				//���;��� ����Ʈ
				if ((*vArrIter)->getIsRunning()) continue;
				(*vArrIter)->startEffect(x, y);
				return;
			}
		}
	}
}
