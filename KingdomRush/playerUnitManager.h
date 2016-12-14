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
	typedef map<string, playerUnitBase*> mapPlayerUnitList;	//������ ���� Ÿ�� ���
	typedef map<string, playerUnitBase*>::iterator mapPlayerUnitIter;

private:
	mapPlayerUnitList _mPlayerUnitList;	//������ ������ Ÿ�� ���

								//gameStage* _linkedGameStage;

public:
	//�̹��� �ʱ�ȭ
	HRESULT init();
	//�̹��� �Ŵ��� ����
	void release();

	//Ű���� �������ָ� Ÿ�� �߰�
	playerUnitBase* addUnit(string strKey, playerUnitBase* unit);
	playerUnitBase* addUnit(string strKey, playerUnitBase* unit, float x, float y);

	//�̹��� Ű������ ã��
	playerUnitBase* findUnit(string strKey);
	//�̹��� Ű������ ã��
	playerUnitBase* copyUnit(string strKey, float x, float y);
	//�̹��� Ű������ ����
	BOOL deleteUnit(string strKey);
	//�̹��� ��ü ����
	BOOL deleteAll(void);

	void setPosition(string strKey, float x, float y);

	//void linkGameStage(gameStage* stage);


	playerUnitManager();
	~playerUnitManager();
};