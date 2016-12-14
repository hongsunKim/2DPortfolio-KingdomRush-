#pragma once
#include "singletonBase.h"

//INI테이터의 기본요소
struct tagIniData
{
	char* section;
	char* key;
	char* value;
};

class iniData : public singletonBase<iniData>
{
private:
	typedef vector<tagIniData> arrIniData;
	typedef vector<tagIniData>::iterator arrIniDataIter;
	typedef vector<arrIniData> arrIniDatas;
	typedef vector<arrIniData>::iterator arrIniDatasIter;

private:
	arrIniDatas _vIniData;

public:
	HRESULT init(void);

	//데이터 추가(섹션, 키, 벨류)
	void addData(char* section, char* key, char* value);
	//세이브
	void iniSave(char* fileName);

	//문자값 로드
	char* loadDataString(char* fileName, char* section, char* key);
	//정수값 로드
	int loadDataInteger(char* fileName, char* section, char* key);


	iniData();
	~iniData();
};

