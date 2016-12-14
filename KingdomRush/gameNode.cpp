#include "stdafx.h"
#include "gameNode.h"
gameNode::gameNode()
{
}
gameNode::~gameNode()
{
}
//==================================================================
//		## ���̻� ������, �Ҹ��ڴ� ������� �ʴ´� ##
//==================================================================

//==================================================================
//		## �ʱ�ȭ ## init(void)
//==================================================================
HRESULT gameNode::init(void)
{
	SetTimer(_hWnd, 1, 10, NULL);			//Ÿ�̸� �ʱ�ȭ
	_managerInit = false;
	
	return S_OK;
}

//==================================================================
//		## �ʱ�ȭ ## init(bool managerInit)
//==================================================================
HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if (managerInit)
	{
		SetTimer(_hWnd, 1, 10, NULL);			//Ÿ�̸� �ʱ�ȭ
		KEYMANAGER->init();						//Ű�Ŵ��� �ʱ�ȭ
		IMAGEMANAGER->init();					//�̹����Ŵ��� �ʱ�ȭ
		TIMEMANAGER->init();					//Ÿ�ӸŴ��� �ʱ�ȭ
		TXTDATA->init();						//�ؽ�Ʈ ������ ����
		INIDATA->init();						//ini ������ �ʱ�ȭ
		SCENEMANAGER->init();					//�� �Ŵ��� �ʱ�ȭ
		SOUNDMANAGER->init();					//���� �Ŵ��� �ʱ�ȭ
		EFFECTMANAGER->init();					//����Ʈ �Ŵ��� �ʱ�ȭ
		ANIMANAGER->init();						//���� �Ŵ��� �ʱ�ȭ
		TOWERMANAGER->init();
		PLAYERUNITMANAGER->init();
		ENEMYUNITMANAGER->init();
	}

	return S_OK;
}

//==================================================================
//		## ���� ## release(void)
//==================================================================
void gameNode::release(void)
{
	if (_managerInit)
	{
		//Ÿ�̸� ����
		KillTimer(_hWnd, 1);

		//Ű�Ŵ��� ����
		KEYMANAGER->releaseSingleton();
		//�̹����Ŵ��� ����
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
		//Ÿ�ӸŴ��� ����
		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();
		//�ؽ�Ʈ������ ����
		TXTDATA->releaseSingleton();
		//INI ������ ����
		INIDATA->releaseSingleton();
		//���޴��� ����
		SCENEMANAGER->release();
		SCENEMANAGER->releaseSingleton();
		//����Ŵ��� ����
		SOUNDMANAGER->release();
		SOUNDMANAGER->releaseSingleton();
		//����Ʈ �Ŵ��� ����
		EFFECTMANAGER->release();
		EFFECTMANAGER->releaseSingleton();
		//���ϸ޴��� ����
		ANIMANAGER->release();
		ANIMANAGER->releaseSingleton();

		TOWERMANAGER->release();
		TOWERMANAGER->releaseSingleton();

		PLAYERUNITMANAGER->release();
		PLAYERUNITMANAGER->releaseSingleton();

		ENEMYUNITMANAGER->release();
		ENEMYUNITMANAGER->releaseSingleton();
	}
	
	//DC ����
	ReleaseDC(_hWnd, _hdc);
}

//==================================================================
//		## ������Ʈ ## update(void)
//==================================================================
void gameNode::update(void)
{
	//���ΰ�ħ(���߿� ���� Ÿ�̸Ӹ� ������ �����Ѵ�)
	//InvalidateRect(_hWnd, NULL, FALSE);
}

//==================================================================
//		## ���� ## render(void)//�Ű����� HDC hdc�� ����� ����ƽ���� ���鼭 ����.
//==================================================================
void gameNode::render(void)
{
}

//==================================================================
//		## ���� ���ν��� ## 
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