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

//스태틱 변수 초기화
gameNode* sceneManager::_currentScene = NULL;

HRESULT sceneManager::init(void)
{
	return S_OK;
}

void sceneManager::release(void)
{
	//반복자를 이용해서 맵을 하나씩 돌면서 삭재하자
	miSceneList iter = _mSceneList.begin();

	for (; iter != _mSceneList.end();)
	{
		//삭제
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


//씬추가
gameNode* sceneManager::addScene(string sceneName, gameNode* scene)
{
	if (!scene) return NULL;
	_mSceneList.insert(make_pair(sceneName, scene));
	return scene;
}


//씬변경
HRESULT sceneManager::changeScene(string sceneName)
{
	miSceneList find = _mSceneList.find(sceneName);

	//못찾은 경우
	if (find == _mSceneList.end()) return E_FAIL;

	//바꾸려는 씬과 현재씬이 같은 경우
	if (find->second == _currentScene) return E_FAIL;

	//여기까지오면 문제가 없으니 초기화 하고 변경해주자
	if (SUCCEEDED(find->second->init()))
	{
		//혹시나 기존씬이 있으면 릴리즈 하고
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}

//저장된 데이터 불러오기
//메인페이지만 인자로 넣어야함!!!
HRESULT sceneManager::loadMainPage(string sceneName, int slot)
{
	miSceneList find = _mSceneList.find(sceneName);

	//못찾은 경우
	if (find == _mSceneList.end()) return E_FAIL;

	//바꾸려는 씬과 현재씬이 같은 경우
	if (find->second == _currentScene) return E_FAIL;

	//여기까지오면 문제가 없으니 초기화 하고 변경해주자
	//메인페이지로 형변환해서 자체적으로 설정된 초기화로ㅠㅠ
	if (SUCCEEDED(((mainPage*)(find->second))->init(slot)))
	{
		//혹시나 기존씬이 있으면 릴리즈 하고
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}


//저장된 데이터 불러오기
//메인페이지만 인자로 넣어야함!!!
HRESULT sceneManager::loadMainPage(int slot)
{
	miSceneList find = _mSceneList.find("메인화면");

	//못찾은 경우
	if (find == _mSceneList.end()) return E_FAIL;

	//바꾸려는 씬과 현재씬이 같은 경우
	if (find->second == _currentScene) return E_FAIL;

	//여기까지오면 문제가 없으니 초기화 하고 변경해주자
	//메인페이지로 형변환해서 자체적으로 설정된 초기화로ㅠㅠ
	if (SUCCEEDED(((mainPage*)(find->second))->init(slot)))
	{
		((mainPage*)(find->second))->setFlag();
		((mainPage*)(find->second))->sumStar();
		//혹시나 기존씬이 있으면 릴리즈 하고
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}

HRESULT sceneManager::loadMainPage(vector<int> _vStageInfo)
{
	miSceneList find = _mSceneList.find("메인화면");

	//못찾은 경우
	if (find == _mSceneList.end()) return E_FAIL;

	//바꾸려는 씬과 현재씬이 같은 경우
	if (find->second == _currentScene) return E_FAIL;

	//여기까지오면 문제가 없으니 초기화 하고 변경해주자
	//메인페이지로 형변환해서 자체적으로 설정된 초기화로ㅠㅠ
	int slotNum = ((mainPage*)(find->second))->getSlotNum();

	if (SUCCEEDED(((mainPage*)(find->second))->init(slotNum, _vStageInfo)))
	{
		//혹시나 기존씬이 있으면 릴리즈 하고
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}

HRESULT sceneManager::loadMainPage()
{
	miSceneList find = _mSceneList.find("메인화면");

	//못찾은 경우
	if (find == _mSceneList.end()) return E_FAIL;

	//바꾸려는 씬과 현재씬이 같은 경우
	if (find->second == _currentScene) return E_FAIL;

	//여기까지오면 문제가 없으니 초기화 하고 변경해주자
	//메인페이지로 형변환해서 자체적으로 설정된 초기화로ㅠㅠ
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
		//혹시나 기존씬이 있으면 릴리즈 하고
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}

HRESULT sceneManager::continueMainPage()
{
	miSceneList find = _mSceneList.find("메인화면");

	//못찾은 경우
	if (find == _mSceneList.end()) return E_FAIL;

	//바꾸려는 씬과 현재씬이 같은 경우
	if (find->second == _currentScene) return E_FAIL;

	//여기까지오면 문제가 없으니 초기화 하고 변경해주자
	//메인페이지로 형변환해서 자체적으로 설정된 초기화로ㅠㅠ
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
		//혹시나 기존씬이 있으면 릴리즈 하고
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}