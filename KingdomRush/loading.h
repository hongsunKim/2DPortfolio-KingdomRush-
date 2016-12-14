#pragma once
#include "gameNode.h"
#include "prograssBar.h"

//==================================================================
//		## loadItem ## �ε������
//==================================================================

//�ε������ �߰�
enum LOAD_KIND
{
	LOAD_KIND_IMAGE_0,			//���Ʈ�� �̹���
	LOAD_KIND_IMAGE_1,			//�Ϲ� �̹���
	LOAD_KIND_IMAGE_2,			//�Ϲ� �̹���(POS �߰�)
	LOAD_KIND_FRAMEIMAGE_0,		//������ �̹���
	LOAD_KIND_FRAMEIMAGE_1,		//������ �̹���(POS �߰�)
	LOAD_KIND_SOUND,			//����
	LOAD_KIND_END
};

//�̹��� ���ҽ� ����ü
struct tagImageResource
{
	string keyName;				//�̹��� Ű��
	const char* fileName;		//���� �̸�
	int x, y;					//��ġ ��ǥ
	int width, height;			//����, ���� ũ��
	int frameX, frameY;			//������
	bool trans;					//��� ���ٰų�?
	COLORREF transColor;		//�����÷�
};

//���� ���ҽ� ����ü
struct  tagSoundResource 
{
	string keyName;				//���� Ű��
	const char* fileName;		//���� ����
	bool bgm;					//BGM�̳�?
	bool loop;					//������?

};

class loadItem
{
private:
	LOAD_KIND _kind;
	tagImageResource _imageResource;
	tagSoundResource _soundResource;

public:
	//Ű������ �� ��Ʈ�� �ʱ�ȭ
	HRESULT initForImage(string keyName, int width, int height);

	//Ű������ �̹��� ���� �ʱ�ȭ(�ַ� ���)
	HRESULT initForImage(string keyName, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	HRESULT initForImage(string keyName, const char* fileName, int x, int y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//Ű������ ������ �̹��� ���� �ʱ�ȭ
	HRESULT initForFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	HRESULT initForFrameImage(string keyName, const char* fileName, int x, int y, int width, int height, int frameX, int frameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//���� �ʱ�ȭ
	HRESULT initForSound(string keyName, const char* fileName, bool bgm = false, bool loop = false);

	//�ε������� ���� ��������
	LOAD_KIND getLoadingKind(void) { return _kind; }
	//�̹��� ���ҽ� ��������
	tagImageResource getImageResource(void) { return _imageResource; }
	//���� ���ҽ� ��������
	tagSoundResource getSoundResource(void) { return _soundResource; }

	loadItem() {}
	~loadItem() {}
};

//==================================================================
//		## loading ## �ε�Ŭ����
//==================================================================
class loading : public gameNode
{
private: 
	//�����̳�
	typedef vector<loadItem*> arrLoadItem;
	typedef vector<loadItem*>::iterator arrLoadItemIter;

private:
	arrLoadItem _vLoadItem;

	//�ε�ȭ�鿡�� ����� �̹��� �� �ε���
	image* _background;			//�ε�ȭ���� ���
	prograssBar* _loadingBar;	//�ε�ȭ���� �ε� ��
	int _currentGauge;			//�ε��� ������

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void loadImage(string keyName, int width, int height);
	void loadImage(string keyName, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	void loadImage(string keyName, const char* fileName, int x, int y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	void loadFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	void loadFrameImage(string keyName, const char* fileName, int x, int y, int width, int height, int frameX, int frameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//�ε����
	void loadSound(string keyName, const char* fileName, bool bgm = false, bool loop = false);

	//�߿�!!
	//�ε��� �Ϸ� �Ƴ�?(�̰� Ȯ���ϰ� ������)
	BOOL loadingDone(void);

	//�ε������ ���� ��������
	vector<loadItem*> getLoadItem(void) { return _vLoadItem; }

	loading() {}
	~loading() {}
};

