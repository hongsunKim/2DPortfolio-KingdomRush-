#include "stdafx.h"
#include "towerManager.h"

//�̹��� �ʱ�ȭ
HRESULT towerManager::init()
{
	return S_OK;
}
//�̹��� �Ŵ��� ����
void towerManager::release()
{
	deleteAll();
}

//Ű���� �������ָ� Ÿ�� �߰�
towerBase* towerManager::addTower(string strKey, towerBase* paramTower)
{
	//�߰��Ϸ��� Ű������ Ÿ���� �����ϴ��� Ȯ��
	towerBase* tempTower = findTower(strKey);

	//�߰� �Ϸ��� �̹����� �����ϸ� ���� �������ʰ� �ִ³� �����Ѵ�.
	if (tempTower) return tempTower;

	////�̹��� ���λ���
	//tempTower = new tower;
	tempTower = paramTower;
	//�̹����� ����� �ʱ�ȭ �Ǿ����� Ȯ��
	if (FAILED(tempTower->init()))
	{
		SAFE_DELETE(tempTower);
		return NULL;
	}

	//������ �̹����� ������ ���� �̹��� ��Ͽ� �߰�
	_mTowerList.insert(make_pair(strKey, tempTower));

	return tempTower;
	// 	image* temp = imageManager->addImage(asdfsda);
	// 	imageManager->addImage(asdfsda);
}

//Ű���� �������ָ� Ÿ�� �߰�
towerBase* towerManager::addTower(string strKey, towerBase* paramTower, float x, float y)
{
	//�߰��Ϸ��� Ű������ Ÿ���� �����ϴ��� Ȯ��
	towerBase* tempTower = findTower(strKey);

	//�߰� �Ϸ��� �̹����� �����ϸ� ���� �������ʰ� �ִ³� �����Ѵ�.
	if (tempTower) return tempTower;

	////�̹��� ���λ���
	//tempTower = new tower;
	paramTower->setPosition(x, y);
	tempTower = paramTower;
	//�̹����� ����� �ʱ�ȭ �Ǿ����� Ȯ��
	if (FAILED(tempTower->init()))
	{
		SAFE_DELETE(tempTower);
		return NULL;
	}

	//������ �̹����� ������ ���� �̹��� ��Ͽ� �߰�
	_mTowerList.insert(make_pair(strKey, tempTower));

	return tempTower;
	// 	image* temp = imageManager->addImage(asdfsda);
	// 	imageManager->addImage(asdfsda);
}

//�̹��� Ű������ ã��
towerBase* towerManager::findTower(string strKey)
{
	//�ش� Ű�˻�
	mapTowerIter key = _mTowerList.find(strKey);

	//�˻��� Ű�� �ִٸ�
	if (key != _mTowerList.end())
	{
		towerBase* temp = key->second;
		return temp;
	}

	//Ű�� ã�� ���ߴٸ�
	return NULL;
}

//�̹��� Ű������ ã��
towerBase* towerManager::copyTower(string strKey, float x, float y)
{
	//�ش� Ű�˻�
	mapTowerIter key = _mTowerList.find(strKey);

	//�˻��� Ű�� �ִٸ�
	if (key != _mTowerList.end())
	{
		towerBase* temp = key->second->copyTower();
		temp->setPosition(x, y);
		return temp;
	}

	//Ű�� ã�� ���ߴٸ�
	return NULL;
}

//�̹��� Ű������ ����
BOOL towerManager::deleteTower(string strKey)
{
	//�ش�Ű �˻�
	mapTowerIter key = _mTowerList.find(strKey);

	if (key != _mTowerList.end())
	{
		//�̹��� ����
		key->second->release();
		//�޸� ����
		SAFE_DELETE(key->second);
		//�㿡�� �ݺ��� ����
		_mTowerList.erase(key);

		return TRUE;
	}

	//Ű�� ã�� ���ߴٸ�
	return FALSE;
}
//�̹��� ��ü ����
BOOL towerManager::deleteAll(void)
{
	mapTowerIter iter = _mTowerList.begin();
	// 	map<string, image*>::iterator i = _mImageList.begin()
	// 	for (map<string, image*>::iterator i = _mImageList.begin(); iter != _mImageList.end();)
	for (; iter != _mTowerList.end();)
	{
		if (iter->second != NULL)
		{
			//iter->second == image* temp
			iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mTowerList.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	//�� ��ü ����
	_mTowerList.clear();

	return TRUE;
}

//void towerManager::setPosition(string strKey, float x, float y)
//{
//	//�ش� Ű�˻�
//	mapTowerIter key = _mTowerList.find(strKey);
//
//	//�˻��� Ű�� �ִٸ�
//	if (key != _mTowerList.end())
//	{
//		key->second->setPosition(x, y);
//	}
//}

//void towerManager::linkGameStage(gameStage* stage)
//{
//	_linkedGameStage = stage;
//}

towerManager::towerManager()
{
}


towerManager::~towerManager()
{
}
