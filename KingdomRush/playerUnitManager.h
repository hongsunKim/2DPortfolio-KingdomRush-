#pragma once
#include "singletonBase.h"
#include "playerUnitBase.h"
#include "archer.h"
#include "infantry.h"
#include "magician.h"
class playerUnitManager :
	public singletonBase<playerUnitManager>
{
private:
	typedef map<string, playerUnitBase*> mapPlayerUnitList;	//맵으로 만든 타워 목록
	typedef map<string, playerUnitBase*>::iterator mapPlayerUnitIter;

private:
	mapPlayerUnitList _mPlayerUnitList;	//맵으로 구현된 타워 목록

								//gameStage* _linkedGameStage;

public:
	//이미지 초기화
	HRESULT init();
	//이미지 매니져 해제
	void release();

	//키값을 설정해주며 타워 추가
	playerUnitBase* addUnit(string strKey, playerUnitBase* unit);
	playerUnitBase* addUnit(string strKey, playerUnitBase* unit, float x, float y);

	//이미지 키값으로 찾기
	playerUnitBase* findUnit(string strKey);
	//이미지 키값으로 찾기
	playerUnitBase* copyUnit(string strKey, float x, float y);
	//이미지 키값으로 삭제
	BOOL deleteUnit(string strKey);
	//이미지 전체 삭제
	BOOL deleteAll(void);

	void setPosition(string strKey, float x, float y);

	//void linkGameStage(gameStage* stage);


	playerUnitManager();
	~playerUnitManager();
};