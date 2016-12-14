#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}

//==================================================================
//		## 초기화 ## init(void)
//==================================================================
HRESULT mainGame::init(void)
{
	gameNode::init(true);
	//이곳에서 초기화를 한다

	//씬추가
	SCENEMANAGER->addScene("시작화면", new startPage);
	SCENEMANAGER->addScene("크레딧화면", new creditPage);
	SCENEMANAGER->addScene("메인화면", new mainPage);
	SCENEMANAGER->addScene("스테이지1", new stage1);
	SCENEMANAGER->addScene("스테이지2", new stage2);

	//현재씬 설정
	SCENEMANAGER->changeScene("시작화면");

	return S_OK;
}

//==================================================================
//		## 해제 ## release(void)
//==================================================================
void mainGame::release(void)
{
	gameNode::release();
	//이미지 클래스 나갈때까진 사용할 일 없다
	SCENEMANAGER->release();

}

//==================================================================
//		## 업데이트 ## update(void)
//==================================================================
void mainGame::update(void)
{
	gameNode::update();
	//이곳에서 계산식, 키보드, 마우스등등 업데이트를 한다

	SCENEMANAGER->update();
	
	//EFFECTMANAGER->update();

	//ANIMANAGER->update();
}

//==================================================================
//		## 렌더 ## render(HDC hdc)
//==================================================================
void mainGame::render(void)
{
	//흰색 빈 비트맵 (이것도 렌더에 그냥 그대로 둘것!!)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//이곳에서 WM_PAINT에서 했던것을 처리하면 된다
//==================================================================

	SCENEMANAGER->render();

	//EFFECTMANAGER->render();

//==================================================================
	//타임메니저의 렌더(디버그 안보려면 주석)
	/*SetTextColor(getMemDC(), RGB(0, 0, 0));
	wsprintf(debug, "x: %d, y: %d", _ptMouse.x, _ptMouse.y);
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, debug, lstrlen(debug));*/


	//TIMEMANAGER->render(getMemDC());

//==================================================================
	//백버퍼의 내용을 HDC에 그린다 (이것도 렌더에 그냥 둘것!!)
	this->getBackBuffer()->render(getHDC());
}

//==================================================================
//		## 일반함수 ## (너희들이 만든 함수)
//==================================================================
/*


*/