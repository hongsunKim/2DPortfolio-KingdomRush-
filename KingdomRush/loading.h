#pragma once
#include "gameNode.h"
#include "prograssBar.h"

//==================================================================
//		## loadItem ## 로드아이템
//==================================================================

//로드아이템 추가
enum LOAD_KIND
{
	LOAD_KIND_IMAGE_0,			//빈비트맵 이미지
	LOAD_KIND_IMAGE_1,			//일반 이미지
	LOAD_KIND_IMAGE_2,			//일반 이미지(POS 추가)
	LOAD_KIND_FRAMEIMAGE_0,		//프레임 이미지
	LOAD_KIND_FRAMEIMAGE_1,		//프레임 이미지(POS 추가)
	LOAD_KIND_SOUND,			//사운드
	LOAD_KIND_END
};

//이미지 리소스 구조체
struct tagImageResource
{
	string keyName;				//이미지 키값
	const char* fileName;		//파일 이름
	int x, y;					//위치 좌표
	int width, height;			//가로, 세로 크기
	int frameX, frameY;			//프레임
	bool trans;					//배경 없앨거냐?
	COLORREF transColor;		//투명컬러
};

//사운드 리소스 구조체
struct  tagSoundResource 
{
	string keyName;				//사운드 키값
	const char* fileName;		//사운드 파일
	bool bgm;					//BGM이냐?
	bool loop;					//루프냐?

};

class loadItem
{
private:
	LOAD_KIND _kind;
	tagImageResource _imageResource;
	tagSoundResource _soundResource;

public:
	//키값으로 빈 비트맵 초기화
	HRESULT initForImage(string keyName, int width, int height);

	//키값으로 이미지 파일 초기화(주로 사용)
	HRESULT initForImage(string keyName, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	HRESULT initForImage(string keyName, const char* fileName, int x, int y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//키값으로 프레임 이미지 파일 초기화
	HRESULT initForFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	HRESULT initForFrameImage(string keyName, const char* fileName, int x, int y, int width, int height, int frameX, int frameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//사운드 초기화
	HRESULT initForSound(string keyName, const char* fileName, bool bgm = false, bool loop = false);

	//로딩아이템 종류 가져오기
	LOAD_KIND getLoadingKind(void) { return _kind; }
	//이미지 리소스 가져오기
	tagImageResource getImageResource(void) { return _imageResource; }
	//사운드 리소스 가져오기
	tagSoundResource getSoundResource(void) { return _soundResource; }

	loadItem() {}
	~loadItem() {}
};

//==================================================================
//		## loading ## 로딩클래스
//==================================================================
class loading : public gameNode
{
private: 
	//컨테이너
	typedef vector<loadItem*> arrLoadItem;
	typedef vector<loadItem*>::iterator arrLoadItemIter;

private:
	arrLoadItem _vLoadItem;

	//로딩화면에서 사용할 이미지 및 로딩바
	image* _background;			//로딩화면의 배경
	prograssBar* _loadingBar;	//로딩화면의 로딩 바
	int _currentGauge;			//로딩바 게이지

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

	//로드사운드
	void loadSound(string keyName, const char* fileName, bool bgm = false, bool loop = false);

	//중요!!
	//로딩이 완료 됐냐?(이거 확인하고 씬변경)
	BOOL loadingDone(void);

	//로드아이템 백터 가져오기
	vector<loadItem*> getLoadItem(void) { return _vLoadItem; }

	loading() {}
	~loading() {}
};

