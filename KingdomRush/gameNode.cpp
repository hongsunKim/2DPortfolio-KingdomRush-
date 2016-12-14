#include "stdafx.h"
#include "gameNode.h"
gameNode::gameNode()
{
}
gameNode::~gameNode()
{
}
//==================================================================
//		## 더이상 생성자, 소멸자는 사용하지 않는다 ##
//==================================================================

//==================================================================
//		## 초기화 ## init(void)
//==================================================================
HRESULT gameNode::init(void)
{
	SetTimer(_hWnd, 1, 10, NULL);			//타이머 초기화
	_managerInit = false;
	
	return S_OK;
}

//==================================================================
//		## 초기화 ## init(bool managerInit)
//==================================================================
HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if (managerInit)
	{
		SetTimer(_hWnd, 1, 10, NULL);			//타이머 초기화
		KEYMANAGER->init();						//키매니져 초기화
		IMAGEMANAGER->init();					//이미지매니져 초기화
		TIMEMANAGER->init();					//타임매니져 초기화
		TXTDATA->init();						//텍스트 데이터 세팅
		INIDATA->init();						//ini 데이터 초기화
		SCENEMANAGER->init();					//씬 매니져 초기화
		SOUNDMANAGER->init();					//사운드 매니져 초기화
		EFFECTMANAGER->init();					//이펙트 매니져 초기화
		ANIMANAGER->init();						//에니 매니져 초기화
		TOWERMANAGER->init();
		PLAYERUNITMANAGER->init();
		ENEMYUNITMANAGER->init();
	}

	return S_OK;
}

//==================================================================
//		## 해제 ## release(void)
//==================================================================
void gameNode::release(void)
{
	if (_managerInit)
	{
		//타이머 해제
		KillTimer(_hWnd, 1);

		//키매니져 해제
		KEYMANAGER->releaseSingleton();
		//이미지매니저 해제
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
		//타임매니저 해제
		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();
		//텍스트테이터 해제
		TXTDATA->releaseSingleton();
		//INI 데이터 해제
		INIDATA->releaseSingleton();
		//씬메니져 해제
		SCENEMANAGER->release();
		SCENEMANAGER->releaseSingleton();
		//사운드매니저 해제
		SOUNDMANAGER->release();
		SOUNDMANAGER->releaseSingleton();
		//이펙트 매니저 해제
		EFFECTMANAGER->release();
		EFFECTMANAGER->releaseSingleton();
		//에니메니져 해제
		ANIMANAGER->release();
		ANIMANAGER->releaseSingleton();

		TOWERMANAGER->release();
		TOWERMANAGER->releaseSingleton();

		PLAYERUNITMANAGER->release();
		PLAYERUNITMANAGER->releaseSingleton();

		ENEMYUNITMANAGER->release();
		ENEMYUNITMANAGER->releaseSingleton();
	}
	
	//DC 해제
	ReleaseDC(_hWnd, _hdc);
}

//==================================================================
//		## 업데이트 ## update(void)
//==================================================================
void gameNode::update(void)
{
	//새로고침(나중에 고성능 타이머를 만든후 삭제한다)
	//InvalidateRect(_hWnd, NULL, FALSE);
}

//==================================================================
//		## 렌더 ## render(void)//매개변수 HDC hdc은 백버퍼 스테틱으로 빼면서 변경.
//==================================================================
void gameNode::render(void)
{
}

//==================================================================
//		## 메인 프로시져 ## 
//==================================================================
LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (iMessage)
	{
// 	case WM_TIMER:
// 		this->update();
// 		break;
// 	case WM_PAINT:
// 		hdc = BeginPaint(hWnd, &ps);
// 		this->render();
// 		EndPaint(hWnd, &ps);
// 		break;
	case WM_MOUSEMOVE:
		_ptMouse.x = static_cast<float>LOWORD(lParam);
		_ptMouse.y = static_cast<float>HIWORD(lParam);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}