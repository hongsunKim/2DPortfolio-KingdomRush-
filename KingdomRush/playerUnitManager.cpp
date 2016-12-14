#include "stdafx.h"
#include "playerUnitManager.h"

playerUnitManager::playerUnitManager()
{
}

playerUnitManager::~playerUnitManager()
{
}

//이미지 초기화
HRESULT playerUnitManager::init()
{
	return S_OK;
}

//이미지 매니져 해제
void playerUnitManager::release()
{
	deleteAll();
}

//키값을 설정해주며 타워 추가
playerUnitBase* playerUnitManager::addUnit(string strKey, playerUnitBase* unit)
{
	//추가하려는 키값으로 타워가 존재하는지 확인
	playerUnitBase* tempUnit = findUnit(strKey);

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
	_mPlayerUnitList.insert(make_pair(strKey, tempUnit));

	return tempUnit;
	// 	image* temp = imageManager->addImage(asdfsda);
	// 	imageManager->addImage(asdfsda);
}

playerUnitBase* playerUnitManager::addUnit(string strKey, playerUnitBase* unit, float x, float y)
{
	//추가하려는 키값으로 타워가 존재하는지 확인
	playerUnitBase* tempUnit = findUnit(strKey);

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
	_mPlayerUnitList.insert(make_pair(strKey, tempUnit));

	return tempUnit;
	// 	image* temp = imageManager->addImage(asdfsda);
	// 	imageManager->addImage(asdfsda);
}

//이미지 키값으로 찾기
playerUnitBase* playerUnitManager::findUnit(string strKey)
{
	//해당 키검색
	mapPlayerUnitIter key = _mPlayerUnitList.find(strKey);

	//검색한 키가 있다면
	if (key != _mPlayerUnitList.end())
	{
		playerUnitBase* temp = key->second;
		return temp;
	}

	//키를 찾지 못했다면
	return NULL;
}

//이미지 키값으로 찾기
playerUnitBase* playerUnitManager::copyUnit(string strKey, float x, float y)
{
	//해당 키검색
	mapPlayerUnitIter key = _mPlayerUnitList.find(strKey);

	//검색한 키가 있다면
	if (key != _mPlayerUnitList.end())
	{
		playerUnitBase* temp = key->second->copyUnit();
		temp->setX(x);
		temp->setY(y);
		return temp;
	}
	//키를 찾지 못했다면
	return NULL;
}
//이미지 키값으로 삭제
BOOL playerUnitManager::deleteUnit(string strKey)
{
	//해당키 검색
	mapPlayerUnitIter key = _mPlayerUnitList.find(strKey);

	if (key != _mPlayerUnitList.end())
	{
		//이미지 해제
		key->second->release();
		//메모리 해제
		SAFE_DELETE(key->second);
		//멥에서 반복자 삭제
		_mPlayerUnitList.erase(key);

		return TRUE;
	}

	//키를 찾지 못했다면
	return FALSE;
}
//이미지 전체 삭제
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

	//맵 전체 삭제
	_mPlayerUnitList.clear();

	return TRUE;
}

void playerUnitManager::setPosition(string strKey, float x, float y)
{
	//해당 키검색
	mapPlayerUnitIter key = _mPlayerUnitList.find(strKey);

	//검색한 키가 있다면
	if (key != _mPlayerUnitList.end())
	{
		key->second->setX(x);
		key->second->setY(y);
	}
}