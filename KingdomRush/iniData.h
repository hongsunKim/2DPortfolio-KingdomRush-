#pragma once
#include "singletonBase.h"

//INI�������� �⺻���
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

	//������ �߰�(����, Ű, ����)
	void addData(char* section, char* key, char* value);
	//���̺�
	void iniSave(char* fileName);

	//���ڰ� �ε�
	char* loadDataString(char* fileName, char* section, char* key);
	//������ �ε�
	int loadDataInteger(char* fileName, char* section, char* key);


	iniData();
	~iniData();
};

