// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <Windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>


// C++ ��Ÿ�� ��� �����Դϴ�.
#include <iostream>
// ���ֻ���ϴ� STL
#include <string>
#include <vector>
#include <map>


//==================================================================
//		## ���� ���� ��������� �̰��� �߰��Ѵ� ##
//==================================================================
#include "commonMacroFunction.h"
#include "keyManager.h"
#include "randomFunction.h"
#include "imageManager.h"
#include "utils.h"
#include "timeManager.h"
#include "txtData.h"
#include "iniData.h"
#include "sceneManager.h"
#include "soundManager.h"
#include "effectManager.h"
#include "animationManager.h"
#include "towerManager.h"
#include "playerUnitManager.h"
#include "enemyUnitManager.h"
#include "arrow.h"

//==================================================================
//		## ���ӽ����̽��� �߰��Ѵ� ##
//==================================================================
using namespace MY_UTIL;

//==================================================================
//		## �̱����� �߰��Ѵ� ##
//==================================================================
#define KEYMANAGER keyManager::getSingleton()
#define RND randomFunction::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define INIDATA iniData::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define ANIMANAGER animationManager::getSingleton()
#define TOWERMANAGER towerManager::getSingleton()
#define PLAYERUNITMANAGER playerUnitManager::getSingleton()
#define ENEMYUNITMANAGER enemyUnitManager::getSingleton()

//==================================================================
//		## �����ι� ## (������â �ʱ�ȭ)
//==================================================================
#define WINNAME (LPTSTR)(TEXT("Kingdom Rush v.1.0"))
#define WINSTARTX 230
#define WINSTARTY 100
#define WINSIZEX	700
#define WINSIZEY	600
#define WINSTYLE WS_CAPTION | WS_SYSMENU

//==================================================================
//		## ��ũ���Լ� ## (Ŭ�������� �����Ҵ�� �κ� ������ ����Ѵ�)
//==================================================================
#define SAFE_DELETE(p)			{if(p) {delete(p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p)		{if(p) {delete[] (p); (p) = NULL;}}

//==================================================================
//		## �������� ## (Ŭ�������� �����Ҵ�� �κ� ������ ����Ѵ�)
//==================================================================
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
