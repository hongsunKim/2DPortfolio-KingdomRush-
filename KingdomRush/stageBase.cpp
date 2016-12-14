#include "stdafx.h"
#include "stageBase.h"

stageBase::stageBase()
{
}

stageBase::~stageBase()
{
}

HRESULT stageBase::init(void)
{
	_stagePage = STAGEPAGE::OPEN;

	_pauseScreen = IMAGEMANAGER->addImage("일시정지화면", "image/스테이지/일시정지화면.bmp", 700, 600, FALSE, RGB(1, 0, 0));
	_pauseButtonImage = IMAGEMANAGER->addFrameImage("일시정지버튼", "image/스테이지/일시정지버튼.bmp", 117, 36, 3, 1, TRUE, RGB(1, 0, 0));
	_pauseButtonRect = RectMake(605, 10, 39, 36);
	_pauseBoard = IMAGEMANAGER->addImage("일시정지알림판", "image/스테이지/일시정지알림판.bmp", 195, 71, TRUE, RGB(1, 0, 0));

	_optionButtonImage = IMAGEMANAGER->addFrameImage("옵션버튼", "image/스테이지/옵션버튼.bmp", 117, 36, 3, 1, TRUE, RGB(1, 0, 0));
	_optionButtonRect = RectMake(650, 10, 39, 36);
	_optionBoard = IMAGEMANAGER->addImage("옵션알림판", "image/스테이지/옵션보드.bmp", 500, 500, TRUE, RGB(1, 0, 0));
	_optionBoardY = -500;

	_defeatBoard = IMAGEMANAGER->addImage("패배판", "image/스테이지/패배판.bmp", 524, 357, TRUE, RGB(1, 0, 0));
	_defeatBoardY = -357;

	_tryAgainButtonImage = IMAGEMANAGER->addFrameImage("재도전버튼", "image/스테이지/재도전버튼.bmp", 179, 159, 1, 3,  FALSE, RGB(1, 0, 0));
	_tryAgainButtonRect = RectMake(350 - 100 - 179 / 2, 340, 179, 53);

	_giveUpButtonImage = IMAGEMANAGER->addFrameImage("포기버튼", "image/스테이지/포기버튼.bmp", 179, 159, 1, 3, FALSE, RGB(1, 0, 0));
	_giveUpButtonRect = RectMake(350 + 100 - 179 / 2, 340, 179, 53);

	_victoryImage = IMAGEMANAGER->addFrameImage("승리", "image/스테이지/승리.bmp", 6000, 400, 12, 1, TRUE, RGB(0, 0, 0));
	_victoryFrame = 0;
	_frameCount = 0;
	_victoryStarImage = IMAGEMANAGER->addImage("승리별", "image/스테이지/승리별.bmp", 576, 450, TRUE, RGB(83, 55, 13));
	_victoryStarAni.init(576, 450, 6, 9);
	_victoryStarAni.setDefPlayFrame(FALSE, FALSE);
	_victoryStarAni.setFPS(1);
	_stopStar = false;

	_leftFlowerPowderImage = IMAGEMANAGER->addFrameImage("꽃가루(좌)", "image/스테이지/꽃가루(좌흑).bmp", 11562, 490, 41, 1, TRUE, RGB(0, 0, 0));
	_rightFlowerPowderImage = IMAGEMANAGER->addFrameImage("꽃가루(우)", "image/스테이지/꽃가루(우흑).bmp", 11562, 490, 41, 1, TRUE, RGB(0, 0, 0));
	_flowerPowderFrame = 0;
	_flowerPowderFrameCount = 0;

	_continueButtonImage = IMAGEMANAGER->addFrameImage("컨티뉴버튼", "image/스테이지/컨티뉴버튼.bmp", 179, 159, 1, 3, TRUE, RGB(1, 0, 0));
	_reStartButtonImage = IMAGEMANAGER->addFrameImage("스테이지재시작버튼", "image/스테이지/재시작버튼.bmp", 179, 162, 1, 3, TRUE, RGB(1, 0, 0));
	_continueButtonY = _reStartButtonY = 250;
	_continueButtonRect = RectMake(260, 370, 179, 159);
	_reStartButtonRect = RectMake(260, 440, 179, 162);

	_resumeButtonImage = IMAGEMANAGER->addFrameImage("스테이지이어재생버튼", "image/스테이지/다시재생버튼.bmp", 179, 162, 1, 3, TRUE, RGB(1, 0, 0));
	_resumeButtonRect = RectMake(WINSIZEX / 2 - 179 / 2, 200, 179, 54);
	_quitButtonImage = IMAGEMANAGER->addFrameImage("스테이지취소버튼", "image/스테이지/취소버튼.bmp", 179, 162, 1, 3, TRUE, RGB(1, 0, 0));
	_quitButtonRect = RectMake(WINSIZEX / 2 - 179 / 2, 300, 179, 54);
	_restartButtonImage = IMAGEMANAGER->addFrameImage("스테이지재시작버튼", "image/스테이지/재시작버튼.bmp", 179, 162, 1, 3, TRUE, RGB(1, 0, 0));
	_restartButtonRect = RectMake(WINSIZEX / 2 - 179 / 2, 400, 179, 54);

	_leftDoorImage = IMAGEMANAGER->addImage("왼쪽문", "image/씬체인지/왼쪽문.bmp", 470, 655, TRUE, RGB(1, 0, 0));
	_rightDoorImage = IMAGEMANAGER->addImage("오른쪽문", "image/씬체인지/오른쪽문.bmp", 464, 655, TRUE, RGB(1, 0, 0));
	_leftDoorPos = -110;
	_rightDoorPos = 340;

	_stageInfo = IMAGEMANAGER->addImage("스테이지정보", "image/스테이지/스테이지정보.bmp", 155, 54, TRUE, RGB(1, 0, 0));

	_underBar = IMAGEMANAGER->addImage("하단바", "image/스테이지/하단바.bmp", 700, 35, TRUE, RGB(1, 0, 0));
	_information = IMAGEMANAGER->addImage("정보창", "image/스테이지/정보창.bmp", 412, 36, TRUE, RGB(1, 0, 0));
	_waveButtonBoard = IMAGEMANAGER->addImage("웨이브버튼판", "image/스테이지/웨이브버튼판.bmp", 74, 56, TRUE, RGB(1, 0, 0));
	_waveButton = IMAGEMANAGER->addImage("웨이브버튼기본", "image/스테이지/웨이브버튼기본.bmp", 39, 34, FALSE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("웨이브버튼오프", "image/스테이지/웨이브버튼오프.bmp", 39, 34, FALSE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("웨이브버튼온", "image/스테이지/웨이브버튼온.bmp", 39, 34, FALSE, RGB(1, 0, 0));
	_waveButtonRect = RectMake(637, 553, 39, 34);
	_waveStart = false;
	_waveButtonAvailable = true;

	_fullLife = _currentLife = 20;

	_victory = false;

	_selectedTower = nullptr;

	_firstTouch = true;

	setStageObject();

	_waveTime = 45;

	return S_OK;
}
void stageBase::release(void)
{
	deleteAll();
}
void stageBase::update(void)
{
	switch (_stagePage)
	{
	case STAGEPAGE::OPEN:
		_leftDoorPos -= 10;
		_rightDoorPos += 10;
		if (_leftDoorPos < -470 && _rightDoorPos > 700)
		{
			_leftDoorPos = -470;
			_rightDoorPos = 700;
			_stagePage = STAGEPAGE::PLAY;
		}
		break;
	case STAGEPAGE::PLAY:
		//입력X 업데이트
		checkTarget();
		//여기에서 게임 오브젝트 모두 업데이트
		updateNormal();

		if (_waveStart)
		{
			if (_currentWaveNum >= _fullWaveNum)
			{
				_waveButtonAvailable = false;
			}
			else
			{
				waveCount();
			}
			generateWave();
			++_waveCountTime;
		}

		if (_waveButtonAvailable)
		{
			if (PtInRect(&_waveButtonRect, _ptMouse))
				_waveButton = IMAGEMANAGER->findImage("웨이브버튼온");
			else
				_waveButton = IMAGEMANAGER->findImage("웨이브버튼기본");
		}
		else
			_waveButton = IMAGEMANAGER->findImage("웨이브버튼오프");

		if (PtInRect(&_pauseButtonRect, _ptMouse))
			_pauseButtonImage->setFrameX(1);
		else
			_pauseButtonImage->setFrameX(0);
		if (PtInRect(&_optionButtonRect, _ptMouse))
			_optionButtonImage->setFrameX(1);
		else
			_optionButtonImage->setFrameX(0);



		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			updateOnceKeyDown();
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			if (PtInRect(&_pauseButtonRect, _ptMouse))
			{
				_pauseButtonImage->setFrameX(0);
				_stagePage = STAGEPAGE::PAUSE;
			}
			if (PtInRect(&_optionButtonRect, _ptMouse))
			{
				_optionButtonImage->setFrameX(0);
				_stagePage = STAGEPAGE::SET_OPTIONS;
			}

			if (_waveButtonAvailable && PtInRect(&_waveButtonRect, _ptMouse))
			{
				_waveButtonAvailable = false;
				_waveStart = true;

				if (_currentWaveNum != 0)
				{
					_gold = _gold + 30 * ((2101 - _waveCountTime) / 1500);
				}

				_waveCountTime = 0;
				_waveCurrentTime = 0;
				++_currentWaveNum;
			}
			updateOnceKeyUp();
			towerChange();
		}
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&_pauseButtonRect, _ptMouse))
				_pauseButtonImage->setFrameX(2);
			else
				_pauseButtonImage->setFrameX(0);
			if (PtInRect(&_optionButtonRect, _ptMouse))
				_optionButtonImage->setFrameX(2);
			else
				_optionButtonImage->setFrameX(0);

			updateStayKeyDown();
		}

		/////////////////////////////////////////////////////////////////////////////////
		if (_currentWaveNum >= _fullWaveNum)
		{
			STAGEPAGE temp = _stagePage;
			_stagePage = STAGEPAGE::VICTORY;
			for (int i = 0; i < _vEnemyUnit.size(); i++)
			{
				if (_vEnemyUnit[i]->getWaveNum() == _fullWaveNum)
				{
					if (_vEnemyUnit[i]->getUnitState() != UNIT_STATE::COUNTED)
					{
						_stagePage = temp;
						break;
					}
				}
			}
		}

		/*if (TIMEMANAGER->getWorlTime() >= 240)
		{
			int a = 0;
			int b = 12;
			_currentLife = 12;
		}*/

		if (_currentLife <= 0)
		{
			_stagePage = STAGEPAGE::SET_DEFEAT;
		}

		break;
	case STAGEPAGE::PAUSE:
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			_stagePage = STAGEPAGE::PLAY;
		}
		break;
	case STAGEPAGE::SET_OPTIONS:
		_optionBoardY += 20;

		if (_optionBoardY > 50)
		{
			_optionBoardY = 50;
			_stagePage = STAGEPAGE::OPTIONS;
		}
		break;
	case STAGEPAGE::SET_DEFEAT:
		_defeatBoardY += 20;

		if (_defeatBoardY > 70)
		{
			_defeatBoardY = 70;
			_stagePage = STAGEPAGE::DEFEAT;
		}
		break;
		///////////////////////////////////////////////////////////////////////////////////////
	case STAGEPAGE::VICTORY:

		++_frameCount;
		++_flowerPowderFrameCount;
		if (_flowerPowderFrameCount > 1)
		{
			if (_flowerPowderFrame < 40)
			{
				++_flowerPowderFrame;
			}
			_flowerPowderFrameCount = 0;
		}
		if (_frameCount > 2)
		{
			if (_victoryFrame < 12)
			{
				++_victoryFrame;
			}
			_frameCount = 0;
		}
		if (_victoryFrame == 12)
		{
			
			if (!_stopStar)
			{
				_victoryStarAni.start();
				_victoryStarAni.frameUpdate(0.5);
			}
			switch (_currentLife / 9)
			{
			case 0:
				_star = 1;
				if (_victoryStarAni.getFramePos().x == 0 && _victoryStarAni.getFramePos().y == 150)
				{
					_victoryStarAni.pause();
					_stopStar = true;
				}
				break;
			case 1:
				_star = 2;
				if (_victoryStarAni.getFramePos().x == 0 && _victoryStarAni.getFramePos().y == 300)
				{
					_victoryStarAni.pause();
					_stopStar = true;
				}
				break;
			case 2:
				_star = 3;
				if (_victoryStarAni.getFramePos().x == 480 && _victoryStarAni.getFramePos().y == 400)
				{
					_victoryStarAni.pause();
					_stopStar = true;
				}
				break;
			}
		}

		if (_stopStar)
		{
			if (_continueButtonY < 370)
			{
				_continueButtonY += 5;
			}
			if (_reStartButtonY < 440)
			{
				_reStartButtonY += 5;
			}
			else
			{
				_reStartButtonY = _continueButtonY = 250;
				_stagePage = STAGEPAGE::SET_VICTORY;
			}
		}
		break;
	case STAGEPAGE::SET_VICTORY:

		if (PtInRect(&_continueButtonRect, _ptMouse))
		{
			_continueButtonImage->setFrameY(1);
			_reStartButtonImage->setFrameY(0);
		}
		else
		{
			_continueButtonImage->setFrameY(0);
		}

		if (PtInRect(&_reStartButtonRect, _ptMouse))
		{
			_reStartButtonImage->setFrameY(1);
			_continueButtonImage->setFrameY(0);
		}
		else
			_reStartButtonImage->setFrameY(0);


		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&_continueButtonRect, _ptMouse))
			{
				_continueButtonImage->setFrameY(2);
				_reStartButtonImage->setFrameY(0);
			}
			else
				_continueButtonImage->setFrameY(0);

			if (PtInRect(&_reStartButtonRect, _ptMouse))
			{
				_reStartButtonImage->setFrameY(2);
				_continueButtonImage->setFrameY(0);
			}
			else
				_reStartButtonImage->setFrameY(0);
		}

		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			if (PtInRect(&_continueButtonRect, _ptMouse))
			{
				_continueButtonImage->setFrameY(0);
				_reStartButtonImage->setFrameY(0);
				_stagePage = STAGEPAGE::VICTORY_CONTINUE;
			}
			if (PtInRect(&_reStartButtonRect, _ptMouse))
			{
				_continueButtonImage->setFrameY(0);
				_reStartButtonImage->setFrameY(0);
				_stagePage = STAGEPAGE::VICTORY_RESTART;
			}
		}
		break;
	case STAGEPAGE::DEFEAT:
		if (PtInRect(&_tryAgainButtonRect, _ptMouse))
			_tryAgainButtonImage->setFrameY(1);
		else
			_tryAgainButtonImage->setFrameY(0);
		if (PtInRect(&_giveUpButtonRect, _ptMouse))
			_giveUpButtonImage->setFrameY(1);
		else
			_giveUpButtonImage->setFrameY(0);

		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			if (PtInRect(&_tryAgainButtonRect, _ptMouse))
			{
				_tryAgainButtonImage->setFrameY(0);
				_stagePage = STAGEPAGE::CLOSE_FOR_RETRY;
			}

			if (PtInRect(&_giveUpButtonRect, _ptMouse))
			{
				_giveUpButtonImage->setFrameY(0);
				_stagePage = STAGEPAGE::GIVE_UP;
			}
		}

		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&_tryAgainButtonRect, _ptMouse))
				_tryAgainButtonImage->setFrameY(2);
			else
				_tryAgainButtonImage->setFrameY(0);
			if (PtInRect(&_giveUpButtonRect, _ptMouse))
				_giveUpButtonImage->setFrameY(2);
			else
				_giveUpButtonImage->setFrameY(0);
		}
		break;
	case STAGEPAGE::OPTIONS:
		if (PtInRect(&_resumeButtonRect, _ptMouse))
			_resumeButtonImage->setFrameY(1);
		else
			_resumeButtonImage->setFrameY(0);
		if (PtInRect(&_quitButtonRect, _ptMouse))
			_quitButtonImage->setFrameY(1);
		else
			_quitButtonImage->setFrameY(0);
		if (PtInRect(&_restartButtonRect, _ptMouse))
			_restartButtonImage->setFrameY(1);
		else
			_restartButtonImage->setFrameY(0);

		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			if (PtInRect(&_resumeButtonRect, _ptMouse))
			{
				_resumeButtonImage->setFrameY(0);
				_stagePage = STAGEPAGE::FOLD_OPTIONS;
			}
			if (PtInRect(&_quitButtonRect, _ptMouse))
			{
				_quitButtonImage->setFrameY(0);
				_stagePage = STAGEPAGE::CLOSE_FOR_MENU;
			}
			if (PtInRect(&_restartButtonRect, _ptMouse))
			{
				_restartButtonImage->setFrameY(0);
				_stagePage = STAGEPAGE::CLOSE_FOR_RESTART;
			}
		}

		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&_resumeButtonRect, _ptMouse))
				_resumeButtonImage->setFrameY(2);
			else
				_resumeButtonImage->setFrameY(0);
			if (PtInRect(&_quitButtonRect, _ptMouse))
				_quitButtonImage->setFrameY(2);
			else
				_quitButtonImage->setFrameY(0);
			if (PtInRect(&_restartButtonRect, _ptMouse))
				_restartButtonImage->setFrameY(2);
			else
				_restartButtonImage->setFrameY(0);
		}
		break;
	case STAGEPAGE::VICTORY_CONTINUE:
	case STAGEPAGE::VICTORY_RESTART:
	case STAGEPAGE::CLOSE_FOR_RETRY:
	case STAGEPAGE::CLOSE_FOR_RESTART:
		_leftDoorPos += 10;
		_rightDoorPos -= 10;
		//if (_leftDoorPos > -110 && _rightDoorPos < 340)
		//{
		//	_leftDoorPos = -110;
		//	_rightDoorPos = 340;

		//	//저장하면서 나가줘야 할거시다~~~
		//	//어떤 저장소로 나가는가를 알려면
		//	//멤버 변수로 현재 슬롯 번호를 가지고 있어야 할 것 같다.
		//	//괜찮겠지...???.....
		//	/////////////////////////////////////////////////////////////////////
		//	//SCENEMANAGER->loadStage(_currentStageNum);
		//}
		break;
	case STAGEPAGE::GIVE_UP:
	case STAGEPAGE::CLOSE_FOR_MENU:
		_leftDoorPos += 10;
		_rightDoorPos -= 10;
		if (_leftDoorPos > -110 && _rightDoorPos < 340)
		{
			_leftDoorPos = -110;
			_rightDoorPos = 340;

			//저장하면서 나가줘야 할거시다~~~
			//어떤 저장소로 나가는가를 알려면
			//멤버 변수로 현재 슬롯 번호를 가지고 있어야 할 것 같다.
			//괜찮겠지...???.....

			//여기에서 별값 갖고 있는 벡터로 로드메인페이지 하는 것으로 해야한다~
			///////////////////////////////////////////////////////////////////////////////////
			SCENEMANAGER->loadMainPage();//i +1;
		}
		break;
	case STAGEPAGE::FOLD_OPTIONS:
		_optionBoardY -= 20;

		if (_optionBoardY < -500)
		{
			_optionBoardY == -500;
			_stagePage = STAGEPAGE::PLAY;
		}
		break;
	}


	/*checkTarget();
	updateNormal();

	if (_waveButtonAvailable)
	{
		if (PtInRect(&_waveButtonRect, _ptMouse))
			_waveButton = IMAGEMANAGER->findImage("웨이브버튼온");
		else
			_waveButton = IMAGEMANAGER->findImage("웨이브버튼기본");
	}
	else
		_waveButton = IMAGEMANAGER->findImage("웨이브버튼오프");


	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		updateOnceKeyDown();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		if (_waveButtonAvailable && PtInRect(&_waveButtonRect, _ptMouse))
		{
			_waveButtonAvailable = false;
			_waveStart = true;
			++_currentWaveNum;
			_waveCountTime = 0;
			_waveCurrentTime = 0;
		}
		updateOnceKeyUp();
		towerChange();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		updateStayKeyDown();
	}

	if (_waveStart)
	{
		waveCount();
		generateWave();
		++_waveCountTime;
	}*/
}
void stageBase::render(void)
{
	_stageMap->render(getMemDC());

	renderObject();
	//Rectangle(getMemDC(), _vTower[0]->getX(), _vTower[0]->getY(), _vTower[0]->getX() + 20, _vTower[0]->getY() + 20);
	_underBar->render(getMemDC(), 0, 565);
	_information->render(getMemDC(), 200, 564);
	_waveButtonBoard->render(getMemDC(), 618, 544);
	_waveButton->render(getMemDC(), 637, 553);
	_pauseButtonImage->frameRender(getMemDC(), _pauseButtonRect.left, _pauseButtonRect.top);
	_optionButtonImage->frameRender(getMemDC(), _optionButtonRect.left, _optionButtonRect.top);

	if (_selectedTower != nullptr)
	{
		_selectedTower->renderInfo(getMemDC());
	}

	_stageInfo->render(getMemDC(), 10, 10);

	SetBkColor(getMemDC(), RGB(27, 22, 16));
	SetTextColor(getMemDC(), RGB(199, 185, 156));
	SetTextAlign(getMemDC(), TA_LEFT);
	wsprintf(_lifeText, "%d", _currentLife);
	TextOut(getMemDC(), 52, 18, _lifeText, lstrlen(_lifeText));
	wsprintf(_goldText, "%d", _gold);
	TextOut(getMemDC(), 107, 18, _goldText, lstrlen(_goldText));
	wsprintf(_waveNumText, "%d/%d", _currentWaveNum, _fullWaveNum);
	TextOut(getMemDC(), 107, 41, _waveNumText, lstrlen(_waveNumText));

	switch (_stagePage)
	{
	case STAGEPAGE::OPEN:
		_leftDoorImage->render(getMemDC(), _leftDoorPos, -20);
		_rightDoorImage->render(getMemDC(), _rightDoorPos, -20);
		break;
	case STAGEPAGE::PLAY:
		break;
	case STAGEPAGE::PAUSE:
		_pauseScreen->alphaRender(getMemDC(), 0, 0, 120);
		_pauseBoard->render(getMemDC(), WINSIZEX / 2 - _pauseBoard->getWidth() / 2, WINSIZEY / 2 - _pauseBoard->getHeight() / 2);
		break;
	case STAGEPAGE::SET_OPTIONS:
	case STAGEPAGE::OPTIONS:
	case STAGEPAGE::FOLD_OPTIONS:
		_pauseScreen->alphaRender(getMemDC(), 0, 0, 120);
		_optionBoard->render(getMemDC(), 100, _optionBoardY);
		_resumeButtonImage->frameRender(getMemDC(), _resumeButtonRect.left, _optionBoardY + 150);
		_quitButtonImage->frameRender(getMemDC(), _quitButtonRect.left, _optionBoardY + 250);
		_restartButtonImage->frameRender(getMemDC(), _restartButtonRect.left, _optionBoardY + 350);
		break;
	case STAGEPAGE::CLOSE_FOR_MENU:
	case STAGEPAGE::CLOSE_FOR_RESTART:
		_pauseScreen->alphaRender(getMemDC(), 0, 0, 120);
		_optionBoard->render(getMemDC(), 100, _optionBoardY);
		_resumeButtonImage->frameRender(getMemDC(), _resumeButtonRect.left, _optionBoardY + 150);
		_quitButtonImage->frameRender(getMemDC(), _quitButtonRect.left, _optionBoardY + 250);
		_restartButtonImage->frameRender(getMemDC(), _restartButtonRect.left, _optionBoardY + 350);
		_leftDoorImage->render(getMemDC(), _leftDoorPos, -20);
		_rightDoorImage->render(getMemDC(), _rightDoorPos, -20);
		break;
	case STAGEPAGE::SET_DEFEAT:
	case STAGEPAGE::DEFEAT:
		_pauseScreen->alphaRender(getMemDC(), 0, 0, 120);
		_defeatBoard->render(getMemDC(), 88, _defeatBoardY);
		_tryAgainButtonImage->frameRender(getMemDC(), _tryAgainButtonRect.left, _defeatBoardY + 270);
		_giveUpButtonImage->frameRender(getMemDC(), _giveUpButtonRect.left, _defeatBoardY + 270);
		break;
	case STAGEPAGE::GIVE_UP:
	case STAGEPAGE::CLOSE_FOR_RETRY:
		_pauseScreen->alphaRender(getMemDC(), 0, 0, 120);
		_defeatBoard->render(getMemDC(), 88, _defeatBoardY);
		_tryAgainButtonImage->frameRender(getMemDC(), _tryAgainButtonRect.left, _defeatBoardY + 270);
		_giveUpButtonImage->frameRender(getMemDC(), _giveUpButtonRect.left, _defeatBoardY + 270);
		_leftDoorImage->render(getMemDC(), _leftDoorPos, -20);
		_rightDoorImage->render(getMemDC(), _rightDoorPos, -20);
		break;
	case STAGEPAGE::VICTORY:
		_pauseScreen->alphaRender(getMemDC(), 0, 0, 120);
		if (_stopStar)
		{
			_reStartButtonImage->frameRender(getMemDC(), WINSIZEX / 2 - 90, _reStartButtonY);
			_continueButtonImage->frameRender(getMemDC(), WINSIZEX / 2 - 90, _continueButtonY);
		}
		_leftFlowerPowderImage->frameRender(getMemDC(), 68, -25, _flowerPowderFrame, 0);
		_rightFlowerPowderImage->frameRender(getMemDC(), 350, -25, 40 - _flowerPowderFrame, 0);
		_victoryImage->frameRender(getMemDC(), 100, 20, _victoryFrame, 0);
		if (_victoryFrame == 12)
		{
			_victoryStarImage->aniRender(getMemDC(), 302, 252, &_victoryStarAni);
		}
		break;
	case STAGEPAGE::SET_VICTORY:
		_pauseScreen->alphaRender(getMemDC(), 0, 0, 120);
		_victoryImage->frameRender(getMemDC(), 100, 20, _victoryFrame, 0);
		_victoryStarImage->aniRender(getMemDC(), 302, 252, &_victoryStarAni);
		_reStartButtonImage->frameRender(getMemDC(), WINSIZEX / 2 - 90, WINSIZEY / 2 + 140);
		_continueButtonImage->frameRender(getMemDC(), WINSIZEX / 2 - 90, WINSIZEY / 2 + 70);
		break;
	case STAGEPAGE::VICTORY_CONTINUE:
	case STAGEPAGE::VICTORY_RESTART:
		_pauseScreen->alphaRender(getMemDC(), 0, 0, 120);
		_victoryImage->frameRender(getMemDC(), 100, 20, _victoryFrame, 0);
		_victoryStarImage->aniRender(getMemDC(), 302, 252, &_victoryStarAni);
		_reStartButtonImage->frameRender(getMemDC(), WINSIZEX / 2 - 90, WINSIZEY / 2 + 140);
		_continueButtonImage->frameRender(getMemDC(), WINSIZEX / 2 - 90, WINSIZEY / 2 + 70);
		_leftDoorImage->render(getMemDC(), _leftDoorPos, -20);
		_rightDoorImage->render(getMemDC(), _rightDoorPos, -20);
		break;
	}
}
























