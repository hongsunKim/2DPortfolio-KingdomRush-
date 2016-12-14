#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}

//==================================================================
//		## �ʱ�ȭ ## init(void)
//==================================================================
HRESULT mainGame::init(void)
{
	gameNode::init(true);
	//�̰����� �ʱ�ȭ�� �Ѵ�

	//���߰�
	SCENEMANAGER->addScene("����ȭ��", new startPage);
	SCENEMANAGER->addScene("ũ����ȭ��", new creditPage);
	SCENEMANAGER->addScene("����ȭ��", new mainPage);
	SCENEMANAGER->addScene("��������1", new stage1);
	SCENEMANAGER->addScene("��������2", new stage2);

	//����� ����
	SCENEMANAGER->changeScene("����ȭ��");

	return S_OK;
}

//==================================================================
//		## ���� ## release(void)
//==================================================================
void mainGame::release(void)
{
	gameNode::release();
	//�̹��� Ŭ���� ���������� ����� �� ����
	SCENEMANAGER->release();

}

//==================================================================
//		## ������Ʈ ## update(void)
//==================================================================
void mainGame::update(void)
{
	gameNode::update();
	//�̰����� ����, Ű����, ���콺��� ������Ʈ�� �Ѵ�

	SCENEMANAGER->update();
	
	//EFFECTMANAGER->update();

	//ANIMANAGER->update();
}

//==================================================================
//		## ���� ## render(HDC hdc)
//==================================================================
void mainGame::render(void)
{
	//��� �� ��Ʈ�� (�̰͵� ������ �׳� �״�� �Ѱ�!!)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//�̰����� WM_PAINT���� �ߴ����� ó���ϸ� �ȴ�
//==================================================================

	SCENEMANAGER->render();

	//EFFECTMANAGER->render();

//==================================================================
	//Ÿ�Ӹ޴����� ����(����� �Ⱥ����� �ּ�)
	/*SetTextColor(getMemDC(), RGB(0, 0, 0));
	wsprintf(debug, "x: %d, y: %d", _ptMouse.x, _ptMouse.y);
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, debug, lstrlen(debug));*/


	//TIMEMANAGER->render(getMemDC());

//==================================================================
	//������� ������ HDC�� �׸��� (�̰͵� ������ �׳� �Ѱ�!!)
	this->getBackBuffer()->render(getHDC());
}

//==================================================================
//		## �Ϲ��Լ� ## (������� ���� �Լ�)
//==================================================================
/*


*/