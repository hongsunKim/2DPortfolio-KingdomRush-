#include "stdafx.h"
#include "mainPage.h"


mainPage::mainPage()
{
}


mainPage::~mainPage()
{
}

HRESULT mainPage::init(void)
{
	_mainPage = MAINPAGE::OPEN;
	_mainPageImage = IMAGEMANAGER->addImage("����ȭ��", "image/����������/����ȭ��.bmp", 700, 600, FALSE, RGB(1, 0, 0));

	//�޴���ư ����
	_menuButtonImage = IMAGEMANAGER->addImage("�޴���ư(�⺻)", "image/����������/�޴���ư(�⺻).bmp", 60, 60, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("�޴���ư(��)", "image/����������/�޴���ư(��).bmp", 60, 60, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("�޴���ư(Ŭ��)", "image/����������/�޴���ư(Ŭ��).bmp", 60, 60, TRUE, RGB(1, 0, 0));
	_menuButtonRect = RectMake(50, WINSIZEY - 81, _menuButtonImage->getWidth(), _menuButtonImage->getHeight());

	//���׷��̵��ư ����
	_upgradeButtonImage = IMAGEMANAGER->addImage("���׷��̵��ư(�⺻)", "image/����������/���׷��̵��ư(�⺻).bmp", 120, 100, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("���׷��̵��ư(��)", "image/����������/���׷��̵��ư(��).bmp", 120, 100, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("���׷��̵��ư(Ŭ��)", "image/����������/���׷��̵��ư(Ŭ��).bmp", 120, 100, TRUE, RGB(1, 0, 0));
	_upgradeButtonRect = RectMake(500, WINSIZEY - 115, _upgradeButtonImage->getWidth(), _upgradeButtonImage->getHeight());

	//���׷��̵� �� ����
	_upgradeBoardImage = IMAGEMANAGER->addImage("���׷��̵庸��", "image/����������/���׷��̵庸��.bmp", 651, 581, TRUE, RGB(1, 0, 0));
	_upgradeBoardPos = -_upgradeBoardImage->getHeight();
	_doneButtonImage = IMAGEMANAGER->addImage("����ư(�⺻)", "image/����������/����ư(�⺻).bmp", 90, 45, FALSE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("����ư(��)", "image/����������/����ư(��).bmp", 90, 45, FALSE, RGB(1, 0, 0));
	_doneButtonRect = RectMake(535, 586 - 67, 90, 45);
	_resetButtonImage = IMAGEMANAGER->addImage("���¹�ư(��Ȱ��ȭ)", "image/����������/���¹�ư(��Ȱ��ȭ).bmp", 90, 45, FALSE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("���¹�ư(�⺻)", "image/����������/���¹�ư(�⺻).bmp", 90, 45, FALSE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("���¹�ư(��)", "image/����������/���¹�ư(��).bmp", 90, 45, FALSE, RGB(1, 0, 0));
	_resetButtonRect = RectMake(435, 586 - 67, 90, 45);

	_starBoard = IMAGEMANAGER->addImage("����ȭ�麰������", "image/����������/��������.bmp", 144, 142, TRUE, RGB(1, 0, 0));

	IMAGEMANAGER->addImage("������������", "image/����������/������������.bmp", 37, 10, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("�����������ϳ�", "image/����������/�����������ϳ�.bmp", 37, 10, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("������������", "image/����������/������������.bmp", 37, 10, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("������������", "image/����������/������������.bmp", 37, 10, TRUE, RGB(1, 0, 0));

	//������ �ε忡�� ���� �����ؾ� �� ��...
	//���� ���� �ѹ��� ���� �ʱ�ȭ �κ����� ���߿� �ű��!!!
	for (int i = 0; i < 30; i++)
	{
		_upgrade[i].id = i;
		wsprintf(_upgradeDirectory, "image/���׷��̵�/%d.bmp", i);
		wsprintf(_upgradeName, "%d�����׷��̵�", i);
		_upgrade[i].buttonImage = IMAGEMANAGER->addFrameImage(_upgradeName, _upgradeDirectory, 228, 57, 4, 1, TRUE, RGB(1, 0, 0));
		_upgrade[i].buttonRect = RectMake(88 + 95 * (i % 6), 356 - 63 * (i / 6), 57, 57);
		if (i < 6)
		{
			_upgrade[i].upgradeState = UPGRADE_STATE::PURCHABLE_BASE;
		}
		else
		{
			_upgrade[i].upgradeState = UPGRADE_STATE::LOCKED;
		}
	}

	_upgrade[0].description = IMAGEMANAGER->addImage("0������", "image/���׷��̵弳��/0.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[1].description = IMAGEMANAGER->addImage("1������", "image/���׷��̵弳��/1.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[2].description = IMAGEMANAGER->addImage("2������", "image/���׷��̵弳��/2.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[3].description = IMAGEMANAGER->addImage("3������", "image/���׷��̵弳��/3.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[4].description = IMAGEMANAGER->addImage("4������", "image/���׷��̵弳��/4.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[5].description = IMAGEMANAGER->addImage("5������", "image/���׷��̵弳��/5.bmp", 247, 81, TRUE, RGB(1, 0, 0));
	_upgrade[6].description = IMAGEMANAGER->addImage("6������", "image/���׷��̵弳��/6.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[7].description = IMAGEMANAGER->addImage("7������", "image/���׷��̵弳��/7.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[8].description = IMAGEMANAGER->addImage("8������", "image/���׷��̵弳��/8.bmp", 247, 81, TRUE, RGB(1, 0, 0));
	_upgrade[9].description = IMAGEMANAGER->addImage("9������", "image/���׷��̵弳��/9.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[10].description = IMAGEMANAGER->addImage("10������", "image/���׷��̵弳��/10.bmp", 247, 81, TRUE, RGB(1, 0, 0));
	_upgrade[11].description = IMAGEMANAGER->addImage("11������", "image/���׷��̵弳��/11.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[12].description = IMAGEMANAGER->addImage("12������", "image/���׷��̵弳��/12.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[13].description = IMAGEMANAGER->addImage("13������", "image/���׷��̵弳��/13.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[14].description = IMAGEMANAGER->addImage("14������", "image/���׷��̵弳��/14.bmp", 247, 81, TRUE, RGB(1, 0, 0));
	_upgrade[15].description = IMAGEMANAGER->addImage("15������", "image/���׷��̵弳��/15.bmp", 247, 81, TRUE, RGB(1, 0, 0));
	_upgrade[16].description = IMAGEMANAGER->addImage("16������", "image/���׷��̵弳��/16.bmp", 247, 81, TRUE, RGB(1, 0, 0));
	_upgrade[17].description = IMAGEMANAGER->addImage("17������", "image/���׷��̵弳��/17.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[18].description = IMAGEMANAGER->addImage("18������", "image/���׷��̵弳��/18.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[19].description = IMAGEMANAGER->addImage("19������", "image/���׷��̵弳��/19.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[20].description = IMAGEMANAGER->addImage("20������", "image/���׷��̵弳��/20.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[21].description = IMAGEMANAGER->addImage("21������", "image/���׷��̵弳��/21.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[22].description = IMAGEMANAGER->addImage("22������", "image/���׷��̵弳��/22.bmp", 247, 81, TRUE, RGB(1, 0, 0));
	_upgrade[23].description = IMAGEMANAGER->addImage("23������", "image/���׷��̵弳��/23.bmp", 247, 81, TRUE, RGB(1, 0, 0));
	_upgrade[24].description = IMAGEMANAGER->addImage("24������", "image/���׷��̵弳��/24.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[25].description = IMAGEMANAGER->addImage("25������", "image/���׷��̵弳��/25.bmp", 247, 122, TRUE, RGB(1, 0, 0));
	_upgrade[26].description = IMAGEMANAGER->addImage("26������", "image/���׷��̵弳��/26.bmp", 247, 68, TRUE, RGB(1, 0, 0));
	_upgrade[27].description = IMAGEMANAGER->addImage("27������", "image/���׷��̵弳��/27.bmp", 247, 81, TRUE, RGB(1, 0, 0));
	_upgrade[28].description = IMAGEMANAGER->addImage("28������", "image/���׷��̵弳��/28.bmp", 247, 94, TRUE, RGB(1, 0, 0));
	_upgrade[29].description = IMAGEMANAGER->addImage("29������", "image/���׷��̵弳��/29.bmp", 247, 81, TRUE, RGB(1, 0, 0));

	_upgrade[0].price = 1;
	_upgrade[1].price = 1;
	_upgrade[2].price = 1;
	_upgrade[3].price = 1;
	_upgrade[4].price = 1;
	_upgrade[5].price = 2;
	_upgrade[6].price = 1;
	_upgrade[7].price = 1;
	_upgrade[8].price = 1;
	_upgrade[9].price = 1;
	_upgrade[10].price = 1;
	_upgrade[11].price = 3;
	_upgrade[12].price = 2;
	_upgrade[13].price = 2;
	_upgrade[14].price = 2;
	_upgrade[15].price = 3;
	_upgrade[16].price = 2;
	_upgrade[17].price = 3;
	_upgrade[18].price = 2;
	_upgrade[19].price = 2;
	_upgrade[20].price = 2;
	_upgrade[21].price = 3;
	_upgrade[22].price = 2;
	_upgrade[23].price = 3;
	_upgrade[24].price = 3;
	_upgrade[25].price = 3;
	_upgrade[26].price = 3;
	_upgrade[27].price = 3;
	_upgrade[28].price = 3;
	_upgrade[29].price = 4;

	//����������ư ����
	IMAGEMANAGER->addImage("������������(�⺻)", "image/����������/������������(�⺻).bmp", 43, 57, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("������������(��)", "image/����������/������������(��).bmp", 43, 57, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("���罺������(�⺻)", "image/����������/���罺������(�⺻).bmp", 43, 57, TRUE, RGB(1, 0, 0));
	IMAGEMANAGER->addImage("���罺������(��)", "image/����������/���罺������(��).bmp", 43, 57, TRUE, RGB(1, 0, 0));

	//�������� ��� ��ġ ����
	_stage[0].buttonRect = RectMake(85, 435, 43, 57);
	_stage[1].buttonRect = RectMake(70, 375, 43, 57);
	/*
	_stage[1].buttonRect = RectMake(~~~~);
	_stage[2].buttonRect = RectMake(~~~~);
	_stage[3].buttonRect = RectMake(~~~~);
	.
	.
	.
	*/
	for (int i = 0; i < 8; i++)
	{
		//_stage[i].buttonImage = IMAGEMANAGER->addFrameImage("�����������", "image/����������/�����������.bmp", 172, 57, 4, 1, TRUE, RGB(1, 0, 0));
		_stage[i].buttonImage = IMAGEMANAGER->findImage("������������(�⺻)");
		_stage[i].stageState = STAGE_STATE::LOCKED;
		_stage[i].stageNum = i + 1;
		_stage[i].starPoint = 0;
	}

	_star = 0;

	//�����̹� ����
	_leftDoorImage = IMAGEMANAGER->addImage("���ʹ�", "image/��ü����/���ʹ�.bmp", 470, 655, TRUE, RGB(1, 0, 0));
	_rightDoorImage = IMAGEMANAGER->addImage("�����ʹ�", "image/��ü����/�����ʹ�.bmp", 464, 655, TRUE, RGB(1, 0, 0));
	_leftDoorPos = -110;
	_rightDoorPos = 340;

	return S_OK;
}

HRESULT mainPage::init(int slotNum)
{
	mainPage::init();

	switch (slotNum)
	{
	case 0:
		_slotNum = 0;
		break;
	case 1:
		_slotNum = 1;
		_currentStageNum = 1;//�ҷ��� ��
		for (int i = 0; i < 2; i++)//�ۼ��� �������� �� ũ�⸸ŭ ������
		{
			_stage[i].stageNum = i + 1;
			_stage[i].starPoint = 0;//�ҷ��� ��
			if (_stage[i].stageNum < _currentStageNum)
				_stage[i].stageState = STAGE_STATE::COMPLETED_STAGE_BASE;
			else if (_stage[i].stageNum == _currentStageNum)
				_stage[i].stageState = STAGE_STATE::CURRENT_STAGE_BASE;
			else
				_stage[i].stageState = STAGE_STATE::LOCKED;

			//_stage[i].starPoint = �ҷ��� �Ϳ��� �ش� ���������� �ش��ϴ� �� ����Ʈ ��.
		}

		_stage[_currentStageNum - 1].buttonImage = IMAGEMANAGER->findImage("���罺������(�⺻)");
		for (int i = 0; i < 8; i++)
		{
			if (_stage[i].starPoint == 1)
				_stage[i].starImage = IMAGEMANAGER->findImage("�����������ϳ�");
			else if (_stage[i].starPoint == 2)
				_stage[i].starImage = IMAGEMANAGER->findImage("������������");
			else if (_stage[i].starPoint == 3)
				_stage[i].starImage = IMAGEMANAGER->findImage("������������");
			else
				_stage[i].starImage = IMAGEMANAGER->findImage("������������");
		}
		//���׷��̵嵵 �ҷ��� ������ �ʱ�ȭ �ؾ��Ѵ�.
		//�ϴ��� �⺻������ �ʱ�ȭ �� �������� �ҷ������� �Ѵ�~~!!!
		break;
	case 2:
		_slotNum = 1;
		//����� ������ �ҷ�����

		//HANDLE file;
		//DWORD read;

		//file = CreateFile("save/slot1.map",
		//	GENERIC_READ, 0, NULL, OPEN_EXISTING,
		//	FILE_ATTRIBUTE_NORMAL, NULL);

		//CloseHandle(file);

		//break;
	case 3:
		_slotNum = 3;
		//
		break;
	}

	return S_OK;
}

HRESULT mainPage::init(int slotNum, vector<int> vStageInfo)
{
	mainPage::init();

	_slotNum = slotNum;

	for (int i = 0; i < vStageInfo.size(); ++i)
	{
		int sum = 0;

		if (vStageInfo[i] != 0)
		{
			sum += _stage[i].starPoint = vStageInfo[i];
			_stage[i].stageState = STAGE_STATE::COMPLETED_STAGE_BASE;
		}
		else
		{
			_currentStageNum = i + 1;
			_star = sum;
			_stage[i].stageState = STAGE_STATE::CURRENT_STAGE_BASE;
			break;
		}
	}
	return S_OK;
}

HRESULT mainPage::init(int slotNum, STAGE_INFO stage[8], UPGRADE_INFO upgrade[30])
{
	mainPage::init();

	_slotNum = slotNum;
	memcpy(_stage, stage, 8 * sizeof(STAGE_INFO));
	memcpy(_upgrade, upgrade, 30 * sizeof(UPGRADE_INFO));
	return S_OK;
}

void mainPage::release(void)
{
	/*_viStageStar = _vStageStar.begin();
	for (; _viStageStar != _vStageStar.end();)
	{
		_viStageStar = _vStageStar.erase(_viStageStar);
	}
	_vStageStar.clear();*/
}
void mainPage::update(void)
{
	switch (_mainPage)
	{
	case MAINPAGE::OPEN:
		_leftDoorPos -= 10;
		_rightDoorPos += 10;
		if (_leftDoorPos < -470 && _rightDoorPos > 700)
		{
			_leftDoorPos = -470;
			_rightDoorPos = 700;
			_mainPage = MAINPAGE::PLAY;
		}
		break;
	case MAINPAGE::PLAY:
		//�̹��� �ٲ�� �� ����
		_menuButtonImage = IMAGEMANAGER->findImage("�޴���ư(�⺻)");
		_upgradeButtonImage = IMAGEMANAGER->findImage("���׷��̵��ư(�⺻)");


		//��ư Ŭ���Ǵ� �κ�
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&_menuButtonRect, _ptMouse))
			{
				_menuButtonImage = IMAGEMANAGER->findImage("�޴���ư(Ŭ��)");
			}
			if (PtInRect(&_upgradeButtonRect, _ptMouse))
			{
				_upgradeButtonImage = IMAGEMANAGER->findImage("���׷��̵��ư(Ŭ��)");
			}
		}
		//Ŭ�� �κ� ��

		else
		{
			if (PtInRect(&_menuButtonRect, _ptMouse))
			{
				_menuButtonImage = IMAGEMANAGER->findImage("�޴���ư(��)");
			}
			if (PtInRect(&_upgradeButtonRect, _ptMouse))
			{
				_upgradeButtonImage = IMAGEMANAGER->findImage("���׷��̵��ư(��)");
			}
			for (int i = 0; i < 2; i++)
			{
				if (PtInRect(&_stage[i].buttonRect, _ptMouse))
				{
					if (_stage[i].stageState == STAGE_STATE::COMPLETED_STAGE_BASE)
						_stage[i].stageState = STAGE_STATE::COMPLETED_STAGE_ON;
					else if (_stage[i].stageState == STAGE_STATE::CURRENT_STAGE_BASE)
						_stage[i].stageState = STAGE_STATE::CURRENT_STAGE_ON;
				}
				else
				{
					if (_stage[i].stageNum < _currentStageNum)
						_stage[i].stageState = STAGE_STATE::COMPLETED_STAGE_BASE;
					else if (_stage[i].stageNum == _currentStageNum)
						_stage[i].stageState = STAGE_STATE::CURRENT_STAGE_BASE;
					else
						_stage[i].stageState = STAGE_STATE::LOCKED;
				}
				switch (_stage[i].stageState)
				{
				case STAGE_STATE::CURRENT_STAGE_BASE:
					_stage[i].buttonImage = IMAGEMANAGER->findImage("���罺������(�⺻)");
					break;
				case STAGE_STATE::CURRENT_STAGE_ON:
					_stage[i].buttonImage = IMAGEMANAGER->findImage("���罺������(��)");
					break;
				case STAGE_STATE::COMPLETED_STAGE_BASE:
					_stage[i].buttonImage = IMAGEMANAGER->findImage("������������(�⺻)");
					break;
				case STAGE_STATE::COMPLETED_STAGE_ON:
					_stage[i].buttonImage = IMAGEMANAGER->findImage("������������(��)");
					break;
				}
			}
		}

		//���� Ŭ���ؼ� �̵��ϴ� �κ�
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			if (PtInRect(&_menuButtonRect, _ptMouse))
			{
				_mainPage = MAINPAGE::CLOSE_FOR_MENU;
			}
			if (PtInRect(&_upgradeButtonRect, _ptMouse))
			{
				_mainPage = MAINPAGE::SET_UPGRADE;
			}
			for (int i = 0; i < 2; i++)
			{
				if (PtInRect(&_stage[i].buttonRect, _ptMouse))
				{
					if (_stage[i].stageState != STAGE_STATE::LOCKED)
					{
						if (i + 1 == _currentStageNum)
						{
							_stage[i].buttonImage = IMAGEMANAGER->findImage("���罺������(�⺻)");
						}
						else
						{
							_stage[i].buttonImage = IMAGEMANAGER->findImage("������������(�⺻)");
						}
						_openStageNum = i + 1;
						_mainPage = MAINPAGE::CLOSE_FOR_STAGE;
					}
					else{}
				}
			}
		}
		break;
	case MAINPAGE::CLOSE_FOR_STAGE:
		_leftDoorPos += 10;
		_rightDoorPos -= 10;
		if (_leftDoorPos > -110 && _rightDoorPos < 340)
		{
			_leftDoorPos = -110;
			_rightDoorPos = 340;

			/*for (int i = 0; i < 8; i++)
			{
				_vStageStar.push_back(_stage[i].starPoint);
			}*/
			//�̰� ����?
			//STAGEMANAGER->setStageInfo(_vStageStar);
			switch (_openStageNum)
			{
			case 1:
				SCENEMANAGER->changeScene("��������1");
				break;
			case 2:
				SCENEMANAGER->changeScene("��������2");
				break;
			}
			//SCENEMANAGER->loadStage(_openStageNum);//i +1;
		}
		break;

	case MAINPAGE::CLOSE_FOR_MENU:
		_leftDoorPos += 10;
		_rightDoorPos -= 10;
		if (_leftDoorPos > -110 && _rightDoorPos < 340)
		{
			_leftDoorPos = -110;
			_rightDoorPos = 340;

			///////////////////////////////////
			////���⿡�� �����ؾ��Ѵ�!!!!!!////
			///////////////////////////////////

			SCENEMANAGER->changeScene("����ȭ��");
		}
		break;
	case MAINPAGE::SET_UPGRADE:
		_upgradeBoardPos += 20;
		if (_upgradeBoardPos > 5)
		{
			_upgradeBoardPos = 5;
			_mainPage = MAINPAGE::UPGRADE;
		}
		break;
	case MAINPAGE::UPGRADE:
		_doneButtonImage = IMAGEMANAGER->findImage("����ư(�⺻)");

		_resetButtonImage = IMAGEMANAGER->findImage("���¹�ư(��Ȱ��ȭ)");
		for (int i = 0; i < 30; i++)
		{
			if (_upgrade[i].upgradeState == UPGRADE_STATE::ACTIVATED)
			{
				_resetButtonImage = IMAGEMANAGER->findImage("���¹�ư(�⺻)");
				break;
			}
		}

		//��ư ������ ���� ��
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			for (int i = 0; i < 30; i++)
			{
				if (PtInRect(&_upgrade[i].buttonRect, _ptMouse))
				{
					if (_upgrade[i].upgradeState == UPGRADE_STATE::PURCHABLE_ON)
					{
						//���׷��̵� ���� �κ�
						//�̰����� ���� �� ������ �˻��ؼ� �װͺ��� ���� ���ݵ鸸 ���� �����ϵ��� �ؾ��Ѵ�.
						if (_purchableStar >= _upgrade[i].price)
						{
							_purchableStar -= _upgrade[i].price;
							_upgrade[i].upgradeState = UPGRADE_STATE::ACTIVATED;
							switch (i)
							{
							case 0:
								TOWERMANAGER->findTower("����Ÿ��")->setSellPrice(63);
								break;
							case 1:
								PLAYERUNITMANAGER->findUnit("����")->setFullHp(60);
								PLAYERUNITMANAGER->findUnit("����")->setCurHp(60);
								break;
							case 2:
								PLAYERUNITMANAGER->findUnit("������")->setAtkRange(140);
								break;
							case 3:
								((cannonTower*)TOWERMANAGER->findTower("ĳ��Ÿ��"))->setAtkMin(12);
								((cannonTower*)TOWERMANAGER->findTower("ĳ��Ÿ��"))->setAtkMax(20);
								break;
							case 6:
								PLAYERUNITMANAGER->findUnit("�ü�")->setAtkRange(140);
								break;
							case 7:
								PLAYERUNITMANAGER->findUnit("����")->setArmor(ARMOR::LOW);
								break;
							case 8:
								PLAYERUNITMANAGER->findUnit("������")->setDoubleAttack(true);
								break;
							case 9:
								((cannonTower*)TOWERMANAGER->findTower("ĳ��Ÿ��"))->setAtkRange(200);
								break;
							case 12:
								PLAYERUNITMANAGER->findUnit("�ü�")->setAtkType(ATK_TYPE::PHYSICAL_PIERCING);
								break;
							case 13:
								((infantry*)PLAYERUNITMANAGER->findUnit("����"))->setRegen(6);
								break;
							case 14:
								TOWERMANAGER->findTower("������Ÿ��")->setBuyPrice(81);
								break;
							case 15:
								TOWERMANAGER->findTower("ĳ��Ÿ��")->setBuyPrice(112);
								break;
							case 18:
								PLAYERUNITMANAGER->findUnit("�ü�")->setAtkRange(160);
								break;
							case 19:
								PLAYERUNITMANAGER->findUnit("����")->setFullHp(70);
								PLAYERUNITMANAGER->findUnit("����")->setCurHp(70);
								break;
							case 20:
								PLAYERUNITMANAGER->findUnit("������")->setAtkMin(12);
								PLAYERUNITMANAGER->findUnit("������")->setAtkMax(20);
								break;
							case 24:
								PLAYERUNITMANAGER->findUnit("�ü�")->setDoubleAttack(true);
								break;
							case 25:
								PLAYERUNITMANAGER->findUnit("����")->setDoubleAttack(true);
								break;
							case 26:
								((magician*)PLAYERUNITMANAGER->findUnit("������"))->setSlowSkill(true);
								break;
							}
							if (i < 24)
							{
								_upgrade[i + 6].upgradeState = UPGRADE_STATE::PURCHABLE_BASE;
							}
						}
						
					}
				}

			}
			if (PtInRect(&_doneButtonRect, _ptMouse))
			{
				_mainPage = MAINPAGE::FOLD_UPGRADE;
			}
			if (PtInRect(&_resetButtonRect, _ptMouse))
			{
				for (int i = 0; i < 30; i++)
				{
					if (_upgrade[i].upgradeState == UPGRADE_STATE::ACTIVATED)
						_purchableStar += _upgrade[i].price;
					if (i < 6)
						_upgrade[i].upgradeState = UPGRADE_STATE::PURCHABLE_BASE;
					else
						_upgrade[i].upgradeState = UPGRADE_STATE::LOCKED;
				}
				TOWERMANAGER->findTower("����Ÿ��")->setSellPrice(42);
				PLAYERUNITMANAGER->findUnit("�ü�")->setAtkRange(120);
				PLAYERUNITMANAGER->findUnit("�ü�")->setAtkType(ATK_TYPE::PHYSICAL);
				PLAYERUNITMANAGER->findUnit("�ü�")->setDoubleAttack(false);
				PLAYERUNITMANAGER->findUnit("����")->setFullHp(50);
				PLAYERUNITMANAGER->findUnit("����")->setCurHp(50);
				PLAYERUNITMANAGER->findUnit("����")->setArmor(ARMOR::NONE);
				((infantry*)PLAYERUNITMANAGER->findUnit("����"))->setRegen(10);
				PLAYERUNITMANAGER->findUnit("����")->setDoubleAttack(false);
				PLAYERUNITMANAGER->findUnit("������")->setAtkRange(120);
				PLAYERUNITMANAGER->findUnit("������")->setDoubleAttack(false);
				TOWERMANAGER->findTower("������Ÿ��")->setBuyPrice(90);
				PLAYERUNITMANAGER->findUnit("������")->setAtkMin(9);
				PLAYERUNITMANAGER->findUnit("������")->setAtkMax(17);
				((magician*)PLAYERUNITMANAGER->findUnit("������"))->setSlowSkill(false);
				((cannonTower*)TOWERMANAGER->findTower("ĳ��Ÿ��"))->setAtkMin(8);
				((cannonTower*)TOWERMANAGER->findTower("ĳ��Ÿ��"))->setAtkMax(16);
				((cannonTower*)TOWERMANAGER->findTower("ĳ��Ÿ��"))->setAtkRange(100);
				TOWERMANAGER->findTower("ĳ��Ÿ��")->setBuyPrice(125);
			}
		}
		//������ ���� ��Ȳ ��

		//��ư �ȴ����� ��Ȳ
		else
		{
			for (int i = 0; i < 30; i++)
			{
				if (PtInRect(&_upgrade[i].buttonRect, _ptMouse))
				{
					if (_upgrade[i].upgradeState == UPGRADE_STATE::PURCHABLE_BASE)
						_upgrade[i].upgradeState = UPGRADE_STATE::PURCHABLE_ON;
				}
				else
				{
					if (_upgrade[i].upgradeState == UPGRADE_STATE::PURCHABLE_ON)
						_upgrade[i].upgradeState = UPGRADE_STATE::PURCHABLE_BASE;
				}
			}
			if (PtInRect(&_doneButtonRect, _ptMouse))
			{
				_doneButtonImage = IMAGEMANAGER->findImage("����ư(��)");
			}
			if (PtInRect(&_resetButtonRect, _ptMouse))
			{
				for (int i = 0; i < 30; i++)
				{
					if (_upgrade[i].upgradeState == UPGRADE_STATE::ACTIVATED)
					{
						_resetButtonImage = IMAGEMANAGER->findImage("���¹�ư(��)");
						break;
					}
				}
			}
		}
		break;
	case MAINPAGE::FOLD_UPGRADE:
		_upgradeBoardPos -= 20;
		if (_upgradeBoardPos < -_upgradeBoardImage->getHeight())
		{
			_upgradeBoardPos = -_upgradeBoardImage->getHeight();
			_mainPage = MAINPAGE::PLAY;
		}
		break;
	}
}
void mainPage::render(void)
{
	_mainPageImage->render(getMemDC());

	_starBoard->render(getMemDC(), 510, -50);

	HFONT font = CreateFont(28, 0, 0, 0, 700, 1, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "Brush Script Std");
	HFONT oldfont = (HFONT)SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(244, 223, 149));
	SetTextAlign(getMemDC(), TA_RIGHT);
	SetBkMode(getMemDC(), TRANSPARENT);

	wsprintf(_starChar, "%d/62", _star);
	TextOut(getMemDC(), 596, 48, _starChar, lstrlen(_starChar));

	SelectObject(getMemDC(), oldfont);
	DeleteObject(font);

	HFONT font1 = CreateFont(28, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "Arial");
	HFONT oldfont1 = (HFONT)SelectObject(getMemDC(), font1);
	SetTextColor(getMemDC(), RGB(244, 223, 149));
	SetTextAlign(getMemDC(), TA_CENTER);
	SetBkMode(getMemDC(), TRANSPARENT);

	//�׽�Ʈ��
	for (int i = 0; i < _currentStageNum; i++)
	{
		_stage[i].buttonImage->render(getMemDC(), _stage[i].buttonRect.left, _stage[i].buttonRect.top);
		_stage[i].starImage->render(getMemDC(), _stage[i].buttonRect.left + 3, _stage[i].buttonRect.top - 7);
	}

	switch (_mainPage)
	{
	case MAINPAGE::OPEN:
		_menuButtonImage->render(getMemDC(), _menuButtonRect.left, _menuButtonRect.top);
		_upgradeButtonImage->render(getMemDC(), _upgradeButtonRect.left, _upgradeButtonRect.top);
		_leftDoorImage->render(getMemDC(), _leftDoorPos, -20);
		_rightDoorImage->render(getMemDC(), _rightDoorPos, -20);
		break;
	case MAINPAGE::PLAY:
		_menuButtonImage->render(getMemDC(), _menuButtonRect.left, _menuButtonRect.top);
		_upgradeButtonImage->render(getMemDC(), _upgradeButtonRect.left, _upgradeButtonRect.top);
		break;
	case MAINPAGE::CLOSE_FOR_MENU:
	case MAINPAGE::CLOSE_FOR_STAGE:
		_menuButtonImage->render(getMemDC(), _menuButtonRect.left, _menuButtonRect.top);
		_upgradeButtonImage->render(getMemDC(), _upgradeButtonRect.left, _upgradeButtonRect.top);
		_leftDoorImage->render(getMemDC(), _leftDoorPos, -20);
		_rightDoorImage->render(getMemDC(), _rightDoorPos, -20);
		break;
	case MAINPAGE::FOLD_UPGRADE:
	case MAINPAGE::SET_UPGRADE:
		_menuButtonImage->render(getMemDC(), _menuButtonRect.left, _menuButtonRect.top);
		_upgradeButtonImage->render(getMemDC(), _upgradeButtonRect.left, _upgradeButtonRect.top);
		_upgradeBoardImage->render(getMemDC(), WINSIZEX / 2 - _upgradeBoardImage->getWidth() / 2, _upgradeBoardPos);

		wsprintf(_purchableStarChar, "%d", _purchableStar);
		TextOut(getMemDC(), 146, 525 + _upgradeBoardPos, _purchableStarChar, lstrlen(_purchableStarChar));

		for (int i = 0; i < 30; i++)
		{
			int _xPos;
			switch (i % 6)
			{
			case 0:
				_xPos = 88;
				break;
			case 1:
				_xPos = 88 + 95;
				break;
			case 2:
				_xPos = 88 + 95 + 96;
				break;
			case 3:
				_xPos = 88 + 95 + 95 + 95;
				break;
			case 4:
				_xPos = 88 + 95 + 95 + 95 + 94;
				break;
			case 5:
				_xPos = 88 + 95 + 95 + 95 + 95 + 93;
				break;
			}
			switch (_upgrade[i].upgradeState)
			{
			case UPGRADE_STATE::LOCKED:
				_upgrade[i].buttonImage->setFrameX(0);
				break;
			case UPGRADE_STATE::PURCHABLE_BASE:
				_upgrade[i].buttonImage->setFrameX(1);
				break;
			case UPGRADE_STATE::PURCHABLE_ON:
				_upgrade[i].buttonImage->setFrameX(2);
				break;
			case UPGRADE_STATE::ACTIVATED:
				_upgrade[i].buttonImage->setFrameX(3);
				break;
			}
			_upgrade[i].buttonImage->frameRender(getMemDC(), _xPos, _upgradeBoardPos + 356 - 63 * (i / 6));
		}
		
		_doneButtonImage->render(getMemDC(), _doneButtonRect.left, _upgradeBoardPos + _upgradeBoardImage->getHeight() - 67);
		_resetButtonImage->render(getMemDC(), _resetButtonRect.left, _upgradeBoardPos + _upgradeBoardImage->getHeight() - 67);
		break;
	case MAINPAGE::UPGRADE:
		_menuButtonImage->render(getMemDC(), _menuButtonRect.left, _menuButtonRect.top);
		_upgradeButtonImage->render(getMemDC(), _upgradeButtonRect.left, _upgradeButtonRect.top);
		_upgradeBoardImage->render(getMemDC(), WINSIZEX / 2 - _upgradeBoardImage->getWidth() / 2, 5);

		

		wsprintf(_purchableStarChar, "%d", _purchableStar);
		TextOut(getMemDC(), 146, 525, _purchableStarChar, lstrlen(_purchableStarChar));

		

		for (int i = 0; i < 30; i++)
		{
			int _xPos;
			switch (i % 6)
			{
			case 0:
				_xPos = 88;
				break;
			case 1:
				_xPos = 88 + 95;
				break;
			case 2:
				_xPos = 88 + 95 + 96;
				break;
			case 3:
				_xPos = 88 + 95 + 95 + 95;
				break;
			case 4:
				_xPos = 88 + 95 + 95 + 95 + 94;
				break;
			case 5:
				_xPos = 88 + 95 + 95 + 95 + 95 + 93;
				break;
			}
			switch (_upgrade[i].upgradeState)
			{
			case UPGRADE_STATE::LOCKED:
				_upgrade[i].buttonImage->setFrameX(0);
				break;
			case UPGRADE_STATE::PURCHABLE_BASE:
				_upgrade[i].buttonImage->setFrameX(1);
				break;
			case UPGRADE_STATE::PURCHABLE_ON:
				_upgrade[i].buttonImage->setFrameX(2);
				break;
			case UPGRADE_STATE::ACTIVATED:
				_upgrade[i].buttonImage->setFrameX(3);
				break;
			}
			_upgrade[i].buttonImage->frameRender(getMemDC(), _xPos, 356 - 63 * (i / 6));
		}
		_doneButtonImage->render(getMemDC(), _doneButtonRect.left, _doneButtonRect.top);
		_resetButtonImage->render(getMemDC(), _resetButtonRect.left, _resetButtonRect.top);

		for (int i = 0; i < 30; i++)
		{
			if (PtInRect(&_upgrade[i].buttonRect, _ptMouse))
			{
				if (i % 6 < 4)
				{
					_upgrade[i].description->render(getMemDC(), _ptMouse.x, _ptMouse.y - _upgrade[i].description->getHeight());
				}
				else
				{
					_upgrade[i].description->render(getMemDC(), _ptMouse.x - 247, _ptMouse.y - _upgrade[i].description->getHeight());
				}
			}
		}
		break;
	}

	SelectObject(getMemDC(), oldfont1);
	DeleteObject(font1);
}

void mainPage::setStageInfo(STAGE_INFO stage[8])
{
	for (int i = 0; i < 8; i++)
	{
		_stage[i].stageState = stage[i].stageState;
		_stage[i].starPoint = stage[i].starPoint;
	}
}

void mainPage::setUpgradeInfo(UPGRADE_INFO upgrade[30])
{
	for (int i = 0; i < 30; i++)
	{
		_upgrade[i].id = upgrade[i].id;
		_upgrade[i].price = upgrade[i].price;
		_upgrade[i].upgradeState = upgrade[i].upgradeState;
	}
}

void mainPage::setStageInfo(int stageNum, int starNum)
{
	
	if (_stage[stageNum - 1].starPoint < starNum)
		_stage[stageNum - 1].starPoint = starNum;
	if (stageNum == _currentStageNum)
	{
		_currentStageNum = stageNum + 1;
		for (int i = 0; i < 2; i++)//�ۼ��� �������� �� ũ�⸸ŭ ������
		{
			if (_stage[i].stageNum < _currentStageNum)
				_stage[i].stageState = STAGE_STATE::COMPLETED_STAGE_BASE;
			else if (_stage[i].stageNum == _currentStageNum)
				_stage[i].stageState = STAGE_STATE::CURRENT_STAGE_BASE;
			else
				_stage[i].stageState = STAGE_STATE::LOCKED;

			//_stage[i].starPoint = �ҷ��� �Ϳ��� �ش� ���������� �ش��ϴ� �� ����Ʈ ��.
		}
	}
}
int mainPage::getStageStar(int stageNum)
{
	return _stage[stageNum - 1].starPoint;
}

void mainPage::setFlag()
{
	_stage[_currentStageNum - 1].buttonImage = IMAGEMANAGER->findImage("���罺������(�⺻)");
	for (int i = 0; i < 8; i++)
	{
		if (_stage[i].starPoint == 1)
			_stage[i].starImage = IMAGEMANAGER->findImage("�����������ϳ�");
		else if (_stage[i].starPoint == 2)
			_stage[i].starImage = IMAGEMANAGER->findImage("������������");
		else if (_stage[i].starPoint == 3)
			_stage[i].starImage = IMAGEMANAGER->findImage("������������");
		else
			_stage[i].starImage = IMAGEMANAGER->findImage("������������");
	}
}

void mainPage::sumStar()
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		sum = sum + _stage[i].starPoint;
	}
	_star = sum;
	
	sum = 0;
	for (int i = 0; i < 30; i++)
	{
		if (_upgrade[i].upgradeState == UPGRADE_STATE::ACTIVATED)
		{
			sum += _upgrade[i].price;
		}
	}
	_purchableStar = _star - sum;
}