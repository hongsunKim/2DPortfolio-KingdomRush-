#include "stdafx.h"
#include "enemyUnitManager.h"


enemyUnitManager::enemyUnitManager()
{
}


enemyUnitManager::~enemyUnitManager()
{
}

//�̹��� �ʱ�ȭ
HRESULT enemyUnitManager::init()
{
	return S_OK;
}
//�̹��� �Ŵ��� ����
void enemyUnitManager::release()
{
	deleteAll();
}

//Ű���� �������ָ� Ÿ�� �߰�
enemyUnitBase* enemyUnitManager::addUnit(string strKey, enemyUnitBase* unit)
{
	//�߰��Ϸ��� Ű������ Ÿ���� �����ϴ��� Ȯ��
	enemyUnitBase* tempUnit = findUnit(strKey);

	//�߰� �Ϸ��� �̹����� �����ϸ� ���� �������ʰ� �ִ³� �����Ѵ�.
	if (tempUnit) return tempUnit;

	////�̹��� ���λ���
	//tempTower = new tower;
	tempUnit = unit;
	//�̹����� ����� �ʱ�ȭ �Ǿ����� Ȯ��
	if (FAILED(tempUnit->init()))
	{
		SAFE_DELETE(tempUnit);
		return NULL;
	}

	//������ �̹����� ������ ���� �̹��� ��Ͽ� �߰�
	_mEnemyUnitList.insert(make_pair(strKey, tempUnit));

	return tempUnit;
	// 	image* temp = imageManager->addImage(asdfsda);
	// 	imageManager->addImage(asdfsda);
}
enemyUnitBase* enemyUnitManager::addUnit(string strKey, enemyUnitBase* unit, float x, float y)
{
	//�߰��Ϸ��� Ű������ Ÿ���� �����ϴ��� Ȯ��
	enemyUnitBase* tempUnit = findUnit(strKey);

	//�߰� �Ϸ��� �̹����� �����ϸ� ���� �������ʰ� �ִ³� �����Ѵ�.
	if (tempUnit) return tempUnit;

	////�̹��� ���λ���
	//tempTower = new tower;
	unit->setX(x);
	unit->setY(y);
	tempUnit = unit;
	//�̹����� ����� �ʱ�ȭ �Ǿ����� Ȯ��
	if (FAILED(tempUnit->init()))
	{
		SAFE_DELETE(tempUnit);
		return NULL;
	}

	//������ �̹����� ������ ���� �̹��� ��Ͽ� �߰�
	_mEnemyUnitList.insert(make_pair(strKey, tempUnit));

	return tempUnit;
	// 	image* temp = imageManager->addImage(asdfsda);
	// 	imageManager->addImage(asdfsda);
}

//�̹��� Ű������ ã��
enemyUnitBase* enemyUnitManager::findUnit(string strKey)
{
	//�ش� Ű�˻�
	mapEnemyUnitIter key = _mEnemyUnitList.find(strKey);

	//�˻��� Ű�� �ִٸ�
	if (key != _mEnemyUnitList.end())
	{
		enemyUnitBase* temp = key->second;
		return temp;
	}

	//Ű�� ã�� ���ߴٸ�
	return NULL;
}
//�̹��� Ű������ ã��
enemyUnitBase* enemyUnitManager::copyUnit(string strKey, int waveNum)
{
	//�ش� Ű�˻�
	mapEnemyUnitIter key = _mEnemyUnitList.find(strKey);

	//�˻��� Ű�� �ִٸ�
	if (key != _mEnemyUnitList.end())
	{
		enemyUnitBase* temp = key->second->copyUnit();
		temp->setWaveNum(waveNum);
		return temp;
	}
	//Ű�� ã�� ���ߴٸ�
	return NULL;
}
//�̹��� Ű������ ����
BOOL enemyUnitManager::deleteUnit(string strKey)
{
	//�ش�Ű �˻�
	mapEnemyUnitIter key = _mEnemyUnitList.find(strKey);

	if (key != _mEnemyUnitList.end())
	{
		//�̹��� ����
		key->second->release();
		//�޸� ����
		SAFE_DELETE(key->second);
		//�㿡�� �ݺ��� ����
		_mEnemyUnitList.erase(key);

		return TRUE;
	}

	//Ű�� ã�� ���ߴٸ�
	return FALSE;
}
//�̹��� ��ü ����
BOOL enemyUnitManager::deleteAll(void)
{
	mapEnemyUnitIter iter = _mEnemyUnitList.begin();
	// 	map<string, image*>::iterator i = _mImageList.begin()
	// 	for (map<string, image*>::iterator i = _mImageList.begin(); iter != _mImageList.end();)
	for (; iter != _mEnemyUnitList.end();)
	{
		if (iter->second != NULL)
		{
			//iter->second == image* temp
			iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mEnemyUnitList.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	//�� ��ü ����
	_mEnemyUnitList.clear();

	return TRUE;
}

void enemyUnitManager::setPosition(string strKey, float x, float y)
{
	//�ش� Ű�˻�
	mapEnemyUnitIter key = _mEnemyUnitList.find(strKey);

	//�˻��� Ű�� �ִٸ�
	if (key != _mEnemyUnitList.end())
	{
		key->second->setX(x);
		key->second->setY(y);
	}
}