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
	typedef map<string, enemyUnitBase*> mapEnemyUnitList;	//������ ���� Ÿ�� ���
	typedef map<string, enemyUnitBase*>::iterator mapEnemyUnitIter;

private:
	mapEnemyUnitList _mEnemyUnitList;	//������ ������ Ÿ�� ���


public:
	//�̹��� �ʱ�ȭ
	HRESULT init();
	//�̹��� �Ŵ��� ����
	void release();

	//Ű���� �������ָ� Ÿ�� �߰�
	enemyUnitBase* addUnit(string strKey, enemyUnitBase* unit);
	enemyUnitBase* addUnit(string strKey, enemyUnitBase* unit, float x, float y);

	//�̹��� Ű������ ã��
	enemyUnitBase* findUnit(string strKey);
	//�̹��� Ű������ ã��
	enemyUnitBase* copyUnit(string strKey, int waveNum = 1);
	//�̹��� Ű������ ����
	BOOL deleteUnit(string strKey);
	//�̹��� ��ü ����
	BOOL deleteAll(void);

	void setPosition(string strKey, float x, float y);

	//void linkGameStage(gameStage* stage);


	enemyUnitManager();
	~enemyUnitManager();
};

