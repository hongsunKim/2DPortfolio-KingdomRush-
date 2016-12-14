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
	//현재 화면
	STARTPAGE _currentPage;

	//시작 전체화면
	image* _startPageImage;
	image* _titleImage;
	image* _startImage;
	image* _creditImage;
	//시작상황 버튼들
	RECT _startButton;
	RECT _creditButton;
	//버튼 내려오는 효과 위한 변수
	int _startButtonPos;
	int _creditButtonPos;

	//크레딧 상황 이미지
	image* _closeFromCreditImage;
	//크레딧 상황 버튼들
	RECT _closeFromCredit;

	//셀렉트상황 이미지
	image* _selectBoardImage;
	int _selectBoardPos;
	image* _saveGameImage0;
	image* _saveGameImage1;
	image* _saveGameImage2;
	image* _deleteSaveImage;
	image* _closeFromSelect;
	//셀렉트상황 버튼들(사각형이 겹쳐져서 만들어지기 떄문에 영역설정에 주의해야한다.)
	RECT _load[3];
	RECT _delete[3];
	int _selectSlotNum;//셀렉트 슬롯 번호
	//RECT _closeFromSelect;

	//문열리고 닫히기
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

