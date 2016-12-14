#include "stdafx.h"
#include "playerUnitManager.h"

playerUnitManager::playerUnitManager()
{
}

playerUnitManager::~playerUnitManager()
{
}

//�̹��� �ʱ�ȭ
HRESULT playerUnitManager::init()
{
	return S_OK;
}

//�̹��� �Ŵ��� ����
void playerUnitManager::release()
{
	deleteAll();
}

//Ű���� �������ָ� Ÿ�� �߰�
playerUnitBase* playerUnitManager::addUnit(string strKey, playerUnitBase* unit)
{
	//�߰��Ϸ��� Ű������ Ÿ���� �����ϴ��� Ȯ��
	playerUnitBase* tempUnit = findUnit(strKey);

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
	_mPlayerUnitList.insert(make_pair(strKey, tempUnit));

	return tempUnit;
	// 	image* temp = imageManager->addImage(asdfsda);
	// 	imageManager->addImage(asdfsda);
}

playerUnitBase* playerUnitManager::addUnit(string strKey, playerUnitBase* unit, float x, float y)
{
	//�߰��Ϸ��� Ű������ Ÿ���� �����ϴ��� Ȯ��
	playerUnitBase* tempUnit = findUnit(strKey);

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
	_mPlayerUnitList.insert(make_pair(strKey, tempUnit));

	return tempUnit;
	// 	image* temp = imageManager->addImage(asdfsda);
	// 	imageManager->addImage(asdfsda);
}

//�̹��� Ű������ ã��
playerUnitBase* playerUnitManager::findUnit(string strKey)
{
	//�ش� Ű�˻�
	mapPlayerUnitIter key = _mPlayerUnitList.find(strKey);

	//�˻��� Ű�� �ִٸ�
	if (key != _mPlayerUnitList.end())
	{
		playerUnitBase* temp = key->second;
		return temp;
	}

	//Ű�� ã�� ���ߴٸ�
	return NULL;
}

//�̹��� Ű������ ã��
playerUnitBase* playerUnitManager::copyUnit(string strKey, float x, float y)
{
	//�ش� Ű�˻�
	mapPlayerUnitIter key = _mPlayerUnitList.find(strKey);

	//�˻��� Ű�� �ִٸ�
	if (key != _mPlayerUnitList.end())
	{
		playerUnitBase* temp = key->second->copyUnit();
		temp->setX(x);
		temp->setY(y);
		return temp;
	}
	//Ű�� ã�� ���ߴٸ�
	return NULL;
}
//�̹��� Ű������ ����
BOOL playerUnitManager::deleteUnit(string strKey)
{
	//�ش�Ű �˻�
	mapPlayerUnitIter key = _mPlayerUnitList.find(strKey);

	if (key != _mPlayerUnitList.end())
	{
		//�̹��� ����
		key->second->release();
		//�޸� ����
		SAFE_DELETE(key->second);
		//�㿡�� �ݺ��� ����
		_mPlayerUnitList.erase(key);

		return TRUE;
	}

	//Ű�� ã�� ���ߴٸ�
	return FALSE;
}
//�̹��� ��ü ����
BOOL playerUnitManager::deleteAll(void)
{
	mapPlayerUnitIter iter = _mPlayerUnitList.begin();
	// 	map<string, image*>::iterator i = _mImageList.begin()
	// 	for (map<string, image*>::iterator i = _mImageList.begin(); iter != _mImageList.end();)
	for (; iter != _mPlayerUnitList.end();)
	{
		if (iter->second != NULL)
		{
			//iter->second == image* temp
			iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mPlayerUnitList.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	//�� ��ü ����
	_mPlayerUnitList.clear();

	return TRUE;
}

void playerUnitManager::setPosition(string strKey, float x, float y)
{
	//�ش� Ű�˻�
	mapPlayerUnitIter key = _mPlayerUnitList.find(strKey);

	//�˻��� Ű�� �ִٸ�
	if (key != _mPlayerUnitList.end())
	{
		key->second->setX(x);
		key->second->setY(y);
	}
}