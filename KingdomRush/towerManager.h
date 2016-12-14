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
	typedef map<string, towerBase*> mapTowerList;	//������ ���� Ÿ�� ���
	typedef map<string, towerBase*>::iterator mapTowerIter;

private:
	mapTowerList _mTowerList;	//������ ������ Ÿ�� ���

								//gameStage* _linkedGameStage;

public:
	//�̹��� �ʱ�ȭ
	HRESULT init();
	//�̹��� �Ŵ��� ����
	void release();

	//Ű���� �������ָ� Ÿ�� �߰�
	towerBase* addTower(string strKey, towerBase* tower);
	towerBase* addTower(string strKey, towerBase* tower, float x, float y);

	//�̹��� Ű������ ã��
	towerBase* findTower(string strKey);
	//�̹��� Ű������ ã��
	towerBase* copyTower(string strKey, float x, float y);
	//�̹��� Ű������ ����
	BOOL deleteTower(string strKey);
	//�̹��� ��ü ����
	BOOL deleteAll(void);

	//void setPosition(string strKey, float x, float y);

	//void linkGameStage(gameStage* stage);


	towerManager();
	~towerManager();
};

