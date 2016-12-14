#include "stdafx.h"
#include "iniData.h"
iniData::iniData()
{
}
iniData::~iniData()
{
}


HRESULT iniData::init(void)
{
	return S_OK;
}

//데이터 추가(섹션, 키, 벨류)
void iniData::addData(char* section, char* key, char* value)
{
	//ini테이터 구조체 선언, 초기화
	tagIniData iniData;
	iniData.section = section;
	iniData.key = key;
	iniData.value = value;

	//구조체에 담기
	arrIniData vInidata;
	vInidata.push_back(iniData);

	//모든데이터는 _vIniData에 담는다
	_vIniData.push_back(vInidata);
}

//세이브
void iniData::iniSave(char* fileName)
{
	char str[256];
	char dir[256];
	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));
	sprintf(dir, "//%s.ini", fileName);

	GetCurrentDirectory(256, str);
	strcat(str, dir);

	for (int i = 0; i < _vIniData.size(); i++)
	{
		arrIniData vData = _vIniData[i];
		WritePrivateProfileString(vData[0].section, vData[0].key, vData[0].value, str);
		vData.clear();
	}

	_vIniData.clear();
}

//문자값 로드
char* iniData::loadDataString(char* fileName, char* section, char* key)
{
	char str[256];
	char dir[256];
	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));
	sprintf(dir, "//%s.ini", fileName);

	GetCurrentDirectory(256, str);
	strcat(str, dir);

	int const bufSize = 64;
	char data[bufSize] = { NULL };
	GetPrivateProfileString(section, key, "", data, bufSize, str);

	return data;
}

//정수값 로드
int iniData::loadDataInteger(char* fileName, char* section, char* key)
{
	char str[256];
	char dir[256];
	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));
	sprintf(dir, "//%s.ini", fileName);

	GetCurrentDirectory(256, str);
	strcat(str, dir);
	
	return GetPrivateProfileInt(section, key, 0, str);
}
