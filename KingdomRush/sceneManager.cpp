#include "stdafx.h"
#include "sceneManager.h"
#include "gameNode.h"
#include "mainPage.h"
#include "stageBase.h"

sceneManager::sceneManager()
{
}
sceneManager::~sceneManager()
{
}

//����ƽ ���� �ʱ�ȭ
gameNode* sceneManager::_currentScene = NULL;

HRESULT sceneManager::init(void)
{
	return S_OK;
}

void sceneManager::release(void)
{
	//�ݺ��ڸ� �̿��ؼ� ���� �ϳ��� ���鼭 ��������
	miSceneList iter = _mSceneList.begin();

	for (; iter != _mSceneList.end();)
	{
		//����
		if (iter->second != NULL)
		{
			if (iter->second == _currentScene) iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mSceneList.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	_mSceneList.clear();
}

void sceneManager::update(void)
{
	if (_currentScene) _currentScene->update();
}

void sceneManager::render(void)
{
	if (_currentScene) _currentScene->render();
}


//���߰�
gameNode* sceneManager::addScene(string sceneName, gameNode* scene)
{
	if (!scene) return NULL;
	_mSceneList.insert(make_pair(sceneName, scene));
	return scene;
}


//������
HRESULT sceneManager::changeScene(string sceneName)
{
	miSceneList find = _mSceneList.find(sceneName);

	//��ã�� ���
	if (find == _mSceneList.end()) return E_FAIL;

	//�ٲٷ��� ���� ������� ���� ���
	if (find->second == _currentScene) return E_FAIL;

	//����������� ������ ������ �ʱ�ȭ �ϰ� ����������
	if (SUCCEEDED(find->second->init()))
	{
		//Ȥ�ó� �������� ������ ������ �ϰ�
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}

//����� ������ �ҷ�����
//������������ ���ڷ� �־����!!!
HRESULT sceneManager::loadMainPage(string sceneName, int slot)
{
	miSceneList find = _mSceneList.find(sceneName);

	//��ã�� ���
	if (find == _mSceneList.end()) return E_FAIL;

	//�ٲٷ��� ���� ������� ���� ���
	if (find->second == _currentScene) return E_FAIL;

	//����������� ������ ������ �ʱ�ȭ �ϰ� ����������
	//������������ ����ȯ�ؼ� ��ü������ ������ �ʱ�ȭ�ΤФ�
	if (SUCCEEDED(((mainPage*)(find->second))->init(slot)))
	{
		//Ȥ�ó� �������� ������ ������ �ϰ�
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}


//����� ������ �ҷ�����
//������������ ���ڷ� �־����!!!
HRESULT sceneManager::loadMainPage(int slot)
{
	miSceneList find = _mSceneList.find("����ȭ��");

	//��ã�� ���
	if (find == _mSceneList.end()) return E_FAIL;

	//�ٲٷ��� ���� ������� ���� ���
	if (find->second == _currentScene) return E_FAIL;

	//����������� ������ ������ �ʱ�ȭ �ϰ� ����������
	//������������ ����ȯ�ؼ� ��ü������ ������ �ʱ�ȭ�ΤФ�
	if (SUCCEEDED(((mainPage*)(find->second))->init(slot)))
	{
		((mainPage*)(find->second))->setFlag();
		((mainPage*)(find->second))->sumStar();
		//Ȥ�ó� �������� ������ ������ �ϰ�
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}

HRESULT sceneManager::loadMainPage(vector<int> _vStageInfo)
{
	miSceneList find = _mSceneList.find("����ȭ��");

	//��ã�� ���
	if (find == _mSceneList.end()) return E_FAIL;

	//�ٲٷ��� ���� ������� ���� ���
	if (find->second == _currentScene) return E_FAIL;

	//����������� ������ ������ �ʱ�ȭ �ϰ� ����������
	//������������ ����ȯ�ؼ� ��ü������ ������ �ʱ�ȭ�ΤФ�
	int slotNum = ((mainPage*)(find->second))->getSlotNum();

	if (SUCCEEDED(((mainPage*)(find->second))->init(slotNum, _vStageInfo)))
	{
		//Ȥ�ó� �������� ������ ������ �ϰ�
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}

HRESULT sceneManager::loadMainPage()
{
	miSceneList find = _mSceneList.find("����ȭ��");

	//��ã�� ���
	if (find == _mSceneList.end()) return E_FAIL;

	//�ٲٷ��� ���� ������� ���� ���
	if (find->second == _currentScene) return E_FAIL;

	//����������� ������ ������ �ʱ�ȭ �ϰ� ����������
	//������������ ����ȯ�ؼ� ��ü������ ������ �ʱ�ȭ�ΤФ�
	int slotNum = ((mainPage*)(find->second))->getSlotNum();
	STAGE_INFO stageInfo[8];
	memcpy(stageInfo, ((mainPage*)(find->second))->getStageInfo(), 8 * sizeof(STAGE_INFO));
	UPGRADE_INFO upgradeInfo[30];
	memcpy(upgradeInfo, ((mainPage*)(find->second))->getUpgradeInfo(), 30 * sizeof(UPGRADE_INFO));

	if (SUCCEEDED(((mainPage*)(find->second))->init()))
	{
		((mainPage*)(find->second))->setSlotNum(slotNum);
		((mainPage*)(find->second))->setStageInfo(stageInfo);
		((mainPage*)(find->second))->setUpgradeInfo(upgradeInfo);
		((mainPage*)(find->second))->setFlag();
		((mainPage*)(find->second))->sumStar();
		//Ȥ�ó� �������� ������ ������ �ϰ�
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}

HRESULT sceneManager::continueMainPage()
{
	miSceneList find = _mSceneList.find("����ȭ��");

	//��ã�� ���
	if (find == _mSceneList.end()) return E_FAIL;

	//�ٲٷ��� ���� ������� ���� ���
	if (find->second == _currentScene) return E_FAIL;

	//����������� ������ ������ �ʱ�ȭ �ϰ� ����������
	//������������ ����ȯ�ؼ� ��ü������ ������ �ʱ�ȭ�ΤФ�
	int stageNum = ((stageBase*)(_currentScene))->getCurrentStageNum();
	int starNum = ((stageBase*)(_currentScene))->getStarNum();

	int slotNum = ((mainPage*)(find->second))->getSlotNum();
	STAGE_INFO stageInfo[8];
	memcpy(stageInfo, ((mainPage*)(find->second))->getStageInfo(), 8 * sizeof(STAGE_INFO));
	UPGRADE_INFO upgradeInfo[30];
	memcpy(upgradeInfo, ((mainPage*)(find->second))->getUpgradeInfo(), 30 * sizeof(UPGRADE_INFO));

	if (SUCCEEDED(((mainPage*)(find->second))->init()))
	{
		((mainPage*)(find->second))->setSlotNum(slotNum);
		((mainPage*)(find->second))->setStageInfo(stageInfo);
		((mainPage*)(find->second))->setStageInfo(stageNum, starNum);
		((mainPage*)(find->second))->setUpgradeInfo(upgradeInfo);
		((mainPage*)(find->second))->setFlag();
		((mainPage*)(find->second))->sumStar();
		//Ȥ�ó� �������� ������ ������ �ϰ�
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}