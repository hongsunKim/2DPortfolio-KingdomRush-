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

//������ �߰�(����, Ű, ����)
void iniData::addData(char* section, char* key, char* value)
{
	//ini������ ����ü ����, �ʱ�ȭ
	tagIniData iniData;
	iniData.section = section;
	iniData.key = key;
	iniData.value = value;

	//����ü�� ���
	arrIniData vInidata;
	vInidata.push_back(iniData);

	//��絥���ʹ� _vIniData�� ��´�
	_vIniData.push_back(vInidata);
}

//���̺�
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

//���ڰ� �ε�
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

//������ �ε�
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
