#include "stdafx.h"
#include "towerManager.h"

//이미지 초기화
HRESULT towerManager::init()
{
	return S_OK;
}
//이미지 매니져 해제
void towerManager::release()
{
	deleteAll();
}

//키값을 설정해주며 타워 추가
towerBase* towerManager::addTower(string strKey, towerBase* paramTower)
{
	//추가하려는 키값으로 타워가 존재하는지 확인
	towerBase* tempTower = findTower(strKey);

	//추가 하려는 이미지가 존재하면 새로 만들지않고 있는놈 리턴한다.
	if (tempTower) return tempTower;

	////이미지 새로생성
	//tempTower = new tower;
	tempTower = paramTower;
	//이미지가 제대로 초기화 되었는지 확인
	if (FAILED(tempTower->init()))
	{
		SAFE_DELETE(tempTower);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에 추가
	_mTowerList.insert(make_pair(strKey, tempTower));

	return tempTower;
	// 	image* temp = imageManager->addImage(asdfsda);
	// 	imageManager->addImage(asdfsda);
}

//키값을 설정해주며 타워 추가
towerBase* towerManager::addTower(string strKey, towerBase* paramTower, float x, float y)
{
	//추가하려는 키값으로 타워가 존재하는지 확인
	towerBase* tempTower = findTower(strKey);

	//추가 하려는 이미지가 존재하면 새로 만들지않고 있는놈 리턴한다.
	if (tempTower) return tempTower;

	////이미지 새로생성
	//tempTower = new tower;
	paramTower->setPosition(x, y);
	tempTower = paramTower;
	//이미지가 제대로 초기화 되었는지 확인
	if (FAILED(tempTower->init()))
	{
		SAFE_DELETE(tempTower);
		return NULL;
	}

	//생성된 이미지를 맵으로 만든 이미지 목록에 추가
	_mTowerList.insert(make_pair(strKey, tempTower));

	return tempTower;
	// 	image* temp = imageManager->addImage(asdfsda);
	// 	imageManager->addImage(asdfsda);
}

//이미지 키값으로 찾기
towerBase* towerManager::findTower(string strKey)
{
	//해당 키검색
	mapTowerIter key = _mTowerList.find(strKey);

	//검색한 키가 있다면
	if (key != _mTowerList.end())
	{
		towerBase* temp = key->second;
		return temp;
	}

	//키를 찾지 못했다면
	return NULL;
}

//이미지 키값으로 찾기
towerBase* towerManager::copyTower(string strKey, float x, float y)
{
	//해당 키검색
	mapTowerIter key = _mTowerList.find(strKey);

	//검색한 키가 있다면
	if (key != _mTowerList.end())
	{
		towerBase* temp = key->second->copyTower();
		temp->setPosition(x, y);
		return temp;
	}

	//키를 찾지 못했다면
	return NULL;
}

//이미지 키값으로 삭제
BOOL towerManager::deleteTower(string strKey)
{
	//해당키 검색
	mapTowerIter key = _mTowerList.find(strKey);

	if (key != _mTowerList.end())
	{
		//이미지 해제
		key->second->release();
		//메모리 해제
		SAFE_DELETE(key->second);
		//멥에서 반복자 삭제
		_mTowerList.erase(key);

		return TRUE;
	}

	//키를 찾지 못했다면
	return FALSE;
}
//이미지 전체 삭제
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

	//맵 전체 삭제
	_mTowerList.clear();

	return TRUE;
}

//void towerManager::setPosition(string strKey, float x, float y)
//{
//	//해당 키검색
//	mapTowerIter key = _mTowerList.find(strKey);
//
//	//검색한 키가 있다면
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
