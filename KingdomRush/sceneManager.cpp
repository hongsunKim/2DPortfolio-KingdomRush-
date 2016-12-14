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

//什殿峠 痕呪 段奄鉢
gameNode* sceneManager::_currentScene = NULL;

HRESULT sceneManager::init(void)
{
	return S_OK;
}

void sceneManager::release(void)
{
	//鋼差切研 戚遂背辞 己聖 馬蟹梢 宜檎辞 肢仙馬切
	miSceneList iter = _mSceneList.begin();

	for (; iter != _mSceneList.end();)
	{
		//肢薦
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


//樟蓄亜
gameNode* sceneManager::addScene(string sceneName, gameNode* scene)
{
	if (!scene) return NULL;
	_mSceneList.insert(make_pair(sceneName, scene));
	return scene;
}


//樟痕井
HRESULT sceneManager::changeScene(string sceneName)
{
	miSceneList find = _mSceneList.find(sceneName);

	//公達精 井酔
	if (find == _mSceneList.end()) return E_FAIL;

	//郊荷形澗 樟引 薄仙樟戚 旭精 井酔
	if (find->second == _currentScene) return E_FAIL;

	//食奄猿走神檎 庚薦亜 蒸生艦 段奄鉢 馬壱 痕井背爽切
	if (SUCCEEDED(find->second->init()))
	{
		//箸獣蟹 奄糎樟戚 赤生檎 険軒綜 馬壱
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}

//煽舌吉 汽戚斗 災君神奄
//五昔凪戚走幻 昔切稽 隔嬢醤敗!!!
HRESULT sceneManager::loadMainPage(string sceneName, int slot)
{
	miSceneList find = _mSceneList.find(sceneName);

	//公達精 井酔
	if (find == _mSceneList.end()) return E_FAIL;

	//郊荷形澗 樟引 薄仙樟戚 旭精 井酔
	if (find->second == _currentScene) return E_FAIL;

	//食奄猿走神檎 庚薦亜 蒸生艦 段奄鉢 馬壱 痕井背爽切
	//五昔凪戚走稽 莫痕発背辞 切端旋生稽 竺舛吉 段奄鉢稽ばば
	if (SUCCEEDED(((mainPage*)(find->second))->init(slot)))
	{
		//箸獣蟹 奄糎樟戚 赤生檎 険軒綜 馬壱
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}


//煽舌吉 汽戚斗 災君神奄
//五昔凪戚走幻 昔切稽 隔嬢醤敗!!!
HRESULT sceneManager::loadMainPage(int slot)
{
	miSceneList find = _mSceneList.find("五昔鉢檎");

	//公達精 井酔
	if (find == _mSceneList.end()) return E_FAIL;

	//郊荷形澗 樟引 薄仙樟戚 旭精 井酔
	if (find->second == _currentScene) return E_FAIL;

	//食奄猿走神檎 庚薦亜 蒸生艦 段奄鉢 馬壱 痕井背爽切
	//五昔凪戚走稽 莫痕発背辞 切端旋生稽 竺舛吉 段奄鉢稽ばば
	if (SUCCEEDED(((mainPage*)(find->second))->init(slot)))
	{
		((mainPage*)(find->second))->setFlag();
		((mainPage*)(find->second))->sumStar();
		//箸獣蟹 奄糎樟戚 赤生檎 険軒綜 馬壱
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}

HRESULT sceneManager::loadMainPage(vector<int> _vStageInfo)
{
	miSceneList find = _mSceneList.find("五昔鉢檎");

	//公達精 井酔
	if (find == _mSceneList.end()) return E_FAIL;

	//郊荷形澗 樟引 薄仙樟戚 旭精 井酔
	if (find->second == _currentScene) return E_FAIL;

	//食奄猿走神檎 庚薦亜 蒸生艦 段奄鉢 馬壱 痕井背爽切
	//五昔凪戚走稽 莫痕発背辞 切端旋生稽 竺舛吉 段奄鉢稽ばば
	int slotNum = ((mainPage*)(find->second))->getSlotNum();

	if (SUCCEEDED(((mainPage*)(find->second))->init(slotNum, _vStageInfo)))
	{
		//箸獣蟹 奄糎樟戚 赤生檎 険軒綜 馬壱
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}

HRESULT sceneManager::loadMainPage()
{
	miSceneList find = _mSceneList.find("五昔鉢檎");

	//公達精 井酔
	if (find == _mSceneList.end()) return E_FAIL;

	//郊荷形澗 樟引 薄仙樟戚 旭精 井酔
	if (find->second == _currentScene) return E_FAIL;

	//食奄猿走神檎 庚薦亜 蒸生艦 段奄鉢 馬壱 痕井背爽切
	//五昔凪戚走稽 莫痕発背辞 切端旋生稽 竺舛吉 段奄鉢稽ばば
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
		//箸獣蟹 奄糎樟戚 赤生檎 険軒綜 馬壱
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}

HRESULT sceneManager::continueMainPage()
{
	miSceneList find = _mSceneList.find("五昔鉢檎");

	//公達精 井酔
	if (find == _mSceneList.end()) return E_FAIL;

	//郊荷形澗 樟引 薄仙樟戚 旭精 井酔
	if (find->second == _currentScene) return E_FAIL;

	//食奄猿走神檎 庚薦亜 蒸生艦 段奄鉢 馬壱 痕井背爽切
	//五昔凪戚走稽 莫痕発背辞 切端旋生稽 竺舛吉 段奄鉢稽ばば
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
		//箸獣蟹 奄糎樟戚 赤生檎 険軒綜 馬壱
		if (_currentScene) _currentScene->release();
		_currentScene = find->second;

		return S_OK;
	}
	return E_FAIL;
}