#pragma once
#include "gameNode.h"

enum class STARTPAGE
{
	READY,
	START,
	READYSELECT,
	SETSELECT,
	SELECT,
	CLOSE_FOR_CREDIT,
	CLOSE_FOR_MAIN,
	OPEN
};

class startPage :
	public gameNode
{
private:
	//���� ȭ��
	STARTPAGE _currentPage;

	//���� ��üȭ��
	image* _startPageImage;
	image* _titleImage;
	image* _startImage;
	image* _creditImage;
	//���ۻ�Ȳ ��ư��
	RECT _startButton;
	RECT _creditButton;
	//��ư �������� ȿ�� ���� ����
	int _startButtonPos;
	int _creditButtonPos;

	//ũ���� ��Ȳ �̹���
	image* _closeFromCreditImage;
	//ũ���� ��Ȳ ��ư��
	RECT _closeFromCredit;

	//����Ʈ��Ȳ �̹���
	image* _selectBoardImage;
	int _selectBoardPos;
	image* _saveGameImage0;
	image* _saveGameImage1;
	image* _saveGameImage2;
	image* _deleteSaveImage;
	image* _closeFromSelect;
	//����Ʈ��Ȳ ��ư��(�簢���� �������� ��������� ������ ���������� �����ؾ��Ѵ�.)
	RECT _load[3];
	RECT _delete[3];
	int _selectSlotNum;//����Ʈ ���� ��ȣ
	//RECT _closeFromSelect;

	//�������� ������
	image* _leftDoorImage;
	image* _rightDoorImage;
	int _leftDoorPos;
	int _rightDoorPos;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	startPage();
	~startPage();
};

