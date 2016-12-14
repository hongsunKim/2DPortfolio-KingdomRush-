#include "stdafx.h"
#include "enemyUnitManager.h"


enemyUnitManager::enemyUnitManager()
{
}


enemyUnitManager::~enemyUnitManager()
{
}

//이미지 초기화
HRESULT enemyUnitManager::init()
{
	return S_OK;
}
//이미지 매니져 해제
void enemyUnitManager::release()
{
	deleteAll();
}

//키값을 설정해주며 타워 추가
enemyUnitBase* enemyUnitManager::addUnit(string strKey, enemyUnitBase* unit)
{
	//추가하려는 키값으로 타워가 존재하는지 확인
	enemyUnitBase* tempUnit = findUnit(strKey);

	//추가 하려는 이미지가 존재하면 새로 만들지않고 있는놈 리턴한다.
	if (tempUnit) return tempUnit;

	////이미지 새로생성
	//tempTower = new tower;
	tempUnit = unit;
	//이미지가 제대로 초기화 되었는지 확인
	if (FAILED(tempUnit->init()))
	{
		SAFE_DELETE(tempUnit);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에 추가
	_mEnemyUnitList.insert(make_pair(strKey, tempUnit));

	return tempUnit;
	// 	image* temp = imageManager->addImage(asdfsda);
	// 	imageManager->addImage(asdfsda);
}
enemyUnitBase* enemyUnitManager::addUnit(string strKey, enemyUnitBase* unit, float x, float y)
{
	//추가하려는 키값으로 타워가 존재하는지 확인
	enemyUnitBase* tempUnit = findUnit(strKey);

	//추가 하려는 이미지가 존재하면 새로 만들지않고 있는놈 리턴한다.
	if (tempUnit) return tempUnit;

	////이미지 새로생성
	//tempTower = new tower;
	unit->setX(x);
	unit->setY(y);
	tempUnit = unit;
	//이미지가 제대로 초기화 되었는지 확인
	if (FAILED(tempUnit->init()))
	{
		SAFE_DELETE(tempUnit);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에 추가
	_mEnemyUnitList.insert(make_pair(strKey, tempUnit));

	return tempUnit;
	// 	image* temp = imageManager->addImage(asdfsda);
	// 	imageManager->addImage(asdfsda);
}

//이미지 키값으로 찾기
enemyUnitBase* enemyUnitManager::findUnit(string strKey)
{
	//해당 키검색
	mapEnemyUnitIter key = _mEnemyUnitList.find(strKey);

	//검색한 키가 있다면
	if (key != _mEnemyUnitList.end())
	{
		enemyUnitBase* temp = key->second;
		return temp;
	}

	//키를 찾지 못했다면
	return NULL;
}
//이미지 키값으로 찾기
enemyUnitBase* enemyUnitManager::copyUnit(string strKey, int waveNum)
{
	//해당 키검색
	mapEnemyUnitIter key = _mEnemyUnitList.find(strKey);

	//검색한 키가 있다면
	if (key != _mEnemyUnitList.end())
	{
		enemyUnitBase* temp = key->second->copyUnit();
		temp->setWaveNum(waveNum);
		return temp;
	}
	//키를 찾지 못했다면
	return NULL;
}
//이미지 키값으로 삭제
BOOL enemyUnitManager::deleteUnit(string strKey)
{
	//해당키 검색
	mapEnemyUnitIter key = _mEnemyUnitList.find(strKey);

	if (key != _mEnemyUnitList.end())
	{
		//이미지 해제
		key->second->release();
		//메모리 해제
		SAFE_DELETE(key->second);
		//멥에서 반복자 삭제
		_mEnemyUnitList.erase(key);

		return TRUE;
	}

	//키를 찾지 못했다면
	return FALSE;
}
//이미지 전체 삭제
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

	//맵 전체 삭제
	_mEnemyUnitList.clear();

	return TRUE;
}

void enemyUnitManager::setPosition(string strKey, float x, float y)
{
	//해당 키검색
	mapEnemyUnitIter key = _mEnemyUnitList.find(strKey);

	//검색한 키가 있다면
	if (key != _mEnemyUnitList.end())
	{
		key->second->setX(x);
		key->second->setY(y);
	}
}