void stageBase::deleteAll(void)
{
	_viEnemyUnit = _vEnemyUnit.begin();
	for (; _viEnemyUnit != _vEnemyUnit.end();)
	{
		if ((*_viEnemyUnit) != NULL)
		{
			(*_viEnemyUnit)->release();
			SAFE_DELETE((*_viEnemyUnit));
			_viEnemyUnit = _vEnemyUnit.erase(_viEnemyUnit);
		}
		else
			++_viEnemyUnit;
	}

	_viPlayerUnit = _vPlayerUnit.begin();
	for (; _viPlayerUnit != _vPlayerUnit.end();)
	{
		if ((*_viPlayerUnit) != NULL)
		{
			(*_viPlayerUnit)->release();
			SAFE_DELETE((*_viPlayerUnit));
			_viPlayerUnit = _vPlayerUnit.erase(_viPlayerUnit);
		}
		else
			++_viPlayerUnit;
	}

	_viTower = _vTower.begin();
	for (; _viTower != _vTower.end();)
	{
		if ((*_viTower) != NULL)
		{
			(*_viTower)->release();
			SAFE_DELETE((*_viTower));
			_viTower = _vTower.erase(_viTower);
		}
		else
			++_viTower;
	}

	_viStageObject = _vStageObject.begin();
	for (; _viStageObject != _vStageObject.end();)
	{
		if ((*_viStageObject) != NULL)
		{
			_viStageObject = _vStageObject.erase(_viStageObject);
		}
		else
			++_viStageObject;
	}

	_vTower.clear();
	_vPlayerUnit.clear();
	_vEnemyUnit.clear();
	_vStageObject.clear();
}

