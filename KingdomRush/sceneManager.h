#pragma once
#include "singletonBase.h"
//==================================================================
//		## sceneManager ## (씬 매니져)
//==================================================================



//게임노드 클래스 전방선언
class gameNode;
class mainPage;

class sceneManager : public singletonBase<sceneManager>
{
private:
	typedef map<string, gameNode*> mSceneList;
	typedef map<string, gameNode*>::iterator miSceneList;

private:
	static gameNode* _currentScene;		//현재씬
	mSceneList _mSceneList;				//씬들(등록된)

	

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//씬추가
	gameNode* addScene(string sceneName, gameNode* scene);

	//씬변경
	HRESULT changeScene(string sceneName);

	//저장데이터 로드용 씬 변경
	HRESULT loadMainPage(string sceneName, int slot);
	HRESULT loadMainPage();
	HRESULT loadMainPage(int slot);
	HRESULT loadMainPage(vector<int> _vStageInfo);
	HRESULT continueMainPage();

	sceneManager();
	~sceneManager();
};

