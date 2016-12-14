#pragma once
#include "singletonBase.h"
#include "enemyUnitBase.h"
#include "goblin.h"
#include "orc.h"
#include "wlilf.h"
class enemyUnitManager :
	public singletonBase<enemyUnitManager>
{
private:
	typedef map<string, enemyUnitBase*> mapEnemyUnitList;	//맵으로 만든 타워 목록
	typedef map<string, enemyUnitBase*>::iterator mapEnemyUnitIter;

private:
	mapEnemyUnitList _mEnemyUnitList;	//맵으로 구현된 타워 목록


public:
	//이미지 초기화
	HRESULT init();
	//이미지 매니져 해제
	void release();

	//키값을 설정해주며 타워 추가
	enemyUnitBase* addUnit(string strKey, enemyUnitBase* unit);
	enemyUnitBase* addUnit(string strKey, enemyUnitBase* unit, float x, float y);

	//이미지 키값으로 찾기
	enemyUnitBase* findUnit(string strKey);
	//이미지 키값으로 찾기
	enemyUnitBase* copyUnit(string strKey, int waveNum = 1);
	//이미지 키값으로 삭제
	BOOL deleteUnit(string strKey);
	//이미지 전체 삭제
	BOOL deleteAll(void);

	void setPosition(string strKey, float x, float y);

	//void linkGameStage(gameStage* stage);


	enemyUnitManager();
	~enemyUnitManager();
};