void stageBase::checkTarget(void)
{
	_viPlayerUnit = _vPlayerUnit.begin();
	for (; _viPlayerUnit != _vPlayerUnit.end(); ++_viPlayerUnit)
	{
		if ((*_viPlayerUnit)->getBelongedTower()->getTowerState() == TOWER_STATE::READY) {}
		else
		{
			//보병계열유닛이라면
			if ((*_viPlayerUnit)->getIsInfantry())
			{
				//이동중이라면
				if ((*_viPlayerUnit)->getUnitState() == UNIT_STATE::MOVE)
				{
					if ((*_viPlayerUnit)->getTarget() != nullptr)
					{
						(*_viPlayerUnit)->getTarget()->setTarget(nullptr);
						(*_viPlayerUnit)->setTarget(nullptr);
					}
					continue;
				}

				//기존 타겟이 있다면
				if ((*_viPlayerUnit)->getTarget() != nullptr)
				{
					if ((*_viPlayerUnit)->getCurHp() <= 0 || (*_viPlayerUnit)->getTarget()->getCurHp() <= 0)
					{
						(*_viPlayerUnit)->getTarget()->setTarget(nullptr);
						(*_viPlayerUnit)->setTarget(nullptr);
						continue;
					}
				}
				else
				{
					_viEnemyUnit = _vEnemyUnit.begin();
					for (; _viEnemyUnit != _vEnemyUnit.end();)
					{
						if ((*_viEnemyUnit)->getTarget() != nullptr)
						{
							++_viEnemyUnit;
							continue;
						}
						else
						{
							if ((*_viEnemyUnit)->getCurHp() <= 0)
							{
								++_viEnemyUnit;
								continue;
							}
							else
							{
								if ((getDistance((*_viPlayerUnit)->getX(), (*_viPlayerUnit)->getY(),
									(*_viEnemyUnit)->getX(), (*_viEnemyUnit)->getY()) <= (*_viPlayerUnit)->getAtkRange()))
								{
									(*_viPlayerUnit)->setTarget((*_viEnemyUnit));
									(*_viEnemyUnit)->setTarget((*_viPlayerUnit));
									break;
								}
								else
								{
									++_viEnemyUnit;
									continue;
								}
							}
						}
					}
				}
			}
			//보병계열유닛O| 아니면
			else
			{
				//현재 타겟 있다면
				if ((*_viPlayerUnit)->getTarget() != nullptr)
				{
					//타겟의 체력이 0이하로 떨어졌을 때 타겟을 널포인터로 바꿔준다.
					if ((*_viPlayerUnit)->getTarget()->getCurHp() <= 0)
					{
						(*_viPlayerUnit)->setTarget(nullptr);
						continue;
					}
				}
				//현재 타겟이 없다면
				else
				{
					_viEnemyUnit = _vEnemyUnit.begin();
					for (; _viEnemyUnit != _vEnemyUnit.end();)
					{
						if ((*_viPlayerUnit)->getIsMagician())
						{
							//사정거리 안에 들어왔는가?
							if ((getDistance((*_viPlayerUnit)->getX(), (*_viPlayerUnit)->getY(),
								(*_viEnemyUnit)->getX(), (*_viEnemyUnit)->getY()) <= (*_viPlayerUnit)->getAtkRange() - (70 * (*_viEnemyUnit)->getSpeed())))//70은 7 * 1/0.1
							{
								(*_viPlayerUnit)->setTarget((*_viEnemyUnit));
								break;
							}
							else
							{
								++_viEnemyUnit;
								continue;
							}
						}
						else
						{
							//사정거리 안에 들어왔는가?
							if ((getDistance((*_viPlayerUnit)->getX(), (*_viPlayerUnit)->getY(),
								(*_viEnemyUnit)->getX(), (*_viEnemyUnit)->getY()) <= (*_viPlayerUnit)->getAtkRange() - (70 * (*_viEnemyUnit)->getSpeed())))//70은 7 * 1/0.1
							{
								(*_viPlayerUnit)->setTarget((*_viEnemyUnit));
								break;
							}
							else
							{
								++_viEnemyUnit;
								continue;
							}
							////사정거리 안에 들어왔는가?
							//if ((getDistance((*_viPlayerUnit)->getX(), (*_viPlayerUnit)->getY(),
							//	(*_viEnemyUnit)->getX(), (*_viEnemyUnit)->getY()) <= (*_viPlayerUnit)->getAtkRange()))
							//{
							//	(*_viPlayerUnit)->setTarget((*_viEnemyUnit));
							//	break;
							//}
							//else
							//{
							//	++_viEnemyUnit;
							//	continue;
							//}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < _vEnemyUnit.size(); ++i)
	{
		if (_vEnemyUnit[i]->getCurHp() <= 0)
		{
			if (_vEnemyUnit[i]->getTarget() != nullptr)
			{
				_vEnemyUnit[i]->setTarget(nullptr);
			}
		}
	}
}

void stageBase::towerChange(void)
{
	float x, y;

	_viTower = _vTower.begin();
	for (; _viTower != _vTower.end(); ++_viTower)
	{
		switch ((*_viTower)->getTowerChange())
		{
		case TOWER_CHANGE::TOWER_SPOT:
			_gold += (*_viTower)->getSellPrice();
			_viPlayerUnit = _vPlayerUnit.begin();
			for (; _viPlayerUnit != _vPlayerUnit.end();)
			{
				if ((*_viPlayerUnit)->getIsInfantry())
				{
					if ((*_viPlayerUnit)->getTarget() != nullptr)
					{
						(*_viPlayerUnit)->getTarget()->setTarget(nullptr);
					}
					(*_viPlayerUnit)->setTarget(nullptr);
				}
				if ((*_viPlayerUnit)->getBelongedTower() == (*_viTower))
				{
					_viStageObject = _vStageObject.begin();
					for (; _viStageObject != _vStageObject.end(); ++_viStageObject)
					{
						if ((*_viPlayerUnit) == (*_viStageObject))
						{
							_vStageObject.erase(_viStageObject);
							break;
						}
					}
					(*_viPlayerUnit)->release();
					SAFE_DELETE(*_viPlayerUnit);
					_viPlayerUnit = _vPlayerUnit.erase(_viPlayerUnit);
				}
				else
				{
					++_viPlayerUnit;
				}
			}

			x = (*_viTower)->getX();
			y = (*_viTower)->getY();

			_viStageObject = _vStageObject.begin();
			for (; _viStageObject != _vStageObject.end(); ++_viStageObject)
			{
				if ((*_viTower) == (*_viStageObject))
				{
					(*_viTower)->release();
					SAFE_DELETE(*_viTower);
					(*_viTower) = TOWERMANAGER->copyTower("타워스폿", x, y);
					(*_viTower)->setBelongedStage(this);
					(*_viStageObject) = (*_viTower);
					break;
				}
			}
			break;
		case TOWER_CHANGE::BARRACKS_TOWER:
			if (_gold < TOWERMANAGER->findTower("배럭스")->getBuyPrice())
			{
				(*_viTower)->setTowerChangeDef();
			}
			else
			{
				x = (*_viTower)->getX();
				y = (*_viTower)->getY();

				_viStageObject = _vStageObject.begin();
				for (; _viStageObject != _vStageObject.end(); ++_viStageObject)
				{
					if ((*_viTower) == (*_viStageObject))
					{
						(*_viTower)->release();
						SAFE_DELETE(*_viTower);
						(*_viTower) = TOWERMANAGER->copyTower("배럭스", x, y);
						(*_viTower)->setBelongedStage(this);
						(*_viStageObject) = (*_viTower);
						break;
					}
				}
				_gold -= (*_viTower)->getBuyPrice();

				for (int i = 0; i < 3; i++)
				{
					playerUnitBase* tempUnit = PLAYERUNITMANAGER->copyUnit("보병", (*_viTower)->getX() + 10 * i - 4, (*_viTower)->getY());
					tempUnit->setBelongedTower(*_viTower);
					((infantry*)tempUnit)->setUnitNum(i);
					_vPlayerUnit.push_back(tempUnit);
					_vStageObject.push_back(tempUnit);
				}
			}
			break;
		case TOWER_CHANGE::ARCHER_TOWER:
			if (_gold < TOWERMANAGER->findTower("아쳐타워")->getBuyPrice())
			{
				(*_viTower)->setTowerChangeDef();
			}
			else
			{
				x = (*_viTower)->getX();
				y = (*_viTower)->getY();

				_viStageObject = _vStageObject.begin();
				for (; _viStageObject != _vStageObject.end(); ++_viStageObject)
				{
					if ((*_viTower) == (*_viStageObject))
					{
						(*_viTower)->release();
						SAFE_DELETE(*_viTower);
						(*_viTower) = TOWERMANAGER->copyTower("아쳐타워", x, y);
						(*_viTower)->setBelongedStage(this);
						(*_viStageObject) = (*_viTower);
						break;
					}
				}

				_gold -= (*_viTower)->getBuyPrice();

				for (int i = 0; i < 2; i++)
				{
					playerUnitBase* tempUnit = PLAYERUNITMANAGER->copyUnit("궁수", (*_viTower)->getX() + 10 * i - 4, (*_viTower)->getY());
					tempUnit->setBelongedTower(*_viTower);
					_vPlayerUnit.push_back(tempUnit);
					_vStageObject.push_back(tempUnit);
				}
			}
			break;
		case TOWER_CHANGE::MAGICIAN_TOWER:
			if (_gold < TOWERMANAGER->findTower("마법사타워")->getBuyPrice())
			{
				(*_viTower)->setTowerChangeDef();
			}
			else
			{
				x = (*_viTower)->getX();
				y = (*_viTower)->getY();

				_viStageObject = _vStageObject.begin();
				for (; _viStageObject != _vStageObject.end(); ++_viStageObject)
				{
					if ((*_viTower) == (*_viStageObject))
					{
						(*_viTower)->release();
						SAFE_DELETE(*_viTower);
						(*_viTower) = TOWERMANAGER->copyTower("마법사타워", x, y);
						(*_viTower)->setBelongedStage(this);
						(*_viStageObject) = (*_viTower);
						break;
					}
				}
				_gold -= (*_viTower)->getBuyPrice();

				playerUnitBase* tempUnit = PLAYERUNITMANAGER->copyUnit("마법사", (*_viTower)->getX(), (*_viTower)->getY());
				tempUnit->setBelongedTower(*_viTower);
				_vPlayerUnit.push_back(tempUnit);
				_vStageObject.push_back(tempUnit);
			}
			break;
		case TOWER_CHANGE::CANNON_TOWER:
			if (_gold < TOWERMANAGER->findTower("캐논타워")->getBuyPrice())
			{
				(*_viTower)->setTowerChangeDef();
			}
			else
			{
				x = (*_viTower)->getX();
				y = (*_viTower)->getY();

				_viStageObject = _vStageObject.begin();
				for (; _viStageObject != _vStageObject.end(); ++_viStageObject)
				{
					if ((*_viTower) == (*_viStageObject))
					{
						(*_viTower)->release();
						SAFE_DELETE(*_viTower);
						(*_viTower) = TOWERMANAGER->copyTower("캐논타워", x, y);
						(*_viTower)->setBelongedStage(this);
						(*_viStageObject) = (*_viTower);
						break;
					}
				}
				_gold -= (*_viTower)->getBuyPrice();
			}
			break;
		default:
			break;
		}
	}
}

void stageBase::updateNormal(void)
{
	_viTower = _vTower.begin();
	for (; _viTower != _vTower.end(); ++_viTower)
	{
		if ((*_viTower)->getIsCannonTower())
		{
			cannonTower* tempCannonTower = ((cannonTower*)(*_viTower));
			if (tempCannonTower->getTarget() != nullptr)
			{
				if (tempCannonTower->getTarget()->getCurHp() <= 0)
				{
					tempCannonTower->setTarget(nullptr);
				}
			}
			if (tempCannonTower->getTarget() != nullptr)
			{
				if (getDistance(tempCannonTower->getX(), tempCannonTower->getY(), tempCannonTower->getTarget()->getX(), tempCannonTower->getTarget()->getY()) > tempCannonTower->getAtkRange())
				{
					tempCannonTower->setTarget(nullptr);
				}
			}
			else
			{
				_viEnemyUnit = _vEnemyUnit.begin();
				for (; _viEnemyUnit != _vEnemyUnit.end(); ++_viEnemyUnit)
				{
					if (getDistance(tempCannonTower->getX(), tempCannonTower->getY(), (*_viEnemyUnit)->getX(), (*_viEnemyUnit)->getY()) <= tempCannonTower->getAtkRange())
					{
						tempCannonTower->setTarget(*_viEnemyUnit);
						break;
					}
				}
				//if ((getDistance((*_viPlayerUnit)->getX(), (*_viPlayerUnit)->getY(),
				//	(*_viEnemyUnit)->getX(), (*_viEnemyUnit)->getY()) <= (*_viPlayerUnit)->getAtkRange() - (70 * (*_viEnemyUnit)->getSpeed())))//70은 7 * 1/0.1
				//{
				//	(*_viPlayerUnit)->setTarget((*_viEnemyUnit));
				//	break;
				//}
				//else
				//{
				//	++_viEnemyUnit;
				//	continue;
				//}
			}

			vector<cannon*> tempVCannon;
			vector<cannon*>::iterator tempCannonIter;
			tempVCannon = tempCannonTower->getVCannon();
			tempCannonIter = tempVCannon.begin();
			for (; tempCannonIter != tempVCannon.end(); ++tempCannonIter)
			{
				if ((*tempCannonIter)->getDamageCheck() == false && (*tempCannonIter)->getArrived())
				{
					_viEnemyUnit = _vEnemyUnit.begin();
					for (; _viEnemyUnit != _vEnemyUnit.end(); ++_viEnemyUnit)
					{
						float tempDistance = getDistance((*tempCannonIter)->getX(), (*tempCannonIter)->getY(), (*_viEnemyUnit)->getX(), (*_viEnemyUnit)->getY());
						float tempExplosionRange = (*tempCannonIter)->getExplosionRange();
						if (tempDistance <= tempExplosionRange)
						{
							switch ((*_viEnemyUnit)->getArmor())
							{
							case ARMOR::NONE:
								(*_viEnemyUnit)->setCurHp((*_viEnemyUnit)->getCurHp() - (tempCannonTower->getAtk() * ((tempExplosionRange - tempDistance) / tempExplosionRange)));
								break;
							case ARMOR::LOW:
								(*_viEnemyUnit)->setCurHp((*_viEnemyUnit)->getCurHp() - (tempCannonTower->getAtk() * 0.9 * ((tempExplosionRange - tempDistance) / tempExplosionRange)));
								break;
							case ARMOR::MEDIUM:
								(*_viEnemyUnit)->setCurHp((*_viEnemyUnit)->getCurHp() - (tempCannonTower->getAtk() * 0.7 * ((tempExplosionRange - tempDistance) / tempExplosionRange)));
								break;
							case ARMOR::HIGH:
								(*_viEnemyUnit)->setCurHp((*_viEnemyUnit)->getCurHp() - (tempCannonTower->getAtk() * 0.5 * ((tempExplosionRange - tempDistance) / tempExplosionRange)));
								break;
							}
						}
					}
					(*tempCannonIter)->setDamageCheck(true);
				}
			}
		}

		if(_selectedTower == nullptr)
			(*_viTower)->updateNormal();
		else
		{
			if((*_viTower) == _selectedTower)
				(*_viTower)->updateNormal();
			else
				(*_viTower)->updateNormal1();
		}
	}
	if (_waveStart)
	{
		_viEnemyUnit = _vEnemyUnit.begin();
		for (; _viEnemyUnit != _vEnemyUnit.end(); ++_viEnemyUnit)
		{
			(*_viEnemyUnit)->updateNormal();
			if ((*_viEnemyUnit)->getUnitState() == UNIT_STATE::DEAD && (*_viEnemyUnit)->getDeadCheck() == false)
			{
				_gold += (*_viEnemyUnit)->getGold();
				(*_viEnemyUnit)->setDeadCheck(true);
			}
			if ((*_viEnemyUnit)->getUnitState() == UNIT_STATE::ARRIVED)
			{
				--_currentLife;
			}
		}
	}
	_viPlayerUnit = _vPlayerUnit.begin();
	for (; _viPlayerUnit != _vPlayerUnit.end(); ++_viPlayerUnit)
	{
		(*_viPlayerUnit)->updateNormal();
	}
}

void stageBase::updateOnceKeyDown(void)
{
	_viTower = _vTower.begin();
	for (; _viTower != _vTower.end(); ++_viTower)
	{
		(*_viTower)->updateOnceDn();
	}
	_viEnemyUnit = _vEnemyUnit.begin();
	for (; _viEnemyUnit != _vEnemyUnit.end(); ++_viEnemyUnit)
	{
		(*_viEnemyUnit)->updateOnceDn();
	}
	_viPlayerUnit = _vPlayerUnit.begin();
	for (; _viPlayerUnit != _vPlayerUnit.end(); ++_viPlayerUnit)
	{
		(*_viPlayerUnit)->updateOnceDn();
	}

	/////////////////////////////////////////////////////////////////////
	//여기에서 클릭했을 때 정보 선택된 유닛 정보 보여주도록 하자
	/*_viStageObject = _vStageObject.end();
	for (; _viStageObject != _vStageObject.begin(); --_viStageObject)
	{

	}*/

}
void stageBase::updateOnceKeyUp(void)
{
	if (_selectedTower == nullptr)
	{
		//포문 돌면서 잡히면 셀렉티드 타워로
		_viTower = _vTower.begin();
		for (; _viTower != _vTower.end(); ++_viTower)
		{
			if((*_viTower)->getTowerState() != TOWER_STATE::READY)
				(*_viTower)->updateOnceUp1();
		}
	}
	else
	{
		_selectedTower->updateOnceUp();
	}

	/*_viTower = _vTower.begin();
	for (; _viTower != _vTower.end(); ++_viTower)
	{
		(*_viTower)->updateOnceUp();
	}*/

	_viEnemyUnit = _vEnemyUnit.begin();
	for (; _viEnemyUnit != _vEnemyUnit.end(); ++_viEnemyUnit)
	{
		(*_viEnemyUnit)->updateOnceUp();
	}

	_viPlayerUnit = _vPlayerUnit.begin();
	for (; _viPlayerUnit != _vPlayerUnit.end(); ++_viPlayerUnit)
	{
		(*_viPlayerUnit)->updateOnceUp();
	}
}
void stageBase::updateStayKeyDown(void)
{
	_viTower = _vTower.begin();
	for (; _viTower != _vTower.end(); ++_viTower)
	{
		(*_viTower)->updateStayDn();
	}
	_viEnemyUnit = _vEnemyUnit.begin();
	for (; _viEnemyUnit != _vEnemyUnit.end(); ++_viEnemyUnit)
	{
		(*_viEnemyUnit)->updateStayDn();
	}
	_viPlayerUnit = _vPlayerUnit.begin();
	for (; _viPlayerUnit != _vPlayerUnit.end(); ++_viPlayerUnit)
	{
		(*_viPlayerUnit)->updateStayDn();
	}
}

void stageBase::setStageObject(void)
{
	_viTower = _vTower.begin();
	for (; _viTower != _vTower.end(); ++_viTower)
	{
		(*_viTower)->setBelongedStage(this);
		_vStageObject.push_back(*_viTower);
	}
	_viEnemyUnit = _vEnemyUnit.begin();
	for (; _viEnemyUnit != _vEnemyUnit.end(); ++_viEnemyUnit)
	{
		_vStageObject.push_back(*_viEnemyUnit);
	}
	_viPlayerUnit = _vPlayerUnit.begin();
	for (; _viPlayerUnit != _vPlayerUnit.end(); ++_viPlayerUnit)
	{
		_vStageObject.push_back(*_viPlayerUnit);
	}
}

void stageBase::renderObject(void)
{
	/*_viPlayerUnit = _vPlayerUnit.begin();
	for (; _viPlayerUnit != _vPlayerUnit.end(); ++_viPlayerUnit)
	{
	if ((*_viPlayerUnit)->getUnitState() == UNIT_STATE::ATTACK)
	(*_viPlayerUnit)->renderObject(getMemDC());
	}*/


	_viStageObject = _vStageObject.begin();
	for (; _viStageObject != _vStageObject.end(); ++_viStageObject)
	{
		(*_viStageObject)->renderObject(getMemDC());
	}
	_viStageObject = _vStageObject.begin();
	for (; _viStageObject != _vStageObject.end(); ++_viStageObject)
	{
		(*_viStageObject)->renderUI(getMemDC());
	}
}

void stageBase::generateWave()
{
	++_waveCurrentTime;
	if (_waveCurrentTime> _waveTime)
	{
		for (int i = 0; i < _vEnemyUnit.size(); i++)
		{
			_waveCurrentTime = 0;
			if (_vEnemyUnit[i]->getWaveNum() == _currentWaveNum && _vEnemyUnit[i]->getUnitState() == UNIT_STATE::READY)
			{
				_vEnemyUnit[i]->setUnitState(UNIT_STATE::MOVE);
				break;
			}
		}
	}
}

void stageBase::waveCount()
{
	if (_waveCountTime > 600)
	{
		_waveButtonAvailable = true;
	}
	if (_waveCountTime > 2100)
	{
		_waveButtonAvailable = false;
		++_currentWaveNum;
		_waveCountTime = 0;
		_waveCurrentTime = 0;
	}
}