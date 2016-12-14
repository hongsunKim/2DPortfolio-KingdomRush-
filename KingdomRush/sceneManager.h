#pragma once
#include "singletonBase.h"
//==================================================================
//		## sceneManager ## (�� �Ŵ���)
//==================================================================



//���ӳ�� Ŭ���� ���漱��
class gameNode;
class mainPage;

class sceneManager : public singletonBase<sceneManager>
{
private:
	typedef map<string, gameNode*> mSceneList;
	typedef map<string, gameNode*>::iterator miSceneList;

private:
	static gameNode* _currentScene;		//�����
	mSceneList _mSceneList;				//����(��ϵ�)

	

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//���߰�
	gameNode* addScene(string sceneName, gameNode* scene);

	//������
	HRESULT changeScene(string sceneName);

	//���嵥���� �ε�� �� ����
	HRESULT loadMainPage(string sceneName, int slot);
	HRESULT loadMainPage();
	HRESULT loadMainPage(int slot);
	HRESULT loadMainPage(vector<int> _vStageInfo);
	HRESULT continueMainPage();

	sceneManager();
	~sceneManager();
};

