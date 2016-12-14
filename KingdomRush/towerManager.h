#pragma once
#include "singletonBase.h"
#include "towerBase.h"
#include "towerSpot.h"
#include "barracks.h"
#include "archerTower.h"
#include "magicianTower.h"
#include "cannonTower.h"

//static bool _ptOnUI;

class towerManager :
	public singletonBase<towerManager>
{
private:
	typedef map<string, towerBase*> mapTowerList;	//맵으로 만든 타워 목록
	typedef map<string, towerBase*>::iterator mapTowerIter;

private:
	mapTowerList _mTowerList;	//맵으로 구현된 타워 목록

								//gameStage* _linkedGameStage;

public:
	//이미지 초기화
	HRESULT init();
	//이미지 매니져 해제
	void release();

	//키값을 설정해주며 타워 추가
	towerBase* addTower(string strKey, towerBase* tower);
	towerBase* addTower(string strKey, towerBase* tower, float x, float y);

	//이미지 키값으로 찾기
	towerBase* findTower(string strKey);
	//이미지 키값으로 찾기
	towerBase* copyTower(string strKey, float x, float y);
	//이미지 키값으로 삭제
	BOOL deleteTower(string strKey);
	//이미지 전체 삭제
	BOOL deleteAll(void);

	//void setPosition(string strKey, float x, float y);

	//void linkGameStage(gameStage* stage);


	towerManager();
	~towerManager();
};

